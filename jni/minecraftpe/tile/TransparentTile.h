#pragma once

#include "Tile.h"

class TransparentTile : public Tile {
public:
	// Size : 144
	bool b1;	// 140

public:
	TransparentTile(int id, const Material *material) : Tile(id, material), b1(true) {};
	TransparentTile(int id, TextureUVCoordinateSet set, const Material *material) : Tile(id, set, material), b1(true) {};
	TransparentTile(int id, std::string str, const Material *material) : Tile(id, str, material), b1(true) {};
	virtual ~TransparentTile();
	virtual void shouldRenderFace(TileSource *, int, int, int, signed char, const AABB &) const;
};
