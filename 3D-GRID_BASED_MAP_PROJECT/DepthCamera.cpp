#include "DepthCamera.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

string DepthCamera::getDepthCamera()
{
	return this->fileName;
}

void DepthCamera::setDepthCamera(string fileName)
{
	this->fileName = fileName;
}

PointCloud DepthCamera::capture()
{
	fstream file;
	//cin >> fileName;


	file.open(fileName.c_str(), ios::in);

	string str;
	double x, y, z;
	int b1, b2, b3;
	file >> str;
	file >> str;
	file >> str;
	file >> str;
	file >> str;
	file >> str;
	int size;
	file >> size;


	Point* p= new Point();
	PointCloud PC;
	while (file >> x >> y >> z >> b1 >> b2 >> b3) {
		
		p->setPoint(x, y, z);
		//cout << p->getPointX() << " " << p->getPointY() << " " << p->getPointZ() << endl;
		
		PC.setPointCloud(p);
		//cout << p->getPointX() << " " << p->getPointY() << " " << p->getPointZ() << endl;
	}
	/*Point* ptr = PC.getPointCloud();*/

	/*for (int i = 0; i < size; i++)
		cout << (ptr + i)->getPointZ()<<endl;*/


	return PC;
	
}
PointCloud DepthCamera::captureFor() {

	fstream file;
	//cin >> fileName;


	file.open(fileName.c_str(), ios::in);

	string str;
	double x, y, z;
	int b1, b2, b3;
	file >> str;
	file >> str;
	file >> str;
	file >> str;
	file >> str;
	file >> str;
	int size;
	file >> size;


	
	PointCloud* PC = new PointCloud;
	
	while (file >> x >> y >> z >> b1 >> b2 >> b3) {

		Point* p = new Point(x,y,z);
		//cout << p->getPointX() << " " << p->getPointY() << " " << p->getPointZ() << endl;

		PC->setPointCloud(p);

	}
	PC = transform->doTransform(PC);
	/*Point* ptr = PC.getPointCloud();*/

	/*for (int i = 0; i < size; i++)
		cout << (ptr + i)->getPointZ()<<endl;*/
	

	return *PC;


}











