#pragma once

#include "minecraftpe/raknet/RakString.h"
#include "minecraftpe/network/Packet.h"

namespace RakNet {
class RakString;
}

class MessagePacket : public Packet {
public:
	RakNet::RakString _name;	// 12
	RakNet::RakString _message;	// 16

public:
	virtual ~MessagePacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);
};
