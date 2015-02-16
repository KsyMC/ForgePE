#pragma once

#include "minecraftpe/inventory/FillingContainer.h"

class Player;

class Inventory : public FillingContainer {
public:
	// Size : 48

public:
	Inventory(Player *, bool);
	virtual ~Inventory();
	virtual int getContainerSize();
	virtual bool stillValid(Player *);
	virtual void add(ItemInstance *);
	virtual void doDrop(ItemInstance *, bool);
};
