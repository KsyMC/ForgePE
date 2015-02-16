#pragma once

class Abilities {
public:
	bool invulnerable;	// 0;
	bool flying;		// 1;
	bool mayfly;		// 2;
	bool instabuild;	// 3;

public:
	void addSaveData(void *);
	void loadSaveData(void *);
};
