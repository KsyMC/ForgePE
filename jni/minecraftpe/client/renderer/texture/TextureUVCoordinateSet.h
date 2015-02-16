#pragma once

#include "minecraftpe/client/renderer/texture/TextureFileEnum.h"

class TextureUVCoordinateSet {
public:
	// Size : 32
	float startX;		// 0
	float startY;		// 4
	float endX;			// 8
	float endY;			// 12
	float width;		// 16
	float height;		// 20
	int i1;				// 24
	TextureFile type;	// 28

public:
	TextureUVCoordinateSet(float, float, float, float, float, float, int, TextureFile);
	TextureUVCoordinateSet();
	void fix();
};
