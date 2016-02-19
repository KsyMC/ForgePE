package com.mojang.minecraftpe.store;

public interface Store {
    void destructor();

    String getStoreId();

    void purchase(String productId);

    void queryProducts(String[] productIds);

    void queryPurchases();
}
