package com.ksymc.forgepe;

import java.util.List;

import android.content.ComponentName;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.ActivityInfo;
import android.content.pm.ApplicationInfo;
import android.content.pm.FeatureInfo;
import android.content.pm.InstrumentationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.PermissionGroupInfo;
import android.content.pm.PermissionInfo;
import android.content.pm.ProviderInfo;
import android.content.pm.ResolveInfo;
import android.content.pm.ServiceInfo;
import android.content.res.Resources;
import android.content.res.XmlResourceParser;
import android.graphics.drawable.Drawable;

public class CustomPackageManager extends PackageManager {

	private PackageManager packageManager;
	private String customLibDir;
	
	public CustomPackageManager(PackageManager packageManager, String customLibDir) {
		this.packageManager = packageManager;
		this.customLibDir = customLibDir;
	}
	
	@Override
	public void addPackageToPreferred(String packageName) {
		packageManager.addPackageToPreferred(packageName);
	}

	@Override
	public boolean addPermission(PermissionInfo info) {
		return packageManager.addPermission(info);
	}

	@Override
	public boolean addPermissionAsync(PermissionInfo info) {
		return packageManager.addPermissionAsync(info);
	}

	@Override
	public void addPreferredActivity(IntentFilter filter, int match, ComponentName[] set, ComponentName activity) {
		packageManager.addPreferredActivity(filter, match, set, activity);
	}

	@Override
	public String[] canonicalToCurrentPackageNames(String[] names) {
		return packageManager.canonicalToCurrentPackageNames(names);
	}

	@Override
	public int checkPermission(String permName, String pkgName) {
		return packageManager.checkSignatures(permName, pkgName);
	}

	@Override
	public int checkSignatures(String pkg1, String pkg2) {
		return packageManager.checkSignatures(pkg1, pkg2);
	}

	@Override
	public int checkSignatures(int uid1, int uid2) {
		return packageManager.checkSignatures(uid1, uid2);
	}

	@Override
	public void clearPackagePreferredActivities(String packageName) {
		packageManager.clearPackagePreferredActivities(packageName);
	}

	@Override
	public String[] currentToCanonicalPackageNames(String[] names) {
		return packageManager.currentToCanonicalPackageNames(names);
	}

	@Override
	public void extendVerificationTimeout(int id, int verificationCodeAtTimeout, long millisecondsToDelay) {
		packageManager.extendVerificationTimeout(id, verificationCodeAtTimeout, millisecondsToDelay);
	}

	@Override
	public Drawable getActivityIcon(ComponentName activityName) throws NameNotFoundException {
		return packageManager.getActivityIcon(activityName);
	}

	@Override
	public Drawable getActivityIcon(Intent intent) throws NameNotFoundException {
		return packageManager.getActivityIcon(intent);
	}

	@Override
	public ActivityInfo getActivityInfo(ComponentName component, int flags) throws NameNotFoundException {
		ActivityInfo info = packageManager.getActivityInfo(component, flags);
		info.applicationInfo.nativeLibraryDir = customLibDir;
		
		return info;
	}

	@Override
	public Drawable getActivityLogo(ComponentName activityName) throws NameNotFoundException {
		return packageManager.getActivityLogo(activityName);
	}

	@Override
	public Drawable getActivityLogo(Intent intent) throws NameNotFoundException {
		return packageManager.getActivityLogo(intent);
	}

	@Override
	public List<PermissionGroupInfo> getAllPermissionGroups(int flags) {
		return packageManager.getAllPermissionGroups(flags);
	}

	@Override
	public int getApplicationEnabledSetting(String packageName) {
		return packageManager.getApplicationEnabledSetting(packageName);
	}

	@Override
	public Drawable getApplicationIcon(ApplicationInfo info) {
		return packageManager.getApplicationIcon(info);
	}

	@Override
	public Drawable getApplicationIcon(String packageName) throws NameNotFoundException {
		return packageManager.getApplicationIcon(packageName);
	}

	@Override
	public ApplicationInfo getApplicationInfo(String packageName, int flags) throws NameNotFoundException {
		return packageManager.getApplicationInfo(packageName, flags);
	}

	@Override
	public CharSequence getApplicationLabel(ApplicationInfo info) {
		return packageManager.getApplicationLabel(info);
	}

	@Override
	public Drawable getApplicationLogo(ApplicationInfo info) {
		return packageManager.getApplicationLogo(info);
	}

	@Override
	public Drawable getApplicationLogo(String packageName) throws NameNotFoundException {
		return packageManager.getApplicationLogo(packageName);
	}

	@Override
	public int getComponentEnabledSetting(ComponentName componentName) {
		return packageManager.getComponentEnabledSetting(componentName);
	}

	@Override
	public Drawable getDefaultActivityIcon() {
		return packageManager.getDefaultActivityIcon();
	}

	@Override
	public Drawable getDrawable(String packageName, int resid, ApplicationInfo appInfo) {
		return packageManager.getDrawable(packageName, resid, appInfo);
	}

	@Override
	public List<ApplicationInfo> getInstalledApplications(int flags) {
		return packageManager.getInstalledApplications(flags);
	}

	@Override
	public List<PackageInfo> getInstalledPackages(int flags) {
		return packageManager.getInstalledPackages(flags);
	}

	@Override
	public String getInstallerPackageName(String packageName) {
		return packageManager.getInstallerPackageName(packageName);
	}

	@Override
	public InstrumentationInfo getInstrumentationInfo(ComponentName className, int flags) throws NameNotFoundException {
		return packageManager.getInstrumentationInfo(className, flags);
	}

	@Override
	public Intent getLaunchIntentForPackage(String packageName) {
		return packageManager.getLaunchIntentForPackage(packageName);
	}

	@Override
	public String getNameForUid(int uid) {
		return packageManager.getNameForUid(uid);
	}

	@Override
	public int[] getPackageGids(String packageName) throws NameNotFoundException {
		return packageManager.getPackageGids(packageName);
	}

	@Override
	public PackageInfo getPackageInfo(String packageName, int flags) throws NameNotFoundException {
		return packageManager.getPackageInfo(packageName, flags);
	}

	@Override
	public String[] getPackagesForUid(int uid) {
		return packageManager.getPackagesForUid(uid);
	}

	@Override
	public List<PackageInfo> getPackagesHoldingPermissions(String[] permissions, int flags) {
		return packageManager.getPackagesHoldingPermissions(permissions, flags);
	}

	@Override
	public PermissionGroupInfo getPermissionGroupInfo(String name, int flags) throws NameNotFoundException {
		return packageManager.getPermissionGroupInfo(name, flags);
	}

	@Override
	public PermissionInfo getPermissionInfo(String name, int flags) throws NameNotFoundException {
		return packageManager.getPermissionInfo(name, flags);
	}

	@Override
	public int getPreferredActivities(List<IntentFilter> arg0, List<ComponentName> arg1, String arg2) {
		return packageManager.getPreferredActivities(arg0, arg1, arg2);
	}

	@Override
	public List<PackageInfo> getPreferredPackages(int flags) {
		return packageManager.getPreferredPackages(flags);
	}

	@Override
	public ProviderInfo getProviderInfo(ComponentName component, int flags) throws NameNotFoundException {
		return packageManager.getProviderInfo(component, flags);
	}

	@Override
	public ActivityInfo getReceiverInfo(ComponentName component, int flags) throws NameNotFoundException {
		return packageManager.getReceiverInfo(component, flags);
	}

	@Override
	public Resources getResourcesForActivity(ComponentName activityName) throws NameNotFoundException {
		return packageManager.getResourcesForActivity(activityName);
	}

	@Override
	public Resources getResourcesForApplication(ApplicationInfo app) throws NameNotFoundException {
		return packageManager.getResourcesForApplication(app);
	}

	@Override
	public Resources getResourcesForApplication(String appPackageName) throws NameNotFoundException {
		return packageManager.getResourcesForApplication(appPackageName);
	}

	@Override
	public ServiceInfo getServiceInfo(ComponentName component, int flags) throws NameNotFoundException {
		return packageManager.getServiceInfo(component, flags);
	}

	@Override
	public FeatureInfo[] getSystemAvailableFeatures() {
		return packageManager.getSystemAvailableFeatures();
	}

	@Override
	public String[] getSystemSharedLibraryNames() {
		return packageManager.getSystemSharedLibraryNames();
	}

	@Override
	public CharSequence getText(String packageName, int resid, ApplicationInfo appInfo) {
		return packageManager.getText(packageName, resid, appInfo);
	}

	@Override
	public XmlResourceParser getXml(String packageName, int resid, ApplicationInfo appInfo) {
		return packageManager.getXml(packageName, resid, appInfo);
	}

	@Override
	public boolean hasSystemFeature(String name) {
		return packageManager.hasSystemFeature(name);
	}

	@Override
	public boolean isSafeMode() {
		return packageManager.isSafeMode();
	}

	@Override
	public List<ResolveInfo> queryBroadcastReceivers(Intent intent, int flags) {
		return packageManager.queryBroadcastReceivers(intent, flags);
	}

	@Override
	public List<ProviderInfo> queryContentProviders(String processName, int uid, int flags) {
		return packageManager.queryContentProviders(processName, uid, flags);
	}

	@Override
	public List<InstrumentationInfo> queryInstrumentation(String targetPackage, int flags) {
		return packageManager.queryInstrumentation(targetPackage, flags);
	}

	@Override
	public List<ResolveInfo> queryIntentActivities(Intent intent, int flags) {
		return packageManager.queryIntentActivities(intent, flags);
	}

	@Override
	public List<ResolveInfo> queryIntentActivityOptions(ComponentName caller, Intent[] specifics, Intent intent, int flags) {
		return packageManager.queryIntentActivityOptions(caller, specifics, intent, flags);
	}

	@Override
	public List<ResolveInfo> queryIntentContentProviders(Intent intent, int flags) {
		return packageManager.queryIntentContentProviders(intent, flags);
	}

	@Override
	public List<ResolveInfo> queryIntentServices(Intent intent, int flags) {
		return packageManager.queryIntentServices(intent, flags);
	}

	@Override
	public List<PermissionInfo> queryPermissionsByGroup(String group, int flags) throws NameNotFoundException {
		return packageManager.queryPermissionsByGroup(group, flags);
	}

	@Override
	public void removePackageFromPreferred(String packageName) {
		packageManager.removePackageFromPreferred(packageName);
	}

	@Override
	public void removePermission(String name) {
		packageManager.removePermission(name);
	}

	@Override
	public ResolveInfo resolveActivity(Intent intent, int flags) {
		return packageManager.resolveActivity(intent, flags);
	}

	@Override
	public ProviderInfo resolveContentProvider(String name, int flags) {
		return packageManager.resolveContentProvider(name, flags);
	}

	@Override
	public ResolveInfo resolveService(Intent intent, int flags) {
		return packageManager.resolveService(intent, flags);
	}

	@Override
	public void setApplicationEnabledSetting(String packageName, int newState, int flags) {
		packageManager.setApplicationEnabledSetting(packageName, newState, flags);
	}

	@Override
	public void setComponentEnabledSetting(ComponentName componentName, int newState, int flags) {
		packageManager.setComponentEnabledSetting(componentName, newState, flags);
	}

	@Override
	public void setInstallerPackageName(String targetPackage, String installerPackageName) {
		packageManager.setInstallerPackageName(targetPackage, installerPackageName);
	}

	@Override
	public void verifyPendingInstall(int id, int verificationCode) {
		packageManager.verifyPendingInstall(id, verificationCode);
	}

}
