#ifndef is_included_bubble
#define is_included_bubble
class Bubble
{
protected:
	int playId;
	int range;
	int bitx, bity;
	int blowTime;
	int layTime;
	int state; //0: inactive, 1 avtive
public:
	Bubble(){bitx = 0; bity = 0; int state = 0;};
	Bubble(int state, int pId, int xzone, int yzone, int lTime);
	Bubble(int state, int xzone, int yzone)
	{
		state = state;
		bitx = xzone;
		bity = yzone;
	}

	Bubble(const Bubble& other)
	{
		state = other.state;
		playId = other.playId;
		bitx = other.bitx;
		bity = other.bity;
		layTime = other.blowTime;
	}
	void expose();
	void checkTime();
	void setBitX(int x);
	void setBitY(int y);
	void increaseRange();
	int getRange() const;
	int getSate() const;
	~Bubble(){};
	const Bubble& operator=(const Bubble& other)
	{
		state = other.state;
		playId = other.playId;
		bitx = other.bitx;
		bity = other.bity;
		layTime = other.blowTime;
		return *this;
	}
};
#endif