#pragma once

class Mod {
public:
	virtual ~Mod() {};
	virtual const char *getModID();
	virtual const char *getName();
	virtual const char *getVersion();
	virtual void load();
};
