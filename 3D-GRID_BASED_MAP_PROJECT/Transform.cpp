
//using namespace Eigen;
#include "Transform.h"
#include<iostream>
#include<math.h>
#include "DepthCamera.h"
#include<fstream>
#include"PointCloudRecorder.h"
#include<Eigen/Dense>
using namespace std;

Transform::Transform(Eigen::Vector3d trans1, Eigen::Vector3d angle)
{
	for (int i = 0; i < trans1.rows(); i++) {

		this->trans(i) = trans1(i);
		this->angle(i) = angle(i);


	}
}

Transform::Transform()
{
}

void Transform::setTransform(Eigen::Matrix3d rotation, Eigen::Vector3d translation)
{
	//transMatrix.setIdentity();   // Set to Identity to make bottom row of Matrix 0,0,0,1
	//transMatrix.block<3, 3>(0, 0) = rotation;
	//transMatrix.block<3, 1>(0, 3) = translation;
	if (rotation.size() == 0) {
		cout << "empty";
		return;
	}
	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {

			this->transMatrix(i,j) = rotation(i, j);

		}
	}
	
	transMatrix(0,3) = translation(0);
	transMatrix(1,3) = translation(1);
	transMatrix(2,3) = translation(2);
	transMatrix(3,0) = 0.0;
	transMatrix(3,1) = 0.0;
	transMatrix(3,2) = 0.0;
	transMatrix(3,3) = 1.0;

	//this->transMatrix(rotation.rows(), rotation.cols() + translation.cols());
	/*Point* p;*/
	/*this->transMatrix(rotation.rows(), rotation.cols() + translation.cols());
	transMatrix << rotation, translation;*/
	/*this->transMatrix(3, 0) = 0;
	this->transMatrix(3, 1) = 0;
	this->transMatrix(3, 2) = 0;
	this->transMatrix(3, 3) = 1;*/
	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; i < 4; i++) {
			cout << transMatrix(i, j);
		}
	}*/

}

Transform* Transform::getTransform()
{
	return this;
}
Eigen::Matrix3d rotation2;
void Transform::setRotation(Eigen::Vector3d ang)
{
	rotation2(0, 0) = cos(ang(2)) * cos(ang(1));
	rotation2(0, 1) = cos(ang(2)) * sin(ang(1)) * sin(ang(0)) - (sin(ang(2)) * cos(ang(0)));
	rotation2(0, 2) = cos(ang(2)) * sin(ang(1)) * cos(ang(0)) + sin(ang(2)) * sin(ang(0));
	rotation2(1, 0) = sin(ang(2)) * cos(ang(1));
	rotation2(1, 1) = sin(ang(2)) * sin(ang(1)) * sin(ang(0)) + (cos(ang(2)) * cos(ang(0)));
	rotation2(1, 2) = sin(ang(2)) * sin(ang(1)) * cos(ang(0)) - cos(ang(2)) * sin(ang(0));
	rotation2(2, 0) = (-sin(ang(1)));
	rotation2(2, 1) = cos(ang(1)) * sin(ang(0));
	rotation2(2, 2) = cos(ang(1)) * cos(ang(0));
}

void Transform::setTranslation(Eigen::Vector3d tr)
{
}

Point* Transform::doTransform(Point* p)
{
	
	Eigen::Vector4d arr;
	Eigen::Vector4d pointArray;
	pointArray(0) = p->getPointX();
	pointArray(1) = p->getPointY();
	pointArray(2) = p->getPointZ();
	pointArray(3) = 1.0;

	arr = transMatrix * pointArray;

	/*arr(0,0) = transMatrix(0,0) * p->getPointX() + transMatrix(0,1) *p->getPointY() + transMatrix(0,2) *p->getPointZ() + transMatrix(0,3)*1;
	arr(1,0) = transMatrix(1,0) * p->getPointX() + transMatrix(1,1) *p->getPointY() + transMatrix(1,2) *p->getPointZ() + transMatrix(1,3)*1; 
	arr(2,0) = transMatrix(2,0) * p->getPointX() + transMatrix(2,1) *p->getPointY() + transMatrix(2,2) *p->getPointZ() + transMatrix(2,3)*1;
	arr(3,0) = 1.0;*/
	p->setPoint(arr(0), arr(1), arr(2));
	return p;
}

PointCloud* Transform::doTransform(PointCloud* pc)
{
	
	PointCloud* pcNew = new PointCloud();

	Point* pNew = new Point;
	Point* pNew2 = new Point();
	
	//list<Point*>::iterator it;
	list<Point*> ptr = pc->getPointCloud();
	list<Point*>::iterator it = ptr.begin();

	for (it; it !=ptr.end(); it++) {
		
		*it = doTransform(*it);
		pcNew->setPointCloud(*it);


	}



	return pcNew;
}


//#include "Transform.h"
//#include<iostream>
//#include<math.h>
//#include "DepthCamera.h"
//#include<fstream>
//#include"PointCloudRecorder.h"
//using namespace std;
//
//
//Transform::Transform(double trans1[3], double angle[3])
//{
//	/*trans1 = new double[3];
//	angle = new double[3];*/
//
//
//	for (int i = 0; i < 3; i++) {
//
//		this->trans[i] = trans1[i];
//		this->angle[i] = angle[i];
//	}
//
//
//}
//Transform::Transform() {
//
//}
//
//void Transform::setTransform(double rotation[3][3], double translation[3][1])
//{
//	for (int i = 0; i < 3; i++) {
//
//		for (int j = 0; j < 3; j++) {
//
//			this->transMatrix[i][j] = rotation[i][j];
//
//		}
//	}
//	Point* p;
//	this->transMatrix[0][3] = translation[0][0];
//	this->transMatrix[1][3] = translation[1][0];
//	this->transMatrix[2][3] = translation[2][0];
//	this->transMatrix[3][0] = 0;
//	this->transMatrix[3][1] = 0;
//	this->transMatrix[3][2] = 0;
//	this->transMatrix[3][3] = 1;
//
//
//}
//
//Transform* Transform::getTransform()
//{
//	return this;
//}
//
//double rotation[3][3];
//
//void Transform::setRotation(double ang[])
//{
//	rotation[0][0] = cos(ang[2]) * cos(ang[1]);
//	rotation[0][1] = cos(ang[2]) * sin(ang[1]) * sin(ang[0]) - (sin(ang[2]) * cos(ang[0]));
//	rotation[0][2] = cos(ang[2]) * sin(ang[1]) * cos(ang[0]) + sin(ang[2]) * sin(ang[0]);
//	rotation[1][0] = sin(ang[2]) * cos(ang[1]);
//	rotation[1][1] = sin(ang[2]) * sin(ang[1]) * sin(ang[0]) + (cos(ang[2]) * cos(ang[0]));
//	rotation[1][2] = sin(ang[2]) * sin(ang[1]) * cos(ang[0]) - cos(ang[2]) * sin(ang[0]);
//	rotation[2][0] = (-sin(ang[1]));
//	rotation[2][1] = cos(ang[1]) * sin(ang[0]);
//	rotation[2][2] = cos(ang[1]) * cos(ang[0]);
//
//
//}
//
//void Transform::setTranslation(double tr[])
//{
//
//}
//Point* Transform::doTransform(Point* p)
//{
//	double array[4][1];
//
//	array[0][0] = transMatrix[0][0] * p->getPointX() + transMatrix[0][1] * p->getPointY() + transMatrix[0][2] * p->getPointZ() + transMatrix[0][3] * 1;
//	array[1][0] = transMatrix[1][0] * p->getPointX() + transMatrix[1][1] * p->getPointY() + transMatrix[1][2] * p->getPointZ() + transMatrix[1][3] * 1;
//	array[2][0] = transMatrix[2][0] * p->getPointX() + transMatrix[2][1] * p->getPointY() + transMatrix[2][2] * p->getPointZ() + transMatrix[2][3] * 1;
//	array[3][0] = 1;
//
//	//Point* point=new Point();
//
//	p->setPoint(array[0][0] , array[1][0] , array[2][0] );
//
//	return p;
//
//}
//PointCloud* Transform::doTransform(PointCloud* pc)
//{
//	PointCloud* pcNew = new PointCloud(pc->getSize());
//
//	Point* pNew = new Point;
//	Point* pNew2 = new Point();
//	Point* ptr = pc->getPointCloud();
//	
//
//for (int i = 0; i < pc->getSize(); i++) {
//	pNew = pc->getPointCloud() + i;
//	pNew = doTransform(pNew);
//	Point* pls = pNew;
//	pcNew->setPointCloud(pls);
//	/*printf("%.8f %.8f %.8f\n", (ptr+i)->getPointX(), (ptr + i)->getPointY(), (ptr + i)->getPointZ());*/
//	
//	
//}
//	
//
//
//	return pcNew;
//}