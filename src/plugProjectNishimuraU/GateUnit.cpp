#include "Game/Cave/Node.h"
#include "Dolphin/math.h"
#include "ObjectTypes.h"

namespace Game {
/*
 * --INFO--
 * Address:	8024FCC8
 * Size:	00005C
 */
Cave::GateNode::GateNode()
{
	m_unit        = nullptr;
	m_index       = 0;
	m_rotationDir = 0.0f;
}

/*
 * --INFO--
 * Address:	8024FD24
 * Size:	00009C
 */
Cave::GateNode::GateNode(Cave::GateUnit* unit, int index, int dir)
{
	m_unit        = unit;
	m_index       = index;
	m_rotationDir = -HALF_PI * dir;
}

/*
 * --INFO--
 * Address:	8024FDC0
 * Size:	000020
 */
int Cave::GateNode::getObjectId()
{
	if (m_unit->m_info) {
		return m_unit->m_info->m_caveID;
	}

	return -1;
}

/*
 * --INFO--
 * Address:	8024FDE0
 * Size:	000008
 */
u32 Cave::GateNode::getObjectType() { return OBJTYPE_Teki; }

/*
 * --INFO--
 * Address:	8024FDE8
 * Size:	000008
 */
int Cave::GateNode::getBirthCount() { return 1; }

/*
 * --INFO--
 * Address:	8024FDF0
 * Size:	000008
 */
float Cave::GateNode::getDirection() { return m_rotationDir; }

/*
 * --INFO--
 * Address:	8024FDF8
 * Size:	000008
 */
int Cave::GateNode::getBirthDoorIndex() { return m_index; }

/*
 * --INFO--
 * Address:	8024FE00
 * Size:	000070
 */
Cave::GateNode::~GateNode() { }
} // namespace Game
