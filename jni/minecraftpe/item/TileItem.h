#pragma once

#include "minecraftpe/item/Item.h"

class TileItem : public Item {
public:
	// Size : 80
	char filler1[4];	// 76

public:
	TileItem(int);
	virtual ~TileItem();
	virtual TextureUVCoordinateSet getIcon(int, int, bool) const;
	virtual float getIconYOffset() const;
	virtual bool useOn(ItemInstance *, Player *, int, int, int, signed char, float, float, float);
	virtual std::string getDescriptionId() const;
	virtual std::string getDescriptionId(const ItemInstance *) const;
	virtual bool isEmissive(int);
};
