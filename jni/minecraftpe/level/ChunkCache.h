#pragma once

#include "minecraftpe/AppPlatformListener.h"
#include "minecraftpe/level/ChunkSource.h"

class ChunkCache : public ChunkSource, public AppPlatformListener {
public:
	ChunkCache(ChunkSource *);
};
