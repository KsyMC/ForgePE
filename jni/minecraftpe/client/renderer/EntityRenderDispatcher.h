#pragma once

class Vec3;
class MinecraftClient;
class EntityRenderer;
class Entity;

class EntityRenderDispatcher {
public:
	static EntityRenderDispatcher *instance;

public:
	EntityRenderDispatcher(MinecraftClient &);
	EntityRenderer *getRenderer(Entity &);
	EntityRenderer *getRenderer(EntityRendererId);
	void render(Entity &, const Vec3 &, float, float);
};
