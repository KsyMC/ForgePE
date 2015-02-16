#pragma once

#include "minecraftpe/ItemInstance.h"
#include "minecraftpe/network/Packet.h"

class ContainerSetSlotPacket : public Packet {
public:
	// Size : 36
	bool _wtf;					// 12
	unsigned char _windowId;	// 13
	unsigned short _slot;		// 14
	ItemInstance _itemInstance;	// 16

public:
	virtual ~ContainerSetSlotPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);

};
