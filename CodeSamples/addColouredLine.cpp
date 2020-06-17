#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {

	if (argc != 2) {
		cout << "Enter BasicImageProcessing.exe ImageFileName\n";
		return -1;
	}

	Mat img;
	img = imread(argv[1], IMREAD_UNCHANGED);

	if (img.empty()) {
		printf("Couldn't open the image file.\n");
		return -1;
	}

	int w = img.cols;
	int h = img.rows;
	int t = img.channels();
	int s = img.step;
	int v = img.data[1];

	for (int i = s; i < s * 50 ; i++) {
		img.data[i] = 255;
	}

	cout << "Width and Height : " << w << " , " << h << endl;
	cout << "Type :" << t << endl;
	cout << v << endl;

	namedWindow("Image", WINDOW_AUTOSIZE);
	imshow("Image", img);
	waitKey(0);
	img.release();

	return 0;
}