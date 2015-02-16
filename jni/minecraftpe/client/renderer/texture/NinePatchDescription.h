#pragma once

class IntRectangle;

class NinePatchDescription {
public:
	NinePatchDescription(float, float, float, float, float, float, float, float, float, float, float, float);
	void createSymmetrical(int, int, const IntRectangle &, int, int);
};
