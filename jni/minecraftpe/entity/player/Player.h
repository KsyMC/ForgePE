#pragma once

#include "minecraftpe/entity/Mob.h"
#include "minecraftpe/raknet/RakNetTypes.h"

class Tile;
class TileEntity;
class LevelChunk;
class Inventory;
class ChestTileEntity;
class FurnaceTileEntity;
class ItemEntity;
class ChunkSource;
class TilePos;

class Player : public Mob {
public:
	static float DEFAULT_WALK_SPEED;
	static float DEFAULT_FLY_SPEED;

public:
	// Size : 3396
	char filler1[2832];				// 332
	std::string _playerName;		// 3164
	char filler2[16];				// 3168
	RakNet::RakNetGUID _playerGUID;	// 3184
	char filler3[4];				// 3200
	int _clientId;					// 3204
	char filler4[4];				// 3208
	Inventory *_inventory;			// 3212
	char filler5[180];				// 3216

public:
	Player(Level &, bool);
	virtual ~Player();
	virtual void reset();
	virtual void remove();
	virtual void normalTick();
	virtual void rideTick();
	virtual float getRidingHeight();
	virtual void ride(Entity *);
	virtual bool isInWall();
	virtual float getHeadHeight();
	virtual bool isPushable();
	virtual bool isShootable();
	virtual bool isCreativeModeAllowed();
	virtual void hurt(Entity *, int);
	virtual void handleEntityEvent(char);
	virtual void awardKillScore(Entity *, int);
	virtual int getEntityTypeId() const;
	virtual void readAdditionalSaveData(CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void die(Entity *);
	virtual bool isSleeping();
	virtual float getBaseSpeed();
	virtual int getMaxHealth();
	virtual float getArmorValue();
	virtual void travel(float, float);
	virtual void aiStep();
	virtual Item *getCarriedItem();
	virtual int getUseItemDuration();
	virtual bool isImmobile();
	virtual void updateAi();
	virtual float getWalkingSpeedModifier();
	virtual void hurtArmor(int);
	virtual bool useNewAi();
	virtual void tickWorld(void */*const Tick &*/); // TODO Tick
	virtual void moveView();
	virtual void respawn();
	virtual bool hasResource(int);
	virtual void completeUsingItem();
	virtual void take(Entity *, int);
	virtual void drop(const ItemInstance *);
	virtual void drop(const ItemInstance *, bool);
	virtual void startCrafting(int, int, int, int);
	virtual void startStonecutting(int, int, int);
	virtual void startDestroying();
	virtual void stopDestroying();
	virtual void openContainer(ChestTileEntity *);
	virtual void openFurnace(FurnaceTileEntity *);
	virtual void displayClientMessage(const std::string &);
	virtual void animateRespawn();
	virtual void startSleepInBed(int, int, int);
	virtual void stopSleepInBed(bool, bool);
	virtual void *getSleepTimer(); // TODO return Timer
	virtual void openTextEdit(TileEntity *);
	virtual bool isLocalPlayer();
	virtual void closeContainer();
	virtual void onViewDistanceChanged(int);
	void _init();
	void _findNearBlockToStandOn(const Vec3 &);
	void _fixSpawnPosition(const Vec3 &);
	void _getTopStandingPosition(const TilePos &);
	void animateRespawn(Player *, Level *);
	int getScore();
	bool checkBed();
	bool canUseCarriedItemWhileMoving();
	bool canDestroy(Tile *);
	void updateTeleportDestPos();
	void touch(Entity *);
	void interact(Entity *);
	void tileEntityDestroyed(int);
	float getDestroySpeed(Tile *);
	ItemInstance *getSelectedItem();
	Item *getTicksUsingItem();
	Item *getUseItem();
	void startUsingItem(ItemInstance, int);
	void stopUsingItem();
	void releaseUsingItem();
	bool isUsingItem();
	bool isHurt();
	bool isSleepingLongEnough();
	std::string getArmorTypeHash();
	void spawnEatParticles(const ItemInstance *, int);
	void setRespawnPosition(const TilePos &);
	void settTeleportDestPos(const Vec3 &);
	void setDefaultHeadHeight();
	void setBedOffset(int);
	void setArmor(int, const ItemInstance *);
	void setAllPlayersSleeping();
	float getSleepRotation();
	void resetPos(bool);
	void reallyDrop(ItemEntity *);
	void prepareRegion(ChunkSource &);
	void onChunkRemoved(LevelChunk &);
	float getViewRadius() const;
	void *hasRespawnPosition() const; // TODO return Position
	void *getStandingPositionOnBlock(const TilePos &); // TODO return Position
	void *getSpawnPosition(); // TODO return Position
	void *findStandUpPosition(Entity *); // TODO return Position
};
