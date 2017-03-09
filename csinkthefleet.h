//----------------------------------------------------------------------------
// File:		csinkthefleet.h
// 
// Description: Header file for CSinkTheFleet
//	
// Programmers:	Dark Vader
// 
// Environment: Hardware: i7 
//              Software: OS: Windows 10; 
//              Compiles under Microsoft Visual C++ 2015
//----------------------------------------------------------------------------

#ifndef CSINKTHEFLEET
#define CSINKTHEFLEET


#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <string>
#include <sstream>

#include "cplayer.h"

using namespace std;

namespace DV_STF
{
	class CSinkTheFleet
	{
	public:
		CSinkTheFleet(char gridSize = 'L') 
			: m_gridSize(gridSize) {};

		short play(); //plays the game
		CSinkTheFleet operator[](short index); //validate and return m_players[index]
		CSinkTheFleet operator[](short index) const; //validate and return m_players[index]
		static void header(ostream& sout);
		static void endBox(short player);

	private:
		CPlayer m_players[2]; //the two players
		char m_gridSize; //'L' or 'S'
	};
}
#endif

