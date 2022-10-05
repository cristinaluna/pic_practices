#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>


int main(int argc, char* argv[])
{
	// initialize object
	cv::Mat original_image;

	// load image from disk
	original_image = cv::imread("lena.jpg", cv::IMREAD_GRAYSCALE);
	
	// check if the image is available
	if (!original_image.data)
	{
		std::cout << "Error in loading the image!" << std::endl;
	}
	else
	{
		// initialize histogram calculating parameters
		int histogram_size = 256;
		float histogram_range[] = { 0, 256 };
		const float* histogram_ranges[] = { histogram_range }; 
		cv::Mat histogram;
		
		// calculate image histogram
		calcHist(&original_image, 1, 0, cv::Mat(), histogram, 1, &histogram_size, histogram_ranges);
		
		// print calculated histogram in the command window
		for (int i = 0; i < histogram_size; i++)
		{
			float bin_value = histogram.at<float>(i);
			std::cout << " " << bin_value;
		}
		
		// initialize histogram plotting parameters
		int bin_width = 2;
		int histogram_width = 512;
		int histogram_height = 400;
		cv::Mat normalized_histogram;

		// empty image for the histogram plot
		cv::Mat image_histogram(histogram_height, histogram_width, CV_8UC1, cv::Scalar(255, 0, 0));
		// normalize histogram to fit the window
		cv::normalize(histogram, normalized_histogram, 0, histogram_height, cv::NORM_MINMAX, -1, cv::Mat());

		for (int i = 1; i < histogram_size; i++)
		{
			cv::Point p1(bin_width*(i - 1), histogram_height - cvRound(normalized_histogram.at<float>(i - 1)));
			cv::Point p2(bin_width*(i), histogram_height - cvRound(normalized_histogram.at<float>(i)));
			cv::line(image_histogram, p1, p2, cv::Scalar(0, 0, 0), 2);
		}
		
		// create window canvas to show image
		cv::namedWindow("L02_E02_Original");
		cv::namedWindow("L02_E02_Histogram");

		// add the image to the window
		cv::imshow("L02_E02_Original", original_image);
		cv::imshow("L02_E02_Histogram", image_histogram);

		// wait till a key is pressed
		cv::waitKey(0);

		// free memory
		cv::destroyAllWindows();
	}
}
