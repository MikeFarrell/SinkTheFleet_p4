#ifndef CSINKTHEFLEET
#define CSINKTHEFLEET


#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <string>
#include <sstream>

#include "cplayer.h"

namespace DV_STF
{
	class CSinkTheFleet
	{
	public:
		CSinkTheFleet(char gridSize = 'L') 
			: m_gridSize(gridSize) {};

	private:
		CPlayer m_players[2];
		char m_gridSize;
	};
}
#endif

