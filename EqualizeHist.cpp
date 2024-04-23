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

	// ����ֱ��ͼ�Ĳ���
	int histSize = 256;    // ֱ��ͼ�ߴ�
	float range[] = { 0, 256 };  // ����ֵ��Χ
	const float* histRange = { range };
	bool uniform = true, accumulate = false;

	// ����ֱ��ͼ
	calcHist(&img, 1, 0, Mat(), Hist, 1, &histSize, &histRange, uniform, accumulate);

	// �����ۻ��ֲ�������CDF��
	Mat HC;
	Hist.copyTo(HC);
	for (int i = 1; i < histSize; i++)
	{
		HC.at<float>(i) += HC.at<float>(i - 1);
	}

	// ֱ��ͼ���⻯
	Mat equalizedHist = Mat::zeros(1, histSize, CV_32FC1);
	for (int i = 1; i < histSize; i++)
	{
		equalizedHist.at<float>(i) = round(HC.at<float>(i) * (histSize - 1) / img.total());
	}

	// ����ֱ��ͼ���⻯���ͼ��
	Mat EqualizedImg;
	EqualizedImg = Mat::zeros(img.size(), img.type());
	for (int y = 0; y < img.rows; y++)
	{
		for (int x = 0; x < img.cols; x++)
		{
			EqualizedImg.at<uchar>(y, x) = equalizedHist.at<float>(img.at<uchar>(y, x));
		}
	}

	//����ԭͼ�񾭹�ֱ��ͼ���⻯��ı任���
	return EqualizedImg;
}

void main()
{
	Mat input = imread("testimg.jpg");

	Mat gray;
	//��ɫͼתΪ�Ҷ�ͼ
	cvtColor(input, gray, COLOR_BGR2GRAY);

	//ֱ��ͼ���⻯������ʵ��
	Mat EqualizedImg = myEqualizeHist(gray);
	
	imshow("input",input);
	imshow("EqualizedImg", EqualizedImg);
	waitKey(0);
}
