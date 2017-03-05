#include "safeio.h"
#include "textGraphics.h"
#include "csinkthefleet.h"

using namespace DV_STF;



int main()
{
	//CSinkTheFleet j;
	char again = 'N';

	do {



		again = safeChoice("Would you like to play again?", 'Y', 'N');
	} while (again == 'Y');

	return EXIT_SUCCESS;
}