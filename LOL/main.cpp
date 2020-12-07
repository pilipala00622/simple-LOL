#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 600

int ezWidth = 40;
int ezHeight = 40;
double ez_x = WIDTH / 2;
double ez_y = HEIGHT / 2;
double ez_vx, ez_vy; //分速度
double x, y, mx, my; //坐标之差，鼠标坐标
double ezsin, ezcos;
int is = 0;

double ez_v = 1.5;

void StartUp()
{
	initgraph(WIDTH, HEIGHT);
	cleardevice();
	setbkcolor(RGB(0, 255, 0));
	BeginBatchDraw();
}

void Show()
{
	cleardevice();
	solidrectangle(ez_x, ez_y, ez_x + ezWidth, ez_y + ezHeight);
	FlushBatchDraw();
}

void updata(double vx, double vy, double mx, double my)
{
	while (1)
	{
		ez_x += vx;
		ez_y += vy;
		Sleep(5);
		Show();
		if (sqrt((ez_x - mx) * (ez_x - mx) + (ez_y - my) * (ez_y - my)) <= 5)
			break;
	}
}

void UpdateWithoutInput()
{
}

void UpdateWithInput()
{
	MOUSEMSG m;
	if (MouseHit)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			x = m.x - ez_x;
			y = m.y - ez_y;
			mx = m.x;
			my = m.y;
			ezcos = x / sqrt((x * x) + (y * y));
			ezsin = y / sqrt((x * x) + (y * y));
			ez_vx = ez_v * ezcos;
			ez_vy = ez_v * ezsin;
			updata(ez_vx, ez_vy, mx, my);
		}
	}
}

int main(void)
{
	StartUp();
	while (1)
	{
		Show();
		UpdateWithInput();
		UpdateWithoutInput();
	}
	return 0;
}