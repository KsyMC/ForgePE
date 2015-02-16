#pragma once

class TileSource;
class TileEntity;
class TilePos;
class FullTile;

class TileSourceListener {
public:
	virtual ~TileSourceListener();
	virtual void onSourceCreated(TileSource *);
	virtual void onSourceDestroyed(TileSource *);
	virtual void onTilesDirty(TileSource *, int, int, int, int, int, int);
	virtual void onAreaChanged(TileSource &, const TilePos &, const TilePos &);
	virtual void onTileChanged(TileSource *, const TilePos &, FullTile, FullTile, int);
	virtual void onBrightnessChanged(TileSource &, TilePos const&);
	virtual void onTileEntityChanged(TileSource &, TileEntity &);
	virtual void onTileEntityRemoved(TileSource &, std::unique_ptr<TileEntity> &);
	virtual void onTileEvent(TileSource *, int, int, int, int, int);
};
