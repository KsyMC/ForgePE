#pragma once

#include "minecraftpe/network/Packet.h"
#include "minecraftpe/tile/TilePos.h"

class UpdateBlockPacket : public Packet {
public:
	TilePos _tilePos;		// 12
	unsigned char _id;		// 24
	unsigned char _damage;	// 25

public:
	UpdateBlockPacket() : _tilePos{0, 0, 0} {
		_id = 0;
		_damage = 0;
	}
	virtual ~UpdateBlockPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);
};
