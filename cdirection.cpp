#include "cdirection.h"

using namespace std;

namespace DV_STF
{
	ostream& operator<<(ostream& os, const CDirection & dir)
	{
		dir.print(os); return os; 
	}

	istream& operator >> (istream& is, CDirection & dir)
	{
		return is;
	}

}