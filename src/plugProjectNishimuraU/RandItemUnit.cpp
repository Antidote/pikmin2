#include "types.h"

/*
    Generated from dpostproc

    .section .rodata  # 0x804732E0 - 0x8049E220
    .global lbl_80484128
    lbl_80484128:
        .4byte 0x3234362D
        .4byte 0x52616E64
        .4byte 0x4974656D
        .4byte 0x556E6974
        .4byte 0x00000000
    .global lbl_8048413C
    lbl_8048413C:
        .4byte 0x52616E64
        .4byte 0x4974656D
        .4byte 0x556E6974
        .4byte 0x2E637070
        .4byte 0x00000000
        .4byte 0x6974656D
        .4byte 0x20736C6F
        .4byte 0x74206E6F
        .4byte 0x6E650A00
        .4byte 0x6974656D
        .4byte 0x20736C6F
        .4byte 0x74206E6F
        .4byte 0x7420656E
        .4byte 0x6F756768
        .4byte 0x0A000000
    .global lbl_80484178
    lbl_80484178:
        .4byte 0x6E6F7420
        .4byte 0x73656172
        .4byte 0x63682069
        .4byte 0x74656D20
        .4byte 0x736C6F74
        .4byte 0x0A000000

    .section .sdata2, "a"     # 0x80516360 - 0x80520E40
    .global lbl_8051A840
    lbl_8051A840:
        .float 1.0
        .4byte 0x00000000
    .global lbl_8051A848
    lbl_8051A848:
        .4byte 0x43300000
        .4byte 0x80000000
    .global lbl_8051A850
    lbl_8051A850:
        .4byte 0x6974656D
        .4byte 0x00000000
    .global lbl_8051A858
    lbl_8051A858:
        .4byte 0x47000000
    .global lbl_8051A85C
    lbl_8051A85C:
        .float 0.5
    .global lbl_8051A860
    lbl_8051A860:
        .4byte 0x43C80000
    .global lbl_8051A864
    lbl_8051A864:
        .4byte 0x00000000
*/

namespace Game {

/*
 * --INFO--
 * Address:	8024E38C
 * Size:	000064
 */
Cave::RandItemUnit::RandItemUnit(Game::Cave::MapUnitGenerator*)
{
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	li       r0, 0
	stw      r31, 0xc(r1)
	mr       r31, r3
	stw      r4, 8(r3)
	stw      r0, 0(r3)
	lwz      r3, 8(r3)
	lwz      r3, 8(r3)
	cmplwi   r3, 0
	beq      lbl_8024E3C8
	bl       getItemMax__Q34Game4Cave9FloorInfoFv
	stw      r3, 4(r31)
	b        lbl_8024E3CC

lbl_8024E3C8:
	stw      r0, 4(r31)

lbl_8024E3CC:
	li       r0, 0
	mr       r3, r31
	stw      r0, 0x10(r31)
	stw      r0, 0x14(r31)
	lwz      r31, 0xc(r1)
	lwz      r0, 0x14(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	8024E3F0
 * Size:	000008
 */
void Cave::RandItemUnit::setManageClassPtr(Game::Cave::RandMapScore* a1)
{
	// Generated from stw r4, 0xC(r3)
	_0C = a1;
}

/*
 * --INFO--
 * Address:	8024E3F8
 * Size:	000104
 */
void Cave::RandItemUnit::setItemSlot()
{
	/*
	stwu     r1, -0x30(r1)
	mflr     r0
	stw      r0, 0x34(r1)
	stmw     r27, 0x1c(r1)
	mr       r31, r3
	lwz      r3, 0(r3)
	lwz      r0, 4(r31)
	cmpw     r3, r0
	bge      lbl_8024E4E8
	li       r29, 0

lbl_8024E420:
	li       r0, 0
	mr       r3, r31
	stw      r0, 8(r1)
	bl       isItemSetHard__Q34Game4Cave12RandItemUnitFv
	clrlwi.  r0, r3, 0x18
	beq      lbl_8024E44C
	mr       r3, r31
	addi     r4, r1, 8
	bl getItemHardSetMapNode__Q34Game4Cave12RandItemUnitFPPQ34Game4Cave7BaseGen
	mr       r30, r3
	b        lbl_8024E45C

lbl_8024E44C:
	mr       r3, r31
	addi     r4, r1, 8
	bl
getItemNormalSetMapNode__Q34Game4Cave12RandItemUnitFPPQ34Game4Cave7BaseGen mr
r30, r3

lbl_8024E45C:
	mr       r28, r30
	mr       r3, r31
	bl       getItemUnit__Q34Game4Cave12RandItemUnitFv
	cmplwi   r30, 0
	mr       r27, r3
	beq      lbl_8024E4E8
	cmplwi   r27, 0
	beq      lbl_8024E4E8
	li       r3, 0x34
	bl       __nw__FUl
	or.      r30, r3, r3
	beq      lbl_8024E4A0
	lwz      r5, 8(r1)
	mr       r4, r27
	li       r6, 1
	bl __ct__Q34Game4Cave8ItemNodeFPQ34Game4Cave8ItemUnitPQ34Game4Cave7BaseGeni
	mr       r30, r3

lbl_8024E4A0:
	mr       r3, r30
	mr       r4, r28
	bl       makeGlobalData__Q34Game4Cave8ItemNodeFPQ34Game4Cave7MapNode
	lwz      r3, 0x24(r28)
	mr       r4, r30
	bl       add__5CNodeFP5CNode
	lwz      r3, 0(r31)
	addi     r0, r3, 1
	stw      r0, 0(r31)
	lwz      r3, 0(r31)
	lwz      r0, 4(r31)
	cmpw     r3, r0
	blt      lbl_8024E4DC
	b        lbl_8024E4E8
	b        lbl_8024E4E8

lbl_8024E4DC:
	addi     r29, r29, 1
	cmpwi    r29, 0x64
	blt      lbl_8024E420

lbl_8024E4E8:
	lmw      r27, 0x1c(r1)
	lwz      r0, 0x34(r1)
	mtlr     r0
	addi     r1, r1, 0x30
	blr
	*/
}

/*
 * --INFO--
 * Address:	8024E4FC
 * Size:	000110
 */
void Cave::RandItemUnit::isItemSetDone(Game::Cave::MapNode*, Game::Cave::BaseGen*)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x10(r1)
	  mflr      r0
	  cmplwi    r5, 0
	  stw       r0, 0x14(r1)
	  stw       r31, 0xC(r1)
	  mr        r31, r4
	  stw       r30, 0x8(r1)
	  mr        r30, r3
	  beq-      .loc_0x54
	  lwz       r3, 0x24(r31)
	  lwz       r3, 0x10(r3)
	  b         .loc_0x48

	.loc_0x30:
	  lwz       r0, 0x1C(r3)
	  cmplw     r0, r5
	  bne-      .loc_0x44
	  li        r3, 0x1
	  b         .loc_0xF8

	.loc_0x44:
	  lwz       r3, 0x4(r3)

	.loc_0x48:
	  cmplwi    r3, 0
	  bne+      .loc_0x30
	  b         .loc_0xF4

	.loc_0x54:
	  lwz       r3, 0xC(r30)
	  li        r4, 0x1
	  bl        -0x19B0
	  cmplw     r31, r3
	  bne-      .loc_0x70
	  li        r3, 0x1
	  b         .loc_0xF8

	.loc_0x70:
	  lwz       r3, 0xC(r30)
	  li        r4, 0x2
	  bl        -0x19CC
	  cmplw     r31, r3
	  bne-      .loc_0x8C
	  li        r3, 0x1
	  b         .loc_0xF8

	.loc_0x8C:
	  lwz       r3, 0x24(r31)
	  lwz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xA4
	  li        r3, 0x1
	  b         .loc_0xF8

	.loc_0xA4:
	  lwz       r3, 0x1C(r31)
	  lwz       r4, 0x10(r3)
	  b         .loc_0xEC

	.loc_0xB0:
	  lwz       r3, 0x18(r4)
	  lwz       r3, 0x0(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0xE8
	  lbz       r0, 0x24(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xE8
	  lwz       r0, 0x20(r3)
	  cmpwi     r0, 0x5
	  beq-      .loc_0xE8
	  cmpwi     r0, 0x6
	  beq-      .loc_0xE8
	  li        r3, 0x1
	  b         .loc_0xF8

	.loc_0xE8:
	  lwz       r4, 0x4(r4)

	.loc_0xEC:
	  cmplwi    r4, 0
	  bne+      .loc_0xB0

	.loc_0xF4:
	  li        r3, 0

	.loc_0xF8:
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  lwz       r30, 0x8(r1)
	  mtlr      r0
	  addi      r1, r1, 0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8024E60C
 * Size:	0000E8
 */
void Cave::RandItemUnit::isGroundCapEnemySetDone(Game::Cave::MapNode*)
{
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	mr       r31, r4
	li       r4, 1
	stw      r30, 8(r1)
	mr       r30, r3
	lwz      r3, 0xc(r3)
	bl       getFixObjNode__Q34Game4Cave12RandMapScoreFi
	cmplw    r31, r3
	bne      lbl_8024E644
	li       r3, 1
	b        lbl_8024E6DC

lbl_8024E644:
	lwz      r3, 0xc(r30)
	li       r4, 2
	bl       getFixObjNode__Q34Game4Cave12RandMapScoreFi
	cmplw    r31, r3
	bne      lbl_8024E660
	li       r3, 1
	b        lbl_8024E6DC

lbl_8024E660:
	lwz      r3, 0x24(r31)
	lwz      r0, 0x10(r3)
	cmplwi   r0, 0
	beq      lbl_8024E678
	li       r3, 1
	b        lbl_8024E6DC

lbl_8024E678:
	lwz      r3, 0x1c(r31)
	lwz      r31, 0x10(r3)
	b        lbl_8024E6D0

lbl_8024E684:
	lwz      r3, 0x18(r31)
	lwz      r4, 0(r3)
	cmplwi   r4, 0
	beq      lbl_8024E6CC
	lwz      r0, 0x20(r4)
	cmpwi    r0, 5
	beq      lbl_8024E6CC
	cmpwi    r0, 6
	beq      lbl_8024E6CC
	lbz      r0, 0x24(r4)
	cmplwi   r0, 0
	beq      lbl_8024E6C4
	lwz      r3, 8(r30)
	bl       isPomGroup__Q34Game4Cave16MapUnitGeneratorFPQ34Game4Cave8TekiInfo
	clrlwi.  r0, r3, 0x18
	beq      lbl_8024E6CC

lbl_8024E6C4:
	li       r3, 1
	b        lbl_8024E6DC

lbl_8024E6CC:
	lwz      r31, 4(r31)

lbl_8024E6D0:
	cmplwi   r31, 0
	bne      lbl_8024E684
	li       r3, 0

lbl_8024E6DC:
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
 * Address:	8024E6F4
 * Size:	0000D0
 */
void Cave::RandItemUnit::isFallCapEnemySetDone(Game::Cave::MapNode*)
{
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	mr       r31, r4
	li       r4, 1
	stw      r30, 8(r1)
	mr       r30, r3
	lwz      r3, 0xc(r3)
	bl       getFixObjNode__Q34Game4Cave12RandMapScoreFi
	cmplw    r31, r3
	bne      lbl_8024E72C
	li       r3, 1
	b        lbl_8024E7AC

lbl_8024E72C:
	lwz      r3, 0xc(r30)
	li       r4, 2
	bl       getFixObjNode__Q34Game4Cave12RandMapScoreFi
	cmplw    r31, r3
	bne      lbl_8024E748
	li       r3, 1
	b        lbl_8024E7AC

lbl_8024E748:
	lwz      r3, 0x1c(r31)
	lwz      r31, 0x10(r3)
	b        lbl_8024E7A0

lbl_8024E754:
	lwz      r3, 0x18(r31)
	lwz      r4, 0(r3)
	cmplwi   r4, 0
	beq      lbl_8024E79C
	lwz      r0, 0x20(r4)
	cmpwi    r0, 5
	beq      lbl_8024E79C
	cmpwi    r0, 6
	beq      lbl_8024E79C
	lbz      r0, 0x24(r4)
	cmplwi   r0, 0
	bne      lbl_8024E794
	lwz      r3, 8(r30)
	bl       isPomGroup__Q34Game4Cave16MapUnitGeneratorFPQ34Game4Cave8TekiInfo
	clrlwi.  r0, r3, 0x18
	beq      lbl_8024E79C

lbl_8024E794:
	li       r3, 1
	b        lbl_8024E7AC

lbl_8024E79C:
	lwz      r31, 4(r31)

lbl_8024E7A0:
	cmplwi   r31, 0
	bne      lbl_8024E754
	li       r3, 0

lbl_8024E7AC:
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
 * Address:	8024E7C4
 * Size:	00000C
 */
void Cave::RandItemUnit::setItemDropPositionList(Game::Cave::MapNode**, Game::Cave::BaseGen**)
{
	/*
	.loc_0x0:
	  stw       r4, 0x10(r3)
	  stw       r5, 0x14(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8024E7D0
 * Size:	000228
 */
void Cave::RandItemUnit::getItemDropPosition(Vector3f&, float, int)
{
	/*
	stwu     r1, -0x890(r1)
	mflr     r0
	stw      r0, 0x894(r1)
	stfd     f31, 0x880(r1)
	psq_st   f31, -1912(r1), 0, qr0
	stfd     f30, 0x870(r1)
	psq_st   f30, -1928(r1), 0, qr0
	stmw     r24, 0x850(r1)
	mr       r29, r3
	lis      r7, lbl_80484128@ha
	lwz      r6, 8(r3)
	fmr      f30, f1
	lwz      r3, 0xc(r3)
	mr       r30, r4
	lwz      r4, 0x28(r6)
	mr       r31, r5
	lwz      r0, 0x2c(r6)
	stw      r4, 0x14(r1)
	addi     r28, r7, lbl_80484128@l
	stw      r0, 0x18(r1)
	bl       getVersusHighScore__Q34Game4Cave12RandMapScoreFv
	xoris    r3, r3, 0x8000
	lis      r0, 0x4330
	stw      r3, 0x83c(r1)
	lfs      f0, lbl_8051A840@sda21(r2)
	stw      r0, 0x838(r1)
	lfd      f2, lbl_8051A848@sda21(r2)
	fsubs    f0, f0, f30
	lfd      f1, 0x838(r1)
	lwz      r3, 0xc(r29)
	fsubs    f1, f1, f2
	fmuls    f31, f0, f1
	bl       getVersusLowScore__Q34Game4Cave12RandMapScoreFv
	xoris    r3, r3, 0x8000
	lis      r0, 0x4330
	stw      r3, 0x844(r1)
	cmpwi    r31, 0
	lfd      f1, lbl_8051A848@sda21(r2)
	stw      r0, 0x840(r1)
	lfd      f0, 0x840(r1)
	fsubs    f0, f0, f1
	fmadds   f0, f30, f0, f31
	fctiwz   f0, f0
	stfd     f0, 0x848(r1)
	lwz      r26, 0x84c(r1)
	bge      lbl_8024E92C
	lis      r3, 0x00138800@ha
	addi     r31, r1, 0x14
	addi     r0, r3, 0x00138800@l
	li       r27, 0
	stw      r0, 0xc(r1)

lbl_8024E89C:
	lwz      r3, 0(r31)
	lwz      r25, 0x10(r3)
	b        lbl_8024E8C4

lbl_8024E8A8:
	mr       r3, r29
	mr       r4, r25
	mr       r6, r26
	addi     r5, r1, 0x10
	addi     r7, r1, 0xc
	bl
getItemDropMapNode__Q34Game4Cave12RandItemUnitFPQ34Game4Cave7MapNodePPQ34Game4Cave7MapNodeiRi
	lwz      r25, 4(r25)

lbl_8024E8C4:
	cmplwi   r25, 0
	bne      lbl_8024E8A8
	addi     r27, r27, 1
	addi     r31, r31, 4
	cmpwi    r27, 2
	blt      lbl_8024E89C
	lwz      r5, 0x10(r1)
	cmplwi   r5, 0
	beq      lbl_8024E914
	mr       r4, r29
	mr       r6, r26
	addi     r3, r1, 0x28
	bl getItemBaseGenPosition__Q34Game4Cave12RandItemUnitFPQ34Game4Cave7MapNodei
	lfs      f0, 0x28(r1)
	stfs     f0, 0(r30)
	lfs      f0, 0x2c(r1)
	stfs     f0, 4(r30)
	lfs      f0, 0x30(r1)
	stfs     f0, 8(r30)
	b        lbl_8024E9D4

lbl_8024E914:
	addi     r3, r28, 0x14
	addi     r5, r28, 0x28
	li       r4, 0x177
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce
	b        lbl_8024E9D4

lbl_8024E92C:
	li       r0, 0
	addi     r27, r1, 0x14
	stw      r0, 8(r1)
	li       r25, 0

lbl_8024E93C:
	lwz      r3, 0(r27)
	lwz      r24, 0x10(r3)
	b        lbl_8024E964

lbl_8024E948:
	mr       r3, r29
	mr       r4, r24
	addi     r5, r1, 0x434
	addi     r6, r1, 0x34
	addi     r7, r1, 8
	bl
getItemDropList__Q34Game4Cave12RandItemUnitFPQ34Game4Cave7MapNodePPQ34Game4Cave7MapNodePPQ34Game4Cave7BaseGenRi
	lwz      r24, 4(r24)

lbl_8024E964:
	cmplwi   r24, 0
	bne      lbl_8024E948
	addi     r25, r25, 1
	addi     r27, r27, 4
	cmpwi    r25, 2
	blt      lbl_8024E93C
	lwz      r7, 8(r1)
	cmpw     r31, r7
	bge      lbl_8024E9C0
	mr       r4, r29
	mr       r8, r26
	mr       r9, r31
	addi     r3, r1, 0x1c
	addi     r5, r1, 0x434
	addi     r6, r1, 0x34
	bl
getItemBaseGenPosition__Q34Game4Cave12RandItemUnitFPPQ34Game4Cave7MapNodePPQ34Game4Cave7BaseGeniii
	lfs      f0, 0x1c(r1)
	stfs     f0, 0(r30)
	lfs      f0, 0x20(r1)
	stfs     f0, 4(r30)
	lfs      f0, 0x24(r1)
	stfs     f0, 8(r30)
	b        lbl_8024E9D4

lbl_8024E9C0:
	addi     r3, r28, 0x14
	addi     r5, r28, 0x38
	li       r4, 0x18e
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8024E9D4:
	psq_l    f31, -1912(r1), 0, qr0
	lfd      f31, 0x880(r1)
	psq_l    f30, -1928(r1), 0, qr0
	lfd      f30, 0x870(r1)
	lmw      r24, 0x850(r1)
	lwz      r0, 0x894(r1)
	mtlr     r0
	addi     r1, r1, 0x890
	blr
	*/
}

/*
 * --INFO--
 * Address:	8024E9F8
 * Size:	00038C
 */
void Cave::RandItemUnit::getItemNormalSetMapNode(Game::Cave::BaseGen**)
{
	/*
	stwu     r1, -0x1850(r1)
	mflr     r0
	stw      r0, 0x1854(r1)
	stmw     r21, 0x1824(r1)
	mr       r22, r3
	mr       r23, r4
	li       r27, 0
	li       r21, 0
	li       r26, 0
	lwz      r3, 8(r3)
	lwz      r3, 0x28(r3)
	lwz      r25, 0x10(r3)
	b        lbl_8024ECC0

lbl_8024EA2C:
	lwz      r3, 0x18(r25)
	bl       getUnitKind__Q34Game4Cave8UnitInfoFv
	cmpwi    r3, 1
	bne      lbl_8024EBB8
	mr       r3, r22
	mr       r4, r25
	bl       getItemSlotNum__Q34Game4Cave12RandItemUnitFPQ34Game4Cave7MapNode
	or.      r31, r3, r3
	beq      lbl_8024ECBC
	lwz      r3, 0x18(r25)
	bl       getBaseGen__Q34Game4Cave8UnitInfoFv
	cmplwi   r3, 0
	beq      lbl_8024ECBC
	addi     r30, r1, 0x1008
	addi     r29, r1, 0x808
	addi     r28, r1, 8
	lwz      r24, 0x10(r3)
	add      r30, r30, r21
	add      r29, r29, r21
	add      r28, r28, r21
	b        lbl_8024EBAC

lbl_8024EA80:
	lwz      r0, 0x18(r24)
	cmpwi    r0, 2
	bne      lbl_8024EBA8
	cmplwi   r24, 0
	beq      lbl_8024EAC4
	lwz      r3, 0x24(r25)
	lwz      r3, 0x10(r3)
	b        lbl_8024EAB8

lbl_8024EAA0:
	lwz      r0, 0x1c(r3)
	cmplw    r0, r24
	bne      lbl_8024EAB4
	li       r0, 1
	b        lbl_8024EB68

lbl_8024EAB4:
	lwz      r3, 4(r3)

lbl_8024EAB8:
	cmplwi   r3, 0
	bne      lbl_8024EAA0
	b        lbl_8024EB64

lbl_8024EAC4:
	lwz      r3, 0xc(r22)
	li       r4, 1
	bl       getFixObjNode__Q34Game4Cave12RandMapScoreFi
	cmplw    r25, r3
	bne      lbl_8024EAE0
	li       r0, 1
	b        lbl_8024EB68

lbl_8024EAE0:
	lwz      r3, 0xc(r22)
	li       r4, 2
	bl       getFixObjNode__Q34Game4Cave12RandMapScoreFi
	cmplw    r25, r3
	bne      lbl_8024EAFC
	li       r0, 1
	b        lbl_8024EB68

lbl_8024EAFC:
	lwz      r3, 0x24(r25)
	lwz      r0, 0x10(r3)
	cmplwi   r0, 0
	beq      lbl_8024EB14
	li       r0, 1
	b        lbl_8024EB68

lbl_8024EB14:
	lwz      r3, 0x1c(r25)
	lwz      r4, 0x10(r3)
	b        lbl_8024EB5C

lbl_8024EB20:
	lwz      r3, 0x18(r4)
	lwz      r3, 0(r3)
	cmplwi   r3, 0
	beq      lbl_8024EB58
	lbz      r0, 0x24(r3)
	cmplwi   r0, 0
	bne      lbl_8024EB58
	lwz      r0, 0x20(r3)
	cmpwi    r0, 5
	beq      lbl_8024EB58
	cmpwi    r0, 6
	beq      lbl_8024EB58
	li       r0, 1
	b        lbl_8024EB68

lbl_8024EB58:
	lwz      r4, 4(r4)

lbl_8024EB5C:
	cmplwi   r4, 0
	bne      lbl_8024EB20

lbl_8024EB64:
	li       r0, 0

lbl_8024EB68:
	clrlwi.  r0, r0, 0x18
	bne      lbl_8024EBA8
	stw      r25, 0(r30)
	mr       r3, r25
	stw      r24, 0(r29)
	bl       getNodeScore__Q34Game4Cave7MapNodeFv
	divw     r3, r3, r31
	addi     r30, r30, 4
	addi     r29, r29, 4
	addi     r27, r27, 1
	addi     r21, r21, 4
	addi     r0, r3, 1
	stw      r0, 0(r28)
	lwz      r0, 0(r28)
	addi     r28, r28, 4
	add      r26, r26, r0

lbl_8024EBA8:
	lwz      r24, 4(r24)

lbl_8024EBAC:
	cmplwi   r24, 0
	bne      lbl_8024EA80
	b        lbl_8024ECBC

lbl_8024EBB8:
	mr       r3, r25
	bl       getUnitName__Q34Game4Cave7MapNodeFv
	addi     r4, r2, lbl_8051A850@sda21
	li       r5, 4
	bl       strncmp
	cmpwi    r3, 0
	bne      lbl_8024ECBC
	lwz      r3, 0xc(r22)
	li       r4, 1
	bl       getFixObjNode__Q34Game4Cave12RandMapScoreFi
	cmplw    r25, r3
	bne      lbl_8024EBF0
	li       r0, 1
	b        lbl_8024EC78

lbl_8024EBF0:
	lwz      r3, 0xc(r22)
	li       r4, 2
	bl       getFixObjNode__Q34Game4Cave12RandMapScoreFi
	cmplw    r25, r3
	bne      lbl_8024EC0C
	li       r0, 1
	b        lbl_8024EC78

lbl_8024EC0C:
	lwz      r3, 0x24(r25)
	lwz      r0, 0x10(r3)
	cmplwi   r0, 0
	beq      lbl_8024EC24
	li       r0, 1
	b        lbl_8024EC78

lbl_8024EC24:
	lwz      r3, 0x1c(r25)
	lwz      r4, 0x10(r3)
	b        lbl_8024EC6C

lbl_8024EC30:
	lwz      r3, 0x18(r4)
	lwz      r3, 0(r3)
	cmplwi   r3, 0
	beq      lbl_8024EC68
	lbz      r0, 0x24(r3)
	cmplwi   r0, 0
	bne      lbl_8024EC68
	lwz      r0, 0x20(r3)
	cmpwi    r0, 5
	beq      lbl_8024EC68
	cmpwi    r0, 6
	beq      lbl_8024EC68
	li       r0, 1
	b        lbl_8024EC78

lbl_8024EC68:
	lwz      r4, 4(r4)

lbl_8024EC6C:
	cmplwi   r4, 0
	bne      lbl_8024EC30
	li       r0, 0

lbl_8024EC78:
	clrlwi.  r0, r0, 0x18
	bne      lbl_8024ECBC
	addi     r3, r1, 0x1008
	addi     r4, r1, 0x808
	li       r0, 0
	stwx     r25, r3, r21
	mr       r3, r25
	stwx     r0, r4, r21
	bl       getNodeScore__Q34Game4Cave7MapNodeFv
	mulli    r3, r3, 0xa
	addi     r4, r1, 8
	addi     r27, r27, 1
	addi     r0, r3, 1
	stwx     r0, r4, r21
	lwzx     r0, r4, r21
	addi     r21, r21, 4
	add      r26, r26, r0

lbl_8024ECBC:
	lwz      r25, 4(r25)

lbl_8024ECC0:
	cmplwi   r25, 0
	bne      lbl_8024EA2C
	cmpwi    r26, 0
	beq      lbl_8024ED6C
	bl       rand
	lis      r4, 0x4330
	xoris    r0, r3, 0x8000
	stw      r0, 0x180c(r1)
	xoris    r0, r26, 0x8000
	lfd      f2, lbl_8051A848@sda21(r2)
	addi     r5, r1, 8
	stw      r4, 0x1808(r1)
	li       r6, 0
	lfs      f0, lbl_8051A858@sda21(r2)
	li       r7, 0
	lfd      f1, 0x1808(r1)
	stw      r0, 0x1814(r1)
	fsubs    f1, f1, f2
	stw      r4, 0x1810(r1)
	fdivs    f1, f1, f0
	lfd      f0, 0x1810(r1)
	fsubs    f0, f0, f2
	fmuls    f0, f0, f1
	fctiwz   f0, f0
	stfd     f0, 0x1818(r1)
	lwz      r3, 0x181c(r1)
	mtctr    r27
	cmpwi    r27, 0
	ble      lbl_8024ED6C

lbl_8024ED34:
	lwz      r0, 0(r5)
	add      r6, r6, r0
	cmpw     r6, r3
	ble      lbl_8024ED60
	slwi     r4, r7, 2
	addi     r3, r1, 0x808
	lwzx     r0, r3, r4
	addi     r3, r1, 0x1008
	lwzx     r3, r3, r4
	stw      r0, 0(r23)
	b        lbl_8024ED70

lbl_8024ED60:
	addi     r5, r5, 4
	addi     r7, r7, 1
	bdnz     lbl_8024ED34

lbl_8024ED6C:
	li       r3, 0

lbl_8024ED70:
	lmw      r21, 0x1824(r1)
	lwz      r0, 0x1854(r1)
	mtlr     r0
	addi     r1, r1, 0x1850
	blr
	*/
}

/*
 * --INFO--
 * Address:	8024ED84
 * Size:	000340
 */
void Cave::RandItemUnit::getItemHardSetMapNode(Game::Cave::BaseGen**)
{
	/*
	stwu     r1, -0x1040(r1)
	mflr     r0
	stw      r0, 0x1044(r1)
	stmw     r25, 0x1024(r1)
	mr       r25, r3
	mr       r26, r4
	li       r31, 0
	li       r30, -1
	lwz      r3, 8(r3)
	lwz      r3, 0x28(r3)
	lwz      r29, 0x10(r3)
	b        lbl_8024F034

lbl_8024EDB4:
	lwz      r3, 0x18(r29)
	bl       getUnitKind__Q34Game4Cave8UnitInfoFv
	cmpwi    r3, 1
	bne      lbl_8024EF2C
	lwz      r3, 0x24(r29)
	lwz      r12, 0(r3)
	lwz      r12, 0xc(r12)
	mtctr    r12
	bctrl
	addi     r27, r3, 1
	mr       r3, r29
	bl       getNodeScore__Q34Game4Cave7MapNodeFv
	divw     r28, r3, r27
	lwz      r3, 0x18(r29)
	bl       getBaseGen__Q34Game4Cave8UnitInfoFv
	cmplwi   r3, 0
	beq      lbl_8024F030
	lwz      r27, 0x10(r3)
	b        lbl_8024EF20

lbl_8024EE00:
	lwz      r0, 0x18(r27)
	cmpwi    r0, 2
	bne      lbl_8024EF1C
	cmplwi   r27, 0
	beq      lbl_8024EE44
	lwz      r3, 0x24(r29)
	lwz      r3, 0x10(r3)
	b        lbl_8024EE38

lbl_8024EE20:
	lwz      r0, 0x1c(r3)
	cmplw    r0, r27
	bne      lbl_8024EE34
	li       r0, 1
	b        lbl_8024EEE8

lbl_8024EE34:
	lwz      r3, 4(r3)

lbl_8024EE38:
	cmplwi   r3, 0
	bne      lbl_8024EE20
	b        lbl_8024EEE4

lbl_8024EE44:
	lwz      r3, 0xc(r25)
	li       r4, 1
	bl       getFixObjNode__Q34Game4Cave12RandMapScoreFi
	cmplw    r29, r3
	bne      lbl_8024EE60
	li       r0, 1
	b        lbl_8024EEE8

lbl_8024EE60:
	lwz      r3, 0xc(r25)
	li       r4, 2
	bl       getFixObjNode__Q34Game4Cave12RandMapScoreFi
	cmplw    r29, r3
	bne      lbl_8024EE7C
	li       r0, 1
	b        lbl_8024EEE8

lbl_8024EE7C:
	lwz      r3, 0x24(r29)
	lwz      r0, 0x10(r3)
	cmplwi   r0, 0
	beq      lbl_8024EE94
	li       r0, 1
	b        lbl_8024EEE8

lbl_8024EE94:
	lwz      r3, 0x1c(r29)
	lwz      r4, 0x10(r3)
	b        lbl_8024EEDC

lbl_8024EEA0:
	lwz      r3, 0x18(r4)
	lwz      r3, 0(r3)
	cmplwi   r3, 0
	beq      lbl_8024EED8
	lbz      r0, 0x24(r3)
	cmplwi   r0, 0
	bne      lbl_8024EED8
	lwz      r0, 0x20(r3)
	cmpwi    r0, 5
	beq      lbl_8024EED8
	cmpwi    r0, 6
	beq      lbl_8024EED8
	li       r0, 1
	b        lbl_8024EEE8

lbl_8024EED8:
	lwz      r4, 4(r4)

lbl_8024EEDC:
	cmplwi   r4, 0
	bne      lbl_8024EEA0

lbl_8024EEE4:
	li       r0, 0

lbl_8024EEE8:
	clrlwi.  r0, r0, 0x18
	bne      lbl_8024EF1C
	cmpw     r28, r30
	blt      lbl_8024EF1C
	ble      lbl_8024EF04
	li       r31, 0
	mr       r30, r28

lbl_8024EF04:
	slwi     r0, r31, 2
	addi     r4, r1, 0x808
	addi     r3, r1, 8
	stwx     r29, r4, r0
	addi     r31, r31, 1
	stwx     r27, r3, r0

lbl_8024EF1C:
	lwz      r27, 4(r27)

lbl_8024EF20:
	cmplwi   r27, 0
	bne      lbl_8024EE00
	b        lbl_8024F030

lbl_8024EF2C:
	mr       r3, r29
	bl       getUnitName__Q34Game4Cave7MapNodeFv
	addi     r4, r2, lbl_8051A850@sda21
	li       r5, 4
	bl       strncmp
	cmpwi    r3, 0
	bne      lbl_8024F030
	mr       r3, r29
	bl       getNodeScore__Q34Game4Cave7MapNodeFv
	addi     r27, r3, 1
	lwz      r3, 0xc(r25)
	li       r4, 1
	bl       getFixObjNode__Q34Game4Cave12RandMapScoreFi
	cmplw    r29, r3
	bne      lbl_8024EF70
	li       r0, 1
	b        lbl_8024EFF8

lbl_8024EF70:
	lwz      r3, 0xc(r25)
	li       r4, 2
	bl       getFixObjNode__Q34Game4Cave12RandMapScoreFi
	cmplw    r29, r3
	bne      lbl_8024EF8C
	li       r0, 1
	b        lbl_8024EFF8

lbl_8024EF8C:
	lwz      r3, 0x24(r29)
	lwz      r0, 0x10(r3)
	cmplwi   r0, 0
	beq      lbl_8024EFA4
	li       r0, 1
	b        lbl_8024EFF8

lbl_8024EFA4:
	lwz      r3, 0x1c(r29)
	lwz      r4, 0x10(r3)
	b        lbl_8024EFEC

lbl_8024EFB0:
	lwz      r3, 0x18(r4)
	lwz      r3, 0(r3)
	cmplwi   r3, 0
	beq      lbl_8024EFE8
	lbz      r0, 0x24(r3)
	cmplwi   r0, 0
	bne      lbl_8024EFE8
	lwz      r0, 0x20(r3)
	cmpwi    r0, 5
	beq      lbl_8024EFE8
	cmpwi    r0, 6
	beq      lbl_8024EFE8
	li       r0, 1
	b        lbl_8024EFF8

lbl_8024EFE8:
	lwz      r4, 4(r4)

lbl_8024EFEC:
	cmplwi   r4, 0
	bne      lbl_8024EFB0
	li       r0, 0

lbl_8024EFF8:
	clrlwi.  r0, r0, 0x18
	bne      lbl_8024F030
	cmpw     r27, r30
	blt      lbl_8024F030
	ble      lbl_8024F014
	li       r31, 0
	mr       r30, r27

lbl_8024F014:
	slwi     r5, r31, 2
	addi     r4, r1, 0x808
	addi     r3, r1, 8
	li       r0, 0
	stwx     r29, r4, r5
	addi     r31, r31, 1
	stwx     r0, r3, r5

lbl_8024F030:
	lwz      r29, 4(r29)

lbl_8024F034:
	cmplwi   r29, 0
	bne      lbl_8024EDB4
	cmpwi    r31, 0
	beq      lbl_8024F0AC
	bl       rand
	lis      r5, 0x4330
	xoris    r0, r3, 0x8000
	stw      r0, 0x100c(r1)
	xoris    r0, r31, 0x8000
	lfd      f2, lbl_8051A848@sda21(r2)
	addi     r4, r1, 8
	stw      r5, 0x1008(r1)
	addi     r3, r1, 0x808
	lfs      f0, lbl_8051A858@sda21(r2)
	lfd      f1, 0x1008(r1)
	stw      r0, 0x1014(r1)
	fsubs    f1, f1, f2
	stw      r5, 0x1010(r1)
	fdivs    f1, f1, f0
	lfd      f0, 0x1010(r1)
	fsubs    f0, f0, f2
	fmuls    f0, f0, f1
	fctiwz   f0, f0
	stfd     f0, 0x1018(r1)
	lwz      r0, 0x101c(r1)
	slwi     r5, r0, 2
	lwzx     r0, r4, r5
	lwzx     r3, r3, r5
	stw      r0, 0(r26)
	b        lbl_8024F0B0

lbl_8024F0AC:
	li       r3, 0

lbl_8024F0B0:
	lmw      r25, 0x1024(r1)
	lwz      r0, 0x1044(r1)
	mtlr     r0
	addi     r1, r1, 0x1040
	blr
	*/
}

/*
 * --INFO--
 * Address:	8024F0C4
 * Size:	000180
 */
void Cave::RandItemUnit::getItemUnit()
{
	/*
	stwu     r1, -0x1030(r1)
	mflr     r0
	li       r10, 0
	stw      r0, 0x1034(r1)
	addi     r6, r1, 0x808
	stw      r31, 0x102c(r1)
	addi     r31, r1, 8
	mr       r7, r31
	stw      r30, 0x1028(r1)
	li       r30, 0
	stw      r29, 0x1024(r1)
	li       r29, 0
	lwz      r4, 8(r3)
	lwz      r4, 0x24(r4)
	lwz      r11, 0x10(r4)
	b        lbl_8024F188

lbl_8024F104:
	lwz      r9, 0x18(r11)
	lwz      r5, 0(r9)
	cmplwi   r5, 0
	beq      lbl_8024F184
	lis      r4, 0x66666667@ha
	lwz      r8, 0x1c(r5)
	addi     r0, r4, 0x66666667@l
	mulhw    r0, r0, r8
	srawi    r4, r0, 2
	srwi     r5, r4, 0x1f
	srawi    r0, r0, 2
	add      r4, r4, r5
	mulli    r5, r4, 0xa
	srwi     r4, r0, 0x1f
	add      r4, r0, r4
	subf.    r0, r5, r8
	beq      lbl_8024F164
	stw      r0, 0(r7)
	addi     r30, r30, 1
	lwz      r0, 0(r7)
	addi     r7, r7, 4
	stw      r9, 0(r6)
	addi     r6, r6, 4
	add      r29, r29, r0

lbl_8024F164:
	cmpwi    r4, 0
	beq      lbl_8024F184
	lwz      r0, 0(r3)
	add      r10, r10, r4
	cmpw     r0, r10
	bge      lbl_8024F184
	lwz      r3, 0x18(r11)
	b        lbl_8024F228

lbl_8024F184:
	lwz      r11, 4(r11)

lbl_8024F188:
	cmplwi   r11, 0
	bne      lbl_8024F104
	cmpwi    r29, 0
	beq      lbl_8024F224
	bl       rand
	lis      r4, 0x4330
	xoris    r0, r3, 0x8000
	stw      r0, 0x100c(r1)
	xoris    r0, r29, 0x8000
	lfd      f2, lbl_8051A848@sda21(r2)
	li       r5, 0
	stw      r4, 0x1008(r1)
	li       r6, 0
	lfs      f0, lbl_8051A858@sda21(r2)
	lfd      f1, 0x1008(r1)
	stw      r0, 0x1014(r1)
	fsubs    f1, f1, f2
	stw      r4, 0x1010(r1)
	fdivs    f1, f1, f0
	lfd      f0, 0x1010(r1)
	fsubs    f0, f0, f2
	fmuls    f0, f0, f1
	fctiwz   f0, f0
	stfd     f0, 0x1018(r1)
	lwz      r3, 0x101c(r1)
	mtctr    r30
	cmpwi    r30, 0
	ble      lbl_8024F224

lbl_8024F1F8:
	lwz      r0, 0(r31)
	add      r5, r5, r0
	cmpw     r5, r3
	ble      lbl_8024F218
	slwi     r0, r6, 2
	addi     r3, r1, 0x808
	lwzx     r3, r3, r0
	b        lbl_8024F228

lbl_8024F218:
	addi     r31, r31, 4
	addi     r6, r6, 1
	bdnz     lbl_8024F1F8

lbl_8024F224:
	li       r3, 0

lbl_8024F228:
	lwz      r0, 0x1034(r1)
	lwz      r31, 0x102c(r1)
	lwz      r30, 0x1028(r1)
	lwz      r29, 0x1024(r1)
	mtlr     r0
	addi     r1, r1, 0x1030
	blr
	*/
}

/*
 * --INFO--
 * Address:	8024F244
 * Size:	000060
 */
void Cave::RandItemUnit::getItemSlotNum(Game::Cave::MapNode*)
{
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	li       r31, 0
	lwz      r3, 0x18(r4)
	bl       getBaseGen__Q34Game4Cave8UnitInfoFv
	cmplwi   r3, 0
	beq      lbl_8024F28C
	lwz      r3, 0x10(r3)
	b        lbl_8024F284

lbl_8024F270:
	lwz      r0, 0x18(r3)
	cmpwi    r0, 2
	bne      lbl_8024F280
	addi     r31, r31, 1

lbl_8024F280:
	lwz      r3, 4(r3)

lbl_8024F284:
	cmplwi   r3, 0
	bne      lbl_8024F270

lbl_8024F28C:
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
 * Address:	8024F2A4
 * Size:	00005C
 */
void Cave::RandItemUnit::isItemSetHard()
{
	/*
	lwz      r4, 8(r3)
	lwz      r0, 4(r4)
	cmpwi    r0, 4
	beq      lbl_8024F2F0
	bge      lbl_8024F2F8
	cmpwi    r0, 2
	bge      lbl_8024F2D4
	cmpwi    r0, 0
	bge      lbl_8024F2CC
	b        lbl_8024F2F8

lbl_8024F2CC:
	li       r3, 0
	blr

lbl_8024F2D4:
	lwz      r0, 0(r3)
	cmpwi    r0, 0
	beq      lbl_8024F2E8
	li       r3, 0
	blr

lbl_8024F2E8:
	li       r3, 1
	blr

lbl_8024F2F0:
	li       r3, 1
	blr

lbl_8024F2F8:
	li       r3, 0
	blr
	*/
}

/*
 * --INFO--
 * Address:	8024F300
 * Size:	000148
 */
void Cave::RandItemUnit::getItemDropMapNode(Game::Cave::MapNode*, Game::Cave::MapNode**, int, int&)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x30(r1)
	  mflr      r0
	  stw       r0, 0x34(r1)
	  stmw      r26, 0x18(r1)
	  mr        r29, r4
	  mr        r30, r5
	  mr        r26, r6
	  mr        r31, r7
	  li        r27, 0
	  lwz       r3, 0x18(r4)
	  bl        -0xC7B0
	  cmpwi     r3, 0x1
	  bne-      .loc_0x3C
	  li        r27, 0x1
	  b         .loc_0xC0

	.loc_0x3C:
	  cmpwi     r3, 0
	  bne-      .loc_0x68
	  mr        r3, r29
	  bl        -0xB984
	  subi      r4, r2, 0x3B10
	  li        r5, 0x4
	  bl        -0x184CD4
	  cmpwi     r3, 0
	  bne-      .loc_0xC0
	  li        r27, 0x1
	  b         .loc_0xC0

	.loc_0x68:
	  cmpwi     r3, 0x2
	  bne-      .loc_0xC0
	  mr        r3, r29
	  bl        -0xB314
	  cmpwi     r3, 0x2
	  bne-      .loc_0xBC
	  mr        r3, r29
	  li        r4, 0x1
	  bl        -0xC360
	  mr        r28, r3
	  mr        r3, r29
	  li        r4, 0
	  bl        -0xC370
	  add       r0, r3, r28
	  rlwinm    r3,r0,1,31,31
	  rlwinm    r0,r0,0,31,31
	  xor       r0, r0, r3
	  sub.      r0, r0, r3
	  bne-      .loc_0xC0
	  li        r27, 0x1
	  b         .loc_0xC0

	.loc_0xBC:
	  li        r27, 0x1

	.loc_0xC0:
	  rlwinm.   r0,r27,0,24,31
	  beq-      .loc_0x134
	  mr        r3, r29
	  bl        -0xBA10
	  sub       r0, r3, r26
	  lwz       r4, 0x0(r31)
	  srawi     r3, r0, 0x1F
	  xor       r0, r3, r0
	  sub       r28, r0, r3
	  cmpw      r28, r4
	  blt-      .loc_0x12C
	  bne-      .loc_0x134
	  bl        -0x185E50
	  xoris     r3, r3, 0x8000
	  lis       r0, 0x4330
	  stw       r3, 0xC(r1)
	  lfd       f3, -0x3B18(r2)
	  stw       r0, 0x8(r1)
	  lfs       f2, -0x3B20(r2)
	  lfd       f0, 0x8(r1)
	  lfs       f1, -0x3B08(r2)
	  fsubs     f3, f0, f3
	  lfs       f0, -0x3B04(r2)
	  fmuls     f2, f2, f3
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x134

	.loc_0x12C:
	  stw       r29, 0x0(r30)
	  stw       r28, 0x0(r31)

	.loc_0x134:
	  lmw       r26, 0x18(r1)
	  lwz       r0, 0x34(r1)
	  mtlr      r0
	  addi      r1, r1, 0x30
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8024F448
 * Size:	000314
 */
void Cave::RandItemUnit::getItemBaseGenPosition(Game::Cave::MapNode*, int)
{
	/*
	stwu     r1, -0x330(r1)
	mflr     r0
	stw      r0, 0x334(r1)
	stfd     f31, 0x320(r1)
	psq_st   f31, 808(r1), 0, qr0
	stfd     f30, 0x310(r1)
	psq_st   f30, 792(r1), 0, qr0
	stfd     f29, 0x300(r1)
	psq_st   f29, 776(r1), 0, qr0
	stfd     f28, 0x2f0(r1)
	psq_st   f28, 760(r1), 0, qr0
	stmw     r25, 0x2d4(r1)
	mr       r31, r5
	mr       r30, r3
	mr       r26, r4
	mr       r25, r6
	mr       r4, r31
	addi     r3, r1, 0x2c
	li       r27, 0
	li       r29, 0
	li       r5, 0
	bl getBaseGenGlobalPosition__Q34Game4Cave7MapNodeFPQ34Game4Cave7BaseGen lfs
f31, 0x2c(r1) lfs      f30, 0x30(r1) lfs      f29, 0x34(r1) lwz      r3,
0x18(r31) bl       getBaseGen__Q34Game4Cave8UnitInfoFv cmplwi   r3, 0 beq
lbl_8024F51C lwz      r4, 0x10(r3) addi     r3, r1, 0x38 b        lbl_8024F514

lbl_8024F4C8:
	lwz      r0, 0x18(r4)
	cmpwi    r0, 2
	bne      lbl_8024F4E4
	stwx     r4, r3, r29
	addi     r27, r27, 1
	addi     r29, r29, 4
	b        lbl_8024F510

lbl_8024F4E4:
	cmpwi    r0, 0
	bne      lbl_8024F4FC
	stwx     r4, r3, r29
	addi     r27, r27, 1
	addi     r29, r29, 4
	b        lbl_8024F510

lbl_8024F4FC:
	cmpwi    r0, 1
	bne      lbl_8024F510
	stwx     r4, r3, r29
	addi     r27, r27, 1
	addi     r29, r29, 4

lbl_8024F510:
	lwz      r4, 4(r4)

lbl_8024F514:
	cmplwi   r4, 0
	bne      lbl_8024F4C8

lbl_8024F51C:
	cmpwi    r27, 0
	ble      lbl_8024F71C
	lis      r4, "__ct__10Vector3<f>Fv"@ha
	addi     r3, r1, 0x138
	addi     r4, r4, "__ct__10Vector3<f>Fv"@l
	li       r5, 0
	li       r6, 0xc
	li       r7, 0x20
	bl       __construct_array
	mr       r3, r31
	bl       getVersusScore__Q34Game4Cave7MapNodeFv
	subf.    r0, r25, r3
	ble      lbl_8024F588
	lwz      r3, 0xc(r26)
	li       r4, 3
	bl       getFixObjGen__Q34Game4Cave12RandMapScoreFi
	mr       r29, r3
	lwz      r3, 0xc(r26)
	li       r4, 3
	bl       getFixObjNode__Q34Game4Cave12RandMapScoreFi
	mr       r4, r3
	mr       r5, r29
	addi     r3, r1, 0x20
	bl getBaseGenGlobalPosition__Q34Game4Cave7MapNodeFPQ34Game4Cave7BaseGen lfs
f30, 0x20(r1) lfs      f28, 0x28(r1) b        lbl_8024F5BC

lbl_8024F588:
	lwz      r3, 0xc(r26)
	li       r4, 4
	bl       getFixObjGen__Q34Game4Cave12RandMapScoreFi
	mr       r29, r3
	lwz      r3, 0xc(r26)
	li       r4, 4
	bl       getFixObjNode__Q34Game4Cave12RandMapScoreFi
	mr       r4, r3
	mr       r5, r29
	addi     r3, r1, 0x14
	bl getBaseGenGlobalPosition__Q34Game4Cave7MapNodeFPQ34Game4Cave7BaseGen lfs
f30, 0x14(r1) lfs      f28, 0x1c(r1)

lbl_8024F5BC:
	fsubs    f0, f28, f29
	addi     r29, r1, 0x38
	fsubs    f1, f30, f31
	addi     r28, r1, 0x138
	li       r26, 0
	li       r25, 0
	fmuls    f0, f0, f0
	fmadds   f31, f1, f1, f0
	b        lbl_8024F630

lbl_8024F5E0:
	lwz      r5, 0(r29)
	mr       r4, r31
	addi     r3, r1, 8
	bl getBaseGenGlobalPosition__Q34Game4Cave7MapNodeFPQ34Game4Cave7BaseGen lfs
f3, 0x10(r1) lfs      f4, 8(r1) fsubs    f0, f28, f3 lfs      f2, 0xc(r1) fsubs
f1, f30, f4 fmuls    f0, f0, f0 fmadds   f0, f1, f1, f0 fcmpo    cr0, f0, f31
	bge      lbl_8024F628
	stfs     f4, 0(r28)
	addi     r26, r26, 1
	stfs     f2, 4(r28)
	stfs     f3, 8(r28)
	addi     r28, r28, 0xc

lbl_8024F628:
	addi     r29, r29, 4
	addi     r25, r25, 1

lbl_8024F630:
	cmpw     r25, r27
	blt      lbl_8024F5E0
	cmpwi    r26, 0
	beq      lbl_8024F6B4
	bl       rand
	lis      r4, 0x4330
	xoris    r0, r3, 0x8000
	stw      r0, 0x2bc(r1)
	xoris    r0, r26, 0x8000
	lfd      f2, lbl_8051A848@sda21(r2)
	addi     r3, r1, 0x138
	stw      r4, 0x2b8(r1)
	lfs      f0, lbl_8051A858@sda21(r2)
	lfd      f1, 0x2b8(r1)
	stw      r0, 0x2c4(r1)
	fsubs    f1, f1, f2
	stw      r4, 0x2c0(r1)
	fdivs    f1, f1, f0
	lfd      f0, 0x2c0(r1)
	fsubs    f0, f0, f2
	fmuls    f0, f0, f1
	fctiwz   f0, f0
	stfd     f0, 0x2c8(r1)
	lwz      r0, 0x2cc(r1)
	mulli    r0, r0, 0xc
	add      r3, r3, r0
	lfs      f0, 0(r3)
	stfs     f0, 0(r30)
	lfs      f0, 4(r3)
	stfs     f0, 4(r30)
	lfs      f0, 8(r3)
	stfs     f0, 8(r30)
	b        lbl_8024F728

lbl_8024F6B4:
	bl       rand
	xoris    r0, r3, 0x8000
	lis      r6, 0x4330
	stw      r0, 0x2cc(r1)
	xoris    r0, r27, 0x8000
	lfd      f2, lbl_8051A848@sda21(r2)
	addi     r5, r1, 0x38
	stw      r6, 0x2c8(r1)
	mr       r3, r30
	lfs      f0, lbl_8051A858@sda21(r2)
	mr       r4, r31
	lfd      f1, 0x2c8(r1)
	stw      r0, 0x2c4(r1)
	fsubs    f1, f1, f2
	stw      r6, 0x2c0(r1)
	fdivs    f1, f1, f0
	lfd      f0, 0x2c0(r1)
	fsubs    f0, f0, f2
	fmuls    f0, f0, f1
	fctiwz   f0, f0
	stfd     f0, 0x2b8(r1)
	lwz      r0, 0x2bc(r1)
	slwi     r0, r0, 2
	lwzx     r5, r5, r0
	bl getBaseGenGlobalPosition__Q34Game4Cave7MapNodeFPQ34Game4Cave7BaseGen b
lbl_8024F728

lbl_8024F71C:
	stfs     f31, 0(r30)
	stfs     f30, 4(r30)
	stfs     f29, 8(r30)

lbl_8024F728:
	psq_l    f31, 808(r1), 0, qr0
	lfd      f31, 0x320(r1)
	psq_l    f30, 792(r1), 0, qr0
	lfd      f30, 0x310(r1)
	psq_l    f29, 776(r1), 0, qr0
	lfd      f29, 0x300(r1)
	psq_l    f28, 760(r1), 0, qr0
	lfd      f28, 0x2f0(r1)
	lmw      r25, 0x2d4(r1)
	lwz      r0, 0x334(r1)
	mtlr     r0
	addi     r1, r1, 0x330
	blr
	*/
}

/*
 * --INFO--
 * Address:	8024F75C
 * Size:	00018C
 */
void Cave::RandItemUnit::getItemDropList(Game::Cave::MapNode*, Game::Cave::MapNode**, Game::Cave::BaseGen**, int&)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  mflr      r0
	  stw       r0, 0x24(r1)
	  stmw      r27, 0xC(r1)
	  mr        r28, r4
	  mr        r29, r5
	  mr        r30, r6
	  mr        r31, r7
	  lwz       r3, 0x18(r4)
	  bl        -0xCC08
	  cmpwi     r3, 0x1
	  bne-      .loc_0x88
	  lwz       r3, 0x18(r28)
	  bl        -0xCBD0
	  cmplwi    r3, 0
	  beq-      .loc_0x178
	  lwz       r4, 0x10(r3)
	  b         .loc_0x7C

	.loc_0x48:
	  lwz       r0, 0x18(r4)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x78
	  lwz       r0, 0x0(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r29, r0
	  lwz       r0, 0x0(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r30, r0
	  lwz       r3, 0x0(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r31)

	.loc_0x78:
	  lwz       r4, 0x4(r4)

	.loc_0x7C:
	  cmplwi    r4, 0
	  bne+      .loc_0x48
	  b         .loc_0x178

	.loc_0x88:
	  cmpwi     r3, 0
	  bne-      .loc_0xD8
	  mr        r3, r28
	  bl        -0xBE2C
	  subi      r4, r2, 0x3B10
	  li        r5, 0x4
	  bl        -0x18517C
	  cmpwi     r3, 0
	  bne-      .loc_0x178
	  lwz       r0, 0x0(r31)
	  li        r3, 0
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r29, r0
	  lwz       r0, 0x0(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r3, r30, r0
	  lwz       r3, 0x0(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r31)
	  b         .loc_0x178

	.loc_0xD8:
	  cmpwi     r3, 0x2
	  bne-      .loc_0x178
	  mr        r3, r28
	  bl        -0xB7E0
	  cmpwi     r3, 0x2
	  bne-      .loc_0x150
	  mr        r3, r28
	  li        r4, 0x1
	  bl        -0xC82C
	  mr        r27, r3
	  mr        r3, r28
	  li        r4, 0
	  bl        -0xC83C
	  add       r0, r3, r27
	  rlwinm    r3,r0,1,31,31
	  rlwinm    r0,r0,0,31,31
	  xor       r0, r0, r3
	  sub.      r0, r0, r3
	  bne-      .loc_0x178
	  lwz       r0, 0x0(r31)
	  li        r3, 0
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r29, r0
	  lwz       r0, 0x0(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r3, r30, r0
	  lwz       r3, 0x0(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r31)
	  b         .loc_0x178

	.loc_0x150:
	  lwz       r0, 0x0(r31)
	  li        r3, 0
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r29, r0
	  lwz       r0, 0x0(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r3, r30, r0
	  lwz       r3, 0x0(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r31)

	.loc_0x178:
	  lmw       r27, 0xC(r1)
	  lwz       r0, 0x24(r1)
	  mtlr      r0
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8024F8E8
 * Size:	0002CC
 */
void Cave::RandItemUnit::getItemBaseGenPosition(Game::Cave::MapNode**, Game::Cave::BaseGen**, int, int, int)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x260(r1)
	  mflr      r0
	  stw       r0, 0x264(r1)
	  stfd      f31, 0x250(r1)
	  psq_st    f31,0x258(r1),0,0
	  stmw      r17, 0x214(r1)
	  mr        r17, r4
	  mr        r31, r3
	  lwz       r3, 0xC(r4)
	  mr        r18, r5
	  mr        r19, r6
	  mr        r20, r7
	  mr        r21, r8
	  mr        r22, r9
	  li        r4, 0x3
	  bl        -0x2D7C
	  mr        r27, r3
	  lwz       r3, 0xC(r17)
	  li        r4, 0x4
	  bl        -0x2D8C
	  mr        r28, r3
	  lwz       r3, 0xC(r17)
	  li        r4, 0x3
	  bl        -0x2D8C
	  mr        r29, r3
	  lwz       r3, 0xC(r17)
	  li        r4, 0x4
	  bl        -0x2D9C
	  lfs       f31, -0x3B00(r2)
	  mr        r30, r3
	  mr        r26, r18
	  mr        r25, r19
	  addi      r24, r1, 0x8
	  li        r23, 0
	  b         .loc_0x1A8

	.loc_0x8C:
	  lwz       r3, 0x0(r26)
	  lfs       f0, -0x3B00(r2)
	  cmplw     r27, r3
	  bne-      .loc_0xFC
	  lwz       r4, 0x0(r25)
	  lfs       f1, 0x20(r29)
	  lfs       f0, 0x20(r4)
	  lfs       f3, 0x1C(r29)
	  fsubs     f4, f1, f0
	  lfs       f2, 0x1C(r4)
	  lfs       f1, 0x24(r29)
	  lfs       f0, 0x24(r4)
	  fsubs     f3, f3, f2
	  fmuls     f4, f4, f4
	  fsubs     f2, f1, f0
	  lfs       f0, -0x3AFC(r2)
	  fmadds    f1, f3, f3, f4
	  fmuls     f2, f2, f2
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xF0
	  ble-      .loc_0xF4
	  fsqrte    f0, f1
	  fmuls     f1, f0, f1
	  b         .loc_0xF4

	.loc_0xF0:
	  fmr       f1, f0

	.loc_0xF4:
	  fmr       f0, f1
	  b         .loc_0x160

	.loc_0xFC:
	  cmplw     r28, r3
	  bne-      .loc_0x160
	  lwz       r4, 0x0(r25)
	  lfs       f1, 0x20(r30)
	  lfs       f0, 0x20(r4)
	  lfs       f3, 0x1C(r30)
	  fsubs     f4, f1, f0
	  lfs       f2, 0x1C(r4)
	  lfs       f1, 0x24(r30)
	  lfs       f0, 0x24(r4)
	  fsubs     f3, f3, f2
	  fmuls     f4, f4, f4
	  fsubs     f2, f1, f0
	  lfs       f0, -0x3AFC(r2)
	  fmadds    f1, f3, f3, f4
	  fmuls     f2, f2, f2
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x158
	  ble-      .loc_0x15C
	  fsqrte    f0, f1
	  fmuls     f1, f0, f1
	  b         .loc_0x15C

	.loc_0x158:
	  fmr       f1, f0

	.loc_0x15C:
	  fmr       f0, f1

	.loc_0x160:
	  fcmpo     cr0, f0, f31
	  bge-      .loc_0x180
	  fctiwz    f0, f0
	  stfd      f0, 0x208(r1)
	  lwz       r0, 0x20C(r1)
	  subfic    r0, r0, 0x3200
	  stw       r0, 0x0(r24)
	  b         .loc_0x198

	.loc_0x180:
	  bl        -0xC0AC
	  sub       r0, r3, r21
	  srawi     r3, r0, 0x1F
	  xor       r0, r3, r0
	  sub       r0, r0, r3
	  stw       r0, 0x0(r24)

	.loc_0x198:
	  addi      r26, r26, 0x4
	  addi      r25, r25, 0x4
	  addi      r24, r24, 0x4
	  addi      r23, r23, 0x1

	.loc_0x1A8:
	  cmpw      r23, r20
	  blt+      .loc_0x8C
	  mr        r3, r17
	  mr        r4, r18
	  mr        r5, r19
	  mr        r7, r20
	  addi      r6, r1, 0x8
	  bl        .loc_0x2CC
	  mr        r6, r18
	  mr        r7, r19
	  li        r8, 0
	  b         .loc_0x270

	.loc_0x1D8:
	  li        r9, 0x1
	  li        r5, 0
	  mtctr     r22
	  cmpwi     r22, 0
	  ble-      .loc_0x220

	.loc_0x1EC:
	  lwz       r3, 0x10(r17)
	  lwz       r4, 0x0(r6)
	  lwzx      r0, r3, r5
	  cmplw     r4, r0
	  bne-      .loc_0x218
	  lwz       r3, 0x14(r17)
	  lwz       r4, 0x0(r7)
	  lwzx      r0, r3, r5
	  cmplw     r4, r0
	  bne-      .loc_0x218
	  li        r9, 0

	.loc_0x218:
	  addi      r5, r5, 0x4
	  bdnz+     .loc_0x1EC

	.loc_0x220:
	  rlwinm.   r0,r9,0,24,31
	  beq-      .loc_0x264
	  rlwinm    r5,r8,2,0,29
	  lwz       r4, 0x10(r17)
	  lwzx      r0, r18, r5
	  rlwinm    r6,r22,2,0,29
	  mr        r3, r31
	  stwx      r0, r4, r6
	  lwzx      r0, r19, r5
	  lwz       r4, 0x14(r17)
	  stwx      r0, r4, r6
	  lwz       r4, 0x10(r17)
	  lwz       r5, 0x14(r17)
	  lwzx      r4, r4, r6
	  lwzx      r5, r5, r6
	  bl        -0xC068
	  b         .loc_0x2B0

	.loc_0x264:
	  addi      r6, r6, 0x4
	  addi      r7, r7, 0x4
	  addi      r8, r8, 0x1

	.loc_0x270:
	  cmpw      r8, r20
	  blt+      .loc_0x1D8
	  lis       r3, 0x8048
	  lis       r5, 0x8048
	  addi      r3, r3, 0x413C
	  li        r4, 0x3A0
	  addi      r5, r5, 0x4178
	  crclr     6, 0x6
	  bl        -0x225538
	  lis       r3, 0x8051
	  lfsu      f0, 0x41E4(r3)
	  stfs      f0, 0x0(r31)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x4(r31)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x8(r31)

	.loc_0x2B0:
	  psq_l     f31,0x258(r1),0,0
	  lfd       f31, 0x250(r1)
	  lmw       r17, 0x214(r1)
	  lwz       r0, 0x264(r1)
	  mtlr      r0
	  addi      r1, r1, 0x260
	  blr

	.loc_0x2CC:
	*/
}

/*
 * --INFO--
 * Address:	8024FBB4
 * Size:	000114
 */
void Cave::RandItemUnit::getItemDropSortingList(Game::Cave::MapNode**, Game::Cave::BaseGen**, int*, int)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x50(r1)
	  mflr      r0
	  stw       r0, 0x54(r1)
	  stmw      r19, 0x1C(r1)
	  mr        r19, r4
	  mr        r20, r5
	  mr        r21, r6
	  mr        r22, r7
	  mr        r27, r19
	  mr        r28, r21
	  mr        r26, r20
	  subi      r25, r22, 0x1
	  li        r24, 0
	  b         .loc_0xF8

	.loc_0x38:
	  addi      r23, r24, 0x1
	  rlwinm    r0,r23,2,0,29
	  add       r31, r21, r0
	  add       r30, r19, r0
	  add       r29, r20, r0
	  b         .loc_0xE0

	.loc_0x50:
	  lwz       r3, 0x0(r28)
	  lwz       r0, 0x0(r31)
	  cmpw      r3, r0
	  bgt-      .loc_0xA0
	  bne-      .loc_0xD0
	  bl        -0x186678
	  xoris     r3, r3, 0x8000
	  lis       r0, 0x4330
	  stw       r3, 0xC(r1)
	  lfd       f3, -0x3B18(r2)
	  stw       r0, 0x8(r1)
	  lfs       f2, -0x3B20(r2)
	  lfd       f0, 0x8(r1)
	  lfs       f1, -0x3B08(r2)
	  fsubs     f3, f0, f3
	  lfs       f0, -0x3B04(r2)
	  fmuls     f2, f2, f3
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xD0

	.loc_0xA0:
	  lwz       r3, 0x0(r27)
	  lwz       r4, 0x0(r26)
	  lwz       r5, 0x0(r28)
	  lwz       r0, 0x0(r30)
	  stw       r0, 0x0(r27)
	  lwz       r0, 0x0(r29)
	  stw       r0, 0x0(r26)
	  lwz       r0, 0x0(r31)
	  stw       r0, 0x0(r28)
	  stw       r3, 0x0(r30)
	  stw       r4, 0x0(r29)
	  stw       r5, 0x0(r31)

	.loc_0xD0:
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x4
	  addi      r29, r29, 0x4
	  addi      r23, r23, 0x1

	.loc_0xE0:
	  cmpw      r23, r22
	  blt+      .loc_0x50
	  addi      r28, r28, 0x4
	  addi      r27, r27, 0x4
	  addi      r26, r26, 0x4
	  addi      r24, r24, 0x1

	.loc_0xF8:
	  cmpw      r24, r25
	  blt+      .loc_0x38
	  lmw       r19, 0x1C(r1)
	  lwz       r0, 0x54(r1)
	  mtlr      r0
	  addi      r1, r1, 0x50
	  blr
	*/
}
} // namespace Game
