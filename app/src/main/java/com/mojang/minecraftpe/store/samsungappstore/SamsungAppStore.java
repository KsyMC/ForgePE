package com.mojang.minecraftpe.store.samsungappstore;

import android.content.Intent;

import com.mojang.minecraftpe.ActivityListener;
import com.mojang.minecraftpe.MainActivity;
import com.mojang.minecraftpe.store.Store;
import com.mojang.minecraftpe.store.StoreListener;

public class SamsungAppStore implements Store, ActivityListener {
    MainActivity mActivity;
    StoreListener mListener;

    public SamsungAppStore(MainActivity activity, StoreListener listener) {
        this.mListener = listener;
        this.mActivity = activity;
        this.mActivity.addListener(this);
        this.mListener.onStoreInitialized(true);
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
    }

    @Override
    public void onDestroy() {
    }

    @Override
    public void destructor() {
        this.mActivity.removeListener(this);
        onDestroy();
    }

    @Override
    public String getStoreId() {
        return "android.samsungappstore";
    }

    @Override
    public void purchase(String productId) {
        this.mListener.onPurchaseFailed(productId);
    }

    @Override
    public void queryProducts(String[] productIds) {
        this.mListener.onQueryProductsFail();
    }

    @Override
    public void queryPurchases() {
        this.mListener.onQueryPurchasesFail();
    }
}
