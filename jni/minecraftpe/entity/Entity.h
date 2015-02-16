#pragma once

class Level;
class TileSource;
class Material;
class Player;
class Entity;
class CompoundTag;
class ItemInstance;
class Random;
class Vec3;
class TilePos;
class EntityPos;

class Entity {
public:
	static std::string RIDING_TAG;
	static uint entityCounter;
	static Random *sharedRandom;

public:
	// Size : NONE
	char filler1[28];			// 4
	float _x;					// 32
	float _y;					// 36
	float _z;					// 40
	char filler2[8];			// 44
	uint _eid;					// 52
	char filler3[4];			// 56
	TileSource *_tileSource;	// 60
	char filler4[4];			// 64
	Level *_level;				// 68
	char filler5[213];			// 72
	bool _b1;					// 285

public:
	Entity(Level &);
	Entity(TileSource &);
	virtual ~Entity();
	virtual void reset();
	virtual void remove();
	virtual void setPos(float, float, float);
	virtual void setPos(const Vec3 &);
	virtual void move(float, float, float);
	virtual void moveTo(float, float, float, float, float);
	virtual void moveRelative(float, float, float);
	virtual void lerpTo(float, float, float, float, float, int);
	virtual void lerpMotion(float, float, float);
	virtual void turn(float, float);
	virtual void interpolateTurn(float, float);
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual void positionRider(bool);
	virtual float getRidingHeight();
	virtual float getRideHeight();
	virtual void ride(Entity *);
	virtual void intersects(float, float, float, float, float, float, float);
	virtual bool isFree(float, float, float, float);
	virtual bool isFree(float, float, float);
	virtual bool isInWall();
	virtual bool isInWater();
	virtual bool isInWaterOrRain();
	virtual bool isInLava();
	virtual bool isUnderLiquid(const Material *) const;
	virtual float getShadowRadius();
	virtual void makeStuckInWeb();
	virtual float getHeadHeight();
	virtual float getShadowHeightOffs();
	virtual bool isSkyLit(float);
	virtual int getBrightness(float);
	virtual void interactPreventDefault();
	virtual void interactWithPlayer(Player *);
	virtual bool canInteractWith(Player *);
	virtual std::string getInteractText(Player *);
	virtual void playerTouch(Player *);
	virtual void push(Entity *);
	virtual void push(float, float, float);
	virtual bool isPickable();
	virtual bool isPushable();
	virtual bool isShootable();
	virtual bool isSneaking();
	virtual bool isAlive();
	virtual bool isOnFire() const;
	virtual bool isCreativeModeAllowed();
	virtual bool isSurfaceMob();
	virtual void shouldRenderAtSqrDistance(float);
	virtual void hurt(Entity *, int);
	virtual void animateHurt();
	virtual void handleEntityEvent(char);
	virtual void getPickRadius();
	virtual void spawnAtLocation(int, int);
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(const ItemInstance &, float);
	virtual void awardKillScore(Entity *, int);
	virtual void setEquippedSlot(int, int, int);
	virtual void save(CompoundTag &);
	virtual void saveWithoutId(CompoundTag &);
	virtual void load(CompoundTag &);
	virtual int getEntityData();
	virtual int getEntityData() const;
	virtual int getEntityTypeId() const;
	virtual void queryEntityRenderer();
	virtual bool isItemEntity();
	virtual bool isHangingEntity();
	virtual int getAuxData();
	virtual void getHandleWaterAABB();
	virtual void setRot(float, float);
	virtual void setSize(float, float);
	virtual void setPos(EntityPos *);
	virtual void outOfWorld();
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float);
	virtual void markHurt();
	virtual void burn(int);
	virtual void lavaHurt();
	virtual void readAdditionalSaveData(CompoundTag *) = 0;
	virtual void addAdditionalSaveData(CompoundTag *) = 0;
	virtual void playStepSound(int, int, int, int);
	virtual void checkInsideTiles();
	virtual void playSound(const std::string, float);
	virtual void onSynchedDataUpdate(int);
	void _init();
	void _updateOwnerChunk();
	float distanceTo(Entity *);
	float distanceTo(float, float, float);
	float distanceToSqr(Entity *);
	float distanceToSqr(float, float, float);
	float distanceSqrToBlockPosCenter(const TilePos &);
	void saveAsMount(CompoundTag &);
	bool isMob() const;
	bool operator==(Entity &);
};
