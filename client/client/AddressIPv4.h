#pragma once
#include <WinSock2.h>
#include <windows.h>
#include <cstdint>
#include <memory>

class AddressIPv4
{
private:
	//	原始地址结构
	sockaddr _addr;
private:
	//	获取sockaddr_in形式
	sockaddr_in *GetAddrIn() { return reinterpret_cast<sockaddr_in*>(&_addr); }
public:
	AddressIPv4(uint32_t uAddr, uint16_t uPort)
	{
		GetAddrIn()->sin_family = AF_INET;
		GetAddrIn()->sin_addr.S_un.S_addr = uAddr;
		GetAddrIn()->sin_port = uPort;
	}

	AddressIPv4(const sockaddr &other)
	{
		memcpy(&_addr, &other, sizeof(_addr));
	}

	~AddressIPv4()
	{
	}

	//	获取地址size
	size_t GetSize() const { return sizeof(_addr); }
};

using PAddressIPv4 = std::shared_ptr<AddressIPv4>;
