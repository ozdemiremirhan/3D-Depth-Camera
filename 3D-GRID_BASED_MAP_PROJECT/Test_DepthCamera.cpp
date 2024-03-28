//#include "DepthCamera.h"
//#include "Point.h"
//#include "PointCloud.h"
//#include<fstream>
//#include<iostream>
//#include<string>
//using namespace std;
//
//
//int main()
//{
//	DepthCamera DC;
//	string str;
//
//	Point* p = new Point();
//
//	cout << "Dosya adi girin: ";
//	cin >> str;
//	DC.setDepthCamera(str);
//
//	cout << DC.getDepthCamera() << endl;
//
//	PointCloud PC = DC.capture();
//
//	int a = PC.getSize();
//
//	Point* ptr = PC.getPointCloud();
//
//	for (int i = 0; i < a; i++)
//		cout << (ptr + i)->getPointX() << " " << (ptr + i)->getPointY() << " " << (ptr + i)->getPointZ() << endl;
//
//
//
//
//
//	return 0;
//
//
//
//}
