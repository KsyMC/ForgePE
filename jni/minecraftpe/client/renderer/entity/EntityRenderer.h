#pragma once

#include "minecraftpe/client/renderer/EntityShaderManager.h"

class Font;
class Entity;
class EntityRendererDispatcher;
class Vec3;

class EntityRenderer {
public:
	static EntityRendererDispatcher *entityRenderDispatcher;

public:
	//void **vtable;					// 0
	EntityShaderManager _shaderManager;	// 4

public:
	static void _emitFlame(Entity &, float);
	static void _emitSmoke(Entity &, float);
	static void init(EntityRenderDispatcher *);
	static bool isFancy();
	static Font *getFont();

public:
	EntityRenderer();
	virtual ~EntityRenderer();
	virtual void render(Entity &, const Vec3 &, float, float) = 0;
	virtual void postRender(Entity &, const Vec3 &, float, float);
	virtual void renderName(Entity &, float);
	void bindTexture(const std::string &);
};
