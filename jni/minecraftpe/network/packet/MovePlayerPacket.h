#pragma once

#include "minecraftpe/network/Packet.h"

class MovePlayerPacket : public Packet {
public:
	// Size : 44
	uint _eid; 		// 12
	float _x;		// 16
	float _y;		// 20
	float _z;		// 24
	float _bodyYaw;	// 28
	float _pitch;	// 32
	float _yaw;		// 36
	bool _teleport;	// 40

public:
	virtual ~MovePlayerPacket();
	virtual void write(RakNet::BitStream *);
	virtual void read(RakNet::BitStream *);
	virtual void handle(const RakNet::RakNetGUID &, NetEventCallback *);
};
