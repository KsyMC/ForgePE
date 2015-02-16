#pragma once

#include "minecraftpe/network/Packet.h"

class LoginStatusPacket : public Packet {
public:
	int _status;	// 12

public:
	virtual ~LoginStatusPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);
};
