#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
        Mat image;//Mang chua du lieu hinh anh    
		//doc hinh anh tu file o che do doc mau sac
        image = imread("lenna.png", IMREAD_COLOR);
        if(image.empty()){//Kiem tra coi hinh co du lieu hay ko?
            printf("Khong the mo hoac tim thay file nay\r\n");
            return -1;
        }
        //Ve duong thang
        line( image,          //ten ma tran
             Point(0,0),      //Diem bat dau
             Point(400,400),  //Diem ket thuc
             Scalar(0,0,0),   //Mau sac BGR
             1.5,             //Do day
             LINE_8           //Kieu duong thang: FILLED,LINE_4,LINE_8,LINE_AA
        );        
        /*---------------------------------------*/
        namedWindow("Lenna", WINDOW_NORMAL);
        resizeWindow("Lenna",300, 300); 
        imshow("Lenna",image);//Hien thi ma tran du lieu hinh anh
        waitKey(0);//cho vo tan
        destroyAllWindows();
        return 0;
}
