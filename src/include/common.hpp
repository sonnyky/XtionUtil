#define common_api __declspec(dllexport) 

extern "C" {
	common_api char* TestHello();
}