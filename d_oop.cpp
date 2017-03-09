#include "csinkthefleet.h"
#include "safeio.h"
#include "textGraphics.h"


using namespace std;

int main()
{
	DV_STF::CSinkTheFleet game;
	char again = 'N';

	do {
		//game = DV_STF::CSinkTheFleet();
		game.play();

		again = safeChoice("Would you like to play again?", 'Y', 'N');
	} while (again == 'Y');

	return EXIT_SUCCESS;
}
