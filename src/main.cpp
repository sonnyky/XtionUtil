#include "common.hpp"
#include <iostream>
#include <fstream>

using namespace std;
using namespace openni;
extern "C" {

	xtion_capture* com_tinker_xtion_capture_create() {
		return new xtion_capture();
	}

	void com_tinker_init_openni(xtion_capture* instance) {
		Status rc = OpenNI::initialize();
		if (rc != STATUS_OK)
		{
			return;
		}
	}
	const char* com_tinker_open_device(xtion_capture* instance) {
		instance->open_device();
		return instance->get_error_message();
	}

	bool com_tinker_get_init_flag(xtion_capture* instance) {
		return instance->get_init_flag();
	}

	const char * com_tinker_get_error_message(xtion_capture* instance) {
		return instance->get_error_message();
	}

	const char * com_tinker_get_plugin_name(xtion_capture* instance) {
		return instance->get_plugin_name();
	}

	void com_tinker_close_device(xtion_capture* instance) {
		instance->close_device();
	}
	
	const char* com_tinker_get_device_name(xtion_capture* instance) {
		return instance->get_device()->getDeviceInfo().getName();
	}
	const char* com_tinker_get_vendor_name(xtion_capture* instance) {	
		return instance->get_device()->getDeviceInfo().getVendor();
	}

	const char * com_tinker_start_depth_stream(xtion_capture* instance) {
		return instance->start_depth_stream();
	}
	DepthPixel* com_tinker_get_depth_data(xtion_capture* instance) {
		return instance->get_depth_data();
	}
}