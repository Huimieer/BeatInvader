#ifndef _COMMDEVICE_H_
#define  _COMMDEVICE_H_
#include "struct.h"
#include "IoCtrlCode.h"
NTSTATUS CreateCommDevice(IN PDRIVER_OBJECT  DriverObject);

VOID DeleteDevice(PDEVICE_OBJECT pDeviceObj);

NTSTATUS DispatchIoctrl(
	PDEVICE_OBJECT pDeviceObject,
	PIRP pIrp);

NTSTATUS DispatchCommon(
	PDEVICE_OBJECT pDeviceObject,
	PIRP pIrp);
#endif