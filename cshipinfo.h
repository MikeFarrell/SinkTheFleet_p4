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
		CShipInfo() {}

	private:
		CShip m_name;
		CDirection m_orientation;
		CCell m_bowlocation;
		short m_piecesleft;
	};
}
#endif

