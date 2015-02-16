#pragma once

#include "minecraftpe/tileentity/TileEntity.h"
#include "minecraftpe/inventory/FillingContainer.h"

class ChestTileEntity : public TileEntity, public FillingContainer {
public:
	ChestTileEntity();
	virtual ~ChestTileEntity();
};
