#include "Menu.h"


void Menu::draw(
	int P1life, int P2life,
	int P1bubblenum, int P2bubblenum,
	int P1bubblerange, int P2bubblerange,
	int P1bubblespeed, int P2speed,
	int time
	)
{
	char str1[256];// for title
	glColor3ub(0, 0, 0);
	sprintf(str1, "Bubble Man");
	glRasterPos2i(775, 40);
	YsGlDrawFontBitmap16x20(str1); 

	//char str2[256];// for players
	//glColor3ub(0, 0, 0);
	//sprintf(str2, "P1 %d : %d P2", P1point, P2point);
	//glRasterPos2i(775, 80);
	//YsGlDrawFontBitmap12x16(str2);
	
	//char str5[256];// for rounds
	//glColor3ub(0, 0, 0);
	//sprintf(str5, "Round %d", round);
	//glRasterPos2i(775, 140);	
	//YsGlDrawFontBitmap12x16(str5);

	char str6[256];// for time
	glColor3ub(0, 0, 0);
	if ((time / 60) < 10 && (time % 60) < 10)
	{
		sprintf(str6, "Time 0%d : 0%d", time / 60, time % 60);
	}
	else if ((time / 60) >= 10 && (time % 60) < 10)
	{
		sprintf(str6, "Time %d : 0%d", time / 60, time % 60);
	}
	else if ((time / 60) < 10 && (time % 60) >= 10)
	{
		sprintf(str6, "Time 0%d : %d", time / 60, time % 60);
	}
	else if ((time / 60) >= 10 && (time % 60) >= 10)
	{
		sprintf(str6, "Time %d : %d", time / 60, time % 60);
	}
	glRasterPos2i(775, 140);
	YsGlDrawFontBitmap12x16(str6);

	char str7[256];// for toolbox title plater1
	glColor3ub(0, 0, 0);
	sprintf(str7, "Player1");
	glRasterPos2i(775, 200);	
	YsGlDrawFontBitmap12x16(str7);

	char str8[256];// for toolbox title playter2
	glColor3ub(0, 0, 0);
	sprintf(str8, "Player2");
	glRasterPos2i(775, 350);	
	YsGlDrawFontBitmap12x16(str8);
	
	char str9[256];// bubble for p1
	glColor3ub(0, 0, 0);
	sprintf(str9, "%d",P1bubblenum);
	glRasterPos2i(775, 300);	
	YsGlDrawFontBitmap16x20(str9);

	char str10[256];// life for p1
	glColor3ub(0, 0, 0);
	sprintf(str10, "%d",P1life);
	glRasterPos2i(825, 300);	
	YsGlDrawFontBitmap16x20(str10);

	char str11[256];// bubble range for p1
	glColor3ub(0, 0, 0);
	sprintf(str11,  "%d",P1bubblerange);
	glRasterPos2i(875, 300);	
	YsGlDrawFontBitmap16x20(str11);

	char str12[256];// bubblespeed for p1
	glColor3ub(0, 0, 0);
	sprintf(str12,  "%d",P1bubblespeed);
	glRasterPos2i(925, 300);	
	YsGlDrawFontBitmap16x20(str12);

	char str13[256];// bubble for p1
	glColor3ub(0, 0, 0);
	sprintf(str13, "%d",P2bubblenum);
	glRasterPos2i(775, 450);	
	YsGlDrawFontBitmap16x20(str13);

	char str14[256];// life for p1
	glColor3ub(0, 0, 0);
	sprintf(str14, "%d",P2life);
	glRasterPos2i(825, 450);	
	YsGlDrawFontBitmap16x20(str14);

	char str15[256];// bubble range for p1
	glColor3ub(0, 0, 0);
	sprintf(str15,  "%d",P2bubblerange);
	glRasterPos2i(875,450);	
	YsGlDrawFontBitmap16x20(str15);

	char str16[256];// bubblespeed for p1
	glColor3ub(0, 0, 0);
	sprintf(str16,  "%d", P2speed);
	glRasterPos2i(925, 450);	
	YsGlDrawFontBitmap16x20(str16);

	DrawTool();

}
       // 载入图片，图片放在 .h .cpp 所在处（如果直接运行EXE，要放在 .exe 那里）

void Menu::DrawTool()
{
// 贴图
if ( MyPng != NULL )
{
for (int i=0;i<4;i++)
{
	// 使用原图透明度
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glRasterPos2d(750+i*50,265);
    glDrawPixels(MyPng[i].wid, MyPng[i].hei, GL_RGBA, GL_UNSIGNED_BYTE, MyPng[i].rgba);
	
}
for (int i=0;i<4;i++)
{
		// 使用原图透明度
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glRasterPos2d(750+i*50,415);
    glDrawPixels(MyPng[i].wid, MyPng[i].hei, GL_RGBA, GL_UNSIGNED_BYTE, MyPng[i].rgba);
	
}
}

}