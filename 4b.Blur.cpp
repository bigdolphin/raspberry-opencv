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
	//Lam nhoe anh
	blur(image,		 //Anh goc
	     image,		 //Anh dich
	     Size(20,20),//Kich thuoc nhan (kernel)
		 Point(-1,-1)//Vi tri neo				
	);
	namedWindow("Lenna", WINDOW_NORMAL);
	resizeWindow("Lenna",300, 300);
	imshow("Lenna",image);//Hien thi ma tran du lieu hinh anh
	waitKey(0);//cho vo tan
	destroyAllWindows();
	return 0;
}
