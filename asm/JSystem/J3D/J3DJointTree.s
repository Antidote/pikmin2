.include "macros.inc"

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.global __ct__12J3DJointTreeFv
__ct__12J3DJointTreeFv:
/* 8008828C 000851CC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80088290 000851D0  7C 08 02 A6 */	mflr r0
/* 80088294 000851D4  3C 80 80 4A */	lis r4, __vt__12J3DJointTree@ha
/* 80088298 000851D8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8008829C 000851DC  38 00 00 00 */	li r0, 0
/* 800882A0 000851E0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800882A4 000851E4  7C 7F 1B 78 */	mr r31, r3
/* 800882A8 000851E8  38 64 2F BC */	addi r3, r4, __vt__12J3DJointTree@l
/* 800882AC 000851EC  90 7F 00 00 */	stw r3, 0(r31)
/* 800882B0 000851F0  38 7F 00 34 */	addi r3, r31, 0x34
/* 800882B4 000851F4  90 1F 00 04 */	stw r0, 4(r31)
/* 800882B8 000851F8  90 1F 00 08 */	stw r0, 8(r31)
/* 800882BC 000851FC  90 1F 00 0C */	stw r0, 0xc(r31)
/* 800882C0 00085200  90 1F 00 10 */	stw r0, 0x10(r31)
/* 800882C4 00085204  90 1F 00 14 */	stw r0, 0x14(r31)
/* 800882C8 00085208  90 1F 00 18 */	stw r0, 0x18(r31)
/* 800882CC 0008520C  B0 1F 00 1C */	sth r0, 0x1c(r31)
/* 800882D0 00085210  B0 1F 00 1E */	sth r0, 0x1e(r31)
/* 800882D4 00085214  90 1F 00 20 */	stw r0, 0x20(r31)
/* 800882D8 00085218  90 1F 00 24 */	stw r0, 0x24(r31)
/* 800882DC 0008521C  90 1F 00 28 */	stw r0, 0x28(r31)
/* 800882E0 00085220  90 1F 00 2C */	stw r0, 0x2c(r31)
/* 800882E4 00085224  90 1F 00 30 */	stw r0, 0x30(r31)
/* 800882E8 00085228  4B FD 6B 41 */	bl __ct__14J3DDrawMtxDataFv
/* 800882EC 0008522C  38 00 00 00 */	li r0, 0
/* 800882F0 00085230  7F E3 FB 78 */	mr r3, r31
/* 800882F4 00085234  90 1F 00 40 */	stw r0, 0x40(r31)
/* 800882F8 00085238  90 1F 00 44 */	stw r0, 0x44(r31)
/* 800882FC 0008523C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80088300 00085240  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80088304 00085244  7C 08 03 A6 */	mtlr r0
/* 80088308 00085248  38 21 00 10 */	addi r1, r1, 0x10
/* 8008830C 0008524C  4E 80 00 20 */	blr 

.global makeHierarchy__12J3DJointTreeFP8J3DJointPPC17J3DModelHierarchyP16J3DMaterialTableP13J3DShapeTable
makeHierarchy__12J3DJointTreeFP8J3DJointPPC17J3DModelHierarchyP16J3DMaterialTableP13J3DShapeTable:
/* 80088310 00085250  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80088314 00085254  7C 08 02 A6 */	mflr r0
/* 80088318 00085258  90 01 00 34 */	stw r0, 0x34(r1)
/* 8008831C 0008525C  BE E1 00 0C */	stmw r23, 0xc(r1)
/* 80088320 00085260  7C 98 23 78 */	mr r24, r4
/* 80088324 00085264  7C 77 1B 78 */	mr r23, r3
/* 80088328 00085268  7C B9 2B 78 */	mr r25, r5
/* 8008832C 0008526C  7C DA 33 78 */	mr r26, r6
/* 80088330 00085270  7C FB 3B 78 */	mr r27, r7
/* 80088334 00085274  7F 1F C3 78 */	mr r31, r24
lbl_80088338:
/* 80088338 00085278  80 99 00 00 */	lwz r4, 0(r25)
/* 8008833C 0008527C  3B C0 00 00 */	li r30, 0
/* 80088340 00085280  3B A0 00 00 */	li r29, 0
/* 80088344 00085284  3B 80 00 00 */	li r28, 0
/* 80088348 00085288  A0 04 00 00 */	lhz r0, 0(r4)
/* 8008834C 0008528C  28 00 00 12 */	cmplwi r0, 0x12
/* 80088350 00085290  41 81 00 A0 */	bgt lbl_800883F0
/* 80088354 00085294  3C 60 80 4A */	lis r3, lbl_804A2F70@ha
/* 80088358 00085298  54 00 10 3A */	slwi r0, r0, 2
/* 8008835C 0008529C  38 63 2F 70 */	addi r3, r3, lbl_804A2F70@l
/* 80088360 000852A0  7C 03 00 2E */	lwzx r0, r3, r0
/* 80088364 000852A4  7C 09 03 A6 */	mtctr r0
/* 80088368 000852A8  4E 80 04 20 */	bctr 
.global lbl_8008836C
lbl_8008836C:
/* 8008836C 000852AC  38 04 00 04 */	addi r0, r4, 4
/* 80088370 000852B0  7E E3 BB 78 */	mr r3, r23
/* 80088374 000852B4  90 19 00 00 */	stw r0, 0(r25)
/* 80088378 000852B8  7F E4 FB 78 */	mr r4, r31
/* 8008837C 000852BC  7F 25 CB 78 */	mr r5, r25
/* 80088380 000852C0  7F 46 D3 78 */	mr r6, r26
/* 80088384 000852C4  7F 67 DB 78 */	mr r7, r27
/* 80088388 000852C8  4B FF FF 89 */	bl makeHierarchy__12J3DJointTreeFP8J3DJointPPC17J3DModelHierarchyP16J3DMaterialTableP13J3DShapeTable
/* 8008838C 000852CC  48 00 00 64 */	b lbl_800883F0
.global lbl_80088390
lbl_80088390:
/* 80088390 000852D0  38 04 00 04 */	addi r0, r4, 4
/* 80088394 000852D4  90 19 00 00 */	stw r0, 0(r25)
/* 80088398 000852D8  48 00 00 C0 */	b lbl_80088458
.global lbl_8008839C
lbl_8008839C:
/* 8008839C 000852DC  48 00 00 BC */	b lbl_80088458
.global lbl_800883A0
lbl_800883A0:
/* 800883A0 000852E0  80 77 00 18 */	lwz r3, 0x18(r23)
/* 800883A4 000852E4  38 04 00 04 */	addi r0, r4, 4
/* 800883A8 000852E8  90 19 00 00 */	stw r0, 0(r25)
/* 800883AC 000852EC  A0 04 00 02 */	lhz r0, 2(r4)
/* 800883B0 000852F0  54 00 10 3A */	slwi r0, r0, 2
/* 800883B4 000852F4  7F C3 00 2E */	lwzx r30, r3, r0
/* 800883B8 000852F8  48 00 00 38 */	b lbl_800883F0
.global lbl_800883BC
lbl_800883BC:
/* 800883BC 000852FC  38 04 00 04 */	addi r0, r4, 4
/* 800883C0 00085300  90 19 00 00 */	stw r0, 0(r25)
/* 800883C4 00085304  A0 04 00 02 */	lhz r0, 2(r4)
/* 800883C8 00085308  80 7A 00 08 */	lwz r3, 8(r26)
/* 800883CC 0008530C  54 00 13 BA */	rlwinm r0, r0, 2, 0xe, 0x1d
/* 800883D0 00085310  7F A3 00 2E */	lwzx r29, r3, r0
/* 800883D4 00085314  48 00 00 1C */	b lbl_800883F0
.global lbl_800883D8
lbl_800883D8:
/* 800883D8 00085318  38 04 00 04 */	addi r0, r4, 4
/* 800883DC 0008531C  90 19 00 00 */	stw r0, 0(r25)
/* 800883E0 00085320  A0 04 00 02 */	lhz r0, 2(r4)
/* 800883E4 00085324  80 7B 00 08 */	lwz r3, 8(r27)
/* 800883E8 00085328  54 00 13 BA */	rlwinm r0, r0, 2, 0xe, 0x1d
/* 800883EC 0008532C  7F 83 00 2E */	lwzx r28, r3, r0
.global lbl_800883F0
lbl_800883F0:
/* 800883F0 00085330  28 1E 00 00 */	cmplwi r30, 0
/* 800883F4 00085334  41 82 00 28 */	beq lbl_8008841C
/* 800883F8 00085338  28 18 00 00 */	cmplwi r24, 0
/* 800883FC 0008533C  7F DF F3 78 */	mr r31, r30
/* 80088400 00085340  40 82 00 0C */	bne lbl_8008840C
/* 80088404 00085344  93 D7 00 10 */	stw r30, 0x10(r23)
/* 80088408 00085348  4B FF FF 30 */	b lbl_80088338
lbl_8008840C:
/* 8008840C 0008534C  7F 03 C3 78 */	mr r3, r24
/* 80088410 00085350  7F C4 F3 78 */	mr r4, r30
/* 80088414 00085354  4B FE 34 75 */	bl appendChild__8J3DJointFP8J3DJoint
/* 80088418 00085358  4B FF FF 20 */	b lbl_80088338
lbl_8008841C:
/* 8008841C 0008535C  28 1D 00 00 */	cmplwi r29, 0
/* 80088420 00085360  41 82 00 20 */	beq lbl_80088440
/* 80088424 00085364  80 18 00 58 */	lwz r0, 0x58(r24)
/* 80088428 00085368  28 00 00 00 */	cmplwi r0, 0
/* 8008842C 0008536C  41 82 00 08 */	beq lbl_80088434
/* 80088430 00085370  90 1D 00 04 */	stw r0, 4(r29)
lbl_80088434:
/* 80088434 00085374  93 B8 00 58 */	stw r29, 0x58(r24)
/* 80088438 00085378  93 1D 00 0C */	stw r24, 0xc(r29)
/* 8008843C 0008537C  4B FF FE FC */	b lbl_80088338
lbl_80088440:
/* 80088440 00085380  28 1C 00 00 */	cmplwi r28, 0
/* 80088444 00085384  41 82 FE F4 */	beq lbl_80088338
/* 80088448 00085388  80 78 00 58 */	lwz r3, 0x58(r24)
/* 8008844C 0008538C  93 83 00 08 */	stw r28, 8(r3)
/* 80088450 00085390  90 7C 00 04 */	stw r3, 4(r28)
/* 80088454 00085394  4B FF FE E4 */	b lbl_80088338
lbl_80088458:
/* 80088458 00085398  BA E1 00 0C */	lmw r23, 0xc(r1)
/* 8008845C 0008539C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80088460 000853A0  7C 08 03 A6 */	mtlr r0
/* 80088464 000853A4  38 21 00 30 */	addi r1, r1, 0x30
/* 80088468 000853A8  4E 80 00 20 */	blr 

.global findImportantMtxIndex__12J3DJointTreeFv
findImportantMtxIndex__12J3DJointTreeFv:
/* 8008846C 000853AC  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80088470 000853B0  39 20 00 00 */	li r9, 0
/* 80088474 000853B4  BF 21 00 14 */	stmw r25, 0x14(r1)
/* 80088478 000853B8  A0 83 00 36 */	lhz r4, 0x36(r3)
/* 8008847C 000853BC  A0 03 00 1E */	lhz r0, 0x1e(r3)
/* 80088480 000853C0  28 04 00 00 */	cmplwi r4, 0
/* 80088484 000853C4  80 E3 00 24 */	lwz r7, 0x24(r3)
/* 80088488 000853C8  80 C3 00 28 */	lwz r6, 0x28(r3)
/* 8008848C 000853CC  80 A3 00 30 */	lwz r5, 0x30(r3)
/* 80088490 000853D0  40 81 00 D0 */	ble lbl_80088560
/* 80088494 000853D4  28 04 00 08 */	cmplwi r4, 8
/* 80088498 000853D8  39 04 FF F8 */	addi r8, r4, -8
/* 8008849C 000853DC  40 81 00 B8 */	ble lbl_80088554
/* 800884A0 000853E0  55 0A 04 3E */	clrlwi r10, r8, 0x10
/* 800884A4 000853E4  48 00 00 8C */	b lbl_80088530
lbl_800884A8:
/* 800884A8 000853E8  81 03 00 3C */	lwz r8, 0x3c(r3)
/* 800884AC 000853EC  55 39 0B FC */	rlwinm r25, r9, 1, 0xf, 0x1e
/* 800884B0 000853F0  3B 79 00 02 */	addi r27, r25, 2
/* 800884B4 000853F4  39 29 00 08 */	addi r9, r9, 8
/* 800884B8 000853F8  7D 68 CA 2E */	lhzx r11, r8, r25
/* 800884BC 000853FC  7D 05 CA 14 */	add r8, r5, r25
/* 800884C0 00085400  3B 99 00 04 */	addi r28, r25, 4
/* 800884C4 00085404  3B B9 00 06 */	addi r29, r25, 6
/* 800884C8 00085408  B1 68 00 00 */	sth r11, 0(r8)
/* 800884CC 0008540C  3B D9 00 08 */	addi r30, r25, 8
/* 800884D0 00085410  3B F9 00 0A */	addi r31, r25, 0xa
/* 800884D4 00085414  39 99 00 0C */	addi r12, r25, 0xc
/* 800884D8 00085418  83 43 00 3C */	lwz r26, 0x3c(r3)
/* 800884DC 0008541C  39 79 00 0E */	addi r11, r25, 0xe
/* 800884E0 00085420  7F 7A DA 2E */	lhzx r27, r26, r27
/* 800884E4 00085424  B3 68 00 02 */	sth r27, 2(r8)
/* 800884E8 00085428  83 63 00 3C */	lwz r27, 0x3c(r3)
/* 800884EC 0008542C  7F 9B E2 2E */	lhzx r28, r27, r28
/* 800884F0 00085430  B3 88 00 04 */	sth r28, 4(r8)
/* 800884F4 00085434  83 83 00 3C */	lwz r28, 0x3c(r3)
/* 800884F8 00085438  7F BC EA 2E */	lhzx r29, r28, r29
/* 800884FC 0008543C  B3 A8 00 06 */	sth r29, 6(r8)
/* 80088500 00085440  83 A3 00 3C */	lwz r29, 0x3c(r3)
/* 80088504 00085444  7F DD F2 2E */	lhzx r30, r29, r30
/* 80088508 00085448  B3 C8 00 08 */	sth r30, 8(r8)
/* 8008850C 0008544C  83 C3 00 3C */	lwz r30, 0x3c(r3)
/* 80088510 00085450  7F FE FA 2E */	lhzx r31, r30, r31
/* 80088514 00085454  B3 E8 00 0A */	sth r31, 0xa(r8)
/* 80088518 00085458  83 E3 00 3C */	lwz r31, 0x3c(r3)
/* 8008851C 0008545C  7D 9F 62 2E */	lhzx r12, r31, r12
/* 80088520 00085460  B1 88 00 0C */	sth r12, 0xc(r8)
/* 80088524 00085464  81 83 00 3C */	lwz r12, 0x3c(r3)
/* 80088528 00085468  7D 6C 5A 2E */	lhzx r11, r12, r11
/* 8008852C 0008546C  B1 68 00 0E */	sth r11, 0xe(r8)
lbl_80088530:
/* 80088530 00085470  55 28 04 3E */	clrlwi r8, r9, 0x10
/* 80088534 00085474  7C 08 50 40 */	cmplw r8, r10
/* 80088538 00085478  41 80 FF 70 */	blt lbl_800884A8
/* 8008853C 0008547C  48 00 00 18 */	b lbl_80088554
lbl_80088540:
/* 80088540 00085480  81 03 00 3C */	lwz r8, 0x3c(r3)
/* 80088544 00085484  55 2A 0B FC */	rlwinm r10, r9, 1, 0xf, 0x1e
/* 80088548 00085488  39 29 00 01 */	addi r9, r9, 1
/* 8008854C 0008548C  7D 08 52 2E */	lhzx r8, r8, r10
/* 80088550 00085490  7D 05 53 2E */	sthx r8, r5, r10
lbl_80088554:
/* 80088554 00085494  55 28 04 3E */	clrlwi r8, r9, 0x10
/* 80088558 00085498  7C 08 20 40 */	cmplw r8, r4
/* 8008855C 0008549C  41 80 FF E4 */	blt lbl_80088540
lbl_80088560:
/* 80088560 000854A0  39 60 00 00 */	li r11, 0
/* 80088564 000854A4  48 00 00 68 */	b lbl_800885CC
lbl_80088568:
/* 80088568 000854A8  81 03 00 20 */	lwz r8, 0x20(r3)
/* 8008856C 000854AC  55 64 04 3E */	clrlwi r4, r11, 0x10
/* 80088570 000854B0  7C C9 33 78 */	mr r9, r6
/* 80088574 000854B4  7C EA 3B 78 */	mr r10, r7
/* 80088578 000854B8  7C 88 20 AE */	lbzx r4, r8, r4
/* 8008857C 000854BC  39 00 00 00 */	li r8, 0
/* 80088580 000854C0  C0 22 87 90 */	lfs f1, lbl_80516AF0@sda21(r2)
/* 80088584 000854C4  7C 89 03 A6 */	mtctr r4
/* 80088588 000854C8  2C 04 00 00 */	cmpwi r4, 0
/* 8008858C 000854CC  40 81 00 2C */	ble lbl_800885B8
lbl_80088590:
/* 80088590 000854D0  C0 09 00 00 */	lfs f0, 0(r9)
/* 80088594 000854D4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80088598 000854D8  40 80 00 0C */	bge lbl_800885A4
/* 8008859C 000854DC  FC 20 00 90 */	fmr f1, f0
/* 800885A0 000854E0  A1 0A 00 00 */	lhz r8, 0(r10)
lbl_800885A4:
/* 800885A4 000854E4  39 29 00 04 */	addi r9, r9, 4
/* 800885A8 000854E8  39 4A 00 02 */	addi r10, r10, 2
/* 800885AC 000854EC  38 C6 00 04 */	addi r6, r6, 4
/* 800885B0 000854F0  38 E7 00 02 */	addi r7, r7, 2
/* 800885B4 000854F4  42 00 FF DC */	bdnz lbl_80088590
lbl_800885B8:
/* 800885B8 000854F8  A0 83 00 36 */	lhz r4, 0x36(r3)
/* 800885BC 000854FC  7C 8B 22 14 */	add r4, r11, r4
/* 800885C0 00085500  39 6B 00 01 */	addi r11, r11, 1
/* 800885C4 00085504  54 84 08 3C */	slwi r4, r4, 1
/* 800885C8 00085508  7D 05 23 2E */	sthx r8, r5, r4
lbl_800885CC:
/* 800885CC 0008550C  7C 0B 00 00 */	cmpw r11, r0
/* 800885D0 00085510  41 80 FF 98 */	blt lbl_80088568
/* 800885D4 00085514  BB 21 00 14 */	lmw r25, 0x14(r1)
/* 800885D8 00085518  38 21 00 30 */	addi r1, r1, 0x30
/* 800885DC 0008551C  4E 80 00 20 */	blr 

.global calc__12J3DJointTreeFP12J3DMtxBufferRC3VecRA3_A4_Cf
calc__12J3DJointTreeFP12J3DMtxBufferRC3VecRA3_A4_Cf:
/* 800885E0 00085520  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800885E4 00085524  7C 08 02 A6 */	mflr r0
/* 800885E8 00085528  90 01 00 14 */	stw r0, 0x14(r1)
/* 800885EC 0008552C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800885F0 00085530  7C 9F 23 78 */	mr r31, r4
/* 800885F4 00085534  7C A4 2B 78 */	mr r4, r5
/* 800885F8 00085538  7C C5 33 78 */	mr r5, r6
/* 800885FC 0008553C  93 C1 00 08 */	stw r30, 8(r1)
/* 80088600 00085540  7C 7E 1B 78 */	mr r30, r3
/* 80088604 00085544  80 63 00 14 */	lwz r3, 0x14(r3)
/* 80088608 00085548  81 83 00 00 */	lwz r12, 0(r3)
/* 8008860C 0008554C  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80088610 00085550  7D 89 03 A6 */	mtctr r12
/* 80088614 00085554  4E 80 04 21 */	bctrl 
/* 80088618 00085558  7F E3 FB 78 */	mr r3, r31
/* 8008861C 0008555C  48 00 00 35 */	bl setMtxBuffer__10J3DMtxCalcFP12J3DMtxBuffer
/* 80088620 00085560  80 7E 00 10 */	lwz r3, 0x10(r30)
/* 80088624 00085564  28 03 00 00 */	cmplwi r3, 0
/* 80088628 00085568  41 82 00 10 */	beq lbl_80088638
/* 8008862C 0008556C  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 80088630 00085570  90 0D 89 90 */	stw r0, mCurrentMtxCalc__8J3DJoint@sda21(r13)
/* 80088634 00085574  4B FE 35 21 */	bl recursiveCalc__8J3DJointFv
lbl_80088638:
/* 80088638 00085578  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8008863C 0008557C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80088640 00085580  83 C1 00 08 */	lwz r30, 8(r1)
/* 80088644 00085584  7C 08 03 A6 */	mtlr r0
/* 80088648 00085588  38 21 00 10 */	addi r1, r1, 0x10
/* 8008864C 0008558C  4E 80 00 20 */	blr 

.global setMtxBuffer__10J3DMtxCalcFP12J3DMtxBuffer
setMtxBuffer__10J3DMtxCalcFP12J3DMtxBuffer:
/* 80088650 00085590  90 6D 89 88 */	stw r3, mMtxBuffer__10J3DMtxCalc@sda21(r13)
/* 80088654 00085594  4E 80 00 20 */	blr 
