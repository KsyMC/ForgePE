package com.mojang.minecraftpe.platforms;

import android.annotation.TargetApi;
import android.os.Build;
import android.os.Handler;
import android.view.View;

@TargetApi(Build.VERSION_CODES.LOLLIPOP)
public class Platform21 extends Platform19 {

	public Platform21(boolean initEventHandler) {
		super(initEventHandler);
	}

	public String getABIS() {
		return Build.SUPPORTED_ABIS.toString();
	}
}
