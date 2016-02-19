package com.mojang.minecraftpe.store.amazonappstore;

import android.content.Context;

import com.mojang.minecraftpe.store.Store;
import com.mojang.minecraftpe.store.StoreListener;

public class AmazonAppStore implements Store {

    public AmazonAppStore(Context context, StoreListener listener) {

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
