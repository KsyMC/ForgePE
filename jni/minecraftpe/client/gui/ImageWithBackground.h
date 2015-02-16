#pragma once

#include "LargeImageButton.h"

class MinecraftClient;
class Textures;

class ImageWithBackground : public LargeImageButton {
public:
	// Size : 196

public:
	ImageWithBackground(int);
	virtual ~ImageWithBackground();
	virtual void render(MinecraftClient *, int, int);
	virtual void renderBg(MinecraftClient *, int, int);
	void init(Textures *, int, int, IntRectangle, IntRectangle, int, int, const std::string &);
	void setSize(float, float);
};
