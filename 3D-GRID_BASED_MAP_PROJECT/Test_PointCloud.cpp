//#include"PointCloud.h"
//#include"Point.h"
//#include<iostream>
//using namespace std;
//int main()
//{
//	Point* p1 = new Point(1.1, 2.2, 3.3);
//	Point* p2 = new Point(4.4, 5.5, 6.6);
//	PointCloud* pc = new PointCloud(2);
//	pc->setPointCloud(p1);
//	pc->setPointCloud(p2);
//
//	Point* ptr = pc->getPointCloud();
//	cout << "pc: " << endl;
//	for (int i = 0; i < 2; i++)
//	{
//		cout << "x = " << (ptr + i)->getPointX() << " y = " << (ptr + i)->getPointY() << " z = " << (ptr + i)->getPointZ() << endl;
//
//	}
//
//	PointCloud* temp = new PointCloud(2);
//	temp = pc;
//	ptr = temp->getPointCloud();
//	cout << "after temp = pc, temp: " << endl;
//	for (int i = 0; i < 2; i++)
//	{
//		cout << "x = " << (ptr + i)->getPointX() << " y = " << (ptr + i)->getPointY() << " z = " << (ptr + i)->getPointZ() << endl;
//
//	}
//	return 0;
//
//
//}