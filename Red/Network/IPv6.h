/*
	Copyright (c) 2017-2018 Andrew Depke
*/
#pragma once

#include "../Core/Platform.h"

#include "IP.h"

#if OS_WINDOWS
	#include <WS2tcpip.h>  // sockaddr_in6
	#include <cstring>  // memset(), memcmp()
#else
	#include <sys/socket.h>  // sockaddr_in6
	#include <string.h>  // memset(), memcmp()
#endif

namespace Red
{
	// Wrapper Around sockaddr_in6
	struct IP6Address : public IPAddress
	{
	public:
		sockaddr_in6 Address;

	public:
		IP6Address() : IPAddress(IPv6)
		{
#if OS_WINDOWS
			std::memset(&Address, 0, sizeof(Address));
#else
			memset(&Address, 0, sizeof(Address));
#endif

			Address.sin6_family = AF_INET6;
		}

		IP6Address(const sockaddr_in6& Target) : IPAddress(IPv6), Address(Target) {}

		IP6Address(const char* InAddress) : IPAddress(IPv6)
		{
			if (inet_pton(AF_INET6, InAddress, &Address.sin6_addr) != 1)
			{
#if OS_WINDOWS
				std::memset(&Address.sin6_addr, 0, sizeof(Address.sin6_addr));
#else
				memset(&Address.sin6_addr, 0, sizeof(Address.sin6_addr));
#endif
			}
		}

		virtual ~IP6Address() {}

	public:
		IP6Address& operator=(const IP6Address& Target)
		{
			Address = Target.Address;

			return *this;
		}

		bool operator==(const IP6Address& Target) const
		{
			return (memcmp((void*)&Address, (void*)&Target.Address, sizeof(Address)) == 0);
		}

		bool operator!=(const IP6Address& Target) const
		{
			return !operator==(Target);
		}

	public:
		// Loopback: ::1
		virtual bool IsLoopbackAddress() const override
		{
			static const in6_addr LoopbackAddress{ { { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 } } };

			return (memcmp((void*)&Address.sin6_addr, (void*)&LoopbackAddress, sizeof(Address.sin6_addr)) == 0);
		}

		// @todo: Need a Better Way to Handle This
		virtual bool IsMulticastAddress() const override
		{
			/*
			static in6_addr MulticastAddress{ { { 0xff, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 } } };

			return memcmp(Address.sin6_addr, MulticastAddress, sizeof(Address.sin6_addr)) == 0;
			*/

			return false;
		}

		virtual operator std::string() const override
		{
			char AddressString[64];

			inet_ntop(AF_INET6, &Address.sin6_addr, AddressString, sizeof(AddressString));

			return std::string(AddressString);
		}
	};

	struct IP6EndPoint : public IPEndPoint
	{
	public:
		IP6Address Address;
		unsigned short Port;

	public:
		IP6EndPoint() : IPEndPoint(IPv6), Port(0) {}
		IP6EndPoint(const IP6Address& InAddress, unsigned short InPort) : IPEndPoint(IPv6), Address(InAddress), Port(InPort) {}

		virtual ~IP6EndPoint() {}

	public:
		IP6EndPoint& operator=(const IP6EndPoint& Target)
		{
			Address = Target.Address;
			Port = Target.Port;

			return *this;
		}

		bool operator==(const IP6EndPoint& Target) const
		{
			return (Address == Target.Address && Port == Target.Port);
		}

		bool operator!=(const IP6EndPoint& Target) const
		{
			return (Address != Target.Address || Port != Target.Port);
		}

	public:
		virtual operator std::string() const override
		{
			char AddressString[64];

			inet_ntop(AF_INET6, &Address.Address.sin6_addr, AddressString, sizeof(AddressString));

			std::string AddressStringType = "[";

			AddressStringType += AddressString;
			AddressStringType += "]:" + std::to_string(Port);

			return AddressStringType;
		}
	};
}  // namespace Red