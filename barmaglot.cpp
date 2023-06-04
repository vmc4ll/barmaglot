#include <cstdio>
#include <Windows.h>
#include "barmaglot.h";
#include <wchar.h>

int main()
{
	HANDLE device = CreateFile(L"barmaglot", GENERIC_WRITE, FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, 0, nullptr);

	if (device == INVALID_HANDLE_VALUE) {
		printf("Couldn't open device.\n");
		return 0;
	}

	DWORD bytesReturned;

	WCHAR executableName[] = L"\\Windows\\System32\\notepad.exe";
	size_t len = (wcslen(executableName) + 1) * sizeof(WCHAR);

	DWORD result = DeviceIoControl(device, IOCTL_ROOTKIT_PREVENT_START, executableName, len, nullptr, 0, &bytesReturned, nullptr);

	CloseHandle(device);

	if (result)
	{
		printf("%s", "Try starting notepad.exe!\n");
	}

	else
	{
		printf("%s", "An error occurred\n");
	}

}
