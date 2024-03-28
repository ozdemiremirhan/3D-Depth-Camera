#pragma once

#include<iostream>
using namespace std;

class Point {

private:
	double x;
	double y;
	double z;

public:
	Point(double x=0.0, double y=0.0, double z=0.0) : x(x),y(y),z(z) { }

	void setPoint(double _x,double _y,double _z);
	double getPointX();
	double getPointY();
	double getPointZ();
	bool operator==(const Point&point);
	double distance(const Point&point) const;
};
