#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

Mat rotate(Mat src, double angle){
	Mat dst;
	//Lay vi tri trung tam
	Point2f center(src.cols/2.0, src.rows/2.0);
	//Tinh toan su chuyen doi khi xoay
	Mat r = getRotationMatrix2D(center,				//Tam xoay
								angle,				//Goc xoay
								1.0					//Ty le co gian
			);
	//Ap dung ket qua chuyen doi vao anh
	warpAffine(src,									//Anh goc
				dst,								//Anh dich
				r,									//Ma tran thong tin chuyen doi
				Size(src.cols, src.rows)			//Kich thuoc ma tran dich
	);
	return dst;
}

int main(){
	Mat image;//Mang chua du lieu hinh anh
	//Doc hinh anh tu file o che do doc mau sac
	image = imread("lenna.png", IMREAD_COLOR);
	if(image.empty()){//Kiem tra coi hinh co du lieu hay ko?
		printf("ERROR: Khong the mo hoac tim thay file nay\r\n");
		return -1;
	}
	printf("So channel: %d\r\n",image.channels());
	//Xoay ma tran 45 do
	image = rotate(image,45);
	//Hien thi ma tran du lieu hinh anh
	namedWindow("Lenna", WINDOW_NORMAL);
	resizeWindow("Lenna",300, 300);
	imshow("Lenna",image);
	waitKey(0);//cho vo tan
	destroyAllWindows();
	return 0;
}
