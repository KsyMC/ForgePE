package com.mojang.minecraftpe.platforms;

import android.annotation.TargetApi;
import android.os.Build;
import android.os.Handler;
import android.view.View;

@TargetApi(Build.VERSION_CODES.KITKAT)
public class Platform19 extends Platform9 {
    private Runnable decorViewSettings;
    private View decoreView;
    private Handler eventHandler;

    public Platform19(boolean initEventHandler) {
        if (initEventHandler)
            this.eventHandler = new Handler();
    }

    @Override
    public void onAppStart(View view) {
        if (this.eventHandler == null)
            return;

        this.decoreView = view;
        this.decoreView.setOnSystemUiVisibilityChangeListener(new View.OnSystemUiVisibilityChangeListener() {
            @Override
            public void onSystemUiVisibilityChange(int visibility) {
                Platform19.this.eventHandler.postDelayed(Platform19.this.decorViewSettings, 500L);
            }
        });
        this.decorViewSettings = new Runnable() {
            @Override
            public void run() {
                Platform19.this.decoreView.setSystemUiVisibility(5894);
            }
        };
        this.eventHandler.post(this.decorViewSettings);
    }

    @Override
    public void onViewFocusChanged(boolean hasFocus) {
        if (this.eventHandler != null && hasFocus)
            this.eventHandler.postDelayed(this.decorViewSettings, 500L);
    }

    @Override
    public void onVolumePressed() {}
}
