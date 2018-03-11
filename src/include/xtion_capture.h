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

	const char * error_message = "No error";
	const char * get_error_message();
	void set_error_message(std::string error);

	void open_device();
	void close_device();

	std::string device_uri;

	Device thisDevice;
	Device* get_device();
	VideoStream depth_stream;
	VideoFrameRef frame;

	const char* start_depth_stream();
	DepthPixel * depth_pixel;
	DepthPixel* get_depth_data();

	const char * vendor_name;

	const char* device_name;

private:
	bool init_success_flag;
};

