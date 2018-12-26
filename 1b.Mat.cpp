#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main(){
	int rows = 50;	//Chieu cao (height)
	int cols = 50;	//Chieu rong (width)
	Mat image(rows,cols,CV_8UC3,Scalar(0,0,255)); 	
	/*---- In ra noi dung ma tran ----------------*/
	printf("[");
	for(int i=0; i<image.cols; i++){
		for(int j=0; j<image.rows;j++){
			uchar *p = image.ptr<uchar>(i,j);
			printf("(%d,%d,%d),",p[0],p[1],p[2]);
		}
		printf("\r\n");
	}
	printf("]\r\n");	
	printf("So channel: %d\r\n",image.channels());
	/*---- Hien thi ra cua so -------------------*/
	imshow("Mat",image);
	/*---- Cho vo tan cho den khi co phim nhan --*/
	waitKey();
	return 0;
}
