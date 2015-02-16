#pragma once

class ChunkPos;
class Vec3;

class TilePos {
public:
	int _x;		// 0
	int _y;		// 4
	int _z;		// 8

public:
	TilePos(const ChunkPos &, int);
	TilePos(const Vec3 &);
	TilePos(float, float, float);
};
