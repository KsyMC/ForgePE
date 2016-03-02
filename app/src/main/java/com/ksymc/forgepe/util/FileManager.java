package com.ksymc.forgepe.util;

import java.io.DataInputStream;
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
        throw new AssertionError();
    }

    public static void copy(InputStream is, File outFile, boolean append) throws IOException {
        DataInputStream dis = new DataInputStream(is);

        byte allower = dis.readByte();
        byte[] tmp = new byte[dis.available() + 1];

        tmp[0] = allower;
        dis.readFully(tmp, 1, dis.available());

        //dis.close();

        FileOutputStream fos = new FileOutputStream(outFile, append);

        fos.write(tmp);

        fos.close();
    }

    public static void copy(File inFile, File outFile, boolean append) throws IOException {
        FileInputStream fis = new FileInputStream(inFile);
        copy(fis, outFile, append);
        fis.close();
    }

    public static void copyDirectory(File inDir, File outDir, boolean append) throws IOException {
        File[] files = inDir.listFiles();
        for (File fileOrDir : files) {
            File outFile = new File(outDir, fileOrDir.getName());

            if (fileOrDir.isDirectory()) {
                outFile.mkdir();
                copyDirectory(fileOrDir, outFile, append);
            } else
                copy(fileOrDir, outFile, append);
        }
    }

    public static boolean deleteDirectory(File dir) {
        File[] files = dir.listFiles();
        for (File fileOrDir : files) {
            if (fileOrDir.isDirectory()) {
                if (!deleteDirectory(fileOrDir))
                    return false;
            } else if (!fileOrDir.delete())
                return false;
        }
        return dir.delete();
    }

    public static byte[] getMD5(File file) throws IOException {
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            FileInputStream fis = new FileInputStream(file);

            byte[] tmp = new byte[1024];

            int count;
            while ((count = fis.read(tmp)) != -1)
                md.update(tmp, 0, count);
            fis.close();

            return md.digest();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        return null;
    }

    public static boolean checkMD5(File file, File md5File) throws IOException {
        byte[] md5 = new byte[(int) md5File.length()];

        FileInputStream fis = new FileInputStream(md5File);
        fis.read(md5);
        fis.close();

        return Arrays.equals(getMD5(file), md5);
    }
}