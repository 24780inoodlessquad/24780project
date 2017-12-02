#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include "yspng.h"

class Menu
{
public:
	YsRawPngDecoder *MyPng;
	void draw(/*int P1point, int P2point, */
			  int P1life, int P2life, 
		      int P1bubblenum, int P2bubblenum,
			  int P1bubblerange, int P2bubblerange,
		      int P1bubblespeed, int P2speed,
			  int time);
	Menu()
{

        MyPng = NULL;
		MyPng = new YsRawPngDecoder[4];

		if (YSOK == MyPng[0].Decode("adbubble.png"))
		{
			printf("Read adbubble1111111 Width=%d Height=%d\n", MyPng[0].wid, MyPng[0].hei);
			MyPng[0].Flip();
		}
		else printf("Read obs Error!\n");

		if (YSOK == MyPng[1].Decode("adlife.png"))
		{
			printf("Read obs1111111 Width=%d Height=%d\n", MyPng[1].wid, MyPng[1].hei);
			MyPng[1].Flip();
		}
		else printf("Read obs Error!\n");

		if (YSOK == MyPng[2].Decode("adrange.png"))
		{
			printf("Read adrange11111 Width=%d Height=%d\n", MyPng[2].wid, MyPng[2].hei);
			MyPng[2].Flip();
		}
		else printf("Read obs Error!\n");

		if (YSOK == MyPng[3].Decode("adspeed.png"))
		{
			printf("Read adspeed111111 Width=%d Height=%d\n", MyPng[3].wid, MyPng[3].hei);
			MyPng[3].Flip();
		}
		else printf("Read obs Error!\n");
}
	void DrawTool();
};



