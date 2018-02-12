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
	void com_tinker_open_device(xtion_capture* instance) {
		Device device;
		Status rc = device.open(ANY_DEVICE);
		if (rc != STATUS_OK)
		{
			return;
		}
		std::string device_uri_string(device.getDeviceInfo().getUri()) ;
		instance->set_init_flag(true);
		instance->set_device_address(&device);
		instance->set_device_uri(device_uri_string);
		ofstream myfile;
		myfile.open("open_device.txt");
		myfile << "The device URI.\n";
		myfile << device.getDeviceInfo().getUri();
		myfile << "\nFinished.\n";
		myfile.close();
		instance->set_device_handle(device._getHandle());
		return;
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
		
		std::string device_uri = instance->get_device_uri();
		ofstream myfile;
		Device newDevice;
		Status rc = newDevice.open(device_uri.c_str());
		if (rc != STATUS_OK)
		{
			return "cannot open device name";
		}
		myfile.open("vendor.txt");
		myfile << "Plugin name.\n";
		myfile << instance->get_plugin_name();
		myfile << "URI\n";
		myfile << newDevice.getDeviceInfo().getVendor();
		myfile << "\nFinished.\n";
		myfile.close();
		
		return "check text file first";
	}
}