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
    // ����Sobel����
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

    // ��������ı�Եͼ��
    Mat EdgeImg = Mat::zeros(img.size(), CV_8UC1);

    // Ӧ��Sobel���ӽ��б�Ե���
    for (int i = 1; i < img.rows - 1; i++) {
        for (int j = 1; j < img.cols - 1; j++) {
            int gx = 0, gy = 0;
            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    // ����x��y������ݶ�
                    gx += img.at<uchar>(i + a - 1, j + b - 1) * sobel_x[a][b];
                    gy += img.at<uchar>(i + a - 1, j + b - 1) * sobel_y[a][b];
                }
            }
            // �����ݶȷ�ֵ������д���Եͼ��
            EdgeImg.at<uchar>(i, j) = sqrt(gx * gx + gy * gy);
        }
    }

    return EdgeImg;
}


void main()
{
	Mat input = imread("testimg.jpg");

	Mat gray;
	//��ɫͼתΪ�Ҷ�ͼ
	cvtColor(input, gray, COLOR_BGR2GRAY);

	//ʹ�ò���˲����ı�Ե��⣨���������˲���������ʵ��
	Mat EdgeImg = myEdgeDetect(gray);

	imshow("input", input);
	imshow("EdgeImg", EdgeImg);
	waitKey(0);

}*/