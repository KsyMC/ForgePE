#pragma once

#include <string>
#include <memory>

#include "minecraftpe/client/App.h"

class Level;
class GameMode;
class Player;
class LocalPlayer;
class Mob;
class RakNetInstance;
class NetEventCallback;
class ServerCommandParser;
class LevelSettings;
class ICommandManager;

class Minecraft : public App {
public:
	// Size : NONE
	char filler1[28];					// 4
	int _width;							// 32
	int _height;						// 36
	char filler2[24];					// 40
	GameMode *_gameMode;				// 64
	char filler3[8];					// 68
	RakNetInstance *_raknetInstance;	// 76
	NetEventCallback *_netEventCallback;// 80
	char filler4[16];					// 84
	std::string _serverName;			// 100
	Level *_level;						// 104
	char filler5[44];					// 108
	ServerCommandParser *_commandParser;// 152

public:
	Minecraft(int, char **);
	virtual ~Minecraft();
	virtual void update();
	virtual void init();
	virtual void teardown();
	virtual void selectLevel(const std::string &, const std::string &, const LevelSettings &);
	virtual void setLevel(std::unique_ptr<Level> &, const std::string &, Player *);
	virtual void startFrame();
	virtual void updateGraphics();
	virtual void endFrame();
	virtual void tick(int, int);
	virtual void leaveGame(bool, bool);
	virtual void play(const std::string &, float, float, float, float, float);
	virtual void playUI(const std::string &, float, float);
	virtual void updateSoundLocation(Mob *, float);
	virtual void isServerVisible();
	virtual void sendLocalMessage(const std::string &, const std::string &);
	virtual LocalPlayer *getPlayer();
	virtual void onInternetUpdate();
	virtual void onPlayerLoaded(Player &);
	virtual void vibrate(int);
	void init(const std::string &);
	void hostMultiplayer(int);
	void cancelLocateMultiplayer();
	void *getLevelSource();
	ServerCommandParser *getCommandParser();
	const char *getCreator();
	std::string getServerName();
	bool isCreativeMode();
	void setIsCreativeMode(bool);
	void setLeaveGame();
	void removeAllPlayers();
	bool isOnline();
	bool isOnlineClient();
	void updateStats();

public:
	static ICommandManager *_commandManager;

	ICommandManager *getCommandManager();

public:
	typedef void (*InitReal)(Minecraft *, const std::string &);

	static InitReal init_real;

public:
	static void initHooks(void *);
	void init_hook(const std::string &);
	std::string getServerName_hook();
};
