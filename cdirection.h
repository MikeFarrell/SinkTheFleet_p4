#ifndef CDIRECTION
#define CDIRECTION

#include <iostream>
#include <iomanip>

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
		~CDirection() {};									// Destructor
		operator Direction() const { return m_direction; }	// Cast 

															// Print 
		void print(std::ostream& os) const {}
		void print() const { print(std::cout); }
	private:
		Direction m_direction;							// HORIZONTAL or VERTICAL
	};
}
#endif