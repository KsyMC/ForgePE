#pragma once

#include "minecraftpe/ParticleTypeEnum.h"
#include "minecraftpe/level/TileSourceListener.h"

class Mob;
class Player;
class Entity;
class LevelChunk;
class Vec3;

class LevelListener : public TileSourceListener {
public:
	virtual ~LevelListener();
	virtual void allChanged();
	virtual bool addParticle(ParticleType, const Vec3 &, float, float, float, int);
	virtual void playSound(const std::string &, float, float, float, float, float);
	virtual void playMusic(const std::string &, float, float, float, float);
	virtual void playStreamingMusic(const std::string &, int, int, int);
	virtual void onEntityAdded(Entity &);
	virtual void onEntityRemoved(Entity &);
	virtual void onNewChunkFor(Player &, LevelChunk &);
	virtual void levelEvent(Mob *, int, int, int, int, int);
};
