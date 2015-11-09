#include "Sprout.h"
#include <iostream>
#include <string>
#include "HPPC.hpp"
#include "ConversionUtilities.hpp"
#include "helpers.h"

void capturePicture(std::string outFilePath)
{
    try
    {
		hp::pc::PcPtr<hp::pc::IPcLink> link = hp::pc::HPPC::CreateLink();
        hp::pc::PcPtr<hp::pc::IPcMoment> moment = link->CaptureMoment();
        //std::wstring output_folder = OutputFolder(Timestamp(L"%Y-%m-%d_%H-%M-%S"));
		hp::pc::PcPtr<hp::pc::IPcPicture> picture = link->ExtractPicture(moment);
		std::wstring filename = std::wstring(outFilePath.begin(), outFilePath.end());
        BitmapImage(picture->Image()).Save(filename);
    }
    catch (const hp::pc::PcException& exception)
    {
        std::wcerr << Timestamp() << L"*** An SDK error occurred *****************************" << std::endl;
        std::wcerr << Timestamp() << L"* " << exception.Message() << std::endl;
        std::wcerr << Timestamp() << L"*******************************************************" << std::endl;
    }
    catch (const std::exception& exception)
    {
        std::wcerr << Timestamp() << L"*** An exception ocurred ******************************" << std::endl;
        std::wcerr << Timestamp() << L"* " << exception.what() << std::endl;
        std::wcerr << Timestamp() << L"*******************************************************" << std::endl;
    }
}