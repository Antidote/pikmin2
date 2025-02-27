#include "Game/AILOD.h"
#include "Game/Creature.h"
#include "Game/GameSystem.h"
#include "Sys/Sphere.h"
#include "Sys/Cylinder.h"
#include "Viewport.h"
#include "nans.h"

namespace Game {

/*
 * --INFO--
 * Address:	801D7808
 * Size:	00001C
 */
AILODParm::AILODParm()
    : mFar(0.07f)
    , mClose(0.02f)
    , mIsCylinder(false)
{
}

/*
 * --INFO--
 * Address:	801D7824
 * Size:	000018
 */
AILOD::AILOD()
    : mFlags(AILOD_NULL)
    , mSndVpId(0)
{
	mFlags = AILOD_IsVisVP0;
}

/*
 * --INFO--
 * Address:	801D783C
 * Size:	0003A8
 */
void Creature::updateLOD(Game::AILODParm& parm)
{
	Sys::Sphere lodSphere;
	Sys::Cylinder lodCylinder;
	getLODSphere(lodSphere);
	if (parm.mIsCylinder) {
		getLODCylinder(lodCylinder);
	}
	mLod.mFlags = AILOD_NULL;
	int iStack[2];
	int* pi           = iStack;
	bool shouldCull   = true; // set to false if visible on any viewport
	int v11           = 2;
	Graphics* gfx     = sys->mGfx;
	int viewportCount = gfx->mViewportCount;
	for (int i = 0; i < viewportCount; i++) {
		Viewport* vp = gfx->getViewport(i);
		if (!vp->viewable()) {
			*pi = 2;
		} else {
			Camera* camera = vp->mCamera;
			if (parm.mIsCylinder) {
				if (camera->isCylinderVisible(lodCylinder)) {
					shouldCull = false;
					mLod.mFlags |= (AILOD_IsVisVP0 << i);
				}
			} else {
				if (camera->isVisible(lodSphere)) {
					shouldCull = false;
					mLod.mFlags |= (AILOD_IsVisVP0 << i);
				}
			}
			float screenSize = camera->calcScreenSize(lodSphere);
			if (screenSize > parm.mFar) {

				*pi = 0;
			} else {
				if (screenSize > parm.mClose) {
					*pi = 1;
				} else {
					*pi = 2;
				}
			}
			if (*pi < v11) {
				v11 = *pi;
			}
		}
		pi++;
	}

	if (!(gameSystem->isMultiplayerMode() && (2 <= viewportCount))) {
		mLod.mSndVpId = 0;
	} else {
		Viewport* vp0 = gfx->getViewport(0);
		Viewport* vp1 = gfx->getViewport(1);
		if (!vp0->viewable()) {
			mLod.mSndVpId = 1;
		} else {
			if (!vp1->viewable()) {
				mLod.mSndVpId = 0;
			} else {
				P2ASSERTLINE(175, vp0->mCamera);
				P2ASSERTLINE(176, vp1->mCamera);
				Vector3f pos0 = *vp0->mCamera->getSoundPositionPtr();
				Vector3f pos1 = *vp1->mCamera->getSoundPositionPtr();
				if (sqrDistance(pos1, lodSphere.mPosition) < sqrDistance(pos0, lodSphere.mPosition)) {
					mLod.mSndVpId = 0;
				} else {
					mLod.mSndVpId = 1;
				}
			}
		}
	}
	for (int i = 0; i < viewportCount; i++) {
		gfx->getViewport(i)->viewable();
	}
	mLod.mFlags |= (u8)v11;
	if (!shouldCull) {
		mLod.mFlags |= AILOD_IsVisible;
	} else {
		mLod.mFlags = AILOD_IsFar;
	}
	if (0 < getCellPikiCount()) {
		mLod.mFlags |= AILOD_PikiInCell;
	}
	/*
	stwu     r1, -0xa0(r1)
	mflr     r0
	stw      r0, 0xa4(r1)
	stfd     f31, 0x90(r1)
	psq_st   f31, 152(r1), 0, qr0
	stfd     f30, 0x80(r1)
	psq_st   f30, 136(r1), 0, qr0
	stfd     f29, 0x70(r1)
	psq_st   f29, 120(r1), 0, qr0
	stmw     r23, 0x4c(r1)
	lwz      r12, 0(r3)
	mr       r24, r4
	mr       r23, r3
	addi     r4, r1, 0x10
	lwz      r12, 0x140(r12)
	mtctr    r12
	bctrl
	lbz      r0, 8(r24)
	cmplwi   r0, 0
	beq      lbl_801D78A4
	mr       r3, r23
	addi     r4, r1, 0x20
	lwz      r12, 0(r23)
	lwz      r12, 0x144(r12)
	mtctr    r12
	bctrl

lbl_801D78A4:
	li       r0, 0
	addi     r28, r1, 8
	stb      r0, 0xd8(r23)
	li       r27, 1
	li       r26, 2
	li       r25, 0
	lwz      r3, sys@sda21(r13)
	lwz      r31, 0x24(r3)
	lwz      r30, 0x264(r31)
	b        lbl_801D79BC

lbl_801D78CC:
	mr       r3, r31
	mr       r4, r25
	bl       getViewport__8GraphicsFi
	mr       r29, r3
	bl       viewable__8ViewportFv
	clrlwi.  r0, r3, 0x18
	bne      lbl_801D78F4
	li       r0, 2
	stw      r0, 0(r28)
	b        lbl_801D79B4

lbl_801D78F4:
	lbz      r0, 8(r24)
	lwz      r29, 0x44(r29)
	cmplwi   r0, 0
	beq      lbl_801D7934
	mr       r3, r29
	addi     r4, r1, 0x20
	bl       isCylinderVisible__9CullPlaneFRQ23Sys8Cylinder
	clrlwi.  r0, r3, 0x18
	beq      lbl_801D7960
	li       r0, 0x10
	lbz      r3, 0xd8(r23)
	slw      r0, r0, r25
	li       r27, 0
	or       r0, r3, r0
	stb      r0, 0xd8(r23)
	b        lbl_801D7960

lbl_801D7934:
	mr       r3, r29
	addi     r4, r1, 0x10
	bl       isVisible__9CullPlaneFRQ23Sys6Sphere
	clrlwi.  r0, r3, 0x18
	beq      lbl_801D7960
	li       r0, 0x10
	lbz      r3, 0xd8(r23)
	slw      r0, r0, r25
	li       r27, 0
	or       r0, r3, r0
	stb      r0, 0xd8(r23)

lbl_801D7960:
	mr       r3, r29
	addi     r4, r1, 0x10
	bl       calcScreenSize__6CameraFRQ23Sys6Sphere
	lfs      f0, 0(r24)
	fcmpo    cr0, f1, f0
	ble      lbl_801D7984
	li       r0, 0
	stw      r0, 0(r28)
	b        lbl_801D79A4

lbl_801D7984:
	lfs      f0, 4(r24)
	fcmpo    cr0, f1, f0
	ble      lbl_801D799C
	li       r0, 1
	stw      r0, 0(r28)
	b        lbl_801D79A4

lbl_801D799C:
	li       r0, 2
	stw      r0, 0(r28)

lbl_801D79A4:
	lwz      r0, 0(r28)
	cmpw     r0, r26
	bge      lbl_801D79B4
	mr       r26, r0

lbl_801D79B4:
	addi     r28, r28, 4
	addi     r25, r25, 1

lbl_801D79BC:
	cmpw     r25, r30
	blt      lbl_801D78CC
	lwz      r4, gameSystem__4Game@sda21(r13)
	li       r3, 0
	lwz      r0, 0x44(r4)
	cmpwi    r0, 1
	beq      lbl_801D79E0
	cmpwi    r0, 3
	bne      lbl_801D79E4

lbl_801D79E0:
	li       r3, 1

lbl_801D79E4:
	clrlwi.  r0, r3, 0x18
	beq      lbl_801D79F4
	cmpwi    r30, 2
	bge      lbl_801D7A00

lbl_801D79F4:
	li       r0, 0
	stb      r0, 0xd9(r23)
	b        lbl_801D7B48

lbl_801D7A00:
	mr       r3, r31
	li       r4, 0
	bl       getViewport__8GraphicsFi
	mr       r0, r3
	mr       r3, r31
	mr       r25, r0
	li       r4, 1
	bl       getViewport__8GraphicsFi
	mr       r0, r3
	mr       r3, r25
	mr       r28, r0
	bl       viewable__8ViewportFv
	clrlwi.  r0, r3, 0x18
	bne      lbl_801D7A44
	li       r0, 1
	stb      r0, 0xd9(r23)
	b        lbl_801D7B48

lbl_801D7A44:
	mr       r3, r28
	bl       viewable__8ViewportFv
	clrlwi.  r0, r3, 0x18
	bne      lbl_801D7A60
	li       r0, 0
	stb      r0, 0xd9(r23)
	b        lbl_801D7B48

lbl_801D7A60:
	lwz      r0, 0x44(r25)
	cmplwi   r0, 0
	bne      lbl_801D7A88
	lis      r3, lbl_804807C8@ha
	lis      r5, lbl_804807D8@ha
	addi     r3, r3, lbl_804807C8@l
	li       r4, 0xaf
	addi     r5, r5, lbl_804807D8@l
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_801D7A88:
	lwz      r0, 0x44(r28)
	cmplwi   r0, 0
	bne      lbl_801D7AB0
	lis      r3, lbl_804807C8@ha
	lis      r5, lbl_804807D8@ha
	addi     r3, r3, lbl_804807C8@l
	li       r4, 0xb0
	addi     r5, r5, lbl_804807D8@l
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_801D7AB0:
	lwz      r3, 0x44(r25)
	lwz      r12, 0(r3)
	lwz      r12, 0x68(r12)
	mtctr    r12
	bctrl
	lfs      f31, 0(r3)
	lfs      f30, 4(r3)
	lfs      f29, 8(r3)
	lwz      r3, 0x44(r28)
	lwz      r12, 0(r3)
	lwz      r12, 0x68(r12)
	mtctr    r12
	bctrl
	lfs      f2, 0x14(r1)
	lfs      f1, 4(r3)
	fsubs    f0, f30, f2
	lfs      f6, 0x10(r1)
	fsubs    f7, f1, f2
	lfs      f3, 0(r3)
	lfs      f5, 0x18(r1)
	fsubs    f2, f31, f6
	fmuls    f1, f0, f0
	lfs      f4, 8(r3)
	fsubs    f6, f3, f6
	fmuls    f0, f7, f7
	fsubs    f3, f29, f5
	fmadds   f1, f2, f2, f1
	fsubs    f2, f4, f5
	fmadds   f0, f6, f6, f0
	fmadds   f1, f3, f3, f1
	fmadds   f0, f2, f2, f0
	fcmpo    cr0, f1, f0
	bge      lbl_801D7B40
	li       r0, 0
	stb      r0, 0xd9(r23)
	b        lbl_801D7B48

lbl_801D7B40:
	li       r0, 1
	stb      r0, 0xd9(r23)

lbl_801D7B48:
	li       r24, 0
	b        lbl_801D7B64

lbl_801D7B50:
	mr       r3, r31
	mr       r4, r24
	bl       getViewport__8GraphicsFi
	bl       viewable__8ViewportFv
	addi     r24, r24, 1

lbl_801D7B64:
	cmpw     r24, r30
	blt      lbl_801D7B50
	lbz      r4, 0xd8(r23)
	clrlwi   r3, r26, 0x18
	clrlwi.  r0, r27, 0x18
	or       r3, r4, r3
	stb      r3, 0xd8(r23)
	bne      lbl_801D7B94
	lbz      r0, 0xd8(r23)
	ori      r0, r0, 4
	stb      r0, 0xd8(r23)
	b        lbl_801D7B9C

lbl_801D7B94:
	li       r0, 2
	stb      r0, 0xd8(r23)

lbl_801D7B9C:
	mr       r3, r23
	bl       getCellPikiCount__Q24Game8CreatureFv
	cmpwi    r3, 0
	ble      lbl_801D7BB8
	lbz      r0, 0xd8(r23)
	ori      r0, r0, 8
	stb      r0, 0xd8(r23)

lbl_801D7BB8:
	psq_l    f31, 152(r1), 0, qr0
	lfd      f31, 0x90(r1)
	psq_l    f30, 136(r1), 0, qr0
	lfd      f30, 0x80(r1)
	psq_l    f29, 120(r1), 0, qr0
	lfd      f29, 0x70(r1)
	lmw      r23, 0x4c(r1)
	lwz      r0, 0xa4(r1)
	mtlr     r0
	addi     r1, r1, 0xa0
	blr
	*/
}

/*
 * --INFO--
 * Address:	801D7BE4
 * Size:	000258
 */
void Creature::drawLODInfo(Graphics& gfx, Vector3f& position)
{
	if (AILOD::drawInfo) {
		PerspPrintfInfo info;
		gfx.initPerspPrintf(gfx.mCurrentViewport);
		const char* nearnessLabels[] = { "near", "mid", "far" };

		u8 nearness = mLod.mFlags & (AILOD_IsMid | AILOD_IsFar);
		switch (nearness) {
		case AILOD_NULL:
			info.mColorA.set(0, 10, 255, 255);
			info.mColorB.set(200, 200, 200, 255);
			break;
		case AILOD_IsMid:
			info.mColorA.set(200, 200, 0, 255);
			info.mColorB.set(200, 200, 200, 255);
			break;
		case AILOD_IsFar:
			info.mColorA.set(255, 10, 0, 255);
			info.mColorB.set(200, 200, 200, 255);
			break;
		}
		const char* flag4Text = "_";
		if (mLod.mFlags & AILOD_IsVisible) {
			flag4Text = "p";
		}
		const char* vp1VisibilityText = "x";
		if (mLod.mFlags & AILOD_IsVisVP1) {
			vp1VisibilityText = "v";
		}
		const char* vp0VisibilityText = "x";
		if (mLod.mFlags & AILOD_IsVisVP0) {
			vp0VisibilityText = "v";
		}
		gfx.perspPrintf(info, position, "[%s%s %s %s]", vp0VisibilityText, vp1VisibilityText, flag4Text, nearnessLabels[nearness]);
		Camera* camera0 = sys->mGfx->getViewport(0)->mCamera;
		Vector3f sizeOnScreenTextPosition;
		sizeOnScreenTextPosition.x = position.x;
		sizeOnScreenTextPosition.y = position.y + 15.0f;
		sizeOnScreenTextPosition.z = position.z;
		Sys::Sphere lodSphere;
		getLODSphere(lodSphere);
		gfx.perspPrintf(info, sizeOnScreenTextPosition, "<%f>", camera0->calcScreenSize(lodSphere));
	}
	/*
	stwu     r1, -0x60(r1)
	mflr     r0
	stw      r0, 0x64(r1)
	stw      r31, 0x5c(r1)
	mr       r31, r5
	stw      r30, 0x58(r1)
	mr       r30, r4
	stw      r29, 0x54(r1)
	mr       r29, r3
	stw      r28, 0x50(r1)
	lbz      r0, drawInfo__Q24Game5AILOD@sda21(r13)
	cmplwi   r0, 0
	beq      lbl_801D7E1C
	lwz      r3, systemFont__9JFWSystem@sda21(r13)
	li       r6, 0
	li       r0, 0xff
	li       r5, 0x66
	lfs      f0, lbl_80519768@sda21(r2)
	li       r4, 0x99
	stw      r3, 0x30(r1)
	mr       r3, r30
	stw      r6, 0x34(r1)
	stw      r6, 0x38(r1)
	stw      r6, 0x3c(r1)
	stfs     f0, 0x40(r1)
	stb      r5, 0x44(r1)
	stb      r4, 0x45(r1)
	stb      r0, 0x46(r1)
	stb      r0, 0x47(r1)
	stb      r6, 0x48(r1)
	stb      r5, 0x49(r1)
	stb      r0, 0x4a(r1)
	stb      r0, 0x4b(r1)
	lwz      r4, 0x25c(r30)
	bl       initPerspPrintf__8GraphicsFP8Viewport
	lbz      r0, 0xd8(r29)
	lis      r3, lbl_804807E4@ha
	lwzu     r5, lbl_804807E4@l(r3)
	clrlwi   r0, r0, 0x1e
	lwz      r4, 4(r3)
	cmpwi    r0, 1
	lwz      r3, 8(r3)
	stw      r5, 0x24(r1)
	stw      r4, 0x28(r1)
	stw      r3, 0x2c(r1)
	beq      lbl_801D7CEC
	bge      lbl_801D7CAC
	cmpwi    r0, 0
	bge      lbl_801D7CB8
	b        lbl_801D7D4C

lbl_801D7CAC:
	cmpwi    r0, 3
	bge      lbl_801D7D4C
	b        lbl_801D7D1C

lbl_801D7CB8:
	li       r4, 0xff
	li       r3, 0xc8
	li       r6, 0
	li       r5, 0xa
	stb      r6, 0x44(r1)
	stb      r5, 0x45(r1)
	stb      r4, 0x46(r1)
	stb      r4, 0x47(r1)
	stb      r3, 0x48(r1)
	stb      r3, 0x49(r1)
	stb      r3, 0x4a(r1)
	stb      r4, 0x4b(r1)
	b        lbl_801D7D4C

lbl_801D7CEC:
	li       r5, 0xc8
	li       r3, 0xff
	li       r4, 0
	stb      r5, 0x44(r1)
	stb      r5, 0x45(r1)
	stb      r4, 0x46(r1)
	stb      r3, 0x47(r1)
	stb      r5, 0x48(r1)
	stb      r5, 0x49(r1)
	stb      r5, 0x4a(r1)
	stb      r3, 0x4b(r1)
	b        lbl_801D7D4C

lbl_801D7D1C:
	li       r6, 0xff
	li       r3, 0xc8
	li       r5, 0xa
	li       r4, 0
	stb      r6, 0x44(r1)
	stb      r5, 0x45(r1)
	stb      r4, 0x46(r1)
	stb      r6, 0x47(r1)
	stb      r3, 0x48(r1)
	stb      r3, 0x49(r1)
	stb      r3, 0x4a(r1)
	stb      r6, 0x4b(r1)

lbl_801D7D4C:
	lbz      r4, 0xd8(r29)
	addi     r9, r2, lbl_80519770@sda21
	rlwinm.  r3, r4, 0, 0x1c, 0x1c
	beq      lbl_801D7D60
	addi     r9, r2, lbl_8051976C@sda21

lbl_801D7D60:
	rlwinm.  r3, r4, 0, 0x1a, 0x1a
	addi     r8, r2, lbl_80519778@sda21
	beq      lbl_801D7D70
	addi     r8, r2, lbl_80519774@sda21

lbl_801D7D70:
	rlwinm.  r3, r4, 0, 0x1b, 0x1b
	lis      r4, lbl_804807F0@ha
	addi     r6, r4, lbl_804807F0@l
	mr       r5, r31
	mr       r3, r30
	addi     r4, r1, 0x30
	addi     r7, r2, lbl_80519778@sda21
	beq      lbl_801D7D94
	addi     r7, r2, lbl_80519774@sda21

lbl_801D7D94:
	slwi     r0, r0, 2
	addi     r10, r1, 0x24
	lwzx     r10, r10, r0
	crclr    6
	bl       "perspPrintf__8GraphicsFR15PerspPrintfInfoR10Vector3<f>Pce"
	lwz      r3, sys@sda21(r13)
	li       r4, 0
	lwz      r3, 0x24(r3)
	bl       getViewport__8GraphicsFi
	lwz      r28, 0x44(r3)
	mr       r3, r29
	lfs      f1, 0(r31)
	addi     r4, r1, 8
	lfs      f0, lbl_8051977C@sda21(r2)
	stfs     f1, 0x18(r1)
	lfs      f1, 4(r31)
	stfs     f1, 0x1c(r1)
	fadds    f0, f1, f0
	lfs      f1, 8(r31)
	stfs     f1, 0x20(r1)
	stfs     f0, 0x1c(r1)
	lwz      r12, 0(r29)
	lwz      r12, 0x140(r12)
	mtctr    r12
	bctrl
	mr       r3, r28
	addi     r4, r1, 8
	bl       calcScreenSize__6CameraFRQ23Sys6Sphere
	mr       r3, r30
	addi     r4, r1, 0x30
	addi     r5, r1, 0x18
	addi     r6, r2, lbl_80519780@sda21
	crset    6
	bl       "perspPrintf__8GraphicsFR15PerspPrintfInfoR10Vector3<f>Pce"

lbl_801D7E1C:
	lwz      r0, 0x64(r1)
	lwz      r31, 0x5c(r1)
	lwz      r30, 0x58(r1)
	lwz      r29, 0x54(r1)
	lwz      r28, 0x50(r1)
	mtlr     r0
	addi     r1, r1, 0x60
	blr
	*/
}

} // namespace Game
