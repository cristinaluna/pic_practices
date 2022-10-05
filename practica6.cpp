#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>


int main(int argc, char* argv[])
{
	// initialize object
	cv::Mat original_image, grayscale_image;

	// load image from disk
	original_image = cv::imread("lena.jpg", cv::IMREAD_COLOR);

	// load image from disk as gray scale
	grayscale_image = cv::imread("lena.jpg", cv::IMREAD_GRAYSCALE);

	// check if the image is available
	if (!original_image.data || !grayscale_image.data)
	{
		std::cout << "Error in loading the image!" << std::endl;
	}
	else
	{
		// print out number of channels colors in the command window
		std::cout << "Original Image has: " << original_image.channels() << " channels" << std::endl;
		std::cout << "Grayscale Image has: " << grayscale_image.channels() << " channels" << std::endl;
		
		// create window canvas to show image
		cv::namedWindow("L03_E01_Original");
		cv::namedWindow("L03_E01_Grayscale");

		// add the image to the window
		cv::imshow("L03_E01_Original", original_image);
		cv::imshow("L03_E01_Grayscale", grayscale_image);

		// wait till a key is pressed
		cv::waitKey(0);

		// free memory
		cv::destroyAllWindows();
	}
}


