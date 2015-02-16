#pragma once

#include "minecraftpe/tileentity/TileEntity.h"
#include "minecraftpe/inventory/FillingContainer.h"

class MobSpawnerTileEntity : public TileEntity, public FillingContainer {
public:
	MobSpawnerTileEntity();
	virtual ~MobSpawnerTileEntity();
};
