#include "Game/Entities/ItemDownFloor.h"
#include "Game/MapMgr.h"
#include "Game/routeMgr.h"
#include "Game/Navi.h"
#include "Game/MoviePlayer.h"
#include "efx/TDownf.h"
#include "efx/TPbag.h"
#include "PSM/WorkItem.h"
#include "PSSystem/PSSystemIF.h"
#include "Dolphin/rand.h"
#include "Platform.h"
#include "nans.h"

namespace Game {
namespace ItemDownFloor {

static const int unusedArray[] = { 0, 0, 0 };
static const char unusedName[] = "itemDownFloor";

Mgr* mgr;

/*
 * --INFO--
 * Address:	801F4CDC
 * Size:	0001E4
 */
void FSM::init(Item*)
{
	create(DOWNFLOOR_StateCount);
	registerState(new WaitState);
	registerState(new DamagedState);
	registerState(new DownState);
	registerState(new UpState);
	registerState(new DeadState);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000134
 */
Item::Item()
    : FSMItem<Item, FSM, State>(OBJTYPE_Downfloor)
    , CarryInfoOwner()
    , mSoundEvent()
    , mID()
{
	mCollTree               = new CollTree();
	mBoundingSphere.mRadius = 170.0f;
	mIsPressed              = false;
	mDownFloorType          = DFTYPE_PaperBag;
	mOtherSeesaw            = nullptr;
	mID.setID('none');
	mWayPoint    = nullptr;
	mIsDemoBlock = false;
}

/*
 * --INFO--
 * Address:	801F4EC0
 * Size:	000048
 */
void Item::constructor() { mSoundObj = new PSM::WorkItem(this); }

/*
 * --INFO--
 * Address:	801F4F08
 * Size:	0000FC
 */
void Item::onInit(CreatureInitArg* initArg)
{
	mCarryInfoList = nullptr;
	mgr->setupDownFloor(this);
	JUT_ASSERTLINE(219, mModel, "no shape !\n");
	mFsm->start(this, DOWNFLOOR_Wait, nullptr);
	setAlive(true);

	InitArg* dfArg = static_cast<InitArg*>(initArg);
	if (dfArg) {
		mFaceDir = dfArg->mFaceDir;
	} else {
		mFaceDir = randFloat() * TAU;
	}

	mWeightBuffer  = 0;
	mCurrentWeight = 0;
}

/*
 * --INFO--
 * Address:	801F5038
 * Size:	0002B4
 */
void Item::initDependency()
{
	if (mDownFloorType != DFTYPE_PaperBag) {
		mOtherSeesaw = nullptr;

		Iterator<BaseItem> iter(mgr);
		CI_LOOP(iter)
		{
			Item* item = static_cast<Item*>(*iter);
			if (item != this && item->mID.match(mID.getID(), '*')) {
				mOtherSeesaw = item;
				break;
			}
		}

		if (mOtherSeesaw) {
			if (mOtherSeesaw->mDownFloorType == DFTYPE_UpBlock) {
				mDownFloorType = DFTYPE_DownBlock;
				mIsPressed     = true;
			} else {
				mIsPressed     = false;
				mDownFloorType = DFTYPE_UpBlock;
			}

			mFsm->start(this, DOWNFLOOR_Wait, nullptr);
		} else {
			JUT_PANICLINE(280, "No Friend Found for seesaw: searching for same id (%s)\n", mID.getStr()); // no friend found :(
		}
	}
}

/*
 * --INFO--
 * Address:	801F52EC
 * Size:	000138
 */
void Item::onSetPosition()
{
	Vector3f rot(0.0f, mFaceDir, 0.0f);
	mObjMatrix.makeTR(mPosition, rot);
	PSMTXCopy(mObjMatrix.mMatrix.mtxView, mModel->mJ3dModel->mPosMtx);
	mModel->mJ3dModel->calc();

	mgr->setupPlatform(this);

	if (mDownFloorType == DFTYPE_PaperBag || mIsDemoBlock) {
		WPSearchArg searchArg(mPosition, nullptr, 0, 10.0f);

		if (mapMgr && mapMgr->mRouteMgr) {
			mWayPoint = mapMgr->mRouteMgr->getNearestWayPoint(searchArg);
			mWayPoint->setOpen(false);
			mWayPoint->mPosition = mPosition;
			if (mDownFloorType != DFTYPE_PaperBag) {
				mWayPoint->setOpen(mIsPressed);
			}
		} else {
			mWayPoint = nullptr;
		}
	}
}

/*
 * --INFO--
 * Address:	801F5424
 * Size:	00001C
 */
void Item::updateBoundSphere() { mBoundingSphere.mPosition = mPosition; }

/*
 * --INFO--
 * Address:	801F5440
 * Size:	000044
 */
void Item::onKeyEvent(SysShape::KeyEvent const& keyEvent)
{
	if (mCurrentState) {
		mCurrentState->onKeyEvent(this, keyEvent);
	}
}

/*
 * --INFO--
 * Address:	801F5484
 * Size:	000004
 */
void State::onKeyEvent(Item* item, SysShape::KeyEvent const& keyEvent) { }

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void Item::initMotion()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F5488
 * Size:	000338
 */
void Item::startDamageMotion()
{
	mAnimator.startAnim(1, this);
	if (mModelType == DFMODEL_PaperBag) {
		mSoundObj->startSound(PSSE_EV_PAPERBAG_PRESSED, 0);
	} else {
		mSoundObj->startSound(PSSE_EV_DOWNFLOOR_SHAKE, 0);
	}

	mAnimSpeed = 30.0f;

	Sys::Sphere sphere = mBoundingSphere;
	sphere.mPosition.y -= 20.0f;

	WaterBox* water = mapMgr->findWater(sphere);

	if (water) {
		switch (mModelType) {
		case DFMODEL_SmallBlock:
			efx::TDownf1WOn water1On(&mObjMatrix);
			water1On.create(nullptr);
			break;
		case DFMODEL_LargeBlock:
			efx::TDownf2WOn water2On(&mObjMatrix);
			water2On.create(nullptr);
			break;
		case DFMODEL_PaperBag:
			efx::TDownf3WOn water3On(&mObjMatrix);
			water3On.create(nullptr);
			break;
		}

	} else {
		switch (mModelType) {
		case DFMODEL_SmallBlock:
			efx::TDownf1On land1On(&mObjMatrix);
			land1On.create(nullptr);
			break;
		case DFMODEL_LargeBlock:
			efx::TDownf2On land2On(&mObjMatrix);
			land2On.create(nullptr);
			break;
		case DFMODEL_PaperBag:
			efx::TPbagOn land3On(&mObjMatrix);
			land3On.create(nullptr);
			break;
		}
	}
}

/*
 * --INFO--
 * Address:	801F57C0
 * Size:	00033C
 */
void Item::startDownMotion()
{
	mAnimator.startAnim(2, this);
	mAnimSpeed = 30.0f;
	if (mModelType == DFMODEL_PaperBag) {
		startSound(PSSE_EV_PAPERBAG_SINK);
	} else {
		startSound(PSSE_EV_WORK_WALLDOWN);
	}

	Sys::Sphere sphere = mBoundingSphere;
	sphere.mPosition.y -= 20.0f;

	WaterBox* water = mapMgr->findWater(sphere);

	if (water) {
		switch (mModelType) {
		case DFMODEL_SmallBlock:
			efx::TDownf1WUpdown water1Updown(&mObjMatrix);
			water1Updown.create(nullptr);
			break;
		case DFMODEL_LargeBlock:
			efx::TDownf2WUpdown water2Updown(&mObjMatrix);
			water2Updown.create(nullptr);
			break;
		case DFMODEL_PaperBag:
			efx::TDownf3WUpdown water3Updown(&mObjMatrix);
			water3Updown.create(nullptr);
			break;
		}

	} else {
		switch (mModelType) {
		case DFMODEL_SmallBlock:
			efx::TDownf1Updown land1Updown(&mObjMatrix);
			land1Updown.create(nullptr);
			break;
		case DFMODEL_LargeBlock:
			efx::TDownf2Updown land2Updown(&mObjMatrix);
			land2Updown.create(nullptr);
			break;
		case DFMODEL_PaperBag:
			efx::TPbagDown land3Updown(&mObjMatrix);
			land3Updown.create(nullptr);
			break;
		}
	}
}

/*
 * --INFO--
 * Address:	801F5AFC
 * Size:	0002E4
 */
void Item::startUpMotion()
{
	mAnimator.startAnim(3, this);
	mAnimSpeed = 30.0f;

	Sys::Sphere sphere = mBoundingSphere;
	sphere.mPosition.y -= 20.0f;

	WaterBox* water = mapMgr->findWater(sphere);

	if (water) {
		switch (mModelType) {
		case DFMODEL_SmallBlock:
			efx::TDownf1WUpdown water1Updown(&mObjMatrix);
			water1Updown.create(nullptr);
			break;
		case DFMODEL_LargeBlock:
			efx::TDownf2WUpdown water2Updown(&mObjMatrix);
			water2Updown.create(nullptr);
			break;
		case DFMODEL_PaperBag:
			efx::TDownf3WUpdown water3Updown(&mObjMatrix);
			water3Updown.create(nullptr);
			break;
		}

	} else {
		switch (mModelType) {
		case DFMODEL_SmallBlock:
			efx::TDownf1Updown land1Updown(&mObjMatrix);
			land1Updown.create(nullptr);
			break;
		case DFMODEL_LargeBlock:
			efx::TDownf2Updown land2Updown(&mObjMatrix);
			land2Updown.create(nullptr);
			break;
		case DFMODEL_PaperBag:
			efx::TDownf3Updown land3Updown(&mObjMatrix);
			land3Updown.create(nullptr);
			break;
		}
	}
}

/*
 * --INFO--
 * Address:	801F5DE0
 * Size:	000004
 */
void Item::changeMaterial() { }

/*
 * --INFO--
 * Address:	801F5DE4
 * Size:	000038
 */
void Item::doSave(Stream& output)
{
	if (mDownFloorType == DFTYPE_PaperBag) {
		output.writeByte(mIsPressed);
	}
}

/*
 * --INFO--
 * Address:	801F5E1C
 * Size:	0000F8
 */
void Item::doLoad(Stream& input)
{
	if (mDownFloorType == DFTYPE_PaperBag) {
		u32 isPressed = input.readByte();
		setAlive(true);
		if (isPressed) {
			mAnimator.startAnim(2, nullptr);
			mAnimSpeed = 0.0f;
			mAnimator.setLastFrame();
			mPlatInstance->setCollision(false);

			mIsPressed = true;
			mFsm->transit(this, DOWNFLOOR_Dead, nullptr);
			if (mCarryInfoList) {
				mCarryInfoList->mParam.mCarryInfo.disappear();
				mCarryInfoList = nullptr;
			}

			platMgr->delInstance(mPlatInstance);

			if (mWayPoint) {
				mWayPoint->setOpen(true);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	801F5F14
 * Size:	0000F8
 */
void Item::doAI()
{
	if (mDownFloorType == DFTYPE_PaperBag) {
		switch (mSoundEvent.update()) {
		case 2:
			P2ASSERTLINE(607, mSoundObj->getCastType() == PSM::CCT_WorkItem);
			static_cast<PSM::WorkItem*>(mSoundObj)->eventStop();
			break;
		}
	}

	if (mCarryInfoList && mWeightBuffer == 0) {
		mCarryInfoList->mParam.mCarryInfo.disappear();
		mCarryInfoList = nullptr;
	}

	if (mCurrentState->mId == DOWNFLOOR_Wait) {
		mCurrentWeight = mWeightBuffer;
	}

	mWeightBuffer    = 0;
	mCurrentOccupant = nullptr;
	mFsm->exec(this);
}

/*
 * --INFO--
 * Address:	801F600C
 * Size:	00023C
 */
void Item::platCallback(PlatEvent& event)
{
	if (mDownFloorType != DFTYPE_PaperBag || !mIsPressed) {
		Creature* creature = event.mObj;
		if (creature != mCurrentOccupant) {
			if (creature->isPiki()) {
				mWeightBuffer += static_cast<Piki*>(creature)->getDownfloorMass();
				mCurrentOccupant = event.mObj;
			} else if (creature->isNavi()) {
				mWeightBuffer += static_cast<Navi*>(creature)->getDownfloorMass();
				mCurrentOccupant = event.mObj;
			}
		}

		if (mDownFloorType == DFTYPE_PaperBag && mWeightBuffer > 0) {
			switch (mSoundEvent.event()) {
			case 1:
				P2ASSERTLINE(731, mSoundObj->getCastType() == PSM::CCT_WorkItem);
				static_cast<PSM::WorkItem*>(mSoundObj)->eventStart();
				break;
			case 3:
				P2ASSERTLINE(738, mSoundObj->getCastType() == PSM::CCT_WorkItem);
				static_cast<PSM::WorkItem*>(mSoundObj)->eventRestart();
				break;
			}
		}

		if (!mCarryInfoList) {
			mCarryInfoList = carryInfoMgr->appear(this);
		}

		if (mCurrentState && mCurrentState->mId == DOWNFLOOR_Wait && mWeightBuffer > mCurrentWeight) {
			mCurrentWeight = mWeightBuffer;
			mCurrentState->onPlat(this);
		}
	}
}

/*
 * --INFO--
 * Address:	801F6248
 * Size:	000004
 */
void State::onPlat(Item*) { }

/*
 * --INFO--
 * Address:	801F624C
 * Size:	00005C
 */
void Item::getCarryInfoParam(CarryInfoParam& param)
{
	param.mUseType  = 0;
	param.mPosition = mPosition;
	param.mPosition.y += 50.0f;
	param.mYOffsetMax = 50.0f;
	param._14         = 1;
	param.mValue1     = mCurrentWeight;
	param.mValue2     = mBagMaxWeight;
	param.mColor      = 6;
	param.mIsTopFirst = FALSE;
}

/*
 * --INFO--
 * Address:	801F62A8
 * Size:	0001E0
 */
Mgr::Mgr()
{
	mItemName = "DownFloor";
	sys->heapStatusStart("ItemDownFloor", nullptr);
	mObjectPathComponent = "user/Kando/objects/downfloor";
	setModelSize(3);

	JKRArchive* textArc = openTextArc("texts.szs");
	loadArchive("arc.szs");
	loadBmd("down_floor_1.bmd", 0, 0x20000);
	loadBmd("down_floor_2.bmd", 1, 0x20000);
	loadBmd("down_floor_3.bmd", 2, 0x20020000);

	loadAnimMgr(textArc, "animmgr.txt");
	mPlatforms = new Platform*[3];

	mPlatforms[0] = loadPlatform(textArc, "platform.bin");
	mPlatforms[1] = loadPlatform(textArc, "platform_2.bin");
	mPlatforms[2] = loadPlatform(textArc, "platform_3.bin");

	MapCode::Code mapCode;
	mapCode.setCode(MapCode::Code::Attribute1 | MapCode::Code::Attribute2, MapCode::Code::SlipCode0, true);

	mPlatforms[0]->setMapCodeAll(mapCode);
	mPlatforms[1]->setMapCodeAll(mapCode);
	mPlatforms[2]->setMapCodeAll(mapCode);

	for (int i = 0; i < 3; i++) {
		mModelData[i]->newSharedDisplayList(0x40000);
		mModelData[i]->makeSharedDL();
	}

	closeTextArc(textArc);

	sys->heapStatusEnd("ItemDownFloor");
}

/*
 * --INFO--
 * Address:	801F6488
 * Size:	0000F0
 */
void Mgr::setupDownFloor(Item* item)
{
	sys->heapStatusStart("new Model", nullptr);
	item->mModel = new SysShape::Model(mModelData[item->mModelType], 0x20000, 2);
	item->mModel->mJ3dModel->calc();
	item->mModel->mJ3dModel->calcMaterial();
	item->mModel->mJ3dModel->makeDL();
	item->mModel->mJ3dModel->lock();
	sys->heapStatusEnd("new Model");
	item->mAnimator.mAnimMgr = mAnimMgr;
	item->mAnimator.startAnim(0, nullptr);
}

/*
 * --INFO--
 * Address:	801F6578
 * Size:	000108
 */
void Mgr::setupPlatform(Item* item)
{
	sys->heapStatusStart("Platform", nullptr);
	sys->heapStatusStart("Platform-Down", nullptr);
	Matrixf* worldMat = item->mModel->getJoint("move")->getWorldMatrix();
	if (!worldMat) {
		item->mModel->mJoints[0].getWorldMatrix(); // feel like worldMat is meant to get set to this, but it doesn't.
	}

	ID32 id('down');
	PlatAddInstanceArg platArg;
	platArg.mItem     = item;
	platArg.mId       = id;
	platArg.mPlatform = mPlatforms[item->mModelType];
	platArg.mMatrix   = worldMat;

	item->mPlatInstance = platMgr->addInstance(platArg);

	sys->heapStatusEnd("Platform-Down");
	sys->heapStatusEnd("Platform");
}

/*
 * --INFO--
 * Address:	801F6680
 * Size:	000004
 */
void Mgr::onLoadResources() { }

/*
 * --INFO--
 * Address:	801F6684
 * Size:	00017C
 */
BaseItem* Mgr::birth()
{
	sys->heapStatusStart("ItemDownFloor", nullptr);
	Item* downFloor = new Item;
	entry(downFloor);
	sys->heapStatusEnd("ItemDownFloor");
	return downFloor;
}

/*
 * --INFO--
 * Address:	801F6800
 * Size:	00003C
 */
char* Mgr::getCaveName(int type)
{
	if (type == DFMODEL_SmallBlock) {
		return "DownFloor";
	} else if (type == DFMODEL_LargeBlock) {
		return "DownFloor2";
	} else if (type == DFMODEL_PaperBag) {
		return "DownFloor3";
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	801F683C
 * Size:	0000B0
 */
int Mgr::getCaveID(char* name)
{
	int id;
	if (strncmp("DownFloor", name, strlen("DownFloor")) == 0) {
		return DFMODEL_SmallBlock;
	}
	if (strncmp("DownFloor2", name, strlen("DownFloor2")) == 0) {
		return DFMODEL_LargeBlock;
	}
	if (strncmp("DownFloor3", name, strlen("DownFloor3")) != 0) {
		return -1;
	}

	return DFMODEL_PaperBag;
}

/*
 * --INFO--
 * Address:	801F68EC
 * Size:	000068
 */
void WaitState::init(Item* item, StateArg* stateArg)
{
	if (!item->mIsPressed) {
		item->mAnimator.startAnim(0, nullptr);
	} else {
		item->mAnimator.startAnim(2, nullptr);
		item->mAnimator.setLastFrame();
	}
	item->mAnimSpeed = 0.0f;
}

/*
 * --INFO--
 * Address:	801F6954
 * Size:	000060
 */
void WaitState::exec(Item* item)
{
	if (item->mDownFloorType != DFTYPE_PaperBag && !item->mIsPressed && item->mCurrentWeight > item->mOtherSeesaw->mCurrentWeight) {
		transit(item, DOWNFLOOR_Down, nullptr);
	}
}

/*
 * --INFO--
 * Address:	801F69E4
 * Size:	000004
 */
void WaitState::cleanup(Item*) { }

/*
 * --INFO--
 * Address:	801F69E8
 * Size:	000004
 */
void WaitState::onKeyEvent(Item*, SysShape::KeyEvent const&) { }

/*
 * --INFO--
 * Address:	801F69EC
 * Size:	000040
 */
void WaitState::onPlat(Item* item)
{
	if (!item->mIsPressed) {
		transit(item, DOWNFLOOR_Damaged, nullptr);
	}
}

/*
 * --INFO--
 * Address:	801F6A2C
 * Size:	000038
 */
void DamagedState::init(Item* item, StateArg* stateArg)
{
	item->startDamageMotion();
	mIsReady = false;
}

/*
 * --INFO--
 * Address:	801F6A64
 * Size:	0000C4
 */
void DamagedState::exec(Item* item)
{
	if (mIsReady) {
		if (item->mDownFloorType != DFTYPE_PaperBag) {
			if (item->mCurrentWeight > item->mOtherSeesaw->mCurrentWeight) {
				transit(item, DOWNFLOOR_Down, nullptr);
			} else {
				transit(item, DOWNFLOOR_Wait, nullptr);
			}
		} else if (item->mCurrentWeight >= item->mBagMaxWeight) {
			transit(item, DOWNFLOOR_Down, nullptr);
		} else {
			transit(item, DOWNFLOOR_Wait, nullptr);
		}
	}
}

/*
 * --INFO--
 * Address:	801F6B28
 * Size:	000004
 */
void DamagedState::cleanup(Item*) { }

/*
 * --INFO--
 * Address:	801F6B2C
 * Size:	00000C
 */
void DamagedState::onKeyEvent(Item*, SysShape::KeyEvent const&) { mIsReady = true; }

/*
 * --INFO--
 * Address:	801F6B38
 * Size:	000004
 */
void DamagedState::onPlat(Item*) { }

/*
 * --INFO--
 * Address:	801F6B3C
 * Size:	00009C
 */
void DownState::init(Item* item, StateArg* stateArg)
{
	item->startDownMotion();
	if (item->mOtherSeesaw) {
		item->mOtherSeesaw->mFsm->transit(item->mOtherSeesaw, DOWNFLOOR_Up, nullptr);
		if (item->mIsDemoBlock && item->mWayPoint) {
			item->mWayPoint->setOpen(true);
		}

		if (item->mOtherSeesaw->mIsDemoBlock && item->mOtherSeesaw->mWayPoint) {
			item->mOtherSeesaw->mWayPoint->setOpen(false);
		}
	}
}

/*
 * --INFO--
 * Address:	801F6BD8
 * Size:	000004
 */
void DownState::exec(Item*) { }

/*
 * --INFO--
 * Address:	801F6BDC
 * Size:	000004
 */
void DownState::cleanup(Item*) { }

/*
 * --INFO--
 * Address:	801F6BE0
 * Size:	000220
 */
void DownState::onKeyEvent(Item* item, SysShape::KeyEvent const&)
{
	item->mIsPressed = true;
	if (item->mDownFloorType == DFTYPE_PaperBag) {
		item->mSoundEvent.finish();
		P2ASSERTLINE(1100, item->mSoundObj->getCastType() == PSM::CCT_WorkItem);
		static_cast<PSM::WorkItem*>(item->mSoundObj)->eventFinish();
		item->mPlatInstance->setCollision(false);
		if (item->mCarryInfoList) {
			item->mCarryInfoList->mParam.mCarryInfo.disappear();
			item->mCarryInfoList = nullptr;
		}

		platMgr->delInstance(item->mPlatInstance);
		PSSystem::spSysIF->playSystemSe(PSSE_SY_WORK_FINISH, 0);

		if (item->mWayPoint) {
			item->mWayPoint->setOpen(true);
		}

		if (!playData->isDemoFlag(DEMO_You_Appear_Lost)) {
			playData->setDemoFlag(DEMO_You_Appear_Lost);
		}

		if (!playData->isDemoFlag(DEMO_Reunite_Captains)) {
			Navi* navi = naviMgr->getAt(1);
			MoviePlayArg playArg("x06_join", nullptr, nullptr, 0);
			playArg.mOrigin            = navi->getPosition();
			playArg.mAngle             = navi->getFaceDir();
			moviePlayer->mTargetObject = navi;

			moviePlayer->play(playArg);

			playData->setDemoFlag(DEMO_Reunite_Captains);

			gameSystem->mSection->disableTimer(DEMOTIMER_CrushBag);
		}

	} else {
		transit(item, DOWNFLOOR_Wait, nullptr);
	}
}

/*
 * --INFO--
 * Address:	801F6E00
 * Size:	000004
 */
void DownState::onPlat(Item*) { }

/*
 * --INFO--
 * Address:	801F6E04
 * Size:	000024
 */
void UpState::init(Item* item, StateArg*) { item->startUpMotion(); }

/*
 * --INFO--
 * Address:	801F6E28
 * Size:	000004
 */
void UpState::exec(Item*) { }

/*
 * --INFO--
 * Address:	801F6E2C
 * Size:	000004
 */
void UpState::cleanup(Item*) { }

/*
 * --INFO--
 * Address:	801F6E30
 * Size:	00003C
 */
void UpState::onKeyEvent(Item* item, SysShape::KeyEvent const&)
{
	item->mIsPressed = false;
	transit(item, DOWNFLOOR_Wait, nullptr);
}

/*
 * --INFO--
 * Address:	801F6E6C
 * Size:	000004
 */
void UpState::onPlat(Item*) { }

/*
 * --INFO--
 * Address:	801F6E70
 * Size:	00007C
 */
GenItemParm* Mgr::generatorNewItemParm() { return new GenDownFloorParm(); }

/*
 * --INFO--
 * Address:	801F6EEC
 * Size:	000104
 */
void Mgr::generatorWrite(Stream& input, GenItemParm* genParm)
{
	GenDownFloorParm* downParm = static_cast<GenDownFloorParm*>(genParm);
	P2ASSERTLINE(1246, downParm);
	input.textWriteTab(input.mTabCount);
	input.writeShort(downParm->mBagWeight);
	input.textWriteText("\t#���ݐl��\r\n"); // '#number of people sinking'

	input.textWriteTab(input.mTabCount);
	input.writeShort(downParm->mModelType);
	input.textWriteText("\t#type\r\n"); // '#type'

	input.textWriteTab(input.mTabCount);
	input.writeByte(downParm->mDownFloorType);
	input.textWriteText("\t# 1:seesaw\r\n"); // '# 1: seesaw'

	input.textWriteTab(input.mTabCount);
	downParm->mId.write(input);
	input.textWriteText("\t# id\r\n"); // '# id'
}

/*
 * --INFO--
 * Address:	801F6FF0
 * Size:	0000CC
 */
void Mgr::generatorRead(Stream& input, GenItemParm* genParm, u32 version)
{
	GenDownFloorParm* downParm = static_cast<GenDownFloorParm*>(genParm);
	P2ASSERTLINE(1268, downParm);
	downParm->mBagWeight = input.readShort();

	if (version >= '0001') {
		downParm->mModelType = input.readShort();
	} else {
		downParm->mModelType = DFMODEL_SmallBlock;
	}

	if (version >= '0002') {
		downParm->mDownFloorType = input.readByte();
		downParm->mId.read(input);
	} else {
		downParm->mDownFloorType = DFTYPE_PaperBag;
	}
}

/*
 * --INFO--
 * Address:	801F70BC
 * Size:	0001E4
 */
BaseItem* Mgr::generatorBirth(Vector3f& pos, Vector3f& rot, GenItemParm* genParm)
{
	GenDownFloorParm* downParm = static_cast<GenDownFloorParm*>(genParm);
	P2ASSERTLINE(1286, downParm);
	Item* downFloor           = static_cast<Item*>(birth());
	downFloor->mBagMaxWeight  = downParm->mBagWeight;
	downFloor->mModelType     = downParm->mModelType;
	downFloor->mDownFloorType = downParm->mDownFloorType;
	downFloor->mID.setID(downParm->mId.getID());
	downFloor->init(nullptr);
	downFloor->mFaceDir = roundAng(rot.y);
	downFloor->setPosition(pos, false);
	return downFloor;
}

} // namespace ItemDownFloor
} // namespace Game
