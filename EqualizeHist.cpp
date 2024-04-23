#include <iostream>
#include <fstream>
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
using namespace cv;
using namespace std;

Mat myEqualizeHist(Mat img)
{
	Mat Hist;

	// 设置直方图的参数
	int histSize = 256;    // 直方图尺寸
	float range[] = { 0, 256 };  // 像素值范围
	const float* histRange = { range };
	bool uniform = true, accumulate = false;

	// 计算直方图
	calcHist(&img, 1, 0, Mat(), Hist, 1, &histSize, &histRange, uniform, accumulate);

	// 计算累积分布函数（CDF）
	Mat HC;
	Hist.copyTo(HC);
	for (int i = 1; i < histSize; i++)
	{
		HC.at<float>(i) += HC.at<float>(i - 1);
	}

	// 直方图均衡化
	Mat equalizedHist = Mat::zeros(1, histSize, CV_32FC1);
	for (int i = 1; i < histSize; i++)
	{
		equalizedHist.at<float>(i) = round(HC.at<float>(i) * (histSize - 1) / img.total());
	}

	// 创建直方图均衡化后的图像
	Mat EqualizedImg;
	EqualizedImg = Mat::zeros(img.size(), img.type());
	for (int y = 0; y < img.rows; y++)
	{
		for (int x = 0; x < img.cols; x++)
		{
			EqualizedImg.at<uchar>(y, x) = equalizedHist.at<float>(img.at<uchar>(y, x));
		}
	}

	//返回原图像经过直方图均衡化后的变换结果
	return EqualizedImg;
}

void main()
{
	Mat input = imread("testimg.jpg");

	Mat gray;
	//彩色图转为灰度图
	cvtColor(input, gray, COLOR_BGR2GRAY);

	//直方图均衡化，需编程实现
	Mat EqualizedImg = myEqualizeHist(gray);
	
	imshow("input",input);
	imshow("EqualizedImg", EqualizedImg);
	waitKey(0);
}
