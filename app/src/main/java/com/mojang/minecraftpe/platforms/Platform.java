package com.mojang.minecraftpe.platforms;

import android.os.Build;
import android.view.View;

public abstract class Platform {
	public static Platform createPlatform(boolean initEventHandler) {
		if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.KITKAT)
			return new Platform21(initEventHandler);
		if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP)
			return new Platform19(initEventHandler);
		return new Platform9();
	}

	public abstract String getABIS();
	public abstract void onAppStart(View view);
	public abstract void onViewFocusChanged(boolean hasFocus);
	public abstract void onVolumePressed();
}
