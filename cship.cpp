//----------------------------------------------------------------------------
//	File:		cship.cpp
//
//	functions:	
//			void CShip::print(ostream & sout) const
//			void CShip::printName(ostream & sout) const
//			ostream &operator << (ostream &sout, const CShip ship)
//			istream &operator >> (istream &sin, CShip &ship)
//
//
//
//----------------------------------------------------------------------------

#include "cship.h"
#include "textGraphics.h"

using namespace std;
namespace DV_STF
{
	
	//----------------------------------------------------------------------------
	//	Class:         CShip
	//	method:        void CShip::print(ostream & sout) const
	//	description:   print method for CShip class
	//	Input:         None 
	//	Output:        Contents to ostream
	//	Calls:         N/A
	//	Called By:     print(), << operator 
	//	Parameters:	   ostream& sout
	//	Returns:       output stream after output 
	//	History Log:
	//	               2017-03-04 DV  completed version 1.0
	//----------------------------------------------------------------------------
	void CShip::print(ostream & sout) const
	{
		sout << ' ';
		switch (m_ship)
		{
		case NOSHIP: sout << ' ';
			break;
		case MINESWEEPER: sout << 'M';
			break;
		case SUB: sout << 'S';
			break;
		case FRIGATE: sout << 'F';
			break;
		case BATTLESHIP: sout << 'B';
			break;
		case CARRIER: sout << 'C';
			break;
		case HIT: sout << 'H';
			break;
		case MISSED:
		default: sout << 'X';
		}
		sout << VERT;

	}

	//----------------------------------------------------------------------------
	//	Class:         CShip
	//	method:        void CShip::printName(ostream & sout) const
	//	description:   prints the name of the ship
	//	Input:         None 
	//	Output:        Contents to ostream
	//	Calls:         N/A
	//	Called By:     print(), << operator 
	//	Parameters:	   ostream& sout
	//	Returns:       output stream after output 
	//	History Log:
	//	               2017-03-04 DV  completed version 1.0
	//----------------------------------------------------------------------------
	void CShip::printName(ostream & sout) const
	{
		sout << shipNames[m_ship];
	}

	//----------------------------------------------------------------------------
	//	Class:         CShip
	//	method:        ostream &operator << (ostream &sout, const CShip ship)
	//	description:   overloaded << operator
	//	Input:         None 
	//	Output:        N/A
	//	Calls:         N/A
	//	Called By:     N/A
	//	Parameters:	   ostream& sout, const CShip ship
	//	Returns:       output stream after calling print();
	//	History Log:
	//	               2017-03-04 DV  completed version 1.0
	//----------------------------------------------------------------------------
	ostream &operator << (ostream &sout, const CShip ship)
	{
		ship.print(sout);
		return sout;
	}

	//----------------------------------------------------------------------------
	//	Class:         CShip
	//	method:        istream &operator >> (istream &sin, CShip &ship)
	//	description:   overloaded >> operator
	//	Input:         None 
	//	Output:        Contents to ostream
	//	Calls:         N/A
	//	Called By:     N/A
	//	Parameters:	   istream &sin, CShip &ship
	//	Returns:       input stream
	//	History Log:
	//	               2017-03-04 DV  completed version 1.0
	//----------------------------------------------------------------------------
	istream &operator >> (istream &sin, CShip &ship)
	{
		string str;
		if (!(sin >> str))
			return sin;

		for (short i = 0; i < SHIP_SIZE_ARRAYSIZE; i++)
		{
			size_t found = str.find(shipNames[i]);
			if (found != string::npos)
				ship = CShip(static_cast<Ship>(i));
		}
		return sin;
	}
}