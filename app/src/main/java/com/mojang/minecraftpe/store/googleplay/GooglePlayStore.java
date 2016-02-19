package com.mojang.minecraftpe.store.googleplay;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

import com.mojang.minecraftpe.ActivityListener;
import com.mojang.minecraftpe.MainActivity;
import com.mojang.minecraftpe.store.Store;
import com.mojang.minecraftpe.store.StoreListener;

public class GooglePlayStore extends BroadcastReceiver implements Store, ActivityListener {

    public GooglePlayStore(MainActivity activity, String licenseKey, StoreListener listener) {

    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {

    }

    @Override
    public void onDestroy() {

    }

    @Override
    public void onReceive(Context context, Intent intent) {

    }

    @Override
    public void destructor() {

    }

    @Override
    public String getStoreId() {
        return null;
    }

    @Override
    public void purchase(String productId) {

    }

    @Override
    public void queryProducts(String[] productIds) {

    }

    @Override
    public void queryPurchases() {

    }
}
