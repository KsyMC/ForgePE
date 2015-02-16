#pragma once

#include "minecraftpe/tileentity/TileEntity.h"
#include "minecraftpe/inventory/FillingContainer.h"

class SignTileEntity : public TileEntity, public FillingContainer {
public:
	SignTileEntity();
	virtual ~SignTileEntity();
};
