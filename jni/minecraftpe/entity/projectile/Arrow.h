#pragma once

#include "minecraftpe/entity/Entity.h"

class Player;
class Mob;

class Arrow : public Entity {
public:
	Arrow(Mob *, float);
	Arrow(Mob *, Mob *, float, float);
	Arrow(TileSource &);
	Arrow(TileSource &, float, float, float);
	virtual void lerpMotion(float, float, float);
	virtual void normalTick();
	virtual float getShadowRadius();
	virtual float getShadowHeightOffs();
	virtual void playerTouch(Player *);
	virtual int getEntityTypeId() const;
	virtual int getAuxData();
	virtual void readAdditionalSaveData(CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	void shoot(float, float, float, float, float);
	void _init();
};
