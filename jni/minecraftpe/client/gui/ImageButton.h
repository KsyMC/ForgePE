#pragma once

#include "minecraftpe/client/gui/Button.h"
#include "minecraftpe/client/gui/IntRectangle.h"

class ImageDef;

class ImageButton : public Button {
public:
	// Size : 196
	std::string _textureName;	// 120
	char filler1[20];			// 124
	IntRectangle _intRectangle;	// 140
	Color _color;				// 160
	char filler2[4];			// 176
	int _offsetY;				// 180
	char filler3[12];			// 184

public:
	ImageButton(int, const std::string &);
	ImageButton(int, const std::string &, const ImageDef &);
	virtual ~ImageButton();
	virtual void render(MinecraftClient *, int, int);
	virtual void renderBg(MinecraftClient *, int, int);
	bool isSecondImage(bool);
	void setImageDef(const ImageDef &, bool);
	void setYOffset(int);
	void setupDefault();
};
