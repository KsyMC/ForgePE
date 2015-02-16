#pragma once

#include <string>

class ImageData;
class LoginInformation;

class AppPlatform {
public:
	virtual ~AppPlatform();
	virtual void getImagePath(const std::string &, bool) = 0;
	virtual void loadPNG(ImageData &, const std::string &) = 0;
	virtual void loadTGA(ImageData &, const std::string &);
	virtual void playSound(const std::string &, float, float);
	virtual void showDialog(int);
	virtual void createUserInput();
	virtual void getUserInputStatus();
	virtual void getUserInput();
	virtual void getDateString(int);
	virtual void checkLicense();
	virtual void hasBuyButtonWhenInvalidLicense();
	virtual void saveImage(const std::string &, const std::string &, int, int);
	virtual void uploadPlatformDependentData(int, void *);
	virtual void readAssetFile(const std::string &);
	virtual void _tick();
	virtual void getScreenWidth();
	virtual void getScreenHeight();
	virtual void getPixelsPerMillimeter();
	virtual void isNetworkEnabled(bool);
	virtual void openLoginWindow();
	virtual void isPowerVR();
	virtual void getKeyFromKeyCode(int, int, int);
	virtual void buyGame();
	virtual void finish();
	virtual void swapBuffers() = 0;
	virtual void supportsTouchscreen();
	virtual void hasIDEProfiler();
	virtual void supportsVibration();
	virtual void vibrate(int);
	virtual void getPlatformStringVar(int);
	virtual void showKeyboard(const std::string &, int, bool);
	virtual void hideKeyboard();
	virtual void updateTextBoxText(const std::string &);
	virtual void isKeyboardVisible();
	virtual void getLoginInformation();
	virtual void setLoginInformation(const LoginInformation &);
	virtual void clearSessionIDAndRefreshToken();
	virtual void statsTrackData(const std::string &, const std::string &);
	virtual void captureScreen(int, int, bool);
	virtual void getAvailableMemory();
	virtual void getBroadcastAddresses();
	virtual void getModelName();
};
