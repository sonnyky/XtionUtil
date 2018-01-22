#include "common.hpp"
#include <iostream>

using namespace std;
using namespace openni;
extern "C" {
	char* TestHello() {
		static char str[100];
		sprintf(str, "Hello from native");
		return str;
	}

	int InitDevice() {
		Status rc = OpenNI::initialize();
		if (rc != STATUS_OK)
		{
			printf("Initialize failed\n%s\n", OpenNI::getExtendedError());
			return 1;
		}
		return 0;
	}
}