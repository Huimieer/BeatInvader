#pragma once
#define CTL_CODE( DeviceType, Function, Method, Access ) (                 \
	((DeviceType) << 16) | ((Access) << 14) | ((Function) << 2) | (Method) \
	)
#define  CTRL_BASE 0xa00
#define COMM_CONTROL_CODE(i) \
	CTL_CODE(FILE_DEVICE_UNKNOWN, CTRL_BASE+i, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define  COMM_PRINT_TEST		COMM_CONTROL_CODE(0)