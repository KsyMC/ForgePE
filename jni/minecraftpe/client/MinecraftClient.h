#pragma once

#include "minecraftpe/client/Minecraft.h"
#include "minecraftpe/client/settings/Options.h"

class Level;
class Screen;
class ScreenChooser;
class Gui;
class Player;
class LocalPlayer;
class Textures;
class Font;
class TextureAtlas;
class LevelSettings;

class MinecraftClient : public Minecraft {
public:
	static TextureAtlas *_itemsTextureAtlas;
	static TextureAtlas *_terrainTextureAtlas;
	static int _hasInitedStatics;

public:
	// Size : 304
	char filler1[20];		// 156
	ScreenChooser *_chooser;// 176
	char filler2[48];		// 180
	Textures *_textures;	// 228
	Font *_font;			// 232
	char filler3[12];		// 236
	Player *_player;		// 248
	Gui *_gui;				// 252
	Options *_options;		// 256

public:
	MinecraftClient(int, char **);
	virtual ~MinecraftClient();
	virtual void onLowMemory();
	virtual void onAppSuspended();
	virtual void onAppResumed();
	virtual void onAppFocusLost();
	virtual void onAppFocusGained();
	virtual void audioEngineOn();
	virtual void audioEngineOff();
	virtual void muteAudio();
	virtual void unMuteAudio();
	virtual bool useTouchscreen();
	virtual void setTextboxText(const std::string &);
	virtual void setSize(int, int, float);
	virtual void handleBack(bool);
	virtual void handleBack();
	virtual void init();
	virtual void teardown();
	virtual void selectLevel(const std::string &, const std::string &, const LevelSettings &);
	virtual void setLevel(std::unique_ptr<Level> &, const std::string &, Player *);
	virtual void startFrame();
	virtual void updateGraphics();
	virtual void endFrame();
	virtual void tick(int, int);
	virtual void leaveGame(bool, bool);
	virtual void play(const std::string &, float, float, float, float, float);
	virtual void playUI(const std::string &, float, float);
	virtual void isServerVisible();
	virtual void sendLocalMessage(const std::string &, const std::string &);
	virtual LocalPlayer *getPlayer();
	virtual void onInternetUpdate();
	virtual void onPlayerLoaded(Player &);
	virtual void vibrate(int);
	virtual LocalPlayer *getLocalPlayer();
	void _reloadFancy(bool);
	void _reloadInput();
	Gui *getGui();
	Options *getOptions();
	float getPixelCalc();
	float getPixelCalcUI();
	void locateMultiplayer();
	void onUpdatedClient(int, int, int, int);
	void optionUpdated(const Options::Option *, bool);
	void optionUpdated(const Options::Option *, float);
	void optionUpdated(const Options::Option *, int);
	void transformResolution(int *, int *);
	void setScreen(Screen *);
	void isKindleFire(int);
	void handleBackNoReturn();
	void handleMouseClick(int);
	void handleMouseDown(int, bool);
	void updateScheduledScreen();
	void updateStats();
	void restartServer();
};
