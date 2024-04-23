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

	// ����ֱ��ͼ�Ĳ���
	int histSize = 256;    // ֱ��ͼ�ߴ�
	float range[] = { 0, 256 };  // ����ֵ��Χ
	const float* histRange = { range };
	bool uniform = true, accumulate = false;

	// ֱ��ʹ��calcHist��������ֱ��ͼ
	calcHist(&img, 1, 0, Mat(), Hist, 1, &histSize, &histRange, uniform, accumulate);

	float P = 0.5;   //����ѡ��Pֵ
	float T = 0;     //����ֱ��ͼ�õ�����ֵ
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
	
	����p����ֵ���ļ������
	
	*/

	Mat ThresholdPImg;

	//������ֱ��ͼ�õ�����ֵ��ͼ����ж�ֵ������
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




	//����ԭͼ��img����p����ֵ����Ľ��,��ͼ��ThresholdPImg��
	return ThresholdPImg;
}

void main()
{
	Mat input = imread("testimg.jpg");

	Mat gray;
	//��ɫͼתΪ�Ҷ�ͼ
	cvtColor(input, gray, COLOR_BGR2GRAY);


	//�Ҷ�ͼp����ֵ��������ʵ��
	Mat ThresholdPImg = myThresholdP(gray);
	

	imshow("input", input);
	imshow("gray", gray);
	imshow("ThresholdPImg", ThresholdPImg);
	waitKey(0);
}