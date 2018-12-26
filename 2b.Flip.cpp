#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main(){
	Mat image;//Mang chua du lieu hinh anh
	image = imread("lenna.png", IMREAD_COLOR);//doc hinh anh tu file o che do doc mau sac
	if(image.empty()){//Kiem tra coi hinh co du lieu hay ko?
		printf("ERROR: Khong the mo hoac tim thay file nay\r\n");
		return -1;
	}
	printf("So channel: %d\r\n",image.channels());
	flip(image,		//Anh goc
		 image,		//Anh dich
		 0			//Co: 0 - lat theo truc ngang,
					//	  1 - lat truc doc,
					//   -1 - lat 2 truc
	);
	namedWindow("Lenna", WINDOW_NORMAL);
	resizeWindow("Lenna",300, 300);
	imshow("Lenna",image);//Hien thi ma tran du lieu hinh anh
	waitKey(0);//cho vo tan
	destroyAllWindows();
	return 0;
}
