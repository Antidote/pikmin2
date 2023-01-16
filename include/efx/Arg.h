#ifndef _EFX_ARG_H
#define _EFX_ARG_H

#include "Game/enemyInfo.h"
#include "types.h"
#include "Vector3.h"

namespace Game {
struct EnemyBase;
struct BaseItem;
struct Onyon;
} // namespace Game

namespace efx {
struct Arg {
	inline Arg()
	    : m_position(Vector3f::zero)
	{
	}

	Arg(const Vector3f& position)
	    : m_position(position)
	{
	}

	inline Arg(f32 x, f32 y, f32 z)
	    : m_position(x, y, z)
	{
	}

	inline Arg(Game::EnemyBase*); // defined in Game/EnemyBase.h header to avoid include loops

	inline Arg(Game::BaseItem*); // defined in Game/BaseItem.h header to avoid include loops

	/**
	 * @reifiedAddress{80108200}
	 * @reifiedFile{plugProjectYamashitaU/enemyBase.cpp}
	 */
	virtual const char* getName() // _08 (weak)
	{
		return "Arg";
	}

	Vector3f m_position; // _04
};

struct ArgEnemyType : public Arg {
	ArgEnemyType(Vector3f position, Game::EnemyTypeID::EEnemyTypeID typeID, f32 scale)
	    : Arg(position)
	    , m_typeID(typeID)
	{
		m_scale = scale;
	};
	ArgEnemyType(Vector3f position)
	    : Arg(position) {};

	/**
	 * @reifiedAddress{801081F4}
	 * @reifiedFile{plugProjectYamashitaU/enemyBase.cpp}
	 */
	virtual const char* getName() // _08 (weak)
	{
		return "ArgEnemyType";
	}

	Game::EnemyTypeID::EEnemyTypeID m_typeID;
	f32 m_scale;
};

struct ArgScale : public Arg {
	ArgScale(Vector3f position, f32 scale)
	    : Arg(position)
	{
		m_scale = scale;
	}
	/**
	 * @reifiedAddress{80107C44}
	 * @reifiedFile{plugProjectYamashitaU/enemyBase.cpp}
	 */
	virtual const char* getName() // _08 (weak)
	{
		return "ArgScale";
	}

	f32 m_scale; // _10
};

struct ArgChou : public Arg {
	ArgChou(Vector3f position)
	    : Arg(position)
	{
	}

	virtual const char* getName() // _08 (weak)
	{
		return "ArgChou";
	}
};

struct ArgCursor : public Arg {
	ArgCursor(Vector3f& position, f32 scale)
	    : Arg(position)
	{
		m_scale = scale;
	}

	virtual const char* getName() // _08 (weak)
	{
		return "ArgCursor";
	}

	f32 m_scale; // _10
};

struct ArgDenkiHiba : public Arg {
	ArgDenkiHiba(Vector3f& position)
	    : Arg(position)
	{
	}

	ArgDenkiHiba(Vector3f ownerPos, Vector3f targetPos)
	    : Arg()
	    , m_ownerPos(ownerPos)
	    , m_targetPos(targetPos)
	{
	}

	virtual const char* getName() // _08 (weak)
	{
		return "ArgDenkiHiba";
	}

	// _00     = VTBL
	// _00-_10 = Arg
	Vector3f m_ownerPos;  // _10
	Vector3f m_targetPos; // _1C
	int _28;              // _28
};

struct ArgDir : public Arg {
	ArgDir(Vector3f position)
	    : Arg(position)
	{
	}

	virtual const char* getName() // _08 (weak)
	{
		return "ArgDir";
	}

	// _00     = VTBL
	// _00-_10 = Arg
	Vector3f m_angle; // _10
};

struct ArgDopingSmoke : public Arg {
	ArgDopingSmoke(Vector3f position)
	    : Arg(position)
	{
	}

	virtual const char* getName() // _08 (weak)
	{
		return "ArgDopingSmoke";
	}
	Vector3f m_dopePos;
	u16 m_dopeType;
};

struct ArgGasuHiba : public Arg {
	ArgGasuHiba(Vector3f position)
	    : Arg(position)
	{
	}

	virtual const char* getName() // _08 (weak)
	{
		return "ArgGasuHiba";
	}
	bool m_isUnderground; // _10
};

struct ArgImoEat : public Arg {
	ArgImoEat(Vector3f position)
	    : Arg(position)
	{
	}

	virtual const char* getName() // _08 (weak)
	{
		return "ArgImoEat";
	}
};

struct ArgKchYodare : public Arg {
	ArgKchYodare(Vector3f position)
	    : Arg(position)
	{
	}

	virtual const char* getName() // _08 (weak)
	{
		return "ArgKchYodare";
	}
	f32 m_scale;
};

struct ArgKouhai : public Arg {
	ArgKouhai(Vector3f position)
	    : Arg(position)
	{
	}

	virtual const char* getName() // _08 (weak)
	{
		return "ArgKouhai";
	}

	// _00     = VTBL
	// _00-_10 = Arg
	int _10; // _10
};

struct ArgPelType : public Arg {
	ArgPelType(Vector3f position)
	    : Arg(position)
	{
	}

	virtual const char* getName() // _08 (weak)
	{
		return "ArgPelType";
	}

	// _00     = VTBL
	// _00-_10 = Arg
	int m_type; // _10
};

struct ArgPosPos : public Arg {
	ArgPosPos(Vector3f position)
	    : Arg(position)
	{
	}

	ArgPosPos(Vector3f pos1, Vector3f pos2)
	    : Arg()
	{
		m_pos1 = pos1;
		m_pos2 = pos2;
	}

	virtual const char* getName() // _08 (weak)
	{
		return "ArgPosPos";
	}

	// _00     = VTBL
	// _00-_10 = Arg
	Vector3f m_pos1; // _10
	Vector3f m_pos2; // _1C
};

struct ArgPrmColor : public Arg {
	ArgPrmColor(Vector3f position)
	    : Arg(position)
	{
	}

	virtual const char* getName() // _08 (weak)
	{
		return "ArgPrmColor";
	}
	Color4 m_color; // _10
};

struct ArgRotY : public Arg {
	ArgRotY(f32 x, f32 y, f32 z, f32 faceDir)
	    : Arg(x, y, z)
	{
		m_faceDir = faceDir;
	}

	virtual const char* getName() // _08 (weak)
	{
		return "ArgRotY";
	}
	f32 m_faceDir; // _10
};

struct ArgRotYScale : public Arg {
	ArgRotYScale(Vector3f position)
	    : Arg(position)
	{
	}

	virtual const char* getName() // _08 (weak)
	{
		return "ArgRotYScale";
	}
	f32 m_faceDir;
	f32 m_scale;
};

struct ArgType : public Arg {
	ArgType(Vector3f position)
	    : Arg(position)
	{
	}

	inline ArgType(Game::Onyon* onyon);

	inline ArgType(u16 type)
	    : Arg()
	{
		m_type = type;
	}

	virtual const char* getName() // _08 (weak)
	{
		return "ArgType";
	}

	u16 m_type; // _10, onyon or pikmin
};
} // namespace efx

#endif
