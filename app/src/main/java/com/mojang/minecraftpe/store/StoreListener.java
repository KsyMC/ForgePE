package com.mojang.minecraftpe.store;

public interface StoreListener {
    void onPurchaseCanceled(String productId);

    void onPurchaseFailed(String productId);

    void onPurchaseSuccessful(String productId);

    void onQueryProductsFail();

    void onQueryProductsSuccess(Product[] products);

    void onQueryPurchasesFail();

    void onQueryPurchasesSuccess(Purchase[] purchases);

    void onStoreInitialized(boolean available);
}
