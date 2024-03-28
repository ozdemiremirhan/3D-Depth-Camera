#include "Point.h"
#include<math.h>

void Point::setPoint(double _x, double _y, double _z)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;

}

double Point::getPointX()
{
	return this->x;
}
double Point::getPointY()
{
	return this->y;
}
double Point::getPointZ()
{
	return this->z;
}

bool Point::operator==(const Point& point)
{
	if (point.x == x && point.y == y && point.z == z)
		return true;

	else
		return false;

}

double Point::distance(const Point& point) const
{
	double distance = sqrt(pow((point.x - x), 2) + pow((point.y - y), 2) + pow((point.z - z), 2));
	return distance;
}
