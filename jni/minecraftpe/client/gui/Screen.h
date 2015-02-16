#pragma once

#include "minecraftpe/client/gui/GuiComponent.h"

class MinecraftClient;
class Button;
class TextBox;
class GuiElement;
class Font;
namespace Controller {
class StickDirection;
}
class IntRectangle;
class MojangConnectionStatus;
class MCOEvent;

class Screen : public GuiComponent {
public:
	// Size : 200
	int _width;							// 64
	int _height;						// 68
	char filler1[4];					// 72
	MinecraftClient *_minecraftClient;	// 76
	std::vector<Button *> _vecBtn;		// 80
	std::vector<TextBox *> _vecTextB;	// 92
	std::vector<Button *> _vecBtn2;		// 104
	std::vector<GuiElement *> _vecGuiE;	// 116
	std::vector<GuiElement *> _vecGui2E;// 128
	char filler5[12];					// 140
	Font *_font;						// 152
	char filler6[32];					// 156
	MaterialPtr _ui_cubemap;			// 188

public:
	Screen();
	virtual ~Screen();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual void updateEvents();
	virtual void mouseEvent();
	virtual void keyboardEvent();
	virtual void keyboardTextEvent();
	virtual void controllerEvent();
	virtual bool handleBackEvent(bool);
	virtual void tick();
	virtual void removed();
	virtual void renderBackground(int);
	virtual void renderDirtBackground();
	virtual void renderMenuBackground(float);
	virtual bool renderGameBehind();
	virtual void hasClippingArea(IntRectangle &);
	virtual bool isPauseScreen();
	virtual bool isErrorScreen();
	virtual bool isInGameScreen();
	virtual void closeOnPlayerHurt();
	virtual void confirmResult(bool, int);
	virtual void lostFocus();
	virtual void toGUICoordinate(int &, int &);
	virtual void feedMCOEvent(MCOEvent);
	virtual bool supppressedBySubWindow();
	virtual void onTextBoxUpdated(int);
	virtual void onMojangConnectorStatus(MojangConnectionStatus);
	virtual void setTextboxText(const std::string &);
	virtual void onInternetUpdate();
	virtual void updateTabButtonSelection();
	virtual void buttonClicked(Button *);
	virtual void guiElementClicked(GuiElement *);
	virtual void mouseClicked(int, int, int);
	virtual void mouseReleased(int, int, int);
	virtual void controllerDirectionChanged(int, Controller::StickDirection);
	virtual void controllerDirectionHeld(int, Controller::StickDirection);
	virtual void keyPressed(int);
	virtual void keyboardNewChar(const std::string &, bool);
	virtual void shouldSendAllKeyStates();
	void init(MinecraftClient &, int, int);
	void getCursorMoveThrottle();
	void getPassGuiEvents();
	void processControllerDirection(int);
	void setPassGuiEvents(bool);
	void setSize(int, int);
	void tabNext();
	void tabPrev();
};
