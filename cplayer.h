#ifndef CPLAYER
#define CPLAYER

#include "oop.h"

namespace DV_STF
{
	class CPlayer
	{
		CPlayer();

	private:
		unsigned short m_whichPlayer;
		short m_piecesLeft;
		CShipInfo m_ships[6];
		char m_gridSize;
		CShip ** m_gameGrid[2];

		//alloc mem
		//delete mem
	};
}
#endif

