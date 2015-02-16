#pragma once

#include "minecraftpe/client/renderer/entity/EntityRenderer.h"

class ItemInstance;
class Tessellator;
class Textures;
class TextureUVCoordinateSet;

class ItemRenderer : public EntityRenderer {
public:
	static ItemRenderer *singletonPtr;

public:
	static ItemRenderer *singleton();

public:
	ItemRenderer();
	virtual ~ItemRenderer();
	virtual void render(Entity &, const Vec3 &, float, float);
	void renderGuiItemCorrect(Font *, Textures *, const ItemInstance *, int, int);
	void renderGuiItemDecorations(const ItemInstance *, float, float);
	//void renderGuiItemInChunk(ItemRenderChunkType, Textures *, const ItemInstacne *, float, float, float, float, float); TODO
	void renderGuiItemNew(Textures *, const ItemInstance *, int, float, float, float, float, float);
	void blit(float, float, float, float, float, float);
	void iconBlit(float, float, const TextureUVCoordinateSet &, float, float, float, float, int, float);
	void fillRect(Tessellator &, float, float, float, float, int);
	int getAtlasPos(const ItemInstance *);
};
