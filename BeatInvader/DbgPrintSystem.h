#pragma once
#include "struct.h"
#include <stdio.h>
#define  _VDBG_
//#ifdef _VDBG_
//#define CodeVprint(_x_)  DbgPrint(_x_)
//#else
//#define CodeVprint(_x_) 
//#endif
ULONG  CodeVprint(	
	__in_z __drv_formatString(printf) PCSTR Format,
	...);