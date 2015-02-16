#pragma once

#include "minecraftpe/client/gui/GuiElement.h"

class NinePatchDescription;
class Textures;
class Tessellator;

class NinePatchLayer : public GuiElement {
public:
	NinePatchLayer(const NinePatchDescription &, const std::string &, Textures *, float, float);
	virtual ~NinePatchLayer();
	void draw(Tessellator &, float, float);
	void setSize(float, float);
};
