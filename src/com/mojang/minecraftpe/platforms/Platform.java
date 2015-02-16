package com.mojang.minecraftpe.platforms;

import android.os.Build;
import android.view.View;

public abstract class Platform {
	public static Platform createPlatform() {
		if(Build.VERSION.SDK_INT < Build.VERSION_CODES.KITKAT) {
			return new Platform44();
		}
		
		return new Platform23();
	}
	
	public abstract void onAppStart(View view);
	public abstract void onViewFocusChanged(boolean hasFocus);
	public abstract void onVolumePressed();
}
