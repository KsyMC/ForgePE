package com.mojang.minecraftpe.store;

public class NativeStoreListener implements StoreListener {
    long mStoreListener;

    public NativeStoreListener(long storeListener) {
        this.mStoreListener = storeListener;
    }

    @Override
    public void onPurchaseCanceled(String productId) {
        onPurchaseCanceled(this.mStoreListener, productId);
    }

    @Override
    public void onPurchaseFailed(String productId) {
        onPurchaseFailed(this.mStoreListener, productId);
    }

    @Override
    public void onPurchaseSuccessful(String productId) {
        onPurchaseSuccessful(this.mStoreListener, productId);
    }

    @Override
    public void onQueryProductsFail() {
        onQueryProductsFail(this.mStoreListener);
    }

    @Override
    public void onQueryProductsSuccess(Product[] products) {
        onQueryProductsSuccess(this.mStoreListener, products);
    }

    @Override
    public void onQueryPurchasesFail() {
        onQueryPurchasesFail(this.mStoreListener);
    }

    @Override
    public void onQueryPurchasesSuccess(Purchase[] purchases) {
        onQueryPurchasesSuccess(this.mStoreListener, purchases);
    }

    @Override
    public void onStoreInitialized(boolean available) {
        onStoreInitialized(this.mStoreListener, available);
    }

    public native void onPurchaseCanceled(long storeListener, String productId);
    public native void onPurchaseFailed(long storeListener, String productId);
    public native void onPurchaseSuccessful(long storeListener, String productId);
    public native void onQueryProductsFail(long storeListener);
    public native void onQueryProductsSuccess(long storeListener, Product[] products);
    public native void onQueryPurchasesFail(long storeListener);
    public native void onQueryPurchasesSuccess(long storeListener, Purchase[] purchases);
    public native void onStoreInitialized(long storeListener, boolean available);
}
