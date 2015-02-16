#pragma once

#include "minecraftpe/util/Color.h"
#include "minecraftpe/client/gui/GuiComponent.h"

class MinecraftClient;
class IntRectangle;

class GuiElement : public GuiComponent {
public:
	// Size : 108
	bool _isActive;		// 64
	bool _isVisible;	// 65
	char filler1[2];	// 66
	int _x;				// 68
	int _y;				// 72
	int _width;			// 76
	int _height;		// 80
	Color _color;		// 84
	void *_ninepatch;	// 100
	bool _isSelected;	// 104

public:
	GuiElement(bool, bool, int, int, int, int);
	virtual ~GuiElement();
	virtual void tick(MinecraftClient *);
	virtual void render(MinecraftClient *, int, int);
	virtual void topRender(MinecraftClient *, int, int);
	virtual void setupPositions();
	virtual void mouseClicked(MinecraftClient *, int, int, int);
	virtual void mouseReleased(MinecraftClient *, int, int, int);
	virtual void focusuedMouseClicked(MinecraftClient *, int, int, int);
	virtual void focusuedMouseReleased(MinecraftClient *, int, int, int);
	virtual void keyPressed(MinecraftClient *, int);
	virtual void keyboardNewChar(MinecraftClient *, std::string, bool);
	virtual bool backPressed(MinecraftClient *, bool);
	virtual void pointInside(int, int);
	virtual bool suppressOtherGUI();
	virtual void setTextboxText(const std::string &);
	virtual void drawSelected();
	virtual void drawSliderSelected();
	virtual void onSelectedChanged();
	void clearBackground();
	bool isSelected();
	void setBackground(const Color &);
	void setBackground(MinecraftClient *, const std::string &, const IntRectangle &, int, int);
	void setVisible(bool);
	void setSelected(bool);
	void setActiveAndVisibility(bool, bool);
	void setActiveAndVisibility(bool);
};
