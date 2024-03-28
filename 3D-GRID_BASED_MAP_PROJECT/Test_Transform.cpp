/*#include "Transform.h"
#include<iostream>
#include<math.h>
#include "DepthCamera.h"
#include<fstream>
#include"PointCloudRecorder.h"
using namespace std;

int main() {
	double* ar1 = NULL;
	double* ar2 = NULL;
	PointCloud* pc = new PointCloud(70000);
	Transform* transform = new Transform();
	DepthCamera* camera = new DepthCamera();
	PointCloudRecorder recorder;
	int number = 0;
	cout << " 1: cam\n 2: cam1\n 3: cam2\n 4: cam3\n " << endl;
	cout << "Choose camera: ";
	cin >> number;
	
		if (number == 1) {
			camera->setDepthCamera("cam.txt");
			*pc = camera->capture();
			double translation[3][1]{ {1.95704},{1.93000}, {1.05707} };
			double rotation[3][3] = { {-0.7076050,0.0065031,-0.7065783},{0.7066082,0.0065134,-0.7075750},{0.0000008,-0.9999576,-0.0092041} };
			transform->setTransform(rotation, translation);
			transform->doTransform(pc);
			recorder.setPointCloudRecorder("newfile.txt");
			recorder.save(pc);
			
		}
		else if (number == 2) {
			camera->setDepthCamera("cam1.txt");
			*pc = camera->capture();
			double translation1[3][1]{ {-1.91288},{1.94412}, {1.05465} };
			double rotation1[3][3] = { {-0.6638364,-0.0068830,0.7478462},{-0.7478778,0.0061099,-0.6638082},{-0.0000002,-0.9999576,-0.0092036} };
			transform->setTransform(rotation1, translation1);
			transform->doTransform(pc);
			recorder.setPointCloudRecorder("newfile1.txt");
			recorder.save(pc);
			

		}
		else if (number == 3) {
			camera->setDepthCamera("cam2.txt");
			*pc = camera->capture();
			double translation2[3][1]{ {1.96978},{-1.94622}, {1.05264} };
			double rotation2[3][3] = { {0.8762180,0.0044351,-0.4818945},{0.4819149,-0.0080638,0.8761809},{0.0000001,-0.9999577,-0.0092030} };
			transform->setTransform(rotation2, translation2);
			transform->doTransform(pc);
			recorder.setPointCloudRecorder("newfile2.txt");
			recorder.save(pc);
		

		}
		else if (number == 4) {
			camera->setDepthCamera("cam3.txt");
			*pc = camera->capture();
			double translation3[3][1]{ {-1.87445},{-1.95027}, {1.06432} };
			double rotation3[3][3] = { {0.3597052,-0.0085871,0.9330265},{-0.9330660,-0.0033108,0.3596900},{0.0000003,-0.9999576,-0.0092033} };
			transform->setTransform(rotation3, translation3);
			transform->doTransform(pc);
			recorder.setPointCloudRecorder("newfile3.txt");
			recorder.save(pc);
			
		}

	
	



	return 0;
}*/