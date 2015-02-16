#pragma once

#include "IRakNetInstance.h"

class RakNetInstance : public IRakNetInstance {
public:
	// Size 1096
	//void **vtable;			// 0
	RakNet::RakPeer *_RakPeer;	// 4

public:
	RakNetInstance();
	virtual ~RakNetInstance();
	virtual void host(const std::string &, int, int);
	virtual void connect(char const *, int);
	virtual void setIsLoggedIn(bool);
	virtual void startPingForHosts(int);
	virtual void startPingForHosts(int, const std::vector<std::string> &);
	virtual void stopPingForHosts();
	virtual void getServerList();
	virtual void clearServerList();
	virtual void disconnect();
	virtual void announceServer(const std::string &);
	virtual RakNet::RakPeer *getPeer();
	virtual void isMyLocalGuid(RakNet::RakNetGUID const &);
	virtual void runEvents(NetEventCallback *);
	virtual void send(Packet &);
	virtual void send(const RakNet::RakNetGUID  &, Packet &);
	virtual void send(Packet *);
	virtual void send(const RakNet::RakNetGUID &, Packet *);
	virtual void send(const RakNet::AddressOrGUID &, Packet &, bool);
	virtual void isServer();
	virtual void isProbablyBroken();
	virtual void resetIsBroken();
	virtual void getStatistics(RakNet::RakNetStatistics *);
	virtual void getPacketCounts();

public:
	typedef void (*HostReal)(RakNetInstance *, const std::string &, int, int);
	typedef void (*ConnectReal)(RakNetInstance *, char const *, int);
	typedef void (*StartPingForHostsReal)(RakNetInstance *, int, const std::vector<std::string> &);

	static HostReal host_real;
	static ConnectReal connect_real;
	static StartPingForHostsReal startPingForHosts_real;

	static void initHooks(void *);
	void host_hook(const std::string &, int, int);
	void connect_hook(char const *, int);
	void startPingForHosts_hook(int, const std::vector<std::string> &);
};
