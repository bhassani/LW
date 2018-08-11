#include "stdafx.h"
#include "memory.h"
#include "extend.h"



SHORT readShort(DWORD BaseAddress)
{
	SHORT value = 0;
	__try {

		if (IsBadReadPtr((LPVOID)BaseAddress, sizeof(value)) == 0) {
			value = *(SHORT *)BaseAddress;
			return value;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		debug_print("readShort - exception code < %8x >\n", GetExceptionCode());
	}
	return -1;
}
INT readInteger(DWORD BaseAddress)
{
	INT value = 0;
	__try {
		if (IsBadReadPtr((LPVOID)BaseAddress, sizeof(value)) == 0) {
			value = *(INT *)BaseAddress;
			return value;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		debug_print("readInteger - exception code < %8x >\n", GetExceptionCode());
	}
	return -1;
}
FLOAT readFloat(DWORD BaseAddress)
{
	FLOAT value = 0;
	__try {
		if (IsBadReadPtr((LPVOID)BaseAddress, sizeof(value)) == 0) {
			value = *(FLOAT *)BaseAddress;
			return value;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		debug_print("readFloat - exception code < %8x >\n", GetExceptionCode());
	}
	return -1;
}

std::string readString(DWORD BaseAddress,INT Length)
{

}


BOOL writeShort(DWORD BaseAddress,SHORT value)
{
	if (readInteger(BaseAddress) == -1)
	{
		return FALSE;
	}
	__try {

		if (IsBadWritePtr((LPVOID)BaseAddress, sizeof(value)) == 0) {
			*(SHORT *)BaseAddress = value;
			return TRUE;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		debug_print("writeShort - exception code < %8x >\n", GetExceptionCode());
	}
	return FALSE;
}
BOOL writeInteger(DWORD BaseAddress, INT value)
{
	if (readInteger(BaseAddress) == -1)
	{
		return FALSE;
	}
	__try {
		if (IsBadWritePtr((LPVOID)BaseAddress, sizeof(value)) == 0) {
			*(INT *)BaseAddress  = value;
			return TRUE;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		debug_print("writeInteger - exception code < %8x >\n", GetExceptionCode());
	}
	return FALSE;
}
BOOL writeFloat(DWORD BaseAddress, FLOAT value)
{
	if (readInteger(BaseAddress) == -1)
	{
		return FALSE;
	}
	__try {
		if (IsBadWritePtr((LPVOID)BaseAddress, sizeof(value)) == 0) {
			*(FLOAT *)BaseAddress = value;
			return TRUE;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		debug_print("writeFloat - exception code < %8x >\n", GetExceptionCode());
	}
	return FALSE;
}