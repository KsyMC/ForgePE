#pragma once

#include "minecraftpe/item/ItemInstance.h"
#include "minecraftpe/tile/TilePos.h"
#include "minecraftpe/network/Packet.h"

class UseItemPacket : public Packet {
public:
	TilePos _tilePos;			// 12
	unsigned char _face;		// 24
	float _posX;				// 28
	float _posY;				// 32
	float _posZ;				// 36
	float _fx;					// 40
	float _fy;					// 44
	float _fz;					// 48
	int _eid;					// 52
	short _item;				// 56
	unsigned short _meta;		// 58
	ItemInstance _itemInstance;	// 60

public:
	virtual ~UseItemPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);
};
