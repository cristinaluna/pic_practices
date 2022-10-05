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
	original_image = imread("lightballs.jpg", cv::IMREAD_COLOR);

	// check if the image is available
	if (!original_image.data)
	{
		std::cout << "Error in loading the image!" << std::endl;
	}
	else
	{
		// convert the image from BGR to RGB
		cv::cvtColor(original_image, modified_image, cv::COLOR_BGR2RGB);

		// create a channel for each color with image size
		cv::Mat red_channel(modified_image.size(), CV_8UC1);
		cv::Mat green_channel(modified_image.size(), CV_8UC1);
		cv::Mat blue_channel(modified_image.size(), CV_8UC1);
		// create an array of all channels
		cv::Mat channels_array[] = {red_channel, green_channel, blue_channel};
		// split the image to separate channels
		cv::split(modified_image, channels_array);

		// create window canvases to show images
		cv::namedWindow("L03_E02_Original");
		cv::namedWindow("L03_E02_Modified");
		cv::namedWindow("L03_E02_Red_Color");
		cv::namedWindow("L03_E02_Green_Color");
		cv::namedWindow("L03_E02_Blue_Color");

		// add images to windows
		cv::imshow("L03_E02_Original", original_image);
		cv::imshow("L03_E02_Modified", modified_image);
		cv::imshow("L03_E02_Red_Color", red_channel);
		cv::imshow("L03_E02_Green_Color", green_channel);
		cv::imshow("L03_E02_Blue_Color", blue_channel);

		// wait till a key is pressed
		cv::waitKey(0);

		// free memory
		cv::destroyAllWindows();
	}
}


