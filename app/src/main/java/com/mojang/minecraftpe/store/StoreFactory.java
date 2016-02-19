package com.mojang.minecraftpe.store;

import com.mojang.minecraftpe.MainActivity;
import com.mojang.minecraftpe.store.amazonappstore.AmazonAppStore;
import com.mojang.minecraftpe.store.googleplay.GooglePlayStore;
import com.mojang.minecraftpe.store.samsungappstore.SamsungAppStore;

public class StoreFactory {
    static Store createAmazonAppStore(StoreListener storeListener) {
        return new AmazonAppStore(MainActivity.mInstance, storeListener);
    }

    static Store createGooglePlayStore(String googlePlayLicenseKey, StoreListener storeListener) {
        return new GooglePlayStore(MainActivity.mInstance, googlePlayLicenseKey, storeListener);
    }

    static Store createSamsungAppStore(StoreListener storeListener) {
        return new SamsungAppStore(MainActivity.mInstance, storeListener);
    }
}
