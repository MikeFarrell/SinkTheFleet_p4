#ifndef CSHIPINFO
#define CSHIPINFO


#include "cdirection.h"
#include "ccell.h"
#include "cship.h"

using namespace std;

namespace DV_STF
{
	class CShipInfo
	{
	public:
		// Constructor & Destructor
		CShipInfo(CShip name, CDirection orientation, CCell bowlocation, short piecesleft)
			: m_name(name), m_orientation(orientation), m_bowlocation(bowlocation), m_piecesleft(piecesleft) {};
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

		CShipInfo operator--() { --m_piecesleft; } //  pre-decrement
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