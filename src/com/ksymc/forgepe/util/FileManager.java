package com.ksymc.forgepe.util;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;

public final class FileManager {
	private FileManager() {
		throw new AssertionError():
	}

	public static void copy(InputStream is, File outFile, boolean append) throws IOException {
		FileOutputStream fos = new FileOutputStream(outFile, append);

		byte[] tmp = new byte[1024];

		int count = 0;
		while((count = is.read(tmp)) != -1) {
			fos.write(tmp, 0, count);
		}

		is.close();
		fos.close();
	}

	public static void copy(File inFile, File outFile, boolean append) throws IOException {
		copy(new FileInputStream(inFile), outFile, append);
	}

	public static void copyDirectory(File inDir, File outDir, boolean append) throws IOException {
		File[] files = inDir.listFiles();
		for(File fileOrDir : files) {
			File outFile = new File(outDir, fileOrDir.getName());

			if(fileOrDir.isDirectory()) {
				outFile.mkdir();
				copyDirectory(fileOrDir, outFile, append);
			} else {
				copy(fileOrDir, outFile, append);
			}
		}
	}

	public static boolean deleteDirectory(File dir) {
		File[] files = dir.listFiles();
		for(File fileOrDir : files) {
			if(fileOrDir.isDirectory()) {
				if(!deleteDirectory(fileOrDir)) {
					return false;
				}
			} else if(!fileOrDir.delete()) {
				return false;
			}
		}
		return dir.delete();
	}

	public static byte[] getMD5(File file) throws IOException {
		try {
			MessageDigest md = MessageDigest.getInstance("MD5");
			FileInputStream fis = new FileInputStream(file);

			byte[] tmp = new byte[1024];

			int count = 0;
			while((count = fis.read(tmp)) != -1) {
				md.update(tmp, 0, count);
			}

			fis.close();

			return md.digest();
		} catch(NoSuchAlgorithmException e) {
			e.printStackTrace();
		}

		return null;
	}

	public static boolean checkMD5(File file, File md5File) throws IOException {
		byte[] md5 = new byte[(int) md5File.length()];

		FileInputStream fis = new FileInputStream(md5File);
		fis.read(md5);
		fis.close();

		if(Arrays.equals(getMD5(file), md5)) {
			return true;
		}
		return false;
	}
}
