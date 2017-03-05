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

	
	static const short SHIP_SIZE_ARRAYSIZE = 6;
	static const char* shipNames[SHIP_SIZE_ARRAYSIZE] =
	{ "No Ship", "Mine Sweeper", "Submarine", "Frigate",
		"Battleship", "Aircraft Carrier" };

	class CShip
	{
	public:
		CShip(Ship ship = NOSHIP)
			: m_ship(ship) {}

		//operator Ship() const { return m_ship; }

		void print(std::ostream & sout) const;
		void print() const { print(std::cout); }
		void printName(std::ostream & sout) const;

	private:
		Ship m_ship;

	};

	ostream &operator << (ostream &sout, const CShip &ship);
	istream &operator >> (istream &sin, CShip &ship);
}
#endif