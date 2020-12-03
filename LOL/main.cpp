#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 600

int ezWidth = 40;
int ezHeight = 40;
float ez_x = WIDTH / 2;
float ez_y = HEIGHT / 2; 
float ez_vx, ez_vy; //分速度
float x, y; //坐标之差
float ezsin, ezcos;

float ez_v = 10;

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
			ezcos = x / sqrt((x * x) + (y * y));
			ezsin = y / sqrt((x * x) + (y * y));
			ez_vx = ez_v * ezcos;
			ez_vy = ez_v * ezsin;
		}
	}
	ez_x += ez_vx;
	ez_y += ez_vy;
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