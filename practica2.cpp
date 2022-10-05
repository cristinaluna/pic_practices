#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>


#define ESCAPE 27

int main(int argc, char* argv[])
{
	// initialize object
	cv::Mat frame;
	
	// initialize video capturing object
	cv::VideoCapture capture;

	// keyboard pressed
	char pressedKey = 0;

	// check the success for image reading
	bool success;

	// load video from disk
	capture.open("honda-asimo.avi");

	// check if the video is available
	if (!capture.isOpened())
	{
		std::cout << "Error in loading the video!" << std::endl;
	}
	else
	{
		// create window canvas to show video
		cv::namedWindow("L01_E02");

		while (pressedKey != ESCAPE)
		{
			// read frame by frame in a loop
			success = capture.read(frame);

			// check if it was successful read
			if (success == false)
			{
				std::cout << "Can't read the frame from file!" << std::endl;
				return 1;
			}

			// add the frame to the window
			cv::imshow("L01_E02", frame);

			// update the pressed key
			pressedKey = cv::waitKey(0);
		}

		// free memory
		cv::destroyWindow("L01_E02");
		capture.release();
	}
}
