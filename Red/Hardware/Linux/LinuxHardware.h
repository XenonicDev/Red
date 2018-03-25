/*
	Copyright (c) 2017-2018 Andrew Depke
*/
#pragma once

#include <cstdint>
#include <string>

namespace Red
{
	struct LinuxSystemHardware
	{
		static std::string GetOSName();
		static uint8_t GetArchitecture();
		static std::string GetCPUVendor();
		static std::string GetCPUBrand();
		static unsigned int GetCPUCoreCount();
		// Returns Physical Memory Size in Megabytes
		static unsigned long int GetPhysicalMemory();
		// Returns Disk Space of the Disk Where the Executable is Housed in Megabytes
		static unsigned long int GetDiskSpace();
		// Returns Usable Disk Space of the Disk Where the Executable is Housed in Megabytes
		static unsigned long int GetDiskSpaceAvailable();
	};

	struct LinuxExternalHardware
	{

	};

	typedef LinuxSystemHardware SystemHardware;
	typedef LinuxExternalHardware ExternalHardware;
}  // namespace Red