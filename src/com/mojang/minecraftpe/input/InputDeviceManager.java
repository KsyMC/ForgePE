package com.mojang.minecraftpe.input;

import android.content.Context;
import android.os.Build;
import android.util.Log;

public abstract class InputDeviceManager {
	public static InputDeviceManager create(Context ctx) {
		if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.JELLY_BEAN) {
			return new JellyBeanDeviceManager(ctx);
		}
		
		return new DefaultDeviceManager();
	}
	
	public abstract void register();
	public abstract void unregister();
	
	public static class DefaultDeviceManager extends InputDeviceManager {

		@Override
		public void register() {
			Log.w("MCPE", "INPUT Noop register device manager");
		}
		
		@Override
		public void unregister() {
			Log.w("MCPE", "INPUT Noop unregister device manager");
		}
	}
}
