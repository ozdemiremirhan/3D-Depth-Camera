//#include"PointCloudRecorder.h"
//#include"PointCloud.h"
//#include<iostream>
//
//using namespace std;
//
//int main() {
//
//	PointCloudRecorder temp;
//	PointCloudRecorder temp2("hello.txt");
//	temp.setPointCloudRecorder("change.txt");
//
//	cout << "there is 2 files\nOne of them is: " << temp.getPointClouderRecorder() << endl << "The other one is: "
//		<< temp2.getPointClouderRecorder() << endl;
//	Point* p1 = new Point(1.1, 1.2, 1.3);
//	Point* p2 = new Point(2.1, 2.2, 2.3);
//	Point* p3 = new Point(3.1, 3.2, 3.3);
//	PointCloud* cloud = new PointCloud(4);
//	cloud->setPointCloud(p1);
//	cloud->setPointCloud(p2);
//	if (temp.save(cloud) == false) return 0;
//	cloud->setPointCloud(p3);
//	if (temp2.save(cloud) == false) return 0;
//
//	cout << "The files have been created successfuly\n\n";
//	return 0;
//}