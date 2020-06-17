#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
	Mat image;
	image = imread("lena.jpg");
	if (image.empty()) {
		printf("No Image to load");
		return -1;
	}
	namedWindow("My_Image", WINDOW_AUTOSIZE);
	imshow("My_Image", image);
	waitKey(0);
	image.release();

	return 0;
}