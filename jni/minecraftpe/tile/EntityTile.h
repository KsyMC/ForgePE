#pragma once

#include "minecraftpe/tile/Tile.h"

class TileEntity;

class EntityTile : public Tile {
public:
	// Size : 140


public:
	EntityTile(int, const Material *);
	EntityTile(int, const std::string &, const Material *);
	virtual ~EntityTile();
	virtual void neighborChanged(TileSource *, int, int, int, int, int, int);
	virtual void triggerEvent(TileSource *, int, int, int, int, int);
	virtual TileEntity *newTileEntity(const TilePos &);
};
