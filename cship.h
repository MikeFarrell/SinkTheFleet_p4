#ifndef CSHIP
#define CSHIP

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

namespace DV_STF
{

	enum Ship
	{
		NOSHIP,		 // 0
		MINESWEEPER, // 1 (1-5) -- used only for owner
		SUB,		 // 2
		FRIGATE,	 // 3
		BATTLESHIP,	 // 4
		CARRIER,	 // 5
		HIT,		 // 6 (6-7)-- used only for other side
		MISSED,		 // 7 
	};


	const short NUMPLAYERS = 2;	// number of players in game
	const short SMALLROWS = 8;	// number of rows/columns in small sea array 
	const short LARGEROWS = 10;	// number of rows/columns in large sea array
	const short SMALLCOLS = 12;	// number of rows/columns in small sea array 
	const short LARGECOLS = 24;	// number of rows/columns in large sea array
	const short BOXWIDTH = 79;	// maximum screen line length

	static const short SHIP_SIZE_ARRAYSIZE = 6;
	static const short shipSize[SHIP_SIZE_ARRAYSIZE] = { 0, 2, 3, 3, 4, 5 };
	static const char* shipNames[SHIP_SIZE_ARRAYSIZE] =
	{ "No Ship", "Mine Sweeper", "Submarine", "Frigate",
		"Battleship", "Aircraft Carrier" };

	class CShip
	{
	public:
		CShip(Ship ship = NOSHIP)
			: m_ship(ship) {}

		operator Ship() const { return m_ship; }

		void print(ostream & sout) const;
		void print() const { print(cout); }
		void printName(ostream & sout) const;

	private:
		Ship m_ship;

	};

	ostream &operator << (ostream &sout, const CShip ship);
	istream &operator >> (istream &sin, CShip &ship);
}
#endif