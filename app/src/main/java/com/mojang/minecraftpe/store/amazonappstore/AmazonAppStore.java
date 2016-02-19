package com.mojang.minecraftpe.store.amazonappstore;

import android.content.Context;

import com.mojang.minecraftpe.store.Store;
import com.mojang.minecraftpe.store.StoreListener;

public class AmazonAppStore implements Store {
    private StoreListener mListener;

    public AmazonAppStore(Context context, StoreListener listener) {
        this.mListener = listener;
        this.mListener.onStoreInitialized(true);
    }

    @Override
    public void destructor() {
    }

    @Override
    public String getStoreId() {
        return "android.amazonappstore";
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
