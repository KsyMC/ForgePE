#pragma once

#include "minecraftpe/network/Packet.h"

class RemoveBlockPacket : public Packet {
public:
	uint _eid;			// 12
	int _x;				// 16
	int _z;				// 20
	unsigned char _y;	// 24

public:
	virtual ~RemoveBlockPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);
};
