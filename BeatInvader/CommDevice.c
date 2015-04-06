#include "CommDevice.h"

#define CommDeviceName L"\\device\\SpursWinDevice"
#define CommSymbolName L"\\dosdevices\\SpursWin"
NTSTATUS CreateCommDevice(IN PDRIVER_OBJECT  DriverObject)
{
	NTSTATUS nStatus = STATUS_SUCCESS;
	PDEVICE_OBJECT pDeviceObj = NULL;
	UNICODE_STRING uDeviceName = {0};
	UNICODE_STRING uSymbolLinkName = {0};
/*
	NTSTATUS 
		IoCreateDevice(
		IN PDRIVER_OBJECT  DriverObject,
		IN ULONG  DeviceExtensionSize,
		IN PUNICODE_STRING  DeviceName  OPTIONAL,
		IN DEVICE_TYPE  DeviceType,
		IN ULONG  DeviceCharacteristics,
		IN BOOLEAN  Exclusive,
		OUT PDEVICE_OBJECT  *DeviceObject
		);*/

	RtlInitUnicodeString(&uDeviceName,CommDeviceName);
	nStatus = IoCreateDevice(DriverObject,
		0,
		&uDeviceName,
		FILE_DEVICE_UNKNOWN,
		0,
		TRUE,
		&pDeviceObj);
	if (!NT_SUCCESS(nStatus))
	{
		CodeVprint("IoCreateDevice Failed");
		return nStatus;
	}
	//设置成缓冲方式
	pDeviceObj->Flags |= DO_BUFFERED_IO;
	//创建符号链接
	RtlInitUnicodeString(&uSymbolLinkName,CommSymbolName);
	nStatus = IoCreateSymbolicLink(&uSymbolLinkName,&uDeviceName);
	if (!NT_SUCCESS(nStatus))
	{
		CodeVprint("IoCreateSymbolicLink Failed");
		//删除device
		IoDeleteDevice(pDeviceObj);
		return nStatus;
	}
	return nStatus;
}
//
VOID DeleteDevice(PDEVICE_OBJECT pDeviceObj)
{

	UNICODE_STRING uSymbolLinkName = {0};
	RtlInitUnicodeString(&uSymbolLinkName,CommSymbolName);
	IoDeleteSymbolicLink(&uSymbolLinkName);
	IoDeleteDevice(pDeviceObj);
	CodeVprint("DeleteDevice success");
}
//通信控制，各种命令的集散地
NTSTATUS DispatchIoctrl(PDEVICE_OBJECT pDeviceObject,
	PIRP pIrp)
{
	PVOID pInputBuffer = NULL;
	PVOID pOutputBuffer = NULL;

	ULONG ulInputLength = 0;
	ULONG ulOutputLength = 0;
	ULONG ulIoCtrlCode = 0;


	PIO_STACK_LOCATION pStack = NULL;
	CodeVprint("Dispatch Ioctrl Called\n");
	pInputBuffer = pOutputBuffer = pIrp->AssociatedIrp.SystemBuffer;
	pStack = IoGetCurrentIrpStackLocation(pIrp);
	ulInputLength = pStack->Parameters.DeviceIoControl.InputBufferLength;
	ulOutputLength = pStack->Parameters.DeviceIoControl.OutputBufferLength;
	ulIoCtrlCode = pStack->Parameters.DeviceIoControl.IoControlCode;

	switch(ulIoCtrlCode)
	{
	case COMM_PRINT_TEST:
		CodeVprint("DeviceIoControl called success!");
		break;

	default:
		CodeVprint("Unkown code!\n");
		break;
	}

	pIrp->IoStatus.Status = STATUS_SUCCESS;
	IoCompleteRequest(pIrp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}
//
NTSTATUS DispatchCommon(PDEVICE_OBJECT pDeviceObject,
	PIRP pIrp)
{
	pIrp->IoStatus.Status = STATUS_SUCCESS;
	IoCompleteRequest(pIrp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}