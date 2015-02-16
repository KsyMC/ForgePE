#pragma once

#include "ImageButton.h"

class MinecraftClient;
class ImageDef;

class LargeImageButton : public ImageButton {
public:
	// Size : 196

public:
	LargeImageButton(const std::string &);
	LargeImageButton(const std::string &, ImageDef &);
	virtual ~LargeImageButton();
	virtual void render(MinecraftClient *, int, int);
	virtual void setupDefault();
};
