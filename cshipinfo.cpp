//----------------------------------------------------------------------------
//	File:		cshipinfo.cpp
//
//	functions:	
//			void CShipInfo::print(ostream & os) 
//			ostream & operator<<(ostream & os, CShipInfo theShip)
//			
//----------------------------------------------------------------------------

#include "cshipinfo.h"

namespace DV_STF
{
	//----------------------------------------------------------------------------
	//	Class:         CShipInfo
	//	method:        print(ostream & os) 
	//	description:   print method for CShipInfo class 
	//	Input:         None 
	//	Output:        Contents to ostream
	//	Calls:         N/A
	//	Called By:     print(), << operator 
	//	Parameters:	   ostream& os
	//	Returns:       output stream after output 
	//	History Log:
	//	               2017-03-04 DV  completed version 1.0
	//----------------------------------------------------------------------------
	void CShipInfo::print(ostream & os) 
	{
		os << "Ship: " << m_name << ". Direction: " << m_orientation
			<< ". Location: " << m_bowlocation << ". " << m_piecesleft
			<< " Pieces left." << endl;
	}

	//----------------------------------------------------------------------------
	//	Class:         CShipInfo
	//	method:        ostream & operator<<(ostream & os, CShipInfo theShip) 
	//	description:   output operator for CShipInfo class 
	//	Input:         None 
	//	Output:        N/A
	//	Calls:         N/A
	//	Called By:     N/A
	//	Parameters:	   ostream& os, CShipInfo theShip
	//	Returns:       output stream 
	//	History Log:
	//	               2017-03-04 DV  completed version 1.0
	//----------------------------------------------------------------------------
	ostream & operator<<(ostream & os, CShipInfo theShip)
	{
		theShip.print(os);
		return os;
	}
}
