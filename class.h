#include <vector>
class Map
{
protected:
	enum map_array {floor = 0, box = 1, obstacle = 2};
public:
	void setPixel();
	int  getPixel();
	void Draw();
};

class Player
{
	std::vector<Bubble> bubble;

};

class Bubble
{

};

class Tool
{

};

class Menu
{

};