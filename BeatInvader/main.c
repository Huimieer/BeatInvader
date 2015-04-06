/***************************************************************************************
* AUTHOR : vLink
* DATE   : 2015-3-31
* MODULE : BeatInvader.C
* 
* Command: 
*	Source of IOCTRL Sample Driver
*
* Description:
*		Demonstrates communications between USER and KERNEL.
*
****************************************************************************************
* Copyright (C) 2010 vLink.
****************************************************************************************/
#include "main.h"
#include "struct.h"
#include "CommDevice.h"
/**************************DriverUnload********************************/
VOID
DriverUnload(IN PDRIVER_OBJECT pDriverObj)
{	
	DeleteDevice(pDriverObj->DeviceObject);
	CodeVprint("Driver Unload");
	return;
}
/**************************RegisterDispatch********************************/
VOID RegisterDispatch(PDRIVER_OBJECT pDriverObj)
{
	int i = 0;
	//×¢²á¸÷ÖÖº¯Êý
	pDriverObj->DriverUnload = DriverUnload;
	for(i = 0; i < IRP_MJ_MAXIMUM_FUNCTION; i++)
	{
		pDriverObj->MajorFunction[i] = DispatchCommon;
	}
	pDriverObj->MajorFunction[IRP_MJ_DEVICE_CONTROL] = DispatchIoctrl;
}
/**************************DriverEntry********************************/
NTSTATUS
DriverEntry(IN PDRIVER_OBJECT pDriverObj, IN PUNICODE_STRING pRegistryString)
{
	NTSTATUS nStatus = STATUS_SUCCESS;
	CodeVprint("Enter DriverEntry");
	DbgBreakPoint();
	nStatus = CreateCommDevice(pDriverObj);
	if (!NT_SUCCESS(nStatus))
	{
		return nStatus;
	}
	RegisterDispatch(pDriverObj);
	return STATUS_SUCCESS;
}


