#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace cv;


int main(){
	int cornerCount = 300;
	CvPoint2D32f corners[300];
	CvPoint2D32f cornerss[300];
	double qualityLevel = 0.02;
	double minDistance = 5;
	IplImage *srcImage = 0, *grayImage = 0, *corners1 = 0, *corners2 = 0;
	IplImage *srcImage2 = 0, *grayImage2 = 0, *corners3 = 0, *corners4 = 0;
	
	CvScalar color = CV_RGB(255, 0, 0);


	srcImage = cvLoadImage("p1.jpg", 1);//image1
	srcImage2 = cvLoadImage("p2.jpg", 1);//image2

	grayImage = cvCreateImage(cvGetSize(srcImage), IPL_DEPTH_8U, 1);
	grayImage2 = cvCreateImage(cvGetSize(srcImage2), IPL_DEPTH_8U, 1);

	cvCvtColor(srcImage, grayImage, CV_BGR2GRAY);
	cvCvtColor(srcImage2, grayImage2, CV_BGR2GRAY);

	corners1 = cvCreateImage(cvGetSize(srcImage), IPL_DEPTH_32F, 1);
	corners2 = cvCreateImage(cvGetSize(srcImage), IPL_DEPTH_32F, 1);
	corners3 = cvCreateImage(cvGetSize(srcImage2), IPL_DEPTH_32F, 1);
	corners4 = cvCreateImage(cvGetSize(srcImage2), IPL_DEPTH_32F, 1);
	cvGoodFeaturesToTrack(grayImage, corners1, corners2, corners, &cornerCount, qualityLevel, minDistance, 0);
	cvGoodFeaturesToTrack(grayImage2, corners3, corners4, cornerss, &cornerCount, qualityLevel, minDistance, 0);
	
	printf("num corners found: %d\n", cornerCount);
	if (cornerCount>0){
		for (int i = 0; i < cornerCount; ++i){
			cvCircle(srcImage, cvPoint((int)(corners[i].x), (int)(corners[i].y)), 6, color, 1, CV_AA, 0);
			cvCircle(srcImage2, cvPoint((int)(cornerss[i].x), (int)(cornerss[i].y)), 6, color, 1, CV_AA, 0);
		}
	}
	

	cvShowImage("SUSAN-p1", srcImage);
	cvShowImage("SUSAN-p2", srcImage2);
	cvWaitKey(0);



}
