/*
	Copyright (c) 2017-2018 Andrew Depke
*/
#pragma once

#include "../Core/Platform.h"

#if OS_WINDOWS
	#include "Windows/WindowsProcess.h"
#elif OS_MACINTOSH
	#include "Darwin/DarwinProcess.h"
#elif OS_LINUX
	#include "Linux/LinuxProcess.h"
#elif OS_BSD
	#include "Linux/LinuxProcess.h"
#elif OS_ANDROID
	#include "Linux/LinuxProcess.h"
#elif OS_IOS
	#include "Darwin/DarwinProcess.h"
#endif