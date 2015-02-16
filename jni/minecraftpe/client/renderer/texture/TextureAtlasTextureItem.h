#pragma once

#include <string>
#include <vector>

class TextureAtlasTextureItem {
public:
	TextureAtlasTextureItem();
	TextureAtlasTextureItem(const TextureAtlasTextureItem &);
	TextureAtlasTextureItem(const std::string &, const std::vector<TextureUVCoordinateSet> &);
	void getName() const;
	int uvCount() const;
	TextureUVCoordinateSet operator[](int) const;
};
