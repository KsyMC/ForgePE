#pragma once

#include "minecraftpe/tileentity/TileEntity.h"
#include "minecraftpe/inventory/FillingContainer.h"

class FurnaceTileEntity : public TileEntity, public FillingContainer {
public:
	FurnaceTileEntity();
	virtual ~FurnaceTileEntity();
};
