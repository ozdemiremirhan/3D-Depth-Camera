#include"PointCloud.h"
#include"PointCloud.h"
#include<iostream>
using namespace std;

PointCloud::PointCloud() {
	pointNumber = 0;
}

void PointCloud::setPointCloud(Point* temp) {

	points.push_back(temp);
	pointNumber++;
}

list<Point*> PointCloud::getPointCloud() {

	return points;
}

int PointCloud::getSize()
{
	return pointNumber;
}

PointCloud PointCloud::operator+(PointCloud pointcloud)
{
	for (list<Point*>::iterator ptr = pointcloud.points.begin(); ptr != pointcloud.points.end(); ptr++) {
		points.push_back(*ptr);
		pointNumber++;
	}
	return *(this);
}

PointCloud PointCloud::operator=(PointCloud pointcloud)
{
	if (points.empty()) {
		for (list<Point*>::iterator ptr = pointcloud.points.begin(); ptr != pointcloud.points.end(); ptr++) {
			points.push_back(*ptr);
		}
		return *(this);
	}
	else {
		points.clear();
		for (list<Point*>::iterator ptr = pointcloud.points.begin(); ptr != pointcloud.points.end(); ptr++) {
			points.push_back(*ptr);
		}
		return *(this);
	}

}

//PointCloud::PointCloud(int size) {
//	points = new Point[size];
//	pointNumber = 0;
//}
//
//void PointCloud::setPointCloud(Point* temp) {
//	
//	points[pointNumber] = *temp;
//	pointNumber++;
//}
//
//Point* PointCloud::getPointCloud() {
//	
//	
//	return points;
//}
//
//int PointCloud::getSize()
//{
//	return pointNumber;
//}
//
//PointCloud PointCloud::operator+(const PointCloud& pointcloud)
//{
//	int toplam = pointNumber + pointcloud.pointNumber;
//	PointCloud temp(toplam);
//
//	for (int i = 0; i < pointNumber; i++)
//	{
//		temp.setPointCloud(points + i);
//	}
//	for (int i = 0; i < pointcloud.pointNumber; i++) {
//		temp.setPointCloud((pointcloud.points) + i);
//	}
//	return temp;
//
//}
//
//PointCloud PointCloud::operator=(const PointCloud& pointcloud)
//{
//	if (pointNumber != pointcloud.pointNumber) {
//
//		delete this;
//		this->points = new Point[pointcloud.pointNumber];
//		this->pointNumber = pointcloud.pointNumber;
//	}
//	for (int i = 0; i < pointcloud.pointNumber; i++) {
//		this->points[i] = pointcloud.points[i];			
//	}
//	return *(this);
//}