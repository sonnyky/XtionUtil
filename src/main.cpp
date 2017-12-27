#include "common.hpp"
#include <iostream>

using namespace std;

extern "C" {
	char* TestHello() {
		static char str[100];
		sprintf(str, "Hello from native");
		return str;
	}
}