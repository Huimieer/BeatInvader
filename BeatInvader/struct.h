/***************************************************************************************
* AUTHOR : vLink
* DATE   : 2015-3-31
* MODULE : struct.h
* 
* Command: 
*   驱动的头文件
*
* Description:
*   定义一些常量,避免重复劳动; 您可以在此添加需要的函数/结构体
*
****************************************************************************************

Copyright (C) 2010 vLink.
****************************************************************************************/
#pragma once

#include <ntddk.h> 
//调试打印的头文件也放在这，基本上所有文件都要包含
#include "DbgPrintSystem.h"
typedef long LONG;
typedef unsigned char  BOOL, *PBOOL;
typedef unsigned char  BYTE, *PBYTE;
typedef unsigned long  DWORD, *PDWORD;
typedef unsigned short WORD, *PWORD;

typedef void  *HMODULE;
typedef unsigned long DWORD;
typedef DWORD * PDWORD;
typedef unsigned short WORD;
typedef unsigned long ULONG;
typedef ULONG * PULONG;
typedef unsigned char BYTE; 
typedef unsigned char UCHAR;
typedef unsigned short USHORT;
typedef void *PVOID;
typedef BYTE BOOLEAN;

//----------------------------------------------------

