#pragma once

#include "minecraftpe/entity/Entity.h"

class Item;
class Color;

class Mob : public Entity {
public:
	// Size : NONE
	char filler1[42];	// 286
	int _health;		// 328

public:
	Mob(Level &);
	Mob(TileSource &);
	virtual ~Mob();
	virtual void reset();
	virtual void lerpTo(float, float, float, float, float, int);
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual float getHeadHeight();
	virtual bool isPickable();
	virtual bool isPushable();
	virtual bool isShootable();
	virtual bool isSneaking();
	virtual bool isAlive();
	virtual bool isOnFire() const;
	virtual void hurt(Entity *, int);
	virtual void animateHurt();
	virtual void handleEntityEvent(char);
	virtual int getEntityData();
	virtual int getEntityData() const;
	virtual void setSize(float, float);
	virtual void outOfWorld();
	virtual void causeFallDamage(float);
	virtual void readAdditionalSaveData(CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void postInit(void);
	virtual void knockback(Entity *, int, float, float);
	virtual void die(Entity *);
	virtual bool canSee(Entity *);
	virtual void onLadder();
	virtual void spawnAnim();
	virtual void *getTexture(); // TODO return Texture
	virtual bool isSleeping();
	virtual bool isWaterMob();
	virtual void setSneaking(bool);
	virtual float getVoicePitch();
	virtual void playAmbientSound();
	virtual int getAmbientSoundInterval();
	virtual void *getItemInHandIcon(const ItemInstance *, int); // TODO return Icon
	virtual float getBaseSpeed() = 0;
	virtual void superTick();
	virtual void heal(int);
	virtual int getMaxHealth();
	virtual void actuallyHurt(int);
	virtual float getArmorValue();
	virtual void pick(float, float, bool);
	virtual void travel(float, float);
	virtual void updateWalkAnim();
	virtual void aiStep();
	virtual void lookAt(Entity *, float, float);
	virtual bool isLookingAtAnEntity();
	virtual void beforeRemove();
	virtual bool canSpawn();
	virtual void finalizeMobSpawn();
	virtual bool shouldDespawn();
	virtual float getAttackAnim(float);
	virtual bool isBaby();
	virtual bool isTamable();
	virtual Item *getCarriedItem();
	virtual int getUseItemDuration();
	virtual void swing();
	virtual void ate();
	virtual float getMaxHeadXRot();
	virtual Mob *getLastHurtByMob();
	virtual void setLastHurtByMob(Mob *);
	virtual Entity *getLastHurtMob();
	virtual void setLastHurtMob(Entity *);
	virtual Mob *getTarget();
	virtual void setTarget(Mob *);
	virtual bool isAlliedTo(Mob *);
	virtual void doHurtTarget(Entity *);
	virtual bool canBeControlledByRider();
	virtual void teleportTo(float, float, float);
	virtual Color getOverlayColor(float);
	virtual bool removeWhenFarAway();
	virtual Item *getDeathLoot();
	virtual void dropDeathLoot();
	virtual bool isImmobile();
	virtual void jumpFromGround();
	virtual void updateAi();
	virtual void newServerAiStep();
	virtual void serverAiMobStep();
	virtual float getSoundVolume();
	virtual const char *getAmbientSound();
	virtual std::string getHurtSound();
	virtual std::string getDeathSound();
	virtual float getWalkingSpeedModifier();
	virtual void getDamageAfterArmorAbsorb(int);
	virtual void hurtArmor(int);
	virtual bool useNewAi();
	void _init();
	void _ctor();
	bool checkDespawn();
	bool checkDespawn(Mob *);
	void *getMoveControl(); // TODO return
	void *getNavigation(); // TODO Navigation
	bool getSensing();
	bool getSharedFlag(int) const;
	float getSpeed();
	float getYHeadRot();
	bool interpolateOnly();
	void pushEntities();
	void setJumping(bool);
	void setSharedFlag(int, bool);
	void setSpeed(float);
	void setYHeadRot(float);
	void setYya(float);
	void updateMobId(int *);
};
