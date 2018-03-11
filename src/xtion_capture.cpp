#include "xtion_capture.h"
#define SAMPLE_READ_WAIT_TIMEOUT 2000 //2000ms


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

const char* xtion_capture::start_depth_stream() {
	if (thisDevice.getSensorInfo(SENSOR_DEPTH) != NULL) {
		Status rc = depth_stream.create(thisDevice, SENSOR_DEPTH);
		if (rc == STATUS_OK)
		{
			rc = depth_stream.start();
			if (rc != STATUS_OK)
			{
				return OpenNI::getExtendedError();
			}
		}
		else
		{
			return OpenNI::getExtendedError();
		}
		return "Successfully started depth stream";
	}
	return "Get sensor info is null";
}

DepthPixel* xtion_capture::get_depth_data() {
	int changedStreamDummy;
	VideoStream* pStream = &depth_stream;
	Status rc = OpenNI::waitForAnyStream(&pStream, 1, &changedStreamDummy, SAMPLE_READ_WAIT_TIMEOUT);
	if (rc != STATUS_OK)
	{
		set_error_message("Wait failed");
	}
	rc = depth_stream.readFrame(&frame);
	if (rc != STATUS_OK)
	{
		set_error_message("Read failed");
	}
	if (frame.getVideoMode().getPixelFormat() != PIXEL_FORMAT_DEPTH_1_MM && frame.getVideoMode().getPixelFormat() != PIXEL_FORMAT_DEPTH_100_UM)
	{
		set_error_message("Unexpected frame format");
	}

	DepthPixel* pDepth = (DepthPixel*)frame.getData();
	//int middleIndex = (frame.getHeight() + 1)*frame.getWidth() / 2;

	//printf("[%08llu] %8d\n", (long long)frame.getTimestamp(), pDepth[middleIndex]);
	return pDepth;
}

int xtion_capture::test_depth_data() {
	int changedStreamDummy;
	VideoStream* pStream = &depth_stream;
	Status rc = OpenNI::waitForAnyStream(&pStream, 1, &changedStreamDummy, SAMPLE_READ_WAIT_TIMEOUT);
	if (rc != STATUS_OK)
	{
		set_error_message("Wait failed");
	}
	rc = depth_stream.readFrame(&frame);
	if (rc != STATUS_OK)
	{
		set_error_message("Read failed");
	}
	if (frame.getVideoMode().getPixelFormat() != PIXEL_FORMAT_DEPTH_1_MM && frame.getVideoMode().getPixelFormat() != PIXEL_FORMAT_DEPTH_100_UM)
	{
		set_error_message("Unexpected frame format");
	}

	DepthPixel* pDepth = (DepthPixel*)frame.getData();
	int middleIndex = (frame.getHeight() + 1)*frame.getWidth() / 2;

	//printf("[%08llu] %8d\n", (long long)frame.getTimestamp(), pDepth[middleIndex]);
	return pDepth[middleIndex];
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
	thisDevice.close();
	OpenNI::shutdown();
}
