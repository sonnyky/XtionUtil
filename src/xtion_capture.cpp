#include "xtion_capture.h"

xtion_capture::xtion_capture()
{
	Status rc = thisDevice.open(ANY_DEVICE);
	if (rc != STATUS_OK)
	{
		set_error_message("Failed to open device");
		return;
	}
}

xtion_capture::~xtion_capture()
{
	
}

void xtion_capture::open_device() {
	
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

void xtion_capture::set_device_address(Device* address) {
	device_address = address;
}

void xtion_capture::set_device_uri(std::string uri) {
	device_uri = uri;
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

Device* xtion_capture::get_handle() {
	return device_address;
}

const char* xtion_capture::get_device_name() {
	return device_address->getDeviceInfo().getName();
}

const char * xtion_capture::get_first_device_name() {
	return device_name;
}

const char * xtion_capture::get_vendor_name() {
	return get_handle()->getDeviceInfo().getVendor();
}

bool xtion_capture::is_valid() {
	return device_address->isValid();
}

OniDeviceHandle xtion_capture::get_device_handle() {
	return device_handle;
}

std::string xtion_capture::get_device_uri() {
	return device_uri;
}
void xtion_capture::set_device_handle(OniDeviceHandle handle) {
	device_handle = handle;
}