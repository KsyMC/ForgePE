#pragma once

#include "minecraftpe/tile/TileID.h"
#include "minecraftpe/tileentity/TileEntityTypeEnum.h"
#include "minecraftpe/client/renderer/texture/TextureUVCoordinateSet.h"
#include "minecraftpe/client/renderer/texture/TextureAtlasTextureItem.h"

class TileSource;
class AABB;
class Random;
class Player;
class ItemInstance;
class Entity;
class Mob;
class TextureAtlas;
class Material;
class Vec3;
class TilePos;

class Tile {
public:
	class SoundType {
		SoundType(const std::string &, float, float);
		~SoundType();
	};

public:
	static Tile *netherFence, *stairs_netherBricks, *stairs_sandStone, *quartzBlock, *mycelium, *brownMushroomBlock, *redMushroomBlock, *emeraldBlock, *redStoneDust, *waterlily, *emeraldOre;
	static Tile *woodStairsJungle, *woodStairsBigOak, *woodStairsAcacia, *deadBush, *leaves2, *log2, *stairs_stoneBrickSmooth, *netherBrick, *netherrack, *ironFence, *stairs_quartz, *stainedClay;
	static Tile *pumpkin, *litPumpkin, *info_updateGame1, *carrots, *potatoes, *beetroot, *netherReactor, *glowingObsidian, *woodStairsDark, *woodStairsBirch, *hayBlock, *coalBlock, *woolCarpet;
	static Tile *stoneBrickSmooth, *fenceGateOak, *fenceGateSpruce, *fenceGateBirch, *fenceGateJungle, *fenceGateBigOak, *fenceGateAcacia, *info_updateGame2, *info_reserved6, *cobbleWall;
	static Tile *stairs_stone, *stairs_brick, *door_wood, *door_iron, *cactus, *rail, *goldenRail, *activatorRail, *melon, *pumpkinStem, *melonStem, *bed, *tallgrass, *trapdoor, *monsterStoneEgg;
	static Tile *water, *lava, *fire, *invisible_bedrock, *goldBlock, *ironBlock, *diamondBlock, *workBench, *stonecutterBench, *crops, *furnace, *furnace_lit, *chest, *lightGem, *stairs_wood, *fence;
	static Tile *redStoneOre, *redStoneOre_lit, *goldOre, *ironOre, *coalOre, *lapisOre, *lapisBlock, *reeds, *ladder, *obsidian, *tnt, *bookshelf, *sign, *wallSign, *mossStone, *torch, *mobSpawner;
	static Tile *sandStone, *sand, *stoneSlab, *stoneSlabHalf, *woodSlab, *woodSlabHalf, *cloth, *yellowFlower, *redFlower, *brownMushroom, *redMushroom, *topSnow, *log, *snow, *leaves, *diamondOre;
	static Tile *calmLava, *calmWater, *thinGlass, *web, *glass, *sponge, *sapling, *wood, *redBrick, *farmland, *clay, *ice, *grass, *podzol, *dirt, *unbreakable, *rock, *gravel, *stoneBrick, *endStone;
	static Tile *hardenedClay, *doublePlant;

	static SoundType SOUND_SILENT, SOUND_SAND, SOUND_CLOTH, SOUND_GLASS, SOUND_METAL, SOUND_STONE, SOUND_GRASS, SOUND_GRAVEL, SOUND_WOOD, SOUND_NORMAL;

	static bool shouldTick[255];
	static float translucency[255];
	static bool solid[255];
	static float lightEmission[255];
	static int lightBlock[255];
	static Tile *tiles[255];
	static TextureAtlas *_terrainTextureAtlas;
	static const char *TILE_DESCRIPTION_PREFIX;

public:
	// Size : 140
	//void **vtable;		// 0
	char filler1[64];		// 4
	unsigned char _id;		// 68
	char filler2[12];		// 72
	int _rendererId;		// 84
	char filler3[4];		// 88
	TileEntityType _type;	// 92
	char filler4[28];		// 96
	int _category;			// 124
	char filler5[12];		// 128

public:
	Tile(int, const Material *);
	Tile(int, TextureUVCoordinateSet, const Material *);
	Tile(int, std::string, const Material *);
	virtual ~Tile();
	virtual void onFertilized(TileSource *, int, int, int);
	virtual AABB *getShape(TileSource *, int, int, int, AABB &, bool);
	virtual void getShape(unsigned char, AABB &, bool);
	virtual void isObstructingChests(TileSource *, int, int, int);
	virtual void shouldRenderFace(TileSource *, int, int, int, signed char, const AABB &) const;
	virtual TextureUVCoordinateSet *getTexture(signed char);
	virtual TextureUVCoordinateSet *getTexture(signed char, int);
	virtual TextureUVCoordinateSet *getTexture(TileSource *, int, int, int, signed char);
	virtual void getTessellatedUVs();
	virtual void getCarriedTexture(signed char, int);
	virtual AABB *getAABB(TileSource *, int, int, int, AABB &, int, bool, int);
	virtual void addAABBs(TileSource *, int, int, int, AABB const *, std::vector<AABB> &);
	virtual void getTileAABB(TileSource *, int, int, int, AABB &);
	virtual void isPathfindable(TileSource *, int, int, int);
	virtual void mayPick();
	virtual void mayPick(int, bool);
	virtual void mayPlace(TileSource *, int, int, int, signed char);
	virtual void mayPlace(TileSource *, int, int, int);
	virtual void getTickDelay();
	virtual void tick(TileSource *, int, int, int, Random *);
	virtual void animateTick(TileSource *, int, int, int, Random *);
	virtual void destroy(TileSource *, int, int, int, int);
	virtual void playerWillDestroy(Player *, int, int, int, int);
	virtual void neighborChanged(TileSource *, int, int, int, int, int, int);
	virtual void onPlace(TileSource *, int, int, int);
	virtual void onRemove(TileSource *, int, int, int);
	virtual void getSecondPart(TileSource &, const TilePos &, TilePos &);
	virtual void onGraphicsModeChanged(bool, bool);
	virtual int getResource(int, Random *);
	virtual int getResourceCount(Random *);
	virtual void getDestroyProgress(Player *);
	virtual void spawnResources(TileSource *, int, int, int, int, float);
	virtual void spawnBurnResources(TileSource *, float, float, float);
	virtual void getExplosionResistance(Entity *);
	virtual void clip(TileSource *, int, int, int, const Vec3 &, const Vec3 &, bool, int);
	virtual void wasExploded(TileSource *, int, int, int);
	virtual void use(Player *, int, int, int);
	virtual void stepOn(Entity *, int, int, int);
	virtual void fallOn(TileSource *, int, int, int, Entity *, float);
	virtual void getPlacementDataValue(Mob *, int, int, int, signed char, float, float, float, int);
	virtual void prepareRender(TileSource *, int, int, int);
	virtual void attack(Player *, int, int, int);
	virtual void handleEntityInside(TileSource *, int, int, int, Entity *, Vec3 &);
	virtual void getColor(int);
	virtual void getColor(TileSource *, int, int, int);
	virtual void isSignalSource();
	virtual void getSignal(TileSource *, int, int, int);
	virtual void getSignal(TileSource *, int, int, int, int);
	virtual void getDirectSignal(TileSource *, int, int, int, int);
	virtual void entityInside(TileSource *, int, int, int, Entity *);
	virtual void playerDestroy(Player *, int, int, int, int);
	virtual void canSurvive(TileSource *, int, int, int);
	virtual void getName() const;
	virtual void getDescriptionId() const;
	virtual void getDescriptionId(const ItemInstance *) const;
	virtual void getTypeDescriptionId(int);
	virtual void setDescriptionId(const std::string &);
	virtual void triggerEvent(TileSource *, int, int, int, int, int);
	virtual void getTextureNum(int);
	virtual void getMobToSpawn(TileSource &, const TilePos &) const;
	virtual void getIconYOffset() const;
	virtual void setShape(float, float, float, float, float, float);
	virtual void setSoundType(const Tile::SoundType &);
	virtual void setLightBlock(int);
	virtual void setLightEmission(float);
	virtual void setExplodeable(float);
	virtual void setDestroyTime(float);
	virtual void setTicking(bool);
	virtual void getSpawnResourcesAuxValue(int);
	virtual void init();
	static void initTiles();
	static Material *getTileMaterial(int);
	static float getLightEmission(TileID);
	static int getIDByName(const std::string &, bool);
	void _getTypeToSpawn(TileSource &, int, const TilePos &) const;
	void addAABB(const AABB &, const AABB *, std::vector<AABB> &);
	void setCategory(int);
	TextureAtlasTextureItem getTextureItem(const std::string &);
	float getShadeBrightness() const;
	TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string &, int);
};
