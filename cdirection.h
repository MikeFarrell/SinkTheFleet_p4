//----------------------------------------------------------------------------
// File:		cdirection.h
// 
// Description: Header file for CDirection
//	
// Programmers:	Dark Vader
// 
// Environment: Hardware: i7 
//              Software: OS: Windows 10; 
//              Compiles under Microsoft Visual C++ 2015
//----------------------------------------------------------------------------

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
	//---------------------------------------------------------------------------
	//	Title:          CDirection.h
	//	Description:    This file contains the class definition for CDirection
	//	Programmers:     dark vader
	//	Date:           3/4/2017
	//	Version:	1.00
	//	Environment:	 Hardware: i7 
	//              Software: OS: Windows 10 
	//              Compiles under Microsoft Visual C++ 2015
	//	class CDirection:
	//	Properties:
	//			Direction m_direction;
	//
	//	Methods:
	//		Inline:
	//			CDirection() {}
	//			CDirection(Direction dir) { m_direction = dir; }
	//			~CDirection() {}
	//			void print(ostream& os) const
	//			void print()
	//		Non-Inline:
	//				void print(ostream & sout) const
	//		Related:
	//				ostream& operator<<(ostream& os, const CDirection & dir);
	//				istream &operator>>(istream& is, CDirection & dir)
	//  History Log:
	//				3/04/2017 dark vader completed v 1.0
	//     
	//-----------------------------------------------------------------------------
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
		Direction getDirection(void) { return m_direction; }

	private:
		Direction m_direction;							// HORIZONTAL or VERTICAL
	};

	ostream& operator<<(ostream& os, const CDirection & dir);
	istream& operator >> (istream& is, CDirection & dir);
}
#endif

