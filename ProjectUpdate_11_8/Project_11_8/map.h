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
	int  getPixel(int bitX, int bitY) const;
	void Draw();
	//check whether the current bit map zone is exposed or not
	void setMapState(int x, int y, int state);
	void checkExposeTime(); // traverse row and col
	void adjacentExplode(int x, int y, int range) //recursion
	{
		//base case:
			if (x <= 0 || x >= 14 || y <= 0 || y >= 14) 
			{
				return;
			}
			int count = 1;
			while(count <= range && (x+count)<=14)
			{
				if(bubbleMap[x+count][y].getSate() == 1)   //向右侧查找
			    {
				    adjacentExplode(x+count,y,bubbleMap[x+count][y].getRange());
				    map[x+count][y] = 3;
				    break;
			    }
			    if(map[x+count][y] == 1 || map[x+count][y] == 2 || map[x+count][y] == 5)
			    {
			    	map[x+count][y] = 3;
			    	break;
			    }
			    map[x+count][y] = 3;
				count++;
			}
			count = 1;
			while(count <= range && (x - count) >= 0)
			{
				if(bubbleMap[x-count][y].getSate() == 1)   //向右侧查找
			    {
				    adjacentExplode(x-count,y,bubbleMap[x-count][y].getRange());
				    map[x-count][y] = 3;
				    break;
			    }
			    if(map[x-count][y] == 1 || map[x-count][y] == 2 || map[x-count][y] == 5)
			    {
			    	map[x-count][y] = 3;
			    	break;
			    }
			    map[x-count][y] = 3;
				count++;
			}
			count = 1;
			while(count <= range && (y + count) <= 14)
			{
				if(bubbleMap[x][y+count].getSate() == 1)   //向xia侧查找
			    {
				    adjacentExplode(x,y+count,bubbleMap[x][y+count].getRange());
				    map[x][y+count] = 3;
				    break;
			    }
			    if(map[x][y+count] == 1 || map[x][y+count] == 2 || map[x][y+count] == 5)
			    {
			    	map[x][y+count] = 3;
			    	break;
			    }
			    map[x][y+count] = 3;
				count++;
			}
			count = 1;
			while(count <= range && (y - count) >= 0)
			{
				if(bubbleMap[x][y-count].getSate() == 1)   //向up侧查找
			    {
				    adjacentExplode(x,y-count,bubbleMap[x][y-count].getRange());
				    map[x][y-count] = 3;
				    break;
			    }
			    if(map[x][y-count] == 1 || map[x][y-count] == 2 || map[x][y-count] == 5)
			    {
			    	map[x][y-count] = 3;
			    	break;
			    }
			    map[x][y-count] = 3;
				count++;
			}
	}	
    int getMapState() const;
};
#endif