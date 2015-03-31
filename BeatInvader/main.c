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
/**************************DriverUnload********************************/
VOID
DriverUnload(IN PDRIVER_OBJECT pDriverObj)
{	

	return;
}
/**************************DriverEntry********************************/
NTSTATUS
DriverEntry(IN PDRIVER_OBJECT pDriverObj, IN PUNICODE_STRING pRegistryString)
{
	NTSTATUS status = STATUS_SUCCESS;
	pDriverObj->DriverUnload = DriverUnload;
	return STATUS_SUCCESS;
}


