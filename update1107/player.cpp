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

void Player::layBubble(Map &map)
{
	map.setMapState(this->getX()/50,this->getY()/50, 4);
}

int Player::getX() const
{
	return x;
}

int Player::getY() const
{
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
}

int Player::getState() const
{
	return this->state;
}

void Player::move(int direction)
{
	if(direction == 1)
	{
		y -= v;
	}
	if(direction == 2)
	{
		y -= v;
	}
	if(direction == 3)
	{
		y += v;
	}
	if(direction == 4)
	{
		x += v;
	}
}