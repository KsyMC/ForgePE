package com.ksymc.forgepe;

import android.content.pm.PackageManager;
import android.os.Bundle;

public class LauncherActivity extends com.mojang.minecraftpe.MainActivity {

	private String customLibraryDir = "";
	private boolean fakePackage = false;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		Bundle data = getIntent().getExtras();
		customLibraryDir = data.getString("custom_library_dir");

		System.load(customLibraryDir + "/" + System.mapLibraryName("minecraftpe"));
		
		fakePackage = true;
		super.onCreate(savedInstanceState);
		fakePackage = false;
		
		ModManager.nativeInitialization();
	}

	@Override
	public PackageManager getPackageManager() {
		PackageManager packageManager = super.getPackageManager();
		
		if(fakePackage)
			return new CustomPackageManager(packageManager, customLibraryDir);
		return packageManager;
	}
}
