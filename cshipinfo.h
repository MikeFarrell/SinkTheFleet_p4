//----------------------------------------------------------------------------
// File:		cshipinfo.h
// 
// Description: Header file for CShipInfo
//	
// Programmers:	Dark Vader
// 
// Environment: Hardware: i7 
//              Software: OS: Windows 10; 
//              Compiles under Microsoft Visual C++ 2015
//----------------------------------------------------------------------------

#ifndef CSHIPINFO
#define CSHIPINFO


#include "cdirection.h"
#include "ccell.h"
#include "cship.h"

using namespace std;

namespace DV_STF
{
	//---------------------------------------------------------------------------
	//	Title:          CShipInfo.h
	//	Description:    This file contains the class definition for CShipInfo
	//	Programmers:     dark vader
	//	Date:           3/8/2017
	//	Version:	1.00
	//	Environment:	 Hardware: i7 
	//              Software: OS: Windows 10; 
	//              Compiles under Microsoft Visual C++ 2015
	//	class CShipInfo:
	//	Properties:
	//			CShip m_name;
	//			CDirection m_orientation;
	//			CCell m_bowlocation;
	//			short m_piecesleft;
	//
	//	Methods:
	//		Inline:
	//			CShipInfo(CShip name, CDirection orientation, 
	//					CCell bowlocation, short piecesleft)
	//			CShipInfo() {};
	//			~CShipInfo() {};
	//			void print()
	//		Accessors
	//			CShip getName(void) const { return m_name; }
	//			CDirection getOrientation(void) const { return m_orientation; }
	//			CCell getBowLocation(void) const { return m_bowlocation; }
	//			short getPiecesLeft(void) const { return m_piecesleft; }
	//		Mutators
	//			void setName(const CShip name) { m_name = name; }
	//			void setOrientation(const CDirection dir) { m_orientation = dir; }
	//			void setBowLocation(const CCell location) { m_bowlocation = location; }
	//			void setPiecesLeft(const short pieces) { m_piecesleft = pieces; }
	//
	//			CShipInfo operator--() { --m_piecesleft; return *this; }
	//			bool isSunk(void) const { return (m_piecesleft == 0) ? true : false; }
	//		Non-Inline:
	//				void print(ostream & os) const
	//				static const short shipSize[6]; // Holds ship sizes
	//		Related:
	//				ostream& operator<<(ostream& sout, CShipInfo& theShip);
	//  History Log:
	//				3/08/2017 dark vader completed v 1.0
	//     
	//-----------------------------------------------------------------------------
	class CShipInfo
	{
	public:
		// Constructor & Destructor
		CShipInfo(CShip name, CDirection orientation, CCell bowlocation, short piecesleft)
			: m_name(name), m_orientation(orientation), m_bowlocation(bowlocation), 
			m_piecesleft(piecesleft) {};
		CShipInfo() {}; // 
		~CShipInfo() {};
		//Prints out the proprties (e.g., "Frigate, located vertically at 
		//B4--2 pieces left")
		void print(ostream & os);

		//with no parameter. Prints to cout.
		void print(void) { print(cout); }

		// Accessors
		CShip getName(void) const { return m_name; }
		CDirection getOrientation(void) const { return m_orientation; }
		CCell getBowLocation(void) const { return m_bowlocation; }
		short getPiecesLeft(void) const { return m_piecesleft; }
		// Mutators
		void setName(const CShip name) { m_name = name; }
		void setOrientation(const CDirection dir) { m_orientation = dir; }
		void setBowLocation(const CCell location) { m_bowlocation = location; }
		void setPiecesLeft(const short pieces) { m_piecesleft = pieces; }

		CShipInfo operator--() { --m_piecesleft; return *this; } //  pre-decrement
		bool isSunk(void) const { return (m_piecesleft == 0) ? true : false; }
		static const short shipSize[6]; // Holds ship sizes

	private:
		CShip m_name;
		CDirection m_orientation;
		CCell m_bowlocation;
		short m_piecesleft;
	};
	ostream & operator<<(ostream & os, CShipInfo theShip);
}
#endif