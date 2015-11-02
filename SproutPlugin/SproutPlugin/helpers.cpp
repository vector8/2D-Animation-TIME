#include "helpers.h"

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
#include <shlobj.h>

using namespace hp::pc;

BitmapImage::BitmapImage(const PcPtr<PcImage> image)
{
    int bits_per_pixel;
    switch (image->PixelFormat()) {
    case PcPixelFormat::BGRA:
        bits_per_pixel = 32;
        break;
    case PcPixelFormat::BGR:
        bits_per_pixel = 24;
        break;
    case PcPixelFormat::Grayscale:
    case PcPixelFormat::Grayscale16:
    case PcPixelFormat::Unknown:
    default:
        bits_per_pixel = 0;
        // Even though we support Grayscale formats for PcImage, the SproutService does not
        // currently return any of with this format and supporting them would add unnecessary
        // overhead to this already complicated method.
        throw std::runtime_error("Invalid PcImage format.");
    }

    data_size_ = image->Buffer().size();

    memset(&bmp_file_header_, 0, sizeof(BITMAPFILEHEADER));
    memset(&bmp_v4_header_, 0, sizeof(BITMAPV4HEADER));

    // Fill the bitmap file header

    // The file type; must be BM.
    bmp_file_header_.bfType = 'MB'; // "BM" in little-endian
    // The size, in bytes, of the bitmap file.
    bmp_file_header_.bfSize = sizeof(bmp_file_header_) + sizeof(bmp_v4_header_) + data_size_;
    // Reserved; must be zero.
    bmp_file_header_.bfReserved1 = 0;
    // Reserved; must be zero.
    bmp_file_header_.bfReserved2 = 0;
    // As we are not using palette, the offset is just the headers
    bmp_file_header_.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPV4HEADER);

    // Fill the bitmap information header

    // The number of bytes required by the structure.
    bmp_v4_header_.bV4Size = sizeof(BITMAPV4HEADER);
    // The width of the bitmap, in pixels.
    bmp_v4_header_.bV4Width = image->Size().Width();
    // The height of the bitmap, in pixels.
    // Use negative height as PcImage bytes are stored as top-down DIB (device-independent bitmap).
    // Its origin is the upper-left corner.
    bmp_v4_header_.bV4Height = -image->Size().Height();
    // The number of planes for the target device. This value must be set to 1.
    bmp_v4_header_.bV4Planes = 1;
    // The number of bits-per-pixel (24 or 32).
    bmp_v4_header_.bV4BitCount = bits_per_pixel;
    // Use an uncompressed format for simplification.
    bmp_v4_header_.bV4V4Compression = BI_BITFIELDS;
    // Can be 0 for BI_RGB images
    bmp_v4_header_.bV4SizeImage = 0;
    // PcImage store density in pixels per millimeter.
    bmp_v4_header_.bV4XPelsPerMeter = static_cast<LONG>(image->PixelDensity().X() * 1000.0);
    bmp_v4_header_.bV4YPelsPerMeter = static_cast<LONG>(image->PixelDensity().Y() * 1000.0);
    // We are in RGB mode and have no palette.
    bmp_v4_header_.bV4ClrUsed = 0;
    bmp_v4_header_.bV4ClrImportant = 0;

    // We are using BI_BITFIELDS to enable alpha channel, so we need to define color's masks in big-endian
    bmp_v4_header_.bV4RedMask = 0x00FF0000;
    bmp_v4_header_.bV4GreenMask = 0x0000FF00;
    bmp_v4_header_.bV4BlueMask = 0x000000FF;
    if (bits_per_pixel == 32) {
        bmp_v4_header_.bV4AlphaMask = 0xFF000000;
    }

    // Allocate memory buffer and copy information
    data_ = std::make_unique<char[]>(data_size_);
    memcpy(data_.get(), image->Buffer().data(), data_size_);
}

void BitmapImage::Save(std::wstring filename)
{
    // Create file to which data will be written
    std::ofstream file(filename.c_str(), std::ios::binary | std::ios::out);

    if (!file.is_open()) {
        throw std::runtime_error("Error creating file for bitmap image.");
    }

    // Write bitmap header
    file.write(reinterpret_cast<const char*>(&bmp_file_header_), sizeof(BITMAPFILEHEADER));
    // Write bitmap information
    file.write(reinterpret_cast<const char*>(&bmp_v4_header_), sizeof(BITMAPV4HEADER));
    // Write image data
    file.write(data_.get(), data_size_);
}

std::wstring Timestamp(const wchar_t* format)
{
    std::time_t current_time = std::time(nullptr);
    std::tm current_tm;
    localtime_s(&current_tm, &current_time); // Use Windows only safe version
    std::wostringstream buffer;
    buffer << std::put_time(&current_tm, format);
    return buffer.str();
}

std::wstring OutputFolder(const std::wstring& subdir)
{
    // Static reference for output folder name to avoid unecessary re-creations.
    static std::wstring output_folder;

    if (output_folder.empty()) {

        // Get Desktop directory for current user
        static wchar_t buffer[MAX_PATH + 1];
        if (!SHGetSpecialFolderPath(HWND_DESKTOP, buffer, CSIDL_DESKTOPDIRECTORY, FALSE)) {
            throw std::system_error(GetLastError(), std::iostream_category(), "Could not find Desktop directory");
        }
        output_folder = std::wstring(buffer);

        // Create common c++ tutorials folder
        output_folder.append(L"\\SproutCppTutorials_Output");
        // Create directory for log file.
        if (!CreateDirectory(output_folder.c_str(), NULL) && GetLastError() != ERROR_ALREADY_EXISTS) {
            throw std::system_error(GetLastError(), std::iostream_category(), "Could not create root directory for log");
        }

        // Create folder for this sample
        output_folder.append(L"\\Moment_PictureExtraction");
        // Create directory for log file.
        if (!CreateDirectory(output_folder.c_str(), NULL) && GetLastError() != ERROR_ALREADY_EXISTS) {
            throw std::system_error(GetLastError(), std::iostream_category(), "Could not create sample directory.");
        }

        // Append trailing slash to define path as folder.
        output_folder.append(L"\\");
    }

    // Create folder for this instance
    if (!subdir.empty()) {
        std::wstring output_folder_with_subdir(output_folder);
        output_folder_with_subdir.append(subdir);
        if (!CreateDirectory(output_folder_with_subdir.c_str(), NULL) && GetLastError() != ERROR_ALREADY_EXISTS) {
            throw std::system_error(GetLastError(), std::iostream_category(), "Could not create sample subdir.");
        }
        output_folder_with_subdir.append(L"\\");
        return output_folder_with_subdir;
    }

    return output_folder;
}