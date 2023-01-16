#ifndef _EBI_E2DCALLBACK_H
#define _EBI_E2DCALLBACK_H

#include "ebi/E2DFullFontColor.h"
#include "JSystem/J2D/J2DGrafContext.h"
#include "JSystem/J3D/J3DAnmBase.h"
#include "JSystem/J3D/J3DFrameCtrl.h"
#include "JSystem/JGeometry.h"
#include "og/Screen/ScaleMgr.h"
#include "P2DScreen.h"
#include "types.h"

namespace ebi {
struct E2DCallBack_Base : public P2DScreen::CallBackNode {
	inline E2DCallBack_Base()
	    : m_isEnabled(1)
	{
	}
	virtual ~E2DCallBack_Base();                      // _08 (weak)
	virtual void update();                            // _10 (weak)
	virtual void draw(Graphics&, J2DGrafContext&);    // _14 (weak)
	virtual void do_update();                         // _1C (weak)
	virtual void do_draw(Graphics&, J2DGrafContext&); // _20 (weak)

	bool m_isEnabled; // _1C
};

// Size: 0x3C
struct E2DCallBack_AnmBase : public E2DCallBack_Base {
	E2DCallBack_AnmBase();

	virtual ~E2DCallBack_AnmBase(); // _08 (weak)
	virtual void do_update();       // _1C

	void loadAnm(char*, JKRArchive*, long, long);
	void play(f32, J3DAnmAttr, bool);
	void playBack(f32, bool);
	void stop();
	void setStartFrame();
	void setEndFrame();
	void setRandFrame();
	f32 getPlayFinRate();
	bool isFinish();

	J3DFrameCtrl m_frameCtrl; // _20
	J2DAnmBase* m_anim;       // _34
	bool m_isFinished;        // _38
};

struct E2DCallBack_BlinkAlpha : public E2DCallBack_Base {
	virtual ~E2DCallBack_BlinkAlpha(); // _08 (weak)
	virtual void do_update();          // _1C

	// TODO: _20 through _29 and BlinkFontColor's _40 through _49 are
	// suspiciously similar in usage....
	f32 _20; // _20
	f32 _24; // _24
	u8 _28;  // _28
	u8 _29;  // _29
	u32 : 0; // set alignment to next 4-byte boundary
	u8 _2C;  // _2C
	u8 _2D;  // _2D
};

// Size: 0x4C
struct E2DCallBack_BlinkFontColor : public E2DCallBack_Base {
	E2DCallBack_BlinkFontColor();

	virtual ~E2DCallBack_BlinkFontColor(); // _08 (weak)
	virtual void do_update();              // _1C

	void set(J2DTextBox*, J2DTextBox*);
	void set(ebi::E2DFullFontColor&, ebi::E2DFullFontColor&);

	inline void setColors(int i, J2DTextBox* pane)
	{
		m_fonts[i].m_col1.set(pane->m_color1);
		m_fonts[i].m_col2.set(pane->m_color2);
		m_fonts[i].m_white = pane->getWhite();
		m_fonts[i].m_black = pane->getBlack();
	}

	// needs tweaking
	inline void setPaneColors()
	{
		m_isEnabled      = false;
		J2DTextBox* pane = static_cast<J2DTextBox*>(m_pane);
		if (pane) {
			pane->m_color1.set(m_fonts[0].m_col1);
			pane->m_color2.set(m_fonts[0].m_col2);
			JUtility::TColor white = m_fonts[0].m_white;
			pane->setWhite(white);
			JUtility::TColor black = m_fonts[0].m_black;
			pane->setBlack(black);
		}
	}

	E2DFullFontColor m_fonts[2]; // _20
	f32 _40;                     // _40
	f32 m_speed;                 // _44
	u8 _48;                      // _48
	u8 _49;                      // _49
};

struct E2DCallBack_CalcAnimation : public E2DCallBack_Base {
	E2DCallBack_CalcAnimation();

	virtual ~E2DCallBack_CalcAnimation(); // _08 (weak)
	virtual void do_update();             // _1C (weak)
};

// Size: 0x40
struct E2DCallBack_Purupuru : public E2DCallBack_Base {
	E2DCallBack_Purupuru();

	virtual ~E2DCallBack_Purupuru(); // _08 (weak)
	virtual void do_update();        // _1C

	og::Screen::ScaleMgr m_scaleMgr; // _20
	// TODO: Rename to `m_scale`
	f32 _3C; // _3C
};

struct E2DCallBack_WindowCursor : public E2DCallBack_Base {
	virtual ~E2DCallBack_WindowCursor(); // _08 (weak)
	virtual void do_update();            // _1C

	JGeometry::TBox2f _20;    // _20
	JGeometry::TBox2f _30;    // _30
	u32 _40;                  // _40
	u32 _44;                  // _44
	og::Screen::ScaleMgr _48; // _48
	f32 _64;                  // _64
	J2DPane* _68;             // _68
};
} // namespace ebi

#endif
