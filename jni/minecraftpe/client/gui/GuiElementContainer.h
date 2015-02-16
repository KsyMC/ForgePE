#pragma once

#include "minecraftpe/client/gui/GuiElement.h"

class GuiElementContainer : public GuiElement {
public:
	// Size : 128
	char filler1[20];	// 108

public:
	GuiElementContainer(bool, bool, int, int, int, int);
	virtual ~GuiElementContainer();
	virtual void tick(MinecraftClient *);
	virtual void render(MinecraftClient *, int, int);
	virtual void topRender(MinecraftClient *, int, int);
	virtual void setupPositions();
	virtual void mouseClicked();
	virtual void mouseReleased();
	virtual void focusuedMouseClicked(MinecraftClient *, int, int, int);
	virtual void focusuedMouseReleased(MinecraftClient *, int, int, int);
	virtual void keyPressed(MinecraftClient *, int);
	virtual void keyboardNewChar(MinecraftClient *, std::string, bool);
	virtual void backPressed(MinecraftClient *, bool);
	virtual void pointInside(int, int);
	virtual void suppressOtherGUI();
	virtual void setTextboxText(const std::string &);
	virtual void drawSelected();
	virtual void drawSliderSelected();
	virtual void onSelectedChanged();
	virtual void addChild(std::shared_ptr<GuiElement>);
	virtual void removeChild(std::shared_ptr<GuiElement>);
	virtual void clearAll();
	void *getChildren(); // TODO return
};
