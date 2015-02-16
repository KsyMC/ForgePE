#pragma once

class Level;
class Mob;
class TileSource;
class Vec3;

class MobFactory {
public:
	MobFactory(Level &);
	static std::string GetMobNameID(int);
	static Mob *CreateMob(int, TileSource &, const Vec3 &, Vec3*);
};
