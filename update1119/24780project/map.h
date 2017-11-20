#include <vector>
#include <string>
#include "fssimplewindow.h"

#ifndef is_included_bubble
#include "bubble.h"
#endif

#define isFloor 0;
#define isBox 1;
#define isObstacle 2;
#define inExplosion 3;
#define isBubble 4;
#define isPlayer 5;


#ifndef MAP_IS_INCLUDED
#define MAP_IS_INCLUDED
class Map
{
protected:
	//enum map_state {floor = 0, box = 1, obstacle = 2, isWithinExposedZone=3, hasBubble=4, player = 5};
	Bubble bubbleMap[15][15];
	//map_state map[15][15];
	int map[15][15];
    //to be implemented...
public:
	Map()
	{
		for (int i = 0; i < 15; i++) 
		{
			for (int j = 0; j < 15; j++)
			{
				Bubble tempb(0,i,j);
				bubbleMap[i][j] = tempb;
				//map[i][j] = 0;
			}
		}
	}

	/*Map(std::string fileName)
	{
		//...load file, remaining to be completed
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				bubbleMap[i][j] = new Bubble(0,0,i,j,0); // just set state
			}
		}
	}*/
	void setPixel();
	void setBubbleMap(int x, int y, int state, int range, int layTime, int playerID);
	//void setBubbleRange(const int x, const int y, const int range);
	int  getPixel(int bitX, int bitY) const;
	int getID(int x, int y);
	void Draw();
	//check whether the current bit map zone is exposed or not
	void setMapState(int x, int y, int state);
	void checkExposeTime(); // traverse row and col
	void adjacentExplode(int x, int y, int range, int left, int right, int up, int down, int& num1, int& num2);//recursion
    int getMapState(int i, int j) const;
	int getBubbleMapState(int i, int j) const;
	int checkBubbleTime(int x, int y) const;
	int getRange(int x, int y) const;
	void setBlowTime(int x, int y);
};
#endif