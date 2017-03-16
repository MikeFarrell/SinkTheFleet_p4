//----------------------------------------------------------------------------
// File:	d_oop.cpp
// 
// Function: main() 
//----------------------------------------------------------------------------
#include "csinkthefleet.h"
#include "safeio.h"
#include "textGraphics.h"
//----------------------------------------------------------------------------
// Function:	main()
//
// Description:
//				Driver file that runs the Sink The Fleet program
//
// Team:			Dark Vader
// Programmers:	
//					Jared Whitney
//					Mike Farrell
//					Jeremiah Robinson
//					Sung Kim
//					Chao Jiang
// 
// Date:		2017-03-09
//
// Version:		1.0
// 
// Environment: Hardware: i7 
//              Software: OS: Windows 10; 
//              Compiles under Microsoft Visual C++ 2015
//
// Input:		user safeChoice for play again
//
// Output:		prompt to play again
//
// Calls:		CSinkTheFleet class and related functions/classes
//
// Called By:	n/a
//
// Parameters:	none
// 
// Returns:		int -- EXIT_SUCCESS upon successful completion
//
// History Log: 
//				2017-03-02 DV completed v 0.1
//				2017-03-08 DV completed v 0.2
//				2017-03-09 DV completed v 1.0
//   
//----------------------------------------------------------------------------
using namespace std;

int main()
{
	using namespace DV_STF;
	char again = 'N';
	short winner;

	do {
		CSinkTheFleet game;
		winner = game.play();
		game.endBox(winner);
		again = safeChoice("Would you like to play again?", 'Y', 'N');
	} while (again == 'Y');

	return EXIT_SUCCESS;
}
