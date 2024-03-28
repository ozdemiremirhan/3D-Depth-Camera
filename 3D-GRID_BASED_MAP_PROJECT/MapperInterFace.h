#pragma once
#include<vector>
#include"PointCloud.h"
#include"PointCloudGenerator.h"
#include"PointCloudRecorder.h"
#include "Map.h"

class MapperInterFace {
private:
	PointCloud pointcloud;
	PointCloud patch;
	vector<PointCloudGenerator*> generators;
	PointCloudRecorder* recorder;
	 Map* map;

public:
	MapperInterFace();
	void addGenerator(PointCloudGenerator*);
	void setRecorder(PointCloudRecorder*);
	bool generate();
	bool recordPointCloud();
	bool recordMap();
	bool insertMap();
};

