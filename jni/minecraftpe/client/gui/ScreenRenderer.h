#pragma once

#include "minecraftpe/client/renderer/MaterialPtr.h"

class Font;
class Color;
class IntRectangle;

class ScreenRenderer {
public:
	static ScreenRenderer *singletonPtr;

public:
	MaterialPtr ui_textured;			// 0
	MaterialPtr ui_fill_color;			// 12
	MaterialPtr ui_fill_gradient;		// 24
	MaterialPtr ui_texture_and_color;	// 36
	MaterialPtr ui_textured_and_glcolor;// 48

public:
	ScreenRenderer();
	void drawRect(int, int, int, int, const Color &, int);
	void drawRect(int, int, int, int, const Color &, const Color &, const Color &, const Color &, int);
	void blit(const IntRectangle &);
	void blit(float, float, int, int, float, float, int, int);
	void blit(int, int, int, int, int, int, int, int, MaterialPtr *);
	void blitRaw(float, float, float, float, float, float, float, float, float);
	void drawString(Font *, const std::string &, int, int, Color const &);
	void drawCenteredString(Font *, const std::string &, int, int, const Color &);
	void fill(float, float, float, float, const Color &);
	void fill(int, int, int, int, const Color &);
	void fillGradient(float, float, float, float, const Color &, const Color &);
	void fillGradient(int, int, int, int, const Color &, const Color &);
	void fillHorizontalGradient(float, float, float, float, const Color &, const Color &);
	void fillHorizontalGradient(int, int, int, int, const Color &, const Color &);
	ScreenRenderer *singleton();
};
