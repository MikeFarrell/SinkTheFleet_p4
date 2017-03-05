#ifndef CSHIPINFO
#define CSHIPINFO

#include "cdirection.h"
#include "ccell.h"
#include "cship.h"

namespace DV_STF
{
	class CShipInfo
	{
		CShipInfo();

	private:
		CShip m_name;
		CDirection m_orientation;
		CCell m_bowlocation;
		short m_piecesleft;
	};
}
#endif

