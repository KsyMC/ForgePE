#pragma once

#include "minecraftpe/tileentity/TileEntityTypeEnum.h"

class CompoundTag;
class TileSource;
class Packet;
class TilePos;

class TileEntity {
public:
	TileEntity(TileEntityType, const TilePos &, const std::string &);
	virtual ~TileEntity();
	virtual void load(CompoundTag *);
	virtual void save(CompoundTag *);
	virtual void tick(TileSource *);
	virtual bool isFinished();
	virtual Packet *getUpdatePacket();
	virtual void onUpdatePacket(CompoundTag *);
	virtual void setRemoved();
	virtual void triggerEvent(int, int);
	virtual void clearCache();
	virtual void onNeighborChanged(TileSource &, int, int, int);
	virtual float getShadowRadius(TileSource &) const;
	void _destructionWobble(float &, float &, float &);
	void _resetAABB();
	bool isRemoved() const;
	bool isType(TileEntityType);
	static bool isType(TileEntity *, TileEntityType);
};
