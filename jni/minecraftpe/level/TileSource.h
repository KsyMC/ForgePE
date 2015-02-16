#pragma once

class Level;
class ChunkSource;
class Player;
class TilePos;
class FullTile;
class LightLayer;
class TileID;
class Tile;
class TileEntity;

class TileSource {
public:
	TileSource(Level &, ChunkSource *, bool, bool);
	TileSource(Player &);
	virtual ~TileSource();
	Level *getLevel() const;
	inline TileID getTile(int, int, int);
	inline TileID getTile(const TilePos &);
	inline FullTile getTileAndData(int, int, int);
	inline FullTile getTileAndData(const TilePos &);
	Tile *getTilePtr(int, int, int);
	TileEntity *getTileEntity(int, int, int);
	TileEntity *getTileEntity(const TilePos &);
	bool setTile(int, int, int, TileID, int);
	bool setTileAndData(int, int, int, FullTile, int);
	int getBrightness(const LightLayer &, const TilePos &);
	int getBrightness(const LightLayer &, int, int, int);
	int getBrightness(const TilePos &);
	int getBrightness(int, int, int);
	bool canSeeSky(int, int, int);
	bool canSeeSky(const TilePos &);
};
