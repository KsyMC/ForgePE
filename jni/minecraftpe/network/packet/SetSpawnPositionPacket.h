#pragma once

#include "minecraftpe/network/Packet.h"

class TilePos;

class SetSpawnPositionPacket : public Packet {
public:
	TilePos _tilePos;	// 12

public:
	SetSpawnPositionPacket() : _tilePos{0, 0, 0} {}
	virtual ~SetSpawnPositionPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);
};
