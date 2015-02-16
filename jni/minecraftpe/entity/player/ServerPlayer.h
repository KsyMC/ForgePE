#pragma once

#include "minecraftpe/inventory/IContainerListener.h"
#include "minecraftpe/entity/player/Player.h"

class Minecraft;

class ServerPlayer : public Player, public IContainerListener {
public:
	// Size : 3416
	//void **vtable;		// 3396
	Minecraft *_minecarft;	// 3400

public:
	ServerPlayer(Minecraft *, Level &);
	virtual ~ServerPlayer();
	virtual void normalTick();
	virtual void ride(Entity *);
	virtual void aiStep();
	virtual void hurtArmor(int);
	virtual void tickWorld(void */*const Tick &*/); // TODO Tick
	virtual bool hasResource(int);
	virtual void completeUsingItem();
	virtual void take(Entity *, int);
	virtual void openContainer(ChestTileEntity *);
	virtual void openFurnace(FurnaceTileEntity *);
	virtual void displayClientMessage(const std::string &);
	virtual void stopSleepInBed(bool, bool);
	virtual void closeContainer();
	virtual void setContainerData(BaseContainerMenu *, int, int);
	virtual void slotChanged(BaseContainerMenu *, int, const ItemInstance &, bool);
	virtual void refreshContainer(BaseContainerMenu *, const std::vector<ItemInstance> &);
	void disconnect();

public:
	static void initHooks(void *);
	void die_hook(Entity *);
};
