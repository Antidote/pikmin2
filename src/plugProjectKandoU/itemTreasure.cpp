#include "Game/Entities/ItemTreasure.h"
#include "Game/GameSystem.h"
#include "Game/gamePlayData.h"
#include "Game/MoviePlayer.h"
#include "Game/PikiMgr.h"
#include "efx/TOtakara.h"
#include "Dolphin/rand.h"
#include "PSM/WorkItem.h"
#include "VsOtakaraName.h"
#include "JSystem/JKR/JKRDvdRipper.h"

// Don't be fooled by this files name, it is NOT related to actual treasures, those are pellets/otakara
// ItemTreasure is specifically for buried treasures, its an invisible object that effectively holds
// the actual treasure in place until you kill, where the treasure becomes freed
// Why they handled buried treasures this way is beyond me

static const char name[] = "itemTreasure";

/*
    Generated from dpostproc

    .section .ctors, "wa"  # 0x80472F00 - 0x804732C0
    .4byte __sinit_itemTreasure_cpp

    .section .rodata  # 0x804732E0 - 0x8049E220
    .global lbl_804816B8
    lbl_804816B8:
        .4byte 0x00000000
        .4byte 0x00000000
        .4byte 0x00000000
        .4byte 0x6974656D
        .4byte 0x54726561
        .4byte 0x73757265
        .4byte 0x00000000
    .global lbl_804816D4
    lbl_804816D4:
        .4byte 0x7831345F
        .4byte 0x77686974
        .4byte 0x655F6469
        .4byte 0x67000000
    .global lbl_804816E4
    lbl_804816E4:
        .4byte 0x6974656D
        .4byte 0x54726561
        .4byte 0x73757265
        .4byte 0x2E637070
        .4byte 0x00000000
    .global lbl_804816F8
    lbl_804816F8:
        .asciz "P2Assert"
        .skip 3
    .global lbl_80481704
    lbl_80481704:
        .4byte 0x54726561
        .4byte 0x73757265
        .4byte 0x00000000
        .4byte 0x75736572
        .4byte 0x2F4B616E
        .4byte 0x646F2F6F
        .4byte 0x626A6563
        .4byte 0x74732F74
        .4byte 0x72656173
        .4byte 0x75726500
        .4byte 0x75736572
        .4byte 0x2F416265
        .4byte 0x2F697465
        .4byte 0x6D2F7472
        .4byte 0x65617375
        .4byte 0x72655061
        .4byte 0x726D732E
        .4byte 0x74787400
        .4byte 0x43726561
        .4byte 0x74757265
        .4byte 0x3A3A5072
        .4byte 0x6F706572
        .4byte 0x74790000
        .4byte 0x66726963
        .4byte 0x74696F6E
        .4byte 0x286E6F74
        .4byte 0x20757365
        .4byte 0x64290000
        .4byte 0x77616C6C
        .4byte 0x5265666C
        .4byte 0x65637469
        .4byte 0x6F6E0000
        .4byte 0x66616365
        .4byte 0x44697241
        .4byte 0x646A7573
        .4byte 0x74000000
        .4byte 0x626F756E
        .4byte 0x63654661
        .4byte 0x63746F72
        .4byte 0x00000000
        .4byte 0x506C616E
        .4byte 0x743A3A50
        .4byte 0x61726D73
        .4byte 0x00000000
        .4byte 0x83898343
        .4byte 0x83742830
        .4byte 0x29000000
        .4byte 0x83898343
        .4byte 0x83742831
        .4byte 0x29000000
        .4byte 0x83898343
        .4byte 0x83742832
        .4byte 0x29000000
        .4byte 0x83898343
        .4byte 0x83742833
        .4byte 0x29000000
        .4byte 0x50656C6C
        .4byte 0x6574496E
        .4byte 0x69744172
        .4byte 0x67000000
        .4byte 0x41726753
        .4byte 0x63616C65
        .4byte 0x00000000

    .section .data, "wa"  # 0x8049E220 - 0x804EFC20
    .global lbl_804BBC18
    lbl_804BBC18:
        .4byte 0x00000000
        .4byte 0x00000000
        .4byte 0x00000000
    .global __vt__Q34Game12ItemTreasure3Mgr
    __vt__Q34Game12ItemTreasure3Mgr:
        .4byte 0
        .4byte 0
        .4byte doAnimation__Q24Game12TNodeItemMgrFv
        .4byte doEntry__Q24Game12TNodeItemMgrFv
        .4byte doSetView__Q24Game12TNodeItemMgrFi
        .4byte doViewCalc__Q24Game12TNodeItemMgrFv
        .4byte doSimulation__Q24Game12TNodeItemMgrFf
        .4byte doDirectDraw__Q24Game12TNodeItemMgrFR8Graphics
        .4byte doSimpleDraw__16GenericObjectMgrFP8Viewport
        .4byte loadResources__Q24Game11BaseItemMgrFv
        .4byte resetMgr__16GenericObjectMgrFv
        .4byte pausable__16GenericObjectMgrFv
        .4byte frozenable__16GenericObjectMgrFv
        .4byte getMatrixLoadType__16GenericObjectMgrFv
        .4byte initDependency__Q24Game12TNodeItemMgrFv
        .4byte killAll__Q24Game12TNodeItemMgrFv
        .4byte setup__Q24Game11BaseItemMgrFPQ24Game8BaseItem
        .4byte setupSoundViewerAndBas__Q24Game11BaseItemMgrFv
        .4byte onLoadResources__Q34Game12ItemTreasure3MgrFv
        .4byte loadEverytime__Q24Game11BaseItemMgrFv
        .4byte updateUseList__Q24Game11BaseItemMgrFPQ24Game11GenItemParmi
        .4byte onUpdateUseList__Q24Game11BaseItemMgrFPQ24Game11GenItemParmi
        .4byte generatorGetID__Q34Game12ItemTreasure3MgrFv
        .4byte
   "generatorBirth__Q34Game12ItemTreasure3MgrFR10Vector3<f>R10Vector3<f>PQ24Game11GenItemParm"
        .4byte
   generatorWrite__Q24Game11BaseItemMgrFR6StreamPQ24Game11GenItemParm .4byte
   generatorRead__Q24Game11BaseItemMgrFR6StreamPQ24Game11GenItemParmUl .4byte
   generatorLocalVersion__Q24Game11BaseItemMgrFv .4byte
   generatorGetShape__Q24Game11BaseItemMgrFPQ24Game11GenItemParm .4byte
   generatorNewItemParm__Q24Game11BaseItemMgrFv .4byte 0 .4byte 0 .4byte
   "@48@__dt__Q34Game12ItemTreasure3MgrFv" .4byte getChildCount__5CNodeFv .4byte
   "getObject__27Container<Q24Game8BaseItem>FPv" .4byte
   "@48@getNext__Q24Game12TNodeItemMgrFPv" .4byte
   "@48@getStart__Q24Game12TNodeItemMgrFv" .4byte
   "@48@getEnd__Q24Game12TNodeItemMgrFv" .4byte
   "@48@get__Q24Game12TNodeItemMgrFPv" .4byte
   "getAt__27Container<Q24Game8BaseItem>Fi" .4byte
   "getTo__27Container<Q24Game8BaseItem>Fv" .4byte
   doNew__Q34Game12ItemTreasure3MgrFv .4byte
   kill__Q24Game12TNodeItemMgrFPQ24Game8BaseItem .4byte
   get__Q24Game12TNodeItemMgrFPv .4byte getNext__Q24Game12TNodeItemMgrFPv .4byte
   getStart__Q24Game12TNodeItemMgrFv .4byte getEnd__Q24Game12TNodeItemMgrFv
        .4byte __dt__Q34Game12ItemTreasure3MgrFv
        .4byte birth__Q34Game12ItemTreasure3MgrFv
    .global __vt__Q34Game12ItemTreasure13TreasureParms
    __vt__Q34Game12ItemTreasure13TreasureParms:
        .4byte 0
        .4byte 0
        .4byte read__Q34Game12ItemTreasure13TreasureParmsFR6Stream
    .global __vt__Q34Game12ItemTreasure4Item
    __vt__Q34Game12ItemTreasure4Item:
        .4byte 0
        .4byte 0
        .4byte getPosition__Q24Game8BaseItemFv
        .4byte checkCollision__Q24Game8CreatureFPQ24Game10CellObject
        .4byte getBoundingSphere__Q24Game8BaseItemFRQ23Sys6Sphere
        .4byte collisionUpdatable__Q24Game8CreatureFv
        .4byte isPiki__Q24Game8CreatureFv
        .4byte isNavi__Q24Game8CreatureFv
        .4byte deferPikiCollision__Q24Game10CellObjectFv
        .4byte getTypeName__Q24Game8CreatureFv
        .4byte getObjType__Q24Game8CreatureFv
        .4byte constructor__Q34Game12ItemTreasure4ItemFv
        .4byte onInit__Q34Game12ItemTreasure4ItemFPQ24Game15CreatureInitArg
        .4byte onKill__Q24Game8CreatureFPQ24Game15CreatureKillArg
        .4byte onInitPost__Q24Game8CreatureFPQ24Game15CreatureInitArg
        .4byte doAnimation__Q24Game8BaseItemFv
        .4byte doEntry__Q24Game8BaseItemFv
        .4byte doSetView__Q24Game8CreatureFi
        .4byte doViewCalc__Q24Game8CreatureFv
        .4byte doSimulation__Q24Game8BaseItemFf
        .4byte doDirectDraw__Q34Game12ItemTreasure4ItemFR8Graphics
        .4byte getBodyRadius__Q24Game8CreatureFv
        .4byte getCellRadius__Q24Game8CreatureFv
        .4byte "initPosition__Q24Game8CreatureFR10Vector3<f>"
        .4byte "onInitPosition__Q24Game8CreatureFR10Vector3<f>"
        .4byte getFaceDir__Q24Game8BaseItemFv
        .4byte "setVelocity__Q24Game8BaseItemFR10Vector3<f>"
        .4byte getVelocity__Q24Game8BaseItemFv
        .4byte "onSetPosition__Q24Game8BaseItemFR10Vector3<f>"
        .4byte "onSetPositionPost__Q24Game8CreatureFR10Vector3<f>"
        .4byte updateTrMatrix__Q24Game8BaseItemFv
        .4byte isTeki__Q24Game8CreatureFv
        .4byte isPellet__Q24Game8CreatureFv
        .4byte inWaterCallback__Q24Game8CreatureFPQ24Game8WaterBox
        .4byte outWaterCallback__Q24Game8CreatureFv
        .4byte inWater__Q24Game8CreatureFv
        .4byte getFlockMgr__Q24Game8CreatureFv
        .4byte onStartCapture__Q24Game8CreatureFv
        .4byte onUpdateCapture__Q24Game8CreatureFR7Matrixf
        .4byte onEndCapture__Q24Game8CreatureFv
        .4byte isAtari__Q24Game8CreatureFv
        .4byte setAtari__Q24Game8CreatureFb
        .4byte isAlive__Q24Game8CreatureFv
        .4byte setAlive__Q24Game8CreatureFb
        .4byte isCollisionFlick__Q24Game8CreatureFv
        .4byte setCollisionFlick__Q24Game8CreatureFb
        .4byte isMovieActor__Q24Game8CreatureFv
        .4byte isMovieExtra__Q24Game8CreatureFv
        .4byte isMovieMotion__Q24Game8CreatureFv
        .4byte setMovieMotion__Q24Game8CreatureFb
        .4byte isBuried__Q24Game8CreatureFv
        .4byte isFlying__Q24Game8CreatureFv
        .4byte isUnderground__Q24Game8CreatureFv
        .4byte isLivingThing__Q24Game8CreatureFv
        .4byte isDebugCollision__Q24Game8CreatureFv
        .4byte setDebugCollision__Q24Game8CreatureFb
        .4byte doSave__Q24Game8CreatureFR6Stream
        .4byte doLoad__Q24Game8CreatureFR6Stream
        .4byte
   "bounceCallback__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>FPQ23Sys8Triangle"
        .4byte
   "collisionCallback__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>FRQ24Game9CollEvent"
        .4byte
   "platCallback__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>FRQ24Game9PlatEvent"
        .4byte getJAIObject__Q24Game8BaseItemFv
        .4byte getPSCreature__Q24Game8BaseItemFv
        .4byte getSound_AILOD__Q24Game8CreatureFv
        .4byte getSound_PosPtr__Q24Game8BaseItemFv
        .4byte sound_culling__Q24Game8CreatureFv
        .4byte getSound_CurrAnimFrame__Q24Game8CreatureFv
        .4byte getSound_CurrAnimSpeed__Q24Game8CreatureFv
        .4byte on_movie_begin__Q24Game8CreatureFb
        .4byte on_movie_end__Q24Game8CreatureFb
        .4byte movieStartAnimation__Q24Game8BaseItemFUl
        .4byte movieStartDemoAnimation__Q24Game8BaseItemFPQ28SysShape8AnimInfo
        .4byte movieSetAnimationLastFrame__Q24Game8BaseItemFv
        .4byte "movieSetTranslation__Q24Game8BaseItemFR10Vector3<f>f"
        .4byte movieSetFaceDir__Q24Game8CreatureFf
        .4byte "movieGotoPosition__Q24Game8CreatureFR10Vector3<f>"
        .4byte movieUserCommand__Q24Game8CreatureFUlPQ24Game11MoviePlayer
        .4byte getShadowParam__Q24Game8CreatureFRQ24Game11ShadowParam
        .4byte needShadow__Q24Game8CreatureFv
        .4byte getLifeGaugeParam__Q24Game8CreatureFRQ24Game14LifeGaugeParam
        .4byte getLODSphere__Q24Game8CreatureFRQ23Sys6Sphere
        .4byte getLODCylinder__Q24Game8CreatureFRQ23Sys8Cylinder
        .4byte startPick__Q24Game8CreatureFv
        .4byte endPick__Q24Game8CreatureFb
        .4byte getMabiki__Q24Game8CreatureFv
        .4byte getFootmarks__Q24Game8CreatureFv
        .4byte onStickStart__Q24Game8CreatureFPQ24Game8Creature
        .4byte onStickEnd__Q24Game8CreatureFPQ24Game8Creature
        .4byte onStickStartSelf__Q24Game8CreatureFPQ24Game8Creature
        .4byte onStickEndSelf__Q24Game8CreatureFPQ24Game8Creature
        .4byte isSlotFree__Q24Game8CreatureFs
        .4byte getFreeStickSlot__Q24Game8CreatureFv
        .4byte "getNearFreeStickSlot__Q24Game8CreatureFR10Vector3<f>"
        .4byte getRandomFreeStickSlot__Q24Game8CreatureFv
        .4byte onSlotStickStart__Q24Game8CreatureFPQ24Game8Creatures
        .4byte onSlotStickEnd__Q24Game8CreatureFPQ24Game8Creatures
        .4byte "calcStickSlotGlobal__Q24Game8CreatureFsR10Vector3<f>"
        .4byte "getVelocityAt__Q24Game8BaseItemFR10Vector3<f>R10Vector3<f>"
        .4byte "getAngularEffect__Q24Game8CreatureFR10Vector3<f>R10Vector3<f>"
        .4byte "applyImpulse__Q24Game8CreatureFR10Vector3<f>R10Vector3<f>"
        .4byte ignoreAtari__Q34Game12ItemTreasure4ItemFPQ24Game8Creature
        .4byte getSuckPos__Q24Game8CreatureFv
        .4byte getGoalPos__Q24Game8CreatureFv
        .4byte isSuckReady__Q24Game8CreatureFv
        .4byte isSuckArriveWait__Q24Game8CreatureFv
        .4byte stimulate__Q24Game8BaseItemFRQ24Game11Interaction
        .4byte getCreatureName__Q34Game12ItemTreasure4ItemFv
        .4byte getCreatureID__Q24Game8BaseItemFv
        .4byte 0
        .4byte 0
        .4byte
   "@376@onKeyEvent__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>FRCQ28SysShape8KeyEvent"
        .4byte initDependency__Q24Game8BaseItemFv
        .4byte startSound__Q24Game8BaseItemFUl
        .4byte makeTrMatrix__Q24Game8BaseItemFv
        .4byte doAI__Q34Game12ItemTreasure4ItemFv
        .4byte move__Q24Game8BaseItemFf
        .4byte changeMaterial__Q24Game8BaseItemFv
        .4byte do_updateLOD__Q24Game8BaseItemFv
        .4byte do_setLODParm__Q24Game8BaseItemFRQ24Game9AILODParm
        .4byte getMapCollisionRadius__Q24Game8BaseItemFv
        .4byte
   interactAttack__Q34Game12ItemTreasure4ItemFRQ24Game14InteractAttack .4byte
   interactBreakBridge__Q24Game8BaseItemFRQ24Game19InteractBreakBridge .4byte
   interactEat__Q24Game8BaseItemFRQ24Game11InteractEat .4byte
   interactFlockAttack__Q24Game8BaseItemFRQ24Game19InteractFlockAttack .4byte
   interactAbsorb__Q24Game8BaseItemFRQ24Game14InteractAbsorb .4byte
   interactFue__Q24Game8BaseItemFRQ24Game11InteractFue .4byte
   interactFarmKarero__Q24Game8BaseItemFRQ24Game18InteractFarmKarero .4byte
   interactFarmHaero__Q24Game8BaseItemFRQ24Game17InteractFarmHaero .4byte
   interactGotKey__Q24Game8BaseItemFRQ24Game14InteractGotKey .4byte
   "getVectorField__Q34Game12ItemTreasure4ItemFRQ23Sys6SphereR10Vector3<f>"
        .4byte getWorkDistance__Q34Game12ItemTreasure4ItemFRQ23Sys6Sphere
        .4byte do_doAnimation__Q24Game8BaseItemFv
        .4byte updateBoundSphere__Q34Game12ItemTreasure4ItemFv
        .4byte update__Q24Game8BaseItemFv
        .4byte entryShape__Q24Game8BaseItemFv
        .4byte onSetPosition__Q34Game12ItemTreasure4ItemFv
        .4byte
   "onKeyEvent__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>FRCQ28SysShape8KeyEvent"
    .global __vt__Q44Game12ItemTreasure4Item10DummyShape
    __vt__Q44Game12ItemTreasure4Item10DummyShape:
        .4byte 0
        .4byte 0
        .4byte getMatrix__Q44Game12ItemTreasure4Item10DummyShapeFi
        .4byte isModel__Q28SysShape9MtxObjectFv
    .global __vt__Q28SysShape9MtxObject
    __vt__Q28SysShape9MtxObject:
        .4byte 0
        .4byte 0
        .4byte 0
        .4byte isModel__Q28SysShape9MtxObjectFv
    .global
   "__vt__Q24Game90WorkItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>"
    "__vt__Q24Game90WorkItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>":
        .4byte 0
        .4byte 0
        .4byte getPosition__Q24Game8BaseItemFv
        .4byte checkCollision__Q24Game8CreatureFPQ24Game10CellObject
        .4byte getBoundingSphere__Q24Game8BaseItemFRQ23Sys6Sphere
        .4byte collisionUpdatable__Q24Game8CreatureFv
        .4byte isPiki__Q24Game8CreatureFv
        .4byte isNavi__Q24Game8CreatureFv
        .4byte deferPikiCollision__Q24Game10CellObjectFv
        .4byte getTypeName__Q24Game8CreatureFv
        .4byte getObjType__Q24Game8CreatureFv
        .4byte 0
        .4byte onInit__Q24Game8CreatureFPQ24Game15CreatureInitArg
        .4byte onKill__Q24Game8CreatureFPQ24Game15CreatureKillArg
        .4byte onInitPost__Q24Game8CreatureFPQ24Game15CreatureInitArg
        .4byte doAnimation__Q24Game8BaseItemFv
        .4byte doEntry__Q24Game8BaseItemFv
        .4byte doSetView__Q24Game8CreatureFi
        .4byte doViewCalc__Q24Game8CreatureFv
        .4byte doSimulation__Q24Game8BaseItemFf
        .4byte doDirectDraw__Q24Game8CreatureFR8Graphics
        .4byte getBodyRadius__Q24Game8CreatureFv
        .4byte getCellRadius__Q24Game8CreatureFv
        .4byte "initPosition__Q24Game8CreatureFR10Vector3<f>"
        .4byte "onInitPosition__Q24Game8CreatureFR10Vector3<f>"
        .4byte getFaceDir__Q24Game8BaseItemFv
        .4byte "setVelocity__Q24Game8BaseItemFR10Vector3<f>"
        .4byte getVelocity__Q24Game8BaseItemFv
        .4byte "onSetPosition__Q24Game8BaseItemFR10Vector3<f>"
        .4byte "onSetPositionPost__Q24Game8CreatureFR10Vector3<f>"
        .4byte updateTrMatrix__Q24Game8BaseItemFv
        .4byte isTeki__Q24Game8CreatureFv
        .4byte isPellet__Q24Game8CreatureFv
        .4byte inWaterCallback__Q24Game8CreatureFPQ24Game8WaterBox
        .4byte outWaterCallback__Q24Game8CreatureFv
        .4byte inWater__Q24Game8CreatureFv
        .4byte getFlockMgr__Q24Game8CreatureFv
        .4byte onStartCapture__Q24Game8CreatureFv
        .4byte onUpdateCapture__Q24Game8CreatureFR7Matrixf
        .4byte onEndCapture__Q24Game8CreatureFv
        .4byte isAtari__Q24Game8CreatureFv
        .4byte setAtari__Q24Game8CreatureFb
        .4byte isAlive__Q24Game8CreatureFv
        .4byte setAlive__Q24Game8CreatureFb
        .4byte isCollisionFlick__Q24Game8CreatureFv
        .4byte setCollisionFlick__Q24Game8CreatureFb
        .4byte isMovieActor__Q24Game8CreatureFv
        .4byte isMovieExtra__Q24Game8CreatureFv
        .4byte isMovieMotion__Q24Game8CreatureFv
        .4byte setMovieMotion__Q24Game8CreatureFb
        .4byte isBuried__Q24Game8CreatureFv
        .4byte isFlying__Q24Game8CreatureFv
        .4byte isUnderground__Q24Game8CreatureFv
        .4byte isLivingThing__Q24Game8CreatureFv
        .4byte isDebugCollision__Q24Game8CreatureFv
        .4byte setDebugCollision__Q24Game8CreatureFb
        .4byte doSave__Q24Game8CreatureFR6Stream
        .4byte doLoad__Q24Game8CreatureFR6Stream
        .4byte
   "bounceCallback__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>FPQ23Sys8Triangle"
        .4byte
   "collisionCallback__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>FRQ24Game9CollEvent"
        .4byte
   "platCallback__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>FRQ24Game9PlatEvent"
        .4byte getJAIObject__Q24Game8BaseItemFv
        .4byte getPSCreature__Q24Game8BaseItemFv
        .4byte getSound_AILOD__Q24Game8CreatureFv
        .4byte getSound_PosPtr__Q24Game8BaseItemFv
        .4byte sound_culling__Q24Game8CreatureFv
        .4byte getSound_CurrAnimFrame__Q24Game8CreatureFv
        .4byte getSound_CurrAnimSpeed__Q24Game8CreatureFv
        .4byte on_movie_begin__Q24Game8CreatureFb
        .4byte on_movie_end__Q24Game8CreatureFb
        .4byte movieStartAnimation__Q24Game8BaseItemFUl
        .4byte movieStartDemoAnimation__Q24Game8BaseItemFPQ28SysShape8AnimInfo
        .4byte movieSetAnimationLastFrame__Q24Game8BaseItemFv
        .4byte "movieSetTranslation__Q24Game8BaseItemFR10Vector3<f>f"
        .4byte movieSetFaceDir__Q24Game8CreatureFf
        .4byte "movieGotoPosition__Q24Game8CreatureFR10Vector3<f>"
        .4byte movieUserCommand__Q24Game8CreatureFUlPQ24Game11MoviePlayer
        .4byte getShadowParam__Q24Game8CreatureFRQ24Game11ShadowParam
        .4byte needShadow__Q24Game8CreatureFv
        .4byte getLifeGaugeParam__Q24Game8CreatureFRQ24Game14LifeGaugeParam
        .4byte getLODSphere__Q24Game8CreatureFRQ23Sys6Sphere
        .4byte getLODCylinder__Q24Game8CreatureFRQ23Sys8Cylinder
        .4byte startPick__Q24Game8CreatureFv
        .4byte endPick__Q24Game8CreatureFb
        .4byte getMabiki__Q24Game8CreatureFv
        .4byte getFootmarks__Q24Game8CreatureFv
        .4byte onStickStart__Q24Game8CreatureFPQ24Game8Creature
        .4byte onStickEnd__Q24Game8CreatureFPQ24Game8Creature
        .4byte onStickStartSelf__Q24Game8CreatureFPQ24Game8Creature
        .4byte onStickEndSelf__Q24Game8CreatureFPQ24Game8Creature
        .4byte isSlotFree__Q24Game8CreatureFs
        .4byte getFreeStickSlot__Q24Game8CreatureFv
        .4byte "getNearFreeStickSlot__Q24Game8CreatureFR10Vector3<f>"
        .4byte getRandomFreeStickSlot__Q24Game8CreatureFv
        .4byte onSlotStickStart__Q24Game8CreatureFPQ24Game8Creatures
        .4byte onSlotStickEnd__Q24Game8CreatureFPQ24Game8Creatures
        .4byte "calcStickSlotGlobal__Q24Game8CreatureFsR10Vector3<f>"
        .4byte "getVelocityAt__Q24Game8BaseItemFR10Vector3<f>R10Vector3<f>"
        .4byte "getAngularEffect__Q24Game8CreatureFR10Vector3<f>R10Vector3<f>"
        .4byte "applyImpulse__Q24Game8CreatureFR10Vector3<f>R10Vector3<f>"
        .4byte ignoreAtari__Q24Game8CreatureFPQ24Game8Creature
        .4byte getSuckPos__Q24Game8CreatureFv
        .4byte getGoalPos__Q24Game8CreatureFv
        .4byte isSuckReady__Q24Game8CreatureFv
        .4byte isSuckArriveWait__Q24Game8CreatureFv
        .4byte stimulate__Q24Game8BaseItemFRQ24Game11Interaction
        .4byte getCreatureName__Q24Game8BaseItemFv
        .4byte getCreatureID__Q24Game8BaseItemFv
        .4byte 0
        .4byte 0
        .4byte
   "@376@onKeyEvent__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>FRCQ28SysShape8KeyEvent"
        .4byte initDependency__Q24Game8BaseItemFv
        .4byte startSound__Q24Game8BaseItemFUl
        .4byte makeTrMatrix__Q24Game8BaseItemFv
        .4byte
   "doAI__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>Fv"
        .4byte move__Q24Game8BaseItemFf
        .4byte changeMaterial__Q24Game8BaseItemFv
        .4byte do_updateLOD__Q24Game8BaseItemFv
        .4byte do_setLODParm__Q24Game8BaseItemFRQ24Game9AILODParm
        .4byte getMapCollisionRadius__Q24Game8BaseItemFv
        .4byte interactAttack__Q24Game8BaseItemFRQ24Game14InteractAttack
        .4byte
   interactBreakBridge__Q24Game8BaseItemFRQ24Game19InteractBreakBridge .4byte
   interactEat__Q24Game8BaseItemFRQ24Game11InteractEat .4byte
   interactFlockAttack__Q24Game8BaseItemFRQ24Game19InteractFlockAttack .4byte
   interactAbsorb__Q24Game8BaseItemFRQ24Game14InteractAbsorb .4byte
   interactFue__Q24Game8BaseItemFRQ24Game11InteractFue .4byte
   interactFarmKarero__Q24Game8BaseItemFRQ24Game18InteractFarmKarero .4byte
   interactFarmHaero__Q24Game8BaseItemFRQ24Game17InteractFarmHaero .4byte
   interactGotKey__Q24Game8BaseItemFRQ24Game14InteractGotKey .4byte 0 .4byte 0
        .4byte do_doAnimation__Q24Game8BaseItemFv
        .4byte updateBoundSphere__Q24Game8BaseItemFv
        .4byte update__Q24Game8BaseItemFv
        .4byte entryShape__Q24Game8BaseItemFv
        .4byte onSetPosition__Q24Game8BaseItemFv
        .4byte
   "onKeyEvent__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>FRCQ28SysShape8KeyEvent"
    .global "__vt__Q24Game35ItemFSM<Q34Game12ItemTreasure4Item>"
    "__vt__Q24Game35ItemFSM<Q34Game12ItemTreasure4Item>":
        .4byte 0
        .4byte 0
        .4byte
   "init__Q24Game40StateMachine<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "start__Q24Game40StateMachine<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemiPQ24Game8StateArg"
        .4byte
   "exec__Q24Game40StateMachine<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "transit__Q24Game40StateMachine<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemiPQ24Game8StateArg"
    .global "__vt__Q24Game40StateMachine<Q34Game12ItemTreasure4Item>"
    "__vt__Q24Game40StateMachine<Q34Game12ItemTreasure4Item>":
        .4byte 0
        .4byte 0
        .4byte
   "init__Q24Game40StateMachine<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "start__Q24Game40StateMachine<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemiPQ24Game8StateArg"
        .4byte
   "exec__Q24Game40StateMachine<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "transit__Q24Game40StateMachine<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemiPQ24Game8StateArg"
    .global
   "__vt__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>"
    "__vt__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>":
        .4byte 0
        .4byte 0
        .4byte getPosition__Q24Game8BaseItemFv
        .4byte checkCollision__Q24Game8CreatureFPQ24Game10CellObject
        .4byte getBoundingSphere__Q24Game8BaseItemFRQ23Sys6Sphere
        .4byte collisionUpdatable__Q24Game8CreatureFv
        .4byte isPiki__Q24Game8CreatureFv
        .4byte isNavi__Q24Game8CreatureFv
        .4byte deferPikiCollision__Q24Game10CellObjectFv
        .4byte getTypeName__Q24Game8CreatureFv
        .4byte getObjType__Q24Game8CreatureFv
        .4byte constructor__Q24Game8BaseItemFv
        .4byte onInit__Q24Game8CreatureFPQ24Game15CreatureInitArg
        .4byte onKill__Q24Game8CreatureFPQ24Game15CreatureKillArg
        .4byte onInitPost__Q24Game8CreatureFPQ24Game15CreatureInitArg
        .4byte doAnimation__Q24Game8BaseItemFv
        .4byte doEntry__Q24Game8BaseItemFv
        .4byte doSetView__Q24Game8CreatureFi
        .4byte doViewCalc__Q24Game8CreatureFv
        .4byte doSimulation__Q24Game8BaseItemFf
        .4byte doDirectDraw__Q24Game8CreatureFR8Graphics
        .4byte getBodyRadius__Q24Game8CreatureFv
        .4byte getCellRadius__Q24Game8CreatureFv
        .4byte "initPosition__Q24Game8CreatureFR10Vector3<f>"
        .4byte "onInitPosition__Q24Game8CreatureFR10Vector3<f>"
        .4byte getFaceDir__Q24Game8BaseItemFv
        .4byte "setVelocity__Q24Game8BaseItemFR10Vector3<f>"
        .4byte getVelocity__Q24Game8BaseItemFv
        .4byte "onSetPosition__Q24Game8BaseItemFR10Vector3<f>"
        .4byte "onSetPositionPost__Q24Game8CreatureFR10Vector3<f>"
        .4byte updateTrMatrix__Q24Game8BaseItemFv
        .4byte isTeki__Q24Game8CreatureFv
        .4byte isPellet__Q24Game8CreatureFv
        .4byte inWaterCallback__Q24Game8CreatureFPQ24Game8WaterBox
        .4byte outWaterCallback__Q24Game8CreatureFv
        .4byte inWater__Q24Game8CreatureFv
        .4byte getFlockMgr__Q24Game8CreatureFv
        .4byte onStartCapture__Q24Game8CreatureFv
        .4byte onUpdateCapture__Q24Game8CreatureFR7Matrixf
        .4byte onEndCapture__Q24Game8CreatureFv
        .4byte isAtari__Q24Game8CreatureFv
        .4byte setAtari__Q24Game8CreatureFb
        .4byte isAlive__Q24Game8CreatureFv
        .4byte setAlive__Q24Game8CreatureFb
        .4byte isCollisionFlick__Q24Game8CreatureFv
        .4byte setCollisionFlick__Q24Game8CreatureFb
        .4byte isMovieActor__Q24Game8CreatureFv
        .4byte isMovieExtra__Q24Game8CreatureFv
        .4byte isMovieMotion__Q24Game8CreatureFv
        .4byte setMovieMotion__Q24Game8CreatureFb
        .4byte isBuried__Q24Game8CreatureFv
        .4byte isFlying__Q24Game8CreatureFv
        .4byte isUnderground__Q24Game8CreatureFv
        .4byte isLivingThing__Q24Game8CreatureFv
        .4byte isDebugCollision__Q24Game8CreatureFv
        .4byte setDebugCollision__Q24Game8CreatureFb
        .4byte doSave__Q24Game8CreatureFR6Stream
        .4byte doLoad__Q24Game8CreatureFR6Stream
        .4byte
   "bounceCallback__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>FPQ23Sys8Triangle"
        .4byte
   "collisionCallback__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>FRQ24Game9CollEvent"
        .4byte
   "platCallback__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>FRQ24Game9PlatEvent"
        .4byte getJAIObject__Q24Game8BaseItemFv
        .4byte getPSCreature__Q24Game8BaseItemFv
        .4byte getSound_AILOD__Q24Game8CreatureFv
        .4byte getSound_PosPtr__Q24Game8BaseItemFv
        .4byte sound_culling__Q24Game8CreatureFv
        .4byte getSound_CurrAnimFrame__Q24Game8CreatureFv
        .4byte getSound_CurrAnimSpeed__Q24Game8CreatureFv
        .4byte on_movie_begin__Q24Game8CreatureFb
        .4byte on_movie_end__Q24Game8CreatureFb
        .4byte movieStartAnimation__Q24Game8BaseItemFUl
        .4byte movieStartDemoAnimation__Q24Game8BaseItemFPQ28SysShape8AnimInfo
        .4byte movieSetAnimationLastFrame__Q24Game8BaseItemFv
        .4byte "movieSetTranslation__Q24Game8BaseItemFR10Vector3<f>f"
        .4byte movieSetFaceDir__Q24Game8CreatureFf
        .4byte "movieGotoPosition__Q24Game8CreatureFR10Vector3<f>"
        .4byte movieUserCommand__Q24Game8CreatureFUlPQ24Game11MoviePlayer
        .4byte getShadowParam__Q24Game8CreatureFRQ24Game11ShadowParam
        .4byte needShadow__Q24Game8CreatureFv
        .4byte getLifeGaugeParam__Q24Game8CreatureFRQ24Game14LifeGaugeParam
        .4byte getLODSphere__Q24Game8CreatureFRQ23Sys6Sphere
        .4byte getLODCylinder__Q24Game8CreatureFRQ23Sys8Cylinder
        .4byte startPick__Q24Game8CreatureFv
        .4byte endPick__Q24Game8CreatureFb
        .4byte getMabiki__Q24Game8CreatureFv
        .4byte getFootmarks__Q24Game8CreatureFv
        .4byte onStickStart__Q24Game8CreatureFPQ24Game8Creature
        .4byte onStickEnd__Q24Game8CreatureFPQ24Game8Creature
        .4byte onStickStartSelf__Q24Game8CreatureFPQ24Game8Creature
        .4byte onStickEndSelf__Q24Game8CreatureFPQ24Game8Creature
        .4byte isSlotFree__Q24Game8CreatureFs
        .4byte getFreeStickSlot__Q24Game8CreatureFv
        .4byte "getNearFreeStickSlot__Q24Game8CreatureFR10Vector3<f>"
        .4byte getRandomFreeStickSlot__Q24Game8CreatureFv
        .4byte onSlotStickStart__Q24Game8CreatureFPQ24Game8Creatures
        .4byte onSlotStickEnd__Q24Game8CreatureFPQ24Game8Creatures
        .4byte "calcStickSlotGlobal__Q24Game8CreatureFsR10Vector3<f>"
        .4byte "getVelocityAt__Q24Game8BaseItemFR10Vector3<f>R10Vector3<f>"
        .4byte "getAngularEffect__Q24Game8CreatureFR10Vector3<f>R10Vector3<f>"
        .4byte "applyImpulse__Q24Game8CreatureFR10Vector3<f>R10Vector3<f>"
        .4byte ignoreAtari__Q24Game8CreatureFPQ24Game8Creature
        .4byte getSuckPos__Q24Game8CreatureFv
        .4byte getGoalPos__Q24Game8CreatureFv
        .4byte isSuckReady__Q24Game8CreatureFv
        .4byte isSuckArriveWait__Q24Game8CreatureFv
        .4byte stimulate__Q24Game8BaseItemFRQ24Game11Interaction
        .4byte getCreatureName__Q24Game8BaseItemFv
        .4byte getCreatureID__Q24Game8BaseItemFv
        .4byte 0
        .4byte 0
        .4byte
   "@376@onKeyEvent__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>FRCQ28SysShape8KeyEvent"
        .4byte initDependency__Q24Game8BaseItemFv
        .4byte startSound__Q24Game8BaseItemFUl
        .4byte makeTrMatrix__Q24Game8BaseItemFv
        .4byte
   "doAI__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>Fv"
        .4byte move__Q24Game8BaseItemFf
        .4byte changeMaterial__Q24Game8BaseItemFv
        .4byte do_updateLOD__Q24Game8BaseItemFv
        .4byte do_setLODParm__Q24Game8BaseItemFRQ24Game9AILODParm
        .4byte getMapCollisionRadius__Q24Game8BaseItemFv
        .4byte interactAttack__Q24Game8BaseItemFRQ24Game14InteractAttack
        .4byte
   interactBreakBridge__Q24Game8BaseItemFRQ24Game19InteractBreakBridge .4byte
   interactEat__Q24Game8BaseItemFRQ24Game11InteractEat .4byte
   interactFlockAttack__Q24Game8BaseItemFRQ24Game19InteractFlockAttack .4byte
   interactAbsorb__Q24Game8BaseItemFRQ24Game14InteractAbsorb .4byte
   interactFue__Q24Game8BaseItemFRQ24Game11InteractFue .4byte
   interactFarmKarero__Q24Game8BaseItemFRQ24Game18InteractFarmKarero .4byte
   interactFarmHaero__Q24Game8BaseItemFRQ24Game17InteractFarmHaero .4byte
   interactGotKey__Q24Game8BaseItemFRQ24Game14InteractGotKey .4byte
   "getVectorField__Q24Game8BaseItemFRQ23Sys6SphereR10Vector3<f>" .4byte
   getWorkDistance__Q24Game8BaseItemFRQ23Sys6Sphere .4byte
   do_doAnimation__Q24Game8BaseItemFv .4byte
   updateBoundSphere__Q24Game8BaseItemFv .4byte update__Q24Game8BaseItemFv
        .4byte entryShape__Q24Game8BaseItemFv
        .4byte onSetPosition__Q24Game8BaseItemFv
        .4byte
   "onKeyEvent__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>FRCQ28SysShape8KeyEvent"
    .global __vt__Q34Game12ItemTreasure11NormalState
    __vt__Q34Game12ItemTreasure11NormalState:
        .4byte 0
        .4byte 0
        .4byte
   init__Q34Game12ItemTreasure11NormalStateFPQ34Game12ItemTreasure4ItemPQ24Game8StateArg
        .4byte
   exec__Q34Game12ItemTreasure11NormalStateFPQ34Game12ItemTreasure4Item .4byte
   cleanup__Q34Game12ItemTreasure11NormalStateFPQ34Game12ItemTreasure4Item
        .4byte
   "resume__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "restart__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "transit__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemiPQ24Game8StateArg"
        .4byte
   onDamage__Q34Game12ItemTreasure11NormalStateFPQ34Game12ItemTreasure4Itemf
        .4byte
   "onKeyEvent__Q24Game37ItemState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemRCQ28SysShape8KeyEvent"
        .4byte
   "onBounce__Q24Game37ItemState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemPQ23Sys8Triangle"
        .4byte
   "onPlatCollision__Q24Game37ItemState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemRQ24Game9PlatEvent"
        .4byte
   "onCollision__Q24Game37ItemState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemRQ24Game9CollEvent"
    .global __vt__Q34Game12ItemTreasure5State
    __vt__Q34Game12ItemTreasure5State:
        .4byte 0
        .4byte 0
        .4byte
   "init__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemPQ24Game8StateArg"
        .4byte
   "exec__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "cleanup__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "resume__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "restart__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "transit__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemiPQ24Game8StateArg"
        .4byte
   onDamage__Q34Game12ItemTreasure5StateFPQ34Game12ItemTreasure4Itemf .4byte
   "onKeyEvent__Q24Game37ItemState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemRCQ28SysShape8KeyEvent"
        .4byte
   "onBounce__Q24Game37ItemState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemPQ23Sys8Triangle"
        .4byte
   "onPlatCollision__Q24Game37ItemState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemRQ24Game9PlatEvent"
        .4byte
   "onCollision__Q24Game37ItemState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemRQ24Game9CollEvent"
    .global "__vt__Q24Game37ItemState<Q34Game12ItemTreasure4Item>"
    "__vt__Q24Game37ItemState<Q34Game12ItemTreasure4Item>":
        .4byte 0
        .4byte 0
        .4byte
   "init__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemPQ24Game8StateArg"
        .4byte
   "exec__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "cleanup__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "resume__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "restart__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "transit__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemiPQ24Game8StateArg"
        .4byte
   "onDamage__Q24Game37ItemState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Itemf"
        .4byte
   "onKeyEvent__Q24Game37ItemState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemRCQ28SysShape8KeyEvent"
        .4byte
   "onBounce__Q24Game37ItemState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemPQ23Sys8Triangle"
        .4byte
   "onPlatCollision__Q24Game37ItemState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemRQ24Game9PlatEvent"
        .4byte
   "onCollision__Q24Game37ItemState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemRQ24Game9CollEvent"
    .global "__vt__Q24Game36FSMState<Q34Game12ItemTreasure4Item>"
    "__vt__Q24Game36FSMState<Q34Game12ItemTreasure4Item>":
        .4byte 0
        .4byte 0
        .4byte
   "init__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemPQ24Game8StateArg"
        .4byte
   "exec__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "cleanup__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "resume__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "restart__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "transit__Q24Game36FSMState<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemiPQ24Game8StateArg"
    .global __vt__Q34Game12ItemTreasure3FSM
    __vt__Q34Game12ItemTreasure3FSM:
        .4byte 0
        .4byte 0
        .4byte init__Q34Game12ItemTreasure3FSMFPQ34Game12ItemTreasure4Item
        .4byte
   "start__Q24Game40StateMachine<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemiPQ24Game8StateArg"
        .4byte
   "exec__Q24Game40StateMachine<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4Item"
        .4byte
   "transit__Q24Game40StateMachine<Q34Game12ItemTreasure4Item>FPQ34Game12ItemTreasure4ItemiPQ24Game8StateArg"

    .section .sbss # 0x80514D80 - 0x80516360
    .global lbl_80515B48
    lbl_80515B48:
        .skip 0x4
    .global lbl_80515B4C
    lbl_80515B4C:
        .skip 0x4
    .global mgr__Q24Game12ItemTreasure
    mgr__Q24Game12ItemTreasure:
        .skip 0x8

    .section .sdata2, "a"     # 0x80516360 - 0x80520E40
    .global lbl_80519BD0
    lbl_80519BD0:
        .4byte 0x00000000
    .global lbl_80519BD4
    lbl_80519BD4:
        .float 0.25
    .global lbl_80519BD8
    lbl_80519BD8:
        .float 0.5
    .global lbl_80519BDC
    lbl_80519BDC:
        .4byte 0x47000000
    .global lbl_80519BE0
    lbl_80519BE0:
        .4byte 0x41200000
    .global lbl_80519BE4
    lbl_80519BE4:
        .4byte 0x43160000
    .global lbl_80519BE8
    lbl_80519BE8:
        .4byte 0x40400000
        .4byte 0x00000000
    .global lbl_80519BF0
    lbl_80519BF0:
        .4byte 0x43300000
        .4byte 0x80000000
    .global lbl_80519BF8
    lbl_80519BF8:
        .float 1.0
    .global lbl_80519BFC
    lbl_80519BFC:
        .4byte 0x40A00000
    .global lbl_80519C00
    lbl_80519C00:
        .4byte 0x3F400000
    .global lbl_80519C04
    lbl_80519C04:
        .4byte 0x3F59999A
    .global lbl_80519C08
    lbl_80519C08:
        .4byte 0x61636365
        .4byte 0x6C000000
    .global lbl_80519C10
    lbl_80519C10:
        .float 0.1
    .global lbl_80519C14
    lbl_80519C14:
        .4byte 0x3C23D70A
    .global lbl_80519C18
    lbl_80519C18:
        .4byte 0x40000000
    .global lbl_80519C1C
    lbl_80519C1C:
        .float 0.3
    .global lbl_80519C20
    lbl_80519C20:
        .4byte 0x437A0000
    .global lbl_80519C24
    lbl_80519C24:
        .4byte 0x476A6000
    .global lbl_80519C28
    lbl_80519C28:
        .4byte 0x443B8000
    .global lbl_80519C2C
    lbl_80519C2C:
        .4byte 0x44960000
    .global lbl_80519C30
    lbl_80519C30:
        .4byte 0x44BB8000
        .4byte 0x00000000
*/

namespace Game {

/*
 * --INFO--
 * Address:	801F316C
 * Size:	000084
 */
void ItemTreasure::FSM::init(Game::ItemTreasure::Item*)
{
	create(1);
	registerState(new NormalState);
}

/*
 * --INFO--
 * Address:	801F31F0
 * Size:	00000C
 */
void ItemTreasure::NormalState::init(Game::ItemTreasure::Item* item, Game::StateArg*) { item->m_animSpeed = 0.0f; }

/*
 * --INFO--
 * Address:	801F31FC
 * Size:	000004
 */
void ItemTreasure::NormalState::exec(Game::ItemTreasure::Item*) { }

/*
 * --INFO--
 * Address:	801F3200
 * Size:	000004
 */
void ItemTreasure::NormalState::cleanup(Game::ItemTreasure::Item*) { }

/*
 * --INFO--
 * Address:	801F3204
 * Size:	0003C8
 */
void ItemTreasure::NormalState::onDamage(Game::ItemTreasure::Item* item, f32 damage)
{
	if (gameSystem->m_flags & GAMESYS_Unk6 && gameSystem->m_mode == GSM_STORY_MODE && !playData->isDemoFlag(DEMO_Whites_Digging)) {
		f32 depth = item->m_pellet->getBuryDepth();
		f32 max   = item->m_pellet->getBuryDepthMax();
		// float == float? :rock eyebrow:
		if (depth == max) {
			playData->setDemoFlag(DEMO_Whites_Digging);
			MoviePlayArg arg("x14_white_dig", nullptr, nullptr, 0);
			Iterator<Piki> itPiki(pikiMgr);
			CI_LOOP(itPiki)
			{
				Piki* piki = *itPiki;
				if ((int)piki->m_pikiKind == White) {
					piki->movie_begin(false);
				}
			}
			item->movie_begin(false);
			arg.m_origin                = item->m_pellet->getPosition();
			arg.m_angle                 = item->m_pellet->getFaceDir();
			moviePlayer->m_targetObject = item->m_pellet;
			moviePlayer->play(arg);
		}
	}

	item->m_instantDamage += damage;
	item->m_currStageLife -= item->m_instantDamage;
	item->m_instantDamage = 0.0f;

	f32 maxlife  = item->getCurrMaxLife();
	f32 depthmax = item->m_pellet->getBuryDepthMax();

	item->m_totalLife = -((depthmax * 0.25f) * (damage / maxlife) - item->m_totalLife);

	if (item->m_currStageLife <= 0.0f) {
		item->m_soundObj->startSound(PSSE_EV_TREASURE_RISE_UP, 0);
		item->setLife();
	}

	if (item->m_totalLife <= 0.0f) {
		item->m_totalLife = 0.0f;
		item->releasePellet();
	}

	/*
	stwu     r1, -0x80(r1)
	mflr     r0
	stw      r0, 0x84(r1)
	stfd     f31, 0x70(r1)
	psq_st   f31, 120(r1), 0, qr0
	stfd     f30, 0x60(r1)
	psq_st   f30, 104(r1), 0, qr0
	stw      r31, 0x5c(r1)
	lwz      r3, gameSystem__4Game@sda21(r13)
	fmr      f30, f1
	mr       r31, r4
	lbz      r0, 0x3c(r3)
	rlwinm.  r0, r0, 0, 0x1a, 0x1a
	beq      lbl_801F3500
	lwz      r0, 0x44(r3)
	cmpwi    r0, 0
	bne      lbl_801F3500
	lwz      r3, playData__4Game@sda21(r13)
	li       r4, 0x2d
	bl       isDemoFlag__Q24Game8PlayDataFi
	clrlwi.  r0, r3, 0x18
	bne      lbl_801F3500
	lwz      r3, 0x1fc(r31)
	bl       getBuryDepth__Q24Game6PelletFv
	fmr      f31, f1
	lwz      r3, 0x1fc(r31)
	bl       getBuryDepthMax__Q24Game6PelletFv
	fcmpu    cr0, f1, f31
	bne      lbl_801F3500
	lwz      r3, playData__4Game@sda21(r13)
	li       r4, 0x2d
	bl       setDemoFlag__Q24Game8PlayDataFi
	li       r5, 0
	lfs      f0, lbl_80519BD0@sda21(r2)
	lwz      r3, pikiMgr__4Game@sda21(r13)
	lis      r6, lbl_804816D4@ha
	lis      r4, "__vt__22Iterator<Q24Game4Piki>"@ha
	cmplwi   r5, 0
	addi     r6, r6, lbl_804816D4@l
	stw      r5, 0x28(r1)
	addi     r0, r4, "__vt__22Iterator<Q24Game4Piki>"@l
	stw      r6, 0x24(r1)
	stw      r5, 0x30(r1)
	stfs     f0, 0x3c(r1)
	stfs     f0, 0x40(r1)
	stfs     f0, 0x44(r1)
	stfs     f0, 0x48(r1)
	stw      r5, 0x4c(r1)
	stw      r5, 0x34(r1)
	stw      r5, 0x2c(r1)
	stw      r5, 0x50(r1)
	stw      r5, 0x38(r1)
	stw      r5, 0x54(r1)
	stw      r0, 0x14(r1)
	stw      r5, 0x20(r1)
	stw      r5, 0x18(r1)
	stw      r3, 0x1c(r1)
	bne      lbl_801F3304
	lwz      r12, 0(r3)
	lwz      r12, 0x18(r12)
	mtctr    r12
	bctrl
	stw      r3, 0x18(r1)
	b        lbl_801F3474

lbl_801F3304:
	lwz      r12, 0(r3)
	lwz      r12, 0x18(r12)
	mtctr    r12
	bctrl
	stw      r3, 0x18(r1)
	b        lbl_801F3370

lbl_801F331C:
	lwz      r3, 0x1c(r1)
	lwz      r4, 0x18(r1)
	lwz      r12, 0(r3)
	lwz      r12, 0x20(r12)
	mtctr    r12
	bctrl
	mr       r4, r3
	lwz      r3, 0x20(r1)
	lwz      r12, 0(r3)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_801F3474
	lwz      r3, 0x1c(r1)
	lwz      r4, 0x18(r1)
	lwz      r12, 0(r3)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	stw      r3, 0x18(r1)

lbl_801F3370:
	lwz      r12, 0x14(r1)
	addi     r3, r1, 0x14
	lwz      r12, 0x10(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_801F331C
	b        lbl_801F3474

lbl_801F3390:
	lwz      r3, 0x1c(r1)
	lwz      r12, 0(r3)
	lwz      r12, 0x20(r12)
	mtctr    r12
	bctrl
	lbz      r0, 0x2b8(r3)
	cmpwi    r0, 4
	bne      lbl_801F33B8
	li       r4, 0
	bl       movie_begin__Q24Game8CreatureFb

lbl_801F33B8:
	lwz      r0, 0x20(r1)
	cmplwi   r0, 0
	bne      lbl_801F33E4
	lwz      r3, 0x1c(r1)
	lwz      r4, 0x18(r1)
	lwz      r12, 0(r3)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	stw      r3, 0x18(r1)
	b        lbl_801F3474

lbl_801F33E4:
	lwz      r3, 0x1c(r1)
	lwz      r4, 0x18(r1)
	lwz      r12, 0(r3)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	stw      r3, 0x18(r1)
	b        lbl_801F3458

lbl_801F3404:
	lwz      r3, 0x1c(r1)
	lwz      r4, 0x18(r1)
	lwz      r12, 0(r3)
	lwz      r12, 0x20(r12)
	mtctr    r12
	bctrl
	mr       r4, r3
	lwz      r3, 0x20(r1)
	lwz      r12, 0(r3)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_801F3474
	lwz      r3, 0x1c(r1)
	lwz      r4, 0x18(r1)
	lwz      r12, 0(r3)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	stw      r3, 0x18(r1)

lbl_801F3458:
	lwz      r12, 0x14(r1)
	addi     r3, r1, 0x14
	lwz      r12, 0x10(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_801F3404

lbl_801F3474:
	lwz      r3, 0x1c(r1)
	lwz      r12, 0(r3)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	lwz      r4, 0x18(r1)
	cmplw    r4, r3
	bne      lbl_801F3390
	mr       r3, r31
	li       r4, 0
	bl       movie_begin__Q24Game8CreatureFb
	lwz      r4, 0x1fc(r31)
	addi     r3, r1, 8
	lwz      r12, 0(r4)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	lfs      f2, 8(r1)
	lfs      f1, 0xc(r1)
	lfs      f0, 0x10(r1)
	stfs     f2, 0x3c(r1)
	stfs     f1, 0x40(r1)
	stfs     f0, 0x44(r1)
	lwz      r3, 0x1fc(r31)
	lwz      r12, 0(r3)
	lwz      r12, 0x64(r12)
	mtctr    r12
	bctrl
	stfs     f1, 0x48(r1)
	addi     r4, r1, 0x24
	lwz      r3, moviePlayer__4Game@sda21(r13)
	lwz      r0, 0x1fc(r31)
	stw      r0, 0x194(r3)
	lwz      r3, moviePlayer__4Game@sda21(r13)
	bl       play__Q24Game11MoviePlayerFRQ24Game12MoviePlayArg

lbl_801F3500:
	lfs      f1, 0x230(r31)
	mr       r3, r31
	lfs      f0, lbl_80519BD0@sda21(r2)
	fadds    f1, f1, f30
	stfs     f1, 0x230(r31)
	lfs      f2, 0x1f4(r31)
	lfs      f1, 0x230(r31)
	fsubs    f1, f2, f1
	stfs     f1, 0x1f4(r31)
	stfs     f0, 0x230(r31)
	bl       getCurrMaxLife__Q34Game12ItemTreasure4ItemFv
	fmr      f31, f1
	lwz      r3, 0x1fc(r31)
	bl       getBuryDepthMax__Q24Game6PelletFv
	fdivs    f3, f30, f31
	lfs      f4, lbl_80519BD4@sda21(r2)
	lfs      f2, 0x1f8(r31)
	lfs      f0, lbl_80519BD0@sda21(r2)
	fmuls    f1, f4, f1
	fnmsubs  f1, f1, f3, f2
	stfs     f1, 0x1f8(r31)
	lfs      f1, 0x1f4(r31)
	fcmpo    cr0, f1, f0
	cror     2, 0, 2
	bne      lbl_801F3588
	lwz      r3, 0x17c(r31)
	li       r4, 0x3832
	li       r5, 0
	lwz      r12, 0x28(r3)
	lwz      r12, 0x7c(r12)
	mtctr    r12
	bctrl
	mr       r3, r31
	bl       setLife__Q34Game12ItemTreasure4ItemFv

lbl_801F3588:
	lfs      f1, 0x1f8(r31)
	lfs      f0, lbl_80519BD0@sda21(r2)
	fcmpo    cr0, f1, f0
	cror     2, 0, 2
	bne      lbl_801F35A8
	stfs     f0, 0x1f8(r31)
	mr       r3, r31
	bl       releasePellet__Q34Game12ItemTreasure4ItemFv

lbl_801F35A8:
	psq_l    f31, 120(r1), 0, qr0
	lfd      f31, 0x70(r1)
	psq_l    f30, 104(r1), 0, qr0
	lfd      f30, 0x60(r1)
	lwz      r0, 0x84(r1)
	lwz      r31, 0x5c(r1)
	mtlr     r0
	addi     r1, r1, 0x80
	blr
	*/
}

/*
 * --INFO--
 * Address:	801F35CC
 * Size:	000298
 */
void ItemTreasure::Item::releasePellet()
{
	if (m_pellet) {
		m_pellet->endCapture();
		TexCaster::Caster* caster = m_pellet->m_caster;
		if (caster) {
			caster->fadein(0.5f);
		}

		f32 scale                   = m_pellet->getPickRadius();
		volatile Vector3f pelletpos = m_position;

		::efx::TOtakaraAp efx;
		::efx::ArgScale arg(m_position, scale);
		efx.create(&arg);

		m_soundObj->startSound(PSSE_EV_TREASURE_JUMP_OUT, 0);

		Vector3f velocity;
		velocity.x = (randFloat() - 0.5f) * 10.0f;
		velocity.y = 15.0;
		velocity.z = (randFloat() - 0.5f) * 10.0f;
		m_pellet->setVelocity(velocity);

		if (gameSystem->m_mode == GSM_VERSUS_MODE) {
			f32 test = randFloat() * 3.0f;
			GameMessageVsBirthTekiTreasure mesg;
			mesg.m_position = m_pellet->m_pelletPosition;
			mesg._14        = false;
			mesg._10        = (int)test + 1;
			gameSystem->m_section->sendMessage(mesg);
		}

		m_soundEvent.finish();
		P2ASSERTLINE(327, m_soundObj->getCastType() == 10);
		m_soundObj->disable();
		setAlive(false);
		m_pellet = nullptr;
	}
	/*
	stwu     r1, -0x70(r1)
	mflr     r0
	stw      r0, 0x74(r1)
	stw      r31, 0x6c(r1)
	mr       r31, r3
	lwz      r3, 0x1fc(r3)
	cmplwi   r3, 0
	beq      lbl_801F3850
	bl       endCapture__Q24Game8CreatureFv
	lwz      r3, 0x1fc(r31)
	lwz      r3, 0x328(r3)
	cmplwi   r3, 0
	beq      lbl_801F3608
	lfs      f1, lbl_80519BD8@sda21(r2)
	bl       fadein__Q29TexCaster6CasterFf

lbl_801F3608:
	lwz      r3, 0x1fc(r31)
	bl       getPickRadius__Q24Game6PelletFv
	lwz      r5, 0x19c(r31)
	lis      r4, __vt__Q23efx3Arg@ha
	lwz      r0, 0x1a0(r31)
	lis      r3, __vt__Q23efx5TBase@ha
	lwz      r8, 0x1a4(r31)
	addi     r7, r4, __vt__Q23efx3Arg@l
	stw      r5, 0xc(r1)
	addi     r5, r3, __vt__Q23efx5TBase@l
	lis      r4, __vt__Q23efx8ArgScale@ha
	lis      r3, __vt__Q23efx10TOtakaraAp@ha
	stw      r0, 0x10(r1)
	addi     r6, r4, __vt__Q23efx8ArgScale@l
	lfs      f3, 0xc(r1)
	addi     r0, r3, __vt__Q23efx10TOtakaraAp@l
	stw      r8, 0x14(r1)
	addi     r3, r1, 8
	lfs      f2, 0x10(r1)
	addi     r4, r1, 0x3c
	stw      r7, 0x3c(r1)
	lfs      f0, 0x14(r1)
	stw      r5, 8(r1)
	stfs     f3, 0x40(r1)
	stfs     f2, 0x44(r1)
	stfs     f0, 0x48(r1)
	stw      r6, 0x3c(r1)
	stfs     f1, 0x4c(r1)
	stw      r0, 8(r1)
	bl       create__Q23efx10TOtakaraApFPQ23efx3Arg
	lwz      r3, 0x17c(r31)
	li       r4, 0x3833
	li       r5, 0
	lwz      r12, 0x28(r3)
	lwz      r12, 0x7c(r12)
	mtctr    r12
	bctrl
	bl       rand
	xoris    r3, r3, 0x8000
	lis      r0, 0x4330
	stw      r3, 0x54(r1)
	lfd      f3, lbl_80519BF0@sda21(r2)
	stw      r0, 0x50(r1)
	lfs      f2, lbl_80519BDC@sda21(r2)
	lfd      f1, 0x50(r1)
	lfs      f0, lbl_80519BD8@sda21(r2)
	fsubs    f3, f1, f3
	lfs      f1, lbl_80519BE0@sda21(r2)
	fdivs    f2, f3, f2
	fsubs    f0, f2, f0
	fmuls    f0, f1, f0
	stfs     f0, 0x18(r1)
	bl       rand
	xoris    r3, r3, 0x8000
	lis      r0, 0x4330
	stw      r3, 0x5c(r1)
	addi     r4, r1, 0x18
	lfs      f0, lbl_80519BE4@sda21(r2)
	stw      r0, 0x58(r1)
	lfd      f2, lbl_80519BF0@sda21(r2)
	lfd      f1, 0x58(r1)
	lfs      f3, lbl_80519BDC@sda21(r2)
	fsubs    f4, f1, f2
	lfs      f1, lbl_80519BD8@sda21(r2)
	lfs      f2, lbl_80519BE0@sda21(r2)
	stfs     f0, 0x1c(r1)
	fdivs    f0, f4, f3
	fsubs    f0, f0, f1
	fmuls    f0, f2, f0
	stfs     f0, 0x20(r1)
	lwz      r3, 0x1fc(r31)
	lwz      r12, 0(r3)
	lwz      r12, 0x68(r12)
	mtctr    r12
	bctrl
	lwz      r3, gameSystem__4Game@sda21(r13)
	lwz      r0, 0x44(r3)
	cmpwi    r0, 1
	bne      lbl_801F37DC
	bl       rand
	xoris    r3, r3, 0x8000
	lis      r0, 0x4330
	stw      r3, 0x5c(r1)
	lis      r3, __vt__Q24Game11GameMessage@ha
	addi     r5, r3, __vt__Q24Game11GameMessage@l
	lis      r3, __vt__Q24Game30GameMessageVsBirthTekiTreasure@ha
	stw      r0, 0x58(r1)
	addi     r3, r3, __vt__Q24Game30GameMessageVsBirthTekiTreasure@l
	lfd      f2, lbl_80519BF0@sda21(r2)
	li       r0, 0
	lfd      f0, 0x58(r1)
	addi     r4, r1, 0x24
	lfs      f1, lbl_80519BDC@sda21(r2)
	fsubs    f2, f0, f2
	stw      r5, 0x24(r1)
	lfs      f0, lbl_80519BE8@sda21(r2)
	stw      r3, 0x24(r1)
	fdivs    f2, f2, f1
	lwz      r3, gameSystem__4Game@sda21(r13)
	lfs      f1, 0x19c(r31)
	stfs     f1, 0x28(r1)
	lfs      f1, 0x1a0(r31)
	stfs     f1, 0x2c(r1)
	fmuls    f0, f0, f2
	lfs      f1, 0x1a4(r31)
	stfs     f1, 0x30(r1)
	fctiwz   f0, f0
	stb      r0, 0x38(r1)
	stfd     f0, 0x50(r1)
	lwz      r5, 0x54(r1)
	addi     r0, r5, 1
	stw      r0, 0x34(r1)
	lwz      r3, 0x58(r3)
	lwz      r12, 0(r3)
	lwz      r12, 0x50(r12)
	mtctr    r12
	bctrl

lbl_801F37DC:
	addi     r3, r31, 0x1e0
	bl       finish__Q24Game11TSoundEventFv
	lwz      r3, 0x17c(r31)
	lwz      r12, 0x28(r3)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	cmpwi    r3, 0xa
	beq      lbl_801F381C
	lis      r3, lbl_804816E4@ha
	lis      r5, lbl_804816F8@ha
	addi     r3, r3, lbl_804816E4@l
	li       r4, 0x147
	addi     r5, r5, lbl_804816F8@l
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_801F381C:
	lwz      r3, 0x17c(r31)
	lwz      r12, 0x28(r3)
	lwz      r12, 0x94(r12)
	mtctr    r12
	bctrl
	mr       r3, r31
	li       r4, 0
	lwz      r12, 0(r31)
	lwz      r12, 0xac(r12)
	mtctr    r12
	bctrl
	li       r0, 0
	stw      r0, 0x1fc(r31)

lbl_801F3850:
	lwz      r0, 0x74(r1)
	lwz      r31, 0x6c(r1)
	mtlr     r0
	addi     r1, r1, 0x70
	blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00010C
 */
ItemTreasure::Item::Item()
    : WorkItem(OBJTYPE_Treasure)
{
	m_mass                = 0.0f;
	m_dummyShape.m_matrix = &m_objMatrix;
	m_pellet              = nullptr;
}

/*
 * --INFO--
 * Address:	801F3864
 * Size:	000048
 */
void ItemTreasure::Item::constructor() { m_soundObj = new PSM::WorkItem(this); }

/*
 * --INFO--
 * Address:	801F38AC
 * Size:	000080
 */
void ItemTreasure::Item::onInit(Game::CreatureInitArg*)
{
	m_model = nullptr;
	m_fsm->start(this, 0, nullptr);
	setAlive(true);
	m_collTree->createSingleSphere(&m_dummyShape, 0, m_boundingSphere, nullptr);
}

/*
 * --INFO--
 * Address:	801F392C
 * Size:	000034
 */
void StateMachine<Game::ItemTreasure::Item>::start(ItemTreasure::Item* item, int id, StateArg* arg)
{
	item->m_currentState = nullptr;
	transit(item, id, arg);
}

/*
 * --INFO--
 * Address:	801F3960
 * Size:	000044
 */
void ItemTreasure::Item::onSetPosition()
{
	updateBoundSphere();
	m_objMatrix.makeT(m_position);
}

/*
 * --INFO--
 * Address:	801F39A4
 * Size:	000048
 */
void ItemTreasure::Item::updateBoundSphere()
{
	f32 rad                     = getWorkRadius();
	m_boundingSphere.m_position = m_position;
	m_boundingSphere.m_radius   = rad;
}

/*
 * --INFO--
 * Address:	801F39EC
 * Size:	000180
 */
void ItemTreasure::Item::doAI()
{
	m_fsm->exec(this);
	m_boundingSphere.m_radius = getWorkRadius();
	updateCollTree();
	CollPart* part = m_collTree->m_part;
	part->m_radius = getWorkRadius();

	if (m_pellet) {
		f32 depth = (m_pellet->getBuryDepthMax() * 0.5f) - m_totalLife;

		Matrixf mtx;
		PSMTXCopy(m_pellet->m_objMatrix.m_matrix.mtxView, mtx.m_matrix.mtxView);
		mtx.m_matrix.structView.ty = depth;
		mtx.m_matrix.structView.tx = 0.0f;
		mtx.m_matrix.structView.tz = 0.0f;
		m_pellet->updateCapture(mtx);

		if (m_pellet->getBuryDepthMax() >= m_totalLife) {
			m_pellet->m_lod.m_flags &= -0x35;
		}
		m_pellet->m_depth = m_totalLife;
	}

	if (isAlive()) {
		int state = m_soundEvent.update();
		switch (state) {
		case 2:
			P2ASSERTLINE(406, m_soundObj->getCastType() == 10);
			m_soundObj->exec();
			break;
		}
	}
	/*
	stwu     r1, -0x50(r1)
	mflr     r0
	stw      r0, 0x54(r1)
	stfd     f31, 0x40(r1)
	psq_st   f31, 72(r1), 0, qr0
	stw      r31, 0x3c(r1)
	stw      r30, 0x38(r1)
	mr       r30, r3
	lwz      r3, 0x1d8(r3)
	mr       r4, r30
	lwz      r12, 0(r3)
	lwz      r12, 0x10(r12)
	mtctr    r12
	bctrl
	mr       r3, r30
	bl       getWorkRadius__Q34Game12ItemTreasure4ItemFv
	stfs     f1, 0x1d0(r30)
	mr       r3, r30
	bl       updateCollTree__Q24Game8BaseItemFv
	lwz      r4, 0x114(r30)
	mr       r3, r30
	lwz      r31, 0(r4)
	bl       getWorkRadius__Q34Game12ItemTreasure4ItemFv
	stfs     f1, 0x1c(r31)
	lwz      r3, 0x1fc(r30)
	cmplwi   r3, 0
	beq      lbl_801F3AD0
	bl       getBuryDepthMax__Q24Game6PelletFv
	lfs      f0, lbl_80519BD8@sda21(r2)
	addi     r4, r1, 8
	lwz      r3, 0x1fc(r30)
	fmuls    f1, f0, f1
	lfs      f0, 0x1f8(r30)
	addi     r3, r3, 0x138
	fsubs    f31, f1, f0
	bl       PSMTXCopy
	lfs      f0, lbl_80519BD0@sda21(r2)
	addi     r4, r1, 8
	stfs     f31, 0x24(r1)
	stfs     f0, 0x14(r1)
	stfs     f0, 0x34(r1)
	lwz      r3, 0x1fc(r30)
	bl       updateCapture__Q24Game8CreatureFR7Matrixf
	lwz      r3, 0x1fc(r30)
	bl       getBuryDepthMax__Q24Game6PelletFv
	lfs      f0, 0x1f8(r30)
	fcmpo    cr0, f0, f1
	cror     2, 1, 2
	bne      lbl_801F3AC4
	lwz      r4, 0x1fc(r30)
	li       r0, -53
	lbz      r3, 0xd8(r4)
	and      r0, r3, r0
	stb      r0, 0xd8(r4)

lbl_801F3AC4:
	lfs      f0, 0x1f8(r30)
	lwz      r3, 0x1fc(r30)
	stfs     f0, 0x320(r3)

lbl_801F3AD0:
	mr       r3, r30
	lwz      r12, 0(r30)
	lwz      r12, 0xa8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_801F3B4C
	addi     r3, r30, 0x1e0
	bl       update__Q24Game11TSoundEventFv
	cmpwi    r3, 2
	beq      lbl_801F3B00
	b        lbl_801F3B4C

lbl_801F3B00:
	lwz      r3, 0x17c(r30)
	lwz      r12, 0x28(r3)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	cmpwi    r3, 0xa
	beq      lbl_801F3B38
	lis      r3, lbl_804816E4@ha
	lis      r5, lbl_804816F8@ha
	addi     r3, r3, lbl_804816E4@l
	li       r4, 0x196
	addi     r5, r5, lbl_804816F8@l
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_801F3B38:
	lwz      r3, 0x17c(r30)
	lwz      r12, 0x28(r3)
	lwz      r12, 0x90(r12)
	mtctr    r12
	bctrl

lbl_801F3B4C:
	psq_l    f31, 72(r1), 0, qr0
	lwz      r0, 0x54(r1)
	lfd      f31, 0x40(r1)
	lwz      r31, 0x3c(r1)
	lwz      r30, 0x38(r1)
	mtlr     r0
	addi     r1, r1, 0x50
	blr
	*/
}

/*
 * --INFO--
 * Address:	801F3B6C
 * Size:	000050
 */
void ItemTreasure::Item::doDirectDraw(Graphics& gfx)
{
	gfx.initPrimDraw(nullptr);
	gfx.drawSphere(m_boundingSphere.m_position, m_boundingSphere.m_radius);
}

/*
 * --INFO--
 * Address:	801F3BBC
 * Size:	00011C
 */
bool ItemTreasure::Item::getVectorField(Sys::Sphere& bounds, Vector3f& pos)
{
	Vector3f diff = m_position - bounds.m_position;
	f32 dist      = diff.normalise();
	if (dist > getWorkRadius() + 5.0f) {
		pos = diff;
	} else {
		pos = Vector3f(0.0f);
	}
	return true;
	/*
	stwu     r1, -0x50(r1)
	mflr     r0
	stw      r0, 0x54(r1)
	stfd     f31, 0x40(r1)
	psq_st   f31, 72(r1), 0, qr0
	stfd     f30, 0x30(r1)
	psq_st   f30, 56(r1), 0, qr0
	stfd     f29, 0x20(r1)
	psq_st   f29, 40(r1), 0, qr0
	stfd     f28, 0x10(r1)
	psq_st   f28, 24(r1), 0, qr0
	stw      r31, 0xc(r1)
	lfs      f0, 4(r4)
	mr       r31, r5
	lfs      f1, 0x1a0(r3)
	lfs      f3, 0x1a4(r3)
	fsubs    f31, f1, f0
	lfs      f2, 8(r4)
	lfs      f1, 0x19c(r3)
	fsubs    f28, f3, f2
	lfs      f0, 0(r4)
	fmuls    f2, f31, f31
	fsubs    f29, f1, f0
	lfs      f0, lbl_80519BD0@sda21(r2)
	fmuls    f3, f28, f28
	fmadds   f1, f29, f29, f2
	fadds    f30, f3, f1
	fcmpo    cr0, f30, f0
	ble      lbl_801F3C40
	ble      lbl_801F3C44
	frsqrte  f0, f30
	fmuls    f30, f0, f30
	b        lbl_801F3C44

lbl_801F3C40:
	fmr      f30, f0

lbl_801F3C44:
	lfs      f0, lbl_80519BD0@sda21(r2)
	fcmpo    cr0, f30, f0
	ble      lbl_801F3C68
	lfs      f0, lbl_80519BF8@sda21(r2)
	fdivs    f0, f0, f30
	fmuls    f29, f29, f0
	fmuls    f31, f31, f0
	fmuls    f28, f28, f0
	b        lbl_801F3C6C

lbl_801F3C68:
	fmr      f30, f0

lbl_801F3C6C:
	bl       getWorkRadius__Q34Game12ItemTreasure4ItemFv
	lfs      f0, lbl_80519BFC@sda21(r2)
	fadds    f0, f0, f1
	fcmpo    cr0, f30, f0
	ble      lbl_801F3C90
	stfs     f29, 0(r31)
	stfs     f31, 4(r31)
	stfs     f28, 8(r31)
	b        lbl_801F3CA0

lbl_801F3C90:
	lfs      f0, lbl_80519BD0@sda21(r2)
	stfs     f0, 0(r31)
	stfs     f0, 4(r31)
	stfs     f0, 8(r31)

lbl_801F3CA0:
	li       r3, 1
	psq_l    f31, 72(r1), 0, qr0
	lfd      f31, 0x40(r1)
	psq_l    f30, 56(r1), 0, qr0
	lfd      f30, 0x30(r1)
	psq_l    f29, 40(r1), 0, qr0
	lfd      f29, 0x20(r1)
	psq_l    f28, 24(r1), 0, qr0
	lfd      f28, 0x10(r1)
	lwz      r0, 0x54(r1)
	lwz      r31, 0xc(r1)
	mtlr     r0
	addi     r1, r1, 0x50
	blr
	*/
}

/*
 * --INFO--
 * Address:	801F3CD8
 * Size:	000088
 */
f32 ItemTreasure::Item::getWorkDistance(Sys::Sphere& bounds)
{
	f32 dist = _distanceBetween2(m_position, bounds.m_position);
	return dist - getWorkRadius();
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	stw      r0, 0x24(r1)
	stfd     f31, 0x10(r1)
	psq_st   f31, 24(r1), 0, qr0
	lfs      f0, 4(r4)
	lfs      f1, 0x1a0(r3)
	lfs      f3, 0x1a4(r3)
	fsubs    f4, f1, f0
	lfs      f2, 8(r4)
	lfs      f1, 0x19c(r3)
	fsubs    f2, f3, f2
	lfs      f0, 0(r4)
	fmuls    f3, f4, f4
	fsubs    f1, f1, f0
	lfs      f0, lbl_80519BD0@sda21(r2)
	fmuls    f2, f2, f2
	fmadds   f1, f1, f1, f3
	fadds    f31, f2, f1
	fcmpo    cr0, f31, f0
	ble      lbl_801F3D3C
	ble      lbl_801F3D40
	frsqrte  f0, f31
	fmuls    f31, f0, f31
	b        lbl_801F3D40

lbl_801F3D3C:
	fmr      f31, f0

lbl_801F3D40:
	bl       getWorkRadius__Q34Game12ItemTreasure4ItemFv
	fsubs    f1, f31, f1
	psq_l    f31, 24(r1), 0, qr0
	lwz      r0, 0x24(r1)
	lfd      f31, 0x10(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	801F3D60
 * Size:	0000B8
 */
void ItemTreasure::Item::setTreasure(Game::Pellet* pelt)
{
	Vector3f pos = m_position;
	m_matrix.makeT(pos);
	m_pellet = pelt;
	if (m_pellet) {
		m_pellet->startCapture(&m_matrix);
		m_totalLife = m_pellet->getBuryDepth();
		if (gameSystem->m_mode == GSM_VERSUS_MODE && m_pellet->m_pelletFlag == Pellet::FLAG_VS_BEDAMA_YELLOW) {
			m_totalLife = VsOtakaraName::cBedamaYellowDepth;
		}
		m_pellet->m_depth = m_totalLife;
		setLife();
	}
}

/*
 * --INFO--
 * Address:	801F3E18
 * Size:	000030
 */
void ItemTreasure::Item::setLife() { m_currStageLife = getCurrMaxLife(); }

/*
 * --INFO--
 * Address:	801F3E48
 * Size:	000098
 */
f32 ItemTreasure::Item::getCurrMaxLife()
{
	f32 depth = m_pellet->getBuryDepthMax();
	f32 test  = m_totalLife / depth;

	if (test < 0.25f) {
		return mgr->m_parameters->m_parms.m_p003.m_value;
	} else if (test < 0.5f) {
		return mgr->m_parameters->m_parms.m_p002.m_value;
	} else if (test < 0.75f) {
		return mgr->m_parameters->m_parms.m_p001.m_value;
	} else {
		return mgr->m_parameters->m_parms.m_p000.m_value;
	}
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	mr       r31, r3
	lwz      r3, 0x1fc(r3)
	bl       getBuryDepthMax__Q24Game6PelletFv
	lfs      f2, 0x1f8(r31)
	lfs      f0, lbl_80519BD4@sda21(r2)
	fdivs    f1, f2, f1
	fcmpo    cr0, f1, f0
	bge      lbl_801F3E88
	lwz      r3, mgr__Q24Game12ItemTreasure@sda21(r13)
	lwz      r3, 0x88(r3)
	lfs      f1, 0x178(r3)
	b        lbl_801F3ECC

lbl_801F3E88:
	lfs      f0, lbl_80519BD8@sda21(r2)
	fcmpo    cr0, f1, f0
	bge      lbl_801F3EA4
	lwz      r3, mgr__Q24Game12ItemTreasure@sda21(r13)
	lwz      r3, 0x88(r3)
	lfs      f1, 0x150(r3)
	b        lbl_801F3ECC

lbl_801F3EA4:
	lfs      f0, lbl_80519C00@sda21(r2)
	fcmpo    cr0, f1, f0
	bge      lbl_801F3EC0
	lwz      r3, mgr__Q24Game12ItemTreasure@sda21(r13)
	lwz      r3, 0x88(r3)
	lfs      f1, 0x128(r3)
	b        lbl_801F3ECC

lbl_801F3EC0:
	lwz      r3, mgr__Q24Game12ItemTreasure@sda21(r13)
	lwz      r3, 0x88(r3)
	lfs      f1, 0x100(r3)

lbl_801F3ECC:
	lwz      r0, 0x14(r1)
	lwz      r31, 0xc(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000144
 */
void ItemTreasure::Item::createTreasure()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F3EE0
 * Size:	00011C
 */
bool ItemTreasure::Item::interactAttack(Game::InteractAttack& act)
{
	State* cState = m_currentState;
	if (cState) {
		cState->onDamage(this, act.m_damage);

		int id = m_soundEvent.event();
		switch (id) {
		case 1:
			P2ASSERTLINE(555, m_soundObj->getCastType() == 10);
			m_soundObj->exec();
			break;
		case 3:
			P2ASSERTLINE(561, m_soundObj->getCastType() == 10);
			m_soundObj->exec();
			break;
		}
	}
	return true;
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	mr       r5, r4
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	mr       r31, r3
	lwz      r3, 0x1dc(r3)
	cmplwi   r3, 0
	beq      lbl_801F3FE4
	lwz      r12, 0(r3)
	mr       r4, r31
	lfs      f1, 8(r5)
	lwz      r12, 0x20(r12)
	mtctr    r12
	bctrl
	addi     r3, r31, 0x1e0
	bl       event__Q24Game11TSoundEventFv
	cmpwi    r3, 2
	beq      lbl_801F3FE4
	bge      lbl_801F3F3C
	cmpwi    r3, 1
	bge      lbl_801F3F48
	b        lbl_801F3FE4

lbl_801F3F3C:
	cmpwi    r3, 4
	bge      lbl_801F3FE4
	b        lbl_801F3F98

lbl_801F3F48:
	lwz      r3, 0x17c(r31)
	lwz      r12, 0x28(r3)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	cmpwi    r3, 0xa
	beq      lbl_801F3F80
	lis      r3, lbl_804816E4@ha
	lis      r5, lbl_804816F8@ha
	addi     r3, r3, lbl_804816E4@l
	li       r4, 0x22b
	addi     r5, r5, lbl_804816F8@l
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_801F3F80:
	lwz      r3, 0x17c(r31)
	lwz      r12, 0x28(r3)
	lwz      r12, 0x88(r12)
	mtctr    r12
	bctrl
	b        lbl_801F3FE4

lbl_801F3F98:
	lwz      r3, 0x17c(r31)
	lwz      r12, 0x28(r3)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	cmpwi    r3, 0xa
	beq      lbl_801F3FD0
	lis      r3, lbl_804816E4@ha
	lis      r5, lbl_804816F8@ha
	addi     r3, r3, lbl_804816E4@l
	li       r4, 0x231
	addi     r5, r5, lbl_804816F8@l
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_801F3FD0:
	lwz      r3, 0x17c(r31)
	lwz      r12, 0x28(r3)
	lwz      r12, 0x8c(r12)
	mtctr    r12
	bctrl

lbl_801F3FE4:
	lwz      r0, 0x14(r1)
	li       r3, 1
	lwz      r31, 0xc(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	801F3FFC
 * Size:	000004
 */
void ItemTreasure::State::onDamage(Game::ItemTreasure::Item*, float) { }

/*
 * --INFO--
 * Address:	801F4000
 * Size:	000058
 */
f32 ItemTreasure::Item::getWorkRadius()
{
	if (!m_pellet) {
		return 10.0f;
	}

	return m_pellet->getBuryRadius(1.0f - m_totalLife / m_pellet->getBuryDepthMax());
}

/*
 * --INFO--
 * Address:	801F4058
 * Size:	000060
 */
bool ItemTreasure::Item::isVisible()
{
	// TODO: probably straight returns and NOT bool
	bool visible;

	if (!m_pellet) {
		visible = false;
	} else {
		visible = (m_totalLife / m_pellet->getBuryDepthMax() > 0.85f);
	}

	return visible;
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	mr       r31, r3
	lwz      r3, 0x1fc(r3)
	cmplwi   r3, 0
	bne      lbl_801F4080
	li       r3, 0
	b        lbl_801F40A4

lbl_801F4080:
	bl       getBuryDepthMax__Q24Game6PelletFv
	lfs      f2, 0x1f8(r31)
	lfs      f0, lbl_80519C04@sda21(r2)
	fdivs    f1, f2, f1
	fcmpo    cr0, f1, f0
	mfcr     r0
	rlwinm   r0, r0, 2, 0x1f, 0x1f
	cntlzw   r0, r0
	srwi     r3, r0, 5

lbl_801F40A4:
	lwz      r0, 0x14(r1)
	lwz      r31, 0xc(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	801F40B8
 * Size:	0000B0
 */
bool ItemTreasure::Item::ignoreAtari(Game::Creature* obj)
{
	// inline isVisible? <-- yep probably
	bool visible;
	if (!m_pellet) {
		visible = false;
	} else {
		visible = (m_totalLife / m_pellet->getBuryDepthMax() > 0.85f);
	}

	if (visible) {
		Piki* piki = static_cast<Piki*>(obj);
		if (piki->isPiki() || piki->m_pikiKind != White) {
			return true;
		}

		return false;
	}

	return false;
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	mr       r31, r4
	stw      r30, 8(r1)
	mr       r30, r3
	lwz      r3, 0x1fc(r3)
	cmplwi   r3, 0
	bne      lbl_801F40E8
	li       r0, 0
	b        lbl_801F410C

lbl_801F40E8:
	bl       getBuryDepthMax__Q24Game6PelletFv
	lfs      f2, 0x1f8(r30)
	lfs      f0, lbl_80519C04@sda21(r2)
	fdivs    f1, f2, f1
	fcmpo    cr0, f1, f0
	ble      lbl_801F4108
	li       r0, 0
	b        lbl_801F410C

lbl_801F4108:
	li       r0, 1

lbl_801F410C:
	clrlwi.  r0, r0, 0x18
	bne      lbl_801F414C
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x18(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_801F4144
	lbz      r0, 0x2b8(r31)
	cmpwi    r0, 4
	bne      lbl_801F4144
	li       r3, 0
	b        lbl_801F4150

lbl_801F4144:
	li       r3, 1
	b        lbl_801F4150

lbl_801F414C:
	li       r3, 0

lbl_801F4150:
	lwz      r0, 0x14(r1)
	lwz      r31, 0xc(r1)
	lwz      r30, 8(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	801F4168
 * Size:	000114
 */
ItemTreasure::Mgr::Mgr()
{
	// m_name = "Treasure"; problem
	m_objectPathComponent = "user/kando/objects/treasure";
	m_parameters          = new TreasureParms;

	loadAndRead(m_parameters, "user/Abe/item/treasureParms.txt");
	// void* file = JKRDvdRipper::loadToMainRAM(, nullptr, (JKRExpandSwitch)0, 0, nullptr,
	//                                          (JKRDvdRipper::EAllocDirection)2, 0, nullptr, nullptr);

	// if (file) {
	// 	RamStream stm(file, -1);
	// 	stm.m_mode     = STREAM_MODE_TEXT;
	// 	stm.m_tabCount = 0;
	// 	m_parameters->read(stm);
	// 	delete[] file;
	// }
	/*
	stwu     r1, -0x440(r1)
	mflr     r0
	stw      r0, 0x444(r1)
	extsh.   r0, r4
	lis      r4, lbl_804816B8@ha
	stw      r31, 0x43c(r1)
	addi     r31, r4, lbl_804816B8@l
	stw      r30, 0x438(r1)
	mr       r30, r3
	beq      lbl_801F4198
	addi     r0, r30, 0x8c
	stw      r0, 4(r30)

lbl_801F4198:
	mr       r3, r30
	li       r4, 0
	bl       __ct__Q24Game12TNodeItemMgrFv
	lis      r3, __vt__Q34Game12ItemTreasure3Mgr@ha
	addi     r4, r31, 0x4c
	addi     r3, r3, __vt__Q34Game12ItemTreasure3Mgr@l
	addi     r0, r31, 0x58
	stw      r3, 0(r30)
	addi     r5, r3, 0x74
	li       r3, 0x18c
	stw      r5, 0x30(r30)
	stw      r4, 8(r30)
	stw      r0, 0x28(r30)
	bl       __nw__FUl
	or.      r0, r3, r3
	beq      lbl_801F41E0
	bl       __ct__Q34Game12ItemTreasure13TreasureParmsFv
	mr       r0, r3

lbl_801F41E0:
	stw      r0, 0x88(r30)
	li       r0, 0
	addi     r3, r31, 0x74
	li       r4, 0
	stw      r0, 8(r1)
	li       r5, 0
	li       r6, 0
	li       r7, 0
	li       r8, 2
	li       r9, 0
	li       r10, 0
	bl
loadToMainRAM__12JKRDvdRipperFPCcPUc15JKRExpandSwitchUlP7JKRHeapQ212JKRDvdRipper15EAllocDirectionUlPiPUl
	or.      r31, r3, r3
	beq      lbl_801F4260
	mr       r4, r31
	addi     r3, r1, 0x10
	li       r5, -1
	bl       __ct__9RamStreamFPvi
	li       r0, 1
	cmpwi    r0, 1
	stw      r0, 0x1c(r1)
	bne      lbl_801F4240
	li       r0, 0
	stw      r0, 0x424(r1)

lbl_801F4240:
	lwz      r3, 0x88(r30)
	addi     r4, r1, 0x10
	lwz      r12, 0xd8(r3)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r3, r31
	bl       __dla__FPv

lbl_801F4260:
	lwz      r0, 0x444(r1)
	mr       r3, r30
	lwz      r31, 0x43c(r1)
	lwz      r30, 0x438(r1)
	mtlr     r0
	addi     r1, r1, 0x440
	blr
	*/
}

/*
 * --INFO--
 * Address:	801F427C
 * Size:	000024
 */
void ItemTreasure::TreasureParms::read(Stream& stm) { m_parms.read(stm); }

/*
 * --INFO--
 * Address:	801F42A0
 * Size:	0002A0
 */
ItemTreasure::TreasureParms::TreasureParms()
{
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	lis      r5, 0x73303030@ha
	lis      r4, __vt__Q24Game13CreatureParms@ha
	stw      r0, 0x14(r1)
	addi     r0, r4, __vt__Q24Game13CreatureParms@l
	addi     r5, r5, 0x73303030@l
	stw      r31, 0xc(r1)
	stw      r30, 8(r1)
	mr       r30, r3
	lis      r3, lbl_804816B8@ha
	stw      r0, 0xd8(r30)
	addi     r31, r3, lbl_804816B8@l
	addi     r0, r30, 0xd4
	li       r3, 0
	stw      r0, 0(r30)
	addi     r0, r31, 0x94
	mr       r4, r30
	addi     r6, r31, 0xa8
	stw      r3, 4(r30)
	addi     r3, r30, 0xc
	stw      r0, 8(r30)
	bl       __ct__8BaseParmFP10ParametersUlPc
	lis      r3, "__vt__7Parm<f>"@ha
	lis      r5, 0x73303031@ha
	addi     r0, r3, "__vt__7Parm<f>"@l
	lfs      f0, lbl_80519BD8@sda21(r2)
	stw      r0, 0xc(r30)
	mr       r4, r30
	lfs      f1, lbl_80519BD0@sda21(r2)
	addi     r3, r30, 0x34
	stfs     f0, 0x24(r30)
	addi     r5, r5, 0x73303031@l
	lfs      f0, lbl_80519BF8@sda21(r2)
	addi     r6, r31, 0xbc
	stfs     f1, 0x2c(r30)
	stfs     f0, 0x30(r30)
	bl       __ct__8BaseParmFP10ParametersUlPc
	lis      r3, "__vt__7Parm<f>"@ha
	lis      r5, 0x73303032@ha
	addi     r0, r3, "__vt__7Parm<f>"@l
	lfs      f0, lbl_80519BD8@sda21(r2)
	stw      r0, 0x34(r30)
	mr       r4, r30
	lfs      f1, lbl_80519BD0@sda21(r2)
	addi     r3, r30, 0x5c
	stfs     f0, 0x4c(r30)
	addi     r5, r5, 0x73303032@l
	lfs      f0, lbl_80519BF8@sda21(r2)
	addi     r6, r31, 0xcc
	stfs     f1, 0x54(r30)
	stfs     f0, 0x58(r30)
	bl       __ct__8BaseParmFP10ParametersUlPc
	lis      r3, "__vt__7Parm<f>"@ha
	lis      r5, 0x73303033@ha
	addi     r0, r3, "__vt__7Parm<f>"@l
	lfs      f0, lbl_80519BD4@sda21(r2)
	stw      r0, 0x5c(r30)
	mr       r4, r30
	lfs      f1, lbl_80519BD0@sda21(r2)
	addi     r3, r30, 0x84
	stfs     f0, 0x74(r30)
	addi     r5, r5, 0x73303033@l
	lfs      f0, lbl_80519BF8@sda21(r2)
	addi     r6, r2, lbl_80519C08@sda21
	stfs     f1, 0x7c(r30)
	stfs     f0, 0x80(r30)
	bl       __ct__8BaseParmFP10ParametersUlPc
	lis      r3, "__vt__7Parm<f>"@ha
	lis      r5, 0x73303034@ha
	addi     r0, r3, "__vt__7Parm<f>"@l
	lfs      f0, lbl_80519C10@sda21(r2)
	stw      r0, 0x84(r30)
	mr       r4, r30
	lfs      f1, lbl_80519C14@sda21(r2)
	addi     r3, r30, 0xac
	stfs     f0, 0x9c(r30)
	addi     r5, r5, 0x73303034@l
	lfs      f0, lbl_80519C18@sda21(r2)
	addi     r6, r31, 0xdc
	stfs     f1, 0xa4(r30)
	stfs     f0, 0xa8(r30)
	bl       __ct__8BaseParmFP10ParametersUlPc
	lis      r4, "__vt__7Parm<f>"@ha
	lis      r3, __vt__Q34Game12ItemTreasure13TreasureParms@ha
	addi     r0, r4, "__vt__7Parm<f>"@l
	lis      r5, 0x70303030@ha
	stw      r0, 0xac(r30)
	addi     r9, r3, __vt__Q34Game12ItemTreasure13TreasureParms@l
	lfs      f0, lbl_80519C1C@sda21(r2)
	addi     r8, r30, 0x188
	lfs      f1, lbl_80519C14@sda21(r2)
	li       r7, 0
	stfs     f0, 0xc4(r30)
	addi     r0, r31, 0xec
	lfs      f0, lbl_80519C18@sda21(r2)
	addi     r3, r30, 0xe8
	stfs     f1, 0xcc(r30)
	addi     r4, r30, 0xdc
	addi     r5, r5, 0x70303030@l
	addi     r6, r31, 0xfc
	stfs     f0, 0xd0(r30)
	stw      r9, 0xd8(r30)
	stw      r8, 0xdc(r30)
	stw      r7, 0xe0(r30)
	stw      r0, 0xe4(r30)
	bl       __ct__8BaseParmFP10ParametersUlPc
	lis      r3, "__vt__7Parm<f>"@ha
	lis      r5, 0x70303031@ha
	addi     r0, r3, "__vt__7Parm<f>"@l
	lfs      f0, lbl_80519C20@sda21(r2)
	stw      r0, 0xe8(r30)
	addi     r3, r30, 0x110
	lfs      f1, lbl_80519BF8@sda21(r2)
	addi     r4, r30, 0xdc
	stfs     f0, 0x100(r30)
	addi     r5, r5, 0x70303031@l
	lfs      f0, lbl_80519C24@sda21(r2)
	addi     r6, r31, 0x108
	stfs     f1, 0x108(r30)
	stfs     f0, 0x10c(r30)
	bl       __ct__8BaseParmFP10ParametersUlPc
	lis      r3, "__vt__7Parm<f>"@ha
	lis      r5, 0x70303032@ha
	addi     r0, r3, "__vt__7Parm<f>"@l
	lfs      f0, lbl_80519C28@sda21(r2)
	stw      r0, 0x110(r30)
	addi     r3, r30, 0x138
	lfs      f1, lbl_80519BF8@sda21(r2)
	addi     r4, r30, 0xdc
	stfs     f0, 0x128(r30)
	addi     r5, r5, 0x70303032@l
	lfs      f0, lbl_80519C24@sda21(r2)
	addi     r6, r31, 0x114
	stfs     f1, 0x130(r30)
	stfs     f0, 0x134(r30)
	bl       __ct__8BaseParmFP10ParametersUlPc
	lis      r3, "__vt__7Parm<f>"@ha
	lis      r5, 0x70303033@ha
	addi     r0, r3, "__vt__7Parm<f>"@l
	lfs      f0, lbl_80519C2C@sda21(r2)
	stw      r0, 0x138(r30)
	addi     r3, r30, 0x160
	lfs      f1, lbl_80519BF8@sda21(r2)
	addi     r4, r30, 0xdc
	stfs     f0, 0x150(r30)
	addi     r5, r5, 0x70303033@l
	lfs      f0, lbl_80519C24@sda21(r2)
	addi     r6, r31, 0x120
	stfs     f1, 0x158(r30)
	stfs     f0, 0x15c(r30)
	bl       __ct__8BaseParmFP10ParametersUlPc
	lis      r3, "__vt__7Parm<f>"@ha
	lfs      f2, lbl_80519C30@sda21(r2)
	addi     r0, r3, "__vt__7Parm<f>"@l
	lfs      f1, lbl_80519BF8@sda21(r2)
	stw      r0, 0x160(r30)
	mr       r3, r30
	lfs      f0, lbl_80519C24@sda21(r2)
	stfs     f2, 0x178(r30)
	stfs     f1, 0x180(r30)
	stfs     f0, 0x184(r30)
	lwz      r31, 0xc(r1)
	lwz      r30, 8(r1)
	lwz      r0, 0x14(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	801F4540
 * Size:	000130
 */
BaseItem* ItemTreasure::Mgr::birth()
{
	Item* item = new Item;
	entry(item);
	return item;
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	stw      r30, 8(r1)
	mr       r30, r3
	li       r3, 0x234
	bl       __nw__FUl
	or.      r31, r3, r3
	beq      lbl_801F4648
	li       r4, 0x40e
	bl       __ct__Q24Game8BaseItemFi
	lis      r3,
"__vt__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>"@ha
	li       r0, 0
	addi     r4, r3,
"__vt__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>"@l
	li       r3, 0x1c
	stw      r4, 0(r31)
	addi     r4, r4, 0x1b0
	stw      r4, 0x178(r31)
	stw      r0, 0x1d8(r31)
	stw      r0, 0x1dc(r31)
	bl       __nw__FUl
	cmplwi   r3, 0
	beq      lbl_801F45CC
	lis      r4, "__vt__Q24Game40StateMachine<Q34Game12ItemTreasure4Item>"@ha
	lis      r5, "__vt__Q24Game35ItemFSM<Q34Game12ItemTreasure4Item>"@ha
	addi     r0, r4, "__vt__Q24Game40StateMachine<Q34Game12ItemTreasure4Item>"@l
	lis      r4, __vt__Q34Game12ItemTreasure3FSM@ha
	stw      r0, 0(r3)
	li       r6, -1
	addi     r5, r5, "__vt__Q24Game35ItemFSM<Q34Game12ItemTreasure4Item>"@l
	addi     r0, r4, __vt__Q34Game12ItemTreasure3FSM@l
	stw      r6, 0x18(r3)
	stw      r5, 0(r3)
	stw      r0, 0(r3)

lbl_801F45CC:
	stw      r3, 0x1d8(r31)
	mr       r4, r31
	lwz      r3, 0x1d8(r31)
	lwz      r12, 0(r3)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	lis      r4,
"__vt__Q24Game90WorkItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>"@ha
	addi     r3, r31, 0x1e0
	addi     r4, r4,
"__vt__Q24Game90WorkItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>"@l
	stw      r4, 0(r31)
	addi     r0, r4, 0x1b0
	stw      r0, 0x178(r31)
	bl       __ct__Q24Game11TSoundEventFv
	lis      r3, __vt__Q34Game12ItemTreasure4Item@ha
	lis      r4, __vt__Q28SysShape9MtxObject@ha
	addi     r5, r3, __vt__Q34Game12ItemTreasure4Item@l
	lis      r3, __vt__Q44Game12ItemTreasure4Item10DummyShape@ha
	stw      r5, 0(r31)
	addi     r0, r5, 0x1b0
	addi     r5, r4, __vt__Q28SysShape9MtxObject@l
	addi     r4, r3, __vt__Q44Game12ItemTreasure4Item10DummyShape@l
	stw      r0, 0x178(r31)
	addi     r3, r31, 0x138
	lfs      f0, lbl_80519BD0@sda21(r2)
	li       r0, 0
	stw      r5, 0x1ec(r31)
	stw      r4, 0x1ec(r31)
	stfs     f0, 0x118(r31)
	stw      r3, 0x1f0(r31)
	stw      r0, 0x1fc(r31)

lbl_801F4648:
	mr       r3, r30
	mr       r4, r31
	bl       entry__Q24Game12TNodeItemMgrFPQ24Game8BaseItem
	lwz      r0, 0x14(r1)
	mr       r3, r31
	lwz      r31, 0xc(r1)
	lwz      r30, 8(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	801F4670
 * Size:	000060
 */
BaseItem* ItemTreasure::Mgr::generatorBirth(Vector3f& pos, Vector3f&, GenItemParm*)
{
	BaseItem* item = birth();
	item->init(nullptr);
	item->setPosition(pos, false);
	return item;
}

/*
 * --INFO--
 * Address:	801F46D0
 * Size:	000004
 */
void ItemTreasure::Mgr::onLoadResources() { }

/*
 * --INFO--
 * Address:	801F46D4
 * Size:	000134
 */
ItemTreasure::Mgr::~Mgr()
{
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	mr       r31, r4
	stw      r30, 8(r1)
	or.      r30, r3, r3
	beq      lbl_801F47EC
	lis      r3, __vt__Q34Game12ItemTreasure3Mgr@ha
	addi     r3, r3, __vt__Q34Game12ItemTreasure3Mgr@l
	stw      r3, 0(r30)
	addi     r0, r3, 0x74
	stw      r0, 0x30(r30)
	beq      lbl_801F47DC
	lis      r3, __vt__Q24Game12TNodeItemMgr@ha
	addic.   r0, r30, 0x4c
	addi     r3, r3, __vt__Q24Game12TNodeItemMgr@l
	stw      r3, 0(r30)
	addi     r0, r3, 0x74
	stw      r0, 0x30(r30)
	beq      lbl_801F47A8
	lis      r4, "__vt__31NodeObjectMgr<Q24Game8BaseItem>"@ha
	addic.   r3, r30, 0x6c
	addi     r4, r4, "__vt__31NodeObjectMgr<Q24Game8BaseItem>"@l
	stw      r4, 0x4c(r30)
	addi     r0, r4, 0x2c
	stw      r0, 0x68(r30)
	beq      lbl_801F4758
	lis      r4, "__vt__29TObjectNode<Q24Game8BaseItem>"@ha
	addi     r0, r4, "__vt__29TObjectNode<Q24Game8BaseItem>"@l
	stw      r0, 0x6c(r30)
	li       r4, 0
	bl       __dt__5CNodeFv

lbl_801F4758:
	addic.   r0, r30, 0x4c
	beq      lbl_801F47A8
	lis      r3, "__vt__27ObjectMgr<Q24Game8BaseItem>"@ha
	addic.   r0, r30, 0x4c
	addi     r3, r3, "__vt__27ObjectMgr<Q24Game8BaseItem>"@l
	stw      r3, 0x4c(r30)
	addi     r0, r3, 0x2c
	stw      r0, 0x68(r30)
	beq      lbl_801F47A8
	lis      r3, "__vt__27Container<Q24Game8BaseItem>"@ha
	addic.   r0, r30, 0x4c
	addi     r0, r3, "__vt__27Container<Q24Game8BaseItem>"@l
	stw      r0, 0x4c(r30)
	beq      lbl_801F47A8
	lis      r4, __vt__16GenericContainer@ha
	addi     r3, r30, 0x4c
	addi     r0, r4, __vt__16GenericContainer@l
	li       r4, 0
	stw      r0, 0x4c(r30)
	bl       __dt__5CNodeFv

lbl_801F47A8:
	addic.   r0, r30, 0x30
	beq      lbl_801F47DC
	lis      r3, "__vt__27Container<Q24Game8BaseItem>"@ha
	addic.   r0, r30, 0x30
	addi     r0, r3, "__vt__27Container<Q24Game8BaseItem>"@l
	stw      r0, 0x30(r30)
	beq      lbl_801F47DC
	lis      r4, __vt__16GenericContainer@ha
	addi     r3, r30, 0x30
	addi     r0, r4, __vt__16GenericContainer@l
	li       r4, 0
	stw      r0, 0x30(r30)
	bl       __dt__5CNodeFv

lbl_801F47DC:
	extsh.   r0, r31
	ble      lbl_801F47EC
	mr       r3, r30
	bl       __dl__FPv

lbl_801F47EC:
	lwz      r0, 0x14(r1)
	mr       r3, r30
	lwz      r31, 0xc(r1)
	lwz      r30, 8(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	801F4808
 * Size:	000118
 */
BaseItem* ItemTreasure::Mgr::doNew()
{
	return new Item;
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	li       r3, 0x234
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	bl       __nw__FUl
	or.      r31, r3, r3
	beq      lbl_801F4908
	li       r4, 0x40e
	bl       __ct__Q24Game8BaseItemFi
	lis      r3,
"__vt__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>"@ha
	li       r0, 0
	addi     r4, r3,
"__vt__Q24Game89FSMItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>"@l
	li       r3, 0x1c
	stw      r4, 0(r31)
	addi     r4, r4, 0x1b0
	stw      r4, 0x178(r31)
	stw      r0, 0x1d8(r31)
	stw      r0, 0x1dc(r31)
	bl       __nw__FUl
	cmplwi   r3, 0
	beq      lbl_801F488C
	lis      r4, "__vt__Q24Game40StateMachine<Q34Game12ItemTreasure4Item>"@ha
	lis      r5, "__vt__Q24Game35ItemFSM<Q34Game12ItemTreasure4Item>"@ha
	addi     r0, r4, "__vt__Q24Game40StateMachine<Q34Game12ItemTreasure4Item>"@l
	lis      r4, __vt__Q34Game12ItemTreasure3FSM@ha
	stw      r0, 0(r3)
	li       r6, -1
	addi     r5, r5, "__vt__Q24Game35ItemFSM<Q34Game12ItemTreasure4Item>"@l
	addi     r0, r4, __vt__Q34Game12ItemTreasure3FSM@l
	stw      r6, 0x18(r3)
	stw      r5, 0(r3)
	stw      r0, 0(r3)

lbl_801F488C:
	stw      r3, 0x1d8(r31)
	mr       r4, r31
	lwz      r3, 0x1d8(r31)
	lwz      r12, 0(r3)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	lis      r4,
"__vt__Q24Game90WorkItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>"@ha
	addi     r3, r31, 0x1e0
	addi     r4, r4,
"__vt__Q24Game90WorkItem<Q34Game12ItemTreasure4Item,Q34Game12ItemTreasure3FSM,Q34Game12ItemTreasure5State>"@l
	stw      r4, 0(r31)
	addi     r0, r4, 0x1b0
	stw      r0, 0x178(r31)
	bl       __ct__Q24Game11TSoundEventFv
	lis      r3, __vt__Q34Game12ItemTreasure4Item@ha
	lis      r4, __vt__Q28SysShape9MtxObject@ha
	addi     r5, r3, __vt__Q34Game12ItemTreasure4Item@l
	lis      r3, __vt__Q44Game12ItemTreasure4Item10DummyShape@ha
	stw      r5, 0(r31)
	addi     r0, r5, 0x1b0
	addi     r5, r4, __vt__Q28SysShape9MtxObject@l
	addi     r4, r3, __vt__Q44Game12ItemTreasure4Item10DummyShape@l
	stw      r0, 0x178(r31)
	addi     r3, r31, 0x138
	lfs      f0, lbl_80519BD0@sda21(r2)
	li       r0, 0
	stw      r5, 0x1ec(r31)
	stw      r4, 0x1ec(r31)
	stfs     f0, 0x118(r31)
	stw      r3, 0x1f0(r31)
	stw      r0, 0x1fc(r31)

lbl_801F4908:
	lwz      r0, 0x14(r1)
	mr       r3, r31
	lwz      r31, 0xc(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	801F4920
 * Size:	00000C
 */
u32 ItemTreasure::Mgr::generatorGetID() { return 'trsr'; }

/*
 * --INFO--
 * Address:	801F492C
 * Size:	00000C
 */
char* ItemTreasure::Item::getCreatureName() { return "Treasure"; }

/*
 * --INFO--
 * Address:	801F4938
 * Size:	000008
 */
Matrixf* ItemTreasure::Item::DummyShape::getMatrix(int) { return m_matrix; }

/*
 * --INFO--
 * Address:	801F4940
 * Size:	000008
 */
// bool MtxObject::isModel() { return false; }

/*
 * --INFO--
 * Address:	801F4948
 * Size:	000034
 */
void FSMItem<Game::ItemTreasure::Item, Game::ItemTreasure::FSM, Game::ItemTreasure::State>::doAI()
{
	m_currentState->exec((ItemTreasure::Item*)this);
}

/*
 * --INFO--
 * Address:	801F497C
 * Size:	000004
 */
void ItemState<Game::ItemTreasure::Item>::onDamage(ItemTreasure::Item*, f32) { }

/*
 * --INFO--
 * Address:	801F4980
 * Size:	000004
 */
void ItemState<Game::ItemTreasure::Item>::onKeyEvent(ItemTreasure::Item* item, const SysShape::KeyEvent&) { }

/*
 * --INFO--
 * Address:	801F4984
 * Size:	000004
 */
void ItemState<Game::ItemTreasure::Item>::onBounce(ItemTreasure::Item*, Sys::Triangle*) { }

/*
 * --INFO--
 * Address:	801F4988
 * Size:	000004
 */
void ItemState<Game::ItemTreasure::Item>::onPlatCollision(ItemTreasure::Item*, PlatEvent&) { }

/*
 * --INFO--
 * Address:	801F498C
 * Size:	000004
 */
void ItemState<Game::ItemTreasure::Item>::onCollision(ItemTreasure::Item*, CollEvent&) { }

/*
 * --INFO--
 * Address:	801F4990
 * Size:	000004
 */
void FSMState<Game::ItemTreasure::Item>::init(ItemTreasure::Item*, StateArg*) { }

/*
 * --INFO--
 * Address:	801F4994
 * Size:	000004
 */
void FSMState<Game::ItemTreasure::Item>::exec(ItemTreasure::Item*) { }

/*
 * --INFO--
 * Address:	801F4998
 * Size:	000004
 */
void FSMState<Game::ItemTreasure::Item>::cleanup(ItemTreasure::Item*) { }

/*
 * --INFO--
 * Address:	801F499C
 * Size:	000004
 */
void FSMState<Game::ItemTreasure::Item>::resume(ItemTreasure::Item*) { }

/*
 * --INFO--
 * Address:	801F49A0
 * Size:	000004
 */
void FSMState<Game::ItemTreasure::Item>::restart(ItemTreasure::Item*) { }

/*
 * --INFO--
 * Address:	801F49A4
 * Size:	000030
 */
void FSMState<Game::ItemTreasure::Item>::transit(ItemTreasure::Item* item, int id, StateArg* arg) { m_fsm->transit(item, id, arg); }

/*
 * --INFO--
 * Address:	801F49D4
 * Size:	000004
 */
void StateMachine<ItemTreasure::Item>::init(ItemTreasure::Item*) { }

/*
 * --INFO--
 * Address:	801F49D8
 * Size:	000038
 */
void StateMachine<ItemTreasure::Item>::exec(ItemTreasure::Item* item)
{
	if (item->m_currentState) {
		item->m_currentState->exec(item);
	}
}

/*
 * --INFO--
 * Address:	801F4A10
 * Size:	000064
 */
void StateMachine<ItemTreasure::Item>::create(int count)
{
	m_limit          = count;
	m_count          = 0;
	m_states         = new FSMState<ItemTreasure::Item>*[m_limit];
	m_indexToIDArray = new int[m_limit];
	m_idToIndexArray = new int[m_limit];
}

/*
 * --INFO--
 * Address:	801F4A74
 * Size:	00009C
 */
void StateMachine<ItemTreasure::Item>::transit(ItemTreasure::Item* obj, int id, StateArg* arg)
{
	int index                  = m_idToIndexArray[id];
	ItemTreasure::State* state = obj->m_currentState;
	if (state) {
		state->cleanup(obj);
		m_currentID = state->m_id;
	}

	ASSERT_HANG(index < m_limit);

	state               = static_cast<ItemTreasure::State*>(m_states[index]);
	obj->m_currentState = state;
	state->init(obj, arg);
}

/*
 * --INFO--
 * Address:	801F4B10
 * Size:	000084
 */
void StateMachine<ItemTreasure::Item>::registerState(FSMState<Game::ItemTreasure::Item>* newState)
{
	// copied all this from enemyFSM.cpp, do we actually need it here? no idea
	bool check;
	if (m_count >= m_limit) {
		return;
	}
	m_states[m_count] = newState;
	// TODO: This looks weird. How would they really have written it?
	if (!(0 <= newState->m_id && newState->m_id < m_limit)) {
		check = false;
	} else {
		check = true;
	}
	if (check == false) {
		return;
	}
	newState->m_fsm                  = this;
	m_indexToIDArray[m_count]        = newState->m_id;
	m_idToIndexArray[newState->m_id] = m_count;
	m_count++;
}

/*
 * --INFO--
 * Address:	801F4B94
 * Size:	000044
 */
void FSMItem<ItemTreasure::Item, ItemTreasure::FSM, ItemTreasure::State>::onKeyEvent(const SysShape::KeyEvent& event)
{
	ItemState<ItemTreasure::Item>* state = m_currentState;
	if (state) {
		state->onKeyEvent((ItemTreasure::Item*)this, event);
	}
}

/*
 * --INFO--
 * Address:	801F4BD8
 * Size:	000044
 */
void FSMItem<ItemTreasure::Item, ItemTreasure::FSM, ItemTreasure::State>::platCallback(PlatEvent& event)
{
	ItemState<ItemTreasure::Item>* state = m_currentState;
	if (state) {
		state->onPlatCollision((ItemTreasure::Item*)this, event);
	}
}

/*
 * --INFO--
 * Address:	801F4C1C
 * Size:	000044
 */
void FSMItem<ItemTreasure::Item, ItemTreasure::FSM, ItemTreasure::State>::collisionCallback(CollEvent& event)
{
	ItemState<ItemTreasure::Item>* state = m_currentState;
	if (state) {
		state->onCollision((ItemTreasure::Item*)this, event);
	}
}

/*
 * --INFO--
 * Address:	801F4C60
 * Size:	000044
 */
void FSMItem<ItemTreasure::Item, ItemTreasure::FSM, ItemTreasure::State>::bounceCallback(Sys::Triangle* tri)
{
	ItemState<ItemTreasure::Item>* state = m_currentState;
	if (state) {
		state->onBounce((ItemTreasure::Item*)this, tri);
	}
}

/*
 * --INFO--
 * Address:	801F4CA4
 * Size:	000028
 */
void __sinit_itemTreasure_cpp()
{
	/*
	lis      r4, __float_nan@ha
	li       r0, -1
	lfs      f0, __float_nan@l(r4)
	lis      r3, lbl_804BBC18@ha
	stw      r0, lbl_80515B48@sda21(r13)
	stfsu    f0, lbl_804BBC18@l(r3)
	stfs     f0, lbl_80515B4C@sda21(r13)
	stfs     f0, 4(r3)
	stfs     f0, 8(r3)
	blr
	*/
}

} // namespace Game

/*
 * --INFO--
 * Address:	801F4CCC
 * Size:	000008
 */
// void @376 @onKeyEvent__Q24Game89FSMItem<Game::ItemTreasure::Item, Game::ItemTreasure::FSM, Game::ItemTreasure::State>
// FRCQ28SysShape8KeyEvent(void)
//{
/*
.loc_0x0:
  subi      r3, r3, 0x178
  b         -0x13C
*/
//}

/*
 * --INFO--
 * Address:	801F4CD4
 * Size:	000008
 */
//@48 @Game::ItemTreasure::Mgr::~Mgr(void)
//{
/*
addi     r3, r3, -48
b        __dt__Q34Game12ItemTreasure3MgrFv
*/
//}
