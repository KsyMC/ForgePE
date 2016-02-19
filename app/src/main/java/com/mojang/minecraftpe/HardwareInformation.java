package com.mojang.minecraftpe;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileFilter;
import java.io.FileReader;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import android.os.Build;

import com.mojang.minecraftpe.platforms.Platform;

public class HardwareInformation {
    private static final CPUInfo cpuInfo = getCPUInfo();

    public static String getAndroidVersion() {
        return "Android " + Build.VERSION.RELEASE;
    }

    public static String getDeviceModelName() {
        String manufacturer = Build.MANUFACTURER;
        String model = Build.MODEL;
        if(model.startsWith(manufacturer)) {
            return model.toUpperCase();
        }

        return manufacturer.toUpperCase() + " " + model;
    }

    public static String getLocale() {
        return Locale.getDefault().toString();
    }

    public static String getCPU() {
        return Build.CPU_ABI;
    }

    public static CPUInfo getCPUInfo() {
        StringBuffer sb = new StringBuffer();
        Map<String, String> list = new HashMap<>();
        int processorCount = 0;

        if (new File("/proc/cpuinfo").exists()) {
            try {
                BufferedReader br = new BufferedReader(new FileReader(new File("/proc/cpuinfo")));
                String regexp = "(\\\\w*)\\\\s*:\\\\s([^\\\\n]*)";
                Pattern pattern = Pattern.compile(regexp);

                while (true) {
                    String line = br.readLine();
                    Matcher matcher = pattern.matcher(line);
                    if (matcher.find() || matcher.groupCount() == 2)
                        break;

                    if (!list.containsKey(matcher.group()))
                        list.put(matcher.group(1), matcher.group(2));

                    if (matcher.group(1).contentEquals("processor"))
                        processorCount++;
                }
                br.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return new CPUInfo(list, processorCount);
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

    public static String getCPUName() {
        return cpuInfo.getCPULine("Hardware");
    }

    public static String getCPUFeatures() {
        return cpuInfo.getCPULine("Features");
    }

    public static String getCPUType() {
        return Platform.createPlatform(false).getABIS();
    }

    public static class CPUInfo {
        private final Map<String, String> cpuLines;
        private final int numberCPUCores;

        public CPUInfo(Map<String, String> cpuLines, int numberCPUCores) {
            this.cpuLines = cpuLines;
            this.numberCPUCores = numberCPUCores;
        }

        String getCPULine(String line) {
            if (this.cpuLines.containsKey(line))
                return this.cpuLines.get(line);
            return "";
        }

        int getNumberCPUCores() {
            return this.numberCPUCores;
        }
    }
}
