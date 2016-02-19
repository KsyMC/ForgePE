package com.mojang.minecraftpe.store.samsungappstore;

import android.content.Intent;

import com.mojang.minecraftpe.ActivityListener;
import com.mojang.minecraftpe.MainActivity;
import com.mojang.minecraftpe.store.Store;
import com.mojang.minecraftpe.store.StoreListener;

public class SamsungAppStore implements Store, ActivityListener {

    public SamsungAppStore(MainActivity activity, StoreListener listener) {

    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {

    }

    @Override
    public void onDestroy() {

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
