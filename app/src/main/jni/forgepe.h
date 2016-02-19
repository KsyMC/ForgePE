typedef struct ModInfo
{
	string modid;
	string name;
	string version;
} MODINFO;

class ForgePE
{
private:
	map<string, Mod *> _mods;

public:
	ForgePE();
	void setupHooks();
};
