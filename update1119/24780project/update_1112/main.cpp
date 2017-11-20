#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include "map.h"
#include "Player.h"
#include "bubble.h"

#define isFloor 0;
#define isBox 1;
#define isObstacle 2;
#define inExplosion 3;
#define isBubble 4;
#define isPlayer 5;

using namespace std;

int main(void)
{
	Map background;
	Player p1(75, 100, 3, 5);
	Player p2(675, 700, 3, 5);
	Bubble player1_bubble(0, 1, p1.getY()/50, p1.getX()/50, 100);
	Bubble player2_bubble(0, 2, p2.getY()/50, p2.getX()/50, 100);
	priority_queue<Bubble, vector<Bubble>, cmp> bubbleQueue;
	vector<Bubble> bubbleVector;
	char BitMap[] = {
		"222222222222222"
		"200011101110002"
		"202121222121202"
		"111100000001111"
		"212021121120212"
		"111011212110111"
		"202010222010202"
		"202010222010202"
		"202010222010202"
		"111011212110111"
		"212021121120212"
		"111100000001111"
		"202121222121202"
		"200011101110002"
		"222222222222222" };

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			switch (BitMap[i * 15 + j])
			{
			case '0':
				background.setMapState(i, j, 0);
				break;
			case '1':
				background.setMapState(i, j, 1);
				break;
			case '2':
				background.setMapState(i, j, 2);
				break;
			}
			//printf("%d ", background.getMapState());
		}
		printf("\n");
	}

	int P1Flag1 = 0, P1Flag2 = 0, P1Flag3 = 0, P1Flag4 = 0;
	int P2Flag1 = 0, P2Flag2 = 0, P2Flag3 = 0, P2Flag4 = 0;
	FsOpenWindow(16, 16, 750, 750, 2);
	for (;;)
	{
		int direc = 0;
		FsPollDevice();
		auto key = FsInkey();
		if (FSKEY_ESC == key)
		{
			break;
		}

		//move of player 1
		if (0 != FsGetKeyState(FSKEY_UP) && 0 == P1Flag2 && 0 == P1Flag3 && 0 == P1Flag4)
		{
			P1Flag1 = 1;
			direc = 1;
			p1.move(direc,background);
		}
		if (0 != FsGetKeyState(FSKEY_LEFT) && 0 == P1Flag1 && 0 == P1Flag3 && 0 == P1Flag4)
		{
			P1Flag2 = 1;
			direc = 2;
			p1.move(direc, background);
		}
		if (0 != FsGetKeyState(FSKEY_DOWN) && 0 == P1Flag1 && 0 == P1Flag2 && 0 == P1Flag4)
		{
			P1Flag3 = 1;
			direc = 3;
			p1.move(direc, background);
		}
		if (0 != FsGetKeyState(FSKEY_RIGHT) && 0 == P1Flag1 && 0 == P1Flag2 && 0 == P1Flag3)
		{
			P1Flag4 = 1;
			direc = 4;
			p1.move(direc, background);
		}

		if (0 == FsGetKeyState(FSKEY_UP) && 1 == P1Flag1)
		{
			P1Flag1 = 0;
		}
		if (0 == FsGetKeyState(FSKEY_LEFT) && 1 == P1Flag2)
		{
			P1Flag2 = 0;
		}
		if (0 == FsGetKeyState(FSKEY_DOWN) && 1 == P1Flag3)
		{
			P1Flag3 = 0;
		}
		if (0 == FsGetKeyState(FSKEY_RIGHT) && 1 == P1Flag4)
		{
			P1Flag4 = 0;
		}


		if(key == FSKEY_SPACE)
		{
			if(p1.getBubbleNum() > 0)
			{
				p1.layBubble(background); 
			    player1_bubble.reset(0, 1, p1.getX()/50, p1.getY()/50, 100);
			    background.setBubbleMap(p1.getY()/50, p1.getX()/50,1);
			    bubbleVector.push_back(player1_bubble);
			}
		}




		//move of player 2
		if (0 != FsGetKeyState(FSKEY_W) && 0 == P2Flag2 && 0 == P2Flag3 && 0 == P2Flag4)
		{
			P2Flag1 = 1;
			direc = 1;
			p2.move(direc, background);
		}
		if (0 != FsGetKeyState(FSKEY_A) && 0 == P2Flag1 && 0 == P2Flag3 && 0 == P2Flag4)
		{
			P2Flag2 = 1;
			direc = 2;
			p2.move(direc, background);
		}
		if (0 != FsGetKeyState(FSKEY_S) && 0 == P2Flag1 && 0 == P2Flag2 && 0 == P2Flag4)
		{
			P2Flag3 = 1;
			direc = 3;
			p2.move(direc, background);
		}
		if (0 != FsGetKeyState(FSKEY_D) && 0 == P2Flag1 && 0 == P2Flag2 && 0 == P2Flag3)
		{
			P2Flag4 = 1;
			direc = 4;
			p2.move(direc, background);
		}

		if (0 == FsGetKeyState(FSKEY_W) && 1 == P2Flag1)
		{
			P2Flag1 = 0;
		}
		if (0 == FsGetKeyState(FSKEY_A) && 1 == P2Flag2)
		{
			P2Flag2 = 0;
		}
		if (0 == FsGetKeyState(FSKEY_S) && 1 == P2Flag3)
		{
			P2Flag3 = 0;
		}
		if (0 == FsGetKeyState(FSKEY_D) && 1 == P2Flag4)
		{
			P2Flag4 = 0;
		}
		if(key == FSKEY_ENTER)
		{
			if(p2.getBubbleNum() > 0)
			{
				p2.layBubble(background);
			    player2_bubble.reset(0, 2, p2.getX()/50, p2.getY()/50, 100);
			    background.setBubbleMap(p2.getY()/50, p2.getX()/50,1);
			    bubbleVector.push_back(player2_bubble);
			}
		}


		for(int i=0;i<bubbleVector.size();++i)
		{
			bubbleVector[i].tictoc();
			if(bubbleVector[i].checkTime())
			{
				background.setMapState(bubbleVector[i].getBitY(),bubbleVector[i].getBitX(),0);
				background.adjacentExplode(bubbleVector[i].getBitY(), bubbleVector[i].getBitX(), bubbleVector[i].getRange());
				bubbleVector.erase(bubbleVector.begin() + i);
			}
		}


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		background.Draw();
		p1.Draw();
		p2.Draw();
		FsSwapBuffers();
		FsSleep(20);

		for(int i=0;i<15;++i)
		{
			for(int j=0;j<15;++j)
			{
				if(background.getMapState(i,j) == 3)
				{
					background.setMapState(j,i,0);
				}
			}
		}


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		background.Draw();
		p1.Draw();
		p2.Draw();

		FsSwapBuffers();
		//FsSleep(10);
	}

	return 0;
}