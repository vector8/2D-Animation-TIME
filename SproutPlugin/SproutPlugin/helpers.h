#pragma once

#include <memory>
#include <Windows.h>
#include "HPPC.hpp"

// This helper class is used to store the PcImage using WinAPI bitmap headers
// It also provides simple drawing support.
class BitmapImage
{
public:
    // Create BitmapImage from PcImage data
    BitmapImage(const hp::pc::PcPtr<hp::pc::PcImage> image);

    // Save bitmap file to disk
    void Save(std::wstring filename);

private:
    // Hold image buffer
    std::unique_ptr<char[]> data_;
    unsigned int data_size_;

    // Headers for Bitmap file
    BITMAPFILEHEADER bmp_file_header_;
    BITMAPV4HEADER bmp_v4_header_;
};

// Helper method used to get timestamp
std::wstring Timestamp(const wchar_t* format = L"%X - ");

// Return the default path for outputs, creating it if necessary.
std::wstring OutputFolder(const std::wstring& subdir = L"");