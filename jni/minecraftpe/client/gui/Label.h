#pragma once

#include "GuiElement.h"

class MinecraftClient;
class Color;

class Label : public GuiElement {
public:
	// Size : 144
	char filler1[36];	// 108

	Label(std::string, MinecraftClient *, const Color &, int, int, int, bool);
	virtual ~Label();
	virtual void render(MinecraftClient *, int, int);
	virtual void setupPositions();
	virtual std::string getText() const;
	virtual void setText(std::string);
	virtual void setWidth(int);
	virtual void setColor(const Color &);
	void setCentered(bool);
};
