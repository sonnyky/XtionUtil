#define common_api __declspec(dllexport) 

#include <OpenNI.h>

extern "C" {
	common_api char* TestHello();
	common_api int InitDevice();
}