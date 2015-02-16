#pragma once

#include "minecraftpe/client/AppPlatformListener.h"

class AppPlatform;

class App : public AppPlatformListener {
public:
	App(int, char **);
	virtual ~App();
	virtual AppPlatform *platform();
	virtual void audioEngineOn();
	virtual void audioEngineOff();
	virtual void muteAudio();
	virtual void unMuteAudio();
	virtual void destroy();
	virtual void loadState(void *, int);
	virtual void saveState(void **, int *);
	virtual bool useTouchscreen();
	virtual void setTextboxText(const std::string &);
	virtual void draw();
	virtual void update();
	virtual void setSize(int, int, float);
	virtual void quit();
	virtual void wantToQuit();
	virtual void handleBack(bool);
	virtual void handleBack();
	virtual void init();
};
