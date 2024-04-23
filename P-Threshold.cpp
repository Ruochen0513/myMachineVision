#include <iostream>
#include <fstream>
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
using namespace cv;
using namespace std;

Mat myThresholdP(Mat img)
{
	Mat Hist;

	// 设置直方图的参数
	int histSize = 256;    // 直方图尺寸
	float range[] = { 0, 256 };  // 像素值范围
	const float* histRange = { range };
	bool uniform = true, accumulate = false;

	// 直接使用calcHist函数计算直方图
	calcHist(&img, 1, 0, Mat(), Hist, 1, &histSize, &histRange, uniform, accumulate);

	float P = 0.5;   //自由选择P值
	float T = 0;     //经由直方图得到的阈值
	float totalPixels = img.rows * img.cols;
	float sum_pixels = 0;
	for(int i = 0; i < histSize; i++) {
		sum_pixels += Hist.at<float>(i);
		if (sum_pixels >= totalPixels * P) {
			break;
		}
		T = i;
	}


	/*
	
	完善p率阈值化的计算过程
	
	*/

	Mat ThresholdPImg;

	//根据由直方图得到的阈值对图像进行二值化处理
	ThresholdPImg = img.clone();
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			if (ThresholdPImg.at<uchar>(i, j) >= T) {
				ThresholdPImg.at<uchar>(i, j) = 255;
			}
			else {
				ThresholdPImg.at<uchar>(i, j) = 0;
			}
		}
	}




	//返回原图像img经过p率阈值化后的结果,即图像ThresholdPImg。
	return ThresholdPImg;
}

void main()
{
	Mat input = imread("testimg.jpg");

	Mat gray;
	//彩色图转为灰度图
	cvtColor(input, gray, COLOR_BGR2GRAY);


	//灰度图p率阈值化，需编程实现
	Mat ThresholdPImg = myThresholdP(gray);
	

	imshow("input", input);
	imshow("gray", gray);
	imshow("ThresholdPImg", ThresholdPImg);
	waitKey(0);
}