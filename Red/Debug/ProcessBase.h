/*
	Copyright (c) 2017-2018 Andrew Depke
*/
#pragma once

#include <string>

namespace Red
{
	struct ProcessModule
	{
		std::string BaseAddress;
		std::string Name;
		long long int FileSize;  // In Bytes
	};
}  // namespace Red