#pragma once

#include <string>

#include "minecraftpe/AppPlatformListener.h"
#include "minecraftpe/client/gui/GuiComponent.h"

class MinecraftClient;
class ItemInstance;

class Gui : public GuiComponent, AppPlatformListener {
public:
	// Size : 2848
	static float DropTicks;
	static float GuiScale;
	static float InvGuiScale;

public:
	//void **vtable;					// 64
	char filler1[2548];					// 68
	MinecraftClient *_minecraftClient;	// 2616
	char filler2[228];					// 2620

public:
	Gui(MinecraftClient &);
	void addMessage(const std::string &, const std::string &, int);
	void clearMessages();
	void cubeSmoothStep(float, float, float);
	void displayClientMessage(const std::string &);
	void floorAlignToScreenPixel(float);
	void flashSlot(int slot);
	void setNowPlaying(const std::string &);
	void showPopupNotice(const std::string &);
	void showTipMessage(const std::string &);
	void handleKeyPressed(int);
	void handleClick(int, int, int);
	int getNumSlots();
	void getRectangleArea(int);
	int getSlotIdAt(int, int);
	int getSlotPos(int, int &, int &);
	int itemCountItoa(char *, int);
	void inventoryUpdated();
	void onLevelGenerated();
	bool isInside(int, int);
	void postError(int);
	void processLeftShoulder(int);
	void processRightShoulder(int);
	void render(float, bool, int, int);
	void renderToolBar(float, float);
	void renderProgressIndicator(bool, int, int, float);
	void renderSleepAnimation(int, int);
	void renderSlot(int, int, int, float);
	void renderSlotText(const ItemInstance *, float, float, bool, bool, bool);
	void renderHearts();
	void renderBubbles();
	void renderVignette(float, int, int);
	void renderChatMessages(int, int, unsigned int, bool, Font *);
	void renderOnSelectItemNameText(int, Font *, int);
	void tick();
	void tickItemDrop();
};
