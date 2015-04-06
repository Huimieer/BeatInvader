#include "DbgPrintSystem.h"


/*
ULONG
	__cdecl
	DbgPrint (
	__in_z __drv_formatString(printf) PCSTR Format,
	...
	);*/
ULONG __cdecl CodeVprint(	
	__in_z __drv_formatString(printf) PCSTR Format,
	...)
{
#ifdef _VDBG_
	CHAR szPrintInfo[260] = {0};
	sprintf_s(szPrintInfo,(size_t)260,"%s\n",Format);
	return DbgPrint(szPrintInfo);
#else
	return 0;
#endif
}
