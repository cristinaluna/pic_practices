#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>


int main(int argc, char* argv[])
{
	// initialize object
	cv::Mat img;

	// load image from disk
	img = cv::imread("lena.jpg");

	// check if the image is available
	if (!img.data)
	{
		std::cout << "Error in loading the image!" << std::endl;
	}
	else
	{
		// create window canvas to show image
		cv::namedWindow("L01_E01");

		// add the image to the window
		cv::imshow("L01_E01", img);

		// wait till a key is pressed
		cv::waitKey(0);

		// free memory
		cv::destroyWindow("L01_E01");
	}
}
