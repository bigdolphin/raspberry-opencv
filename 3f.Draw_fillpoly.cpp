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
        //Ve hinh da giac phu mau
        vector< Point> contour;                 //Mang chua cac diem da giac
		contour.clear();                        //Xoa danh sach cu
        contour.push_back(Point(150, 150));
        contour.push_back(Point(250, 150));
        contour.push_back(Point(250, 300));
        contour.push_back(Point(150, 250));
        vector<vector<Point>> contour_array;    //Mang chua cac tap hop diem
        contour_array.push_back(contour);
        fillPoly( image,               //ten ma tran
                   contour_array,      //danh sach vi tri                                                         
                   Scalar(255,255,0),  //Mau sac                   
                   LINE_8              //Kieu duong thang: FILLED,LINE_4,LINE_8,LINE_AA
        );
        /*---------------------------------------*/
        namedWindow("Lenna", WINDOW_NORMAL);
        resizeWindow("Lenna",300, 300); 
        imshow("Lenna",image);//Hien thi ma tran du lieu hinh anh
        waitKey(0);//cho vo tan
        destroyAllWindows();
        return 0;
}
