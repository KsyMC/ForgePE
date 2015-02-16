#pragma once

#include "minecraftpe/network/Packet.h"
#include "minecraftpe/raknet/RakString.h"

class ChatPacket : public Packet {
public:
	std::string _chat;	// 12

public:
	virtual ~ChatPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);
};
