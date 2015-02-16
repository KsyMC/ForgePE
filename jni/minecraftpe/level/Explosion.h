#pragma once

class TileSource;
class Entity;

class Explosion {
public:
	Explosion(TileSource &, Entity *, float, float, float, float);
	void explode();
	void finalizeExplosion();
};
