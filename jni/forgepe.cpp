#include <jni.h>
#include <dlfcn.h>
#include <string>
#include <map>

#include "log.h"
#include "header.h"
#include "substrate.h"

#include "minecraftpe/client/MinecraftClient.h"

using std::string;
using std::map;

#include "Mod.h"
#include "forgepe.h"

ForgePE _forgePE;

ForgePE::ForgePE() {
	// TODD
}

void ForgePE::setupHooks() {
	void *handle = dlopen("libminecraftpe.so", RTLD_LAZY);

	//MSHookFunction((void *) &MinecraftClient::init, (void *) &MinecraftClient::initHooks, (void **) &MinecraftClient::init_real);
}

JNIEXPORT void JNICALL Java_com_ksymc_forgepe_ModManager_nativeLoadMod
  (JNIEnv *env, jclass modManager, jstring jmodid, jstring jname, jstring jversion) {
	const char *modid = env->GetStringUTFChars(jmodid, NULL);
	const char *name = env->GetStringUTFChars(jname, NULL);
	const char *version = env->GetStringUTFChars(jversion, NULL);

	LOGI("%s %s %s", modid, name, version);

	env->ReleaseStringUTFChars(jmodid, modid);
	env->ReleaseStringUTFChars(jname, name);
	env->ReleaseStringUTFChars(jversion, version);
}

JNIEXPORT void JNICALL Java_com_ksymc_forgepe_ModManager_nativeInitialization
  (JNIEnv *env, jclass modManager) {
	// TODO
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
	_forgePE = ForgePE();

	return JNI_VERSION_1_2;
}
