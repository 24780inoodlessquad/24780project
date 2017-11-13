#include "bubble.h"

int Bubble::getBlowTime()
{
	return blowTime;
}

void Bubble::tictoc()
{
	blowTime++;
}

bool Bubble::checkTime()
{
	return blowTime >= layTime;
}

void Bubble::setBitX(int x)
{
	this->bitx = x;
}

void Bubble::setBitY(int y)
{
	this->bity = y;
}

int Bubble::getBitX() const
{
	return this->bitx;
}

int Bubble::getBitY() const
{
	return this->bity;
}

void Bubble::setState(int state)
{
	this->state = state;
}

Bubble::Bubble(int state, int pId, int xzone, int yzone, int lTime)
{
	this->state = state;
	this->playId = pId;
	this->setBitX(xzone);
	this->setBitY(yzone);
	this->layTime = lTime;
	this->blowTime = 0;
	this->range = 3;
}

void Bubble::reset(int state, int pId, int xzone, int yzone, int lTime)
{
	this->state = state;
	this->playId = pId;
	this->setBitX(xzone);
	this->setBitY(yzone);
	this->layTime = lTime;
	this->blowTime = 0;
	this->range = 3;
}

int Bubble::getRange() const
{
	return range;
}

int Bubble::getSate() const
{
	return state;
}