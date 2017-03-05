#include "cship.h"
#include "textGraphics.h"
//#include "global.h"


namespace DV_STF
{
	const short SHIP_SIZE_ARRAYSIZE = 6;
	const char* shipNames[SHIP_SIZE_ARRAYSIZE] =
	{ "No Ship", "Mine Sweeper", "Submarine", "Frigate",
		"Battleship", "Aircraft Carrier" };

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

	void CShip::printName(ostream & sout) const
	{
		sout << shipNames[m_ship];
	}

	ostream &operator << (ostream &sout, const CShip &ship)
	{
		ship.print(sout);
		return sout;
	}

	istream &operator >> (istream &sin, CShip &ship)
	{
		string str;
		if (!(sin >> str))
			return sin;

		for (short i = 0; i < SHIP_SIZE_ARRAYSIZE; i++)
		{
			std::size_t found = str.find(shipNames[i]);
			if (found != std::string::npos)
				ship = CShip(static_cast<Ship>(i));
		}
		return sin;
	}
}