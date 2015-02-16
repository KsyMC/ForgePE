package com.mojang.minecraftpe.platforms;

import android.annotation.TargetApi;
import android.os.Build;
import android.os.Handler;
import android.view.View;

@TargetApi(Build.VERSION_CODES.KITKAT)
public class Platform44 extends Platform {

	private Runnable decorViewSettings;
	private View decoreView;
	private Handler eventHandler = new Handler();
	
	@Override
	public void onAppStart(View view) {
		this.decoreView = view;
		this.decoreView.setOnSystemUiVisibilityChangeListener(new View.OnSystemUiVisibilityChangeListener() {
			
			@Override
			public void onSystemUiVisibilityChange(int visibility) {
				eventHandler.postDelayed(decorViewSettings, 500);
			}
		});
		this.decorViewSettings = new Runnable() {
			
			@Override
			public void run() {
				decoreView.setSystemUiVisibility(5894);
			}
		};
		this.eventHandler.post(this.decorViewSettings);
	}
	
	@Override
	public void onViewFocusChanged(boolean hasFocus) {
		eventHandler.postDelayed(decorViewSettings, 500);
	}
	
	@Override
	public void onVolumePressed() {
		
	}
}
