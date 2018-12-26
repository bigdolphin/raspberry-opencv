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
        //Viet chu  
        putText(image,                 //ten ma tran
                "Lop hoc Xu ly anh",   //Noi dung van ban
                Point(200, 200),       //Vi tri
                FONT_HERSHEY_SIMPLEX,  //Font:
                                       //FONT_HERSHEY_SIMPLEX
                                       //FONT_HERSHEY_PLAIN
                                       //FONT_HERSHEY_DUPLEX
                                       //FONT_HERSHEY_COMPLEX
                                       //FONT_HERSHEY_TRIPLEX
                                       //FONT_HERSHEY_COMPLEX_SMALL
                                       //FONT_HERSHEY_SCRIPT_SIMPLEX
                                       //FONT_HERSHEY_SCRIPT_COMPLEX
                0.8,                   //Kich co
                Scalar(255, 255, 255), //Mau sac
                4,                     //Do day net
                LINE_AA                //Kieu net 
                );      
        /*---------------------------------------*/
        namedWindow("Lenna", WINDOW_NORMAL);
        resizeWindow("Lenna",300, 300); 
        imshow("Lenna",image);//Hien thi ma tran du lieu hinh anh
        waitKey(0);//cho vo tan
        destroyAllWindows();
        return 0;
}
