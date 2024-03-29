#include "GCApplication.h"

const cv::Scalar RED = cv::Scalar(0, 0, 255);
const cv::Scalar PINK = cv::Scalar(230, 130, 255);
const cv::Scalar BLUE = cv::Scalar(255, 0, 0);
const cv::Scalar LIGHTBLUE = cv::Scalar(255, 255, 160);
const cv::Scalar GREEN = cv::Scalar(0, 255, 0);

const int BGD_KEY = cv::EVENT_FLAG_CTRLKEY;
const int FGD_KEY = cv::EVENT_FLAG_SHIFTKEY;

static void getBinMask(const cv::Mat& comMask, cv::Mat& binMask)
{
	if (comMask.empty() || comMask.type() != CV_8UC1)
		CV_Error(cv::Error::StsBadArg, "comMask is empty or has incorrect type (not CV_8UC1)");
	if (binMask.empty() || binMask.rows != comMask.rows || binMask.cols != comMask.cols)
		binMask.create(comMask.size(), CV_8UC1);
	binMask = comMask & 1;
}

void GCApplication::reset()
{
	if (!mask.empty())
		mask.setTo(cv::Scalar::all(cv::GC_BGD));
	bgdPxls.clear(); fgdPxls.clear();
	prBgdPxls.clear();  prFgdPxls.clear();

	isInitialized = false;
	rectState = NOT_SET;
	lblsState = NOT_SET;
	prLblsState = NOT_SET;
	iterCount = 0;
}

void GCApplication::setImageAndWinName(const cv::Mat& _image, const std::string& _winName)
{
	if (_image.empty() || _winName.empty())
		return;
	image = &_image;
	winName = &_winName;
	mask.create(image->size(), CV_8UC1);
	reset();
}

void GCApplication::showImage() const
{
	if (image->empty() || winName->empty())
		return;

	cv::Mat res;
	cv::Mat binMask;
	if (!isInitialized)
		image->copyTo(res);
	else
	{
		getBinMask(mask, binMask);
		image->copyTo(res, binMask);
	}

	std::vector<cv::Point>::const_iterator it;
	for (it = bgdPxls.begin(); it != bgdPxls.end(); ++it)
		circle(res, *it, radius, BLUE, thickness);
	for (it = fgdPxls.begin(); it != fgdPxls.end(); ++it)
		circle(res, *it, radius, RED, thickness);
	for (it = prBgdPxls.begin(); it != prBgdPxls.end(); ++it)
		circle(res, *it, radius, LIGHTBLUE, thickness);
	for (it = prFgdPxls.begin(); it != prFgdPxls.end(); ++it)
		circle(res, *it, radius, PINK, thickness);

	if (rectState == IN_PROCESS || rectState == SET)
		rectangle(res, cv::Point(rect.x, rect.y), cv::Point(rect.x + rect.width, rect.y + rect.height), GREEN, 2);

	imshow(*winName, res);
}

void GCApplication::setRectInMask()
{
	CV_Assert(!mask.empty());
	mask.setTo(cv::GC_BGD);
	rect.x = cv::max(0, rect.x);
	rect.y = cv::max(0, rect.y);
	rect.width = cv::min(rect.width, image->cols - rect.x);
	rect.height = cv::min(rect.height, image->rows - rect.y);
	(mask(rect)).setTo(cv::Scalar(cv::GC_PR_FGD));
}

void GCApplication::setLblsInMask(int flags, cv::Point p, bool isPr)
{
	std::vector<cv::Point> *bpxls, *fpxls;
	uchar bvalue, fvalue;
	if (!isPr)
	{
		bpxls = &bgdPxls;
		fpxls = &fgdPxls;
		bvalue = cv::GC_BGD;
		fvalue = cv::GC_FGD;
	}
	else
	{
		bpxls = &prBgdPxls;
		fpxls = &prFgdPxls;
		bvalue = cv::GC_PR_BGD;
		fvalue = cv::GC_PR_FGD;
	}
	if (flags & BGD_KEY)
	{
		bpxls->push_back(p);
		circle(mask, p, radius, bvalue, thickness);
	}
	if (flags & FGD_KEY)
	{
		fpxls->push_back(p);
		circle(mask, p, radius, fvalue, thickness);
	}
}

void GCApplication::mouseClick(int event, int x, int y, int flags, void*)
{
	// TODO add bad args check
	switch (event)
	{
	case cv::EVENT_LBUTTONDOWN: // set rect or GC_BGD(GC_FGD) labels
	{
								bool isb = (flags & BGD_KEY) != 0,
									isf = (flags & FGD_KEY) != 0;
								if (rectState == NOT_SET && !isb && !isf)
								{
									rectState = IN_PROCESS;
									rect = cv::Rect(x, y, 1, 1);
								}
								if ((isb || isf) && rectState == SET)
									lblsState = IN_PROCESS;
	}
		break;
	case cv::EVENT_RBUTTONDOWN: // set GC_PR_BGD(GC_PR_FGD) labels
	{
								bool isb = (flags & BGD_KEY) != 0,
									isf = (flags & FGD_KEY) != 0;
								if ((isb || isf) && rectState == SET)
									prLblsState = IN_PROCESS;
	}
		break;
	case cv::EVENT_LBUTTONUP:
		if (rectState == IN_PROCESS)
		{
			rect = cv::Rect(cv::Point(rect.x, rect.y), cv::Point(x, y));
			rectState = SET;
			setRectInMask();
			CV_Assert(bgdPxls.empty() && fgdPxls.empty() && prBgdPxls.empty() && prFgdPxls.empty());
			showImage();
		}
		if (lblsState == IN_PROCESS)
		{
			setLblsInMask(flags, cv::Point(x, y), false);
			lblsState = SET;
			showImage();
		}
		break;
	case cv::EVENT_RBUTTONUP:
		if (prLblsState == IN_PROCESS)
		{
			setLblsInMask(flags, cv::Point(x, y), true);
			prLblsState = SET;
			showImage();
		}
		break;
	case cv::EVENT_MOUSEMOVE:
		if (rectState == IN_PROCESS)
		{
			rect = cv::Rect(cv::Point(rect.x, rect.y), cv::Point(x, y));
			CV_Assert(bgdPxls.empty() && fgdPxls.empty() && prBgdPxls.empty() && prFgdPxls.empty());
			showImage();
		}
		else if (lblsState == IN_PROCESS)
		{
			setLblsInMask(flags, cv::Point(x, y), false);
			showImage();
		}
		else if (prLblsState == IN_PROCESS)
		{
			setLblsInMask(flags, cv::Point(x, y), true);
			showImage();
		}
		break;
	}
}

int GCApplication::nextIter()
{
	if (isInitialized)
		grabCut(*image, mask, rect, bgdModel, fgdModel, 1);
	else
	{
		if (rectState != SET)
			return iterCount;

		if (lblsState == SET || prLblsState == SET)
			grabCut(*image, mask, rect, bgdModel, fgdModel, 1, cv::GC_INIT_WITH_MASK);
		else
			grabCut(*image, mask, rect, bgdModel, fgdModel, 1, cv::GC_INIT_WITH_RECT);

		isInitialized = true;
	}
	iterCount++;

	bgdPxls.clear(); fgdPxls.clear();
	prBgdPxls.clear(); prFgdPxls.clear();

	return iterCount;
}