#pragma once
#include<iostream>
using namespace std;
#include "PointCloud.h"
#include "PointCloudGenerator.h"

class DepthCamera : public PointCloudGenerator{
	
private:
	string fileName;

public:
	
	DepthCamera() {};
	string getDepthCamera();
	void setDepthCamera(string fileName);
	PointCloud capture();
	PointCloud captureFor();


};