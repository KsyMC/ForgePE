package com.mojang.minecraftpe.store.googleplay;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

import com.mojang.minecraftpe.ActivityListener;
import com.mojang.minecraftpe.MainActivity;
import com.mojang.minecraftpe.store.Store;
import com.mojang.minecraftpe.store.StoreListener;

public class GooglePlayStore extends BroadcastReceiver implements Store, ActivityListener {
    static final String IAB_BROADCAST_ACTION = "com.android.vending.billing.PURCHASES_UPDATED";

    MainActivity mActivity;
    StoreListener mListener;
    int mPurchaseRequestCode;

    public GooglePlayStore(MainActivity activity, String licenseKey, StoreListener listener) {
        this.mListener = listener;
        this.mActivity = activity;
        this.mActivity.addListener(this);
        this.mPurchaseRequestCode = MainActivity.RESULT_GOOGLEPLAY_PURCHASE;
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {

    }

    @Override
    public void onDestroy() {
        //this.mActivity.unregisterReceiver(this);
    }

    @Override
    public void onReceive(Context context, Intent intent) {
        Log.i("GooglePlayStore", "IabBroadcastReceiver received message PURCHASES_UPDATED");
        queryPurchases();
    }

    @Override
    public void destructor() {
        this.mActivity.removeListener(this);
        onDestroy();
    }

    @Override
    public String getStoreId() {
        return "android.googleplay";
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
