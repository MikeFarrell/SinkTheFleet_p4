#ifndef CDIRECTION
#define CDIRECTION

#include <iostream>
#include <iomanip>

using namespace std;

namespace DV_STF
{
	enum Direction
	{
		HORIZONTAL, // 0
		VERTICAL	// 1
	};

	class CDirection
	{
	public:

		CDirection() {}			// Default constructor
		CDirection(Direction dir) { m_direction = dir; } // Direction enum constructor
		~CDirection() {};									// Destructor
		operator Direction() const { return m_direction; }	// Cast 


		void print(ostream& os) const {
			(m_direction == VERTICAL) ?
				os << 'V' : os << 'H';
		}	// Print 
		void print() const { print(std::cout); }


	private:
		Direction m_direction;							// HORIZONTAL or VERTICAL
	};

	ostream& operator<<(ostream& os, const CDirection & dir);
	istream& operator >> (istream& is, CDirection & dir);
}
#endif

