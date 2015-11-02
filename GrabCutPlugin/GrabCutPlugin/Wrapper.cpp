#include "Wrapper.h"
#include "GrabCut.h"

void run(char* filename)
{
	std::string fileNameString(filename);

	runGrabCut(fileNameString);
}