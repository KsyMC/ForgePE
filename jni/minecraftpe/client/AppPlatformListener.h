#pragma once

class AppPlatformListener {
public:
	//void **vtable;	// 0

public:
	AppPlatformListener(bool);
	AppPlatformListener();
	virtual ~AppPlatformListener();
	virtual void onLowMemory();
	virtual void onAppSuspended();
	virtual void onAppResumed();
	virtual void onAppFocusLost();
	virtual void onAppFocusGained();
	virtual void onAppTerminated();
};
