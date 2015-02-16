#pragma once

#include "minecraftpe/AppPlatformListener.h"
#include "minecraftpe/level/LevelListener.h"

class MinecraftClient;
class TextureAtlas;

class LevelRenderer : public LevelListener, public AppPlatformListener {
public:
	LevelRenderer(MinecraftClient *, std::shared_ptr<TextureAtlas>);
};
