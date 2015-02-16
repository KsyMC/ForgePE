#pragma once

#include <memory>
#include <unordered_set>

#include "minecraftpe/client/AppPlatformListener.h"
#include "minecraftpe/level/LevelListener.h"

class Minecraft;
class LevelStorage;
class Player;
class Entity;
class Mob;
class LevelSettings;
class TilePos;
class Vec3;
class FullTile;
class LightLayer;

class Level : public AppPlatformListener, public LevelListener {
public:
	//void **vtable;						// 8
	bool isMultiLevel;						// 12
	char filler1[47];						// 13
	std::unordered_set<Player *> _players;	// 60

public:
	Level(Minecraft &, std::unique_ptr<LevelStorage>, const std::string &, const LevelSettings &, bool);
	virtual ~Level();
	virtual void onSourceCreated(TileSource *);
	virtual void onSourceDestroyed(TileSource *);
	virtual void onTileChanged(TileSource *, const TilePos &, FullTile, FullTile, int);
	virtual void isNaturalDimension();
	virtual void addEntity(Entity *);
	virtual void addPlayer(Player *);
	virtual void tick();
	virtual void directTickEntities();
	virtual void updateSleepingPlayerList();
	virtual void setDifficulty(int);
	virtual void runLightUpdates(TileSource &, const LightLayer &, const TilePos &, const TilePos &);
	virtual void onNewChunkFor(Player &, LevelChunk &);
	virtual void onChunkLoaded(LevelChunk &);
	virtual void removeEntity(std::unique_ptr<Entity> &&);
	virtual void removeEntity(Entity &);
	virtual void onAppSuspended();
	virtual void onAppResumed();
	bool addParticle(ParticleType, const Vec3 &, float, float, float, int);
	void addListener(LevelListener *);
	void removeListener(LevelListener *);
	char getDifficulty() const;
	long getSeed();
	Entity *getEntity(int, bool);
	Mob *getMob(int);
	Player *getLocalPlayer();
	Player *getPlayer(int);
	Player *getPlayer(const std::string &);
	Player *getPlayerByClientId(int);
	Player *getRandomPlayer();
	Player *getNearestPlayer(Entity *, float);
	Player *getNearestPlayer(float, float, float, float);
	long getTime() const;
	void setTime(long);
	void setNightMode(bool);
	void setDayCycleActive(bool);
	void setDefaultSpawn(const TilePos &);
};
