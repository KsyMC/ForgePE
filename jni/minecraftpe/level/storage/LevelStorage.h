#pragma once

class LevelData;
class ChunkSource;
class Player;

class LevelStorage {
	virtual ~LevelStorage();
	virtual void loadLevelData(LevelData &) = 0;
	virtual void createChunkStorage(ChunkSource *, StorageVersion) = 0;
	virtual void saveLevelData(LevelData &) = 0;
	virtual void getFullPath()const = 0;
	virtual void saveData(const std::string &, const std::string &);
	virtual void loadData(const std::string &);
	virtual void getState() const = 0;
	virtual void loadPlayerData(const std::string &);
	virtual void save(Player &);
};
