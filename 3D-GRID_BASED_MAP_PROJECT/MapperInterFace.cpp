#include"MapperInterFace.h"

MapperInterFace::MapperInterFace()
{
	recorder = new PointCloudRecorder;
}

void MapperInterFace::addGenerator(PointCloudGenerator* gen)
{
	generators.push_back(gen);
}

void MapperInterFace::setRecorder(PointCloudRecorder* rec)
{
	recorder->setPointCloudRecorder(rec->getPointClouderRecorder());
}

bool MapperInterFace::generate()
{
	if (generators.empty()) return false;
	for (int i = 0; i < generators.size(); i++) {
		PointCloud temp;
		temp = pointcloud + generators[i]->captureFor();
		pointcloud = temp;
	}
	return true;
}

bool MapperInterFace::recordPointCloud()
{
	if (pointcloud.getPointCloud().empty()) return false;
	PointCloud* pc = new PointCloud;
	*pc = pointcloud;
	recorder->save(pc);
	delete pc;
	return true;
}

bool MapperInterFace::recordMap()
{
	if (recorder->getPointClouderRecorder() == " ") return false;
	map->saveMap(recorder->getPointClouderRecorder());
	return true;
}

bool MapperInterFace::insertMap()
{
	if (pointcloud == NULL) return false;
	map->insertPointCloud(pointcloud);
	return true;
}