/*#include <iostream>
#include <fstream>
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>

using namespace cv;
using namespace std;

Mat myEdgeDetect(Mat img)
{
    // 定义Sobel算子
    int sobel_x[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    int sobel_y[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    // 定义输出的边缘图像
    Mat EdgeImg = Mat::zeros(img.size(), CV_8UC1);

    // 应用Sobel算子进行边缘检测
    for (int i = 1; i < img.rows - 1; i++) {
        for (int j = 1; j < img.cols - 1; j++) {
            int gx = 0, gy = 0;
            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    // 计算x和y方向的梯度
                    gx += img.at<uchar>(i + a - 1, j + b - 1) * sobel_x[a][b];
                    gy += img.at<uchar>(i + a - 1, j + b - 1) * sobel_y[a][b];
                }
            }
            // 计算梯度幅值并将其写入边缘图像
            EdgeImg.at<uchar>(i, j) = sqrt(gx * gx + gy * gy);
        }
    }

    return EdgeImg;
}


void main()
{
	Mat input = imread("testimg.jpg");

	Mat gray;
	//彩色图转为灰度图
	cvtColor(input, gray, COLOR_BGR2GRAY);

	//使用差分滤波器的边缘检测（利用线性滤波），需编程实现
	Mat EdgeImg = myEdgeDetect(gray);

	imshow("input", input);
	imshow("EdgeImg", EdgeImg);
	waitKey(0);

}*/