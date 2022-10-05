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
	// & load the video stream from default camera
	cv::VideoCapture capture(0);

	// keyboard pressed
	char pressedKey = 0;

	// check the success for image reading
	bool success;

	// check if the video is available
	if (!capture.isOpened())
	{
		std::cout << "Error in loading the video!" << std::endl;
	}
	else
	{
		// create window canvas to show video
		cv::namedWindow("L01_E03");

		while (pressedKey != ESCAPE)
		{
			// read frame by frame in a loop
			success = capture.read(frame);

			// check if it was successful read
			if (success == false)
			{
				std::cout << "Can't read the frame from stream!" << std::endl;
				return 1;
			}

			// add the frame to the window
			cv::imshow("L01_E03", frame);

			// update the pressed key
			pressedKey = cv::waitKey(0);
		}

		// free memory
		cv::destroyWindow("L01_E03");
		capture.release();
	}
}
