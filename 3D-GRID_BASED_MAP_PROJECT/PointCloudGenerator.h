#pragma once
//#include "MapperInterface.h"
#include"Transform.h"
#include<vector>
class Transform;
class PointCloudGenerator
{
protected:
	Transform *transform;
public:
	Transform* getTransform() { return transform; }
	PointCloudGenerator() {
		transform = new Transform;
	}
	virtual void setDepthCamera(string fileName)=0;
	virtual PointCloud capture() = 0;
	virtual PointCloud captureFor() = 0;
};
