#ifndef CSHIP
#define CSHIP

using namespace std;

#include <ostream>
#include <iostream>

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

	ostream &operator << (ostream &sout, const CShip &ship);
	istream &operator >> (istream &sin, CShip &ship);
}
#endif