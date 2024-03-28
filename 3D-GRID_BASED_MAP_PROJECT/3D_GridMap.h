#pragma once
#include "PointCloud.h"
#include<iostream>

using namespace std;


class ThreeDGripMap {

	bool map[46][46][46];
	float gridSize;
	int depth;

public:
	ThreeDGripMap() { 

		for (int i = 0; i < 46; i++) {
			for (int j = 0; j < 46; j++) {

				for (int k = 0; k < 46; k++) {

					map[i][j][k] = false;
				}
			}
		}
	}
	void setGridSize(float& gridSize) { this->gridSize = gridSize; }

	float getGridSize() { return this->gridSize; }

	void insertPointCloud(PointCloud &pc);
	void insertPoint(Point& p);
	bool getGrid(int x, int y, int z) const;
	bool loadMap(string fileName);
	bool saveMap(string fileName);



};