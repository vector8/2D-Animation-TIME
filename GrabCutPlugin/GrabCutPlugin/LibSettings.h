#pragma once

#ifdef GRABCUTPLUGIN_EXPORTS
#define LIB_API __declspec(dllexport)
#elif GRABCUTPLUGIN_IMPORTS
#define LIB_API __declspec(dllimport)
#else
#define LIB_API
#endif