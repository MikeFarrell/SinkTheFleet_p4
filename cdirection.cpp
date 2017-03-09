#include "cdirection.h"

using namespace std;

namespace DV_STF
{
	//----------------------------------------------------------------------------
	//	Class:         CDirection
	//	method:        ostream& operator<<(ostream& os, const CDirection & dir)
	//	description:   overloaded << operator
	//	Input:         None 
	//	Output:        Contents to ostream
	//	Calls:         N/A
	//	Called By:     N/A 
	//	Parameters:	   ostream& os, const CDirection & dir
	//	Returns:       output stream 
	//	History Log:
	//	               2017-03-04 DV  completed version 1.0
	//----------------------------------------------------------------------------
	ostream& operator<<(ostream& os, const CDirection & dir)
	{
		dir.print(os); return os; 
	}

	//----------------------------------------------------------------------------
	//	Class:         CDirection
	//	method:        istream& operator >> (istream& is, CDirection & dir)
	//	description:   overloaded >> operator
	//	Input:         None 
	//	Output:        N/A
	//	Calls:         N/A
	//	Called By:     N/A
	//	Parameters:	   istream& is, CDirection & dir
	//	Returns:       input stream 
	//	History Log:
	//	               2017-03-04 DV  completed version 1.0
	//----------------------------------------------------------------------------
	istream& operator >> (istream& is, CDirection & dir)
	{
		return is;
	}

}