#pragma once

#include <cstdint>

namespace RakNet {
typedef unsigned char UniqueIDType;
typedef unsigned short SystemIndex;
typedef unsigned char RPCIndex;
typedef uint32_t BitSize_t;

struct SocketDescriptor {
	unsigned short port;
	char hostAddress[32];
	unsigned short remotePortRakNetWasStartedOn_PS3;

	SocketDescriptor();
	SocketDescriptor(unsigned short _port, const char *_hostAddress);
};

struct RakNetGUID {
	uint64_t g;
	SystemIndex systemIndex;
	char filler1[6];

	RakNetGUID();
	explicit RakNetGUID(uint64_t _g);
	void ToString(char *dest) const;
	const char *ToString() const;
	bool FromString(const char *source);
	bool operator!=(const RakNet::RakNetGUID &right);
	bool operator<(const RakNet::RakNetGUID &right);
	bool operator==(const RakNet::RakNetGUID &right);
	bool operator>(const RakNet::RakNetGUID &right);
};

struct SystemAddress {
	uint32_t binaryAddress;
	unsigned short port;
	SystemIndex systemIndex;

	SystemAddress();
	explicit SystemAddress(const char *a, unsigned short b);
	explicit SystemAddress(unsigned int a, unsigned short b);
	SystemAddress(const char *a);
	const char *ToString(bool writePort=true) const;
	void ToString(bool writePort, char *dest) const;
	void SetBinaryAddress(const char *str);
	SystemAddress& operator=(const SystemAddress& input);
	bool operator==( const SystemAddress& right ) const;
	bool operator!=( const SystemAddress& right ) const;
	bool operator > ( const SystemAddress& right ) const;
	bool operator < ( const SystemAddress& right ) const;
	static int size();
};

const SystemAddress UNASSIGNED_SYSTEM_ADDRESS;
const RakNetGUID UNASSIGNED_RAKNET_GUID;

struct Packet {
	SystemAddress systemAddress;
	RakNetGUID guid;
	unsigned int length;
	BitSize_t bitSize;
	unsigned char *data;
	bool deleteData;
};

struct AddressOrGUID {
	RakNetGUID rakNetGuid;
	SystemAddress systemAddress;

	AddressOrGUID(RakNet::Packet *packet);
	AddressOrGUID(const RakNet::AddressOrGUID &input);
	AddressOrGUID(const RakNet::SystemAddress &input);
	bool IsUndefined() const;
	int ToInteger(const RakNet::AddressOrGUID &input);
	const char *ToString(bool);
	void ToString(bool, char *);
	void operator=(const RakNet::SystemAddress &input);
};
}
