#pragma once

#include "minecraftpe/client/gui/GuiElement.h"

class Button : public GuiElement {
public:
	// Size : 120
	std::string _text;			// 108
	int _buttonId;				// 112
	bool _toggle;				// 116
	bool _isPressed;			// 117
	bool _isOverrideRendering;	// 118

	Button(int, int, int, int, int, const std::string &);
	Button(int, int, int, const std::string &);
	Button(int, const std::string &, bool);
	virtual ~Button();
	virtual void render(MinecraftClient *, int, int);
	virtual void mouseReleased(MinecraftClient *, int, int, int);
	virtual bool clicked(MinecraftClient *, int, int);
	virtual void released(int, int);
	virtual void setPressed();
	virtual void getYImage(bool);
	virtual void renderBg(MinecraftClient *, int, int);
	virtual void renderFace(MinecraftClient *, int, int);
	void setMsg(const std::string &);
	void setOverrideScreenRendering(bool);
	void isOveridingScreenRendering(void);
	bool isInside(int, int);
	bool hovered(MinecraftClient *, int, int);
};
