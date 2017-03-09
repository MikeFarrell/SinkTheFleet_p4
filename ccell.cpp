#include "ccell.h"
#include "cship.h"
#include <sstream>

//---------------------------------------------------------------------------------
// Function:	getCoord()
// Title:	getCoord 
// Description:
//		gets the coordinate input and checks for bad input
// Programmer:	dark vader
//
// modified by:	
// 
// Date:	3/4/17
//
// Version:	1.0
// 
// Environment: Hardware: i7 
//              Software: OS: Windows 7; 
//              Compiles under Microsoft Visual C++ 2012
//
// Input:	grid from specified file
//
// Output:	prompts to cout
//
// Calls:	n/a
//
// Called By:	main()
//
// Parameters:	istream& sin, char size
// 
// Returns: CCell (row, col)
//
// History Log: 
//				9/12/06 PB comleted v 0.5
//				3/26/2017 dark vader completed v 0.6
//				3/27/2017 dark vader completed v 0.7
//				3/28/2017 dark vader completed v 0.8
//				3/29/2017 dark vader completed v 0.9
//				3/04/2017 dark vader completed v 1.0
//     
//---------------------------------------------------------------------------------
using namespace std;



namespace DV_STF
{
	CCell CCell::inputCoordinates(istream& sin, char size)
	{

		cin.clear();
		fflush(stdin);
		short numberOfRows = (toupper(size) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols = (toupper(size) == 'L') ? LARGECOLS : SMALLCOLS;
		char highChar = static_cast<char>(numberOfRows + 'A' - 1);
		char row = 0;
		do
		{
			cout << "Row must be a letter from A to " << highChar
				<< " and column must be  from 1 to " << numberOfCols << ": ";
			while ((row = toupper(sin.get())) < 'A' || row > highChar)
			{
				sin.ignore(BUFFER_SIZE, '\n');
				cout << "Row must be a letter from A to " << highChar
					<< " and column must be  from 1 to " << numberOfCols << ": ";
			}
			sin >> m_col;
			if (!sin)
				sin.clear();
			sin.ignore(BUFFER_SIZE, '\n');
		} while (m_col < 1 || m_col > numberOfCols);
		m_row = static_cast<unsigned short>(row - 'A');
		m_col--;
		return *this;
	}
	//---------------------------------------------------------------------------------
	// Function:	ostream& operator<<()
	// Title:	<< operator 
	// Description:
	//		allows the << operator to print things within the CCell class
	// Programmer:	dark vader
	//				
	//				
	// modified by:	dark vader 
	// 
	// Date:	3/4/17
	//
	// Version:	1.0
	// 
	// Environment: Hardware: i7 
	//              Software: OS: Windows 7; 
	//              Compiles under Microsoft Visual C++ 2012
	//
	// Input:	n/a
	//
	// Output:	n/a
	//
	// Calls:	print()
	//
	// Called By:	main()
	//
	// Parameters:	ostream& sout, CCell& cell
	// 
	// Returns: sout
	//
	// History Log: 
	//				9/12/06 PB comleted v 0.5
	//				3/26/2017 dark vader completed v 0.6
	//				3/27/2017 dark vader completed v 0.7
	//				3/28/2017 dark vader completed v 0.8
	//				3/29/2017 dark vader completed v 0.9
	//				3/04/2017 dark vader completed v 1.0
	//     
	//---------------------------------------------------------------------------------
	ostream& operator<<(ostream& sout, CCell& cell)
	{
		cell.print(sout);
		return sout;
	};
}