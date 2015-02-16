#pragma once

#include "Container.h"

class FillingContainer : public Container {
public:
	FillingContainer(int, int, int, bool);
	virtual ~FillingContainer();
	virtual ItemInstance *getItem(int);
	virtual void setItem(int, ItemInstance *);
	virtual void removeItem(int, int);
	virtual std::string getName();
	virtual int getContainerSize() = 0;
	virtual int getMaxStackSize();
	virtual bool stillValid(Player *);
	virtual void startOpen();
	virtual void stopOpen();
	virtual void add(ItemInstance *);
	virtual void doDrop(ItemInstance *, bool);
	void setContainerChanged();
	void dropAll(bool);
};
