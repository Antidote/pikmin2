#include "Game/pathfinder.h"
#include "System.h"
#include "Game/routeMgr.h"

/*
    Generated from dpostproc

    .section .rodata  # 0x804732E0 - 0x8049E220
    .global lbl_8047F400
    lbl_8047F400:
        .asciz "pathfinder"
        .skip 1
    .global lbl_8047F40C
    lbl_8047F40C:
        .asciz "pathfinder.cpp"
        .skip 1
        .asciz "Oh! no!\n"
        .skip 3
        .asciz "no context is available (clients=%d)!\n"
        .skip 1
        .asciz "context state is %d\n"
        .skip 3
        .asciz "no such handle %d\n"
        .skip 1
    .global lbl_8047F47C
    lbl_8047F47C:
        .asciz " no handle ! %d\n"
        .skip 3

    .section .sbss # 0x80514D80 - 0x80516360
    .global testPathfinder__4Game
    testPathfinder__4Game:
        .skip 0x4
    .global routeMgr__Q24Game15PathfindContext
    routeMgr__Q24Game15PathfindContext:
        .skip 0x4

    .section .sdata2, "a"     # 0x80516360 - 0x80520E40
    .global lbl_80519178
    lbl_80519178:
        .asciz "path"
        .skip 3
    .global lbl_80519180
    lbl_80519180:
        .float 1280000.0
    .global lbl_80519184
    lbl_80519184:
        .float 0.0
*/

namespace Game {

Pathfinder* testPathfinder;
Game::RouteMgr* Game::PathfindContext::routeMgr;

/*
 * --INFO--
 * Address:	801A35EC
 * Size:	000060
 */
Pathfinder::Pathfinder()
{
	mAStarPathfinder   = new AStarPathfinder;
	mAStarContextCount = 0;
	mClientCount       = 0;
	mAStarContexts     = nullptr;
	mCounter           = 1;
}

/*
 * --INFO--
 * Address:	801A364C
 * Size:	0000C4
 */
void Pathfinder::create(int contextCount, Game::RouteMgr* routeMgr)
{
	sys->heapStatusStart("pathfinder", nullptr);
	mClientCount       = 0;
	mAStarContextCount = contextCount;
	mAStarContexts     = new AStarContext[contextCount];
	for (int i = 0; i < contextCount; i++) {
		mAStarContexts[i].init(routeMgr, 0);
	}
	mCounter = 1;
	sys->heapStatusEnd("pathfinder");
}

/*
 * --INFO--
 * Address:	801A3710
 * Size:	000020
 */
// AStarContext::AStarContext() { }

/*
 * --INFO--
 * Address:	801A3730
 * Size:	000124
 */
void Pathfinder::update()
{
	sys->mTimers->_start("path", true);

	int counts = 0;
	for (int i = 0; i < mAStarContextCount; i++) {
		bool check = mAStarContexts[i].mStatus && mAStarContexts[i].mCheckHandle == 2;
		if (check) {
			counts++;
		}
	}

	if (counts > 0) {
		for (int i = 0; i < mAStarContextCount; i++) {
			AStarContext* context = &mAStarContexts[i];
			bool check            = context->mStatus && context->mCheckHandle == 2;
			if (check) {
				mAStarContexts[i].mCheckHandle = mAStarPathfinder->search(context, 1, &context->mNode);
			}
		}
	}

	sys->mTimers->_stop("path");

	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	addi     r4, r2, lbl_80519178@sda21
	li       r5, 1
	stw      r0, 0x24(r1)
	stw      r31, 0x1c(r1)
	mr       r31, r3
	stw      r30, 0x18(r1)
	stw      r29, 0x14(r1)
	lwz      r6, sys@sda21(r13)
	lwz      r3, 0x28(r6)
	bl       _start__9SysTimersFPcb
	lwz      r0, 8(r31)
	li       r6, 0
	li       r5, 0
	mtctr    r0
	cmpwi    r0, 0
	ble      lbl_801A37B4

lbl_801A3778:
	lwz      r0, 0xc(r31)
	li       r3, 0
	add      r4, r0, r5
	lwz      r0, 0x60(r4)
	cmplwi   r0, 0
	beq      lbl_801A37A0
	lbz      r0, 0x54(r4)
	cmplwi   r0, 2
	bne      lbl_801A37A0
	li       r3, 1

lbl_801A37A0:
	clrlwi.  r0, r3, 0x18
	beq      lbl_801A37AC
	addi     r6, r6, 1

lbl_801A37AC:
	addi     r5, r5, 0x64
	bdnz     lbl_801A3778

lbl_801A37B4:
	cmpwi    r6, 0
	ble      lbl_801A3828
	li       r29, 0
	li       r30, 0
	b        lbl_801A381C

lbl_801A37C8:
	lwz      r0, 0xc(r31)
	li       r3, 0
	add      r4, r0, r30
	lwz      r0, 0x60(r4)
	cmplwi   r0, 0
	beq      lbl_801A37F0
	lbz      r0, 0x54(r4)
	cmplwi   r0, 2
	bne      lbl_801A37F0
	li       r3, 1

lbl_801A37F0:
	clrlwi.  r0, r3, 0x18
	beq      lbl_801A3814
	lwz      r3, 0x10(r31)
	addi     r6, r4, 0x5c
	li       r5, 1
	bl
search__Q24Game15AStarPathfinderFPQ24Game12AStarContextiPPQ24Game8PathNode lwz
r4, 0xc(r31) addi     r0, r30, 0x54 stbx     r3, r4, r0

lbl_801A3814:
	addi     r30, r30, 0x64
	addi     r29, r29, 1

lbl_801A381C:
	lwz      r0, 8(r31)
	cmpw     r29, r0
	blt      lbl_801A37C8

lbl_801A3828:
	lwz      r3, sys@sda21(r13)
	addi     r4, r2, lbl_80519178@sda21
	lwz      r3, 0x28(r3)
	bl       _stop__9SysTimersFPc
	lwz      r0, 0x24(r1)
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
 * Address:	........
 * Size:	000024
 */
void Pathfinder::getFreeContext()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
AStarContext* Pathfinder::getContext(u32 id)
{
	for (int i = 0; i < mAStarContextCount; i++) {
		if (mAStarContexts[i].mStatus == id) {
			return mAStarContexts + i;
		}
	}
	return nullptr;
}
/*
 * --INFO--
 * Address:	801A3854
 * Size:	00014C
 */
int Pathfinder::start(PathfindRequest& request)
{
	if (mClientCount >= mAStarContextCount) {
		JUT_PANICLINE(250, "Oh! no!\n");
		return 0;
	} else {
		int wpNum = mCounter++;
		if (20000 <= mCounter) {
			mCounter = 1;
		}

		AStarContext* context = getContext(0);

		JUT_ASSERTLINE(258, context, "no context is available (clients=%d)!\n", mClientCount);
		mClientCount++;
		context->mStatus      = 0;
		context->mCheckHandle = 2;
		context->mStatus      = wpNum;
		context->mStartWPID   = request.mStartWpID;
		context->mEndWPID     = request.mEndWpID;
		context->mRequestFlag = request.mFlag;
		mAStarPathfinder->initsearch(context);
		return wpNum;
	}
}

/*
 * --INFO--
 * Address:	801A39A0
 * Size:	0000C0
 */
int Pathfinder::makepath(u32 id, Game::PathNode** path)
{
	AStarContext* context = getContext(id);

	if (context) {
		if (!context->mCheckHandle) {
			return context->makepath(context->mNode, path);
		}
		JUT_PANICLINE(290, "context state is %d\n", context->mCheckHandle);
	} else {
		JUT_PANICLINE(293, "no such handle %d\n", id);
	}
	return 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
int Pathfinder::makepath(unsigned long, short*, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801A3A60
 * Size:	000070
 */
void Pathfinder::release(u32 id)
{
	AStarContext* context = getContext(id);
	if (context) {
		mClientCount--;
		context->mStatus      = 0;
		context->mCheckHandle = 2;
	}
}

/*
 * --INFO--
 * Address:	801A3AD0
 * Size:	000098
 */
int Pathfinder::check(u32 id)
{
	AStarContext* context = getContext(id);
	if (context) {
		return context->mCheckHandle;
	}
	JUT_PANICLINE(332, " no handle ! %d\n", id);
	return 3;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void PathNode::initNode()
{
	// UNUSED FUNCTION
	_18    = nullptr;
	_14    = nullptr;
	_1C    = nullptr;
	_10    = nullptr;
	mChild = nullptr;
	mNext  = nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void PathNode::add(Game::PathNode* newNode)
{
	// UNUSED FUNCTION
	if (_1C != nullptr) {
		PathNode* node;
		for (node = _14; node->_14 != nullptr;) {
			node = node->_14;
		}
		node->_14    = newNode;
		newNode->_18 = node;
	} else {
		_1C = newNode;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void PathNode::del()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void PathNode::dump(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000DC
 */
void PathNode::pop()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void PathNode::countLinks(Game::PathNode**)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801A3B68
 * Size:	000078
 */
void AStarContext::init(RouteMgr* mgr, int wpNum)
{
	if (mgr) {
		PathfindContext::routeMgr = mgr;
		mUsedNodeCount            = 0;
		if (wpNum <= 0) {
			mWpNum = PathfindContext::routeMgr->mCount;
		} else {
			mWpNum = wpNum;
		}
		_58          = new PathNode[mWpNum]; // not sure what this type is
		mStatus      = 0;
		mCheckHandle = 2;
	}
}

/*
 * --INFO--
 * Address:	801A3BE0
 * Size:	00000C
 */
AStarPathfinder::AStarPathfinder() { mContext = nullptr; }

/*
 * --INFO--
 * Address:	801A3BEC
 * Size:	000008
 */
void AStarPathfinder::setContext(AStarContext* context) { mContext = context; }

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
PathNode* AStarContext::getNode(short wpID)
{
	// UNUSED FUNCTION
	PathNode* node;
	for (int i = 0; i < mUsedNodeCount; i++) {
		if (wpID == _58[i].mWpIndex) {
			return _58 + i;
		}
	}
	if (mUsedNodeCount < mWpNum) {
		node = _58 + mUsedNodeCount++;
		node->initNode();
		node->mWpIndex = wpID;
		node->_22      = 2;
		return node;
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000558
 */
void AStarPathfinder::search(short, short, short*, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00057C
 */
void AStarPathfinder::search(Game::AStarContext*, short, short, short*, int, int, int&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801A3BF4
 * Size:	00017C
 */
void AStarPathfinder::initsearch(Game::AStarContext* context)
{
	s16 startID = context->mStartWPID;
	s16 endID   = context->mEndWPID;
	setContext(context);
	mContext->_08[0].initNode();
	mContext->_08[1].initNode();
	mContext->mUsedNodeCount = 0;
	PathNode* node           = mContext->getNode(startID);
	node->mWpIndex           = startID;
	node->_00                = 0.0f;
	node->_04                = estimate(startID, endID);
	node->mChild             = nullptr;
	node->_22                = 0;
	mContext->_08[0].add(node);
	node->_10 = mContext->_08 + 0;
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	li       r6, 0
	stw      r0, 0x14(r1)
	mr       r7, r6
	stw      r31, 0xc(r1)
	mr       r31, r3
	stw      r30, 8(r1)
	lha      r10, 0(r4)
	lha      r5, 2(r4)
	stw      r4, 0(r3)
	lwz      r3, 0(r3)
	stw      r6, 0x20(r3)
	stw      r6, 0x1c(r3)
	stw      r6, 0x24(r3)
	stw      r6, 0x18(r3)
	stw      r6, 0x10(r3)
	stw      r6, 0x14(r3)
	lwz      r3, 0(r31)
	stw      r6, 0x44(r3)
	stw      r6, 0x40(r3)
	stw      r6, 0x48(r3)
	stw      r6, 0x3c(r3)
	stw      r6, 0x34(r3)
	stw      r6, 0x38(r3)
	lwz      r3, 0(r31)
	sth      r6, 0x50(r3)
	lwz      r8, 0(r31)
	lha      r9, 0x50(r8)
	mtctr    r9
	cmpwi    r9, 0
	ble      lbl_801A3CA0

lbl_801A3C74:
	lwz      r3, 0x58(r8)
	addi     r0, r7, 0x20
	lhax     r0, r3, r0
	cmpw     r10, r0
	bne      lbl_801A3C94
	mulli    r0, r6, 0x24
	add      r30, r3, r0
	b        lbl_801A3CF4

lbl_801A3C94:
	addi     r7, r7, 0x24
	addi     r6, r6, 1
	bdnz     lbl_801A3C74

lbl_801A3CA0:
	lha      r0, 0x52(r8)
	cmpw     r9, r0
	bge      lbl_801A3CF0
	lha      r4, 0x50(r8)
	mulli    r6, r9, 0x24
	lwz      r7, 0x58(r8)
	li       r3, 0
	addi     r0, r4, 1
	sth      r0, 0x50(r8)
	add      r30, r7, r6
	li       r0, 2
	stw      r3, 0x18(r30)
	stw      r3, 0x14(r30)
	stw      r3, 0x1c(r30)
	stw      r3, 0x10(r30)
	stw      r3, 8(r30)
	stw      r3, 0xc(r30)
	sth      r10, 0x20(r30)
	stb      r0, 0x22(r30)
	b        lbl_801A3CF4

lbl_801A3CF0:
	li       r30, 0

lbl_801A3CF4:
	sth      r10, 0x20(r30)
	mr       r3, r31
	lfs      f0, lbl_80519184@sda21(r2)
	mr       r4, r10
	stfs     f0, 0(r30)
	bl       estimate__Q24Game15AStarPathfinderFss
	stfs     f1, 4(r30)
	li       r0, 0
	stw      r0, 8(r30)
	stb      r0, 0x22(r30)
	lwz      r3, 0(r31)
	addi     r4, r3, 8
	lwz      r3, 0x24(r3)
	cmplwi   r3, 0
	beq      lbl_801A3D50
	b        lbl_801A3D38

lbl_801A3D34:
	mr       r3, r0

lbl_801A3D38:
	lwz      r0, 0x14(r3)
	cmplwi   r0, 0
	bne      lbl_801A3D34
	stw      r30, 0x14(r3)
	stw      r3, 0x18(r30)
	b        lbl_801A3D54

lbl_801A3D50:
	stw      r30, 0x1c(r4)

lbl_801A3D54:
	stw      r4, 0x10(r30)
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
 * Address:	801A3D70
 * Size:	0004B8
 */
int AStarPathfinder::search(Game::AStarContext*, int, Game::PathNode**)
{
	/*
	stwu     r1, -0x40(r1)
	mflr     r0
	stw      r0, 0x44(r1)
	stmw     r24, 0x20(r1)
	mr       r24, r3
	mr       r25, r6
	mr       r28, r5
	stw      r4, 0(r3)
	lha      r29, 2(r4)
	b        lbl_801A41E4

lbl_801A3D98:
	lfs      f2, lbl_80519180@sda21(r2)
	li       r31, 0
	b        lbl_801A3DC4

lbl_801A3DA4:
	lfs      f1, 0(r3)
	lfs      f0, 4(r3)
	fadds    f0, f1, f0
	fcmpo    cr0, f0, f2
	bge      lbl_801A3DC0
	fmr      f2, f0
	mr       r31, r3

lbl_801A3DC0:
	lwz      r3, 0x14(r3)

lbl_801A3DC4:
	cmplwi   r3, 0
	bne      lbl_801A3DA4
	cmplwi   r31, 0
	beq      lbl_801A3E68
	lwz      r5, 0x10(r31)
	cmplwi   r5, 0
	beq      lbl_801A3E68
	lwz      r4, 0x1c(r5)
	li       r3, 0
	b        lbl_801A3E60

lbl_801A3DEC:
	cmplw    r4, r31
	bne      lbl_801A3E58
	cmplwi   r3, 0
	beq      lbl_801A3E28
	lwz      r0, 0x14(r4)
	stw      r0, 0x14(r3)
	lwz      r4, 0x14(r4)
	cmplwi   r4, 0
	beq      lbl_801A3E14
	stw      r3, 0x18(r4)

lbl_801A3E14:
	li       r0, 0
	stw      r0, 0x18(r31)
	stw      r0, 0x14(r31)
	stw      r0, 0x10(r31)
	b        lbl_801A3E68

lbl_801A3E28:
	lwz      r0, 0x14(r4)
	stw      r0, 0x1c(r5)
	lwz      r3, 0x14(r4)
	cmplwi   r3, 0
	beq      lbl_801A3E44
	li       r0, 0
	stw      r0, 0x18(r3)

lbl_801A3E44:
	li       r0, 0
	stw      r0, 0x18(r31)
	stw      r0, 0x14(r31)
	stw      r0, 0x10(r31)
	b        lbl_801A3E68

lbl_801A3E58:
	mr       r3, r4
	lwz      r4, 0x14(r4)

lbl_801A3E60:
	cmplwi   r4, 0
	bne      lbl_801A3DEC

lbl_801A3E68:
	lha      r4, 0x20(r31)
	cmpw     r4, r29
	bne      lbl_801A3E80
	stw      r31, 0(r25)
	li       r3, 0
	b        lbl_801A4214

lbl_801A3E80:
	lwz      r3, routeMgr__Q24Game15PathfindContext@sda21(r13)
	lwz      r12, 0(r3)
	lwz      r12, 0x2c(r12)
	mtctr    r12
	bctrl
	lwz      r4, 0(r24)
	mr       r27, r3
	addi     r3, r1, 8
	lbz      r0, 4(r4)
	mr       r4, r27
	rlwinm   r5, r0, 0x19, 0x1f, 0x1f
	bl       __ct__Q24Game16WayPointIteratorFPQ24Game8WayPointb
	addi     r3, r1, 8
	bl       first__Q24Game16WayPointIteratorFv
	b        lbl_801A3ECC

lbl_801A3EBC:
	addi     r3, r1, 8
	bl       __ml__Q24Game16WayPointIteratorFv
	addi     r3, r1, 8
	bl       next__Q24Game16WayPointIteratorFv

lbl_801A3ECC:
	addi     r3, r1, 8
	bl       isDone__Q24Game16WayPointIteratorFv
	clrlwi.  r0, r3, 0x18
	beq      lbl_801A3EBC
	addi     r3, r1, 8
	bl       first__Q24Game16WayPointIteratorFv
	b        lbl_801A418C

lbl_801A3EE8:
	addi     r3, r1, 8
	bl       __ml__Q24Game16WayPointIteratorFv
	mr       r0, r3
	lwz      r3, routeMgr__Q24Game15PathfindContext@sda21(r13)
	mr       r26, r0
	lwz      r12, 0(r3)
	mr       r4, r26
	lwz      r12, 0x2c(r12)
	mtctr    r12
	bctrl
	lwz      r8, 0(r24)
	li       r5, 0
	mr       r6, r5
	extsh    r4, r26
	lha      r9, 0x50(r8)
	mtctr    r9
	cmpwi    r9, 0
	ble      lbl_801A3F5C

lbl_801A3F30:
	lwz      r7, 0x58(r8)
	addi     r0, r6, 0x20
	lhax     r0, r7, r0
	cmpw     r4, r0
	bne      lbl_801A3F50
	mulli    r0, r5, 0x24
	add      r30, r7, r0
	b        lbl_801A3FB0

lbl_801A3F50:
	addi     r6, r6, 0x24
	addi     r5, r5, 1
	bdnz     lbl_801A3F30

lbl_801A3F5C:
	lha      r0, 0x52(r8)
	cmpw     r9, r0
	bge      lbl_801A3FAC
	lha      r5, 0x50(r8)
	mulli    r6, r9, 0x24
	lwz      r7, 0x58(r8)
	li       r4, 0
	addi     r0, r5, 1
	sth      r0, 0x50(r8)
	add      r30, r7, r6
	li       r0, 2
	stw      r4, 0x18(r30)
	stw      r4, 0x14(r30)
	stw      r4, 0x1c(r30)
	stw      r4, 0x10(r30)
	stw      r4, 8(r30)
	stw      r4, 0xc(r30)
	sth      r26, 0x20(r30)
	stb      r0, 0x22(r30)
	b        lbl_801A3FB0

lbl_801A3FAC:
	li       r30, 0

lbl_801A3FB0:
	lwz      r4, 0(r24)
	lbz      r4, 4(r4)
	clrlwi.  r0, r4, 0x1f
	beq      lbl_801A3FCC
	lbz      r0, 0x34(r3)
	clrlwi.  r0, r0, 0x1f
	bne      lbl_801A4184

lbl_801A3FCC:
	rlwinm.  r0, r4, 0, 0x1e, 0x1e
	bne      lbl_801A3FE0
	lbz      r0, 0x34(r3)
	rlwinm.  r0, r0, 0, 0x1e, 0x1e
	bne      lbl_801A4184

lbl_801A3FE0:
	rlwinm.  r0, r4, 0, 0x19, 0x19
	bne      lbl_801A3FF4
	lbz      r0, 0x34(r3)
	rlwinm.  r0, r0, 0, 0x18, 0x18
	bne      lbl_801A4184

lbl_801A3FF4:
	lbz      r0, 0x34(r27)
	rlwinm.  r0, r0, 0, 0x1e, 0x1e
	beq      lbl_801A4014
	rlwinm.  r0, r4, 0, 0x1d, 0x1d
	beq      lbl_801A4014
	lbz      r0, 0x34(r3)
	rlwinm.  r0, r0, 0, 0x1d, 0x1d
	bne      lbl_801A4184

lbl_801A4014:
	rlwinm.  r0, r4, 0, 0x1a, 0x1a
	beq      lbl_801A4028
	lbz      r0, 0x34(r3)
	rlwinm.  r0, r0, 0, 0x1a, 0x1a
	bne      lbl_801A4184

lbl_801A4028:
	rlwinm.  r0, r4, 0, 0x1b, 0x1b
	beq      lbl_801A403C
	lbz      r0, 0x34(r3)
	rlwinm.  r0, r0, 0, 0x1b, 0x1b
	bne      lbl_801A4184

lbl_801A403C:
	lha      r4, 0x20(r31)
	mr       r3, r24
	lha      r5, 0x20(r30)
	bl       estimate__Q24Game15AStarPathfinderFss
	lfs      f0, 0(r31)
	lbz      r0, 0x22(r30)
	fadds    f1, f0, f1
	cmplwi   r0, 2
	beq      lbl_801A4070
	lfs      f0, 0(r30)
	fcmpo    cr0, f0, f1
	cror     2, 0, 2
	beq      lbl_801A4184

lbl_801A4070:
	stw      r31, 8(r30)
	mr       r3, r24
	mr       r5, r29
	stfs     f1, 0(r30)
	lha      r4, 0x20(r30)
	bl       estimate__Q24Game15AStarPathfinderFss
	stfs     f1, 4(r30)
	lbz      r0, 0x22(r30)
	cmplwi   r0, 1
	bne      lbl_801A4134
	lwz      r5, 0x10(r30)
	cmplwi   r5, 0
	beq      lbl_801A412C
	lwz      r4, 0x1c(r5)
	li       r3, 0
	b        lbl_801A4124

lbl_801A40B0:
	cmplw    r4, r30
	bne      lbl_801A411C
	cmplwi   r3, 0
	beq      lbl_801A40EC
	lwz      r0, 0x14(r4)
	stw      r0, 0x14(r3)
	lwz      r4, 0x14(r4)
	cmplwi   r4, 0
	beq      lbl_801A40D8
	stw      r3, 0x18(r4)

lbl_801A40D8:
	li       r0, 0
	stw      r0, 0x18(r30)
	stw      r0, 0x14(r30)
	stw      r0, 0x10(r30)
	b        lbl_801A412C

lbl_801A40EC:
	lwz      r0, 0x14(r4)
	stw      r0, 0x1c(r5)
	lwz      r3, 0x14(r4)
	cmplwi   r3, 0
	beq      lbl_801A4108
	li       r0, 0
	stw      r0, 0x18(r3)

lbl_801A4108:
	li       r0, 0
	stw      r0, 0x18(r30)
	stw      r0, 0x14(r30)
	stw      r0, 0x10(r30)
	b        lbl_801A412C

lbl_801A411C:
	mr       r3, r4
	lwz      r4, 0x14(r4)

lbl_801A4124:
	cmplwi   r4, 0
	bne      lbl_801A40B0

lbl_801A412C:
	li       r0, 2
	stb      r0, 0x22(r30)

lbl_801A4134:
	lbz      r0, 0x22(r30)
	cmplwi   r0, 0
	beq      lbl_801A4184
	li       r0, 0
	stb      r0, 0x22(r30)
	lwz      r3, 0(r24)
	addi     r4, r3, 8
	lwz      r3, 0x24(r3)
	cmplwi   r3, 0
	beq      lbl_801A417C
	b        lbl_801A4164

lbl_801A4160:
	mr       r3, r0

lbl_801A4164:
	lwz      r0, 0x14(r3)
	cmplwi   r0, 0
	bne      lbl_801A4160
	stw      r30, 0x14(r3)
	stw      r3, 0x18(r30)
	b        lbl_801A4180

lbl_801A417C:
	stw      r30, 0x1c(r4)

lbl_801A4180:
	stw      r4, 0x10(r30)

lbl_801A4184:
	addi     r3, r1, 8
	bl       next__Q24Game16WayPointIteratorFv

lbl_801A418C:
	addi     r3, r1, 8
	bl       isDone__Q24Game16WayPointIteratorFv
	clrlwi.  r0, r3, 0x18
	beq      lbl_801A3EE8
	li       r0, 1
	stb      r0, 0x22(r31)
	lwz      r3, 0(r24)
	addi     r4, r3, 0x2c
	lwz      r3, 0x48(r3)
	cmplwi   r3, 0
	beq      lbl_801A41D8
	b        lbl_801A41C0

lbl_801A41BC:
	mr       r3, r0

lbl_801A41C0:
	lwz      r0, 0x14(r3)
	cmplwi   r0, 0
	bne      lbl_801A41BC
	stw      r31, 0x14(r3)
	stw      r3, 0x18(r31)
	b        lbl_801A41DC

lbl_801A41D8:
	stw      r31, 0x1c(r4)

lbl_801A41DC:
	stw      r4, 0x10(r31)
	addi     r28, r28, -1

lbl_801A41E4:
	lwz      r4, 0(r24)
	lwz      r3, 0x24(r4)
	cmplwi   r3, 0
	beq      lbl_801A41FC
	cmpwi    r28, 0
	bgt      lbl_801A3D98

lbl_801A41FC:
	lwz      r0, 0x24(r4)
	cmplwi   r0, 0
	bne      lbl_801A4210
	li       r3, 1
	b        lbl_801A4214

lbl_801A4210:
	li       r3, 2

lbl_801A4214:
	lmw      r24, 0x20(r1)
	lwz      r0, 0x44(r1)
	mtlr     r0
	addi     r1, r1, 0x40
	blr
	*/
}

/*
 * --INFO--
 * Address:	801A4228
 * Size:	0000B4
 */
f32 AStarPathfinder::estimate(s16 wpID1, s16 wpID2)
{
	WayPoint* wp1 = PathfindContext::routeMgr->getWayPoint(wpID1);
	WayPoint* wp2 = PathfindContext::routeMgr->getWayPoint(wpID2);

	Vector3f pos1 = wp1->getPosition();
	Vector3f pos2 = wp2->getPosition();
	return _distanceBetween(pos1, pos2);
}

/*
 * --INFO--
 * Address:	801A42DC
 * Size:	000034
 */
int AStarContext::makepath(PathNode* newNode, PathNode** nodePtr)
{
	int i = 1;
	FOREACH_NODE_CHILD(PathNode, newNode->mChild, node)
	{
		i++;
		node->mNext = newNode;
		newNode     = node;
	}

	if (nodePtr) {
		*nodePtr = newNode;
	}
	return i;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void AStarPathfinder::constructPath(Game::PathNode*, short*, int)
{
	// UNUSED FUNCTION
}
} // namespace Game
