#include "cshipinfo.h"

namespace DV_STF
{
	void CShipInfo::print(ostream & os) 
	{
		os << "Ship: " << m_name << ". Direction: " << m_orientation
			<< ". Location: " << m_bowlocation << ". " << m_piecesleft
			<< " Pieces left." << endl;
	}
	ostream & operator<<(ostream & os, CShipInfo theShip)
	{
		theShip.print(os);
		return os;
	}
}
