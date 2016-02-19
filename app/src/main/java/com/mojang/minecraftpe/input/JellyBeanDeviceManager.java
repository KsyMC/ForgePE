package com.mojang.minecraftpe.input;

import android.annotation.TargetApi;
import android.content.Context;
import android.hardware.input.InputManager;
import android.os.Build;

@TargetApi(Build.VERSION_CODES.KITKAT)
public class JellyBeanDeviceManager extends InputDeviceManager implements InputManager.InputDeviceListener {

	private final InputManager inputManager;
	
	JellyBeanDeviceManager(Context ctx) {
		this.inputManager = (InputManager) ctx.getSystemService(Context.INPUT_SERVICE);
	}
	
	@Override
	public void onInputDeviceAdded(int deviceId) {
		onInputDeviceAddedNative(deviceId);
	}
	
	@Override
	public void onInputDeviceChanged(int deviceId) {
		onInputDeviceChangedNative(deviceId);
	}
	
	@Override
	public void onInputDeviceRemoved(int deviceId) {
		onInputDeviceRemovedNative(deviceId);
	}
	
	native void onInputDeviceAddedNative(int deviceId);
	native void onInputDeviceChangedNative(int deviceId);
	native void onInputDeviceRemovedNative(int deviceId);

	@Override
	public void register() {
		this.inputManager.getInputDeviceIds();
		this.inputManager.registerInputDeviceListener(this, null);
	}
	
	@Override
	public void unregister() {
		this.inputManager.unregisterInputDeviceListener(this);
	}
}
