#pragma once

class ItemInstance;

class Container {
public:
	//void **vtable;	// 0

public:
	virtual ~Container();
	virtual ItemInstance *getItem(int) = 0;
	virtual void setItem(int, ItemInstance *) = 0;
	virtual void removeItem(int, int) = 0;
	virtual std::string getName() = 0;
	virtual int getContainerSize() = 0;
	virtual int getMaxStackSize() = 0;
	virtual bool stillValid(Player *) = 0;
	virtual void startOpen() = 0;
	virtual void stopOpen() = 0;
	virtual int getSlotCopies();
};
