#pragma once
//using namespace Eigen;
using namespace std;
#include "Point.h"
#include "PointCloud.h"
#include<Eigen/Dense>

class Transform {

private:
	Eigen::Vector3d angle;
	Eigen::Vector3d trans;
	Eigen::Matrix4d transMatrix;

public:
	Transform(Eigen::Vector3d trans1, Eigen::Vector3d angle);
	Transform();
	void setTransform(Eigen::Matrix3d rotation, Eigen::Vector3d translation);
	Transform* getTransform();
	void setRotation(Eigen::Vector3d ang);
	void setTranslation(Eigen::Vector3d tr);
	Point* doTransform(Point* p);
	PointCloud* doTransform(PointCloud* pc);

};

//#pragma once
//#include "Point.h"
//#include "PointCloud.h"
//
//
//class Transform {
//
//private:
//	double angle[3];
//	double trans[3];
//	double transMatrix[4][4];
//
//public:
//	Transform(double trans1[3], double angle[3]);
//	Transform();
//	void setTransform(double rotation[3][3], double translation[3][1]);
//	Transform* getTransform();
//	void setRotation(double ang[]);
//	void setTranslation(double tr[]);
//	Point* doTransform(Point* pc);
//	PointCloud* doTransform(PointCloud* pc);
//
//};