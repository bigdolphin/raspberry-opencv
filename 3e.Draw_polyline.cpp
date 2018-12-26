#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
        Mat image;//Mang chua du lieu hinh anh
        image = imread("lenna.png", IMREAD_COLOR);//doc hinh anh tu file o che do doc mau sac
        if(image.empty()){//Kiem tra coi hinh co du lieu hay ko?
                        printf("Khong the mo hoac tim thay file nay\r\n");
                        return -1;
        }
        //Ve duong da giac
        vector< Point> contour;                 //Mang chua cac diem da giac
        contour.push_back(Point(50, 50));
        contour.push_back(Point(300, 50));
        contour.push_back(Point(35, 200));
        contour.push_back(Point(300, 150));
        contour.push_back(Point(150, 35));
        contour.push_back(Point(100, 100));        
        polylines( image,                       //ten ma tran
                   contour,                     //danh sach vi tri                                                         
                   true,                        //Hinh kin hay ho
                   Scalar(255,255,0),           //Mau sac
                   1,                           //Do day vien>=0
                   LINE_8                       //Kieu duong thang: FILLED,LINE_4,LINE_8,LINE_AA
        ); 
        /*---------------------------------------*/
        namedWindow("Lenna", WINDOW_NORMAL);
        resizeWindow("Lenna",300, 300); 
        imshow("Lenna",image);//Hien thi ma tran du lieu hinh anh
        waitKey(0);//cho vo tan
        destroyAllWindows();
        return 0;
}
