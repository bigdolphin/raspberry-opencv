#include<opencv2/imgproc.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>

using namespace cv;
using namespace std;

Mat image;		  //Ma tran anh goc
Mat image_select; //Ma tran anh ve vi tri duoc chon
Mat image_mask;   //Ma tran mat na tao ra tu cac vi tri duoc chon
Mat image_crop;	  //Ma tran chua hinh cat boi mat na

Point selected_point;	  //Vi tri vua duoc nhan
int selected_npts = 0;	  //Bien dem so luong vi tri da chon
vector<Point> selected_pts;//Danh sach cac vi tri
void mouseHandler(int, int, int, int, void*);

int main(){    
	image = imread("lenna.png", IMREAD_COLOR);//doc hinh anh tu file o che do doc mau sac
	if(image.empty()){//Kiem tra coi hinh co du lieu hay ko?
		printf("Khong the mo hoac tim thay file nay\r\n");
		return -1;
	}
	namedWindow("Lenna", WINDOW_NORMAL);
	resizeWindow("Lenna",300, 300);
    setMouseCallback("Lenna", mouseHandler, NULL);
    imshow("Lenna",image);//Hien thi ma tran du lieu hinh anh
    waitKey(0);

    return 0;
}

/*---- Ham xu ly su kien chuot --------------------------*/
void mouseHandler(int event, int x, int y, int, void*){
	/*--------- Chuot trai duoc bam ------------------*/
    if (event == EVENT_LBUTTONDOWN){       
        selected_point = Point(x, y);		//Lay toa do diem duoc chon
		printf("[MOUSE] Left-Down: x=%d,y=%d\r\n",x,y);
		//Ve diem tron danh dau
        circle(image,				//Anh duoc ve
				selected_point,		//Vi tri
				2,					//Ban kinh
				Scalar(0, 0, 255),	//Mau sac
				-1,					//Do day net, -1 co nghia phu dac
				LINE_8				//Kieu net
		);
		//Luu vi tri vao mang cac vi tri
        selected_pts.push_back(selected_point);				
		if(selected_npts>0){
			//Ve duong thang noi 2 vi tri
            line(image,							//Anh duoc ve
				selected_pts[selected_npts-1],	//Diem bat dau
				selected_point,					//Diem ket thuc
				Scalar(0, 0, 255),				//Mau sac
				2,								//Do day net
				LINE_8							//Kieu net
			);            
        }
		//Tang bien dem so cac vi tri
        selected_npts++;        						
    }
	/*---------- Chuot trai duoc tha -----------------*/
    if (event == EVENT_LBUTTONUP){
		printf("[MOUSE] Left-Up: x=%d,y=%d\r\n",x,y);
        imshow("Lenna", image);
    }
	/*---------- Chuot phai duoc bam -----------------*/
    if (event == EVENT_RBUTTONDOWN){
		printf("[MOUSE] Right-Down: x=%d,y=%d\r\n",x,y);
        if (selected_npts != 0){
			//Ve da giac kin tu cac vi tri duoc chon
            polylines(image,			//Anh duoc ve
						selected_pts,	//Danh sach cac vi tri
						1,				//Da giac kin
						Scalar(0,0,0),	//Mau sac
						2,				//Do day net
						LINE_8			//Kieu net
			);
        }
        imshow("Lenna", image);
    }
	/*------- Chuot phai duoc tha --------------------*/
    if (event == EVENT_RBUTTONUP){      
		printf("[MOUSE] Right-Up: x=%d,y=%d\r\n",x,y);
        image_crop = Mat::zeros(image.size(), CV_8UC3);//cat anh mau
        image_mask = Mat::zeros(image.size(), CV_8UC1);//mat na thang xam

        vector<vector<Point> > selected_vpts;
        selected_vpts.push_back(selected_pts);
		//Ve da giac phu mau tu tap cac vi tri
        fillPoly(image_mask,				//Anh duoc ve
					selected_vpts,			//Tap cac vi tri
					Scalar(255, 255, 255),	//Mau sac
					LINE_8					//Kieu net
		);
		//Thuc hien logic AND tung bit giua anh goc va mat na de cat anh
        bitwise_and(image, image, image_crop, image_mask);
		//Hien thi ket qua
		namedWindow("Mask", WINDOW_NORMAL);
		resizeWindow("Mask",300, 300);
        imshow("Mask", image_mask);
		namedWindow("Crop", WINDOW_NORMAL);
		resizeWindow("Crop",300, 300);
        imshow("Crop", image_crop);        
    }
	/*------- Chuot giua duoc bam -------------------*/
    if (event == EVENT_MBUTTONDOWN){
		printf("[MOUSE] Middle-Down: x=%d,y=%d\r\n",x,y);
        selected_pts.clear();
        selected_npts = 0;        
    }
	/*------- Chuot giua duoc tha ------------------*/
    if (event == EVENT_MBUTTONUP){
		printf("[MOUSE] Middle-Up: x=%d,y=%d\r\n",x,y);        
    }
	/*------- Chuot dang di chuyen ----------------*/
	if (event == EVENT_MOUSEMOVE ){
		printf("[MOUSE] Moved to: x=%d,y=%d\r\n",x,y);        
	}
}
