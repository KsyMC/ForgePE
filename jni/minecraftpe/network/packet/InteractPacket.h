#pragma once

#include "minecraftpe/network/Packet.h"
#include "minecraftpe/raknet/RakString.h"

class InteractPacket : public Packet {
public:
	char _action;		// 12
	uint _eid;			// 16
	uint _target;		// 20

public:
	virtual ~InteractPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);
};
