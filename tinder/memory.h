#pragma once
SHORT readShort(DWORD BaseAddress);

INT readInteger(DWORD BaseAddress);

FLOAT readFloat(DWORD BaseAddress);

std::string readString(DWORD BaseAddress, INT Length);

BOOL writeShort(DWORD BaseAddress, SHORT value);

BOOL writeInteger(DWORD BaseAddress, INT value);

BOOL writeFloat(DWORD BaseAddress, FLOAT value);
