package com.ksymc.forgepe;

import java.io.File;

import android.os.Environment;

public class ModManager {
	public static final File SDCARD = Environment.getExternalStorageDirectory();
	public static final File FORGE_DIR = new File(SDCARD, "ForgePE");
	public static final String MODS_DIR = "mods";

	public static void saveConfig() {
	}

	public static native void nativeLoadMod(String modID, String name, String version);
	public static native void nativeInitialization();
}
