#include "PikiAI.h"
#include "Dolphin/rand.h"
#include "KandoLib/Choice.h"
#include "Game/Piki.h"
#include "System.h"
#include "PSSystem/PSGame.h"
#include "PSSystem/PSScene.h"
#include "PSM/Scene.h"

// idk how this is supposed to work
// const KandoLib::Choice test[4] = {
// 	KandoLib::Choice(Game::IPikiAnims::AKUBI, 0.05f),
// 	KandoLib::Choice(Game::IPikiAnims::CHATTING, 0.35f),
// 	KandoLib::Choice(Game::IPikiAnims::SAGASU2, 0.4f),
// 	KandoLib::Choice(Game::IPikiAnims::IRAIRA, 0.1f),
// };

namespace PikiAI {
/*
 * --INFO--
 * Address:	802312F4
 * Size:	000098
 */
ActBore::ActBore(Game::Piki* piki)
    : Action(piki)
{
	mFlag       = 0;
	mActions[0] = new ActRest(piki);
	mActions[1] = new ActOneshot(piki);
}

/*
 * --INFO--
 * Address:	8023138C
 * Size:	000080
 */
void ActBore::init(ActionArg* arg)
{
	mRandBehaviorType = randFloat() * 2.0f;
	mTimer            = 0.0f;
	startCurrAction();
	mFlag = 0;
}

/*
 * --INFO--
 * Address:	8023140C
 * Size:	000180
 */
void ActBore::startCurrAction()
{
	P2ASSERTLINE(39, mRandBehaviorType < 2);
	if (mTimer < 2.0f) {
		mRandBehaviorType = 1;
	}

	switch (mRandBehaviorType) {
	case 0:
		mActions[mRandBehaviorType]->init(nullptr);
		break;
	case 1:
		ActOneshotArg arg;
		KandoLib::Choice choice[4]
		    = { KandoLib::Choice(Game::IPikiAnims::AKUBI, 0.05f), KandoLib::Choice(Game::IPikiAnims::CHATTING, 0.35f),
			    KandoLib::Choice(Game::IPikiAnims::SAGASU2, 0.4f), KandoLib::Choice(Game::IPikiAnims::IRAIRA, 0.1f) };
		arg.mAnimID = KandoLib::getRandomChoice(choice, 4);
		mActions[mRandBehaviorType]->init(&arg);
		break;
	}
	_10 = randFloat() * 6.0f + 6.0f;
	/*
	stwu     r1, -0x50(r1)
	mflr     r0
	stw      r0, 0x54(r1)
	stw      r31, 0x4c(r1)
	mr       r31, r3
	lis      r3, lbl_80483930@ha
	stw      r30, 0x48(r1)
	stw      r29, 0x44(r1)
	addi     r29, r3, lbl_80483930@l
	lbz      r0, 0xc(r31)
	cmplwi   r0, 2
	blt      lbl_80231450
	addi     r3, r29, 0x20
	addi     r5, r29, 0x2c
	li       r4, 0x27
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80231450:
	lfs      f1, 0x14(r31)
	lfs      f0, lbl_8051A374@sda21(r2)
	fcmpo    cr0, f1, f0
	bge      lbl_80231468
	li       r0, 1
	stb      r0, 0xc(r31)

lbl_80231468:
	lbz      r0, 0xc(r31)
	cmpwi    r0, 1
	beq      lbl_802314A8
	bge      lbl_8023153C
	cmpwi    r0, 0
	bge      lbl_80231484
	b        lbl_8023153C

lbl_80231484:
	rlwinm   r0, r0, 2, 0x16, 0x1d
	li       r4, 0
	add      r3, r31, r0
	lwz      r3, 0x1c(r3)
	lwz      r12, 0(r3)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	b        lbl_8023153C

lbl_802314A8:
	lis      r3, __vt__Q26PikiAI9ActionArg@ha
	lwz      r11, 0(r29)
	addi     r0, r3, __vt__Q26PikiAI9ActionArg@l
	lwz      r10, 4(r29)
	lwz      r9, 8(r29)
	lis      r3, __vt__Q26PikiAI13ActOneshotArg@ha
	lwz      r8, 0xc(r29)
	li       r12, -1
	lwz      r7, 0x10(r29)
	addi     r30, r3, __vt__Q26PikiAI13ActOneshotArg@l
	stw      r0, 8(r1)
	addi     r3, r1, 0x10
	lwz      r6, 0x14(r29)
	li       r4, 4
	lwz      r5, 0x18(r29)
	lwz      r0, 0x1c(r29)
	stw      r30, 8(r1)
	stw      r12, 0xc(r1)
	stw      r11, 0x10(r1)
	stw      r10, 0x14(r1)
	stw      r9, 0x18(r1)
	stw      r8, 0x1c(r1)
	stw      r7, 0x20(r1)
	stw      r6, 0x24(r1)
	stw      r5, 0x28(r1)
	stw      r0, 0x2c(r1)
	bl       getRandomChoice__8KandoLibFPQ28KandoLib6Choicei
	stw      r3, 0xc(r1)
	addi     r4, r1, 8
	lbz      r0, 0xc(r31)
	slwi     r0, r0, 2
	add      r3, r31, r0
	lwz      r3, 0x1c(r3)
	lwz      r12, 0(r3)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl

lbl_8023153C:
	bl       rand
	xoris    r3, r3, 0x8000
	lis      r0, 0x4330
	stw      r3, 0x34(r1)
	lfd      f3, lbl_8051A380@sda21(r2)
	stw      r0, 0x30(r1)
	lfs      f1, lbl_8051A370@sda21(r2)
	lfd      f2, 0x30(r1)
	lfs      f0, lbl_8051A388@sda21(r2)
	fsubs    f2, f2, f3
	fdivs    f1, f2, f1
	fmadds   f0, f0, f1, f0
	stfs     f0, 0x10(r31)
	lwz      r31, 0x4c(r1)
	lwz      r30, 0x48(r1)
	lwz      r29, 0x44(r1)
	lwz      r0, 0x54(r1)
	mtlr     r0
	addi     r1, r1, 0x50
	blr
	*/
}

/*
 * --INFO--
 * Address:	8023158C
 * Size:	00007C
 */
void ActBore::finish()
{
	P2ASSERTLINE(70, mRandBehaviorType < 2);
	mActions[mRandBehaviorType]->finish();
	mFlag |= 1;
}

/*
 * --INFO--
 * Address:	80231608
 * Size:	000294
 */
int ActBore::exec()
{
	if (mTimer < 2.0f) {
		mTimer += sys->mDeltaTime;
	}
	P2ASSERTLINE(81, mRandBehaviorType < 2);
	int stat = mActions[mRandBehaviorType]->exec();
	if (stat == 0 || stat == 2) {
		if (mFlag & 1) {
			return ACTEXEC_Success;
		}
		mRandBehaviorType = randFloat() * 2.0f;
		startCurrAction();
	} else {
		_10 -= sys->mDeltaTime;
		if (_10 <= 0.0f) {
			mActions[mRandBehaviorType]->finish();
		}
	}
	return ACTEXEC_Continue;
	/*
	stwu     r1, -0x50(r1)
	mflr     r0
	lfs      f0, lbl_8051A374@sda21(r2)
	stw      r0, 0x54(r1)
	stw      r31, 0x4c(r1)
	stw      r30, 0x48(r1)
	mr       r30, r3
	lis      r3, lbl_80483930@ha
	stw      r29, 0x44(r1)
	addi     r31, r3, lbl_80483930@l
	lfs      f1, 0x14(r30)
	fcmpo    cr0, f1, f0
	bge      lbl_8023164C
	lwz      r3, sys@sda21(r13)
	lfs      f0, 0x54(r3)
	fadds    f0, f1, f0
	stfs     f0, 0x14(r30)

lbl_8023164C:
	lbz      r0, 0xc(r30)
	cmplwi   r0, 2
	blt      lbl_8023166C
	addi     r3, r31, 0x20
	addi     r5, r31, 0x2c
	li       r4, 0x51
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8023166C:
	lbz      r0, 0xc(r30)
	slwi     r0, r0, 2
	add      r3, r30, r0
	lwz      r3, 0x1c(r3)
	lwz      r12, 0(r3)
	lwz      r12, 0xc(r12)
	mtctr    r12
	bctrl
	cmpwi    r3, 0
	beq      lbl_8023169C
	cmpwi    r3, 2
	bne      lbl_80231834

lbl_8023169C:
	lbz      r0, 0x18(r30)
	clrlwi.  r0, r0, 0x1f
	beq      lbl_802316B0
	li       r3, 0
	b        lbl_80231880

lbl_802316B0:
	bl       rand
	xoris    r3, r3, 0x8000
	lis      r0, 0x4330
	stw      r3, 0x34(r1)
	lfd      f3, lbl_8051A380@sda21(r2)
	stw      r0, 0x30(r1)
	lfs      f1, lbl_8051A370@sda21(r2)
	lfd      f2, 0x30(r1)
	lfs      f0, lbl_8051A374@sda21(r2)
	fsubs    f2, f2, f3
	fdivs    f1, f2, f1
	fmuls    f0, f0, f1
	fctiwz   f0, f0
	stfd     f0, 0x38(r1)
	lwz      r0, 0x3c(r1)
	stb      r0, 0xc(r30)
	lbz      r0, 0xc(r30)
	cmplwi   r0, 2
	blt      lbl_80231710
	addi     r3, r31, 0x20
	addi     r5, r31, 0x2c
	li       r4, 0x27
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80231710:
	lfs      f1, 0x14(r30)
	lfs      f0, lbl_8051A374@sda21(r2)
	fcmpo    cr0, f1, f0
	bge      lbl_80231728
	li       r0, 1
	stb      r0, 0xc(r30)

lbl_80231728:
	lbz      r0, 0xc(r30)
	cmpwi    r0, 1
	beq      lbl_80231768
	bge      lbl_802317FC
	cmpwi    r0, 0
	bge      lbl_80231744
	b        lbl_802317FC

lbl_80231744:
	rlwinm   r0, r0, 2, 0x16, 0x1d
	li       r4, 0
	add      r3, r30, r0
	lwz      r3, 0x1c(r3)
	lwz      r12, 0(r3)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	b        lbl_802317FC

lbl_80231768:
	lis      r3, __vt__Q26PikiAI9ActionArg@ha
	lwz      r11, 0(r31)
	addi     r0, r3, __vt__Q26PikiAI9ActionArg@l
	lwz      r10, 4(r31)
	lwz      r9, 8(r31)
	lis      r3, __vt__Q26PikiAI13ActOneshotArg@ha
	lwz      r8, 0xc(r31)
	li       r12, -1
	lwz      r7, 0x10(r31)
	addi     r29, r3, __vt__Q26PikiAI13ActOneshotArg@l
	stw      r0, 8(r1)
	addi     r3, r1, 0x10
	lwz      r6, 0x14(r31)
	li       r4, 4
	lwz      r5, 0x18(r31)
	lwz      r0, 0x1c(r31)
	stw      r29, 8(r1)
	stw      r12, 0xc(r1)
	stw      r11, 0x10(r1)
	stw      r10, 0x14(r1)
	stw      r9, 0x18(r1)
	stw      r8, 0x1c(r1)
	stw      r7, 0x20(r1)
	stw      r6, 0x24(r1)
	stw      r5, 0x28(r1)
	stw      r0, 0x2c(r1)
	bl       getRandomChoice__8KandoLibFPQ28KandoLib6Choicei
	stw      r3, 0xc(r1)
	addi     r4, r1, 8
	lbz      r0, 0xc(r30)
	slwi     r0, r0, 2
	add      r3, r30, r0
	lwz      r3, 0x1c(r3)
	lwz      r12, 0(r3)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl

lbl_802317FC:
	bl       rand
	xoris    r3, r3, 0x8000
	lis      r0, 0x4330
	stw      r3, 0x3c(r1)
	lfd      f3, lbl_8051A380@sda21(r2)
	stw      r0, 0x38(r1)
	lfs      f1, lbl_8051A370@sda21(r2)
	lfd      f2, 0x38(r1)
	lfs      f0, lbl_8051A388@sda21(r2)
	fsubs    f2, f2, f3
	fdivs    f1, f2, f1
	fmadds   f0, f0, f1, f0
	stfs     f0, 0x10(r30)
	b        lbl_8023187C

lbl_80231834:
	lwz      r3, sys@sda21(r13)
	lfs      f2, 0x10(r30)
	lfs      f1, 0x54(r3)
	lfs      f0, lbl_8051A378@sda21(r2)
	fsubs    f1, f2, f1
	stfs     f1, 0x10(r30)
	lfs      f1, 0x10(r30)
	fcmpo    cr0, f1, f0
	cror     2, 0, 2
	bne      lbl_8023187C
	lbz      r0, 0xc(r30)
	slwi     r0, r0, 2
	add      r3, r30, r0
	lwz      r3, 0x1c(r3)
	lwz      r12, 0(r3)
	lwz      r12, 0x3c(r12)
	mtctr    r12
	bctrl

lbl_8023187C:
	li       r3, 1

lbl_80231880:
	lwz      r0, 0x54(r1)
	lwz      r31, 0x4c(r1)
	lwz      r30, 0x48(r1)
	lwz      r29, 0x44(r1)
	mtlr     r0
	addi     r1, r1, 0x50
	blr
	*/
}

/*
 * --INFO--
 * Address:	8023189C
 * Size:	000004
 */
void ActBore::cleanup() { }

/*
 * --INFO--
 * Address:	802318A0
 * Size:	00009C
 */
ActRest::ActRest(Game::Piki* piki)
    : ActBoreBase(piki)
{
	mFlag = 0;
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	extsh.   r0, r4
	stw      r31, 0xc(r1)
	mr       r31, r3
	beq      lbl_802318D0
	addi     r0, r31, 0x1c
	lis      r3, __vt__Q28SysShape14MotionListener@ha
	stw      r0, 0xc(r31)
	addi     r0, r3, __vt__Q28SysShape14MotionListener@l
	stw      r0, 0x1c(r31)

lbl_802318D0:
	mr       r3, r31
	mr       r4, r5
	bl       __ct__Q26PikiAI6ActionFPQ24Game4Piki
	lis      r4, __vt__Q26PikiAI11ActBoreBase@ha
	lis      r3, __vt__Q26PikiAI7ActRest@ha
	addi     r6, r4, __vt__Q26PikiAI11ActBoreBase@l
	addi     r4, r31, 0x1c
	stw      r6, 0(r31)
	addi     r5, r3, __vt__Q26PikiAI7ActRest@l
	addi     r8, r6, 0x40
	li       r0, 0
	lwz      r7, 0xc(r31)
	addi     r6, r5, 0x44
	mr       r3, r31
	stw      r8, 0(r7)
	stw      r5, 0(r31)
	lwz      r5, 0xc(r31)
	stw      r6, 0(r5)
	lwz      r5, 0xc(r31)
	subf     r4, r5, r4
	stw      r4, 4(r5)
	stb      r0, 0x18(r31)
	lwz      r31, 0xc(r1)
	lwz      r0, 0x14(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	8023193C
 * Size:	00001C
 */
void ActRest::finish()
{
	mFlag |= 4;
	mParent->mAnimSpeed = 60.0f;
}

/*
 * --INFO--
 * Address:	80231958
 * Size:	000080
 */
void ActRest::init(ActionArg* arg)
{
	mState = 0;
	sitDown();
	mTimer              = randFloat() * 4.0f + 5.0f;
	mFlag               = 0;
	mParent->mAnimSpeed = 30.0f;
}

/*
 * --INFO--
 * Address:	802319D8
 * Size:	0000B8
 */
void ActRest::sitDown()
{
	switch (mState) {
	case 0:
		mParent->startMotion(Game::IPikiAnims::SUWARU, Game::IPikiAnims::SUWARU, this, nullptr);
		mState = 1;
		break;

	case 1:
		mParent->startMotion(Game::IPikiAnims::NERU, Game::IPikiAnims::NERU, this, nullptr);
		mState = 3;
		break;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void ActRest::standUp()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80231A90
 * Size:	000330
 */
int ActRest::exec()
{
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	stw      r0, 0x24(r1)
	stw      r31, 0x1c(r1)
	mr       r31, r3
	lbz      r0, 0x18(r3)
	rlwinm.  r0, r0, 0, 0x1e, 0x1e
	beq      lbl_80231AB8
	li       r3, 0
	b        lbl_80231DAC

lbl_80231AB8:
	lwz      r3, 4(r31)
	lfs      f0, lbl_8051A378@sda21(r2)
	stfs     f0, 0x1e4(r3)
	stfs     f0, 0x1e8(r3)
	stfs     f0, 0x1ec(r3)
	lwz      r3, 4(r31)
	lfs      f1, 0x234(r3)
	fcmpu    cr0, f0, f1
	bne      lbl_80231AE4
	lfs      f0, lbl_8051A398@sda21(r2)
	stfs     f0, 0x234(r3)

lbl_80231AE4:
	lwz      r3, 4(r31)
	lwz      r4, 0x1b8(r3)
	cmplwi   r4, 0
	beq      lbl_80231AFC
	lha      r0, 0x20(r4)
	b        lbl_80231B00

lbl_80231AFC:
	li       r0, -1

lbl_80231B00:
	cmpwi    r0, 0x39
	beq      lbl_80231B18
	cmpwi    r0, 0x38
	beq      lbl_80231B18
	li       r3, 2
	b        lbl_80231DAC

lbl_80231B18:
	lbz      r4, 0x18(r31)
	rlwinm.  r0, r4, 0, 0x1d, 0x1d
	beq      lbl_80231C10
	clrlwi.  r0, r4, 0x1f
	bne      lbl_80231B90
	lbz      r0, 0x10(r31)
	cmplwi   r0, 1
	blt      lbl_80231B88
	cmpwi    r0, 2
	beq      lbl_80231B80
	bge      lbl_80231B50
	cmpwi    r0, 1
	bge      lbl_80231B5C
	b        lbl_80231B80

lbl_80231B50:
	cmpwi    r0, 4
	bge      lbl_80231B80
	b        lbl_80231B70

lbl_80231B5C:
	bl       finishMotion__Q24Game8FakePikiFv
	lbz      r0, 0x18(r31)
	ori      r0, r0, 1
	stb      r0, 0x18(r31)
	b        lbl_80231B80

lbl_80231B70:
	bl       finishMotion__Q24Game8FakePikiFv
	lbz      r0, 0x18(r31)
	ori      r0, r0, 1
	stb      r0, 0x18(r31)

lbl_80231B80:
	li       r3, 1
	b        lbl_80231DAC

lbl_80231B88:
	li       r3, 0
	b        lbl_80231DAC

lbl_80231B90:
	lbz      r0, 0x1c4(r3)
	clrlwi.  r0, r0, 0x1f
	beq      lbl_80231C08
	rlwinm   r0, r4, 0, 0x18, 0x1e
	stb      r0, 0x18(r31)
	lbz      r0, 0x10(r31)
	cmplwi   r0, 3
	bne      lbl_80231C08
	li       r0, 1
	cmplwi   r31, 0
	stb      r0, 0x10(r31)
	mr       r6, r31
	beq      lbl_80231BC8
	lwz      r6, 0xc(r31)

lbl_80231BC8:
	lwz      r3, 4(r31)
	li       r4, 0x38
	li       r5, 0x38
	li       r7, 0
	lwz      r12, 0(r3)
	lwz      r12, 0x208(r12)
	mtctr    r12
	bctrl
	lwz      r3, 4(r31)
	li       r4, 0
	addi     r3, r3, 0x1ac
	bl       setFrameByKeyType__Q28SysShape8AnimatorFUl
	lwz      r3, 4(r31)
	li       r4, 0
	addi     r3, r3, 0x1c8
	bl       setFrameByKeyType__Q28SysShape8AnimatorFUl

lbl_80231C08:
	li       r3, 1
	b        lbl_80231DAC

lbl_80231C10:
	lwz      r3, sys@sda21(r13)
	lfs      f1, 0x14(r31)
	lfs      f0, 0x54(r3)
	fsubs    f0, f1, f0
	stfs     f0, 0x14(r31)
	lbz      r0, 0x18(r31)
	clrlwi.  r0, r0, 0x1f
	bne      lbl_80231DA8
	lfs      f1, 0x14(r31)
	lfs      f0, lbl_8051A378@sda21(r2)
	fcmpo    cr0, f1, f0
	bge      lbl_80231DA8
	lbz      r0, 0x10(r31)
	cmplwi   r0, 1
	bgt      lbl_80231D14
	bl       rand
	xoris    r3, r3, 0x8000
	lis      r0, 0x4330
	stw      r3, 0xc(r1)
	lfd      f3, lbl_8051A380@sda21(r2)
	stw      r0, 8(r1)
	lfs      f1, lbl_8051A370@sda21(r2)
	lfd      f2, 8(r1)
	lfs      f0, lbl_8051A39C@sda21(r2)
	fsubs    f2, f2, f3
	fdivs    f1, f2, f1
	fcmpo    cr0, f1, f0
	ble      lbl_80231D14
	lbz      r0, 0x10(r31)
	cmpwi    r0, 1
	beq      lbl_80231CD8
	bge      lbl_80231D70
	cmpwi    r0, 0
	bge      lbl_80231C9C
	b        lbl_80231D70

lbl_80231C9C:
	cmplwi   r31, 0
	mr       r6, r31
	beq      lbl_80231CAC
	lwz      r6, 0xc(r31)

lbl_80231CAC:
	lwz      r3, 4(r31)
	li       r4, 0x38
	li       r5, 0x38
	li       r7, 0
	lwz      r12, 0(r3)
	lwz      r12, 0x208(r12)
	mtctr    r12
	bctrl
	li       r0, 1
	stb      r0, 0x10(r31)
	b        lbl_80231D70

lbl_80231CD8:
	cmplwi   r31, 0
	mr       r6, r31
	beq      lbl_80231CE8
	lwz      r6, 0xc(r31)

lbl_80231CE8:
	lwz      r3, 4(r31)
	li       r4, 0x39
	li       r5, 0x39
	li       r7, 0
	lwz      r12, 0(r3)
	lwz      r12, 0x208(r12)
	mtctr    r12
	bctrl
	li       r0, 3
	stb      r0, 0x10(r31)
	b        lbl_80231D70

lbl_80231D14:
	lbz      r0, 0x10(r31)
	cmplwi   r0, 1
	blt      lbl_80231D70
	cmpwi    r0, 2
	beq      lbl_80231D70
	bge      lbl_80231D38
	cmpwi    r0, 1
	bge      lbl_80231D44
	b        lbl_80231D70

lbl_80231D38:
	cmpwi    r0, 4
	bge      lbl_80231D70
	b        lbl_80231D5C

lbl_80231D44:
	lwz      r3, 4(r31)
	bl       finishMotion__Q24Game8FakePikiFv
	lbz      r0, 0x18(r31)
	ori      r0, r0, 1
	stb      r0, 0x18(r31)
	b        lbl_80231D70

lbl_80231D5C:
	lwz      r3, 4(r31)
	bl       finishMotion__Q24Game8FakePikiFv
	lbz      r0, 0x18(r31)
	ori      r0, r0, 1
	stb      r0, 0x18(r31)

lbl_80231D70:
	bl       rand
	xoris    r3, r3, 0x8000
	lis      r0, 0x4330
	stw      r3, 0xc(r1)
	lfd      f3, lbl_8051A380@sda21(r2)
	stw      r0, 8(r1)
	lfs      f2, lbl_8051A370@sda21(r2)
	lfd      f0, 8(r1)
	lfs      f1, lbl_8051A374@sda21(r2)
	fsubs    f3, f0, f3
	lfs      f0, lbl_8051A3A0@sda21(r2)
	fdivs    f2, f3, f2
	fmadds   f0, f1, f2, f0
	stfs     f0, 0x14(r31)

lbl_80231DA8:
	li       r3, 1

lbl_80231DAC:
	lwz      r0, 0x24(r1)
	lwz      r31, 0x1c(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	80231DC0
 * Size:	000004
 */
void ActRest::cleanup() { }

/*
 * --INFO--
 * Address:	80231DC4
 * Size:	0001F4
 */
void ActRest::onKeyEvent(SysShape::KeyEvent const& event)
{
	switch (event.mType) {
	case 200:
		PSSystem::SceneMgr* mgr = PSSystem::getSceneMgr();
		PSSystem::checkSceneMgr(mgr);
		PSM::Scene_Game* scene = static_cast<PSM::Scene_Game*>(mgr->getChildScene());
		if (!scene->isGameScene()) {
			scene = nullptr; // masterful gambit, sir
		}
		if (scene->akubiOK()) {
			mParent->startSound(PSSE_PK_VC_SLEEP, true);
		}
		break;
	case 1000:
		if (mFlag & 1) {
			switch (mState) {
			case 1:
				mFlag &= ~1;
				mState = 0;
				mFlag |= 2;
				break;
			case 3:
				mFlag &= ~1;
				mState = 1;
				mParent->startMotion(Game::IPikiAnims::SUWARU, Game::IPikiAnims::SUWARU, this, nullptr);
				mParent->mAnimator.mSelfAnimator.setFrameByKeyType(0);
				mParent->mAnimator.mBoundAnimator.setFrameByKeyType(0);
				break;
			}
		}
		break;
	}
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	stw      r0, 0x24(r1)
	lwz      r0, 0x1c(r4)
	lis      r4, lbl_80483930@ha
	stw      r31, 0x1c(r1)
	mr       r31, r3
	cmpwi    r0, 0xc8
	stw      r30, 0x18(r1)
	addi     r30, r4, lbl_80483930@l
	stw      r29, 0x14(r1)
	beq      lbl_80231E10
	bge      lbl_80231E04
	cmpwi    r0, 1
	beq      lbl_80231F9C
	b        lbl_80231F9C

lbl_80231E04:
	cmpwi    r0, 0x3e8
	beq      lbl_80231EE8
	b        lbl_80231F9C

lbl_80231E10:
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_80231E30
	addi     r3, r30, 0x38
	addi     r5, r30, 0x2c
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80231E30:
	lwz      r29, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r29, 0
	bne      lbl_80231E50
	addi     r3, r30, 0x38
	addi     r5, r30, 0x2c
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80231E50:
	lwz      r0, 4(r29)
	cmplwi   r0, 0
	bne      lbl_80231E70
	addi     r3, r30, 0x44
	addi     r5, r30, 0x2c
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80231E70:
	lwz      r3, 4(r29)
	lwz      r29, 4(r3)
	cmplwi   r29, 0
	bne      lbl_80231E94
	addi     r3, r30, 0x44
	addi     r5, r30, 0x50
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80231E94:
	mr       r3, r29
	lwz      r12, 0(r29)
	lwz      r12, 0x40(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_80231EB4
	b        lbl_80231EB8

lbl_80231EB4:
	li       r29, 0

lbl_80231EB8:
	mr       r3, r29
	lwz      r12, 0(r29)
	lwz      r12, 0x68(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_80231F9C
	lwz      r3, 4(r31)
	li       r4, 0x283e
	li       r5, 1
	bl       startSound__Q24Game4PikiFUlb
	b        lbl_80231F9C

lbl_80231EE8:
	lbz      r3, 0x18(r31)
	clrlwi.  r0, r3, 0x1f
	beq      lbl_80231F9C
	lbz      r0, 0x10(r31)
	cmpwi    r0, 2
	beq      lbl_80231F9C
	bge      lbl_80231F10
	cmpwi    r0, 1
	bge      lbl_80231F1C
	b        lbl_80231F9C

lbl_80231F10:
	cmpwi    r0, 4
	bge      lbl_80231F9C
	b        lbl_80231F3C

lbl_80231F1C:
	rlwinm   r3, r3, 0, 0x18, 0x1e
	li       r0, 0
	stb      r3, 0x18(r31)
	stb      r0, 0x10(r31)
	lbz      r0, 0x18(r31)
	ori      r0, r0, 2
	stb      r0, 0x18(r31)
	b        lbl_80231F9C

lbl_80231F3C:
	rlwinm   r0, r3, 0, 0x18, 0x1e
	cmplwi   r31, 0
	stb      r0, 0x18(r31)
	li       r0, 1
	mr       r6, r31
	stb      r0, 0x10(r31)
	beq      lbl_80231F5C
	lwz      r6, 0xc(r31)

lbl_80231F5C:
	lwz      r3, 4(r31)
	li       r4, 0x38
	li       r5, 0x38
	li       r7, 0
	lwz      r12, 0(r3)
	lwz      r12, 0x208(r12)
	mtctr    r12
	bctrl
	lwz      r3, 4(r31)
	li       r4, 0
	addi     r3, r3, 0x1ac
	bl       setFrameByKeyType__Q28SysShape8AnimatorFUl
	lwz      r3, 4(r31)
	li       r4, 0
	addi     r3, r3, 0x1c8
	bl       setFrameByKeyType__Q28SysShape8AnimatorFUl

lbl_80231F9C:
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
 * Address:	80231FB8
 * Size:	0000BC
 */
ActOneshot::ActOneshot(Game::Piki* piki)
    : ActBoreBase(piki)
    , mFlag(0)
{
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	extsh.   r0, r4
	stw      r31, 0xc(r1)
	mr       r31, r3
	beq      lbl_80231FE8
	addi     r0, r31, 0x1c
	lis      r3, __vt__Q28SysShape14MotionListener@ha
	stw      r0, 0xc(r31)
	addi     r0, r3, __vt__Q28SysShape14MotionListener@l
	stw      r0, 0x1c(r31)

lbl_80231FE8:
	mr       r3, r31
	mr       r4, r5
	bl       __ct__Q26PikiAI6ActionFPQ24Game4Piki
	lis      r4, __vt__Q26PikiAI11ActBoreBase@ha
	lis      r3, __vt__Q26PikiAI10ActOneshot@ha
	addi     r5, r4, __vt__Q26PikiAI11ActBoreBase@l
	lis      r4, __vt__Q26PikiAI9ActionArg@ha
	stw      r5, 0(r31)
	addi     r8, r3, __vt__Q26PikiAI10ActOneshot@l
	lis      r3, __vt__Q26PikiAI13ActOneshotArg@ha
	addi     r0, r5, 0x40
	lwz      r5, 0xc(r31)
	addi     r9, r8, 0x44
	addi     r7, r31, 0x1c
	addi     r6, r4, __vt__Q26PikiAI9ActionArg@l
	stw      r0, 0(r5)
	addi     r5, r3, __vt__Q26PikiAI13ActOneshotArg@l
	li       r4, -1
	li       r0, 0
	stw      r8, 0(r31)
	mr       r3, r31
	lwz      r8, 0xc(r31)
	stw      r9, 0(r8)
	lwz      r8, 0xc(r31)
	subf     r7, r8, r7
	stw      r7, 4(r8)
	stw      r6, 0x10(r31)
	stw      r5, 0x10(r31)
	stw      r4, 0x14(r31)
	stb      r0, 0x18(r31)
	lwz      r31, 0xc(r1)
	lwz      r0, 0x14(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	80232074
 * Size:	000094
 */
void ActOneshot::init(ActionArg* arg)
{
	P2ASSERTLINE(267, arg);
	ActOneshotArg* sarg = static_cast<ActOneshotArg*>(arg);
	mOneshotArg.mAnimID = sarg->mAnimID;
	mParent->startMotion(mOneshotArg.mAnimID, mOneshotArg.mAnimID, this, nullptr);
	mFlag = 0;
}

/*
 * --INFO--
 * Address:	80232108
 * Size:	000048
 */
void ActOneshot::finish()
{
	mParent->mAnimSpeed = 60.0f;
	mParent->finishMotion();
	mFlag |= 2;
}

/*
 * --INFO--
 * Address:	80232150
 * Size:	000070
 */
int ActOneshot::exec()
{
	Vector3f vel(0.0f);
	mParent->setCurrVelocity(vel);
	if (mFlag & 2) {
		return ACTEXEC_Success;
	}
	if (mFlag & 1) {
		return ACTEXEC_Success;
	}
	int id = mParent->mAnimator.mSelfAnimator.getAnimIndex();
	if (mOneshotArg.mAnimID != id) {
		return ACTEXEC_Fail;
	}
	return ACTEXEC_Continue;
}

/*
 * --INFO--
 * Address:	802321C0
 * Size:	000004
 */
void ActOneshot::cleanup() { }

/*
 * --INFO--
 * Address:	802321C4
 * Size:	000150
 */
void ActOneshot::onKeyEvent(SysShape::KeyEvent const& event)
{
	if (event.mType == 1000) {
		mFlag |= 1;
	}
	if (event.mType != 200 || mOneshotArg.mAnimID != 0) {
		return;
	}
	PSSystem::SceneMgr* mgr = PSSystem::getSceneMgr();
	PSSystem::checkSceneMgr(mgr);
	PSM::SceneBase* scene = static_cast<PSM::SceneBase*>(mgr->getChildScene());
	if (scene->isGameScene() && static_cast<PSM::Scene_Game*>(scene)->akubiOK()) {
		mParent->mSoundObj->startFreePikiSound(PSSE_PK_VC_AKUBI, 90, 0);
	}
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	lis      r5, lbl_80483930@ha
	stw      r0, 0x24(r1)
	lwz      r0, 0x1c(r4)
	stw      r31, 0x1c(r1)
	addi     r31, r5, lbl_80483930@l
	cmplwi   r0, 0x3e8
	stw      r30, 0x18(r1)
	stw      r29, 0x14(r1)
	mr       r29, r3
	bne      lbl_80232200
	lbz      r0, 0x18(r29)
	ori      r0, r0, 1
	stb      r0, 0x18(r29)

lbl_80232200:
	lwz      r0, 0x1c(r4)
	cmplwi   r0, 0xc8
	bne      lbl_802322F8
	lwz      r0, 0x14(r29)
	cmpwi    r0, 0
	beq      lbl_8023221C
	b        lbl_802322F8

lbl_8023221C:
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_8023223C
	addi     r3, r31, 0x38
	addi     r5, r31, 0x2c
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8023223C:
	lwz      r30, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r30, 0
	bne      lbl_8023225C
	addi     r3, r31, 0x38
	addi     r5, r31, 0x2c
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8023225C:
	lwz      r0, 4(r30)
	cmplwi   r0, 0
	bne      lbl_8023227C
	addi     r3, r31, 0x44
	addi     r5, r31, 0x2c
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8023227C:
	lwz      r3, 4(r30)
	lwz      r30, 4(r3)
	cmplwi   r30, 0
	bne      lbl_802322A0
	addi     r3, r31, 0x44
	addi     r5, r31, 0x50
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_802322A0:
	mr       r3, r30
	lwz      r12, 0(r30)
	lwz      r12, 0x40(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_802322C0
	b        lbl_802322C4

lbl_802322C0:
	li       r30, 0

lbl_802322C4:
	mr       r3, r30
	lwz      r12, 0(r30)
	lwz      r12, 0x68(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_802322F8
	lwz      r3, 4(r29)
	li       r4, 0x2834
	li       r5, 0x5a
	li       r6, 0
	lwz      r3, 0x250(r3)
	bl       startFreePikiSound__Q23PSM4PikiFUlUlUl

lbl_802322F8:
	lwz      r0, 0x24(r1)
	lwz      r31, 0x1c(r1)
	lwz      r30, 0x18(r1)
	lwz      r29, 0x14(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

} // namespace PikiAI
