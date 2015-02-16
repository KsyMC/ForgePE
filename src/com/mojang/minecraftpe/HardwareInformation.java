package com.mojang.minecraftpe;

import java.io.File;
import java.io.FileFilter;

import android.os.Build;

public class HardwareInformation {
	public static String getAndroidVersion() {
		return Build.VERSION.RELEASE;
	}
	
	public static String getCPU() {
		return Build.CPU_ABI;
	}
	
	public static String getDeviceModelName() {
		String manufacturer = Build.MANUFACTURER;
		String model = Build.MODEL;
		if(model.startsWith(manufacturer)) {
			return model.toUpperCase();
		}
		
		return manufacturer.toUpperCase() + " " + model;
	}
	
	public static int getNumCores() {
		class CpuFilter implements FileFilter {

			@Override
			public boolean accept(File pathname) {
				if(pathname.getName().matches("cpu[0-9]+")) {
					return true;
				}
				
				return false;
			}
			
		}
		
		try {
			File dir = new File("/sys/devices/system/cpu/");
			File[] files = dir.listFiles(new CpuFilter());
			
			return files.length;
		} catch(Exception e) {
			return 1;
		}
	}
}
