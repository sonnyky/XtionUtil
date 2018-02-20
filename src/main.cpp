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
	Device* com_tinker_open_device(xtion_capture* instance) {
		Device device;
		Status rc = device.open(ANY_DEVICE);
		if (rc != STATUS_OK)
		{
			return nullptr;
		}
		std::string device_uri_string(device.getDeviceInfo().getUri()) ;
		instance->set_init_flag(true);
		instance->set_device_address(&device);
		instance->set_device_uri(device_uri_string);
		ofstream myfile;
		Device* address = &device;
		myfile.open("open_device.txt");
		myfile << "The device URI.\n";
		myfile << address->getDeviceInfo().getUri();
		myfile << "\nFinished.\n";
		myfile.close();
		instance->set_device_handle(device._getHandle());
		return &device;
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
		Device device;
		Status rc = device.open(ANY_DEVICE);
		if (rc != STATUS_OK)
		{
			return "cannot open device name";
		}
		return device.getDeviceInfo().getName();
	}
	const char* com_tinker_get_vendor_name(xtion_capture* instance) {
		
		ofstream myfile;
		/*
		Status rc = instance->open(ANY_DEVICE);
		if (rc != STATUS_OK)
		{
			return "cannot open device name";
		}
		*/
		myfile.open("vendor.txt");
		myfile << "Plugin name.\n";
		myfile << "xtion plugin";
		myfile << "URI\n";
		myfile << instance->get_device()->getDeviceInfo().getVendor();
		myfile << "\nFinished.\n";
		myfile.close();
		
		return "check text file first";
	}
}