#include "map.h"
void Map::setMapState(int x, int y, int state)
{
	this->map[x][y] = state;
}

int Map::getPixel(int bitX, int bitY) const
{
	return this->map[bitX][bitY];
}

int Map::getMapState(int x, int y) const
{
	return map[y][x];
}

void Map::Draw(void)
{
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			switch (map[i][j])
			{
			case 0:
				glBegin(GL_QUADS);
				glColor3ub(255, 255, 255);

				glVertex2i(j * 50, i * 50);
				glVertex2i((j + 1) * 50, i * 50);
				glVertex2i((j + 1) * 50, (i + 1) * 50);
				glVertex2i(j * 50, (i + 1) * 50);

				glEnd();
				break;
			case 1:
				glBegin(GL_QUADS);
				glColor3ub(255, 0, 0);

				glVertex2i(j * 50, i * 50);
				glVertex2i((j + 1) * 50, i * 50);
				glVertex2i((j + 1) * 50, (i + 1) * 50);
				glVertex2i(j * 50, (i + 1) * 50);

				glEnd();
				break;
			case 2:
				glBegin(GL_QUADS);
				glColor3ub(0, 0, 0);

				glVertex2i(j * 50, i * 50);
				glVertex2i((j + 1) * 50, i * 50);
				glVertex2i((j + 1) * 50, (i + 1) * 50);
				glVertex2i(j * 50, (i + 1) * 50);

				glEnd();
				break;
			case 3:
				glBegin(GL_QUADS);
				glColor3ub(0, 255, 0);

				glVertex2i(j * 50, i * 50);
				glVertex2i((j + 1) * 50, i * 50);
				glVertex2i((j + 1) * 50, (i + 1) * 50);
				glVertex2i(j * 50, (i + 1) * 50);

				glEnd();
				break;
			case 4:
				glBegin(GL_QUADS);
				glColor3ub(0,0,255);

				glVertex2i(j * 50, i * 50);
				glVertex2i((j + 1) * 50, i * 50);
				glVertex2i((j + 1) * 50, (i + 1) * 50);
				glVertex2i(j * 50, (i + 1) * 50);

				glEnd();
				break;
			}
		}
	}
}

void Map::setBubbleMap(int x, int y, int state, int range, int layTime, int playerID)
{
	this->bubbleMap[x][y].setRange(range);
	this->bubbleMap[x][y].setBlowTime0();
	this->bubbleMap[x][y].reset(state, playerID, x, y, layTime);
}


/*void Map::setBubbleRange(const int x, const int y, const int range)
{
	this->bubbleMap[x][y].setRange(range);
}*/

int Map::getRange(int x, int y) const
{
	return bubbleMap[x][y].getRange();
}

int Map::getBubbleMapState(int x, int y) const
{
	return bubbleMap[x][y].getSate();
}

int Map::checkBubbleTime(int x, int y) const
{
	return bubbleMap[x][y].checkTime();
}

void Map::setBlowTime(int x, int y)
{
	bubbleMap[x][y].tictoc();
}


void Map::adjacentExplode(int x, int y, int range, int left, int right, int up, int down, int& num1, int& num2) //recursion
	{
		//base case:
		num1 = 0;
		num2 = 0;
		    if(range < 1) return;
			if (x <= 0 || x >= 14 || y <= 0 || y >= 14) 
			{
				return;
			}
			int count = 1;
			while(count <= range && (x+count)<=14 && left == 1)
			{
				if(bubbleMap[x+count][y].getSate() == 1)   //向右侧查找
			    {
				    adjacentExplode(x+count,y,bubbleMap[x+count][y].getRange(),1,0,1,1,num1,num2);
				    map[x+count][y] = 3;

					/*if(bubbleMap[x+count][y].getPlayerID() == 1)
					{
						num1++;
					}
					else if(bubbleMap[x+count][y].getPlayerID() == 2)
					{
						num2++;
					}*/
					//bubbleMap[x+count][y].setState(0);
				    
					
					break;
			    }
			    if(map[x+count][y] == 1 || map[x+count][y] == 4)
			    {
			    	map[x+count][y] = 3;
			    	break;
			    }
				if(map[x+count][y] == 2 || map[x+count][y] == 3)
				{
					break;
				}
			    map[x+count][y] = 3;
				count++;
			}
			count = 1;
			while(count <= range && (x - count) >= 0 && right == 1)
			{
				if(bubbleMap[x-count][y].getSate() == 1)   //向右侧查找
			    {
				    adjacentExplode(x-count,y,bubbleMap[x-count][y].getRange(),0,1,1,1,num1,num2);
				    map[x-count][y] = 3;

					//bubbleMap[x-count][y].setState(0);
					/*if(bubbleMap[x-count][y].getPlayerID() == 1)
					{
						num1++;
					}
					else if(bubbleMap[x-count][y].getPlayerID() == 2)
					{
						num2++;
					}*/


				    break;
			    }
			    if(map[x-count][y] == 1 || map[x-count][y] == 4)
			    {
			    	map[x-count][y] = 3;
			    	break;
			    }
				if(map[x - count][y] == 2 || map[x - count][y] == 3)
				{
					break;
				}
			    map[x-count][y] = 3;
				count++;
			}
			count = 1;
			while(count <= range && (y + count) <= 14 && up == 1)
			{
				if(bubbleMap[x][y+count].getSate() == 1)   //向xia侧查找
			    {
				    adjacentExplode(x,y+count,bubbleMap[x][y+count].getRange(),1,1,1,0,num1,num2);
				    map[x][y+count] = 3;

					//bubbleMap[x][y+count].setState(0);
					/*if(bubbleMap[x][y+count].getPlayerID() == 1)
					{
						num1++;
					}
					else if(bubbleMap[x][y+count].getPlayerID() == 2)
					{
						num2++;
					}*/

				    break;
			    }
			    if(map[x][y+count] == 1 || map[x][y+count] == 4)
			    {
			    	map[x][y+count] = 3;
			    	break;
			    }
				if(map[x][y + count] == 2 || map[x][y + count] == 3)
				{
					break;
				}
			    map[x][y+count] = 3;
				count++;
			}
			count = 1;
			while(count <= range && (y - count) >= 0 && down == 1)
			{
				if(bubbleMap[x][y-count].getSate() == 1)   //向up侧查找
			    {
					adjacentExplode(x,y-count,bubbleMap[x][y-count].getRange(),1,1,0,1,num1,num2);
				    map[x][y-count] = 3;

					//bubbleMap[x][y-count].setState(0);
					/*if(bubbleMap[x][y-count].getPlayerID() == 1)
					{
						num1++;
					}
					else if(bubbleMap[x][y-count].getPlayerID() == 2)
					{
						num2++;
					}*/

				    break;
			    }
			    if(map[x][y-count] == 1 || map[x][y-count] == 4)
			    {
			    	map[x][y-count] = 3;
			    	break;
			    }
				if(map[x][y - count] == 2 || map[x][y - count] == 3)
				{
					break;
				}
			    map[x][y-count] = 3;
				count++;
			}
			if(bubbleMap[x][y].getPlayerID() == 1)
			{
				num1++;
			}
			if(bubbleMap[x][y].getPlayerID() == 2)
			{
				num2++;
			}
			//bubbleMap[x][y].setState(0);
			return;
	}

int Map::getID(int x, int y)
{
	return bubbleMap[x][y].getPlayerID();
}