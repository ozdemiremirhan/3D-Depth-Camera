#include "Transform.h"
#include<iostream>
#include<math.h>
#include "DepthCamera.h"
#include<fstream>
#include"PointCloudRecorder.h"
#include"PointCloudGenerator.h"
#include"MapperInterFace.h"
using namespace std;

int main() {
	double* ar1 = NULL;
	double* ar2 = NULL;
	PointCloud* pc = new PointCloud;
	Transform* transform = new Transform();
	DepthCamera* camera = new DepthCamera;
	PointCloudRecorder* recorder = new PointCloudRecorder;
	PointCloudGenerator* gen = new DepthCamera();
	PointCloudGenerator* gen1 = new DepthCamera();
	PointCloudGenerator* gen2 = new DepthCamera();
	PointCloudGenerator* gen3 = new DepthCamera();
	int number = 0;
	cout << "------------------------------------------------------[TEST CODE]------------------------------------------------------";
	cout << " \n\n 1: cam\n 2: cam1\n 3: cam2\n 4: cam3\n 5: concatenated " << endl;
	cout << "Choose camera: ";
	cin >> number;

	if (number == 1) {

		MapperInterFace* temp = new MapperInterFace;
		gen->setDepthCamera("cam.txt");
		
		
		//*pc = camera->capture();
		Eigen::Vector3d translation;
		translation<<  1.95704,1.93000, 1.05707 ;
		Eigen::Matrix3d rotation;
		rotation << -0.7076050,0.0065031,-0.7065783,0.7066082,0.0065134,-0.7075750,0.0000008,-0.9999576,-0.0092041 ;
		////transform->setTransform(rotation, translation);
		gen->getTransform()->setTransform(rotation, translation);
		temp->addGenerator(gen);
		temp->generate();
		//gen->captureFor();
		recorder->setPointCloudRecorder("newfile.txt");
		temp->setRecorder(recorder);
		temp->recordPointCloud();
		//recorder.save(pc);

	}
	else if (number == 2) {
		MapperInterFace* temp = new MapperInterFace;
		gen->setDepthCamera("cam1.txt");
		Eigen::Vector3d translation1;
		translation1 <<  -1.91288,1.94412, 1.05465 ;
		Eigen::Matrix3d rotation1;
		rotation1 << -0.6638364,-0.0068830,0.7478462,-0.7478778,0.0061099,-0.6638082,-0.0000002,-0.9999576,-0.0092036 ;
		gen->getTransform()->setTransform(rotation1, translation1);
		temp->addGenerator(gen);
		temp->generate();
		recorder->setPointCloudRecorder("newfile1.txt");
		temp->setRecorder(recorder);
		temp->recordPointCloud();


	}
	else if (number == 3) {
		MapperInterFace* temp = new MapperInterFace;
		gen->setDepthCamera("cam2.txt");
		Eigen::Vector3d translation2;
		translation2 << 1.96978,-1.94622, 1.05264 ;
		Eigen::Matrix3d rotation2;
		rotation2 <<  0.8762180,0.0044351,-0.4818945,0.4819149,-0.0080638,0.8761809,0.0000001,-0.9999577,-0.0092030 ;
		gen->getTransform()->setTransform(rotation2, translation2);
		temp->addGenerator(gen);
		temp->generate();
		recorder->setPointCloudRecorder("newfile2.txt");
		temp->setRecorder(recorder);
		temp->recordPointCloud();



	}
	else if (number == 4) {
		MapperInterFace* temp = new MapperInterFace;
		gen->setDepthCamera("cam3.txt");
		Eigen::Vector3d translation3;
		translation3 << -1.87445,-1.95027,1.06432 ;
		Eigen::Matrix3d rotation3;
		rotation3 << 0.3597052,-0.0085871,0.9330265,-0.9330660,-0.0033108,0.3596900,0.0000003,-0.9999576,-0.0092033 ;
		gen->getTransform()->setTransform(rotation3, translation3);
		temp->addGenerator(gen);
		temp->generate();
		recorder->setPointCloudRecorder("newfile3.txt");
		temp->setRecorder(recorder);
		temp->recordPointCloud();

	}
	else if (number == 5) {
		MapperInterFace* temp = new MapperInterFace;
		gen->setDepthCamera("cam.txt");
		gen1->setDepthCamera("cam1.txt");
		gen2->setDepthCamera("cam2.txt");
		gen3->setDepthCamera("cam3.txt");
		Eigen::Vector3d translation;
		translation << 1.95704, 1.93000, 1.05707;
		Eigen::Matrix3d rotation;
		rotation << -0.7076050, 0.0065031, -0.7065783, 0.7066082, 0.0065134, -0.7075750, 0.0000008, -0.9999576, -0.0092041;
		gen->getTransform()->setTransform(rotation, translation);


		Eigen::Vector3d translation1;
		translation1 << -1.91288, 1.94412, 1.05465;
		Eigen::Matrix3d rotation1;
		rotation1 << -0.6638364, -0.0068830, 0.7478462, -0.7478778, 0.0061099, -0.6638082, -0.0000002, -0.9999576, -0.0092036;
		gen1->getTransform()->setTransform(rotation1, translation1);


		Eigen::Vector3d translation2;
		translation2 << 1.96978, -1.94622, 1.05264;
		Eigen::Matrix3d rotation2;
		rotation2 << 0.8762180, 0.0044351, -0.4818945, 0.4819149, -0.0080638, 0.8761809, 0.0000001, -0.9999577, -0.0092030;
		gen2->getTransform()->setTransform(rotation2, translation2);


		Eigen::Vector3d translation3;
		translation3 << -1.87445, -1.95027, 1.06432;
		Eigen::Matrix3d rotation3;
		rotation3 << 0.3597052, -0.0085871, 0.9330265, -0.9330660, -0.0033108, 0.3596900, 0.0000003, -0.9999576, -0.0092033;
		gen3->getTransform()->setTransform(rotation3, translation3);

		temp->addGenerator(gen);
		temp->addGenerator(gen1);
		temp->addGenerator(gen2);
		temp->addGenerator(gen3);

		temp->generate();
		recorder->setPointCloudRecorder("concatenated.txt");
		temp->setRecorder(recorder);
		temp->recordPointCloud();
	}






	return 0;
}
