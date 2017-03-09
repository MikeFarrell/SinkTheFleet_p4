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
	//---------------------------------------------------------------------------
	//	Title:          CSinkTheFleet.h
	//	Description:    This file contains the class definition for CShip
	//	Programmers:     dark vader
	//	Date:           3/4/2017
	//	Version:	1.00
	//	Environment:	 Hardware: i7 
	//              Software: OS: Windows 10 
	//              Compiles under Microsoft Visual C++ 2015
	//	class CShip:
	//	Properties:
	//			CPlayer m_players[2]; //the two players
	//			char m_gridSize;
	//
	//	Methods:
	//		Inline:
	//			CSinkTheFleet(char gridSize = 'L')
	//			CSinkTheFleet operator[](short index); //validate and return m_players[index]
	//			CSinkTheFleet operator[](short index) const;
	//		Non-Inline:
	//				short play();
	//				static void header(ostream& sout);
	//				static void endBox(short player);
	//		Related:
	//				ostream& operator<<(ostream& sout, CShip& ship);
	//				istream &operator>>(istream &sin, CShip &ship)
	//  History Log:
	//				3/04/2017 dark vader completed v 1.0
	//     
	//-----------------------------------------------------------------------------
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

