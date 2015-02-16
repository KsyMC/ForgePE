#pragma once

class Minecraft;
class Player;
class Entity;
class ItemInstance;
class Abilities;
class TilePos;
class Vec3;

class GameMode {
public:
	// Size ; 24
	//void **vtable;		// 0
	Minecraft *_minecraft;	// 4

public:
	GameMode(Minecraft *);
	virtual ~GameMode();
	virtual void startDestroyBlock(Player *, int, int, int, signed char);
	virtual void destroyBlock(Player *, int, int, int, signed char);
	virtual void continueDestroyBlock(Player *, int, int, int, signed char) = 0;
	virtual void stopDestroyBlock(Player *, int, int, int, signed char);
	virtual void tick();
	virtual float getPickRange();
	virtual void useItem(Player &, ItemInstance &);
	virtual void useItemOn(Player &, ItemInstance *, const TilePos &, signed char, const Vec3 &);
	virtual void initPlayer(Player *);
	virtual void adjustPlayer(Player &);
	virtual bool canHurtPlayer();
	virtual void interact(Player *, Entity *);
	virtual void attack(Player *, Entity *);
	virtual void handleInventoryMouseClick(int, int, int, Player *);
	virtual void handleCloseInventory(int, Player *);
	virtual bool isCreativeType();
	virtual bool isSurvivalType();
	virtual void initAbilities(Abilities &);
	virtual void releaseUsingItem(Player *);
};
