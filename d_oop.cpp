#include "csinkthefleet.h"
#include "safeio.h"
#include "textGraphics.h"


using namespace std;

int main()
{
	using namespace DV_STF;
	//DV_STF::CSinkTheFleet game;
	char again = 'N';

	do {
		char gridsize = safeChoice("Select a grid size", 'S', 'L');
		CSinkTheFleet newgame(gridsize);
		newgame.play();

		again = safeChoice("Would you like to play again?", 'Y', 'N');
	} while (again == 'Y');

	return EXIT_SUCCESS;
}
