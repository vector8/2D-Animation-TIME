#include "Wrapper.h"
#include <string>
#include "Sprout.h"

void captureImageFromSprout(char* outputFilePath)
{
	std::string filePath(outputFilePath);

	capturePicture(filePath);
}