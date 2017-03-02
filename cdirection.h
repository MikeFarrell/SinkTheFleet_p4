#ifndef CDIRECTION
#define CDIRECTION

#include "oop.h"

namespace DV_STF
{
	class CDirection
	{
		CDirection();

	private:
		Direction m_direction;
	};
	
	enum Direction
	{
		HORIZONTAL, // 0
		VERTICAL	// 1
	};
}
#endif
