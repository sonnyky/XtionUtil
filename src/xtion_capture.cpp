#include "xtion_capture.h"

xtion_capture::xtion_capture()
{
}

xtion_capture::~xtion_capture()
{
	
}

void xtion_capture::open_device() {
	Status rc = thisDevice.open(ANY_DEVICE);
	if (rc != STATUS_OK)
	{
		set_error_message("Failed to open device");
		return;
	}
}

Device* xtion_capture::get_device() {
	return &thisDevice;
}

void xtion_capture::set_init_flag(bool flag) {
	init_success_flag = flag;
}

bool xtion_capture::get_init_flag() {
	return init_success_flag;
}


const char * xtion_capture::get_error_message() {
	return error_message;
}

void xtion_capture::set_error_message(std::string error) {
	error_message = error.c_str();
}

const char * xtion_capture::get_plugin_name() {
	return plugin_name;
}

void xtion_capture::close_device() {
	device_address->close();
	OpenNI::shutdown();
}
