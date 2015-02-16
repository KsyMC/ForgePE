#pragma once

class Level;
class ChunkPos;

class LevelChunk {
public:
	LevelChunk(Level &, const ChunkPos &, bool);
};
