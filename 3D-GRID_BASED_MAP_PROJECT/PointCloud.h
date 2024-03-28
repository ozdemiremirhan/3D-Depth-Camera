#pragma once
#include"Point.h"
#include<list>
using namespace std;

class PointCloud : public Point {
	list<Point*> points;
	int pointNumber;

public:
	PointCloud();
	void setPointCloud(Point* temp);
	int getSize();

	list<Point*> getPointCloud();

	PointCloud operator+(PointCloud pointcloud);
	PointCloud operator=(PointCloud pointcloud);
};
