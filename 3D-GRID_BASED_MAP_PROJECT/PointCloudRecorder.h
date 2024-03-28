#pragma once

#include"PointCloud.h"
#include<string>

class PointCloudRecorder {

private:
	string filename;

public:
	PointCloudRecorder(string name);
	PointCloudRecorder() {}
	void setPointCloudRecorder(string name);
	string getPointClouderRecorder();

	bool save(PointCloud* pc);
};