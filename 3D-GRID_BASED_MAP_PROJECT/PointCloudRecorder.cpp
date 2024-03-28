#include "PointCloudRecorder.h"
#include<fstream>

void PointCloudRecorder::setPointCloudRecorder(string name)
{
	this->filename = name;
	fstream file;
	file.open(filename, ios::out);
	file.close();
}

PointCloudRecorder::PointCloudRecorder(string name)
{
	this->filename = name;
	fstream file;
	file.open(filename, ios::out);
	file.close();
}

string PointCloudRecorder::getPointClouderRecorder()
{
	return filename;
}

bool PointCloudRecorder::save(PointCloud* pc)
{
	fstream file;
	file.open(filename, ios::out);
	list<Point*> ptr = pc->getPointCloud();
	if (ptr.empty()) return false;
	list<Point*>::iterator it = ptr.begin();

	for (it; it != ptr.end(); it++) {
		Point* po = *it;
		file << po->getPointX() << " " << po->getPointY() << " " << po->getPointZ() << endl;
	}
	cout << "File saved.. " << endl;
	return true;
}