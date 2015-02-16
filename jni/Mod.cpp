#include "Mod.h"
#include "log.h"

const char *Mod::getModID() {
	return "forgepe";
}

const char *Mod::getName() {
	return "ForgePE";
}

const char *Mod::getVersion() {
	return "1.0.0";
}

void Mod::load() {
	LOGE("Unusual Mod: %s", getName());
}
