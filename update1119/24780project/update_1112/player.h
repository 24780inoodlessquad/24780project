#include <vector>
#include "tool.h"
#include <math.h>
#include "fssimplewindow.h"


#ifndef MAP_IS_INCLUDED
#include "map.h"
#endif

class Player
{
protected:
	int BubbleNum;
	//std::vector<Bubble> bubbles;
	//Bubble myBubble;
	std::vector<Tool> tools;
	int trapTime;  //
	int state; //0：ishealthy, 1:trapped 2:dead
	int x,y;
	int v;
	bool isInBubble;
	// int id;
public:
	Player(int px, int py, int num, int vel );
	void incVelocity();
	void decVelocity();
	void incBubbleNum();
	void layBubble(Map &map);
	int getX() const;
	int getY() const;
	int getBubbleNum() const;
	void setState(int state);
	int getState() const;
	void countTrapTime();
	void move(int direction, Map bitMap);
	void Draw();
	int Hit(Map bitMap);
	//judge which zone is the person 


};
