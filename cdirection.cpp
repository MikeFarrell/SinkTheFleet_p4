#include "cdirection.h"

using namespace std;

namespace DV_STF
{
	//----------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        operator<<(ostream& os, const CDirection & dir)
	//	description:   formated output 
	//	Input:         None 
	//	Output:        N/A
	//	Calls:         N/A
	//	Called By:     N/A
	//	Parameters:	   ostream& os, const CDirection & dir
	//	Returns:       os
	//	History Log:
	//	               2017-03-08 DV  completed version 1.0
	//----------------------------------------------------------------------------
	ostream& operator<<(ostream& os, const CDirection & dir)
	{
		dir.print(os); return os;
	}

	//----------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        operator >> (istream& is, CDirection & dir)
	//	description:   format input 
	//	Input:         None 
	//	Output:        N/A
	//	Calls:         N/A
	//	Called By:     N/A
	//	Parameters:	   istream& is, CDirection & dir
	//	Returns:       is
	//	History Log:
	//	               2017-03-08 DV  completed version 1.0
	//----------------------------------------------------------------------------
	istream& operator >> (istream& is, CDirection & dir)
	{
		return is;
	}

}