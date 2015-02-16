#pragma once

#include "minecraftpe/tile/Tile.h"

class Color;

class HeavyTile : public Tile {
public:
	HeavyTile(int, const std::string &, const Material *);
	virtual ~HeavyTile();
	virtual void getTickDelay();
	virtual void tick(TileSource *, int, int, int, Random *);
	virtual void animateTick(TileSource *, int, int, int, Random *);
	virtual void neighborChanged(TileSource *, int, int, int, int, int, int);
	virtual void onPlace(TileSource *, int, int, int);
	virtual Color *getDustColor() = 0;
	void _checkSlide(TileSource *, int, int, int);
	void _findBottomSlidingTile(TileSource &, const TilePos &);
	void _isFree(TileSource *, const TilePos &);
	void _scheduleCheck(TileSource &, const TilePos &, Tile *, int);
	void _scheduleCheckIfSliding(TileSource &, const TilePos &, Tile *);
	void _startFalling(TileSource &, const TilePos &, Tile *);
	void _tickTilesAround2D(TileSource &, const TilePos &, Tile *);
};
