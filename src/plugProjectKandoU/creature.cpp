#include "CollInfo.h"
#include "Dolphin/mtx.h"
#include "Game/cellPyramid.h"
#include "Game/Creature.h"
#include "Game/gameGenerator.h"
#include "Game/GameSystem.h"
#include "Game/shadowMgr.h"
#include "IDelegate.h"
#include "JSystem/J3D/J3DModel.h"
#include "ObjectTypes.h"
#include "SysShape/Model.h"
#include "Sys/Sphere.h"
#include "types.h"
#include "Vector3.h"

// inline float _sqrt(register float x) {
// 	register float fthis;
// 	asm {
// 		frsqrte fthis, x
// 		fmuls x, fthis, x
// 	}
// 	return x;
// }

// inline float pikmin2_sqrtf__(float x)
// {
// 	if (!(x > 0.0f)) { // if x <= 0
// 		return x;
// 	}
// 	return _sqrt(x);
// 	// asm {
// 	// 	lfs f0, 0.0f
// 	// 	fcmpo cr0, x, f0
// 	// 	blelr
// 	// 	frsqrte f0, x
// 	// 	fmuls x, f0, x
// 	// }
// 	// return x;
// 	// asm {
// 	// 	opword 0xc0021f10
// 	// 	opword 0xfc010040
// 	// 	opword 0x4c810020
// 	// 	opword 0xfc000834
// 	// 	opword 0xec200072
// 	// 	opword 0x4e800020
// 	// };
// 	// lfs f0, lbl_80520270
// 	// fcmpo cr0, f1, f0
// 	// blelr
// 	// frsqrte f0, f1
// 	// fmuls f1, f0, f1
// 	// blr
// 	// if (!(x > 0.0f)) { // if x <= 0
// 	// 	return x;
// 	// }

// 	// register float reg1 = x;
// 	// register float reg2 = 0.0f;
// 	// register float result;

// 	// asm {
//     //   frsqrte reg2, reg1
//     //   fmuls result, reg2, reg1
// 	// }

// 	// return result;
// 	// return (x > 0.0f) ? x : __frsqrte(x) * (double)x;
// }

// inline float pikmin2_sqrtf_(float x)
// {
// 	if (!(x > 0.0f)) { // if x <= 0
// 		return x;
// 	}

// 	register float reg1 = x;
// 	register float reg2 = 0.0f;
// 	register float result;

// 	asm {
//       frsqrte reg2, reg1
//       fmuls result, reg2, reg1
// 	}

// 	return result;
// }

// template<> float Vector3f::normalise() {
// 	register float que;
// 	asm {
// 		lfs f3, 0(r3)
// 		lfs que, 4(r3)
// 		fmuls f0,f3,f3
// 		lfs f4, 8(r3)
// 		fmuls que,que,que
// 		fadds f0,f0,que
// 		fadds f0,f4,f0
// 		fcmpo cr0,f0,f2
// 		ble LAB_80207E28
// 		fmadds f0,f3,f3,que
// 		fadds que,f4,f0
// 		fcmpo cr0,que,f2
// 		ble LAB_80207E2C
// 		frsqrte f0,que
// 		fmuls que,f0,que
// 		b LAB_80207E2C
// LAB_80207E28:
// 		fmr que,f2
// LAB_80207E2C:
// 		// lfs f0,-0x45CC(r2)
// 		// fcmpo cr0,que,f0
// 		// ble LAB_80207E68
// 		// lfs f2,-0x45C0(r2)
// 		// lfs f0,0(r3)
// 		// fdivs f2,f2,que
// 	};
// 	if (que <= 0.0f) {
// 		return 0.0f;
// 	}
// 	x *= 1.0f / que;
// 	y *= 1.0f / que;
// 	z *= 1.0f / que;
// 	return que;
// }

// TODO: replace with definition in itemUjamushi when we get there.
inline template <> float Vector3f::normalise()
{
	// float f2 = 0.0f;
	// if ((x*x + y*y + z*z > 0.0f)) {
	float f2 = ((x * x + y * y + z * z > 0.0f)) ? pikmin2_sqrtf__(z * z + (x * x + y * y)) : 0.0f;
	// if (f2 = x*x + y*y + z*z, f2 > 0.0f) {
	// float x2 = x*x;
	// float z2 = z*z;
	// float y2 = y*y;
	// if (x2 + y2 + z2 > 0.0f) {
	// 	if (f2 = y2 + x2 + z2, f2 > 0.0f) {
	// float f2 = x*x + y*y + z*z;
	// if ((f2 > 0.0f) && (f2 > 0.0f)) {
	// f2 *= (float)SQRT((float)f2);
	// }
	// f2 = pikmin2_sqrtf__(z*z + (x*x + y*y));
	// }
	if (f2 > 0.0f) {
		// float f1 = 1.0f / f2;
		x *= 1.0f / f2;
		y *= 1.0f / f2;
		z *= 1.0f / f2;
		return f2;
	}
	return 0.0f;
}

/*
    Generated from dpostproc

    .section .ctors, "wa"  # 0x80472F00 - 0x804732C0
    .4byte __sinit_creature_cpp

    .section .rodata  # 0x804732E0 - 0x8049E220
    .global lbl_8047C6E8
    lbl_8047C6E8:
        .asciz "creature.cpp"
        .skip 3
    .global lbl_8047C6F8
    lbl_8047C6F8:
        .asciz "P2Assert"
        .skip 3

    .section .data, "wa"  # 0x8049E220 - 0x804EFC20
    .global lbl_804B0098
    lbl_804B0098:
        .4byte 0x00000000
        .4byte 0x00000000
        .4byte 0x00000000
    .global lbl_804B00A4
    lbl_804B00A4:
        .4byte 0x00000000
        .4byte 0xFFFFFFFF
        .4byte
   "resolveOneColl__Q24Game8CreatureFP8CollPartP8CollPartR10Vector3<f>" .global
   "__vt__63Delegate3<Q24Game8Creature,P8CollPart,P8CollPart,R10Vector3<f>>"
    "__vt__63Delegate3<Q24Game8Creature,P8CollPart,P8CollPart,R10Vector3<f>>":
        .4byte 0
        .4byte 0
        .4byte
   "invoke__63Delegate3<Q24Game8Creature,P8CollPart,P8CollPart,R10Vector3<f>>FP8CollPartP8CollPartR10Vector3<f>"
    .global "__vt__47IDelegate3<P8CollPart,P8CollPart,R10Vector3<f>>"
    "__vt__47IDelegate3<P8CollPart,P8CollPart,R10Vector3<f>>":
        .4byte 0
        .4byte 0
        .4byte 0
    .global __vt__Q24Game8Creature
    __vt__Q24Game8Creature:
        .4byte 0
        .4byte 0
        .4byte 0
        .4byte checkCollision__Q24Game8CreatureFPQ24Game10CellObject
        .4byte 0
        .4byte collisionUpdatable__Q24Game8CreatureFv
        .4byte isPiki__Q24Game8CreatureFv
        .4byte isNavi__Q24Game8CreatureFv
        .4byte deferPikiCollision__Q24Game10CellObjectFv
        .4byte getTypeName__Q24Game8CreatureFv
        .4byte getObjType__Q24Game8CreatureFv
        .4byte constructor__Q24Game8CreatureFv
        .4byte onInit__Q24Game8CreatureFPQ24Game15CreatureInitArg
        .4byte onKill__Q24Game8CreatureFPQ24Game15CreatureKillArg
        .4byte onInitPost__Q24Game8CreatureFPQ24Game15CreatureInitArg
        .4byte doAnimation__Q24Game8CreatureFv
        .4byte doEntry__Q24Game8CreatureFv
        .4byte doSetView__Q24Game8CreatureFi
        .4byte doViewCalc__Q24Game8CreatureFv
        .4byte doSimulation__Q24Game8CreatureFf
        .4byte doDirectDraw__Q24Game8CreatureFR8Graphics
        .4byte getBodyRadius__Q24Game8CreatureFv
        .4byte getCellRadius__Q24Game8CreatureFv
        .4byte "initPosition__Q24Game8CreatureFR10Vector3<f>"
        .4byte "onInitPosition__Q24Game8CreatureFR10Vector3<f>"
        .4byte 0
        .4byte 0
        .4byte 0
        .4byte 0
        .4byte "onSetPositionPost__Q24Game8CreatureFR10Vector3<f>"
        .4byte 0
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
        .4byte bounceCallback__Q24Game8CreatureFPQ23Sys8Triangle
        .4byte collisionCallback__Q24Game8CreatureFRQ24Game9CollEvent
        .4byte platCallback__Q24Game8CreatureFRQ24Game9PlatEvent
        .4byte getJAIObject__Q24Game8CreatureFv
        .4byte getPSCreature__Q24Game8CreatureFv
        .4byte getSound_AILOD__Q24Game8CreatureFv
        .4byte getSound_PosPtr__Q24Game8CreatureFv
        .4byte sound_culling__Q24Game8CreatureFv
        .4byte getSound_CurrAnimFrame__Q24Game8CreatureFv
        .4byte getSound_CurrAnimSpeed__Q24Game8CreatureFv
        .4byte on_movie_begin__Q24Game8CreatureFb
        .4byte on_movie_end__Q24Game8CreatureFb
        .4byte movieStartAnimation__Q24Game8CreatureFUl
        .4byte movieStartDemoAnimation__Q24Game8CreatureFPQ28SysShape8AnimInfo
        .4byte movieSetAnimationLastFrame__Q24Game8CreatureFv
        .4byte "movieSetTranslation__Q24Game8CreatureFR10Vector3<f>f"
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
        .4byte 0
        .4byte "getAngularEffect__Q24Game8CreatureFR10Vector3<f>R10Vector3<f>"
        .4byte "applyImpulse__Q24Game8CreatureFR10Vector3<f>R10Vector3<f>"
        .4byte ignoreAtari__Q24Game8CreatureFPQ24Game8Creature
        .4byte getSuckPos__Q24Game8CreatureFv
        .4byte getGoalPos__Q24Game8CreatureFv
        .4byte isSuckReady__Q24Game8CreatureFv
        .4byte isSuckArriveWait__Q24Game8CreatureFv
        .4byte stimulate__Q24Game8CreatureFRQ24Game11Interaction
        .4byte getCreatureName__Q24Game8CreatureFv
        .4byte getCreatureID__Q24Game8CreatureFv
    .global __vt__Q24Game10CellObject
    __vt__Q24Game10CellObject:
        .4byte 0
        .4byte 0
        .4byte 0
        .4byte checkCollision__Q24Game10CellObjectFPQ24Game10CellObject
        .4byte 0
        .4byte 0
        .4byte isPiki__Q24Game10CellObjectFv
        .4byte isNavi__Q24Game10CellObjectFv
        .4byte deferPikiCollision__Q24Game10CellObjectFv
        .4byte 0
        .4byte 0
    .global __vt__Q24Game15TPositionObject
    __vt__Q24Game15TPositionObject:
        .4byte 0
        .4byte 0
        .4byte 0

    .section .sdata, "wa"  # 0x80514680 - 0x80514D80
    .global usePacketCulling__Q24Game8Creature
    usePacketCulling__Q24Game8Creature:
        .4byte 0x01000000

    .section .sbss # 0x80514D80 - 0x80516360
    .global lbl_805158F0
    lbl_805158F0:
        .skip 0x4
    .global lbl_805158F4
    lbl_805158F4:
        .skip 0x4
    .global currOp__Q24Game8Creature
    currOp__Q24Game8Creature:
        .skip 0x8

    .section .sdata2, "a"     # 0x80516360 - 0x80520E40
    .global lbl_80518280
    lbl_80518280:
        .4byte 0x42C80000
    .global lbl_80518284
    lbl_80518284:
        .float 1.0
    .global lbl_80518288
    lbl_80518288:
        .4byte 0x00000000
    .global lbl_8051828C
    lbl_8051828C:
        .float 0.5
    .global lbl_80518290
    lbl_80518290:
        .4byte 0x41200000
    .global lbl_80518294
    lbl_80518294:
        .4byte 0x40800000
    .global lbl_80518298
    lbl_80518298:
        .4byte 0xC3FA0000
    .global lbl_8051829C
    lbl_8051829C:
        .4byte 0xC3960000
    .global lbl_805182A0
    lbl_805182A0:
        .4byte 0x43480000
    .global lbl_805182A4
    lbl_805182A4:
        .float 0.1
    .global lbl_805182A8
    lbl_805182A8:
        .4byte 0x40000000
        .4byte 0x00000000
*/

namespace Game {

#ifdef NOPE
/*
 * --INFO--
 * Address:	8013AE84
 * Size:	00012C
 */
Creature::Creature()
{

	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	lis      r4, __vt__Q24Game15TPositionObject@ha
	stw      r0, 0x14(r1)
	addi     r0, r4, __vt__Q24Game15TPositionObject@l
	stw      r31, 0xc(r1)
	mr       r31, r3
	stw      r0, 0(r3)
	addi     r3, r31, 4
	bl       __ct__Q210SweepPrune6ObjectFv
	lis      r3, __vt__Q24Game10CellObject@ha
	lis      r4, __ct__Q24Game7CellLegFv@ha
	addi     r0, r3, __vt__Q24Game10CellObject@l
	li       r5, 0
	stw      r0, 0(r31)
	addi     r3, r31, 0x54
	addi     r4, r4, __ct__Q24Game7CellLegFv@l
	li       r6, 0x14
	li       r7, 4
	bl       __construct_array
	addi     r3, r31, 0xa8
	bl       __ct__Q24Game15CollisionBufferFv
	li       r0, 1
	lis      r3, __vt__Q24Game8Creature@ha
	stb      r0, 0x64(r31)
	li       r4, 0
	addi     r0, r3, __vt__Q24Game8Creature@l
	addi     r3, r31, 0xd8
	stb      r4, 0x78(r31)
	stb      r4, 0x8c(r31)
	stb      r4, 0xa0(r31)
	stw      r31, 0x60(r31)
	stw      r31, 0x74(r31)
	stw      r31, 0x88(r31)
	stw      r31, 0x9c(r31)
	stw      r4, 0xa4(r31)
	stw      r0, 0(r31)
	stb      r4, 0xbc(r31)
	stb      r4, 0xbd(r31)
	stb      r4, 0xbe(r31)
	stb      r4, 0xbf(r31)
	bl       __ct__Q24Game5AILODFv
	addi     r3, r31, 0x12c
	bl       __ct__Q24Game13UpdateContextFv
	li       r0, 0
	lfs      f1, lbl_80518280@sda21(r2)
	stw      r0, 0x114(r31)
	addi     r3, r31, 0x138
	lfs      f0, lbl_80518284@sda21(r2)
	stw      r0, 0x174(r31)
	stfs     f1, 0x118(r31)
	stw      r0, 0xc4(r31)
	stfs     f0, 0x168(r31)
	stfs     f0, 0x16c(r31)
	stfs     f0, 0x170(r31)
	bl       PSMTXIdentity
	lis      r3, 0x0000FFFE@ha
	li       r0, 0
	addi     r4, r3, 0x0000FFFE@l
	mr       r3, r31
	sth      r4, 0x128(r31)
	stb      r0, 0xbc(r31)
	stb      r0, 0xbd(r31)
	stb      r0, 0xbe(r31)
	stb      r0, 0xbf(r31)
	lwz      r0, 0xbc(r31)
	ori      r0, r0, 7
	stw      r0, 0xbc(r31)
	bl       clearStick__Q24Game8CreatureFv
	lwz      r0, 0x14(r1)
	mr       r3, r31
	lwz      r31, 0xc(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}
#endif

/*
 * --INFO--
 * Address:	8013AFB0
 * Size:	000018
 */
CellLeg::CellLeg()
{
	m_prev   = nullptr;
	m_next   = nullptr;
	m_object = nullptr;
	m_cell   = nullptr;
	/*
	li       r0, 0
	stw      r0, 4(r3)
	stw      r0, 0(r3)
	stw      r0, 0xc(r3)
	stw      r0, 8(r3)
	blr
	*/
}

/*
 * --INFO--
 * Address:	8013AFC8
 * Size:	000120
 */
void Creature::init(Game::CreatureInitArg* arg)
{
	m_cellLayerIndex    = 0;
	m_cellRect.p1.x     = 0;
	m_cellRect.p1.y     = 0;
	m_cellRect.p2.x     = 0;
	m_cellRect.p2.y     = 0;
	m_flags.byteView[0] = 0;
	m_flags.byteView[1] = 0;
	m_flags.byteView[2] = 0;
	m_flags.byteView[3] = 0;
	m_flags.intView |= 7;
	clearStick();
	m_updateContext.init(Game::collisionUpdateMgr);
	_11C.x = 0.0f;
	_11C.y = 0.0f;
	_11C.z = 0.0f;
	clearCapture();
	_0C8                  = 0;
	m_collisionPosition.x = 0.0f;
	m_collisionPosition.y = 1.0f;
	m_collisionPosition.z = 0.0f;
	clearCapture();
	if (getMabiki()) {
		u32* mabiki = getMabiki();
		mabiki[1]   = 0;
		mabiki[0]   = 0;
	}
	onInit(arg);
	onInitPost(arg);
}

/*
 * --INFO--
 * Address:	8013B0E8
 * Size:	000004
 */
void Creature::onInitPost(Game::CreatureInitArg*) { }

/*
 * --INFO--
 * Address:	8013B0EC
 * Size:	000004
 */
void Creature::onInit(Game::CreatureInitArg*) { }

/*
 * --INFO--
 * Address:	8013B0F0
 * Size:	0000B4
 */
void Creature::kill(Game::CreatureKillArg* arg)
{
	endStick();
	setAlive(false);
	Cell::sCurrCellMgr = Game::cellMgr;
	exitCell();
	Cell::sCurrCellMgr = nullptr;
	m_updateContext.exit();
	releaseAllStickers();
	clearCapture();
	onKill(arg);
	if (m_generator) {
		m_generator->informDeath(this);
		m_generator = nullptr;
	}
}

/*
 * --INFO--
 * Address:	8013B1A4
 * Size:	000004
 */
void Creature::onKill(Game::CreatureKillArg* arg) { }

/*
 * TODO: Conditionally inlined. This might need to not have "inline" marked.
 *
 * --INFO--
 * Address:	8013B1A8
 * Size:	0000C8
 */
inline void Creature::setPosition(Vector3f& position, bool skipProcessing)
{
	onSetPosition(position);
	if (!skipProcessing) {
		updateTrMatrix();
		if (m_model != nullptr) {
			PSMTXCopy(m_mainMatrix.m_matrix.mtxView, m_model->m_j3dModel->_24);
			m_model->m_j3dModel->calc();
			if (m_collTree != nullptr) {
				m_collTree->update();
			}
		}
		onSetPositionPost(position);
	}
}

/*
 * --INFO--
 * Address:	8013B270
 * Size:	000004
 */
void Creature::onSetPositionPost(Vector3f&) { }

/*
 * --INFO--
 * Address:	8013B274
 * Size:	0000CC
 */
void Creature::initPosition(Vector3f& position)
{
	onSetPosition(position);
	updateTrMatrix();
	if (m_model != nullptr) {
		PSMTXCopy(m_mainMatrix.m_matrix.mtxView, m_model->m_j3dModel->_24);
		m_model->m_j3dModel->calc();
		if (m_collTree != nullptr) {
			m_collTree->update();
		}
	}
	onSetPositionPost(position);
	onInitPosition(position);
}

/*
 * --INFO--
 * Address:	8013B340
 * Size:	0000A0
 */
void Creature::getYVector(Vector3f& outVector)
{
	outVector.x = m_mainMatrix.m_matrix.structView.yx;
	outVector.y = m_mainMatrix.m_matrix.structView.yy;
	outVector.z = m_mainMatrix.m_matrix.structView.yz;
	outVector.normalise();
	/*
	lfs      f0, 0x13c(r3)
	lfs      f1, lbl_80518288@sda21(r2)
	stfs     f0, 0(r4)
	lfs      f0, 0x14c(r3)
	stfs     f0, 4(r4)
	lfs      f0, 0x15c(r3)
	stfs     f0, 8(r4)
	lfs      f3, 0(r4)
	lfs      f2, 4(r4)
	fmuls    f0, f3, f3
	lfs      f4, 8(r4)
	fmuls    f2, f2, f2
	fmuls    f4, f4, f4
	fadds    f0, f0, f2
	fadds    f0, f4, f0
	fcmpo    cr0, f0, f1
	ble      lbl_8013B3A0
	fmadds   f0, f3, f3, f2
	fadds    f2, f4, f0
	fcmpo    cr0, f2, f1
	ble      lbl_8013B3A4
	frsqrte  f0, f2
	fmuls    f2, f0, f2
	b        lbl_8013B3A4

lbl_8013B3A0:
	fmr      f2, f1

lbl_8013B3A4:
	lfs      f0, lbl_80518288@sda21(r2)
	fcmpo    cr0, f2, f0
	blelr
	lfs      f1, lbl_80518284@sda21(r2)
	lfs      f0, 0(r4)
	fdivs    f1, f1, f2
	fmuls    f0, f0, f1
	stfs     f0, 0(r4)
	lfs      f0, 4(r4)
	fmuls    f0, f0, f1
	stfs     f0, 4(r4)
	lfs      f0, 8(r4)
	fmuls    f0, f0, f1
	stfs     f0, 8(r4)
	blr
	*/
}

/*
 * --INFO--
 * Address:	8013B3E0
 * Size:	000034
 */
float Creature::getBodyRadius()
{
	Sys::Sphere boundingSphere;
	getBoundingSphere(boundingSphere);
	return boundingSphere.m_radius;
}

/*
 * --INFO--
 * Address:	8013B414
 * Size:	000034
 */
float Creature::getCellRadius()
{
	Sys::Sphere boundingSphere;
	getBoundingSphere(boundingSphere);
	return boundingSphere.m_radius;
}

/*
 * --INFO--
 * Address:	8013B448
 * Size:	000024
 */
char* Creature::getTypeName() { return ObjType::getName(m_objectTypeID); }

/*
 * --INFO--
 * Address:	8013B46C
 * Size:	00008C
 */
void Creature::getShadowParam(Game::ShadowParam& param)
{
	param.m_position = getPosition();
	param.m_position.y += 0.5f;
	param.m_height = 10.0f;
	param.m_radius = 4.0f;
	param._0C      = 0.0f;
	param._10      = 1.0f;
	param._14      = 0.0f;
}

/*
 * --INFO--
 * Address:	8013B4F8
 * Size:	00000C
 */
bool Creature::needShadow() { return m_lod.m_flags & AILOD::FLAG_NEED_SHADOW; }

/*
 * --INFO--
 * Address:	8013B504
 * Size:	000070
 */
void Creature::getLifeGaugeParam(Game::LifeGaugeParam& param)
{
	param._00 = getPosition();
	param._0C = 1.0f;
	param._10 = 10.0f;
	param._14 = 1;
}

/*
 * --INFO--
 * Address:	8013B574
 * Size:	000090
 */
void Creature::save(Stream& output, u8 flags)
{
	if (flags & 1) {
		Vector3f position = getPosition();
		position.write(output);
	}
	doSave(output);
}

/*
 * --INFO--
 * Address:	8013B604
 * Size:	0000E4
 */
void Creature::load(Stream& input, u8 flags)
{
	if (flags & 1) {
		Vector3f position;
		position.read(input);
		setPosition(position, false);
	}
	doLoad(input);
}

/*
 * --INFO--
 * Address:	8013B6E8
 * Size:	0000BC
 */
void Creature::calcSphereDistance(Game::Creature*)
{
	/*
	stwu     r1, -0x30(r1)
	mflr     r0
	stw      r0, 0x34(r1)
	stw      r31, 0x2c(r1)
	mr       r31, r3
	mr       r3, r4
	addi     r4, r1, 0x18
	lwz      r12, 0(r3)
	lwz      r12, 0x10(r12)
	mtctr    r12
	bctrl
	mr       r3, r31
	addi     r4, r1, 8
	lwz      r12, 0(r31)
	lwz      r12, 0x10(r12)
	mtctr    r12
	bctrl
	lfs      f1, 0xc(r1)
	lfs      f0, 0x1c(r1)
	lfs      f3, 0x10(r1)
	fsubs    f4, f1, f0
	lfs      f2, 0x20(r1)
	lfs      f1, 8(r1)
	lfs      f0, 0x18(r1)
	fsubs    f2, f3, f2
	fmuls    f3, f4, f4
	fsubs    f1, f1, f0
	lfs      f0, lbl_80518288@sda21(r2)
	fmuls    f2, f2, f2
	fmadds   f1, f1, f1, f3
	fadds    f2, f2, f1
	fcmpo    cr0, f2, f0
	ble      lbl_8013B77C
	ble      lbl_8013B780
	frsqrte  f0, f2
	fmuls    f2, f0, f2
	b        lbl_8013B780

lbl_8013B77C:
	fmr      f2, f0

lbl_8013B780:
	lfs      f1, 0x14(r1)
	lfs      f0, 0x24(r1)
	fadds    f0, f1, f0
	fsubs    f1, f2, f0
	lwz      r31, 0x2c(r1)
	lwz      r0, 0x34(r1)
	mtlr     r0
	addi     r1, r1, 0x30
	blr
	*/
}

/*
 * --INFO--
 * Address:	8013B7A4
 * Size:	0000CC
 */
void Creature::applyAirDrag(float, float, float)
{
	/*
	stwu     r1, -0x60(r1)
	mflr     r0
	stw      r0, 0x64(r1)
	stfd     f31, 0x50(r1)
	psq_st   f31, 88(r1), 0, qr0
	stfd     f30, 0x40(r1)
	psq_st   f30, 72(r1), 0, qr0
	stfd     f29, 0x30(r1)
	psq_st   f29, 56(r1), 0, qr0
	stw      r31, 0x2c(r1)
	mr       r31, r3
	fmr      f29, f1
	mr       r4, r31
	fmr      f30, f2
	lwz      r12, 0(r31)
	fmr      f31, f3
	addi     r3, r1, 8
	lwz      r12, 0x6c(r12)
	mtctr    r12
	bctrl
	lfs      f4, 0xc(r1)
	fmuls    f5, f29, f30
	lfs      f0, 8(r1)
	mr       r3, r31
	fmuls    f2, f29, f4
	lfs      f3, 0x10(r1)
	fnmsubs  f1, f0, f5, f0
	stfs     f0, 0x14(r1)
	fnmsubs  f0, f3, f5, f3
	fnmsubs  f2, f31, f2, f4
	stfs     f4, 0x18(r1)
	addi     r4, r1, 0x14
	stfs     f3, 0x1c(r1)
	stfs     f2, 0x18(r1)
	stfs     f1, 0x14(r1)
	stfs     f0, 0x1c(r1)
	lwz      r12, 0(r31)
	lwz      r12, 0x68(r12)
	mtctr    r12
	bctrl
	psq_l    f31, 88(r1), 0, qr0
	lfd      f31, 0x50(r1)
	psq_l    f30, 72(r1), 0, qr0
	lfd      f30, 0x40(r1)
	psq_l    f29, 56(r1), 0, qr0
	lfd      f29, 0x30(r1)
	lwz      r0, 0x64(r1)
	lwz      r31, 0x2c(r1)
	mtlr     r0
	addi     r1, r1, 0x60
	blr
	*/
}

/*
 * --INFO--
 * Address:	8013B870
 * Size:	00003C
 */
void Creature::doAnimation()
{
	if (m_model != nullptr) {
		m_model->m_j3dModel->calc();
	}
}

/*
 * --INFO--
 * Address:	8013B8AC
 * Size:	000004
 */
void Creature::doEntry() { }

/*
 * --INFO--
 * Address:	8013B8B0
 * Size:	000108
 */
void Creature::doSetView(int)
{
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	li       r0, 0
	stw      r31, 0xc(r1)
	mr       r31, r3
	stw      r30, 8(r1)
	or.      r30, r4, r4
	blt      lbl_8013B8E0
	cmpwi    r30, 2
	bge      lbl_8013B8E0
	li       r0, 1

lbl_8013B8E0:
	clrlwi.  r0, r0, 0x18
	bne      lbl_8013B904
	lis      r3, lbl_8047C6E8@ha
	lis      r5, lbl_8047C6F8@ha
	addi     r3, r3, lbl_8047C6E8@l
	li       r4, 0x22e
	addi     r5, r5, lbl_8047C6F8@l
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8013B904:
	lwz      r0, 0x174(r31)
	cmplwi   r0, 0
	beq      lbl_8013B9A0
	bne      lbl_8013B930
	lis      r3, lbl_8047C6E8@ha
	lis      r5, lbl_8047C6F8@ha
	addi     r3, r3, lbl_8047C6E8@l
	li       r4, 0x233
	addi     r5, r5, lbl_8047C6F8@l
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8013B930:
	lwz      r3, 0x174(r31)
	clrlwi   r4, r30, 0x10
	bl       setCurrentViewNo__Q28SysShape5ModelFUl
	lbz      r0, usePacketCulling__Q24Game8Creature@sda21(r13)
	cmplwi   r0, 0
	beq      lbl_8013B98C
	li       r0, 0x10
	lbz      r3, 0xd8(r31)
	slw      r0, r0, r30
	and.     r0, r3, r0
	beq      lbl_8013B974
	lwz      r3, 0x174(r31)
	lwz      r12, 0(r3)
	lwz      r12, 0x24(r12)
	mtctr    r12
	bctrl
	b        lbl_8013B9A0

lbl_8013B974:
	lwz      r3, 0x174(r31)
	lwz      r12, 0(r3)
	lwz      r12, 0x20(r12)
	mtctr    r12
	bctrl
	b        lbl_8013B9A0

lbl_8013B98C:
	lwz      r3, 0x174(r31)
	lwz      r12, 0(r3)
	lwz      r12, 0x24(r12)
	mtctr    r12
	bctrl

lbl_8013B9A0:
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
 * Address:	8013B9B8
 * Size:	00002C
 */
void Creature::doViewCalc()
{
	if (m_model != nullptr) {
		m_model->viewCalc();
	}
}

/*
 * --INFO--
 * Address:	8013B9E4
 * Size:	000010
 */
bool Creature::isPiki() { return m_objectTypeID == OBJTYPE_Piki; }

/*
 * --INFO--
 * Address:	8013B9F4
 * Size:	000014
 */
bool Creature::isNavi() { return m_objectTypeID == OBJTYPE_Navi; }

/*
 * --INFO--
 * Address:	8013BA08
 * Size:	000014
 */
bool Creature::isTeki() { return m_objectTypeID == OBJTYPE_Teki; }

/*
 * --INFO--
 * Address:	8013BA1C
 * Size:	000014
 */
bool Creature::isPellet() { return m_objectTypeID == OBJTYPE_Pellet; }

/*
 * --INFO--
 * Address:	8013BA30
 * Size:	000020
 */
bool Creature::sound_culling() { return !((m_lod.m_flags & AILOD::FLAG_UNKNOWN4) || (m_lod.m_flags & AILOD::FLAG_NEED_SHADOW)); }

/*
 * --INFO--
 * Address:	8013BA50
 * Size:	00009C
 */
void Creature::movie_begin(bool required)
{
	// m_flags.m_isMovieActor = TRUE;
	m_flags.intView |= CF_IS_MOVIE_ACTOR;
	if (required == false) {
		// 	m_flags.m_isMovieExtra = TRUE;
		m_flags.intView |= CF_IS_MOVIE_EXTRA;
		isPiki();
	} else {
		// 	m_flags.m_isMovieExtra = FALSE;
		m_flags.intView &= ~CF_IS_MOVIE_EXTRA;
		isPiki();
	}
	on_movie_begin(required);
}

/*
 * TODO: Determine if param really should be named "required".
 * --INFO--
 * Address:	8013BAEC
 * Size:	000050
 */
void Creature::movie_end(bool required)
{
	on_movie_end(required);
	m_flags.intView &= ~CF_IS_MOVIE_ACTOR;
	m_flags.intView &= ~CF_IS_MOVIE_EXTRA;
}

/*
 * --INFO--
 * Address:	8013BB3C
 * Size:	0000E0
 */
void Creature::checkWater(Game::WaterBox* waterBox, Sys::Sphere& sphere)
{
	// if (waterBox == nullptr) {
	// 	waterBox = nullptr;
	// 	if (Game::mapMgr != nullptr) {
	// 		waterBox = Game::mapMgr->findWater(sphere);
	// 	}
	// 	if (waterBox != nullptr) {
	// 		inWaterCallback(waterBox);
	// 	}
	// } else {
	// 	if (!waterBox->inWater(sphere)) {
	// 		if (Game::mapMgr != nullptr) {
	// 			waterBox = Game::mapMgr->findWater(sphere);
	// 		}
	// 		if (waterBox == nullptr) {
	// 			outWaterCallback();
	// 			waterBox = nullptr;
	// 		}
	// 	}
	// }
	// return waterBox;
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	stw      r0, 0x24(r1)
	stw      r31, 0x1c(r1)
	mr       r31, r5
	stw      r30, 0x18(r1)
	or.      r30, r4, r4
	stw      r29, 0x14(r1)
	mr       r29, r3
	beq      lbl_8013BBC0
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8013BBFC
	lwz      r3, mapMgr__4Game@sda21(r13)
	cmplwi   r3, 0
	beq      lbl_8013BB9C
	mr       r4, r31
	bl       findWater__Q24Game6MapMgrFRQ23Sys6Sphere
	mr       r30, r3

lbl_8013BB9C:
	cmplwi   r30, 0
	bne      lbl_8013BBFC
	mr       r3, r29
	lwz      r12, 0(r29)
	lwz      r12, 0x88(r12)
	mtctr    r12
	bctrl
	li       r30, 0
	b        lbl_8013BBFC

lbl_8013BBC0:
	lwz      r3, mapMgr__4Game@sda21(r13)
	li       r4, 0
	cmplwi   r3, 0
	beq      lbl_8013BBDC
	mr       r4, r31
	bl       findWater__Q24Game6MapMgrFRQ23Sys6Sphere
	mr       r4, r3

lbl_8013BBDC:
	cmplwi   r4, 0
	mr       r30, r4
	beq      lbl_8013BBFC
	lwz      r12, 0(r29)
	mr       r3, r29
	lwz      r12, 0x84(r12)
	mtctr    r12
	bctrl

lbl_8013BBFC:
	lwz      r0, 0x24(r1)
	mr       r3, r30
	lwz      r31, 0x1c(r1)
	lwz      r30, 0x18(r1)
	lwz      r29, 0x14(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	8013BC1C
 * Size:	000004
 */
void Creature::inWaterCallback(Game::WaterBox*) { }

/*
 * --INFO--
 * Address:	8013BC20
 * Size:	000004
 */
void Creature::outWaterCallback() { }

/*
 * --INFO--
 * Address:	8013BC24
 * Size:	000144
 */
void Creature::checkHell(Creature::CheckHellArg&)
{
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	stw      r0, 0x24(r1)
	stw      r31, 0x1c(r1)
	mr       r31, r4
	stw      r30, 0x18(r1)
	mr       r30, r3
	mr       r4, r30
	addi     r3, r1, 8
	lwz      r12, 0(r30)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	lfs      f1, 0xc(r1)
	lfs      f0, lbl_80518298@sda21(r2)
	fcmpo    cr0, f1, f0
	bge      lbl_8013BD40
	mr       r3, r30
	lwz      r12, 0(r30)
	lwz      r12, 0x18(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_8013BCA8
	mr       r3, r30
	lwz      r12, 0(r30)
	lwz      r12, 0x1c0(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_8013BCA8
	li       r3, 0
	bl       inc__Q24Game8DeathMgrFi

lbl_8013BCA8:
	lbz      r0, 0(r31)
	cmplwi   r0, 0
	beq      lbl_8013BD38
	mr       r3, r30
	bl       endStick__Q24Game8CreatureFv
	mr       r3, r30
	li       r4, 0
	lwz      r12, 0(r30)
	lwz      r12, 0xac(r12)
	mtctr    r12
	bctrl
	lwz      r0, cellMgr__4Game@sda21(r13)
	mr       r3, r30
	stw      r0, sCurrCellMgr__Q24Game4Cell@sda21(r13)
	bl       exitCell__Q24Game10CellObjectFv
	li       r0, 0
	addi     r3, r30, 0x12c
	stw      r0, sCurrCellMgr__Q24Game4Cell@sda21(r13)
	bl       exit__Q24Game13UpdateContextFv
	mr       r3, r30
	bl       releaseAllStickers__Q24Game8CreatureFv
	mr       r3, r30
	bl       clearCapture__Q24Game8CreatureFv
	mr       r3, r30
	li       r4, 0
	lwz      r12, 0(r30)
	lwz      r12, 0x34(r12)
	mtctr    r12
	bctrl
	lwz      r3, 0xc4(r30)
	cmplwi   r3, 0
	beq      lbl_8013BD38
	mr       r4, r30
	bl       informDeath__Q24Game9GeneratorFPQ24Game8Creature
	li       r0, 0
	stw      r0, 0xc4(r30)

lbl_8013BD38:
	li       r3, 2
	b        lbl_8013BD50

lbl_8013BD40:
	lfs      f0, lbl_8051829C@sda21(r2)
	fcmpo    cr0, f1, f0
	mfcr     r0
	srwi     r3, r0, 0x1f

lbl_8013BD50:
	lwz      r0, 0x24(r1)
	lwz      r31, 0x1c(r1)
	lwz      r30, 0x18(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	8013BD68
 * Size:	000178
 */
void Creature::updateCell()
{
	if ((Game::gameSystem == nullptr) || !(Game::gameSystem->_3C & 4)) {
		m_passID = -1;
		Sys::Sphere collision;
		collision.m_position               = getPosition();
		float radius                       = getCellRadius();
		collision.m_radius                 = radius;
		m_sweepPruneObject.m_minX.m_radius = collision.m_position.x - radius;
		m_sweepPruneObject.m_maxX.m_radius = collision.m_position.x + collision.m_radius;
		m_sweepPruneObject.m_minZ.m_radius = collision.m_position.z - collision.m_radius;
		m_sweepPruneObject.m_maxZ.m_radius = collision.m_position.z + collision.m_radius;
	}
	// TODO: I think the rest is an inline function of something that takes a
	// CellObject*? Didn't find any candidates in the symbol map though.

	/*
	stwu     r1, -0x40(r1)
	mflr     r0
	stw      r0, 0x44(r1)
	stw      r31, 0x3c(r1)
	stw      r30, 0x38(r1)
	stw      r29, 0x34(r1)
	mr       r29, r3
	lwz      r4, gameSystem__4Game@sda21(r13)
	cmplwi   r4, 0
	beq      lbl_8013BD9C
	lbz      r0, 0x3c(r4)
	rlwinm.  r0, r0, 0, 0x1d, 0x1d
	bne      lbl_8013BEC4

lbl_8013BD9C:
	li       r0, -1
	mr       r4, r29
	stw      r0, 0xa4(r29)
	addi     r3, r1, 8
	lwz      r12, 0(r29)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	lfs      f2, 8(r1)
	mr       r3, r29
	lfs      f1, 0xc(r1)
	lfs      f0, 0x10(r1)
	stfs     f2, 0x14(r1)
	stfs     f1, 0x18(r1)
	stfs     f0, 0x1c(r1)
	lwz      r12, 0(r29)
	lwz      r12, 0x58(r12)
	mtctr    r12
	bctrl
	frsp     f0, f1
	lfs      f2, 0x14(r1)
	stfs     f1, 0x20(r1)
	cmplwi   r29, 0
	mr       r31, r29
	fsubs    f0, f2, f0
	stfs     f0, 4(r29)
	lfs      f1, 0x14(r1)
	lfs      f0, 0x20(r1)
	fadds    f0, f1, f0
	stfs     f0, 0x18(r29)
	lfs      f1, 0x1c(r1)
	lfs      f0, 0x20(r1)
	fsubs    f0, f1, f0
	stfs     f0, 0x2c(r29)
	lfs      f1, 0x1c(r1)
	lfs      f0, 0x20(r1)
	fadds    f0, f1, f0
	stfs     f0, 0x40(r29)
	beq      lbl_8013BE3C
	addi     r31, r29, 4

lbl_8013BE3C:
	lwz      r30, cellMgr__4Game@sda21(r13)
	mr       r3, r31
	mr       r4, r30
	bl       insertSort__Q210SweepPrune4NodeFRQ210SweepPrune4Node
	mr       r4, r30
	addi     r3, r31, 0x14
	bl       insertSort__Q210SweepPrune4NodeFRQ210SweepPrune4Node
	addi     r3, r31, 0x28
	addi     r4, r30, 0x14
	bl       insertSort__Q210SweepPrune4NodeFRQ210SweepPrune4Node
	addi     r3, r31, 0x3c
	addi     r4, r30, 0x14
	bl       insertSort__Q210SweepPrune4NodeFRQ210SweepPrune4Node
	lwz      r0, cellMgr__4Game@sda21(r13)
	cmplwi   r0, 0
	beq      lbl_8013BEC4
	mr       r3, r29
	lwz      r12, 0(r29)
	lwz      r12, 0x1a8(r12)
	mtctr    r12
	bctrl
	stw      r3, sCellBugName__Q24Game11CellPyramid@sda21(r13)
	mr       r3, r29
	lwz      r12, 0(r29)
	lwz      r12, 0x1ac(r12)
	mtctr    r12
	bctrl
	stw      r3, sCellBugID__Q24Game11CellPyramid@sda21(r13)
	mr       r4, r29
	lwz      r3, cellMgr__4Game@sda21(r13)
	addi     r5, r1, 0x14
	addi     r6, r29, 0xdc
	addi     r7, r29, 0xe0
	bl
"entry__Q24Game11CellPyramidFPQ24Game10CellObjectRQ23Sys6SphereRiR7Rect<i>"

lbl_8013BEC4:
	lwz      r0, 0x44(r1)
	lwz      r31, 0x3c(r1)
	lwz      r30, 0x38(r1)
	lwz      r29, 0x34(r1)
	mtlr     r0
	addi     r1, r1, 0x40
	blr
	*/
}

/*
 * --INFO--
 * Address:	8013BEE0
 * Size:	000008
 */
s32 Creature::getCreatureID() { return -0x1; }

/*
 * --INFO--
 * Address:	8013BEE8
 * Size:	000044
 */
int Creature::getCellPikiCount()
{
	if (Game::cellMgr != nullptr) {
		return Game::cellMgr->getPikiCount(m_cellLayerIndex, m_cellRect);
	}
	return 0;
}

/*
 * --INFO--
 * Address:	8013BF2C
 * Size:	0000B0
 */
void Creature::applyImpulse(Vector3f& unused, Vector3f& impulse)
{
	Vector3f newVelocity;
	Vector3f oldVelocity = getVelocity();
	// TODO: Check if vector3 had helper functions for multiplying and addition.
	// Those might've been used here, which would explain seperate operations in
	// sets of 3. i.e. 3 stfs, 3 lfs, 3 fmuls, 3 fadds, 3 stfs
	newVelocity.x = oldVelocity.x + impulse.x * _118;
	newVelocity.y = oldVelocity.y + impulse.y * _118;
	newVelocity.z = oldVelocity.z + impulse.z * _118;
	setVelocity(newVelocity);
	/*
	stwu     r1, -0x30(r1)
	mflr     r0
	stw      r0, 0x34(r1)
	stw      r31, 0x2c(r1)
	mr       r31, r5
	stw      r30, 0x28(r1)
	mr       r30, r3
	mr       r4, r30
	addi     r3, r1, 8
	lwz      r12, 0(r30)
	lwz      r12, 0x6c(r12)
	mtctr    r12
	bctrl
	lfs      f5, 8(r1)
	mr       r3, r30
	lfs      f4, 0xc(r1)
	addi     r4, r1, 0x14
	lfs      f3, 0x10(r1)
	stfs     f5, 0x14(r1)
	stfs     f4, 0x18(r1)
	stfs     f3, 0x1c(r1)
	lfs      f6, 0x118(r30)
	lfs      f2, 8(r31)
	lfs      f1, 4(r31)
	lfs      f0, 0(r31)
	fmuls    f2, f2, f6
	fmuls    f1, f1, f6
	fmuls    f0, f0, f6
	fadds    f2, f3, f2
	fadds    f1, f4, f1
	fadds    f0, f5, f0
	stfs     f2, 0x1c(r1)
	stfs     f0, 0x14(r1)
	stfs     f1, 0x18(r1)
	lwz      r12, 0(r30)
	lwz      r12, 0x68(r12)
	mtctr    r12
	bctrl
	lwz      r0, 0x34(r1)
	lwz      r31, 0x2c(r1)
	lwz      r30, 0x28(r1)
	mtlr     r0
	addi     r1, r1, 0x30
	blr
	*/
}

/*
 * --INFO--
 * Address:	8013BFDC
 * Size:	0002E4
 */
void Creature::checkCollision(Game::CellObject*)
{
	/*
	stwu     r1, -0x60(r1)
	mflr     r0
	stw      r0, 0x64(r1)
	stmw     r27, 0x4c(r1)
	mr       r29, r3
	mr       r30, r4
	lwz      r12, 0(r3)
	lwz      r12, 0xd8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_8013C034
	mr       r3, r29
	lwz      r12, 0(r29)
	lwz      r12, 0x1a8(r12)
	mtctr    r12
	bctrl
	mr       r3, r30
	lwz      r12, 0(r30)
	lwz      r12, 0x1a8(r12)
	mtctr    r12
	bctrl

lbl_8013C034:
	mr       r3, r30
	lwz      r12, 0(r30)
	lwz      r12, 0xa0(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_8013C2AC
	mr       r3, r29
	lwz      r12, 0(r29)
	lwz      r12, 0xa0(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8013C070
	b        lbl_8013C2AC

lbl_8013C070:
	mr       r3, r29
	bl       isStickTo__Q24Game8CreatureFv
	clrlwi.  r0, r3, 0x18
	beq      lbl_8013C08C
	lwz      r0, 0xf4(r29)
	cmplw    r0, r30
	beq      lbl_8013C2AC

lbl_8013C08C:
	mr       r3, r30
	bl       isStickTo__Q24Game8CreatureFv
	clrlwi.  r0, r3, 0x18
	beq      lbl_8013C0A8
	lwz      r0, 0xf4(r30)
	cmplw    r0, r29
	beq      lbl_8013C2AC

lbl_8013C0A8:
	mr       r3, r29
	mr       r4, r30
	lwz      r12, 0(r29)
	lwz      r12, 0x190(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8013C2AC
	mr       r3, r30
	mr       r4, r29
	lwz      r12, 0(r30)
	lwz      r12, 0x190(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_8013C0EC
	b        lbl_8013C2AC

lbl_8013C0EC:
	mr       r3, r30
	lwz      r12, 0(r30)
	lwz      r12, 0xa8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_8013C2AC
	mr       r3, r29
	lwz      r12, 0(r29)
	lwz      r12, 0xa8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8013C128
	b        lbl_8013C2AC

lbl_8013C128:
	mr       r3, r29
	lwz      r12, 0(r29)
	lwz      r12, 0xd8(r12)
	mtctr    r12
	bctrl
	lis      r3, lbl_804B00A4@ha
	lis      r4, "__vt__47IDelegate3<P8CollPart,P8CollPart,R10Vector3<f>>"@ha
	addi     r5, r3, lbl_804B00A4@l
	lis      r3,
"__vt__63Delegate3<Q24Game8Creature,P8CollPart,P8CollPart,R10Vector3<f>>"@ha lwz
r7, 0(r5) addi     r4, r4,
"__vt__47IDelegate3<P8CollPart,P8CollPart,R10Vector3<f>>"@l lwz      r6, 4(r5)
	addi     r0, r3,
"__vt__63Delegate3<Q24Game8Creature,P8CollPart,P8CollPart,R10Vector3<f>>"@l lwz
r5, 8(r5) mr       r3, r29 stw      r4, 0x30(r1) addi     r31, r1, 0x38 stw r0,
0x30(r1) stw      r29, 0x34(r1) stw      r7, 0x38(r1) stw      r6, 0x3c(r1) stw
r5, 0x40(r1) stw      r30, currOp__Q24Game8Creature@sda21(r13) lwz      r12,
0(r29) stw      r7, 0x24(r1) lwz      r12, 0xd8(r12) stw      r6, 0x28(r1) stw
r5, 0x2c(r1) mtctr    r12 bctrl clrlwi.  r0, r3, 0x18 beq      lbl_8013C1B0 li
r0, 1 stb      r0, mDebug__8CollTree@sda21(r13)

lbl_8013C1B0:
	mr       r3, r29
	li       r28, 1
	lwz      r12, 0(r29)
	lwz      r12, 0x18(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8013C1F0
	mr       r3, r29
	lwz      r12, 0(r29)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8013C1F0
	li       r28, 0

lbl_8013C1F0:
	mr       r3, r30
	li       r27, 1
	lwz      r12, 0(r30)
	lwz      r12, 0x18(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8013C230
	mr       r3, r30
	lwz      r12, 0(r30)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8013C230
	li       r27, 0

lbl_8013C230:
	clrlwi.  r0, r28, 0x18
	beq      lbl_8013C240
	clrlwi.  r0, r27, 0x18
	bne      lbl_8013C250

lbl_8013C240:
	clrlwi.  r0, r28, 0x18
	bne      lbl_8013C290
	clrlwi.  r0, r27, 0x18
	bne      lbl_8013C290

lbl_8013C250:
	lwz      r3, 0x114(r29)
	addi     r5, r1, 0xc
	lwz      r4, 0x114(r30)
	addi     r6, r1, 8
	addi     r7, r1, 0x10
	bl "checkCollision__8CollTreeFP8CollTreePP8CollPartPP8CollPartR10Vector3<f>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_8013C2A0
	lwz      r3, 0x34(r1)
	mr       r12, r31
	lwz      r4, 0xc(r1)
	addi     r6, r1, 0x10
	lwz      r5, 8(r1)
	bl       __ptmf_scall
	nop
	b        lbl_8013C2A0

lbl_8013C290:
	lwz      r3, 0x114(r29)
	addi     r5, r1, 0x30
	lwz      r4, 0x114(r30)
	bl
"checkCollisionMulti__8CollTreeFP8CollTreeP47IDelegate3<P8CollPart,P8CollPart,R10Vector3<f>>"

lbl_8013C2A0:
	li       r0, 0
	stb      r0, mDebug__8CollTree@sda21(r13)
	stw      r0, currOp__Q24Game8Creature@sda21(r13)

lbl_8013C2AC:
	lmw      r27, 0x4c(r1)
	lwz      r0, 0x64(r1)
	mtlr     r0
	addi     r1, r1, 0x60
	blr
	*/
}

/*
 * --INFO--
 * Address:	8013C2C0
 * Size:	0008CC
 */
void Creature::resolveOneColl(CollPart*, CollPart*, Vector3f&)
{
	/*
	stwu     r1, -0xf0(r1)
	mflr     r0
	stw      r0, 0xf4(r1)
	stfd     f31, 0xe0(r1)
	psq_st   f31, 232(r1), 0, qr0
	stfd     f30, 0xd0(r1)
	psq_st   f30, 216(r1), 0, qr0
	stfd     f29, 0xc0(r1)
	psq_st   f29, 200(r1), 0, qr0
	stmw     r26, 0xa8(r1)
	lwz      r0, currOp__Q24Game8Creature@sda21(r13)
	mr       r28, r3
	mr       r29, r4
	mr       r30, r5
	cmplwi   r0, 0
	mr       r26, r6
	mr       r31, r0
	beq      lbl_8013CB60
	lwz      r12, 0(r3)
	lwz      r12, 0xd8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_8013C348
	mr       r3, r28
	lwz      r12, 0(r28)
	lwz      r12, 0x1a8(r12)
	mtctr    r12
	bctrl
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x1a8(r12)
	mtctr    r12
	bctrl

lbl_8013C348:
	mr       r3, r28
	li       r27, 0
	lwz      r12, 0(r28)
	lwz      r12, 0xb0(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_8013C384
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0xb0(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8013C388

lbl_8013C384:
	li       r27, 1

lbl_8013C388:
	lfs      f1, 4(r26)
	lfs      f0, 0(r26)
	fneg     f3, f1
	lfs      f2, 8(r26)
	fneg     f0, f0
	lfs      f1, lbl_80518288@sda21(r2)
	fneg     f2, f2
	frsp     f4, f3
	frsp     f5, f0
	stfs     f0, 0x98(r1)
	frsp     f6, f2
	fmuls    f4, f4, f4
	stfs     f3, 0x9c(r1)
	fmuls    f0, f5, f5
	fmuls    f3, f6, f6
	stfs     f2, 0xa0(r1)
	fadds    f0, f0, f4
	fadds    f0, f3, f0
	fcmpo    cr0, f0, f1
	ble      lbl_8013C3F4
	fmadds   f0, f5, f5, f4
	fadds    f4, f3, f0
	fcmpo    cr0, f4, f1
	ble      lbl_8013C3F8
	frsqrte  f0, f4
	fmuls    f4, f0, f4
	b        lbl_8013C3F8

lbl_8013C3F4:
	fmr      f4, f1

lbl_8013C3F8:
	lfs      f0, lbl_80518288@sda21(r2)
	fcmpo    cr0, f4, f0
	ble      lbl_8013C434
	lfs      f0, lbl_80518284@sda21(r2)
	lfs      f2, 0x98(r1)
	fdivs    f3, f0, f4
	lfs      f1, 0x9c(r1)
	lfs      f0, 0xa0(r1)
	fmuls    f2, f2, f3
	fmuls    f1, f1, f3
	fmuls    f0, f0, f3
	stfs     f2, 0x98(r1)
	stfs     f1, 0x9c(r1)
	stfs     f0, 0xa0(r1)
	b        lbl_8013C438

lbl_8013C434:
	fmr      f4, f0

lbl_8013C438:
	lfs      f1, lbl_80518288@sda21(r2)
	fcmpu    cr0, f1, f4
	bne      lbl_8013C454
	lfs      f0, lbl_80518284@sda21(r2)
	stfs     f1, 0x98(r1)
	stfs     f1, 0x9c(r1)
	stfs     f0, 0xa0(r1)

lbl_8013C454:
	lfs      f0, 0x1c(r29)
	mr       r3, r28
	lfs      f6, 0xa0(r1)
	addi     r4, r1, 0x74
	lfs      f7, 0x9c(r1)
	addi     r5, r1, 0x8c
	lfs      f8, 0x98(r1)
	fmuls    f5, f6, f0
	lfs      f2, 0x54(r29)
	fmuls    f4, f7, f0
	lfs      f1, 0x50(r29)
	fmuls    f3, f8, f0
	lfs      f0, 0x4c(r29)
	fadds    f2, f2, f5
	fadds    f1, f1, f4
	fadds    f0, f0, f3
	stfs     f2, 0x7c(r1)
	stfs     f0, 0x74(r1)
	stfs     f1, 0x78(r1)
	lfs      f0, 0x1c(r30)
	lfs      f5, 0x54(r30)
	fmuls    f4, f6, f0
	lfs      f3, 0x50(r30)
	fmuls    f2, f7, f0
	lfs      f1, 0x4c(r30)
	fmuls    f0, f8, f0
	fsubs    f4, f5, f4
	fsubs    f2, f3, f2
	fsubs    f0, f1, f0
	stfs     f4, 0x70(r1)
	stfs     f0, 0x68(r1)
	stfs     f2, 0x6c(r1)
	lwz      r12, 0(r28)
	lwz      r12, 0x184(r12)
	mtctr    r12
	bctrl
	mr       r3, r31
	addi     r4, r1, 0x68
	lwz      r12, 0(r31)
	addi     r5, r1, 0x80
	lwz      r12, 0x184(r12)
	mtctr    r12
	bctrl
	lfs      f2, 0x118(r28)
	lfs      f1, 0x118(r31)
	lfs      f0, lbl_80518288@sda21(r2)
	fadds    f1, f2, f1
	fcmpo    cr0, f1, f0
	ble      lbl_8013C528
	fdivs    f31, f2, f1
	lfs      f0, lbl_80518284@sda21(r2)
	fsubs    f30, f0, f31
	b        lbl_8013C530

lbl_8013C528:
	lfs      f30, lbl_8051828C@sda21(r2)
	fmr      f31, f30

lbl_8013C530:
	lwz      r4, sys@sda21(r13)
	mr       r3, r28
	lwz      r12, 0(r28)
	lfs      f1, lbl_80518284@sda21(r2)
	lfs      f0, 0x54(r4)
	lwz      r12, 0x1c(r12)
	fdivs    f29, f1, f0
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_8013C5E0
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8013C5E0
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x18(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8013C61C
	lfs      f1, lbl_8051828C@sda21(r2)
	lfs      f0, lbl_80518288@sda21(r2)
	fmuls    f1, f1, f29
	lfs      f3, 0(r26)
	fmuls    f0, f0, f29
	lfs      f2, 0x11c(r28)
	fmuls    f4, f31, f1
	fmuls    f1, f31, f0
	fmadds   f0, f3, f4, f2
	stfs     f0, 0x11c(r28)
	lfs      f2, 8(r26)
	lfs      f0, 0x124(r28)
	fmadds   f0, f2, f4, f0
	stfs     f0, 0x124(r28)
	lfs      f2, 4(r26)
	lfs      f0, 0x120(r28)
	fmadds   f0, f2, f1, f0
	stfs     f0, 0x120(r28)
	b        lbl_8013C61C

lbl_8013C5E0:
	lfs      f1, lbl_8051828C@sda21(r2)
	lfs      f0, lbl_80518288@sda21(r2)
	fmuls    f1, f1, f29
	lfs      f2, 0(r26)
	fmuls    f0, f0, f29
	fmuls    f3, f31, f1
	fmuls    f0, f31, f0
	fmuls    f1, f2, f3
	stfs     f1, 0x11c(r28)
	lfs      f1, 8(r26)
	fmuls    f1, f1, f3
	stfs     f1, 0x124(r28)
	lfs      f1, 4(r26)
	fmuls    f0, f1, f0
	stfs     f0, 0x120(r28)

lbl_8013C61C:
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_8013C6BC
	mr       r3, r28
	lwz      r12, 0(r28)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8013C6BC
	mr       r3, r28
	lwz      r12, 0(r28)
	lwz      r12, 0x18(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8013C704
	lfs      f0, lbl_8051828C@sda21(r2)
	lfs      f2, 0(r26)
	fmuls    f1, f0, f29
	lfs      f0, lbl_80518288@sda21(r2)
	fneg     f2, f2
	fmuls    f0, f0, f29
	fmuls    f3, f30, f1
	fmuls    f0, f30, f0
	fmuls    f1, f2, f3
	stfs     f1, 0x11c(r31)
	lfs      f1, 8(r26)
	fneg     f1, f1
	fmuls    f1, f1, f3
	stfs     f1, 0x124(r31)
	lfs      f1, 4(r26)
	fneg     f1, f1
	fmuls    f0, f1, f0
	stfs     f0, 0x120(r31)
	b        lbl_8013C704

lbl_8013C6BC:
	lfs      f0, lbl_8051828C@sda21(r2)
	lfs      f2, 0(r26)
	fmuls    f1, f0, f29
	lfs      f0, lbl_80518288@sda21(r2)
	fneg     f2, f2
	fmuls    f0, f0, f29
	fmuls    f3, f30, f1
	fmuls    f0, f30, f0
	fmuls    f1, f2, f3
	stfs     f1, 0x11c(r31)
	lfs      f1, 8(r26)
	fneg     f1, f1
	fmuls    f1, f1, f3
	stfs     f1, 0x124(r31)
	lfs      f1, 4(r26)
	fneg     f1, f1
	fmuls    f0, f1, f0
	stfs     f0, 0x120(r31)

lbl_8013C704:
	lfs      f2, 0x11c(r28)
	lfs      f1, 0x120(r28)
	fmuls    f0, f2, f2
	lfs      f3, 0x124(r28)
	fmuls    f4, f1, f1
	lfs      f1, lbl_80518288@sda21(r2)
	fmuls    f3, f3, f3
	fadds    f0, f0, f4
	fadds    f0, f3, f0
	fcmpo    cr0, f0, f1
	ble      lbl_8013C74C
	fmadds   f0, f2, f2, f4
	fadds    f3, f3, f0
	fcmpo    cr0, f3, f1
	ble      lbl_8013C750
	frsqrte  f0, f3
	fmuls    f3, f0, f3
	b        lbl_8013C750

lbl_8013C74C:
	fmr      f3, f1

lbl_8013C750:
	lfs      f2, lbl_805182A0@sda21(r2)
	fcmpo    cr0, f3, f2
	ble      lbl_8013C78C
	lfs      f1, lbl_80518284@sda21(r2)
	lfs      f0, 0x11c(r28)
	fdivs    f1, f1, f3
	fmuls    f1, f2, f1
	fmuls    f0, f0, f1
	stfs     f0, 0x11c(r28)
	lfs      f0, 0x120(r28)
	fmuls    f0, f0, f1
	stfs     f0, 0x120(r28)
	lfs      f0, 0x124(r28)
	fmuls    f0, f0, f1
	stfs     f0, 0x124(r28)

lbl_8013C78C:
	lfs      f2, 0x11c(r31)
	lfs      f1, 0x120(r31)
	fmuls    f0, f2, f2
	lfs      f3, 0x124(r31)
	fmuls    f4, f1, f1
	lfs      f1, lbl_80518288@sda21(r2)
	fmuls    f3, f3, f3
	fadds    f0, f0, f4
	fadds    f0, f3, f0
	fcmpo    cr0, f0, f1
	ble      lbl_8013C7D4
	fmadds   f0, f2, f2, f4
	fadds    f3, f3, f0
	fcmpo    cr0, f3, f1
	ble      lbl_8013C7D8
	frsqrte  f0, f3
	fmuls    f3, f0, f3
	b        lbl_8013C7D8

lbl_8013C7D4:
	fmr      f3, f1

lbl_8013C7D8:
	lfs      f2, lbl_805182A0@sda21(r2)
	fcmpo    cr0, f3, f2
	ble      lbl_8013C814
	lfs      f1, lbl_80518284@sda21(r2)
	lfs      f0, 0x11c(r31)
	fdivs    f1, f1, f3
	fmuls    f1, f2, f1
	fmuls    f0, f0, f1
	stfs     f0, 0x11c(r31)
	lfs      f0, 0x120(r31)
	fmuls    f0, f0, f1
	stfs     f0, 0x120(r31)
	lfs      f0, 0x124(r31)
	fmuls    f0, f0, f1
	stfs     f0, 0x124(r31)

lbl_8013C814:
	clrlwi.  r0, r27, 0x18
	beq      lbl_8013C838
	lfs      f0, lbl_80518288@sda21(r2)
	stfs     f0, 0x11c(r28)
	stfs     f0, 0x120(r28)
	stfs     f0, 0x124(r28)
	stfs     f0, 0x11c(r31)
	stfs     f0, 0x120(r31)
	stfs     f0, 0x124(r31)

lbl_8013C838:
	lfs      f1, 0x90(r1)
	mr       r3, r28
	lfs      f0, 0x84(r1)
	addi     r4, r1, 0x5c
	lfs      f3, 0x8c(r1)
	lfs      f2, 0x80(r1)
	fsubs    f1, f1, f0
	lfs      f0, 0x9c(r1)
	fsubs    f2, f3, f2
	stw      r31, 0x5c(r1)
	fmuls    f0, f1, f0
	lfs      f1, 0x98(r1)
	stw      r30, 0x60(r1)
	lfs      f3, 0x94(r1)
	stw      r29, 0x64(r1)
	fmadds   f0, f2, f1, f0
	lfs      f1, 0x88(r1)
	lwz      r12, 0(r28)
	fsubs    f2, f3, f1
	lfs      f1, 0xa0(r1)
	lwz      r12, 0xec(r12)
	fmadds   f29, f2, f1, f0
	mtctr    r12
	bctrl
	stw      r28, 0x50(r1)
	mr       r3, r31
	addi     r4, r1, 0x50
	stw      r29, 0x54(r1)
	stw      r30, 0x58(r1)
	lwz      r12, 0(r31)
	lwz      r12, 0xec(r12)
	mtctr    r12
	bctrl
	lfs      f0, lbl_80518288@sda21(r2)
	fcmpo    cr0, f29, f0
	cror     2, 0, 2
	bne      lbl_8013C914
	mr       r3, r28
	lwz      r12, 0(r28)
	lwz      r12, 0xd8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_8013CB60
	mr       r3, r28
	lwz      r12, 0(r28)
	lwz      r12, 0x1a8(r12)
	mtctr    r12
	bctrl
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x1a8(r12)
	mtctr    r12
	bctrl
	b        lbl_8013CB60

lbl_8013C914:
	mr       r3, r28
	lwz      r12, 0(r28)
	lwz      r12, 0xd8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r27, 0x18
	beq      lbl_8013C948
	mr       r3, r28
	lwz      r12, 0(r28)
	lwz      r12, 0xd8(r12)
	mtctr    r12
	bctrl
	b        lbl_8013CB60

lbl_8013C948:
	mr       r3, r28
	lfs      f30, lbl_805182A4@sda21(r2)
	lwz      r12, 0(r28)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8013C984
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_8013C988

lbl_8013C984:
	lfs      f30, lbl_80518288@sda21(r2)

lbl_8013C988:
	lfs      f0, lbl_80518284@sda21(r2)
	li       r27, 0
	lfs      f2, 0x118(r28)
	fadds    f3, f0, f30
	lfs      f1, 0x118(r31)
	lfs      f0, lbl_80518288@sda21(r2)
	fadds    f2, f2, f1
	fneg     f1, f3
	fmr      f30, f2
	fcmpu    cr0, f0, f2
	fmuls    f29, f1, f29
	bne      lbl_8013C9C0
	lfs      f30, lbl_805182A8@sda21(r2)
	li       r27, 1

lbl_8013C9C0:
	mr       r3, r28
	addi     r4, r1, 0x74
	lwz      r12, 0(r28)
	addi     r5, r1, 0x98
	lwz      r12, 0x188(r12)
	mtctr    r12
	bctrl
	mr       r3, r31
	fadds    f30, f30, f1
	lwz      r12, 0(r31)
	addi     r4, r1, 0x68
	addi     r5, r1, 0x98
	lwz      r12, 0x188(r12)
	mtctr    r12
	bctrl
	fadds    f30, f30, f1
	lfs      f1, 0xa0(r1)
	lfs      f6, 0x9c(r1)
	clrlwi.  r0, r27, 0x18
	lfs      f7, 0x98(r1)
	fdivs    f2, f29, f30
	fneg     f5, f2
	fmuls    f0, f1, f2
	fmuls    f3, f6, f2
	fmuls    f4, f1, f5
	fmuls    f2, f7, f2
	stfs     f0, 0x4c(r1)
	fmuls    f1, f7, f5
	fmuls    f0, f6, f5
	stfs     f3, 0x48(r1)
	stfs     f2, 0x44(r1)
	stfs     f1, 0x38(r1)
	stfs     f0, 0x3c(r1)
	stfs     f4, 0x40(r1)
	bne      lbl_8013CA88
	mr       r3, r28
	addi     r4, r1, 0x74
	lwz      r12, 0(r28)
	addi     r5, r1, 0x44
	lwz      r12, 0x18c(r12)
	mtctr    r12
	bctrl
	mr       r3, r31
	addi     r4, r1, 0x68
	lwz      r12, 0(r31)
	addi     r5, r1, 0x38
	lwz      r12, 0x18c(r12)
	mtctr    r12
	bctrl
	b        lbl_8013CB60

lbl_8013CA88:
	mr       r4, r28
	addi     r3, r1, 0x14
	lwz      r12, 0(r28)
	lwz      r12, 0x6c(r12)
	mtctr    r12
	bctrl
	lfs      f5, 0x14(r1)
	mr       r3, r28
	lfs      f4, 0x18(r1)
	addi     r4, r1, 0x2c
	lfs      f3, 0x1c(r1)
	lfs      f2, 0x4c(r1)
	lfs      f1, 0x48(r1)
	lfs      f0, 0x44(r1)
	fadds    f2, f3, f2
	stfs     f3, 0x34(r1)
	fadds    f1, f4, f1
	fadds    f0, f5, f0
	stfs     f5, 0x2c(r1)
	stfs     f4, 0x30(r1)
	stfs     f0, 0x2c(r1)
	stfs     f1, 0x30(r1)
	stfs     f2, 0x34(r1)
	lwz      r12, 0(r28)
	lwz      r12, 0x68(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	addi     r3, r1, 8
	lwz      r12, 0(r31)
	lwz      r12, 0x6c(r12)
	mtctr    r12
	bctrl
	lfs      f5, 8(r1)
	mr       r3, r31
	lfs      f4, 0xc(r1)
	addi     r4, r1, 0x20
	lfs      f3, 0x10(r1)
	lfs      f2, 0x40(r1)
	lfs      f1, 0x3c(r1)
	lfs      f0, 0x38(r1)
	fadds    f2, f3, f2
	stfs     f3, 0x28(r1)
	fadds    f1, f4, f1
	fadds    f0, f5, f0
	stfs     f5, 0x20(r1)
	stfs     f4, 0x24(r1)
	stfs     f0, 0x20(r1)
	stfs     f1, 0x24(r1)
	stfs     f2, 0x28(r1)
	lwz      r12, 0(r31)
	lwz      r12, 0x68(r12)
	mtctr    r12
	bctrl

lbl_8013CB60:
	psq_l    f31, 232(r1), 0, qr0
	lfd      f31, 0xe0(r1)
	psq_l    f30, 216(r1), 0, qr0
	lfd      f30, 0xd0(r1)
	psq_l    f29, 200(r1), 0, qr0
	lfd      f29, 0xc0(r1)
	lmw      r26, 0xa8(r1)
	lwz      r0, 0xf4(r1)
	mtlr     r0
	addi     r1, r1, 0xf0
	blr
	*/
}

/*
 * --INFO--
 * Address:	8013CB8C
 * Size:	000004
 */
void Creature::collisionCallback(Game::CollEvent&) { }

} // namespace Game

/*
 * --INFO--
 * Address:	8013CB90
 * Size:	000030
 */
template <> void Delegate3<Game::Creature, CollPart*, CollPart*, Vector3f&>::invoke(CollPart*, CollPart*, Vector3f&)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x10(r1)
	  mflr      r0
	  mr        r7, r3
	  stw       r0, 0x14(r1)
	  addi      r12, r7, 0x8
	  lwz       r3, 0x4(r3)
	  bl        -0x7B084
	  nop
	  lwz       r0, 0x14(r1)
	  mtlr      r0
	  addi      r1, r1, 0x10
	  blr
	*/
}

namespace Game {

/*
 * --INFO--
 * Address:	8013CBC0
 * Size:	000004
 */
void Creature::constructor() { }

/*
 * --INFO--
 * Address:	8013CBC4
 * Size:	000004
 */
void Creature::doSimulation(float) { }

/*
 * --INFO--
 * Address:	8013CBC8
 * Size:	000008
 */
bool Creature::inWater() { return false; }

/*
 * --INFO--
 * Address:	8013CBD0
 * Size:	000008
 */
bool Creature::isFlying() { return false; }

/*
 * --INFO--
 * Address:	8013CBD8
 * Size:	000008
 */
PSM::Creature* Creature::getPSCreature() { return nullptr; }

/*
 * --INFO--
 * Address:	8013CBE0
 * Size:	000008
 */
Vector3f* Creature::getSound_PosPtr() { return nullptr; }

/*
 * --INFO--
 * Address:	8013CBE8
 * Size:	000008
 */
float Creature::getSound_CurrAnimFrame() { return 0.0f; }

/*
 * --INFO--
 * Address:	8013CBF0
 * Size:	000008
 */
float Creature::getSound_CurrAnimSpeed() { return 0.0f; }

/*
 * --INFO--
 * Address:	8013CBF8
 * Size:	00002C
 */
void Creature::getLODSphere(Sys::Sphere& sphere) { return getBoundingSphere(sphere); }

/*
 * --INFO--
 * Address:	8013CC24
 * Size:	000004
 */
void Creature::onStickStart(Game::Creature*) { }

/*
 * --INFO--
 * Address:	8013CC28
 * Size:	000004
 */
void Creature::onStickEnd(Game::Creature*) { }

/*
 * --INFO--
 * Address:	8013CC2C
 * Size:	000004
 */
void CellObject::checkCollision(Game::CellObject*) { }

/*
 * --INFO--
 * Address:	8013CC30
 * Size:	000008
 */
bool CellObject::isPiki() { return false; }

/*
 * --INFO--
 * Address:	8013CC38
 * Size:	000008
 */
bool CellObject::isNavi() { return false; }

} // namespace Game

/*
 * --INFO--
 * Address:	8013CC40
 * Size:	000028
 */
void __sinit_creature_cpp(void)
{
	/*
	lis      r4, __float_nan@ha
	li       r0, -1
	lfs      f0, __float_nan@l(r4)
	lis      r3, lbl_804B0098@ha
	stw      r0, lbl_805158F0@sda21(r13)
	stfsu    f0, lbl_804B0098@l(r3)
	stfs     f0, lbl_805158F4@sda21(r13)
	stfs     f0, 4(r3)
	stfs     f0, 8(r3)
	blr
	*/
}
