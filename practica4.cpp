#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	// initialize object
	cv::Mat original_image, modified_image;

	// load image from disk
	original_image = cv::imread("lena.jpg");
	
	// check if the image is available
	if (!original_image.data)
	{
		std::cout << "Error in loading the image!" << std::endl;
	}
	else
	{
		// copy the image matrix to the modified image
		// method 1 clone()
		// modified_image = original_image.clone();
		
		// method 2 copyTo()
		original_image.copyTo(modified_image);
		
		// define points
		cv::Point p1(modified_image.rows / 2, modified_image.cols / 2);
		cv::Point p2((modified_image.rows / 2) + 25, (modified_image.cols / 2) + 25);
		
		// draw a line
		cv::line(modified_image, p1, p2, cv::Scalar(255, 0, 0));
		
		// draw a rectangle
		cv::rectangle(modified_image, p1, p2, cv::Scalar(0, 255, 0));
		
		// draw a circle
		cv::circle(modified_image, p1, 25, cv::Scalar(0, 0, 255));

		// create window canvas to show image
		cv::namedWindow("L02_E01_Original");
		cv::namedWindow("L02_E01_Modified");

		// add the image to the window
		cv::imshow("L02_E01_Original", original_image);
		cv::imshow("L02_E01_Modified", modified_image);

		// wait till a key is pressed
		cv::waitKey(0);

		// free memory
		cv::destroyWindow("L02_E01_Original");
		cv::destroyWindow("L02_E01_Modified");
	}
}
