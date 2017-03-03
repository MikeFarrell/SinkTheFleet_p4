#ifndef CDIRECTION
#define CDIRECTION
#include <ostream>
#include <ios>
using namespace std;
#include "oop.h"

namespace DV_STF
{
	class CDirection
	{
	public:

		CDirection() { m_direction = HORIZONTAL; }			// Default constructor
		~CDirection() {};									// Destructor
		operator Direction() const { return m_direction; }	// Cast 

															// Print 
		void print(ostream& os) const { (m_direction == VERTICAL) ? os << 'V' : os << 'H'; }
		void print(void) const { (m_direction == VERTICAL) ? cout << 'V' : cout << 'H'; }
		//Related functions?? should these be public?
		ostream& operator<<(ostream& os) { print(os); return os; }
		istream& operator >> (istream& is) {}
	private:
		Direction m_direction;							// HORIZONTAL or VERTICAL
	};
	//----------------------------------------------------------------------------
	// enumerated type for direction on grid
	//----------------------------------------------------------------------------
	enum Direction
	{
		HORIZONTAL, // 0
		VERTICAL	// 1
	};
}

#endif
