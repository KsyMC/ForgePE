#pragma once

class ItemInstance;
class BaseContainerMenu;

class IContainerListener {
public:
	virtual ~IContainerListener();
	virtual void refreshContainer(BaseContainerMenu *, const std::vector<ItemInstance> &);
	virtual void slotChanged(BaseContainerMenu *, int, const ItemInstance &, bool);
	virtual void setContainerData(BaseContainerMenu *, int, int);
};
