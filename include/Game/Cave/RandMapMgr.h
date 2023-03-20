#ifndef _GAME_CAVE_RANDMAPMGR_H
#define _GAME_CAVE_RANDMAPMGR_H

#include "types.h"
#include "Game/mapParts.h"
#include "Game/Cave/RandMapUnit.h"
#include "JSystem/JUtility/JUTTexture.h"

namespace Game {
namespace Cave {
struct RandEnemyUnit;
struct RandItemUnit;
struct RandMapUnit;

struct RandMapDraw;
struct RandMapScore;
struct MapUnitGenerator;

struct EnemyNode;
struct EnemyUnit;

struct GateUnit;

struct RandEnemyUnit {
	RandEnemyUnit(MapUnitGenerator* generator, bool isVersusHiba);

	void setManageClassPtr(RandMapScore*);
	void setEnemySlot();
	void setEnemyTypeWeight();
	void setEnemyTypeC();
	void setEnemyTypeF();
	void setEnemyTypeB();
	void setEnemyTypeA();
	void setVersusHibaTypeC();
	void setVersusEnemyTypeC();
	void setSlotEnemyTypeC(int&, int);
	void setUnitRandEnemyTypeC();
	void makeSetEnemyTypeC(MapNode*, int, EnemyUnit*);
	void setVersusEnemyTypeF();
	void setSlotEnemyTypeF(int);
	void setUnitRandEnemyTypeF();
	void makeSetEnemyTypeF(MapNode*, BaseGen*, EnemyUnit*);
	void setVersusEnemyTypeB();
	void setSlotEnemyTypeB(int);
	void setUnitRandEnemyTypeB();
	void makeSetEnemyTypeB(MapNode*, BaseGen*, EnemyUnit*);
	void setVersusEasyEnemy();
	void getVersusEasyEnemyBaseGen(MapNode*, BaseGen*);
	void setVersusEnemyTypeA();
	void setSlotEnemyTypeA(int&, int&, int);
	void setUnitRandEnemyTypeA(int&, int, int);
	void makeSetEnemyTypeA(MapNode*, BaseGen*, EnemyUnit*, int);
	bool isEnemySetGen(MapNode*, BaseGen*);

	MapUnitGenerator* mGenerator; // _00
	RandMapScore* mScore;         // _04
	int mTotalCount;              // _08, count of all types
	int mMaxEnemies;              // _0C
	int mCount[4];                // _10, current count of type 0=A, 1=B, 2=C, 3=F
	int mMaxCount[4];             // _20, max for type 0=A, 1=B, 2=C, 3=F
	MapNode* mMapNode;            // _30
	BaseGen* mBaseGen;            // _34
	EnemyUnit* mEnemyUnit;        // _38
	bool _3C;                     // _3C
};

/**
 * @size{0x18}
 */
struct RandGateUnit {
	RandGateUnit(MapUnitGenerator* generator);

	void setManageClassPtr(RandMapScore*, RandItemUnit*);
	void setGateDoor();
	GateUnit* getGateUnit();
	MapNode* getRoomNodePtr(int&);
	MapNode* getItemSetCapDoor(int&);
	MapNode* getRoomMinScoreDoor(int&);
	MapNode* getRoomLowScoreDoor(int&);
	MapNode* getRandomScoreDoor(int&);

	MapUnitGenerator* mGenerator; // _00
	RandMapScore* mMapScore;      // _04
	RandItemUnit* mItemUnit;      // _08
	int mGatePlacedCount;         // _0C
	int mGateMax;                 // _10
	int mGateWeightSum;           // _14
};

/**
 * @size{0xC}
 */
struct RandPlantUnit {
	RandPlantUnit(MapUnitGenerator* generator);

	void setPlantSlot();
	MapNode* getPlantSetMapNode(BaseGen**);
	EnemyUnit* getPlantUnit(BaseGen*);
	bool isPlantSet(MapNode*, BaseGen*);

	MapUnitGenerator* mGenerator; // _00
	int mCurrentPlantCount;       // _04
	int mDesiredPlantCount;       // _08
};

/**
 * @size{0x18}
 */
struct RandItemUnit {
	RandItemUnit(MapUnitGenerator* generator);
	void setManageClassPtr(Game::Cave::RandMapScore* a1);
	void setItemSlot();

	bool isItemSetDone(MapNode*, BaseGen*);
	bool isGroundCapEnemySetDone(MapNode*);
	bool isFallCapEnemySetDone(MapNode*);

	void setItemDropPositionList(Game::Cave::MapNode**, Game::Cave::BaseGen**);
	void getItemDropPosition(Vector3f&, f32, int);
	MapNode* getItemNormalSetMapNode(Game::Cave::BaseGen**);
	MapNode* getItemHardSetMapNode(Game::Cave::BaseGen**);
	ItemUnit* getItemUnit();
	int getItemSlotNum(MapNode*);
	bool isItemSetHard();
	void getItemDropMapNode(MapNode*, MapNode**, int, int&);
	Vector3f getItemBaseGenPosition(MapNode*, int);
	void getItemDropList(MapNode*, MapNode**, BaseGen**, int&);
	Vector3f getItemBaseGenPosition(MapNode**, BaseGen**, int, int, int);
	void getItemDropSortingList(MapNode**, BaseGen**, int*, int);

	int mItems;                          // _00
	int mMax;                            // _04
	MapUnitGenerator* mMapUnitGenerator; // _08
	RandMapScore* mRandMapScore;         // _0C
	MapNode** mMapNode;                  // _10
	BaseGen** mBaseGen;                  // _14
};

/**
 * @size{0x18}
 */
struct RandCapEnemyUnit {
	RandCapEnemyUnit(MapUnitGenerator*);

	void setManageClassPtr(RandItemUnit*);
	void setCapEnemySlot();
	void setCapCommonEnemySlot(MapNode*, int);
	void setCapEnemy(MapNode*, EnemyUnit*, int, int);

	MapUnitGenerator* mMapUnitGenerator; // _00
	RandItemUnit* mRandItemUnit;         // _04
	EnemyNode* mEnemyNode[2];            // _08
	int mPerSpawn[2];                    // _10
};

/**
 * @size{0x48}
 */
struct RandMapMgr : public CNode {
	RandMapMgr(bool isVersusHiba);

	virtual ~RandMapMgr() { } // _08 (weak)

	void loadResource(MapUnitInterface*, int, FloorInfo*, bool, EditMapUnit*);
	void create();
	int getNumRooms();
	char* getUseUnitName(int);
	char* getRoomData(int, f32&, f32&, int&);
	RoomLink* makeRoomLink(int);
	ObjectLayoutInfo* makeObjectLayoutInfo(int);
	void getStartPosition(Vector3f&, int);
	void getItemDropPosition(Vector3f&, f32, f32);
	void getItemDropPosition(Vector3f*, int, f32, f32);
	void setUnitTexture(int, JUTTexture*);
	void setCaptureOn();
	void captureRadarMap(Graphics&);
	bool isLastFloor();
	bool isVersusHiba();
	JUTTexture* getRadarMapTexture();
	void radarMapPartsOpen(Vector3f&);
	void getPositionOnTex(Vector3f&, f32&, f32&);
	void getBaseGenData(Vector3f*, f32*);
	void drawFrameBuffer(Graphics&);

	MapUnitGenerator* mMapUnitGenerator; // _18
	RandMapUnit* mRandMapUnit;           // _1C
	RandEnemyUnit* mRandEnemyUnit;       // _20
	RandCapEnemyUnit* mRandCapEnemyUnit; // _24
	RandPlantUnit* mRandPlantUnit;       // _28
	RandGateUnit* mRandGateUnit;         // _2C
	RandItemUnit* mRandItemUnit;         // _30
	RandMapScore* mRandMapScore;         // _34
	RandMapDraw* mRandMapDraw;           // _38
	bool mIsCaptureOn;                   // _3C
	JUTTexture* mRadarMapTexture;        // _40
	bool mIsVersusHiba;                  // _44
};

/**
 * @size{0x4}
 */
struct RandMapDraw {
	RandMapDraw(MapUnitGenerator* generator);

	void radarMapPartsOpen(Vector3f& vec);
	void draw(struct Graphics& gfx, f32 x, f32 y, f32 z);

	MapUnitGenerator* mGenerator; // _00
};

struct RandMapScore {
	enum FixObjNodeTypes {
		FIXNODE_Pod         = 0,
		FIXNODE_Hole        = 1,
		FIXNODE_Fountain    = 2,
		FIXNODE_VsRedOnyon  = 3,
		FIXNODE_VsBlueOnyon = 4,
	};

	RandMapScore(MapUnitGenerator*);

	void setMapUnitScore();
	void setStartSlot();
	void setGoalSlot();
	void makeObjectLayout(MapNode*, ObjectLayout*);
	MapNode* getFixObjNode(int);
	BaseGen* getFixObjGen(int);
	void getGlobalPosition(int, Vector3f&);
	int getVersusHighScore();
	int getVersusLowScore();
	bool isScoreSetDone();
	void clearRoomAndDoorScore();
	void setUnitAndDoorScore();
	void setStartMapNodeScore(MapNode*);
	void setChallengePod();
	void setVersusOnyon();
	MapNode* getMaxScoreRoomMapNode(MapNode*, BaseGen**);
	void calcNodeScore(MapNode*);
	void copyNodeScore();
	void subNodeScore();
	void setMapNodeScore(MapNode*, int);
	void setChallengeFixObjNormal();
	void setChallengeFixObjHard();
	bool isGoalSetHard();
	bool isFixObjSet(MapNode*, BaseGen*);
	MapNode* getRandRoomMapNode();

	MapUnitGenerator* mGenerator; // _00
	MapNode** mFixObjNodes;       // _04, array of 5 map nodes, see FixObjNodeTypes enum
	BaseGen** mFixObjGens;        // _08, array of 5 gens, see FixObjNodeTypes enum
	u32 mVersusHighScore;         // _0C
	u32 mVersusLowScore;          // _10
};

// instantiated in Nishimura/MapCreator.cpp
extern RandMapMgr* randMapMgr;

} // namespace Cave
} // namespace Game

#endif
