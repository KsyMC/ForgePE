#pragma once

#include "minecraftpe/inventory/IContainerListener.h"
#include "minecraftpe/entity/player/Player.h"

class MinecraftClient;
class BaseContainerMenu;
class User;

class LocalPlayer : public Player, public IContainerListener {
public:
	// Size : 3624
	//void **vtable;			// 3396
	char filler1[44];			// 3400
	MinecraftClient *_client;	// 3444

public:
	LocalPlayer(MinecraftClient *, Level &, User *, bool);
	virtual ~LocalPlayer();
	virtual void reset();
	virtual void setPos(float, float, float);
	virtual void setPos(const Vec3 &);
	virtual void move(float, float, float);
	virtual void normalTick();
	virtual void rideTick();
	virtual void ride(Entity *);
	virtual bool isSneaking();
	virtual void causeFallDamage(float);
	virtual void readAdditionalSaveData(CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag *);
	virtual void actuallyHurt(int);
	virtual void aiStep();
	virtual void swing();
	virtual void updateAi();
	virtual void tickWorld(void */*const Tick &*/); // TODO Tick
	virtual void respawn();
	virtual void take(Entity *, int);
	virtual void drop(const ItemInstance *, bool);
	virtual void startCrafting(int, int, int, int);
	virtual void startStonecutting(int, int, int);
	virtual void openContainer(ChestTileEntity *);
	virtual void openFurnace(FurnaceTileEntity *);
	virtual void displayClientMessage(const std::string &);
	virtual void animateRespawn();
	virtual void startSleepInBed(int, int, int);
	virtual void stopSleepInBed(bool, bool);
	virtual void openTextEdit(TileEntity *);
	virtual bool isLocalPlayer();
	virtual void closeContainer();
	virtual void onViewDistanceChanged(int);
	virtual void refreshContainer(BaseContainerMenu *, const std::vector<ItemInstance> &);
	virtual void slotChanged(BaseContainerMenu *, int, const ItemInstance &, bool);
	void _init();
	void calculateFlight(float, float, float);
	void releaseAllKeys();
	void sendPosition();

public:
	typedef void (*SendPositionReal)(LocalPlayer *);

	static SendPositionReal sendPosition_real;

	static void initHooks(void *);
	void sendPosition_hook();
};
