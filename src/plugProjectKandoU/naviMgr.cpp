#include "Game/Navi.h"
#include "Game/NaviParms.h"
#include "SysShape/Model.h"
#include "PSM/ObjMgr.h"
#include "PSM/Navi.h"
#include "utilityU.h"
#include "JSystem/J3D/J3DModelLoader.h"
#include "Game/PikiMgr.h"

namespace Game {

NaviMgr* naviMgr;
SysShape::AnimMgr* NaviMgr::animMgr;

/*
 * --INFO--
 * Address:	8015928C
 * Size:	0000CC
 */
NaviMgr::NaviMgr()
    : mFlags()
{
	mName      = "naviMgr";
	mNaviParms = new NaviParms;
	clearDeadCount();
	_48     = 0;
	mPSMMgr = nullptr;
}

/*
 * --INFO--
 * Address:	8015A7C0
 * Size:	000110
 */
NaviMgr::~NaviMgr()
{
	animMgr = nullptr;
	naviMgr = nullptr;
	if (_48) {
		delete _48;
		_48 = nullptr;
	}
	if (mPSMMgr) {
		delete mPSMMgr;
		mPSMMgr = nullptr;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
unknown NaviMgr::init()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8015A8D0
 * Size:	000078
 */
void NaviMgr::createPSMDirectorUpdator()
{
	mPSMMgr = new PSM::DirectorUpdator(PSMGetLifeD(), 2, PSM::DirectorUpdator::TYPE_0);
	mPSMMgr->directOff(0);
	mPSMMgr->directOff(1);
}

/*
 * --INFO--
 * Address:	8015A948
 * Size:	00005C
 */
void NaviMgr::resetMgr()
{
	MonoObjectMgr::resetMgr(); // should be MonoObjectMgr::resetMgr
	if (_48) {
		delete _48;
		_48 = nullptr;
	}
	if (mPSMMgr) {
		delete mPSMMgr;
		mPSMMgr = nullptr;
	}
}

/*
 * --INFO--
 * Address:	8015A9A4
 * Size:	000090
 */
void NaviMgr::killAll()
{
	for (int i = 0; i < mMax; i++) {
		Navi* navi = &mArray[i];
		navi->kill(nullptr);
		if (PSSystem::SingletonBase<PSM::ObjMgr>::sInstance && navi->mSoundObj) {
			PSSystem::SingletonBase<PSM::ObjMgr>::sInstance->remove(navi->mSoundObj);
		}
	}
}

/*
 * --INFO--
 * Address:	8015AA34
 * Size:	0000F0
 */
void NaviMgr::setupNavi(Game::Navi* navi)
{
	navi->mModel       = createModel(navi->mNaviIndex);
	navi->mParms       = mNaviParms;
	navi->mMarkerModel = new SysShape::Model(mCursorModelData, 0, 2);

	navi->mCursorModel = new SysShape::Model(mMarkerModelData, 0x80000, 2);
	navi->mCursorModel->mJ3dModel->newDifferedDisplayList(0x1000000);
	navi->mCursorModel->mJ3dModel->calc();
	navi->mCursorModel->mJ3dModel->calcMaterial();
	navi->mCursorModel->mJ3dModel->makeDL();
	navi->mCursorModel->mJ3dModel->lock();
}

/*
 * --INFO--
 * Address:	8015AB24
 * Size:	0000FC
 */
Navi* NaviMgr::birth()
{
	Navi* navi = MonoObjectMgr::birth();
	if (navi) {
		navi->mNaviIndex = mActiveCount - 1;

		P2ASSERTLINE(349, navi->mSoundObj);
		navi->mSoundObj->init(navi->mNaviIndex);
		// Use president sounds for navi ID 1
		if (playData->mStoryFlags & STORY_DebtPaid && navi->mNaviIndex == 1) {
			navi->mSoundObj->setShacho();
		}
	}

	for (int i = 0; i < mDeadNavis; i++) {
		if (mNaviDeadFlags[i] == navi->mNaviIndex) {
			navi->setAlive(false);
		}
	}
	return navi;
}

/*
 * --INFO--
 * Address:	8015AC20
 * Size:	00009C
 */
Navi* NaviMgr::getActiveNavi()
{
	Navi* navi1 = getAt(0);
	Navi* navi2 = getAt(1);
	if (!navi1 && !navi2) {
		return nullptr;
	}

	// navi is considered active if it is controller
	if (navi1->mController1) {
		return navi1;
	} else if (navi2->mController1) {
		return navi2;
	} else {
		return nullptr;
	}
}

/*
 * --INFO--
 * Address:	8015ACBC
 * Size:	0000BC
 */
void NaviMgr::loadResources()
{
	void* file
	    = JKRDvdRipper::loadToMainRAM("user/Abe/piki/naviParms.txt", 0, Switch_0, 0, nullptr, JKRDvdRipper::ALLOC_DIR_BOTTOM, 0, 0, 0);
	if (file) {
		RamStream stream(file, -1);
		stream.resetPosition(true, 1);
		mNaviParms->read(stream);
		delete[] file;
	}
	load();
}

/*
 * --INFO--
 * Address:	8015ADC8
 * Size:	000264
 */
void NaviMgr::load()
{
	P2DEBUG("Before mount: %d", JKRGetCurrentHeap()->getTotalFreeSize());
	JKRArchive* texts = JKRArchive::mount("/user/Kando/piki/texts.szs", JKRArchive::EMM_Mem, JKRGetCurrentHeap(), JKRArchive::EMD_Tail);
	P2DEBUG("After mount: %d", JKRGetCurrentHeap()->getTotalFreeSize());
	sys->heapStatusStart("NaviMgr::Archive", nullptr);
	JKRArchive* arc = JKRArchive::mount("/user/Kando/piki/pikis.szs", JKRArchive::EMM_Mem, sys->mSysHeap, JKRArchive::EMD_Head);
	sys->heapStatusEnd("NaviMgr::Archive");

	J3DModelData* model = J3DModelLoaderDataBase::load(arc->getResource("orima_model/orima1.bmd"), 0x20000030);
	for (u16 j = 0; j < model->getShapeNum(); j++) {
		J3DShape* shape = model->mShapeTable.mItems[j];
		shape->mFlags   = (shape->mFlags & (~0xF000)) | 0x2000;
	}

	mOlimarModel = model;
	if (!animMgr) {
		animMgr = SysShape::AnimMgr::load(texts, "animMgr.txt", model, arc, "motion");
	}
	mCollData = CollPartFactory::load(texts, "naviColl.txt");

	mCursorModelData = J3DModelLoaderDataBase::load(arc->getResource("cursor/cursor.bmd"), 0x240000);
	mMarkerModelData = J3DModelLoaderDataBase::load(arc->getResource("cursor/marker.bmd"), 0x240000);
	mMarkerModelData->newSharedDisplayList(0x40000);

	SysShape::Model::enableMaterialAnim(mCursorModelData, 0);
	mCursorAnims[0].attachResource(arc->getResource("cursor/wakka_orima.brk"), mCursorModelData);
	mCursorAnims[1].attachResource(arc->getResource("cursor/wakka_luji.brk"), mCursorModelData);
	mMarkerAnims[0].attachResource(arc->getResource("cursor/arrow_orima.brk"), mCursorModelData);
	mMarkerAnims[1].attachResource(arc->getResource("cursor/arrow_luji.brk"), mCursorModelData);

	P2DEBUG("Before unmount: %d", JKRGetCurrentHeap()->getTotalFreeSize());
	texts->unmount();
	P2DEBUG("After unmount: %d", JKRGetCurrentHeap()->getTotalFreeSize());

	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	lis      r4, lbl_8047D088@ha
	stw      r0, 0x24(r1)
	stw      r31, 0x1c(r1)
	addi     r31, r4, lbl_8047D088@l
	stw      r30, 0x18(r1)
	stw      r29, 0x14(r1)
	stw      r28, 0x10(r1)
	mr       r28, r3
	lwz      r3, sCurrentHeap__7JKRHeap@sda21(r13)
	bl       getTotalFreeSize__7JKRHeapFv
	lwz      r5, sCurrentHeap__7JKRHeap@sda21(r13)
	addi     r3, r31, 0x5dc
	li       r4, 1
	li       r6, 2
	bl
mount__10JKRArchiveFPCcQ210JKRArchive10EMountModeP7JKRHeapQ210JKRArchive15EMountDirection
	mr       r30, r3
	lwz      r3, sCurrentHeap__7JKRHeap@sda21(r13)
	bl       getTotalFreeSize__7JKRHeapFv
	lwz      r3, sys@sda21(r13)
	addi     r4, r31, 0x5f8
	li       r5, 0
	bl       heapStatusStart__6SystemFPcP7JKRHeap
	lwz      r5, sys@sda21(r13)
	addi     r3, r31, 0x60c
	li       r4, 1
	li       r6, 1
	lwz      r5, 0x38(r5)
	bl
mount__10JKRArchiveFPCcQ210JKRArchive10EMountModeP7JKRHeapQ210JKRArchive15EMountDirection
	mr       r29, r3
	lwz      r3, sys@sda21(r13)
	addi     r4, r31, 0x5f8
	bl       heapStatusEnd__6SystemFPc
	mr       r3, r29
	addi     r4, r31, 0x628
	lwz      r12, 0(r29)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	lis      r4, 0x20000030@ha
	addi     r4, r4, 0x20000030@l
	bl       load__22J3DModelLoaderDataBaseFPCvUl
	li       r4, 0
	mr       r5, r3
	b        lbl_8015AEA0

lbl_8015AE80:
	lwz      r3, 0x80(r5)
	rlwinm   r0, r4, 2, 0xe, 0x1d
	addi     r4, r4, 1
	lwzx     r3, r3, r0
	lwz      r0, 0xc(r3)
	rlwinm   r0, r0, 0, 0x14, 0xf
	ori      r0, r0, 0x2000
	stw      r0, 0xc(r3)

lbl_8015AEA0:
	lhz      r0, 0x7c(r5)
	clrlwi   r3, r4, 0x10
	cmplw    r3, r0
	blt      lbl_8015AE80
	stw      r5, 0xb0(r28)
	lwz      r0, animMgr__Q24Game7NaviMgr@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_8015AED8
	mr       r3, r30
	mr       r6, r29
	addi     r4, r31, 0x640
	addi     r7, r2, lbl_80518748@sda21
	bl
load__Q28SysShape7AnimMgrFP13JKRFileLoaderPcP12J3DModelDataP13JKRFileLoaderPc
	stw      r3, animMgr__Q24Game7NaviMgr@sda21(r13)

lbl_8015AED8:
	mr       r3, r30
	addi     r4, r31, 0x64c
	bl       load__15CollPartFactoryFP13JKRFileLoaderPc
	stw      r3, 0xcc(r28)
	mr       r3, r29
	addi     r4, r31, 0x65c
	lwz      r12, 0(r29)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	lis      r4, 0x24
	bl       load__22J3DModelLoaderDataBaseFPCvUl
	stw      r3, 0xb8(r28)
	mr       r3, r29
	addi     r4, r31, 0x670
	lwz      r12, 0(r29)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	lis      r4, 0x24
	bl       load__22J3DModelLoaderDataBaseFPCvUl
	stw      r3, 0xc4(r28)
	lis      r4, 4
	lwz      r3, 0xc4(r28)
	bl       newSharedDisplayList__12J3DModelDataFUl
	lwz      r3, 0xb8(r28)
	li       r4, 0
	bl       enableMaterialAnim__Q28SysShape5ModelFP12J3DModelDatai
	mr       r3, r29
	addi     r4, r31, 0x684
	lwz      r12, 0(r29)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	lwz      r5, 0xb8(r28)
	mr       r4, r3
	addi     r3, r28, 0x60
	bl       attachResource__Q23Sys16MatBaseAnimationFPvP12J3DModelData
	mr       r3, r29
	addi     r4, r31, 0x69c
	lwz      r12, 0(r29)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	lwz      r5, 0xb8(r28)
	mr       r4, r3
	addi     r3, r28, 0x74
	bl       attachResource__Q23Sys16MatBaseAnimationFPvP12J3DModelData
	mr       r3, r29
	addi     r4, r31, 0x6b4
	lwz      r12, 0(r29)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	lwz      r5, 0xb8(r28)
	mr       r4, r3
	addi     r3, r28, 0x88
	bl       attachResource__Q23Sys16MatBaseAnimationFPvP12J3DModelData
	mr       r3, r29
	addi     r4, r31, 0x6cc
	lwz      r12, 0(r29)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	lwz      r5, 0xb8(r28)
	mr       r4, r3
	addi     r3, r28, 0x9c
	bl       attachResource__Q23Sys16MatBaseAnimationFPvP12J3DModelData
	lwz      r3, sCurrentHeap__7JKRHeap@sda21(r13)
	bl       getTotalFreeSize__7JKRHeapFv
	mr       r3, r30
	lwz      r12, 0(r30)
	lwz      r12, 0xc(r12)
	mtctr    r12
	bctrl
	lwz      r3, sCurrentHeap__7JKRHeap@sda21(r13)
	bl       getTotalFreeSize__7JKRHeapFv
	lwz      r0, 0x24(r1)
	lwz      r31, 0x1c(r1)
	lwz      r30, 0x18(r1)
	lwz      r29, 0x14(r1)
	lwz      r28, 0x10(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	8015B02C
 * Size:	000064
 */
SysShape::Model* NaviMgr::createModel(int id) { return new SysShape::Model((&mOlimarModel)[id], 0, 2); }

/*
 * --INFO--
 * Address:	8015B090
 * Size:	0000D4
 */
void NaviMgr::loadResources_float()
{
	JKRArchive* arc = JKRArchive::mount("/user/Kando/piki/pikis.szs", JKRArchive::EMM_Mem, sys->mSysHeap, JKRArchive::EMD_Head);
	void* file;
	if (playData->mStoryFlags & STORY_DebtPaid) {
		file = arc->getResource("orima_model/syatyou.bmd");
	} else {
		file = arc->getResource("orima_model/orima3.bmd");
	}

	J3DModelData* model = J3DModelLoaderDataBase::load(file, 0x20000030);
	for (u16 j = 0; j < model->getShapeNum(); j++) {
		J3DShape* shape = model->mShapeTable.mItems[j];
		shape->mFlags   = (shape->mFlags & (~0xF000)) | 0x2000;
	}

	mLouieModel = model;
}

/*
 * --INFO--
 * Address:	8015B164
 * Size:	00008C
 */
int NaviMgr::getAliveCount()
{
	int alive = 0;
	for (int i = 0; i < mMax; i++) {
		if (mArray[i].isAlive()) {
			alive++;
		}
	}
	return alive;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
Navi* NaviMgr::getSurviveNavi()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8015B1F0
 * Size:	000018
 */
void NaviMgr::clearDeadCount()
{
	mDeadNavis        = 0;
	mNaviDeadFlags[0] = -1;
	mNaviDeadFlags[1] = -1;
}

/*
 * --INFO--
 * Address:	8015B208
 * Size:	000078
 */
void NaviMgr::informOrimaDead(int id)
{
	for (int i = 0; i < mDeadNavis; i++) {
		if (mNaviDeadFlags[i] == id) {
			return;
		}
	}

	mNaviDeadFlags[mDeadNavis] = id;
	mDeadNavis++;
	Navi* navi = getAt(id);
	if (navi) {
		navi->releasePikis();
	}
}

/*
 * --INFO--
 * Address:	8015B280
 * Size:	00004C
 */
Navi* NaviMgr::getDeadOrima(int id)
{
	if (mDeadNavis > id) {
		return getAt(mNaviDeadFlags[id]);
	} else {
		return nullptr;
	}
}

/*
 * --INFO--
 * Address:	8015B2CC
 * Size:	0000EC
 */
Navi* NaviMgr::getAliveOrima(int type)
{
	if (mDeadNavis == 2) {
		return nullptr;
	} else if (mDeadNavis == 1) {
		int index = 1 - mNaviDeadFlags[0];
		return (type == 0) ? getAt(index) : nullptr;
		// if (type == 0) {
		// 	return getAt(1 - mNaviDeadFlags[0]);
		// } else {
		// 	return nullptr;
		// }
	} else if (mDeadNavis == 0) {
		Navi* navi1 = getAt(0);
		Navi* navi2 = getAt(1);
		Navi* navi3;
		if (navi1->mController1) {
			navi3 = navi1;
			navi1 = navi2;
		}
		if (!type) {
			navi1 = navi3;
		}
		return navi1;
	} else {
		return nullptr;
	}
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	mr       r31, r3
	stw      r30, 8(r1)
	mr       r30, r4
	lwz      r0, 0x50(r3)
	cmpwi    r0, 2
	bne      lbl_8015B2FC
	li       r3, 0
	b        lbl_8015B3A0

lbl_8015B2FC:
	cmpwi    r0, 1
	bne      lbl_8015B330
	lwz      r0, 0x54(r31)
	cmpwi    r30, 0
	subfic   r4, r0, 1
	bne      lbl_8015B328
	lwz      r12, 0(r3)
	lwz      r12, 0x24(r12)
	mtctr    r12
	bctrl
	b        lbl_8015B3A0

lbl_8015B328:
	li       r3, 0
	b        lbl_8015B3A0

lbl_8015B330:
	cmpwi    r0, 0
	bne      lbl_8015B39C
	lwz      r12, 0(r3)
	li       r4, 0
	lwz      r12, 0x24(r12)
	mtctr    r12
	bctrl
	mr       r0, r3
	mr       r3, r31
	lwz      r12, 0(r31)
	mr       r31, r0
	li       r4, 1
	lwz      r12, 0x24(r12)
	mtctr    r12
	bctrl
	lwz      r0, 0x278(r31)
	cmplwi   r0, 0
	beq      lbl_8015B380
	mr       r0, r31
	b        lbl_8015B388

lbl_8015B380:
	mr       r0, r3
	mr       r3, r31

lbl_8015B388:
	cmpwi    r30, 0
	bne      lbl_8015B3A0
	mr       r3, r0
	b        lbl_8015B3A0
	b        lbl_8015B3A0

lbl_8015B39C:
	li       r3, 0

lbl_8015B3A0:
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
 * Address:	8015B3B8
 * Size:	0000A8
 */
void NaviMgr::setMovieDraw(bool drawOn)
{
	if (!drawOn) {
		mFlags.set(0x01);
	} else {
		mFlags.unset(0x01);
	}

	for (int i = 0; i < mMax; i++) {
		if (!mOpenIds[i]) {
			mArray[i].set_movie_draw(drawOn);
		}
	}
}

/*
 * --INFO--
 * Address:	8015B460
 * Size:	0000E0
 */
void NaviMgr::doAnimation()
{
	u32 flag = mFlags.typeView;
	for (int i = 0; i < mMax; i++) {
		if (mOpenIds[i] == 0 && ((flag & 1) == 0 || mArray[i].isMovieActor())) {
			mArray[i].mFaceDirOffset = mArray[i].mFaceDir;
			mArray[i].update();
			mArray[i].doAnimation();
		}
	}
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	stw      r0, 0x24(r1)
	stw      r31, 0x1c(r1)
	stw      r30, 0x18(r1)
	li       r30, 0
	stw      r29, 0x14(r1)
	li       r29, 0
	stw      r28, 0x10(r1)
	mr       r28, r3
	lbz      r0, 0x5c(r3)
	clrlwi   r31, r0, 0x1f
	b        lbl_8015B514

lbl_8015B494:
	lwz      r3, 0x2c(r28)
	lbzx     r0, r3, r29
	cmplwi   r0, 0
	bne      lbl_8015B50C
	cmplwi   r31, 0
	beq      lbl_8015B4CC
	lwz      r0, 0x28(r28)
	add      r3, r0, r30
	lwz      r12, 0(r3)
	lwz      r12, 0xb8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_8015B50C

lbl_8015B4CC:
	lwz      r0, 0x28(r28)
	add      r3, r0, r30
	lfs      f0, 0x1fc(r3)
	stfs     f0, 0x244(r3)
	lwz      r0, 0x28(r28)
	add      r3, r0, r30
	lwz      r12, 0(r3)
	lwz      r12, 0x1cc(r12)
	mtctr    r12
	bctrl
	lwz      r0, 0x28(r28)
	add      r3, r0, r30
	lwz      r12, 0(r3)
	lwz      r12, 0x3c(r12)
	mtctr    r12
	bctrl

lbl_8015B50C:
	addi     r30, r30, 0x320
	addi     r29, r29, 1

lbl_8015B514:
	lwz      r0, 0x24(r28)
	cmpw     r29, r0
	blt      lbl_8015B494
	lwz      r0, 0x24(r1)
	lwz      r31, 0x1c(r1)
	lwz      r30, 0x18(r1)
	lwz      r29, 0x14(r1)
	lwz      r28, 0x10(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	8015B540
 * Size:	000168
 */
void NaviMgr::doEntry()
{
	bool vs = false;
	if (gameSystem->isVersusMode()) {
		vs = true;
	}
	u32 flag = mFlags.typeView;
	for (int i = 0; i < mMax; i++) {
		if (mOpenIds[i] != 0) {
			continue;
		}
		if ((flag & 1) != 0 && !mArray[i].isMovieActor()) {
			mArray[i].mLod.resetFlag(0x34);
		} else if (mArray[i].isMovieActor()) {
			mArray[i].mLod.setFlag(0x34);
		}

		if (vs) {
			Navi* navi = &mArray[i];
			if ((int)navi->mNaviIndex == 1 && pikiMgr->mFlags[0] & 1) {
				navi->mLod.resetFlag(0x10);
			} else if ((int)navi->mNaviIndex == 0 && pikiMgr->mFlags[0] & 2) {
				navi->mLod.resetFlag(0x20);
			}
		}
		mArray[i].doEntry();
	}
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	stw      r0, 0x24(r1)
	stmw     r27, 0xc(r1)
	mr       r27, r3
	li       r29, 0
	lwz      r4, gameSystem__4Game@sda21(r13)
	lwz      r0, 0x44(r4)
	cmpwi    r0, 1
	bne      lbl_8015B56C
	li       r29, 1

lbl_8015B56C:
	lbz      r0, 0x5c(r27)
	li       r28, 0
	li       r30, 0
	clrlwi   r31, r0, 0x1f
	b        lbl_8015B688

lbl_8015B580:
	lwz      r3, 0x2c(r27)
	lbzx     r0, r3, r28
	cmplwi   r0, 0
	bne      lbl_8015B680
	cmplwi   r31, 0
	beq      lbl_8015B5D4
	lwz      r0, 0x28(r27)
	add      r3, r0, r30
	lwz      r12, 0(r3)
	lwz      r12, 0xb8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8015B5D4
	lwz      r5, 0x28(r27)
	addi     r4, r30, 0xd8
	li       r0, -53
	lbzx     r3, r5, r4
	and      r0, r3, r0
	stbx     r0, r5, r4
	b        lbl_8015B608

lbl_8015B5D4:
	lwz      r0, 0x28(r27)
	add      r3, r0, r30
	lwz      r12, 0(r3)
	lwz      r12, 0xb8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_8015B608
	lwz      r4, 0x28(r27)
	addi     r3, r30, 0xd8
	lbzx     r0, r4, r3
	ori      r0, r0, 0x34
	stbx     r0, r4, r3

lbl_8015B608:
	clrlwi.  r0, r29, 0x18
	beq      lbl_8015B668
	lwz      r0, 0x28(r27)
	add      r5, r0, r30
	lhz      r4, 0x2dc(r5)
	cmpwi    r4, 1
	bne      lbl_8015B644
	lwz      r3, pikiMgr__4Game@sda21(r13)
	lbz      r0, 0x38(r3)
	clrlwi.  r0, r0, 0x1f
	beq      lbl_8015B644
	lbz      r0, 0xd8(r5)
	rlwinm   r0, r0, 0, 0x1c, 0x1a
	stb      r0, 0xd8(r5)
	b        lbl_8015B668

lbl_8015B644:
	cmpwi    r4, 0
	bne      lbl_8015B668
	lwz      r3, pikiMgr__4Game@sda21(r13)
	lbz      r0, 0x38(r3)
	rlwinm.  r0, r0, 0, 0x1e, 0x1e
	beq      lbl_8015B668
	lbz      r0, 0xd8(r5)
	rlwinm   r0, r0, 0, 0x1b, 0x19
	stb      r0, 0xd8(r5)

lbl_8015B668:
	lwz      r0, 0x28(r27)
	add      r3, r0, r30
	lwz      r12, 0(r3)
	lwz      r12, 0x40(r12)
	mtctr    r12
	bctrl

lbl_8015B680:
	addi     r30, r30, 0x320
	addi     r28, r28, 1

lbl_8015B688:
	lwz      r0, 0x24(r27)
	cmpw     r28, r0
	blt      lbl_8015B580
	lmw      r27, 0xc(r1)
	lwz      r0, 0x24(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	8015B6A8
 * Size:	000378
 */
void NaviMgr::doSimulation(f32 rate)
{
	doSimulation(rate); // should be MonoObjectMgr::doSimulation
	if (gameSystem->isMultiplayerMode() || mPSMMgr) {
		Iterator<Navi> iterator(this);
		CI_LOOP(iterator)
		{
			Navi* navi = *iterator;
			if (navi->isAlive() && navi->mHealth <= 0.5f) {
				mPSMMgr->directOn(navi->mNaviIndex);
			} else {
				mPSMMgr->directOff(navi->mNaviIndex);
			}
		}
		mPSMMgr->frameEndWork();
	} else {
		PSM::ActorDirector_TempoChange* psm = PSMGetLifeD();
		if (psm) {
			Navi* navi = getActiveNavi();
			if (navi) {
				if (navi->getLifeRatio() <= 0.5f) {
					psm->directOn();
				} else {
					psm->directOff();
				}
			} else {
				psm->directOff();
			}
		}
	}
	/*
	stwu     r1, -0x30(r1)
	mflr     r0
	stw      r0, 0x34(r1)
	stw      r31, 0x2c(r1)
	mr       r31, r3
	stw      r30, 0x28(r1)
	stw      r29, 0x24(r1)
	bl       "doSimulation__27MonoObjectMgr<Q24Game4Navi>Ff"
	lwz      r4, gameSystem__4Game@sda21(r13)
	li       r3, 0
	lwz      r0, 0x44(r4)
	cmpwi    r0, 2
	beq      lbl_8015B6E4
	cmpwi    r0, 3
	bne      lbl_8015B6E8

lbl_8015B6E4:
	li       r3, 1

lbl_8015B6E8:
	clrlwi.  r0, r3, 0x18
	bne      lbl_8015B6FC
	lwz      r0, 0x4c(r31)
	cmplwi   r0, 0
	beq      lbl_8015B91C

lbl_8015B6FC:
	li       r0, 0
	lis      r3, "__vt__22Iterator<Q24Game4Navi>"@ha
	addi     r3, r3, "__vt__22Iterator<Q24Game4Navi>"@l
	stw      r0, 0x14(r1)
	cmplwi   r0, 0
	stw      r3, 8(r1)
	stw      r0, 0xc(r1)
	stw      r31, 0x10(r1)
	bne      lbl_8015B73C
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x18(r12)
	mtctr    r12
	bctrl
	stw      r3, 0xc(r1)
	b        lbl_8015B8F0

lbl_8015B73C:
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x18(r12)
	mtctr    r12
	bctrl
	stw      r3, 0xc(r1)
	b        lbl_8015B7AC

lbl_8015B758:
	lwz      r3, 0x10(r1)
	lwz      r4, 0xc(r1)
	lwz      r12, 0(r3)
	lwz      r12, 0x20(r12)
	mtctr    r12
	bctrl
	mr       r4, r3
	lwz      r3, 0x14(r1)
	lwz      r12, 0(r3)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8015B8F0
	lwz      r3, 0x10(r1)
	lwz      r4, 0xc(r1)
	lwz      r12, 0(r3)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	stw      r3, 0xc(r1)

lbl_8015B7AC:
	lwz      r12, 8(r1)
	addi     r3, r1, 8
	lwz      r12, 0x10(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_8015B758
	b        lbl_8015B8F0

lbl_8015B7CC:
	lwz      r3, 0x10(r1)
	lwz      r12, 0(r3)
	lwz      r12, 0x20(r12)
	mtctr    r12
	bctrl
	lwz      r12, 0(r3)
	mr       r30, r3
	lwz      r12, 0xa8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_8015B824
	lfs      f1, 0x2a0(r30)
	lfs      f0, lbl_80518674@sda21(r2)
	fcmpo    cr0, f1, f0
	cror     2, 0, 2
	bne      lbl_8015B824
	lhz      r0, 0x2dc(r30)
	lwz      r3, 0x4c(r31)
	clrlwi   r4, r0, 0x18
	bl       directOn__Q23PSM15DirectorUpdatorFUc
	b        lbl_8015B834

lbl_8015B824:
	lhz      r0, 0x2dc(r30)
	lwz      r3, 0x4c(r31)
	clrlwi   r4, r0, 0x18
	bl       directOff__Q23PSM15DirectorUpdatorFUc

lbl_8015B834:
	lwz      r0, 0x14(r1)
	cmplwi   r0, 0
	bne      lbl_8015B860
	lwz      r3, 0x10(r1)
	lwz      r4, 0xc(r1)
	lwz      r12, 0(r3)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	stw      r3, 0xc(r1)
	b        lbl_8015B8F0

lbl_8015B860:
	lwz      r3, 0x10(r1)
	lwz      r4, 0xc(r1)
	lwz      r12, 0(r3)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	stw      r3, 0xc(r1)
	b        lbl_8015B8D4

lbl_8015B880:
	lwz      r3, 0x10(r1)
	lwz      r4, 0xc(r1)
	lwz      r12, 0(r3)
	lwz      r12, 0x20(r12)
	mtctr    r12
	bctrl
	mr       r4, r3
	lwz      r3, 0x14(r1)
	lwz      r12, 0(r3)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8015B8F0
	lwz      r3, 0x10(r1)
	lwz      r4, 0xc(r1)
	lwz      r12, 0(r3)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	stw      r3, 0xc(r1)

lbl_8015B8D4:
	lwz      r12, 8(r1)
	addi     r3, r1, 8
	lwz      r12, 0x10(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_8015B880

lbl_8015B8F0:
	lwz      r3, 0x10(r1)
	lwz      r12, 0(r3)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	lwz      r4, 0xc(r1)
	cmplw    r4, r3
	bne      lbl_8015B7CC
	lwz      r3, 0x4c(r31)
	bl       frameEndWork__Q23PSM15DirectorUpdatorFv
	b        lbl_8015BA04

lbl_8015B91C:
	bl       PSMGetLifeD__Fv
	or.      r29, r3, r3
	beq      lbl_8015BA04
	lwz      r3, naviMgr__4Game@sda21(r13)
	li       r4, 0
	lwz      r12, 0(r3)
	mr       r31, r3
	lwz      r12, 0x24(r12)
	mtctr    r12
	bctrl
	lwz      r12, 0(r31)
	mr       r30, r3
	mr       r3, r31
	li       r4, 1
	lwz      r12, 0x24(r12)
	mtctr    r12
	bctrl
	cmplwi   r30, 0
	bne      lbl_8015B978
	cmplwi   r3, 0
	bne      lbl_8015B978
	li       r30, 0
	b        lbl_8015B9A0

lbl_8015B978:
	lwz      r0, 0x278(r30)
	cmplwi   r0, 0
	beq      lbl_8015B988
	b        lbl_8015B9A0

lbl_8015B988:
	lwz      r0, 0x278(r3)
	cmplwi   r0, 0
	beq      lbl_8015B99C
	mr       r30, r3
	b        lbl_8015B9A0

lbl_8015B99C:
	li       r30, 0

lbl_8015B9A0:
	cmplwi   r30, 0
	beq      lbl_8015B9F0
	mr       r3, r30
	bl       getLifeRatio__Q24Game4NaviFv
	lfs      f0, lbl_80518674@sda21(r2)
	fcmpo    cr0, f1, f0
	cror     2, 0, 2
	bne      lbl_8015B9D8
	mr       r3, r29
	lwz      r12, 0(r29)
	lwz      r12, 0x10(r12)
	mtctr    r12
	bctrl
	b        lbl_8015BA04

lbl_8015B9D8:
	mr       r3, r29
	lwz      r12, 0(r29)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	b        lbl_8015BA04

lbl_8015B9F0:
	mr       r3, r29
	lwz      r12, 0(r29)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl

lbl_8015BA04:
	lwz      r0, 0x34(r1)
	lwz      r31, 0x2c(r1)
	lwz      r30, 0x28(r1)
	lwz      r29, 0x24(r1)
	mtlr     r0
	addi     r1, r1, 0x30
	blr
	*/
}

/*
 * --INFO--
 * Address:	8015BA20
 * Size:	000004
 */
void NaviMgr::setupSoundViewerAndBas() { }

} // namespace Game
