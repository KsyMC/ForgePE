#pragma once

class ImageDef {
public:
	std::string _textureName;	// 0
	int	_x;						// 4
	int	_y;						// 8
	float _width;				// 12
	float _height;				// 16
	IntRectangle _intRectangle;	// 20
	bool _crop;					// 36
};
