package com.mojang.minecraftpe;

import android.content.Intent;

public interface ActivityListener {
    void onActivityResult(int requestCode, int resultCode, Intent data);

    void onDestroy();
}