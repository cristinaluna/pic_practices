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
	original_image = imread("mandril.jpg", cv::IMREAD_COLOR);

	// check if the image is available
	if (!original_image.data)
	{
		std::cout << "Error in loading the image!" << std::endl;
	}
	else
	{
		// convert the image from BGR to RGB
		cv::cvtColor(original_image, modified_image, cv::COLOR_BGR2HSV);

		// create a channel for each color with image size
		cv::Mat hue_channel(modified_image.size(), CV_8UC1);
		cv::Mat saturation_channel(modified_image.size(), CV_8UC1);
		cv::Mat value_channel(modified_image.size(), CV_8UC1);
		// create an array of all channels
		cv::Mat channels_array[] = { hue_channel, saturation_channel, value_channel };
		// split the image to separate channels
		cv::split(modified_image, channels_array);

		// initialize histogram calculating parameters
		int histogram_size = 256;
		float histogram_range[] = { 0, 256 };
		const float* histogram_ranges[] = { histogram_range };
		cv::Mat hue_histogram, saturation_histogram, value_histogram;

		// calculate image histograms
		cv::calcHist(&hue_channel, 1, 0, cv::Mat(), hue_histogram, 1, &histogram_size, histogram_ranges);
		cv::calcHist(&saturation_channel, 1, 0, cv::Mat(), saturation_histogram, 1, &histogram_size, histogram_ranges);
		cv::calcHist(&value_channel, 1, 0, cv::Mat(), value_histogram, 1, &histogram_size, histogram_ranges);

		// initialize histogram plotting parameters
		int bin_width = 2;
		int histogram_width = 512;
		int histogram_height = 400;
		cv::Mat normalized_hue_histogram, normalized_saturation_histogram, normalized_value_histogram;

		// empty image for the histogram plot
		cv::Mat image_histogram(histogram_height, histogram_width, CV_8UC3, cv::Scalar(255, 255, 255));
		// normalize histograms to fit the window
		cv::normalize(hue_histogram, normalized_hue_histogram, 0, histogram_height, cv::NORM_MINMAX, -1, cv::Mat());
		cv::normalize(saturation_histogram, normalized_saturation_histogram, 0, histogram_height, cv::NORM_MINMAX, -1, cv::Mat());
		cv::normalize(value_histogram, normalized_value_histogram, 0, histogram_height, cv::NORM_MINMAX, -1, cv::Mat());

		for (int i = 1; i < histogram_size; i++)
		{
			cv::Point p1(bin_width*(i - 1), histogram_height - cvRound(normalized_hue_histogram.at<float>(i - 1)));
			cv::Point p2(bin_width*(i), histogram_height - cvRound(normalized_hue_histogram.at<float>(i)));
			cv::line(image_histogram, p1, p2, cv::Scalar(255, 0, 0), 2); 

			cv::Point p3(bin_width*(i - 1), histogram_height - cvRound(normalized_saturation_histogram.at<float>(i - 1)));
			cv::Point p4(bin_width*(i), histogram_height - cvRound(normalized_saturation_histogram.at<float>(i)));
			cv::line(image_histogram, p3, p4, cv::Scalar(0, 255, 0), 2);

			cv::Point p5(bin_width*(i - 1), histogram_height - cvRound(normalized_value_histogram.at<float>(i - 1)));
			cv::Point p6(bin_width*(i), histogram_height - cvRound(normalized_value_histogram.at<float>(i)));
			cv::line(image_histogram, p5, p6, cv::Scalar(0, 0, 255), 2);
		}
		
		// create window canvases to show images
		cv::namedWindow("L03_E03_Original");
		cv::namedWindow("L03_E03_Modified");
		cv::namedWindow("L03_E03_Hue_Color");
		cv::namedWindow("L03_E03_Saturation_Color");
		cv::namedWindow("L03_E03_Value_Color");
		cv::namedWindow("L03_E03_HSV_Histogram");

		// add images to windows
		cv::imshow("L03_E03_Original", original_image);
		cv::imshow("L03_E03_Modified", modified_image);
		cv::imshow("L03_E03_Hue_Color", hue_channel);
		cv::imshow("L03_E03_Saturation_Color", saturation_channel);
		cv::imshow("L03_E03_Value_Color", value_channel);
		cv::imshow("L03_E03_HSV_Histogram", image_histogram);

		// wait till a key is pressed
		cv::waitKey(0);

		// free memory
		cv::destroyAllWindows();
	}
}


