#pragma once

namespace RakNet {
class RakNetGUID;
class RakPeer;
class AddressOrGUID;
class RakNetStatistics;
}
class Packet;
class NetEventCallback;

class IRakNetInstance {
public:
	virtual ~IRakNetInstance();
	virtual void host(std::string const &, int, int);
	virtual void connect(const char *, int);
	virtual void setIsLoggedIn(bool);
	virtual void startPingForHosts(int);
	virtual void startPingForHosts(int, const std::vector<std::string> &);
	virtual void stopPingForHosts();
	virtual void getServerList();
	virtual void clearServerList();
	virtual void disconnect();
	virtual void announceServer(const std::string &);
	virtual RakNet::RakPeer *getPeer();
	virtual void isMyLocalGuid(const RakNet::RakNetGUID &);
	virtual void runEvents(NetEventCallback *);
	virtual void send(Packet &);
	virtual void send(const RakNet::RakNetGUID &, Packet &);
	virtual void send(Packet *);
	virtual void send(const RakNet::RakNetGUID &, Packet *);
	virtual void send(const RakNet::AddressOrGUID &, Packet &, bool);
	virtual void isServer();
	virtual void isProbablyBroken();
	virtual void resetIsBroken();
	virtual void getStatistics(RakNet::RakNetStatistics *);
	virtual void getPacketCounts();
};
