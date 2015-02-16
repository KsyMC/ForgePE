package com.ksymc.forgepe;

import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FilenameFilter;
import java.io.IOException;
import java.lang.ref.WeakReference;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import net.lingala.zip4j.core.ZipFile;
import net.lingala.zip4j.exception.ZipException;
import net.lingala.zip4j.progress.ProgressMonitor;

import com.ksymc.forgepe.util.FileManager;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager.NameNotFoundException;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.KeyEvent;
import android.widget.ProgressBar;
import android.widget.TextView;

public class MainActivity extends Activity {
	public String customLibraryDir;
	public TextView loadingText;
	public ProgressBar loadingBar;

	private final FileHandler fileHandler = new FileHandler(this);

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.splashscreen);

		try {
			customLibraryDir = getPackageManager().getPackageInfo("com.mojang.minecraftpe", 0).applicationInfo.nativeLibraryDir;
		} catch (NameNotFoundException e) {
			e.printStackTrace();
			startActivity(new Intent(this, MCPENotFoundActivity.class));
			finish();
			
			return;
		}
		
		loadingText = (TextView) findViewById(R.id.textview_loading);
		loadingBar = (ProgressBar) findViewById(R.id.progressbar_loading);
		
		new Thread(new Runnable() {
			
			@Override
			public void run() {
				loadFiles();
			}
		}).start();
	}

	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		return keyCode == KeyEvent.KEYCODE_BACK ? true : super.onKeyDown(keyCode, event);
	}

	private void loadFiles() {
		File forgeModsDir = new File(ModManager.FORGE_DIR, ModManager.MODS_DIR);
		File[] zipFiles = forgeModsDir.listFiles(new FilenameFilter() {
			
			@Override
			public boolean accept(File dir, String filename) {
				return filename.toLowerCase().endsWith(".zip");
			}
		});
		fileHandler.sendMessage(fileHandler.obtainMessage(1, 0, zipFiles.length));
		
		for(int i = 0; i < zipFiles.length; i++) {
			fileHandler.sendMessage(fileHandler.obtainMessage(1, 1, i));
			loadMod(zipFiles[i]);
		}
		fileHandler.sendMessage(fileHandler.obtainMessage(0, "환영합니다!"));
		fileHandler.sendMessageDelayed(fileHandler.obtainMessage(2), 2000);
	}

	private void loadMod(File zipFile) {
		File tempDir = new File(ModManager.FORGE_DIR, "temp");
		File tempModDir = new File(tempDir, zipFile.getName().replace(".zip", ""));
		if(!tempModDir.exists()) {
			tempModDir.mkdirs();
		}
		
		try {
			ZipFile modZip = new ZipFile(zipFile.getAbsolutePath());
			modZip.setRunInThread(true);
			modZip.extractAll(tempModDir.getAbsolutePath());
			
			ProgressMonitor monitor = modZip.getProgressMonitor();
			while(monitor.getState() == ProgressMonitor.STATE_BUSY) {
				String fileName = monitor.getFileName();
				if(fileName != null) {
					String text = String.format(getResources().getString(R.string.initialize_mod), zipFile.getName(), fileName);
					fileHandler.sendMessage(fileHandler.obtainMessage(0, text));
				}
			}
		} catch (ZipException e) {
			e.printStackTrace();
			FileManager.deleteDirectory(tempModDir);
			
			return;
		}
		
		try {
			String modID = null;
			String name = null;
			String version = null;
			
			JSONArray infoArray = (JSONArray) new JSONParser().parse(new FileReader(new File(tempModDir, "mcpemod.info")));
			for(int i = 0; i < infoArray.size(); i++) {
				JSONObject info = (JSONObject) infoArray.get(i);
				modID = (String) info.get("modid");
				name = (String) info.get("name");
				version = (String) info.get("version");
			}
			
			if(modID == null || name == null || version == null) {
				FileManager.deleteDirectory(tempModDir);
				
				return;
			}
			
			File modsDir = getDir(ModManager.MODS_DIR, Context.MODE_PRIVATE);
			File modDir = new File(modsDir, modID);
			if(modDir.exists()) {
				File modMD5File = new File(modDir, "MD5");
				if(FileManager.checkMD5(zipFile, modMD5File)) {
					FileManager.deleteDirectory(tempModDir);
					
					return;
				} else {
					FileManager.deleteDirectory(modDir);
				}
			} else {
				modDir.mkdir();
			}
			
			FileManager.copyDirectory(tempModDir, modDir, false);
			FileManager.deleteDirectory(tempModDir);
			
			byte[] md5 = FileManager.getMD5(zipFile);
			
			FileOutputStream fos = new FileOutputStream(new File(modDir, "MD5"));
			fos.write(md5);
			fos.close();
			
	 		System.load(modDir.getAbsolutePath() + "/libs/lib" + modID + ".so");
			ModManager.nativeLoadMod(modID, name, version);
		} catch(ParseException | IOException e) {
			e.printStackTrace();
			FileManager.deleteDirectory(tempModDir);
		}
	}

	private static class FileHandler extends Handler {
		private WeakReference<MainActivity> activity;

		public FileHandler(MainActivity activity) {
			this.activity = new WeakReference<MainActivity>(activity);
		}

		@Override
		public void handleMessage(Message msg) {
			MainActivity activity = this.activity.get();
			
			if(activity != null) {
				switch(msg.what) {
				case 0:
					activity.loadingText.setText((String) msg.obj); 
					break;
				case 1:
					switch(msg.arg1) {
					case 0:
						activity.loadingBar.setMax(msg.arg2);
						break;
					case 1:
						activity.loadingBar.setProgress(msg.arg2);
						break;
					}
					break;
				case 2:
					Intent intent = new Intent(activity, LauncherActivity.class);
					intent.putExtra("custom_library_dir", activity.customLibraryDir);
					
					activity.startActivity(intent);
					activity.finish();
					break;
				}
			}
		}
	}

	static {
		System.loadLibrary("gnustl_shared");
		System.loadLibrary("substrate");
		System.loadLibrary("forgepe");
	}
}
