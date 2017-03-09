#include "csinkthefleet.h"

using namespace std;

namespace DV_STF
{
	short CSinkTheFleet::play()
	{
		char from_file = 'Y';
		char grid_size = 'L';
		short whichPlayer = 0;
		string filename;

		

		for (short i = 0; i < 2; i++)
		{
			system("cls");
			DV_STF::CSinkTheFleet::header(cout);
			cout << "Player " << whichPlayer + 1 << ", ";
			from_file =
				safeChoice("Would you like to read starting grid from a file?",
					'Y', 'N');
			if (from_file == 'N')
			{
				grid_size = safeChoice("Enter desired grid size: ", 'L', 'S');
				m_players[whichPlayer].setShips();
			}
			else if (from_file == 'Y')
			{
				cout << "Enter file name: ";
				cin >> filename;
				cin.ignore(FILENAME_MAX, '\n');
				cout << "Reading from file...";
				m_players[whichPlayer].getGrid(filename);
				m_players[whichPlayer].printGrid(cout);
				cout << "Press <enter> to continue.." << endl;
				cin.get();
			}
			whichPlayer++;
			
		}

		return whichPlayer;
	}// end for Play

	void CSinkTheFleet::header(ostream& sout)
	{
		const string empty;
		const string sink("SINK THE FLEET!");
		const string group_name("by Dark Vader");
		const string by("Edmonds Community College CS 132");
		boxTop(sout, BOXWIDTH);
		boxLine(sout, empty, BOXWIDTH);
		boxLine(sout, sink, BOXWIDTH, 'C');
		boxLine(sout, group_name, BOXWIDTH, 'C');
		boxLine(sout, by, BOXWIDTH, 'C');
		boxLine(sout, empty, BOXWIDTH);
		boxBottom(sout, BOXWIDTH);
	}

	void CSinkTheFleet::endBox(short player)
	{
		const string empty;
		ostringstream msg;
		msg << "Congratulations player " << player + 1 << "!";
		boxTop(cout, BOXWIDTH);
		boxLine(cout, empty, BOXWIDTH);
		boxLine(cout, msg.str(), BOXWIDTH, 'C');
		boxLine(cout, empty, BOXWIDTH);
		boxBottom(cout, BOXWIDTH);
	}
}
