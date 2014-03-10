//ls612: this should never be disabled

#include "CvGameCoreDLLPCH.h"
#include "CvMinidump.h"

void CreateMiniDump(EXCEPTION_POINTERS *pep)
{
	/* Open a file to store the minidump. */
	HANDLE hFile = CreateFile(_T("CvMinidump.dmp"),
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if ((hFile == NULL) || (hFile == INVALID_HANDLE_VALUE)) {
		_tprintf(_T("CreateFile failed. Error: %u \n"), GetLastError());
		return;
	}
	/* Create the minidump. */
	MINIDUMP_EXCEPTION_INFORMATION mdei;

	mdei.ThreadId = GetCurrentThreadId();
	mdei.ExceptionPointers = pep;
	mdei.ClientPointers = FALSE;

	MINIDUMP_TYPE mdt = MiniDumpNormal;

	BOOL result = MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(),
		hFile,
		mdt,
		(pep != NULL) ? &mdei : NULL,
		NULL,
		NULL);

	/* Close the file. */
	CloseHandle(hFile);
}

LONG WINAPI CustomFilter(EXCEPTION_POINTERS *ExceptionInfo)
{
	CreateMiniDump(ExceptionInfo);
	return EXCEPTION_EXECUTE_HANDLER;
}