//ls612: this should never be disabled

#pragma once
#include <dbghelp.h>
#pragma comment (lib, "dbghelp.lib")

LONG WINAPI CustomFilter(EXCEPTION_POINTERS *ExceptionInfo);
void CreateMiniDump(EXCEPTION_POINTERS *pep);