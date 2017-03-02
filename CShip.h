
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>
using namespace std;

namespace DV_STF
{

	class CShip
	{
	public:
		CShip(Ship ship = NOSHIP)
			: m_ship(ship) {}

		operator Ship() const
		{
			return Ship();
		}
		
		void print(ostream & sout) const;
		void print() const;
		void printName(ostream & sout) const;

	private:
		Ship m_ship;
		
	};
}
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
