#pragma once

class RenderMaterialGroup;

class MaterialPtr {
public:
	char filler1[12];	// 0

	MaterialPtr(MaterialPtr &&);
	MaterialPtr(RenderMaterialGroup &, const std::string &);
	MaterialPtr();
};
