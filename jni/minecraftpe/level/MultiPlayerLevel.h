#pragma once

#include "minecraftpe/level/Level.h"

class MultiPlayerLevel : public Level {
public:
	class ResetInfo {
	public:
		ResetInfo(int, int, int, int, int);
	};

public:
	// Size : 3072

public:
	MultiPlayerLevel(Minecraft &, const std::string &, const LevelSettings &);
	virtual ~MultiPlayerLevel();
	virtual void addEntity(Entity *);
	virtual void tick();
	virtual void directTickEntities();
	void putEntity(int, Entity *);
};
