#pragma once

#include "minecraftpe/gamemode/GameMode.h"

class CreativeMode : public GameMode {
public:
	CreativeMode(Minecraft *);
	virtual ~CreativeMode();
	virtual void startDestroyBlock(Player *, int, int, int, signed char);
	virtual void countinueDestoryBlock(Player *, int, int, int, signed char);
	virtual bool isCreativeType();
	virtual void initAbilities(Abilities &);
	virtual void releaseUsingItem(Player *);
};
