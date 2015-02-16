#pragma once

#include "minecraftpe/raknet/RakString.h"
#include "minecraftpe/network/Packet.h"

class LoginPacket : public Packet {
public:
	RakNet::RakString _name;		// 12
	int _clientId;					// 16
	int _protocol1;					// 20
	int _protocol2;					// 24
	RakNet::RakString _loginData;	// 28

public:
	virtual ~LoginPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);
};
