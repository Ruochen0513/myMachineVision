/*
#include <iostream>
#include <fstream>
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
using namespace cv;
using namespace std;


Mat myHist(Mat img)
{
    Mat Hist;

    // ����ֱ��ͼ�Ĳ���
    int histSize = 256;    // ֱ��ͼ�ߴ�
    float range[] = { 0, 256 };  // ����ֵ��Χ
    const float* histRange = { range };
    bool uniform = true, accumulate = false;

    // ����ֱ��ͼ
    calcHist(&img, 1, 0, Mat(), Hist, 1, &histSize, &histRange, uniform, accumulate);

    // ����ֱ��ͼ��ͼ���ʾ
    int hist_w = 512, hist_h = 400;   // ֱ��ͼ�Ŀ�͸�
    int bin_w = cvRound((double)hist_w / histSize);   // ÿ��bin�Ŀ��
    Mat histImage(hist_h, hist_w, CV_8U, Scalar(0));  // ����ֱ��ͼ��ͼ���ʾ
    normalize(Hist, Hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());  // ��һ��ֱ��ͼ

    // ����ֱ��ͼ
    for (int i = 1; i < histSize; i++)   // ����ÿ��bin
    {
        int x = bin_w * i;  // ��ǰ���x����
        int y = hist_h - cvRound(Hist.at<float>(i));  // ��ǰ���y����

        // ���Ƶ�ǰ����׶˵�����
        line(histImage, Point(x, hist_h), Point(x, y), Scalar(255), 1, 8, 0);
    }
    return histImage;
}

void main()
{
    Mat input = imread("test42.jpg");

    Mat gray;
    //��ɫͼתΪ�Ҷ�ͼ
    cvtColor(input, gray, COLOR_BGR2GRAY);

    //ֱ��ͼ���ƣ�����ʵ��
    Mat Hist = myHist(gray);

    imshow("Hist", Hist);
    waitKey(0);

}
*/