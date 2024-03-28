#include "3D_GridMap.h"
#include<iostream>
#include<list>
using namespace std;

void ThreeDGripMap::insertPointCloud(PointCloud& pc)
{
	list<Point*>::iterator it;
	//Point* pNew = new Point;
	//Point *ptr = pc->getPointCloud();
	//list<Point*>pc;
	for (it = pc.getPointCloud().begin(); it != pc.getPointCloud().end(); it++) {
		
		insertPoint(**it);
	}
}

void ThreeDGripMap::insertPoint(Point& p)
{
	
	int i = p.getPointX() / gridSize;
	int j = p.getPointY() / gridSize;
	int k = p.getPointZ() / gridSize;


	if (i > 0 && j > 0 && k > 0)
		map[22 + i + 1][22 + j + 1][22 + k + 1] = true;
	else if (i > 0 && j > 0 && k < 0)
		map[22 + i + 1][22 + j + 1][22 - k - 1] = true;
	else if (i > 0 && j < 0 && k > 0)
		map[22 + i + 1][22 - j - 1][22 + k + 1] = true;
	else if (i > 0 && j < 0 && k < 0)
		map[22 + i + 1][22 - j - 1][22 - k - 1] = true;
	else if (i < 0 && j > 0 && k > 0)
		map[22 - i - 1][22 + j + 1][22 + k + 1] = true;
	else if (i < 0 && j > 0 && k < 0)
		map[22 - i - 1][22 + j + 1][22 - k - 1] = true;
	else if (i < 0 && j < 0 && k > 0)
		map[22 - i - 1][22 - j - 1][22 + k + 1] = true;
	else if (i < 0 && j < 0 && k < 0)
		map[22 - i - 1][22 - j - 1][22 - k - 1] = true;
	else
		false;


	
}

bool ThreeDGripMap::getGrid(int x, int y, int z) const
{
	if (map[x][y][z] == true)
		return true;
	else
		return false;
}

bool ThreeDGripMap::loadMap(string fileName)
{

    return false;
}

bool ThreeDGripMap::saveMap(string fileName)
{
	return false;
}
