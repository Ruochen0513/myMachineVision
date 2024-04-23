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

    // 设置直方图的参数
    int histSize = 256;    // 直方图尺寸
    float range[] = { 0, 256 };  // 像素值范围
    const float* histRange = { range };
    bool uniform = true, accumulate = false;

    // 计算直方图
    calcHist(&img, 1, 0, Mat(), Hist, 1, &histSize, &histRange, uniform, accumulate);

    // 创建直方图的图像表示
    int hist_w = 512, hist_h = 400;   // 直方图的宽和高
    int bin_w = cvRound((double)hist_w / histSize);   // 每个bin的宽度
    Mat histImage(hist_h, hist_w, CV_8U, Scalar(0));  // 创建直方图的图像表示
    normalize(Hist, Hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());  // 归一化直方图

    // 绘制直方图
    for (int i = 1; i < histSize; i++)   // 绘制每个bin
    {
        int x = bin_w * i;  // 当前点的x坐标
        int y = hist_h - cvRound(Hist.at<float>(i));  // 当前点的y坐标

        // 绘制当前点与底端的线条
        line(histImage, Point(x, hist_h), Point(x, y), Scalar(255), 1, 8, 0);
    }
    return histImage;
}

void main()
{
    Mat input = imread("test42.jpg");

    Mat gray;
    //彩色图转为灰度图
    cvtColor(input, gray, COLOR_BGR2GRAY);

    //直方图绘制，需编程实现
    Mat Hist = myHist(gray);

    imshow("Hist", Hist);
    waitKey(0);

}
*/