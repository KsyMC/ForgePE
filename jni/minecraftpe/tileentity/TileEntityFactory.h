#pragma once

class TileEntity;
class TilePos;

class TileEntityFactory {
public:
	static TileEntity *createTileEntity(TileEntityType, const TilePos &);
};
