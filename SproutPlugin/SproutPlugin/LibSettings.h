#pragma once

#ifdef SPROUTPLUGIN_EXPORTS
#define LIB_API __declspec(dllexport)
#elif SPROUTPLUGIN_IMPORTS
#define LIB_API __declspec(dllimport)
#else
#define LIB_API
#endif