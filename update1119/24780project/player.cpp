#include "player.h"

Player::Player(int px, int py, int num, int vel)
{
    x = px;
    y = py;
    v = vel;
	BubbleNum = num;    
	isInBubble = false;
}

void Player::incVelocity()
{
	v += 5;
}

void Player::decVelocity()
{
	v -= 5;
}

void Player::incBubbleNum()
{
	BubbleNum++;
}

int Player::getBubbleNum() const
{
	return BubbleNum;
}

void Player::layBubble(Map &map)
{
	if(BubbleNum > 0)
	{
		map.setMapState(this->getY()/50,this->getX()/50, 4);
		BubbleNum--;
		printf("%d	%d\n",this->getY(),this->getX());
	}
}

void Player::plusNum(int num)
{
	this->BubbleNum += num;
}

int Player::getX() const
{
//	printf("x: %d\n",x);
	return x;
}

int Player::getY() const
{
//	printf("y: %d\n", y);
	return y;
}

void Player::setState(int state)
{
	this->state = state;
}

void Player::Draw(void)
{
	const double pi = 3.14159265359;
	const double r = 15.;
	const double r2 = 18.;
	double dx = 0, dy = 0;
	double cx = x;
	double cy = y - 50;

	glBegin(GL_TRIANGLES);
	glColor3ub(0, 0, 0);
	glVertex2d(x		, y);
	glVertex2d(x + 25	, y - 40);
	glVertex2d(x - 25	, y - 40);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 0, 0);
	glVertex2d(x	, y - 40);
	glVertex2d(x + 5, y - 20);
	glVertex2d(x	, y - 15);
	glVertex2d(x - 5, y - 20);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 0);
	for (int i = 0; i < 33; ++i)
	{
		dx = r*cos((double)i*pi / 32.);
		dy = r*sin((double)i*pi / 32.);
		glVertex2d(cx + dx, cy + dy);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0, 255, 0);
	for (int i = 32; i < 65; ++i)
	{
		dx = r2*cos((double)i*pi / 32.);
		dy = r2*sin((double)i*pi / 32.);
		glVertex2d(cx + dx, cy + dy);
	}
	glEnd();

	//printf("%d	%d\n",x,y);

}

int Player::getState() const
{
	return this->state;
}

int Player::Hit(Map bitMap)
{
	double x1 = x - 15;
	double y1 = y - 30;
	double x2 = x + 15;
	double y2 = y - 30;
	double x3 = x + 15;
	double y3 = y;
	double x4 = x - 15;
	double y4 = y;
	return 0;
//	if (bitMap.getPixel((int)(x1 - 1) / 50, (int)(y1 - 1) / 50))
//	{

//	}
}

void Player::move(int direction, Map bitMap)
{
	int bitX, bitY;
	bitX = (int)x / 50;
	bitY = (int)y / 50;

	double x1 = x - 15;
	double y1 = y - 30;
	double x2 = x + 15;
	double y2 = y - 30;
	double x3 = x + 15;
	double y3 = y;
	double x4 = x - 15;
	double y4 = y;

	if (direction == 1 && 0 == bitMap.getPixel((int)(y1 - v) / 50, (int)x1 / 50) && 0 == bitMap.getPixel((int)(y2 - v) / 50, (int)x2 / 50))
	{
		y -= v;
	}
	if(direction == 2 && 0 == bitMap.getPixel((int)y1 / 50, (int)(x1 - v) / 50) && 0 == bitMap.getPixel((int)y4 / 50, (int)(x4 - v) / 50))
	{
		x -= v;
	}
	if(direction == 3 && 0 == bitMap.getPixel((int)(y3 + v) / 50, (int)x3 / 50) && 0 == bitMap.getPixel((int)(y4 + v) / 50, (int)x4 / 50))
	{
		y += v;
	}
	if(direction == 4 && 0 == bitMap.getPixel( (int)y2/ 50, (int)(x2 + v) / 50) && 0 == bitMap.getPixel( (int)y3 / 50, (int)(x3 + v) / 50))
	{
		x += v;
	}
//	printf("%d	%d",x,y);
}