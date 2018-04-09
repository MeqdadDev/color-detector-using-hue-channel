#include <opencv2/core/core.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cv.h>

using namespace cv;
using namespace std;

// Functions promoting
void firstPic(void);


// Main Function
int main()
{

    firstPic();

    waitKey(0); 
    return 0;
}

// Images of Green
void firstPic(void){
  
    Mat sta1, dst1, dst2, hsvSta1;
    
    sta1 = imread("/home/meqdad/Desktop/Stadiums/s1.jpg", IMREAD_COLOR); // Read the First Stadium image

    if (!sta1.data) // Check for invalid input
    {
      cout << "A reading problem in the image." << std::endl;
      return;
    }
    
    cvtColor(sta1, hsvSta1, CV_RGB2HSV);
    
    vector<Mat> channels;
    split(hsvSta1, channels);
        
    threshold(channels[0], dst1, 50, 255, THRESH_BINARY);
    threshold(dst1, dst2, 80, 255, THRESH_BINARY);
    
    imshow("Binary Image", dst2);
    imshow("First Stadium", sta1);
    
    //  imshow("Image H", channels[0]);
    //  imshow("Output Image HSV", hsvSta1);
    //  imshow("Output Image S", channels[1]);
    //  imshow("Output Image V", channels[2]);
    
}
