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
        //Ve hinh tron
        circle( image,                           //ten ma tran
                Point(image.cols/2,image.rows/2),//Tam
                50,                              //Ban kinh
                Scalar( 0, 0, 255 ),             //Mau sac
                -1,                              //Do day vien>=0,neu do day<0 se to mau toan bo
                LINE_8                           //Kieu duong thang: FILLED,LINE_4,LINE_8,LINE_AA
        );  
        /*---------------------------------------*/
        namedWindow("Lenna", WINDOW_NORMAL);
        resizeWindow("Lenna",300, 300); 
        imshow("Lenna",image);//Hien thi ma tran du lieu hinh anh
        waitKey(0);//cho vo tan
        destroyAllWindows();
        return 0;
}
