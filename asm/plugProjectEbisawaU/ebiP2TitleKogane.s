.include "macros.inc"
.section .ctors, "wa"  # 0x80472F00 - 0x804732C0
lbl_constructor:
	.4byte __sinit_ebiP2TitleKogane_cpp

.section .rodata  # 0x804732E0 - 0x8049E220
.balign 8
.obj lbl_804974A0, local
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_804974A0
.balign 4
.obj lbl_804974AC, local
	.asciz "ebiP2TitleKogane"
.endobj lbl_804974AC
.balign 4
.obj lbl_804974C0, local
	.asciz "KoganeMgr"
.endobj lbl_804974C0
.balign 4
.obj lbl_804974CC, local
	.4byte 0x83588350
	.4byte 0x815B838B
	.byte 0
.endobj lbl_804974CC
.balign 4
.obj lbl_804974D8, local
	.4byte 0x834A838A
	.4byte 0x8393834F
	.4byte 0x94BC8C61
	.byte 0
.endobj lbl_804974D8
.balign 4
.obj lbl_804974E8, local
	.4byte 0x8352838A
	.4byte 0x83578387
	.4byte 0x839394BC
	.byte 0x8C, 0x61, 0x00
.endobj lbl_804974E8
.balign 4
.obj lbl_804974F8, local
	.4byte 0x8373834E
	.4byte 0x837E8393
	.4byte 0x94BD899E
	.4byte 0x94BC8C61
	.byte 0
.endobj lbl_804974F8
.balign 4
.obj lbl_8049750C, local
	.4byte 0x95E08D73
	.4byte 0x83898393
	.4byte 0x835F8380
	.4byte 0x8A709378
	.byte 0
.endobj lbl_8049750C
.balign 4
.obj lbl_80497520, local
	.4byte 0x95E08D73
	.4byte 0x91AC9378
	.byte 0
.endobj lbl_80497520
.balign 4
.obj lbl_8049752C, local
	.4byte 0x90F989F1
	.4byte 0x90AB945C
	.byte 0
.endobj lbl_8049752C
.balign 4
.obj lbl_80497538, local
	.4byte 0x91D282BF
	.4byte 0x8E9E8AD4
	.4byte 0x8DC58FAC
	.4byte 0x28956229
	.byte 0
.endobj lbl_80497538
.balign 4
.obj lbl_8049754C, local
	.4byte 0x91D282BF
	.4byte 0x8E9E8AD4
	.4byte 0x8DC591E5
	.4byte 0x28956229
	.byte 0
.endobj lbl_8049754C
.balign 4
.obj lbl_80497560, local
	.4byte 0x88DA93AE
	.4byte 0x8E9E8AD4
	.4byte 0x8DC58FAC
	.4byte 0x28956229
	.byte 0
.endobj lbl_80497560
.balign 4
.obj lbl_80497574, local
	.4byte 0x88DA93AE
	.4byte 0x8E9E8AD4
	.4byte 0x8DC591E5
	.4byte 0x28956229
	.byte 0
.endobj lbl_80497574
.balign 4
.obj lbl_80497588, local
	.4byte 0x83528393
	.4byte 0x8367838D
	.4byte 0x815B8389
	.4byte 0x8FF391D4
	.4byte 0x8E9E8AD4
	.4byte 0x28956229
	.byte 0
.endobj lbl_80497588
.balign 4
.obj lbl_804975A4, local
	.asciz "param/param_kogane.txt"
.endobj lbl_804975A4
.balign 4
.obj lbl_804975BC, local
	.asciz "kogane/kogane_move.bck"
.endobj lbl_804975BC
.balign 4
.obj lbl_804975D4, local
	.asciz "kogane/kogane_wait.bck"
.endobj lbl_804975D4
.balign 4
.obj lbl_804975EC, local
	.asciz "kogane/kogane_title.bmd"
.endobj lbl_804975EC
.balign 4
.obj lbl_80497604, local
	.asciz "ebiP2TitleKogane.cpp"
.endobj lbl_80497604
.balign 4
.obj lbl_8049761C, local
	.asciz "P2Assert"
.endobj lbl_8049761C

.section .data, "wa"  # 0x8049E220 - 0x804EFC20
.balign 8
.obj govNAN___Q24Game5P2JST, local
	.float 0.0
	.float 0.0
	.float 0.0
.endobj govNAN___Q24Game5P2JST
.obj lbl_804E9E1C, local
	.4byte .L_803E78A8
	.4byte .L_803E78E8
	.4byte .L_803E7940
	.4byte .L_803E7A58
	.4byte .L_803E7AB0
	.4byte .L_803E7B0C
	.4byte .L_803E78C4
.endobj lbl_804E9E1C
.obj __vt__Q43ebi5title6Kogane5TUnit, global
	.4byte 0
	.4byte 0
	.4byte getCreatureType__Q43ebi5title6Kogane5TUnitFv
	.4byte isCalc__Q43ebi5title6Kogane5TUnitFv
.endobj __vt__Q43ebi5title6Kogane5TUnit
.obj __vt__Q43ebi5title6Kogane11TAnimFolder, weak
	.4byte 0
	.4byte 0
	.4byte getAnimRes__Q43ebi5title6Kogane11TAnimFolderFl
.endobj __vt__Q43ebi5title6Kogane11TAnimFolder
.obj __vt__Q23ebi17E3DAnimFolderBase, weak
	.4byte 0
	.4byte 0
	.4byte 0
.endobj __vt__Q23ebi17E3DAnimFolderBase

.section .sbss # 0x80514D80 - 0x80516360
.balign 8
.obj gu32NAN___Q24Game5P2JST, local
	.skip 0x4
.endobj gu32NAN___Q24Game5P2JST
.obj gfNAN___Q24Game5P2JST, local
	.skip 0x4
.endobj gfNAN___Q24Game5P2JST

.section .sdata2, "a"     # 0x80516360 - 0x80520E40
.balign 8
.obj lbl_8051FD00, local
	.float 0.0
.endobj lbl_8051FD00
.obj lbl_8051FD04, local
	.float -1.0
.endobj lbl_8051FD04
.obj lbl_8051FD08, local
	.float 1.0
.endobj lbl_8051FD08
.balign 4
.obj lbl_8051FD0C, local
	.asciz "Parms"
.endobj lbl_8051FD0C
.balign 4
.obj lbl_8051FD14, local
	.float 2.0
.endobj lbl_8051FD14
.obj lbl_8051FD18, local
	.float 10.0
.endobj lbl_8051FD18
.obj lbl_8051FD1C, local
	.float 50.0
.endobj lbl_8051FD1C
.obj lbl_8051FD20, local
	.float 500.0
.endobj lbl_8051FD20
.obj lbl_8051FD24, local
	.float 150.0
.endobj lbl_8051FD24
.obj lbl_8051FD28, local
	.float 60.0
.endobj lbl_8051FD28
.obj lbl_8051FD2C, local
	.float 90.0
.endobj lbl_8051FD2C
.obj lbl_8051FD30, local
	.float 100.0
.endobj lbl_8051FD30
.obj lbl_8051FD34, local
	.float 0.1
.endobj lbl_8051FD34
.obj lbl_8051FD38, local
	.float 1.5
.endobj lbl_8051FD38
.obj lbl_8051FD3C, local
	.float 0.3
.endobj lbl_8051FD3C
.obj lbl_8051FD40, local
	.float 5.0
.endobj lbl_8051FD40
.obj lbl_8051FD44, local
	.float 32767.0
.endobj lbl_8051FD44
.obj lbl_8051FD48, local
	.float 3.1415927
.endobj lbl_8051FD48
.obj lbl_8051FD4C, local
	.float 0.0055555557
.endobj lbl_8051FD4C
.obj lbl_8051FD50, local
	.float -325.9493
.endobj lbl_8051FD50
.obj lbl_8051FD54, local
	.float 325.9493
.endobj lbl_8051FD54
.balign 8
.obj lbl_8051FD58, local
	.4byte 0x43300000
	.4byte 0x80000000
.endobj lbl_8051FD58
.obj lbl_8051FD60, local
	.float 0.7
.endobj lbl_8051FD60
.obj lbl_8051FD64, local
	.float 0.5
.endobj lbl_8051FD64

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.fn __ct__Q43ebi5title6Kogane4TMgrFv, global
/* 803E7358 003E4298  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 803E735C 003E429C  7C 08 02 A6 */	mflr r0
/* 803E7360 003E42A0  3C 80 80 4F */	lis r4, __vt__5CNode@ha
/* 803E7364 003E42A4  38 C0 00 00 */	li r6, 0
/* 803E7368 003E42A8  90 01 00 14 */	stw r0, 0x14(r1)
/* 803E736C 003E42AC  38 04 B5 28 */	addi r0, r4, __vt__5CNode@l
/* 803E7370 003E42B0  3C 80 80 49 */	lis r4, lbl_804974C0@ha
/* 803E7374 003E42B4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 803E7378 003E42B8  38 A4 74 C0 */	addi r5, r4, lbl_804974C0@l
/* 803E737C 003E42BC  7C 7F 1B 78 */	mr r31, r3
/* 803E7380 003E42C0  38 80 00 01 */	li r4, 1
/* 803E7384 003E42C4  93 C1 00 08 */	stw r30, 8(r1)
/* 803E7388 003E42C8  90 03 00 00 */	stw r0, 0(r3)
/* 803E738C 003E42CC  3C 60 80 4E */	lis r3, __vt__Q43ebi5title6Kogane4TMgr@ha
/* 803E7390 003E42D0  38 03 78 8C */	addi r0, r3, __vt__Q43ebi5title6Kogane4TMgr@l
/* 803E7394 003E42D4  90 DF 00 10 */	stw r6, 0x10(r31)
/* 803E7398 003E42D8  38 7F 00 1C */	addi r3, r31, 0x1c
/* 803E739C 003E42DC  90 DF 00 0C */	stw r6, 0xc(r31)
/* 803E73A0 003E42E0  90 DF 00 08 */	stw r6, 8(r31)
/* 803E73A4 003E42E4  90 DF 00 04 */	stw r6, 4(r31)
/* 803E73A8 003E42E8  90 BF 00 14 */	stw r5, 0x14(r31)
/* 803E73AC 003E42EC  90 1F 00 00 */	stw r0, 0(r31)
/* 803E73B0 003E42F0  48 00 0E B5 */	bl __ct__Q43ebi5title6Kogane6TParamFv
/* 803E73B4 003E42F4  38 60 00 48 */	li r3, 0x48
/* 803E73B8 003E42F8  4B C3 CA ED */	bl __nw__FUl
/* 803E73BC 003E42FC  7C 60 1B 79 */	or. r0, r3, r3
/* 803E73C0 003E4300  41 82 00 0C */	beq .L_803E73CC
/* 803E73C4 003E4304  48 00 01 55 */	bl __ct__Q43ebi5title6Kogane9TAnimatorFv
/* 803E73C8 003E4308  7C 60 1B 78 */	mr r0, r3
.L_803E73CC:
/* 803E73CC 003E430C  90 1F 00 18 */	stw r0, 0x18(r31)
/* 803E73D0 003E4310  38 60 00 68 */	li r3, 0x68
/* 803E73D4 003E4314  4B C3 CA D1 */	bl __nw__FUl
/* 803E73D8 003E4318  7C 7E 1B 79 */	or. r30, r3, r3
/* 803E73DC 003E431C  41 82 00 A4 */	beq .L_803E7480
/* 803E73E0 003E4320  3C 80 80 4E */	lis r4, __vt__Q33ebi5title8TObjBase@ha
/* 803E73E4 003E4324  3C 60 80 4F */	lis r3, __vt__Q43ebi5title6Kogane5TUnit@ha
/* 803E73E8 003E4328  38 04 79 A8 */	addi r0, r4, __vt__Q33ebi5title8TObjBase@l
/* 803E73EC 003E432C  C0 42 19 A0 */	lfs f2, lbl_8051FD00@sda21(r2)
/* 803E73F0 003E4330  90 1E 00 00 */	stw r0, 0(r30)
/* 803E73F4 003E4334  38 80 00 00 */	li r4, 0
/* 803E73F8 003E4338  C0 22 19 A4 */	lfs f1, lbl_8051FD04@sda21(r2)
/* 803E73FC 003E433C  38 03 9E 38 */	addi r0, r3, __vt__Q43ebi5title6Kogane5TUnit@l
/* 803E7400 003E4340  D0 5E 00 04 */	stfs f2, 4(r30)
/* 803E7404 003E4344  C0 02 19 A8 */	lfs f0, lbl_8051FD08@sda21(r2)
/* 803E7408 003E4348  D0 5E 00 08 */	stfs f2, 8(r30)
/* 803E740C 003E434C  D0 5E 00 0C */	stfs f2, 0xc(r30)
/* 803E7410 003E4350  D0 3E 00 10 */	stfs f1, 0x10(r30)
/* 803E7414 003E4354  D0 5E 00 14 */	stfs f2, 0x14(r30)
/* 803E7418 003E4358  D0 1E 00 18 */	stfs f0, 0x18(r30)
/* 803E741C 003E435C  D0 5E 00 1C */	stfs f2, 0x1c(r30)
/* 803E7420 003E4360  D0 5E 00 20 */	stfs f2, 0x20(r30)
/* 803E7424 003E4364  D0 5E 00 24 */	stfs f2, 0x24(r30)
/* 803E7428 003E4368  90 9E 00 28 */	stw r4, 0x28(r30)
/* 803E742C 003E436C  90 1E 00 00 */	stw r0, 0(r30)
/* 803E7430 003E4370  90 9E 00 3C */	stw r4, 0x3c(r30)
/* 803E7434 003E4374  90 9E 00 40 */	stw r4, 0x40(r30)
/* 803E7438 003E4378  90 9E 00 58 */	stw r4, 0x58(r30)
/* 803E743C 003E437C  90 9E 00 5C */	stw r4, 0x5c(r30)
/* 803E7440 003E4380  D0 5E 00 2C */	stfs f2, 0x2c(r30)
/* 803E7444 003E4384  D0 5E 00 30 */	stfs f2, 0x30(r30)
/* 803E7448 003E4388  D0 1E 00 34 */	stfs f0, 0x34(r30)
/* 803E744C 003E438C  D0 5E 00 38 */	stfs f2, 0x38(r30)
/* 803E7450 003E4390  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 803E7454 003E4394  C0 03 00 54 */	lfs f0, 0x54(r3)
/* 803E7458 003E4398  EC 22 00 24 */	fdivs f1, f2, f0
/* 803E745C 003E439C  4B CD A6 F1 */	bl __cvt_fp2unsigned
/* 803E7460 003E43A0  90 7E 00 3C */	stw r3, 0x3c(r30)
/* 803E7464 003E43A4  38 80 00 00 */	li r4, 0
/* 803E7468 003E43A8  38 00 FF FF */	li r0, -1
/* 803E746C 003E43AC  90 7E 00 40 */	stw r3, 0x40(r30)
/* 803E7470 003E43B0  90 9E 00 44 */	stw r4, 0x44(r30)
/* 803E7474 003E43B4  90 9E 00 48 */	stw r4, 0x48(r30)
/* 803E7478 003E43B8  90 9E 00 60 */	stw r4, 0x60(r30)
/* 803E747C 003E43BC  90 1E 00 64 */	stw r0, 0x64(r30)
.L_803E7480:
/* 803E7480 003E43C0  93 DF 02 0C */	stw r30, 0x20c(r31)
/* 803E7484 003E43C4  7F E3 FB 78 */	mr r3, r31
/* 803E7488 003E43C8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 803E748C 003E43CC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 803E7490 003E43D0  83 C1 00 08 */	lwz r30, 8(r1)
/* 803E7494 003E43D4  7C 08 03 A6 */	mtlr r0
/* 803E7498 003E43D8  38 21 00 10 */	addi r1, r1, 0x10
/* 803E749C 003E43DC  4E 80 00 20 */	blr 
.endfn __ct__Q43ebi5title6Kogane4TMgrFv

.fn setArchive__Q43ebi5title6Kogane4TMgrFP10JKRArchive, global
/* 803E74A0 003E43E0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 803E74A4 003E43E4  7C 08 02 A6 */	mflr r0
/* 803E74A8 003E43E8  3C A0 80 49 */	lis r5, lbl_804975A4@ha
/* 803E74AC 003E43EC  90 01 00 14 */	stw r0, 0x14(r1)
/* 803E74B0 003E43F0  38 A5 75 A4 */	addi r5, r5, lbl_804975A4@l
/* 803E74B4 003E43F4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 803E74B8 003E43F8  7C 9F 23 78 */	mr r31, r4
/* 803E74BC 003E43FC  93 C1 00 08 */	stw r30, 8(r1)
/* 803E74C0 003E4400  7C 7E 1B 78 */	mr r30, r3
/* 803E74C4 003E4404  38 7E 00 1C */	addi r3, r30, 0x1c
/* 803E74C8 003E4408  4B FD 96 31 */	bl loadSettingFile__Q33ebi5title10TParamBaseFP10JKRArchivePc
/* 803E74CC 003E440C  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 803E74D0 003E4410  7F E4 FB 78 */	mr r4, r31
/* 803E74D4 003E4414  48 00 00 AD */	bl setArchive__Q43ebi5title6Kogane9TAnimatorFP10JKRArchive
/* 803E74D8 003E4418  80 01 00 14 */	lwz r0, 0x14(r1)
/* 803E74DC 003E441C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 803E74E0 003E4420  83 C1 00 08 */	lwz r30, 8(r1)
/* 803E74E4 003E4424  7C 08 03 A6 */	mtlr r0
/* 803E74E8 003E4428  38 21 00 10 */	addi r1, r1, 0x10
/* 803E74EC 003E442C  4E 80 00 20 */	blr 
.endfn setArchive__Q43ebi5title6Kogane4TMgrFP10JKRArchive

.fn initUnit__Q43ebi5title6Kogane4TMgrFv, global
/* 803E74F0 003E4430  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 803E74F4 003E4434  7C 08 02 A6 */	mflr r0
/* 803E74F8 003E4438  7C 64 1B 78 */	mr r4, r3
/* 803E74FC 003E443C  90 01 00 14 */	stw r0, 0x14(r1)
/* 803E7500 003E4440  80 63 02 0C */	lwz r3, 0x20c(r3)
/* 803E7504 003E4444  48 00 01 A1 */	bl init__Q43ebi5title6Kogane5TUnitFPQ43ebi5title6Kogane4TMgr
/* 803E7508 003E4448  80 01 00 14 */	lwz r0, 0x14(r1)
/* 803E750C 003E444C  7C 08 03 A6 */	mtlr r0
/* 803E7510 003E4450  38 21 00 10 */	addi r1, r1, 0x10
/* 803E7514 003E4454  4E 80 00 20 */	blr 
.endfn initUnit__Q43ebi5title6Kogane4TMgrFv

.fn __ct__Q43ebi5title6Kogane9TAnimatorFv, global
/* 803E7518 003E4458  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 803E751C 003E445C  7C 08 02 A6 */	mflr r0
/* 803E7520 003E4460  3C 80 80 4F */	lis r4, __vt__Q23ebi17E3DAnimFolderBase@ha
/* 803E7524 003E4464  38 A0 00 00 */	li r5, 0
/* 803E7528 003E4468  90 01 00 14 */	stw r0, 0x14(r1)
/* 803E752C 003E446C  38 04 9E 54 */	addi r0, r4, __vt__Q23ebi17E3DAnimFolderBase@l
/* 803E7530 003E4470  3C 80 80 3F */	lis r4, __ct__Q23ebi10E3DAnimResFv@ha
/* 803E7534 003E4474  38 C0 00 20 */	li r6, 0x20
/* 803E7538 003E4478  93 E1 00 0C */	stw r31, 0xc(r1)
/* 803E753C 003E447C  7C 7F 1B 78 */	mr r31, r3
/* 803E7540 003E4480  3C 60 80 4F */	lis r3, __vt__Q43ebi5title6Kogane11TAnimFolder@ha
/* 803E7544 003E4484  38 84 85 AC */	addi r4, r4, __ct__Q23ebi10E3DAnimResFv@l
/* 803E7548 003E4488  90 1F 00 00 */	stw r0, 0(r31)
/* 803E754C 003E448C  38 03 9E 48 */	addi r0, r3, __vt__Q43ebi5title6Kogane11TAnimFolder@l
/* 803E7550 003E4490  38 7F 00 04 */	addi r3, r31, 4
/* 803E7554 003E4494  38 E0 00 02 */	li r7, 2
/* 803E7558 003E4498  90 1F 00 00 */	stw r0, 0(r31)
/* 803E755C 003E449C  4B CD A2 E1 */	bl __construct_array
/* 803E7560 003E44A0  38 00 00 00 */	li r0, 0
/* 803E7564 003E44A4  7F E3 FB 78 */	mr r3, r31
/* 803E7568 003E44A8  90 1F 00 44 */	stw r0, 0x44(r31)
/* 803E756C 003E44AC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 803E7570 003E44B0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 803E7574 003E44B4  7C 08 03 A6 */	mtlr r0
/* 803E7578 003E44B8  38 21 00 10 */	addi r1, r1, 0x10
/* 803E757C 003E44BC  4E 80 00 20 */	blr 
.endfn __ct__Q43ebi5title6Kogane9TAnimatorFv

.fn setArchive__Q43ebi5title6Kogane9TAnimatorFP10JKRArchive, global
/* 803E7580 003E44C0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 803E7584 003E44C4  7C 08 02 A6 */	mflr r0
/* 803E7588 003E44C8  90 01 00 24 */	stw r0, 0x24(r1)
/* 803E758C 003E44CC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 803E7590 003E44D0  7C 9F 23 78 */	mr r31, r4
/* 803E7594 003E44D4  3C 80 80 49 */	lis r4, lbl_804974A0@ha
/* 803E7598 003E44D8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 803E759C 003E44DC  7C 7E 1B 78 */	mr r30, r3
/* 803E75A0 003E44E0  7F E3 FB 78 */	mr r3, r31
/* 803E75A4 003E44E4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 803E75A8 003E44E8  3B A4 74 A0 */	addi r29, r4, lbl_804974A0@l
/* 803E75AC 003E44EC  38 9D 01 4C */	addi r4, r29, 0x14c
/* 803E75B0 003E44F0  93 81 00 10 */	stw r28, 0x10(r1)
/* 803E75B4 003E44F4  81 9F 00 00 */	lwz r12, 0(r31)
/* 803E75B8 003E44F8  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 803E75BC 003E44FC  7D 89 03 A6 */	mtctr r12
/* 803E75C0 003E4500  4E 80 04 21 */	bctrl 
/* 803E75C4 003E4504  7C 7C 1B 79 */	or. r28, r3, r3
/* 803E75C8 003E4508  40 82 00 18 */	bne .L_803E75E0
/* 803E75CC 003E450C  38 7D 01 64 */	addi r3, r29, 0x164
/* 803E75D0 003E4510  38 BD 01 7C */	addi r5, r29, 0x17c
/* 803E75D4 003E4514  38 80 00 75 */	li r4, 0x75
/* 803E75D8 003E4518  4C C6 31 82 */	crclr 6
/* 803E75DC 003E451C  4B C4 30 65 */	bl panic_f__12JUTExceptionFPCciPCce
.L_803E75E0:
/* 803E75E0 003E4520  3C 80 00 24 */	lis r4, 0x00240030@ha
/* 803E75E4 003E4524  7F 83 E3 78 */	mr r3, r28
/* 803E75E8 003E4528  38 84 00 30 */	addi r4, r4, 0x00240030@l
/* 803E75EC 003E452C  4B C8 82 A9 */	bl load__22J3DModelLoaderDataBaseFPCvUl
/* 803E75F0 003E4530  90 7E 00 44 */	stw r3, 0x44(r30)
/* 803E75F4 003E4534  38 A0 00 00 */	li r5, 0
/* 803E75F8 003E4538  48 00 00 24 */	b .L_803E761C
.L_803E75FC:
/* 803E75FC 003E453C  80 63 00 80 */	lwz r3, 0x80(r3)
/* 803E7600 003E4540  54 A0 13 BA */	rlwinm r0, r5, 2, 0xe, 0x1d
/* 803E7604 003E4544  38 A5 00 01 */	addi r5, r5, 1
/* 803E7608 003E4548  7C 63 00 2E */	lwzx r3, r3, r0
/* 803E760C 003E454C  80 03 00 0C */	lwz r0, 0xc(r3)
/* 803E7610 003E4550  54 00 05 1E */	rlwinm r0, r0, 0, 0x14, 0xf
/* 803E7614 003E4554  60 00 20 00 */	ori r0, r0, 0x2000
/* 803E7618 003E4558  90 03 00 0C */	stw r0, 0xc(r3)
.L_803E761C:
/* 803E761C 003E455C  80 7E 00 44 */	lwz r3, 0x44(r30)
/* 803E7620 003E4560  54 A0 04 3E */	clrlwi r0, r5, 0x10
/* 803E7624 003E4564  A0 83 00 7C */	lhz r4, 0x7c(r3)
/* 803E7628 003E4568  7C 00 20 40 */	cmplw r0, r4
/* 803E762C 003E456C  41 80 FF D0 */	blt .L_803E75FC
/* 803E7630 003E4570  3C 80 00 04 */	lis r4, 4
/* 803E7634 003E4574  4B C9 C2 A5 */	bl newSharedDisplayList__12J3DModelDataFUl
/* 803E7638 003E4578  80 7E 00 44 */	lwz r3, 0x44(r30)
/* 803E763C 003E457C  4B C9 C3 F5 */	bl makeSharedDL__12J3DModelDataFv
/* 803E7640 003E4580  83 9E 00 44 */	lwz r28, 0x44(r30)
/* 803E7644 003E4584  7F E5 FB 78 */	mr r5, r31
/* 803E7648 003E4588  38 7E 00 04 */	addi r3, r30, 4
/* 803E764C 003E458C  38 DD 01 1C */	addi r6, r29, 0x11c
/* 803E7650 003E4590  7F 84 E3 78 */	mr r4, r28
/* 803E7654 003E4594  4B FE 26 BD */	bl load__Q23ebi10E3DAnimResFP12J3DModelDataP10JKRArchivePc
/* 803E7658 003E4598  38 00 00 01 */	li r0, 1
/* 803E765C 003E459C  7F 84 E3 78 */	mr r4, r28
/* 803E7660 003E45A0  90 1E 00 20 */	stw r0, 0x20(r30)
/* 803E7664 003E45A4  7F E5 FB 78 */	mr r5, r31
/* 803E7668 003E45A8  38 7E 00 24 */	addi r3, r30, 0x24
/* 803E766C 003E45AC  38 DD 01 34 */	addi r6, r29, 0x134
/* 803E7670 003E45B0  4B FE 26 A1 */	bl load__Q23ebi10E3DAnimResFP12J3DModelDataP10JKRArchivePc
/* 803E7674 003E45B4  38 00 00 01 */	li r0, 1
/* 803E7678 003E45B8  90 1E 00 40 */	stw r0, 0x40(r30)
/* 803E767C 003E45BC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 803E7680 003E45C0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 803E7684 003E45C4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 803E7688 003E45C8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 803E768C 003E45CC  83 81 00 10 */	lwz r28, 0x10(r1)
/* 803E7690 003E45D0  7C 08 03 A6 */	mtlr r0
/* 803E7694 003E45D4  38 21 00 20 */	addi r1, r1, 0x20
/* 803E7698 003E45D8  4E 80 00 20 */	blr 
.endfn setArchive__Q43ebi5title6Kogane9TAnimatorFP10JKRArchive

.fn setController__Q43ebi5title6Kogane5TUnitFP10Controller, global
/* 803E769C 003E45DC  90 83 00 44 */	stw r4, 0x44(r3)
/* 803E76A0 003E45E0  4E 80 00 20 */	blr 
.endfn setController__Q43ebi5title6Kogane5TUnitFP10Controller

.fn init__Q43ebi5title6Kogane5TUnitFPQ43ebi5title6Kogane4TMgr global
/* 803E76A4 003E45E4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 803E76A8 003E45E8  7C 08 02 A6 */	mflr r0
/* 803E76AC 003E45EC  90 01 00 24 */	stw r0, 0x24(r1)
/* 803E76B0 003E45F0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 803E76B4 003E45F4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 803E76B8 003E45F8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 803E76BC 003E45FC  7C 7D 1B 78 */	mr r29, r3
/* 803E76C0 003E4600  38 60 00 DC */	li r3, 0xdc
/* 803E76C4 003E4604  90 9D 00 48 */	stw r4, 0x48(r29)
/* 803E76C8 003E4608  80 9D 00 48 */	lwz r4, 0x48(r29)
/* 803E76CC 003E460C  83 E4 00 18 */	lwz r31, 0x18(r4)
/* 803E76D0 003E4610  4B C3 C7 D5 */	bl __nw__FUl
/* 803E76D4 003E4614  7C 7E 1B 79 */	or. r30, r3, r3
/* 803E76D8 003E4618  41 82 00 38 */	beq .L_803E7710
/* 803E76DC 003E461C  3C 60 80 4A */	lis r3, __vt__8J3DModel@ha
/* 803E76E0 003E4620  83 FF 00 44 */	lwz r31, 0x44(r31)
/* 803E76E4 003E4624  38 03 19 F0 */	addi r0, r3, __vt__8J3DModel@l
/* 803E76E8 003E4628  90 1E 00 00 */	stw r0, 0(r30)
/* 803E76EC 003E462C  38 7E 00 88 */	addi r3, r30, 0x88
/* 803E76F0 003E4630  4B C7 75 59 */	bl init__15J3DVertexBufferFv
/* 803E76F4 003E4634  7F C3 F3 78 */	mr r3, r30
/* 803E76F8 003E4638  4B C7 EC 05 */	bl initialize__8J3DModelFv
/* 803E76FC 003E463C  7F C3 F3 78 */	mr r3, r30
/* 803E7700 003E4640  7F E4 FB 78 */	mr r4, r31
/* 803E7704 003E4644  3C A0 00 02 */	lis r5, 2
/* 803E7708 003E4648  38 C0 00 01 */	li r6, 1
/* 803E770C 003E464C  4B C7 EC 75 */	bl entryModelData__8J3DModelFP12J3DModelDataUlUl
.L_803E7710:
/* 803E7710 003E4650  93 DD 00 28 */	stw r30, 0x28(r29)
/* 803E7714 003E4654  38 7D 00 4C */	addi r3, r29, 0x4c
/* 803E7718 003E4658  80 9D 00 48 */	lwz r4, 0x48(r29)
/* 803E771C 003E465C  80 84 00 18 */	lwz r4, 0x18(r4)
/* 803E7720 003E4660  4B FE 26 F5 */	bl setAnimFolder__Q23ebi11E3DAnimCtrlFPQ23ebi17E3DAnimFolderBase
/* 803E7724 003E4664  80 8D 9A 28 */	lwz r4, titleMgr__Q23ebi5title@sda21(r13)
/* 803E7728 003E4668  38 61 00 08 */	addi r3, r1, 8
/* 803E772C 003E466C  4B FD 79 4D */	bl getPosOutOfViewField__Q33ebi5title9TTitleMgrFv
/* 803E7730 003E4670  C0 01 00 08 */	lfs f0, 8(r1)
/* 803E7734 003E4674  D0 1D 00 04 */	stfs f0, 4(r29)
/* 803E7738 003E4678  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 803E773C 003E467C  D0 1D 00 08 */	stfs f0, 8(r29)
/* 803E7740 003E4680  80 7D 00 48 */	lwz r3, 0x48(r29)
/* 803E7744 003E4684  C0 03 01 08 */	lfs f0, 0x108(r3)
/* 803E7748 003E4688  D0 1D 00 14 */	stfs f0, 0x14(r29)
/* 803E774C 003E468C  80 7D 00 48 */	lwz r3, 0x48(r29)
/* 803E7750 003E4690  C0 03 00 40 */	lfs f0, 0x40(r3)
/* 803E7754 003E4694  D0 1D 00 18 */	stfs f0, 0x18(r29)
/* 803E7758 003E4698  80 7D 00 48 */	lwz r3, 0x48(r29)
/* 803E775C 003E469C  C0 03 00 68 */	lfs f0, 0x68(r3)
/* 803E7760 003E46A0  D0 1D 00 24 */	stfs f0, 0x24(r29)
/* 803E7764 003E46A4  80 7D 00 48 */	lwz r3, 0x48(r29)
/* 803E7768 003E46A8  C0 03 00 90 */	lfs f0, 0x90(r3)
/* 803E776C 003E46AC  D0 1D 00 1C */	stfs f0, 0x1c(r29)
/* 803E7770 003E46B0  80 7D 00 48 */	lwz r3, 0x48(r29)
/* 803E7774 003E46B4  C0 03 00 B8 */	lfs f0, 0xb8(r3)
/* 803E7778 003E46B8  D0 1D 00 20 */	stfs f0, 0x20(r29)
/* 803E777C 003E46BC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 803E7780 003E46C0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 803E7784 003E46C4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 803E7788 003E46C8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 803E778C 003E46CC  7C 08 03 A6 */	mtlr r0
/* 803E7790 003E46D0  38 21 00 20 */	addi r1, r1, 0x20
/* 803E7794 003E46D4  4E 80 00 20 */	blr 
.endfn init__Q43ebi5title6Kogane5TUnitFPQ43ebi5title6Kogane4TMgr

.fn startZigzagWalk__Q43ebi5title6Kogane5TUnitFR10Vector2<f>R10Vector2<f>, global
/* 803E7798 003E46D8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 803E779C 003E46DC  7C 08 02 A6 */	mflr r0
/* 803E77A0 003E46E0  90 01 00 14 */	stw r0, 0x14(r1)
/* 803E77A4 003E46E4  38 00 FF FF */	li r0, -1
/* 803E77A8 003E46E8  C0 04 00 00 */	lfs f0, 0(r4)
/* 803E77AC 003E46EC  D0 03 00 04 */	stfs f0, 4(r3)
/* 803E77B0 003E46F0  C0 04 00 04 */	lfs f0, 4(r4)
/* 803E77B4 003E46F4  38 80 00 04 */	li r4, 4
/* 803E77B8 003E46F8  D0 03 00 08 */	stfs f0, 8(r3)
/* 803E77BC 003E46FC  C0 05 00 00 */	lfs f0, 0(r5)
/* 803E77C0 003E4700  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 803E77C4 003E4704  C0 05 00 04 */	lfs f0, 4(r5)
/* 803E77C8 003E4708  D0 03 00 30 */	stfs f0, 0x30(r3)
/* 803E77CC 003E470C  90 03 00 64 */	stw r0, 0x64(r3)
/* 803E77D0 003E4710  48 00 00 91 */	bl startState__Q43ebi5title6Kogane5TUnitFQ53ebi5title6Kogane5TUnit9enumState
/* 803E77D4 003E4714  80 01 00 14 */	lwz r0, 0x14(r1)
/* 803E77D8 003E4718  7C 08 03 A6 */	mtlr r0
/* 803E77DC 003E471C  38 21 00 10 */	addi r1, r1, 0x10
/* 803E77E0 003E4720  4E 80 00 20 */	blr 
.endfn startZigzagWalk__Q43ebi5title6Kogane5TUnitFR10Vector2<f>R10Vector2<f>

.fn goHome__Q43ebi5title6Kogane5TUnitFv, global
/* 803E77E4 003E4724  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 803E77E8 003E4728  7C 08 02 A6 */	mflr r0
/* 803E77EC 003E472C  90 01 00 14 */	stw r0, 0x14(r1)
/* 803E77F0 003E4730  80 03 00 60 */	lwz r0, 0x60(r3)
/* 803E77F4 003E4734  2C 00 00 00 */	cmpwi r0, 0
/* 803E77F8 003E4738  41 82 00 0C */	beq .L_803E7804
/* 803E77FC 003E473C  38 80 00 05 */	li r4, 5
/* 803E7800 003E4740  48 00 00 61 */	bl startState__Q43ebi5title6Kogane5TUnitFQ53ebi5title6Kogane5TUnit9enumState
.L_803E7804:
/* 803E7804 003E4744  80 01 00 14 */	lwz r0, 0x14(r1)
/* 803E7808 003E4748  7C 08 03 A6 */	mtlr r0
/* 803E780C 003E474C  38 21 00 10 */	addi r1, r1, 0x10
/* 803E7810 003E4750  4E 80 00 20 */	blr 
.endfn goHome__Q43ebi5title6Kogane5TUnitFv

.fn outOfCalc__Q43ebi5title6Kogane5TUnitFv, global
/* 803E7814 003E4754  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 803E7818 003E4758  7C 08 02 A6 */	mflr r0
/* 803E781C 003E475C  38 80 00 00 */	li r4, 0
/* 803E7820 003E4760  90 01 00 14 */	stw r0, 0x14(r1)
/* 803E7824 003E4764  48 00 00 3D */	bl startState__Q43ebi5title6Kogane5TUnitFQ53ebi5title6Kogane5TUnit9enumState
/* 803E7828 003E4768  80 01 00 14 */	lwz r0, 0x14(r1)
/* 803E782C 003E476C  7C 08 03 A6 */	mtlr r0
/* 803E7830 003E4770  38 21 00 10 */	addi r1, r1, 0x10
/* 803E7834 003E4774  4E 80 00 20 */	blr 
.endfn outOfCalc__Q43ebi5title6Kogane5TUnitFv

.fn isCalc__Q43ebi5title6Kogane5TUnitFv, global
/* 803E7838 003E4778  80 63 00 60 */	lwz r3, 0x60(r3)
/* 803E783C 003E477C  7C 03 00 D0 */	neg r0, r3
/* 803E7840 003E4780  7C 00 1B 78 */	or r0, r0, r3
/* 803E7844 003E4784  54 03 0F FE */	srwi r3, r0, 0x1f
/* 803E7848 003E4788  4E 80 00 20 */	blr 
.endfn isCalc__Q43ebi5title6Kogane5TUnitFv

.fn isController__Q43ebi5title6Kogane5TUnitFv, global
/* 803E784C 003E478C  80 03 00 60 */	lwz r0, 0x60(r3)
/* 803E7850 003E4790  20 00 00 06 */	subfic r0, r0, 6
/* 803E7854 003E4794  7C 00 00 34 */	cntlzw r0, r0
/* 803E7858 003E4798  54 03 DE 3E */	rlwinm r3, r0, 0x1b, 0x18, 0x1f
/* 803E785C 003E479C  4E 80 00 20 */	blr 
.endfn isController__Q43ebi5title6Kogane5TUnitFv

.fn startState__Q43ebi5title6Kogane5TUnitFQ53ebi5title6Kogane5TUnit9enumState, global
/* 803E7860 003E47A0  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 803E7864 003E47A4  7C 08 02 A6 */	mflr r0
/* 803E7868 003E47A8  90 01 00 64 */	stw r0, 0x64(r1)
/* 803E786C 003E47AC  DB E1 00 50 */	stfd f31, 0x50(r1)
/* 803E7870 003E47B0  F3 E1 00 58 */	psq_st f31, 88(r1), 0, qr0
/* 803E7874 003E47B4  DB C1 00 40 */	stfd f30, 0x40(r1)
/* 803E7878 003E47B8  F3 C1 00 48 */	psq_st f30, 72(r1), 0, qr0
/* 803E787C 003E47BC  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 803E7880 003E47C0  7C 7F 1B 78 */	mr r31, r3
/* 803E7884 003E47C4  28 04 00 06 */	cmplwi r4, 6
/* 803E7888 003E47C8  90 83 00 60 */	stw r4, 0x60(r3)
/* 803E788C 003E47CC  41 81 02 80 */	bgt .L_803E7B0C
/* 803E7890 003E47D0  3C 60 80 4F */	lis r3, lbl_804E9E1C@ha
/* 803E7894 003E47D4  54 80 10 3A */	slwi r0, r4, 2
/* 803E7898 003E47D8  38 63 9E 1C */	addi r3, r3, lbl_804E9E1C@l
/* 803E789C 003E47DC  7C 03 00 2E */	lwzx r0, r3, r0
/* 803E78A0 003E47E0  7C 09 03 A6 */	mtctr r0
/* 803E78A4 003E47E4  4E 80 04 20 */	bctr 
.L_803E78A8:
/* 803E78A8 003E47E8  80 8D 9A 28 */	lwz r4, titleMgr__Q23ebi5title@sda21(r13)
/* 803E78AC 003E47EC  38 61 00 08 */	addi r3, r1, 8
/* 803E78B0 003E47F0  4B FD 77 C9 */	bl getPosOutOfViewField__Q33ebi5title9TTitleMgrFv
/* 803E78B4 003E47F4  C0 01 00 08 */	lfs f0, 8(r1)
/* 803E78B8 003E47F8  D0 1F 00 04 */	stfs f0, 4(r31)
/* 803E78BC 003E47FC  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 803E78C0 003E4800  D0 1F 00 08 */	stfs f0, 8(r31)
.L_803E78C4:
/* 803E78C4 003E4804  80 9F 00 48 */	lwz r4, 0x48(r31)
/* 803E78C8 003E4808  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 803E78CC 003E480C  C0 24 01 F8 */	lfs f1, 0x1f8(r4)
/* 803E78D0 003E4810  C0 03 00 54 */	lfs f0, 0x54(r3)
/* 803E78D4 003E4814  EC 21 00 24 */	fdivs f1, f1, f0
/* 803E78D8 003E4818  4B CD A2 75 */	bl __cvt_fp2unsigned
/* 803E78DC 003E481C  90 7F 00 3C */	stw r3, 0x3c(r31)
/* 803E78E0 003E4820  90 7F 00 40 */	stw r3, 0x40(r31)
/* 803E78E4 003E4824  48 00 02 28 */	b .L_803E7B0C
.L_803E78E8:
/* 803E78E8 003E4828  80 7F 00 48 */	lwz r3, 0x48(r31)
/* 803E78EC 003E482C  C3 C3 01 58 */	lfs f30, 0x158(r3)
/* 803E78F0 003E4830  C3 E3 01 80 */	lfs f31, 0x180(r3)
/* 803E78F4 003E4834  4B CE 1C AD */	bl rand
/* 803E78F8 003E4838  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 803E78FC 003E483C  3C 00 43 30 */	lis r0, 0x4330
/* 803E7900 003E4840  90 61 00 14 */	stw r3, 0x14(r1)
/* 803E7904 003E4844  EC 3F F0 28 */	fsubs f1, f31, f30
/* 803E7908 003E4848  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 803E790C 003E484C  90 01 00 10 */	stw r0, 0x10(r1)
/* 803E7910 003E4850  C8 62 19 F8 */	lfd f3, lbl_8051FD58@sda21(r2)
/* 803E7914 003E4854  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 803E7918 003E4858  C0 42 19 E4 */	lfs f2, lbl_8051FD44@sda21(r2)
/* 803E791C 003E485C  EC 60 18 28 */	fsubs f3, f0, f3
/* 803E7920 003E4860  C0 03 00 54 */	lfs f0, 0x54(r3)
/* 803E7924 003E4864  EC 43 10 24 */	fdivs f2, f3, f2
/* 803E7928 003E4868  EC 21 F0 BA */	fmadds f1, f1, f2, f30
/* 803E792C 003E486C  EC 21 00 24 */	fdivs f1, f1, f0
/* 803E7930 003E4870  4B CD A2 1D */	bl __cvt_fp2unsigned
/* 803E7934 003E4874  90 7F 00 3C */	stw r3, 0x3c(r31)
/* 803E7938 003E4878  90 7F 00 40 */	stw r3, 0x40(r31)
/* 803E793C 003E487C  48 00 01 D0 */	b .L_803E7B0C
.L_803E7940:
/* 803E7940 003E4880  C0 3F 00 30 */	lfs f1, 0x30(r31)
/* 803E7944 003E4884  3C 60 80 51 */	lis r3, atanTable___5JMath@ha
/* 803E7948 003E4888  C0 1F 00 08 */	lfs f0, 8(r31)
/* 803E794C 003E488C  38 63 D1 E0 */	addi r3, r3, atanTable___5JMath@l
/* 803E7950 003E4890  C0 5F 00 2C */	lfs f2, 0x2c(r31)
/* 803E7954 003E4894  EC 21 00 28 */	fsubs f1, f1, f0
/* 803E7958 003E4898  C0 1F 00 04 */	lfs f0, 4(r31)
/* 803E795C 003E489C  80 9F 00 48 */	lwz r4, 0x48(r31)
/* 803E7960 003E48A0  EC 42 00 28 */	fsubs f2, f2, f0
/* 803E7964 003E48A4  C3 C4 00 E0 */	lfs f30, 0xe0(r4)
/* 803E7968 003E48A8  4B C4 D7 A1 */	bl "atan2___Q25JMath18TAtanTable<1024,f>CFff"
/* 803E796C 003E48AC  FF E0 08 90 */	fmr f31, f1
/* 803E7970 003E48B0  4B CE 1C 31 */	bl rand
/* 803E7974 003E48B4  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 803E7978 003E48B8  3C 00 43 30 */	lis r0, 0x4330
/* 803E797C 003E48BC  90 61 00 14 */	stw r3, 0x14(r1)
/* 803E7980 003E48C0  C0 02 19 EC */	lfs f0, lbl_8051FD4C@sda21(r2)
/* 803E7984 003E48C4  90 01 00 10 */	stw r0, 0x10(r1)
/* 803E7988 003E48C8  C8 42 19 F8 */	lfd f2, lbl_8051FD58@sda21(r2)
/* 803E798C 003E48CC  EC 00 07 B2 */	fmuls f0, f0, f30
/* 803E7990 003E48D0  C8 21 00 10 */	lfd f1, 0x10(r1)
/* 803E7994 003E48D4  C0 82 19 E4 */	lfs f4, lbl_8051FD44@sda21(r2)
/* 803E7998 003E48D8  EC A1 10 28 */	fsubs f5, f1, f2
/* 803E799C 003E48DC  C0 62 19 E8 */	lfs f3, lbl_8051FD48@sda21(r2)
/* 803E79A0 003E48E0  C0 42 19 B4 */	lfs f2, lbl_8051FD14@sda21(r2)
/* 803E79A4 003E48E4  C0 22 19 A4 */	lfs f1, lbl_8051FD04@sda21(r2)
/* 803E79A8 003E48E8  EC 63 00 32 */	fmuls f3, f3, f0
/* 803E79AC 003E48EC  EC 85 20 24 */	fdivs f4, f5, f4
/* 803E79B0 003E48F0  C0 02 19 A0 */	lfs f0, lbl_8051FD00@sda21(r2)
/* 803E79B4 003E48F4  EC 22 09 3A */	fmadds f1, f2, f4, f1
/* 803E79B8 003E48F8  EC 43 F8 7A */	fmadds f2, f3, f1, f31
/* 803E79BC 003E48FC  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 803E79C0 003E4900  40 80 00 30 */	bge .L_803E79F0
/* 803E79C4 003E4904  C0 02 19 F0 */	lfs f0, lbl_8051FD50@sda21(r2)
/* 803E79C8 003E4908  3C 60 80 50 */	lis r3, sincosTable___5JMath@ha
/* 803E79CC 003E490C  38 63 71 A0 */	addi r3, r3, sincosTable___5JMath@l
/* 803E79D0 003E4910  EC 02 00 32 */	fmuls f0, f2, f0
/* 803E79D4 003E4914  FC 00 00 1E */	fctiwz f0, f0
/* 803E79D8 003E4918  D8 01 00 18 */	stfd f0, 0x18(r1)
/* 803E79DC 003E491C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 803E79E0 003E4920  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 803E79E4 003E4924  7C 03 04 2E */	lfsx f0, r3, r0
/* 803E79E8 003E4928  FC 20 00 50 */	fneg f1, f0
/* 803E79EC 003E492C  48 00 00 28 */	b .L_803E7A14
.L_803E79F0:
/* 803E79F0 003E4930  C0 02 19 F4 */	lfs f0, lbl_8051FD54@sda21(r2)
/* 803E79F4 003E4934  3C 60 80 50 */	lis r3, sincosTable___5JMath@ha
/* 803E79F8 003E4938  38 63 71 A0 */	addi r3, r3, sincosTable___5JMath@l
/* 803E79FC 003E493C  EC 02 00 32 */	fmuls f0, f2, f0
/* 803E7A00 003E4940  FC 00 00 1E */	fctiwz f0, f0
/* 803E7A04 003E4944  D8 01 00 20 */	stfd f0, 0x20(r1)
/* 803E7A08 003E4948  80 01 00 24 */	lwz r0, 0x24(r1)
/* 803E7A0C 003E494C  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 803E7A10 003E4950  7C 23 04 2E */	lfsx f1, r3, r0
.L_803E7A14:
/* 803E7A14 003E4954  C0 02 19 A0 */	lfs f0, lbl_8051FD00@sda21(r2)
/* 803E7A18 003E4958  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 803E7A1C 003E495C  40 80 00 08 */	bge .L_803E7A24
/* 803E7A20 003E4960  FC 40 10 50 */	fneg f2, f2
.L_803E7A24:
/* 803E7A24 003E4964  C0 02 19 F4 */	lfs f0, lbl_8051FD54@sda21(r2)
/* 803E7A28 003E4968  3C 60 80 50 */	lis r3, sincosTable___5JMath@ha
/* 803E7A2C 003E496C  38 63 71 A0 */	addi r3, r3, sincosTable___5JMath@l
/* 803E7A30 003E4970  EC 02 00 32 */	fmuls f0, f2, f0
/* 803E7A34 003E4974  FC 00 00 1E */	fctiwz f0, f0
/* 803E7A38 003E4978  D8 01 00 28 */	stfd f0, 0x28(r1)
/* 803E7A3C 003E497C  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 803E7A40 003E4980  54 00 1C B8 */	rlwinm r0, r0, 3, 0x12, 0x1c
/* 803E7A44 003E4984  7C 63 02 14 */	add r3, r3, r0
/* 803E7A48 003E4988  C0 03 00 04 */	lfs f0, 4(r3)
/* 803E7A4C 003E498C  D0 1F 00 34 */	stfs f0, 0x34(r31)
/* 803E7A50 003E4990  D0 3F 00 38 */	stfs f1, 0x38(r31)
/* 803E7A54 003E4994  48 00 00 B8 */	b .L_803E7B0C
.L_803E7A58:
/* 803E7A58 003E4998  80 7F 00 48 */	lwz r3, 0x48(r31)
/* 803E7A5C 003E499C  C3 C3 01 D0 */	lfs f30, 0x1d0(r3)
/* 803E7A60 003E49A0  C3 E3 01 A8 */	lfs f31, 0x1a8(r3)
/* 803E7A64 003E49A4  4B CE 1B 3D */	bl rand
/* 803E7A68 003E49A8  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 803E7A6C 003E49AC  3C 00 43 30 */	lis r0, 0x4330
/* 803E7A70 003E49B0  90 61 00 2C */	stw r3, 0x2c(r1)
/* 803E7A74 003E49B4  EC 3E F8 28 */	fsubs f1, f30, f31
/* 803E7A78 003E49B8  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 803E7A7C 003E49BC  90 01 00 28 */	stw r0, 0x28(r1)
/* 803E7A80 003E49C0  C8 62 19 F8 */	lfd f3, lbl_8051FD58@sda21(r2)
/* 803E7A84 003E49C4  C8 01 00 28 */	lfd f0, 0x28(r1)
/* 803E7A88 003E49C8  C0 42 19 E4 */	lfs f2, lbl_8051FD44@sda21(r2)
/* 803E7A8C 003E49CC  EC 60 18 28 */	fsubs f3, f0, f3
/* 803E7A90 003E49D0  C0 03 00 54 */	lfs f0, 0x54(r3)
/* 803E7A94 003E49D4  EC 43 10 24 */	fdivs f2, f3, f2
/* 803E7A98 003E49D8  EC 21 F8 BA */	fmadds f1, f1, f2, f31
/* 803E7A9C 003E49DC  EC 21 00 24 */	fdivs f1, f1, f0
/* 803E7AA0 003E49E0  4B CD A0 AD */	bl __cvt_fp2unsigned
/* 803E7AA4 003E49E4  90 7F 00 3C */	stw r3, 0x3c(r31)
/* 803E7AA8 003E49E8  90 7F 00 40 */	stw r3, 0x40(r31)
/* 803E7AAC 003E49EC  48 00 00 60 */	b .L_803E7B0C
.L_803E7AB0:
/* 803E7AB0 003E49F0  C0 1F 00 08 */	lfs f0, 8(r31)
/* 803E7AB4 003E49F4  C0 3F 00 04 */	lfs f1, 4(r31)
/* 803E7AB8 003E49F8  FC 60 00 50 */	fneg f3, f0
/* 803E7ABC 003E49FC  C0 02 19 A0 */	lfs f0, lbl_8051FD00@sda21(r2)
/* 803E7AC0 003E4A00  FC 40 08 50 */	fneg f2, f1
/* 803E7AC4 003E4A04  EC 23 00 F2 */	fmuls f1, f3, f3
/* 803E7AC8 003E4A08  EC 22 08 BA */	fmadds f1, f2, f2, f1
/* 803E7ACC 003E4A0C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 803E7AD0 003E4A10  40 81 00 14 */	ble .L_803E7AE4
/* 803E7AD4 003E4A14  40 81 00 14 */	ble .L_803E7AE8
/* 803E7AD8 003E4A18  FC 00 08 34 */	frsqrte f0, f1
/* 803E7ADC 003E4A1C  EC 20 00 72 */	fmuls f1, f0, f1
/* 803E7AE0 003E4A20  48 00 00 08 */	b .L_803E7AE8
.L_803E7AE4:
/* 803E7AE4 003E4A24  FC 20 00 90 */	fmr f1, f0
.L_803E7AE8:
/* 803E7AE8 003E4A28  C0 02 19 A0 */	lfs f0, lbl_8051FD00@sda21(r2)
/* 803E7AEC 003E4A2C  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 803E7AF0 003E4A30  41 82 00 14 */	beq .L_803E7B04
/* 803E7AF4 003E4A34  C0 02 19 A8 */	lfs f0, lbl_8051FD08@sda21(r2)
/* 803E7AF8 003E4A38  EC 00 08 24 */	fdivs f0, f0, f1
/* 803E7AFC 003E4A3C  EC 42 00 32 */	fmuls f2, f2, f0
/* 803E7B00 003E4A40  EC 63 00 32 */	fmuls f3, f3, f0
.L_803E7B04:
/* 803E7B04 003E4A44  D0 5F 00 0C */	stfs f2, 0xc(r31)
/* 803E7B08 003E4A48  D0 7F 00 10 */	stfs f3, 0x10(r31)
.L_803E7B0C:
/* 803E7B0C 003E4A4C  E3 E1 00 58 */	psq_l f31, 88(r1), 0, qr0
/* 803E7B10 003E4A50  CB E1 00 50 */	lfd f31, 0x50(r1)
/* 803E7B14 003E4A54  E3 C1 00 48 */	psq_l f30, 72(r1), 0, qr0
/* 803E7B18 003E4A58  CB C1 00 40 */	lfd f30, 0x40(r1)
/* 803E7B1C 003E4A5C  80 01 00 64 */	lwz r0, 0x64(r1)
/* 803E7B20 003E4A60  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 803E7B24 003E4A64  7C 08 03 A6 */	mtlr r0
/* 803E7B28 003E4A68  38 21 00 60 */	addi r1, r1, 0x60
/* 803E7B2C 003E4A6C  4E 80 00 20 */	blr 
.endfn startState__Q43ebi5title6Kogane5TUnitFQ53ebi5title6Kogane5TUnit9enumState

.fn update__Q43ebi5title6Kogane5TUnitFv, global
/* 803E7B30 003E4A70  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 803E7B34 003E4A74  7C 08 02 A6 */	mflr r0
/* 803E7B38 003E4A78  90 01 00 24 */	stw r0, 0x24(r1)
/* 803E7B3C 003E4A7C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 803E7B40 003E4A80  93 C1 00 18 */	stw r30, 0x18(r1)
/* 803E7B44 003E4A84  7C 7E 1B 78 */	mr r30, r3
/* 803E7B48 003E4A88  81 83 00 00 */	lwz r12, 0(r3)
/* 803E7B4C 003E4A8C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 803E7B50 003E4A90  7D 89 03 A6 */	mtctr r12
/* 803E7B54 003E4A94  4E 80 04 21 */	bctrl 
/* 803E7B58 003E4A98  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 803E7B5C 003E4A9C  41 82 06 F0 */	beq .L_803E824C
/* 803E7B60 003E4AA0  80 1E 00 60 */	lwz r0, 0x60(r30)
/* 803E7B64 003E4AA4  2C 00 00 00 */	cmpwi r0, 0
/* 803E7B68 003E4AA8  41 82 00 3C */	beq .L_803E7BA4
/* 803E7B6C 003E4AAC  2C 00 00 05 */	cmpwi r0, 5
/* 803E7B70 003E4AB0  41 82 00 34 */	beq .L_803E7BA4
/* 803E7B74 003E4AB4  2C 00 00 04 */	cmpwi r0, 4
/* 803E7B78 003E4AB8  41 82 00 2C */	beq .L_803E7BA4
/* 803E7B7C 003E4ABC  80 7E 00 44 */	lwz r3, 0x44(r30)
/* 803E7B80 003E4AC0  28 03 00 00 */	cmplwi r3, 0
/* 803E7B84 003E4AC4  41 82 00 20 */	beq .L_803E7BA4
/* 803E7B88 003E4AC8  C0 23 00 60 */	lfs f1, 0x60(r3)
/* 803E7B8C 003E4ACC  C0 02 1A 00 */	lfs f0, lbl_8051FD60@sda21(r2)
/* 803E7B90 003E4AD0  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 803E7B94 003E4AD4  40 81 00 10 */	ble .L_803E7BA4
/* 803E7B98 003E4AD8  7F C3 F3 78 */	mr r3, r30
/* 803E7B9C 003E4ADC  38 80 00 06 */	li r4, 6
/* 803E7BA0 003E4AE0  4B FF FC C1 */	bl startState__Q43ebi5title6Kogane5TUnitFQ53ebi5title6Kogane5TUnit9enumState
.L_803E7BA4:
/* 803E7BA4 003E4AE4  80 1E 00 60 */	lwz r0, 0x60(r30)
/* 803E7BA8 003E4AE8  83 FE 00 64 */	lwz r31, 0x64(r30)
/* 803E7BAC 003E4AEC  2C 00 00 04 */	cmpwi r0, 4
/* 803E7BB0 003E4AF0  41 82 03 2C */	beq .L_803E7EDC
/* 803E7BB4 003E4AF4  40 80 00 1C */	bge .L_803E7BD0
/* 803E7BB8 003E4AF8  2C 00 00 02 */	cmpwi r0, 2
/* 803E7BBC 003E4AFC  41 82 01 A4 */	beq .L_803E7D60
/* 803E7BC0 003E4B00  40 80 02 B4 */	bge .L_803E7E74
/* 803E7BC4 003E4B04  2C 00 00 01 */	cmpwi r0, 1
/* 803E7BC8 003E4B08  40 80 01 60 */	bge .L_803E7D28
/* 803E7BCC 003E4B0C  48 00 04 4C */	b .L_803E8018
.L_803E7BD0:
/* 803E7BD0 003E4B10  2C 00 00 06 */	cmpwi r0, 6
/* 803E7BD4 003E4B14  41 82 00 0C */	beq .L_803E7BE0
/* 803E7BD8 003E4B18  40 80 04 40 */	bge .L_803E8018
/* 803E7BDC 003E4B1C  48 00 03 A0 */	b .L_803E7F7C
.L_803E7BE0:
/* 803E7BE0 003E4B20  80 7E 00 3C */	lwz r3, 0x3c(r30)
/* 803E7BE4 003E4B24  28 03 00 00 */	cmplwi r3, 0
/* 803E7BE8 003E4B28  41 82 00 0C */	beq .L_803E7BF4
/* 803E7BEC 003E4B2C  38 03 FF FF */	addi r0, r3, -1
/* 803E7BF0 003E4B30  90 1E 00 3C */	stw r0, 0x3c(r30)
.L_803E7BF4:
/* 803E7BF4 003E4B34  38 00 00 00 */	li r0, 0
/* 803E7BF8 003E4B38  90 1E 00 64 */	stw r0, 0x64(r30)
/* 803E7BFC 003E4B3C  80 7E 00 44 */	lwz r3, 0x44(r30)
/* 803E7C00 003E4B40  28 03 00 00 */	cmplwi r3, 0
/* 803E7C04 003E4B44  41 82 01 08 */	beq .L_803E7D0C
/* 803E7C08 003E4B48  C0 43 00 58 */	lfs f2, 0x58(r3)
/* 803E7C0C 003E4B4C  C0 02 1A 00 */	lfs f0, lbl_8051FD60@sda21(r2)
/* 803E7C10 003E4B50  FC 20 12 10 */	fabs f1, f2
/* 803E7C14 003E4B54  FC 20 08 18 */	frsp f1, f1
/* 803E7C18 003E4B58  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 803E7C1C 003E4B5C  40 81 00 A4 */	ble .L_803E7CC0
/* 803E7C20 003E4B60  80 7E 00 48 */	lwz r3, 0x48(r30)
/* 803E7C24 003E4B64  C0 BE 00 0C */	lfs f5, 0xc(r30)
/* 803E7C28 003E4B68  C0 03 01 30 */	lfs f0, 0x130(r3)
/* 803E7C2C 003E4B6C  C0 9E 00 10 */	lfs f4, 0x10(r30)
/* 803E7C30 003E4B70  FC 20 28 50 */	fneg f1, f5
/* 803E7C34 003E4B74  EC 62 00 32 */	fmuls f3, f2, f0
/* 803E7C38 003E4B78  C0 02 19 A0 */	lfs f0, lbl_8051FD00@sda21(r2)
/* 803E7C3C 003E4B7C  EC 44 00 F2 */	fmuls f2, f4, f3
/* 803E7C40 003E4B80  EC 21 00 F2 */	fmuls f1, f1, f3
/* 803E7C44 003E4B84  EC 45 10 2A */	fadds f2, f5, f2
/* 803E7C48 003E4B88  EC 24 08 2A */	fadds f1, f4, f1
/* 803E7C4C 003E4B8C  D0 5E 00 0C */	stfs f2, 0xc(r30)
/* 803E7C50 003E4B90  D0 3E 00 10 */	stfs f1, 0x10(r30)
/* 803E7C54 003E4B94  C0 7E 00 0C */	lfs f3, 0xc(r30)
/* 803E7C58 003E4B98  C0 5E 00 10 */	lfs f2, 0x10(r30)
/* 803E7C5C 003E4B9C  EC 23 00 F2 */	fmuls f1, f3, f3
/* 803E7C60 003E4BA0  EC 42 00 B2 */	fmuls f2, f2, f2
/* 803E7C64 003E4BA4  EC 21 10 2A */	fadds f1, f1, f2
/* 803E7C68 003E4BA8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 803E7C6C 003E4BAC  40 81 00 1C */	ble .L_803E7C88
/* 803E7C70 003E4BB0  EC 43 10 FA */	fmadds f2, f3, f3, f2
/* 803E7C74 003E4BB4  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 803E7C78 003E4BB8  40 81 00 14 */	ble .L_803E7C8C
/* 803E7C7C 003E4BBC  FC 00 10 34 */	frsqrte f0, f2
/* 803E7C80 003E4BC0  EC 40 00 B2 */	fmuls f2, f0, f2
/* 803E7C84 003E4BC4  48 00 00 08 */	b .L_803E7C8C
.L_803E7C88:
/* 803E7C88 003E4BC8  FC 40 00 90 */	fmr f2, f0
.L_803E7C8C:
/* 803E7C8C 003E4BCC  C0 02 19 A0 */	lfs f0, lbl_8051FD00@sda21(r2)
/* 803E7C90 003E4BD0  FC 00 10 00 */	fcmpu cr0, f0, f2
/* 803E7C94 003E4BD4  41 82 00 24 */	beq .L_803E7CB8
/* 803E7C98 003E4BD8  C0 22 19 A8 */	lfs f1, lbl_8051FD08@sda21(r2)
/* 803E7C9C 003E4BDC  C0 1E 00 0C */	lfs f0, 0xc(r30)
/* 803E7CA0 003E4BE0  EC 21 10 24 */	fdivs f1, f1, f2
/* 803E7CA4 003E4BE4  EC 00 00 72 */	fmuls f0, f0, f1
/* 803E7CA8 003E4BE8  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 803E7CAC 003E4BEC  C0 1E 00 10 */	lfs f0, 0x10(r30)
/* 803E7CB0 003E4BF0  EC 00 00 72 */	fmuls f0, f0, f1
/* 803E7CB4 003E4BF4  D0 1E 00 10 */	stfs f0, 0x10(r30)
.L_803E7CB8:
/* 803E7CB8 003E4BF8  38 00 00 01 */	li r0, 1
/* 803E7CBC 003E4BFC  90 1E 00 64 */	stw r0, 0x64(r30)
.L_803E7CC0:
/* 803E7CC0 003E4C00  80 7E 00 44 */	lwz r3, 0x44(r30)
/* 803E7CC4 003E4C04  C0 02 1A 00 */	lfs f0, lbl_8051FD60@sda21(r2)
/* 803E7CC8 003E4C08  C0 43 00 5C */	lfs f2, 0x5c(r3)
/* 803E7CCC 003E4C0C  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 803E7CD0 003E4C10  40 81 00 3C */	ble .L_803E7D0C
/* 803E7CD4 003E4C14  C0 3E 00 14 */	lfs f1, 0x14(r30)
/* 803E7CD8 003E4C18  38 00 00 02 */	li r0, 2
/* 803E7CDC 003E4C1C  C0 1E 00 0C */	lfs f0, 0xc(r30)
/* 803E7CE0 003E4C20  EC 82 00 72 */	fmuls f4, f2, f1
/* 803E7CE4 003E4C24  C0 5E 00 10 */	lfs f2, 0x10(r30)
/* 803E7CE8 003E4C28  C0 3E 00 04 */	lfs f1, 4(r30)
/* 803E7CEC 003E4C2C  C0 7E 00 08 */	lfs f3, 8(r30)
/* 803E7CF0 003E4C30  EC 00 01 32 */	fmuls f0, f0, f4
/* 803E7CF4 003E4C34  EC 42 01 32 */	fmuls f2, f2, f4
/* 803E7CF8 003E4C38  EC 01 00 2A */	fadds f0, f1, f0
/* 803E7CFC 003E4C3C  EC 23 10 2A */	fadds f1, f3, f2
/* 803E7D00 003E4C40  D0 1E 00 04 */	stfs f0, 4(r30)
/* 803E7D04 003E4C44  D0 3E 00 08 */	stfs f1, 8(r30)
/* 803E7D08 003E4C48  90 1E 00 64 */	stw r0, 0x64(r30)
.L_803E7D0C:
/* 803E7D0C 003E4C4C  80 1E 00 3C */	lwz r0, 0x3c(r30)
/* 803E7D10 003E4C50  28 00 00 00 */	cmplwi r0, 0
/* 803E7D14 003E4C54  40 82 03 04 */	bne .L_803E8018
/* 803E7D18 003E4C58  7F C3 F3 78 */	mr r3, r30
/* 803E7D1C 003E4C5C  38 80 00 05 */	li r4, 5
/* 803E7D20 003E4C60  4B FF FB 41 */	bl startState__Q43ebi5title6Kogane5TUnitFQ53ebi5title6Kogane5TUnit9enumState
/* 803E7D24 003E4C64  48 00 02 F4 */	b .L_803E8018
.L_803E7D28:
/* 803E7D28 003E4C68  38 00 00 00 */	li r0, 0
/* 803E7D2C 003E4C6C  90 1E 00 64 */	stw r0, 0x64(r30)
/* 803E7D30 003E4C70  80 7E 00 3C */	lwz r3, 0x3c(r30)
/* 803E7D34 003E4C74  28 03 00 00 */	cmplwi r3, 0
/* 803E7D38 003E4C78  41 82 00 0C */	beq .L_803E7D44
/* 803E7D3C 003E4C7C  38 03 FF FF */	addi r0, r3, -1
/* 803E7D40 003E4C80  90 1E 00 3C */	stw r0, 0x3c(r30)
.L_803E7D44:
/* 803E7D44 003E4C84  80 1E 00 3C */	lwz r0, 0x3c(r30)
/* 803E7D48 003E4C88  28 00 00 00 */	cmplwi r0, 0
/* 803E7D4C 003E4C8C  40 82 02 CC */	bne .L_803E8018
/* 803E7D50 003E4C90  7F C3 F3 78 */	mr r3, r30
/* 803E7D54 003E4C94  38 80 00 02 */	li r4, 2
/* 803E7D58 003E4C98  4B FF FB 09 */	bl startState__Q43ebi5title6Kogane5TUnitFQ53ebi5title6Kogane5TUnit9enumState
/* 803E7D5C 003E4C9C  48 00 02 BC */	b .L_803E8018
.L_803E7D60:
/* 803E7D60 003E4CA0  38 00 00 01 */	li r0, 1
/* 803E7D64 003E4CA4  C0 42 19 C8 */	lfs f2, lbl_8051FD28@sda21(r2)
/* 803E7D68 003E4CA8  90 1E 00 64 */	stw r0, 0x64(r30)
/* 803E7D6C 003E4CAC  C0 A2 1A 04 */	lfs f5, lbl_8051FD64@sda21(r2)
/* 803E7D70 003E4CB0  80 6D 9A EC */	lwz r3, sys@sda21(r13)
/* 803E7D74 003E4CB4  C0 C2 19 D4 */	lfs f6, lbl_8051FD34@sda21(r2)
/* 803E7D78 003E4CB8  C0 03 00 54 */	lfs f0, 0x54(r3)
/* 803E7D7C 003E4CBC  C0 3E 00 34 */	lfs f1, 0x34(r30)
/* 803E7D80 003E4CC0  EC 02 00 32 */	fmuls f0, f2, f0
/* 803E7D84 003E4CC4  C0 7E 00 38 */	lfs f3, 0x38(r30)
/* 803E7D88 003E4CC8  C0 5E 00 0C */	lfs f2, 0xc(r30)
/* 803E7D8C 003E4CCC  C0 9E 00 10 */	lfs f4, 0x10(r30)
/* 803E7D90 003E4CD0  EC A5 00 32 */	fmuls f5, f5, f0
/* 803E7D94 003E4CD4  C0 02 19 A0 */	lfs f0, lbl_8051FD00@sda21(r2)
/* 803E7D98 003E4CD8  EC A6 01 72 */	fmuls f5, f6, f5
/* 803E7D9C 003E4CDC  EC 21 01 72 */	fmuls f1, f1, f5
/* 803E7DA0 003E4CE0  EC 63 01 72 */	fmuls f3, f3, f5
/* 803E7DA4 003E4CE4  EC 22 08 2A */	fadds f1, f2, f1
/* 803E7DA8 003E4CE8  EC 44 18 2A */	fadds f2, f4, f3
/* 803E7DAC 003E4CEC  D0 3E 00 0C */	stfs f1, 0xc(r30)
/* 803E7DB0 003E4CF0  D0 5E 00 10 */	stfs f2, 0x10(r30)
/* 803E7DB4 003E4CF4  C0 7E 00 0C */	lfs f3, 0xc(r30)
/* 803E7DB8 003E4CF8  C0 5E 00 10 */	lfs f2, 0x10(r30)
/* 803E7DBC 003E4CFC  EC 23 00 F2 */	fmuls f1, f3, f3
/* 803E7DC0 003E4D00  EC 42 00 B2 */	fmuls f2, f2, f2
/* 803E7DC4 003E4D04  EC 21 10 2A */	fadds f1, f1, f2
/* 803E7DC8 003E4D08  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 803E7DCC 003E4D0C  40 81 00 1C */	ble .L_803E7DE8
/* 803E7DD0 003E4D10  EC 43 10 FA */	fmadds f2, f3, f3, f2
/* 803E7DD4 003E4D14  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 803E7DD8 003E4D18  40 81 00 14 */	ble .L_803E7DEC
/* 803E7DDC 003E4D1C  FC 00 10 34 */	frsqrte f0, f2
/* 803E7DE0 003E4D20  EC 40 00 B2 */	fmuls f2, f0, f2
/* 803E7DE4 003E4D24  48 00 00 08 */	b .L_803E7DEC
.L_803E7DE8:
/* 803E7DE8 003E4D28  FC 40 00 90 */	fmr f2, f0
.L_803E7DEC:
/* 803E7DEC 003E4D2C  C0 02 19 A0 */	lfs f0, lbl_8051FD00@sda21(r2)
/* 803E7DF0 003E4D30  FC 00 10 00 */	fcmpu cr0, f0, f2
/* 803E7DF4 003E4D34  41 82 00 24 */	beq .L_803E7E18
/* 803E7DF8 003E4D38  C0 22 19 A8 */	lfs f1, lbl_8051FD08@sda21(r2)
/* 803E7DFC 003E4D3C  C0 1E 00 0C */	lfs f0, 0xc(r30)
/* 803E7E00 003E4D40  EC 21 10 24 */	fdivs f1, f1, f2
/* 803E7E04 003E4D44  EC 00 00 72 */	fmuls f0, f0, f1
/* 803E7E08 003E4D48  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 803E7E0C 003E4D4C  C0 1E 00 10 */	lfs f0, 0x10(r30)
/* 803E7E10 003E4D50  EC 00 00 72 */	fmuls f0, f0, f1
/* 803E7E14 003E4D54  D0 1E 00 10 */	stfs f0, 0x10(r30)
.L_803E7E18:
/* 803E7E18 003E4D58  C0 3E 00 10 */	lfs f1, 0x10(r30)
/* 803E7E1C 003E4D5C  C0 1E 00 38 */	lfs f0, 0x38(r30)
/* 803E7E20 003E4D60  C0 5E 00 0C */	lfs f2, 0xc(r30)
/* 803E7E24 003E4D64  EC 61 00 28 */	fsubs f3, f1, f0
/* 803E7E28 003E4D68  C0 3E 00 34 */	lfs f1, 0x34(r30)
/* 803E7E2C 003E4D6C  C0 02 19 A0 */	lfs f0, lbl_8051FD00@sda21(r2)
/* 803E7E30 003E4D70  EC 22 08 28 */	fsubs f1, f2, f1
/* 803E7E34 003E4D74  EC 43 00 F2 */	fmuls f2, f3, f3
/* 803E7E38 003E4D78  EC 21 10 7A */	fmadds f1, f1, f1, f2
/* 803E7E3C 003E4D7C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 803E7E40 003E4D80  40 81 00 14 */	ble .L_803E7E54
/* 803E7E44 003E4D84  40 81 00 14 */	ble .L_803E7E58
/* 803E7E48 003E4D88  FC 00 08 34 */	frsqrte f0, f1
/* 803E7E4C 003E4D8C  EC 20 00 72 */	fmuls f1, f0, f1
/* 803E7E50 003E4D90  48 00 00 08 */	b .L_803E7E58
.L_803E7E54:
/* 803E7E54 003E4D94  FC 20 00 90 */	fmr f1, f0
.L_803E7E58:
/* 803E7E58 003E4D98  C0 02 19 D4 */	lfs f0, lbl_8051FD34@sda21(r2)
/* 803E7E5C 003E4D9C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 803E7E60 003E4DA0  40 80 01 B8 */	bge .L_803E8018
/* 803E7E64 003E4DA4  7F C3 F3 78 */	mr r3, r30
/* 803E7E68 003E4DA8  38 80 00 03 */	li r4, 3
/* 803E7E6C 003E4DAC  4B FF F9 F5 */	bl startState__Q43ebi5title6Kogane5TUnitFQ53ebi5title6Kogane5TUnit9enumState
/* 803E7E70 003E4DB0  48 00 01 A8 */	b .L_803E8018
.L_803E7E74:
/* 803E7E74 003E4DB4  38 00 00 02 */	li r0, 2
/* 803E7E78 003E4DB8  90 1E 00 64 */	stw r0, 0x64(r30)
/* 803E7E7C 003E4DBC  80 7E 00 3C */	lwz r3, 0x3c(r30)
/* 803E7E80 003E4DC0  28 03 00 00 */	cmplwi r3, 0
/* 803E7E84 003E4DC4  41 82 00 0C */	beq .L_803E7E90
/* 803E7E88 003E4DC8  38 03 FF FF */	addi r0, r3, -1
/* 803E7E8C 003E4DCC  90 1E 00 3C */	stw r0, 0x3c(r30)
.L_803E7E90:
/* 803E7E90 003E4DD0  80 1E 00 3C */	lwz r0, 0x3c(r30)
/* 803E7E94 003E4DD4  28 00 00 00 */	cmplwi r0, 0
/* 803E7E98 003E4DD8  40 82 00 14 */	bne .L_803E7EAC
/* 803E7E9C 003E4DDC  7F C3 F3 78 */	mr r3, r30
/* 803E7EA0 003E4DE0  38 80 00 01 */	li r4, 1
/* 803E7EA4 003E4DE4  4B FF F9 BD */	bl startState__Q43ebi5title6Kogane5TUnitFQ53ebi5title6Kogane5TUnit9enumState
/* 803E7EA8 003E4DE8  48 00 01 70 */	b .L_803E8018
.L_803E7EAC:
/* 803E7EAC 003E4DEC  C0 7E 00 14 */	lfs f3, 0x14(r30)
/* 803E7EB0 003E4DF0  C0 1E 00 0C */	lfs f0, 0xc(r30)
/* 803E7EB4 003E4DF4  C0 5E 00 10 */	lfs f2, 0x10(r30)
/* 803E7EB8 003E4DF8  EC 00 00 F2 */	fmuls f0, f0, f3
/* 803E7EBC 003E4DFC  C0 3E 00 04 */	lfs f1, 4(r30)
/* 803E7EC0 003E4E00  EC 42 00 F2 */	fmuls f2, f2, f3
/* 803E7EC4 003E4E04  C0 7E 00 08 */	lfs f3, 8(r30)
/* 803E7EC8 003E4E08  EC 01 00 2A */	fadds f0, f1, f0
/* 803E7ECC 003E4E0C  EC 23 10 2A */	fadds f1, f3, f2
/* 803E7ED0 003E4E10  D0 1E 00 04 */	stfs f0, 4(r30)
/* 803E7ED4 003E4E14  D0 3E 00 08 */	stfs f1, 8(r30)
/* 803E7ED8 003E4E18  48 00 01 40 */	b .L_803E8018
.L_803E7EDC:
/* 803E7EDC 003E4E1C  38 00 00 02 */	li r0, 2
/* 803E7EE0 003E4E20  C0 02 19 A0 */	lfs f0, lbl_8051FD00@sda21(r2)
/* 803E7EE4 003E4E24  90 1E 00 64 */	stw r0, 0x64(r30)
/* 803E7EE8 003E4E28  C0 7E 00 0C */	lfs f3, 0xc(r30)
/* 803E7EEC 003E4E2C  C0 5E 00 10 */	lfs f2, 0x10(r30)
/* 803E7EF0 003E4E30  EC 23 00 F2 */	fmuls f1, f3, f3
/* 803E7EF4 003E4E34  EC 42 00 B2 */	fmuls f2, f2, f2
/* 803E7EF8 003E4E38  EC 21 10 2A */	fadds f1, f1, f2
/* 803E7EFC 003E4E3C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 803E7F00 003E4E40  40 81 00 1C */	ble .L_803E7F1C
/* 803E7F04 003E4E44  EC 43 10 FA */	fmadds f2, f3, f3, f2
/* 803E7F08 003E4E48  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 803E7F0C 003E4E4C  40 81 00 14 */	ble .L_803E7F20
/* 803E7F10 003E4E50  FC 00 10 34 */	frsqrte f0, f2
/* 803E7F14 003E4E54  EC 40 00 B2 */	fmuls f2, f0, f2
/* 803E7F18 003E4E58  48 00 00 08 */	b .L_803E7F20
.L_803E7F1C:
/* 803E7F1C 003E4E5C  FC 40 00 90 */	fmr f2, f0
.L_803E7F20:
/* 803E7F20 003E4E60  C0 02 19 A0 */	lfs f0, lbl_8051FD00@sda21(r2)
/* 803E7F24 003E4E64  FC 00 10 00 */	fcmpu cr0, f0, f2
/* 803E7F28 003E4E68  41 82 00 24 */	beq .L_803E7F4C
/* 803E7F2C 003E4E6C  C0 22 19 A8 */	lfs f1, lbl_8051FD08@sda21(r2)
/* 803E7F30 003E4E70  C0 1E 00 0C */	lfs f0, 0xc(r30)
/* 803E7F34 003E4E74  EC 21 10 24 */	fdivs f1, f1, f2
/* 803E7F38 003E4E78  EC 00 00 72 */	fmuls f0, f0, f1
/* 803E7F3C 003E4E7C  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 803E7F40 003E4E80  C0 1E 00 10 */	lfs f0, 0x10(r30)
/* 803E7F44 003E4E84  EC 00 00 72 */	fmuls f0, f0, f1
/* 803E7F48 003E4E88  D0 1E 00 10 */	stfs f0, 0x10(r30)
.L_803E7F4C:
/* 803E7F4C 003E4E8C  C0 7E 00 14 */	lfs f3, 0x14(r30)
/* 803E7F50 003E4E90  C0 1E 00 0C */	lfs f0, 0xc(r30)
/* 803E7F54 003E4E94  C0 5E 00 10 */	lfs f2, 0x10(r30)
/* 803E7F58 003E4E98  EC 00 00 F2 */	fmuls f0, f0, f3
/* 803E7F5C 003E4E9C  C0 3E 00 04 */	lfs f1, 4(r30)
/* 803E7F60 003E4EA0  EC 42 00 F2 */	fmuls f2, f2, f3
/* 803E7F64 003E4EA4  C0 7E 00 08 */	lfs f3, 8(r30)
/* 803E7F68 003E4EA8  EC 01 00 2A */	fadds f0, f1, f0
/* 803E7F6C 003E4EAC  EC 23 10 2A */	fadds f1, f3, f2
/* 803E7F70 003E4EB0  D0 1E 00 04 */	stfs f0, 4(r30)
/* 803E7F74 003E4EB4  D0 3E 00 08 */	stfs f1, 8(r30)
/* 803E7F78 003E4EB8  48 00 00 A0 */	b .L_803E8018
.L_803E7F7C:
/* 803E7F7C 003E4EBC  38 00 00 02 */	li r0, 2
/* 803E7F80 003E4EC0  C0 02 19 A0 */	lfs f0, lbl_8051FD00@sda21(r2)
/* 803E7F84 003E4EC4  90 1E 00 64 */	stw r0, 0x64(r30)
/* 803E7F88 003E4EC8  C0 7E 00 0C */	lfs f3, 0xc(r30)
/* 803E7F8C 003E4ECC  C0 5E 00 10 */	lfs f2, 0x10(r30)
/* 803E7F90 003E4ED0  EC 23 00 F2 */	fmuls f1, f3, f3
/* 803E7F94 003E4ED4  EC 42 00 B2 */	fmuls f2, f2, f2
/* 803E7F98 003E4ED8  EC 21 10 2A */	fadds f1, f1, f2
/* 803E7F9C 003E4EDC  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 803E7FA0 003E4EE0  40 81 00 1C */	ble .L_803E7FBC
/* 803E7FA4 003E4EE4  EC 43 10 FA */	fmadds f2, f3, f3, f2
/* 803E7FA8 003E4EE8  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 803E7FAC 003E4EEC  40 81 00 14 */	ble .L_803E7FC0
/* 803E7FB0 003E4EF0  FC 00 10 34 */	frsqrte f0, f2
/* 803E7FB4 003E4EF4  EC 40 00 B2 */	fmuls f2, f0, f2
/* 803E7FB8 003E4EF8  48 00 00 08 */	b .L_803E7FC0
.L_803E7FBC:
/* 803E7FBC 003E4EFC  FC 40 00 90 */	fmr f2, f0
.L_803E7FC0:
/* 803E7FC0 003E4F00  C0 02 19 A0 */	lfs f0, lbl_8051FD00@sda21(r2)
/* 803E7FC4 003E4F04  FC 00 10 00 */	fcmpu cr0, f0, f2
/* 803E7FC8 003E4F08  41 82 00 24 */	beq .L_803E7FEC
/* 803E7FCC 003E4F0C  C0 22 19 A8 */	lfs f1, lbl_8051FD08@sda21(r2)
/* 803E7FD0 003E4F10  C0 1E 00 0C */	lfs f0, 0xc(r30)
/* 803E7FD4 003E4F14  EC 21 10 24 */	fdivs f1, f1, f2
/* 803E7FD8 003E4F18  EC 00 00 72 */	fmuls f0, f0, f1
/* 803E7FDC 003E4F1C  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 803E7FE0 003E4F20  C0 1E 00 10 */	lfs f0, 0x10(r30)
/* 803E7FE4 003E4F24  EC 00 00 72 */	fmuls f0, f0, f1
/* 803E7FE8 003E4F28  D0 1E 00 10 */	stfs f0, 0x10(r30)
.L_803E7FEC:
/* 803E7FEC 003E4F2C  C0 7E 00 14 */	lfs f3, 0x14(r30)
/* 803E7FF0 003E4F30  C0 1E 00 0C */	lfs f0, 0xc(r30)
/* 803E7FF4 003E4F34  C0 5E 00 10 */	lfs f2, 0x10(r30)
/* 803E7FF8 003E4F38  EC 00 00 F2 */	fmuls f0, f0, f3
/* 803E7FFC 003E4F3C  C0 3E 00 04 */	lfs f1, 4(r30)
/* 803E8000 003E4F40  EC 42 00 F2 */	fmuls f2, f2, f3
/* 803E8004 003E4F44  C0 7E 00 08 */	lfs f3, 8(r30)
/* 803E8008 003E4F48  EC 01 00 2A */	fadds f0, f1, f0
/* 803E800C 003E4F4C  EC 23 10 2A */	fadds f1, f3, f2
/* 803E8010 003E4F50  D0 1E 00 04 */	stfs f0, 4(r30)
/* 803E8014 003E4F54  D0 3E 00 08 */	stfs f1, 8(r30)
.L_803E8018:
/* 803E8018 003E4F58  80 1E 00 60 */	lwz r0, 0x60(r30)
/* 803E801C 003E4F5C  2C 00 00 04 */	cmpwi r0, 4
/* 803E8020 003E4F60  41 82 00 3C */	beq .L_803E805C
/* 803E8024 003E4F64  40 80 00 10 */	bge .L_803E8034
/* 803E8028 003E4F68  2C 00 00 00 */	cmpwi r0, 0
/* 803E802C 003E4F6C  41 82 00 14 */	beq .L_803E8040
/* 803E8030 003E4F70  48 00 00 74 */	b .L_803E80A4
.L_803E8034:
/* 803E8034 003E4F74  2C 00 00 06 */	cmpwi r0, 6
/* 803E8038 003E4F78  40 80 00 6C */	bge .L_803E80A4
/* 803E803C 003E4F7C  48 00 00 44 */	b .L_803E8080
.L_803E8040:
/* 803E8040 003E4F80  80 8D 9A 28 */	lwz r4, titleMgr__Q23ebi5title@sda21(r13)
/* 803E8044 003E4F84  38 61 00 08 */	addi r3, r1, 8
/* 803E8048 003E4F88  4B FD 70 31 */	bl getPosOutOfViewField__Q33ebi5title9TTitleMgrFv
/* 803E804C 003E4F8C  C0 01 00 08 */	lfs f0, 8(r1)
/* 803E8050 003E4F90  D0 1E 00 04 */	stfs f0, 4(r30)
/* 803E8054 003E4F94  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 803E8058 003E4F98  D0 1E 00 08 */	stfs f0, 8(r30)
.L_803E805C:
/* 803E805C 003E4F9C  80 6D 9A 28 */	lwz r3, titleMgr__Q23ebi5title@sda21(r13)
/* 803E8060 003E4FA0  7F C4 F3 78 */	mr r4, r30
/* 803E8064 003E4FA4  4B FD 6E C1 */	bl isInViewField__Q33ebi5title9TTitleMgrFPQ33ebi5title8TObjBase
/* 803E8068 003E4FA8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 803E806C 003E4FAC  41 82 00 44 */	beq .L_803E80B0
/* 803E8070 003E4FB0  7F C3 F3 78 */	mr r3, r30
/* 803E8074 003E4FB4  38 80 00 03 */	li r4, 3
/* 803E8078 003E4FB8  4B FF F7 E9 */	bl startState__Q43ebi5title6Kogane5TUnitFQ53ebi5title6Kogane5TUnit9enumState
/* 803E807C 003E4FBC  48 00 00 34 */	b .L_803E80B0
.L_803E8080:
/* 803E8080 003E4FC0  80 6D 9A 28 */	lwz r3, titleMgr__Q23ebi5title@sda21(r13)
/* 803E8084 003E4FC4  7F C4 F3 78 */	mr r4, r30
/* 803E8088 003E4FC8  4B FD 6F 69 */	bl isOutViewField__Q33ebi5title9TTitleMgrFPQ33ebi5title8TObjBase
/* 803E808C 003E4FCC  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 803E8090 003E4FD0  41 82 00 20 */	beq .L_803E80B0
/* 803E8094 003E4FD4  7F C3 F3 78 */	mr r3, r30
/* 803E8098 003E4FD8  38 80 00 00 */	li r4, 0
/* 803E809C 003E4FDC  4B FF F7 C5 */	bl startState__Q43ebi5title6Kogane5TUnitFQ53ebi5title6Kogane5TUnit9enumState
/* 803E80A0 003E4FE0  48 00 00 10 */	b .L_803E80B0
.L_803E80A4:
/* 803E80A4 003E4FE4  80 6D 9A 28 */	lwz r3, titleMgr__Q23ebi5title@sda21(r13)
/* 803E80A8 003E4FE8  7F C4 F3 78 */	mr r4, r30
/* 803E80AC 003E4FEC  4B FD 6D F9 */	bl inViewField__Q33ebi5title9TTitleMgrFPQ33ebi5title8TObjBase
.L_803E80B0:
/* 803E80B0 003E4FF0  80 1E 00 64 */	lwz r0, 0x64(r30)
/* 803E80B4 003E4FF4  7C 00 F8 00 */	cmpw r0, r31
/* 803E80B8 003E4FF8  41 82 00 78 */	beq .L_803E8130
/* 803E80BC 003E4FFC  2C 00 00 01 */	cmpwi r0, 1
/* 803E80C0 003E5000  41 82 00 20 */	beq .L_803E80E0
/* 803E80C4 003E5004  40 80 00 10 */	bge .L_803E80D4
/* 803E80C8 003E5008  2C 00 00 00 */	cmpwi r0, 0
/* 803E80CC 003E500C  40 80 00 4C */	bge .L_803E8118
/* 803E80D0 003E5010  48 00 00 60 */	b .L_803E8130
.L_803E80D4:
/* 803E80D4 003E5014  2C 00 00 03 */	cmpwi r0, 3
/* 803E80D8 003E5018  40 80 00 58 */	bge .L_803E8130
/* 803E80DC 003E501C  48 00 00 20 */	b .L_803E80FC
.L_803E80E0:
/* 803E80E0 003E5020  C0 22 19 A8 */	lfs f1, lbl_8051FD08@sda21(r2)
/* 803E80E4 003E5024  38 7E 00 4C */	addi r3, r30, 0x4c
/* 803E80E8 003E5028  38 80 00 00 */	li r4, 0
/* 803E80EC 003E502C  4B FE 1D 81 */	bl init__Q23ebi11E3DAnimCtrlFlf
/* 803E80F0 003E5030  38 7E 00 4C */	addi r3, r30, 0x4c
/* 803E80F4 003E5034  4B FE 1E 1D */	bl play__Q23ebi11E3DAnimCtrlFv
/* 803E80F8 003E5038  48 00 00 38 */	b .L_803E8130
.L_803E80FC:
/* 803E80FC 003E503C  C0 22 19 A8 */	lfs f1, lbl_8051FD08@sda21(r2)
/* 803E8100 003E5040  38 7E 00 4C */	addi r3, r30, 0x4c
/* 803E8104 003E5044  38 80 00 00 */	li r4, 0
/* 803E8108 003E5048  4B FE 1D 65 */	bl init__Q23ebi11E3DAnimCtrlFlf
/* 803E810C 003E504C  38 7E 00 4C */	addi r3, r30, 0x4c
/* 803E8110 003E5050  4B FE 1E 01 */	bl play__Q23ebi11E3DAnimCtrlFv
/* 803E8114 003E5054  48 00 00 1C */	b .L_803E8130
.L_803E8118:
/* 803E8118 003E5058  C0 22 19 A8 */	lfs f1, lbl_8051FD08@sda21(r2)
/* 803E811C 003E505C  38 7E 00 4C */	addi r3, r30, 0x4c
/* 803E8120 003E5060  38 80 00 01 */	li r4, 1
/* 803E8124 003E5064  4B FE 1D 49 */	bl init__Q23ebi11E3DAnimCtrlFlf
/* 803E8128 003E5068  38 7E 00 4C */	addi r3, r30, 0x4c
/* 803E812C 003E506C  4B FE 1D E5 */	bl play__Q23ebi11E3DAnimCtrlFv
.L_803E8130:
/* 803E8130 003E5070  7F C3 F3 78 */	mr r3, r30
/* 803E8134 003E5074  4B FD 8A 4D */	bl calcModelBaseMtx___Q33ebi5title8TObjBaseFv
/* 803E8138 003E5078  80 7E 00 58 */	lwz r3, 0x58(r30)
/* 803E813C 003E507C  28 03 00 00 */	cmplwi r3, 0
/* 803E8140 003E5080  41 82 00 9C */	beq .L_803E81DC
/* 803E8144 003E5084  80 1E 00 54 */	lwz r0, 0x54(r30)
/* 803E8148 003E5088  2C 00 00 02 */	cmpwi r0, 2
/* 803E814C 003E508C  41 82 00 58 */	beq .L_803E81A4
/* 803E8150 003E5090  40 80 00 8C */	bge .L_803E81DC
/* 803E8154 003E5094  2C 00 00 00 */	cmpwi r0, 0
/* 803E8158 003E5098  41 82 00 84 */	beq .L_803E81DC
/* 803E815C 003E509C  40 80 00 0C */	bge .L_803E8168
/* 803E8160 003E50A0  48 00 00 7C */	b .L_803E81DC
/* 803E8164 003E50A4  48 00 00 78 */	b .L_803E81DC
.L_803E8168:
/* 803E8168 003E50A8  C0 5E 00 50 */	lfs f2, 0x50(r30)
/* 803E816C 003E50AC  C0 23 00 18 */	lfs f1, 0x18(r3)
/* 803E8170 003E50B0  C0 1E 00 4C */	lfs f0, 0x4c(r30)
/* 803E8174 003E50B4  EC 02 00 7A */	fmadds f0, f2, f1, f0
/* 803E8178 003E50B8  D0 1E 00 4C */	stfs f0, 0x4c(r30)
/* 803E817C 003E50BC  80 7E 00 58 */	lwz r3, 0x58(r30)
/* 803E8180 003E50C0  C0 3E 00 4C */	lfs f1, 0x4c(r30)
/* 803E8184 003E50C4  C0 43 00 14 */	lfs f2, 0x14(r3)
/* 803E8188 003E50C8  FC 01 10 40 */	fcmpo cr0, f1, f2
/* 803E818C 003E50CC  40 81 00 50 */	ble .L_803E81DC
/* 803E8190 003E50D0  C0 03 00 10 */	lfs f0, 0x10(r3)
/* 803E8194 003E50D4  EC 02 00 28 */	fsubs f0, f2, f0
/* 803E8198 003E50D8  EC 01 00 28 */	fsubs f0, f1, f0
/* 803E819C 003E50DC  D0 1E 00 4C */	stfs f0, 0x4c(r30)
/* 803E81A0 003E50E0  48 00 00 3C */	b .L_803E81DC
.L_803E81A4:
/* 803E81A4 003E50E4  C0 5E 00 50 */	lfs f2, 0x50(r30)
/* 803E81A8 003E50E8  C0 23 00 18 */	lfs f1, 0x18(r3)
/* 803E81AC 003E50EC  C0 1E 00 4C */	lfs f0, 0x4c(r30)
/* 803E81B0 003E50F0  EC 02 00 7A */	fmadds f0, f2, f1, f0
/* 803E81B4 003E50F4  D0 1E 00 4C */	stfs f0, 0x4c(r30)
/* 803E81B8 003E50F8  80 7E 00 58 */	lwz r3, 0x58(r30)
/* 803E81BC 003E50FC  C0 1E 00 4C */	lfs f0, 0x4c(r30)
/* 803E81C0 003E5100  C0 23 00 0C */	lfs f1, 0xc(r3)
/* 803E81C4 003E5104  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 803E81C8 003E5108  4C 41 13 82 */	cror 2, 1, 2
/* 803E81CC 003E510C  40 82 00 10 */	bne .L_803E81DC
/* 803E81D0 003E5110  D0 3E 00 4C */	stfs f1, 0x4c(r30)
/* 803E81D4 003E5114  38 00 00 03 */	li r0, 3
/* 803E81D8 003E5118  90 1E 00 54 */	stw r0, 0x54(r30)
.L_803E81DC:
/* 803E81DC 003E511C  80 7E 00 58 */	lwz r3, 0x58(r30)
/* 803E81E0 003E5120  80 9E 00 28 */	lwz r4, 0x28(r30)
/* 803E81E4 003E5124  28 03 00 00 */	cmplwi r3, 0
/* 803E81E8 003E5128  41 82 00 28 */	beq .L_803E8210
/* 803E81EC 003E512C  C0 1E 00 4C */	lfs f0, 0x4c(r30)
/* 803E81F0 003E5130  80 63 00 00 */	lwz r3, 0(r3)
/* 803E81F4 003E5134  D0 03 00 08 */	stfs f0, 8(r3)
/* 803E81F8 003E5138  80 64 00 04 */	lwz r3, 4(r4)
/* 803E81FC 003E513C  80 9E 00 58 */	lwz r4, 0x58(r30)
/* 803E8200 003E5140  80 63 00 28 */	lwz r3, 0x28(r3)
/* 803E8204 003E5144  80 04 00 04 */	lwz r0, 4(r4)
/* 803E8208 003E5148  80 63 00 00 */	lwz r3, 0(r3)
/* 803E820C 003E514C  90 03 00 54 */	stw r0, 0x54(r3)
.L_803E8210:
/* 803E8210 003E5150  80 7E 00 28 */	lwz r3, 0x28(r30)
/* 803E8214 003E5154  81 83 00 00 */	lwz r12, 0(r3)
/* 803E8218 003E5158  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 803E821C 003E515C  7D 89 03 A6 */	mtctr r12
/* 803E8220 003E5160  4E 80 04 21 */	bctrl 
/* 803E8224 003E5164  80 7E 00 28 */	lwz r3, 0x28(r30)
/* 803E8228 003E5168  81 83 00 00 */	lwz r12, 0(r3)
/* 803E822C 003E516C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 803E8230 003E5170  7D 89 03 A6 */	mtctr r12
/* 803E8234 003E5174  4E 80 04 21 */	bctrl 
/* 803E8238 003E5178  80 7E 00 28 */	lwz r3, 0x28(r30)
/* 803E823C 003E517C  81 83 00 00 */	lwz r12, 0(r3)
/* 803E8240 003E5180  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 803E8244 003E5184  7D 89 03 A6 */	mtctr r12
/* 803E8248 003E5188  4E 80 04 21 */	bctrl 
.L_803E824C:
/* 803E824C 003E518C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 803E8250 003E5190  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 803E8254 003E5194  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 803E8258 003E5198  7C 08 03 A6 */	mtlr r0
/* 803E825C 003E519C  38 21 00 20 */	addi r1, r1, 0x20
/* 803E8260 003E51A0  4E 80 00 20 */	blr 
.endfn update__Q43ebi5title6Kogane5TUnitFv

.fn __ct__Q43ebi5title6Kogane6TParamFv, weak
/* 803E8264 003E51A4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 803E8268 003E51A8  7C 08 02 A6 */	mflr r0
/* 803E826C 003E51AC  90 01 00 14 */	stw r0, 0x14(r1)
/* 803E8270 003E51B0  7C 80 07 35 */	extsh. r0, r4
/* 803E8274 003E51B4  3C 80 80 49 */	lis r4, lbl_804974A0@ha
/* 803E8278 003E51B8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 803E827C 003E51BC  3B E4 74 A0 */	addi r31, r4, lbl_804974A0@l
/* 803E8280 003E51C0  93 C1 00 08 */	stw r30, 8(r1)
/* 803E8284 003E51C4  7C 7E 1B 78 */	mr r30, r3
/* 803E8288 003E51C8  41 82 00 0C */	beq .L_803E8294
/* 803E828C 003E51CC  38 1E 01 EC */	addi r0, r30, 0x1ec
/* 803E8290 003E51D0  90 1E 00 00 */	stw r0, 0(r30)
.L_803E8294:
/* 803E8294 003E51D4  38 00 00 00 */	li r0, 0
/* 803E8298 003E51D8  3C A0 62 30 */	lis r5, 0x62303030@ha
/* 803E829C 003E51DC  90 1E 00 04 */	stw r0, 4(r30)
/* 803E82A0 003E51E0  38 02 19 AC */	addi r0, r2, lbl_8051FD0C@sda21
/* 803E82A4 003E51E4  7F C4 F3 78 */	mr r4, r30
/* 803E82A8 003E51E8  38 7E 00 0C */	addi r3, r30, 0xc
/* 803E82AC 003E51EC  90 1E 00 08 */	stw r0, 8(r30)
/* 803E82B0 003E51F0  38 A5 30 30 */	addi r5, r5, 0x62303030@l
/* 803E82B4 003E51F4  38 DF 00 2C */	addi r6, r31, 0x2c
/* 803E82B8 003E51F8  48 02 B3 A1 */	bl __ct__8BaseParmFP10ParametersUlPc
/* 803E82BC 003E51FC  3C 60 80 4B */	lis r3, "__vt__7Parm<f>"@ha
/* 803E82C0 003E5200  3C A0 62 30 */	lis r5, 0x62303031@ha
/* 803E82C4 003E5204  38 03 AC BC */	addi r0, r3, "__vt__7Parm<f>"@l
/* 803E82C8 003E5208  C0 02 19 B4 */	lfs f0, lbl_8051FD14@sda21(r2)
/* 803E82CC 003E520C  90 1E 00 0C */	stw r0, 0xc(r30)
/* 803E82D0 003E5210  7F C4 F3 78 */	mr r4, r30
/* 803E82D4 003E5214  C0 22 19 A0 */	lfs f1, lbl_8051FD00@sda21(r2)
/* 803E82D8 003E5218  38 7E 00 34 */	addi r3, r30, 0x34
/* 803E82DC 003E521C  D0 1E 00 24 */	stfs f0, 0x24(r30)
/* 803E82E0 003E5220  38 A5 30 31 */	addi r5, r5, 0x62303031@l
/* 803E82E4 003E5224  C0 02 19 B8 */	lfs f0, lbl_8051FD18@sda21(r2)
/* 803E82E8 003E5228  38 DF 00 38 */	addi r6, r31, 0x38
/* 803E82EC 003E522C  D0 3E 00 2C */	stfs f1, 0x2c(r30)
/* 803E82F0 003E5230  D0 1E 00 30 */	stfs f0, 0x30(r30)
/* 803E82F4 003E5234  48 02 B3 65 */	bl __ct__8BaseParmFP10ParametersUlPc
/* 803E82F8 003E5238  3C 60 80 4B */	lis r3, "__vt__7Parm<f>"@ha
/* 803E82FC 003E523C  3C A0 62 30 */	lis r5, 0x62303032@ha
/* 803E8300 003E5240  38 03 AC BC */	addi r0, r3, "__vt__7Parm<f>"@l
/* 803E8304 003E5244  C0 02 19 BC */	lfs f0, lbl_8051FD1C@sda21(r2)
/* 803E8308 003E5248  90 1E 00 34 */	stw r0, 0x34(r30)
/* 803E830C 003E524C  7F C4 F3 78 */	mr r4, r30
/* 803E8310 003E5250  C0 22 19 A0 */	lfs f1, lbl_8051FD00@sda21(r2)
/* 803E8314 003E5254  38 7E 00 5C */	addi r3, r30, 0x5c
/* 803E8318 003E5258  D0 1E 00 4C */	stfs f0, 0x4c(r30)
/* 803E831C 003E525C  38 A5 30 32 */	addi r5, r5, 0x62303032@l
/* 803E8320 003E5260  C0 02 19 C0 */	lfs f0, lbl_8051FD20@sda21(r2)
/* 803E8324 003E5264  38 DF 00 48 */	addi r6, r31, 0x48
/* 803E8328 003E5268  D0 3E 00 54 */	stfs f1, 0x54(r30)
/* 803E832C 003E526C  D0 1E 00 58 */	stfs f0, 0x58(r30)
/* 803E8330 003E5270  48 02 B3 29 */	bl __ct__8BaseParmFP10ParametersUlPc
/* 803E8334 003E5274  3C 60 80 4B */	lis r3, "__vt__7Parm<f>"@ha
/* 803E8338 003E5278  3C A0 62 30 */	lis r5, 0x62303033@ha
/* 803E833C 003E527C  38 03 AC BC */	addi r0, r3, "__vt__7Parm<f>"@l
/* 803E8340 003E5280  C0 02 19 BC */	lfs f0, lbl_8051FD1C@sda21(r2)
/* 803E8344 003E5284  90 1E 00 5C */	stw r0, 0x5c(r30)
/* 803E8348 003E5288  7F C4 F3 78 */	mr r4, r30
/* 803E834C 003E528C  C0 22 19 A0 */	lfs f1, lbl_8051FD00@sda21(r2)
/* 803E8350 003E5290  38 7E 00 84 */	addi r3, r30, 0x84
/* 803E8354 003E5294  D0 1E 00 74 */	stfs f0, 0x74(r30)
/* 803E8358 003E5298  38 A5 30 33 */	addi r5, r5, 0x62303033@l
/* 803E835C 003E529C  C0 02 19 C0 */	lfs f0, lbl_8051FD20@sda21(r2)
/* 803E8360 003E52A0  38 DF 00 58 */	addi r6, r31, 0x58
/* 803E8364 003E52A4  D0 3E 00 7C */	stfs f1, 0x7c(r30)
/* 803E8368 003E52A8  D0 1E 00 80 */	stfs f0, 0x80(r30)
/* 803E836C 003E52AC  48 02 B2 ED */	bl __ct__8BaseParmFP10ParametersUlPc
/* 803E8370 003E52B0  3C 60 80 4B */	lis r3, "__vt__7Parm<f>"@ha
/* 803E8374 003E52B4  3C A0 6B 67 */	lis r5, 0x6B673030@ha
/* 803E8378 003E52B8  38 03 AC BC */	addi r0, r3, "__vt__7Parm<f>"@l
/* 803E837C 003E52BC  C0 02 19 C4 */	lfs f0, lbl_8051FD24@sda21(r2)
/* 803E8380 003E52C0  90 1E 00 84 */	stw r0, 0x84(r30)
/* 803E8384 003E52C4  7F C4 F3 78 */	mr r4, r30
/* 803E8388 003E52C8  C0 22 19 A0 */	lfs f1, lbl_8051FD00@sda21(r2)
/* 803E838C 003E52CC  38 7E 00 AC */	addi r3, r30, 0xac
/* 803E8390 003E52D0  D0 1E 00 9C */	stfs f0, 0x9c(r30)
/* 803E8394 003E52D4  38 A5 30 30 */	addi r5, r5, 0x6B673030@l
/* 803E8398 003E52D8  C0 02 19 C0 */	lfs f0, lbl_8051FD20@sda21(r2)
/* 803E839C 003E52DC  38 DF 00 6C */	addi r6, r31, 0x6c
/* 803E83A0 003E52E0  D0 3E 00 A4 */	stfs f1, 0xa4(r30)
/* 803E83A4 003E52E4  D0 1E 00 A8 */	stfs f0, 0xa8(r30)
/* 803E83A8 003E52E8  48 02 B2 B1 */	bl __ct__8BaseParmFP10ParametersUlPc
/* 803E83AC 003E52EC  3C 60 80 4B */	lis r3, "__vt__7Parm<f>"@ha
/* 803E83B0 003E52F0  3C A0 6B 67 */	lis r5, 0x6B673031@ha
/* 803E83B4 003E52F4  38 03 AC BC */	addi r0, r3, "__vt__7Parm<f>"@l
/* 803E83B8 003E52F8  C0 02 19 C8 */	lfs f0, lbl_8051FD28@sda21(r2)
/* 803E83BC 003E52FC  90 1E 00 AC */	stw r0, 0xac(r30)
/* 803E83C0 003E5300  7F C4 F3 78 */	mr r4, r30
/* 803E83C4 003E5304  C0 22 19 A0 */	lfs f1, lbl_8051FD00@sda21(r2)
/* 803E83C8 003E5308  38 7E 00 D4 */	addi r3, r30, 0xd4
/* 803E83CC 003E530C  D0 1E 00 C4 */	stfs f0, 0xc4(r30)
/* 803E83D0 003E5310  38 A5 30 31 */	addi r5, r5, 0x6B673031@l
/* 803E83D4 003E5314  C0 02 19 CC */	lfs f0, lbl_8051FD2C@sda21(r2)
/* 803E83D8 003E5318  38 DF 00 80 */	addi r6, r31, 0x80
/* 803E83DC 003E531C  D0 3E 00 CC */	stfs f1, 0xcc(r30)
/* 803E83E0 003E5320  D0 1E 00 D0 */	stfs f0, 0xd0(r30)
/* 803E83E4 003E5324  48 02 B2 75 */	bl __ct__8BaseParmFP10ParametersUlPc
/* 803E83E8 003E5328  3C 60 80 4B */	lis r3, "__vt__7Parm<f>"@ha
/* 803E83EC 003E532C  3C A0 6B 67 */	lis r5, 0x6B673135@ha
/* 803E83F0 003E5330  38 03 AC BC */	addi r0, r3, "__vt__7Parm<f>"@l
/* 803E83F4 003E5334  C0 02 19 B8 */	lfs f0, lbl_8051FD18@sda21(r2)
/* 803E83F8 003E5338  90 1E 00 D4 */	stw r0, 0xd4(r30)
/* 803E83FC 003E533C  7F C4 F3 78 */	mr r4, r30
/* 803E8400 003E5340  C0 22 19 A0 */	lfs f1, lbl_8051FD00@sda21(r2)
/* 803E8404 003E5344  38 7E 00 FC */	addi r3, r30, 0xfc
/* 803E8408 003E5348  D0 1E 00 EC */	stfs f0, 0xec(r30)
/* 803E840C 003E534C  38 A5 31 35 */	addi r5, r5, 0x6B673135@l
/* 803E8410 003E5350  C0 02 19 D0 */	lfs f0, lbl_8051FD30@sda21(r2)
/* 803E8414 003E5354  38 DF 00 8C */	addi r6, r31, 0x8c
/* 803E8418 003E5358  D0 3E 00 F4 */	stfs f1, 0xf4(r30)
/* 803E841C 003E535C  D0 1E 00 F8 */	stfs f0, 0xf8(r30)
/* 803E8420 003E5360  48 02 B2 39 */	bl __ct__8BaseParmFP10ParametersUlPc
/* 803E8424 003E5364  3C 60 80 4B */	lis r3, "__vt__7Parm<f>"@ha
/* 803E8428 003E5368  3C A0 6B 67 */	lis r5, 0x6B673130@ha
/* 803E842C 003E536C  38 03 AC BC */	addi r0, r3, "__vt__7Parm<f>"@l
/* 803E8430 003E5370  C0 02 19 D4 */	lfs f0, lbl_8051FD34@sda21(r2)
/* 803E8434 003E5374  90 1E 00 FC */	stw r0, 0xfc(r30)
/* 803E8438 003E5378  7F C4 F3 78 */	mr r4, r30
/* 803E843C 003E537C  C0 22 19 A0 */	lfs f1, lbl_8051FD00@sda21(r2)
/* 803E8440 003E5380  38 7E 01 24 */	addi r3, r30, 0x124
/* 803E8444 003E5384  D0 1E 01 14 */	stfs f0, 0x114(r30)
/* 803E8448 003E5388  38 A5 31 30 */	addi r5, r5, 0x6B673130@l
/* 803E844C 003E538C  C0 02 19 A8 */	lfs f0, lbl_8051FD08@sda21(r2)
/* 803E8450 003E5390  38 DF 00 98 */	addi r6, r31, 0x98
/* 803E8454 003E5394  D0 3E 01 1C */	stfs f1, 0x11c(r30)
/* 803E8458 003E5398  D0 1E 01 20 */	stfs f0, 0x120(r30)
/* 803E845C 003E539C  48 02 B1 FD */	bl __ct__8BaseParmFP10ParametersUlPc
/* 803E8460 003E53A0  3C 60 80 4B */	lis r3, "__vt__7Parm<f>"@ha
/* 803E8464 003E53A4  3C A0 6B 67 */	lis r5, 0x6B673131@ha
/* 803E8468 003E53A8  38 03 AC BC */	addi r0, r3, "__vt__7Parm<f>"@l
/* 803E846C 003E53AC  C0 02 19 A8 */	lfs f0, lbl_8051FD08@sda21(r2)
/* 803E8470 003E53B0  90 1E 01 24 */	stw r0, 0x124(r30)
/* 803E8474 003E53B4  7F C4 F3 78 */	mr r4, r30
/* 803E8478 003E53B8  C0 22 19 A0 */	lfs f1, lbl_8051FD00@sda21(r2)
/* 803E847C 003E53BC  38 7E 01 4C */	addi r3, r30, 0x14c
/* 803E8480 003E53C0  D0 1E 01 3C */	stfs f0, 0x13c(r30)
/* 803E8484 003E53C4  38 A5 31 31 */	addi r5, r5, 0x6B673131@l
/* 803E8488 003E53C8  C0 02 19 B8 */	lfs f0, lbl_8051FD18@sda21(r2)
/* 803E848C 003E53CC  38 DF 00 AC */	addi r6, r31, 0xac
/* 803E8490 003E53D0  D0 3E 01 44 */	stfs f1, 0x144(r30)
/* 803E8494 003E53D4  D0 1E 01 48 */	stfs f0, 0x148(r30)
/* 803E8498 003E53D8  48 02 B1 C1 */	bl __ct__8BaseParmFP10ParametersUlPc
/* 803E849C 003E53DC  3C 60 80 4B */	lis r3, "__vt__7Parm<f>"@ha
/* 803E84A0 003E53E0  3C A0 6B 67 */	lis r5, 0x6B673132@ha
/* 803E84A4 003E53E4  38 03 AC BC */	addi r0, r3, "__vt__7Parm<f>"@l
/* 803E84A8 003E53E8  C0 02 19 D8 */	lfs f0, lbl_8051FD38@sda21(r2)
/* 803E84AC 003E53EC  90 1E 01 4C */	stw r0, 0x14c(r30)
/* 803E84B0 003E53F0  7F C4 F3 78 */	mr r4, r30
/* 803E84B4 003E53F4  C0 22 19 A0 */	lfs f1, lbl_8051FD00@sda21(r2)
/* 803E84B8 003E53F8  38 7E 01 74 */	addi r3, r30, 0x174
/* 803E84BC 003E53FC  D0 1E 01 64 */	stfs f0, 0x164(r30)
/* 803E84C0 003E5400  38 A5 31 32 */	addi r5, r5, 0x6B673132@l
/* 803E84C4 003E5404  C0 02 19 B8 */	lfs f0, lbl_8051FD18@sda21(r2)
/* 803E84C8 003E5408  38 DF 00 C0 */	addi r6, r31, 0xc0
/* 803E84CC 003E540C  D0 3E 01 6C */	stfs f1, 0x16c(r30)
/* 803E84D0 003E5410  D0 1E 01 70 */	stfs f0, 0x170(r30)
/* 803E84D4 003E5414  48 02 B1 85 */	bl __ct__8BaseParmFP10ParametersUlPc
/* 803E84D8 003E5418  3C 60 80 4B */	lis r3, "__vt__7Parm<f>"@ha
/* 803E84DC 003E541C  3C A0 6B 67 */	lis r5, 0x6B673133@ha
/* 803E84E0 003E5420  38 03 AC BC */	addi r0, r3, "__vt__7Parm<f>"@l
/* 803E84E4 003E5424  C0 02 19 DC */	lfs f0, lbl_8051FD3C@sda21(r2)
/* 803E84E8 003E5428  90 1E 01 74 */	stw r0, 0x174(r30)
/* 803E84EC 003E542C  7F C4 F3 78 */	mr r4, r30
/* 803E84F0 003E5430  C0 22 19 A0 */	lfs f1, lbl_8051FD00@sda21(r2)
/* 803E84F4 003E5434  38 7E 01 9C */	addi r3, r30, 0x19c
/* 803E84F8 003E5438  D0 1E 01 8C */	stfs f0, 0x18c(r30)
/* 803E84FC 003E543C  38 A5 31 33 */	addi r5, r5, 0x6B673133@l
/* 803E8500 003E5440  C0 02 19 B8 */	lfs f0, lbl_8051FD18@sda21(r2)
/* 803E8504 003E5444  38 DF 00 D4 */	addi r6, r31, 0xd4
/* 803E8508 003E5448  D0 3E 01 94 */	stfs f1, 0x194(r30)
/* 803E850C 003E544C  D0 1E 01 98 */	stfs f0, 0x198(r30)
/* 803E8510 003E5450  48 02 B1 49 */	bl __ct__8BaseParmFP10ParametersUlPc
/* 803E8514 003E5454  3C 60 80 4B */	lis r3, "__vt__7Parm<f>"@ha
/* 803E8518 003E5458  3C A0 6B 67 */	lis r5, 0x6B673134@ha
/* 803E851C 003E545C  38 03 AC BC */	addi r0, r3, "__vt__7Parm<f>"@l
/* 803E8520 003E5460  C0 02 19 A8 */	lfs f0, lbl_8051FD08@sda21(r2)
/* 803E8524 003E5464  90 1E 01 9C */	stw r0, 0x19c(r30)
/* 803E8528 003E5468  7F C4 F3 78 */	mr r4, r30
/* 803E852C 003E546C  C0 22 19 A0 */	lfs f1, lbl_8051FD00@sda21(r2)
/* 803E8530 003E5470  38 7E 01 C4 */	addi r3, r30, 0x1c4
/* 803E8534 003E5474  D0 1E 01 B4 */	stfs f0, 0x1b4(r30)
/* 803E8538 003E5478  38 A5 31 34 */	addi r5, r5, 0x6B673134@l
/* 803E853C 003E547C  C0 02 19 B8 */	lfs f0, lbl_8051FD18@sda21(r2)
/* 803E8540 003E5480  38 DF 00 E8 */	addi r6, r31, 0xe8
/* 803E8544 003E5484  D0 3E 01 BC */	stfs f1, 0x1bc(r30)
/* 803E8548 003E5488  D0 1E 01 C0 */	stfs f0, 0x1c0(r30)
/* 803E854C 003E548C  48 02 B1 0D */	bl __ct__8BaseParmFP10ParametersUlPc
/* 803E8550 003E5490  3C 60 80 4B */	lis r3, "__vt__7Parm<f>"@ha
/* 803E8554 003E5494  C0 42 19 E0 */	lfs f2, lbl_8051FD40@sda21(r2)
/* 803E8558 003E5498  38 03 AC BC */	addi r0, r3, "__vt__7Parm<f>"@l
/* 803E855C 003E549C  C0 22 19 A0 */	lfs f1, lbl_8051FD00@sda21(r2)
/* 803E8560 003E54A0  90 1E 01 C4 */	stw r0, 0x1c4(r30)
/* 803E8564 003E54A4  7F C3 F3 78 */	mr r3, r30
/* 803E8568 003E54A8  C0 02 19 C8 */	lfs f0, lbl_8051FD28@sda21(r2)
/* 803E856C 003E54AC  D0 5E 01 DC */	stfs f2, 0x1dc(r30)
/* 803E8570 003E54B0  D0 3E 01 E4 */	stfs f1, 0x1e4(r30)
/* 803E8574 003E54B4  D0 1E 01 E8 */	stfs f0, 0x1e8(r30)
/* 803E8578 003E54B8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 803E857C 003E54BC  83 C1 00 08 */	lwz r30, 8(r1)
/* 803E8580 003E54C0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 803E8584 003E54C4  7C 08 03 A6 */	mtlr r0
/* 803E8588 003E54C8  38 21 00 10 */	addi r1, r1, 0x10
/* 803E858C 003E54CC  4E 80 00 20 */	blr 
.endfn __ct__Q43ebi5title6Kogane6TParamFv

.fn getCreatureType__Q43ebi5title6Kogane5TUnitFv, weak
/* 803E8590 003E54D0  38 60 00 05 */	li r3, 5
/* 803E8594 003E54D4  4E 80 00 20 */	blr 
.endfn getCreatureType__Q43ebi5title6Kogane5TUnitFv

.fn getAnimRes__Q43ebi5title6Kogane11TAnimFolderFl, weak
/* 803E8598 003E54D8  54 84 28 34 */	slwi r4, r4, 5
/* 803E859C 003E54DC  7C 60 1B 78 */	mr r0, r3
/* 803E85A0 003E54E0  38 64 00 04 */	addi r3, r4, 4
/* 803E85A4 003E54E4  7C 60 1A 14 */	add r3, r0, r3
/* 803E85A8 003E54E8  4E 80 00 20 */	blr 
.endfn getAnimRes__Q43ebi5title6Kogane11TAnimFolderFl

.fn __ct__Q23ebi10E3DAnimResFv, weak
/* 803E85AC 003E54EC  4E 80 00 20 */	blr 
.endfn __ct__Q23ebi10E3DAnimResFv

.fn __sinit_ebiP2TitleKogane_cpp, local
/* 803E85B0 003E54F0  3C 80 80 51 */	lis r4, __float_nan@ha
/* 803E85B4 003E54F4  38 00 FF FF */	li r0, -1
/* 803E85B8 003E54F8  C0 04 48 B0 */	lfs f0, __float_nan@l(r4)
/* 803E85BC 003E54FC  3C 60 80 4F */	lis r3, govNAN___Q24Game5P2JST@ha
/* 803E85C0 003E5500  90 0D 9A 78 */	stw r0, gu32NAN___Q24Game5P2JST@sda21(r13)
/* 803E85C4 003E5504  D4 03 9E 10 */	stfsu f0, govNAN___Q24Game5P2JST@l(r3)
/* 803E85C8 003E5508  D0 0D 9A 7C */	stfs f0, gfNAN___Q24Game5P2JST@sda21(r13)
/* 803E85CC 003E550C  D0 03 00 04 */	stfs f0, 4(r3)
/* 803E85D0 003E5510  D0 03 00 08 */	stfs f0, 8(r3)
/* 803E85D4 003E5514  4E 80 00 20 */	blr 
.endfn __sinit_ebiP2TitleKogane_cpp
