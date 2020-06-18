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
	
	// Colour convertion 

	cvtColor(img, gr, COLOR_BGR2GRAY);

	cout << "Width and Height : " << w << " , " << h << endl;
	cout << "Type :" << t << endl;
	

	namedWindow("Image", WINDOW_AUTOSIZE);
	imshow("Image", img);
	namedWindow("GrayImage", WINDOW_AUTOSIZE);
	imshow("GrayImage", gr);
	waitKey(0);
	img.release();

	return 0;
}