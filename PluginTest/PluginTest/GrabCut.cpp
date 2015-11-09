#include "GCApplication.h"

#include <iostream>

GCApplication gcapp;

static void on_mouse(int event, int x, int y, int flags, void* param)
{
	gcapp.mouseClick(event, x, y, flags, param);
}

int runGrabCut(std::string filename)
{
	bool running = true;

	if (filename.empty())
	{
		std::cout << "\nDurn, couldn't read in " << filename << std::endl;
		return 1;
	}
	cv::Mat image = cv::imread(filename, cv::IMREAD_UNCHANGED);
	if (image.empty())
	{
		std::cout << "\n Durn, couldn't read image filename " << filename << std::endl;
		return 1;
	}

	const std::string winName = "image";
	cv::namedWindow(winName, cv::WINDOW_AUTOSIZE);
	cv::setMouseCallback(winName, on_mouse, 0);

	gcapp.setImageAndWinName(image, winName);
	gcapp.showImage();

	while (running)
	{
		int c = cv::waitKey(0);
		switch ((char)c)
		{
		case '\x1b':
			std::cout << "Exiting ..." << std::endl;
			running = false;
			break;
		case 'r':
			std::cout << std::endl;
			gcapp.reset();
			gcapp.showImage();
			break;
		case 'n':
			int iterCount = gcapp.getIterCount();
			std::cout << "<" << iterCount << "... ";
			int newIterCount = gcapp.nextIter();
			if (newIterCount > iterCount)
			{
				gcapp.showImage();
				std::cout << iterCount << ">" << std::endl;
			}
			else
				std::cout << "rect must be determined>" << std::endl;
			break;
		}
	}

	cv::destroyWindow(winName);
	return 0;
}