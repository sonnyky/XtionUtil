#include <OpenNI.h>
#include <iostream>

#pragma once
using namespace openni;

class xtion_capture
{
public:
	xtion_capture();
	~xtion_capture();

	void set_init_flag(bool flag);
	bool get_init_flag();

	const char * plugin_name = "tinker xtion plugin for Unity";
	const char * get_plugin_name();

	const char * error_message;
	const char * get_error_message();
	void set_error_message(std::string error);

	void open_device();
	void close_device();

	std::string device_uri;
	std::string get_device_uri();
	void set_device_address(Device* address);
	void set_device_uri(std::string uri);

	Device thisDevice;
	Device* get_device();

	OniDeviceHandle get_device_handle();
	void set_device_handle(OniDeviceHandle handle);
	Device* get_handle();
	bool is_valid();
	const char* get_device_name();

	const char * get_vendor_name();
	const char * vendor_name;

	const char* device_name;
	const char * get_first_device_name();

private:
	bool init_success_flag;
	Device* device_address;
	OniDeviceHandle device_handle;
};

