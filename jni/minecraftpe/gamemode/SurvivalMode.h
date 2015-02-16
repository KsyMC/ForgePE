#pragma once

#include "minecraftpe/gamemode/GameMode.h"

class SurvivalMode : public GameMode {
public:
	SurvivalMode(Minecraft *);
	virtual ~SurvivalMode();
	virtual void startDestroyBlock(Player *, int, int, int, signed char);
	virtual void destroyBlock(Player *, int, int, int, signed char);
	virtual void continueDestroyBlock(Player *, int, int, int, signed char);
	virtual void stopDestroyBlock(Player *);
	virtual bool canHurtPlayer();
	virtual bool isSurvivalType();
	virtual void initAbilities(Abilities &);

public:
	typedef void (*StartDestroyBlockReal)(SurvivalMode *, Player *, int, int, int, signed char);
	typedef void (*DestroyBlockReal)(SurvivalMode *, Player *, int, int, int, signed char);
	typedef void (*ContinueDestroyBlockReal)(SurvivalMode *, Player *, int, int, int, signed char);
	typedef void (*StopDestroyBlockReal)(SurvivalMode *, Player *);

	static StartDestroyBlockReal startDestroyBlock_real;
	static DestroyBlockReal destroyBlock_real;
	static ContinueDestroyBlockReal continueDestroyBlock_real;
	static StopDestroyBlockReal stopDestroyBlock_real;

	static void initHooks(void *);
	void startDestroyBlock_hook(Player *, int, int, int, signed char);
	void destroyBlock_hook(Player *, int, int, int, signed char);
	void continueDestroyBlock_hook(Player *, int, int, int, signed char);
	void stopDestroyBlock_hook(Player *);
	void useItem_hook(Player &, ItemInstance &);
	void useItemOn_hook(Player &, ItemInstance *, const TilePos &, signed char, const Vec3 &);
	void interact_hook(Player *, Entity *);
	void attack_hook(Player *, Entity *);
};
