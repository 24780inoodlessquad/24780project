#include "map.h"
void Map::setMapState(int x, int y, int state)
{
	this->map[x][y] = state;
}

int Map::getPixel(int bitX, int bitY) const
{
	return this->map[bitX][bitY];
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
			}
		}
	}
}