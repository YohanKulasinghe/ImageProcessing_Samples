#include <iostream>
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {

	if (argc != 2) {
		cout << "Enter BasicImageProcessing.exe ImageFileName\n";
		return -1;
	}

	Mat img, gr;
	img = imread(argv[1], IMREAD_UNCHANGED);

	if (img.empty()) {
		printf("Couldn't open the image file.\n");
		return -1;
	}

	int w = img.cols;
	int h = img.rows;
	int t = img.channels();
	int s = img.step;
	int t1 = 0;
	
	cvtColor(img, gr, COLOR_BGR2GRAY);

	// Taking Histogram
	int hist[256];

	for (int i = 0; i < 256; i++) {
		hist[i] = 0;
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			t1 = gr.at<uchar>(i, j);
			hist[t1] = hist[t1] + 1;
		}
	}

	// Ploting Histogram
	int max = 0;
	for (int i = 0; i < 256; i++) {
		cout << "bin-" << i << " =" << hist[i] << endl;
		if (max < hist[i]) {
			max = hist[i];
		}
	}

	cout << max << endl;
	Mat him(601, 520, CV_8UC1, Scalar(255));
	int his[256];
	double maxd = max;
	for (int i = 0; i < 255; i++) {
		his[i] = cvRound(double(hist[i] / maxd) * 600);
		Point pt1 = Point(2*i, 600 - hist[i]);
		Point pt2 = Point(2*i, 600);
		line(him, pt1, pt2, Scalar(0), 1, 8, 0);
	}

	cout << "Width and Height : " << w << " , " << h << endl;
	cout << "Type :" << t << endl;
	

	namedWindow("GrayImage", WINDOW_AUTOSIZE);
	imshow("GrayImage", gr);

	namedWindow("Histogram", WINDOW_AUTOSIZE);
	imshow("Histogram", him);

	waitKey(0);
	img.release();
	gr.release();
	return 0;
}