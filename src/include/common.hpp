#define common_api __declspec(dllexport) 

#include <OpenNI.h>
#include "xtion_capture.h"

extern "C" {
	common_api xtion_capture* com_tinker_xtion_capture_create();
	common_api void com_tinker_init_openni(xtion_capture* instance);
	common_api void com_tinker_open_device(xtion_capture* instance);

	common_api bool com_tinker_get_init_flag(xtion_capture* instance);
	common_api const char * com_tinker_get_plugin_name(xtion_capture* instance);
	common_api const char * com_tinker_get_error_message(xtion_capture* instance);
	common_api void com_tinker_close_device(xtion_capture* instance);

	common_api Device* com_tinker_get_capture_handle(xtion_capture* instance);
	common_api const char* com_tinker_get_device_name(xtion_capture* instance);
	common_api const char* com_tinker_get_vendor_name(xtion_capture* instance);
}