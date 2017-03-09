#include "csinkthefleet.h"

using namespace std;

namespace DV_STF
{
	CSinkTheFleet::CSinkTheFleet(char gridSize)
	{
		m_gridSize = toupper(gridSize);
		CPlayer player1(0, gridSize);
		CPlayer player2(1, gridSize);
		m_players[0] = player1;
		m_players[1] = player2;
	}

	short CSinkTheFleet::play()
	{
		char from_file = 'Y';
		//char grid_size = 'L';
		bool gameOver = false;
		bool reshot = false;
		short whichPlayer = 0;
		string filename;
		Ship shipHit = NOSHIP;
		CCell coord;

		for (whichPlayer = 0; whichPlayer < NUMPLAYERS; whichPlayer++)
		{
			for (int i = 0; i < 2; i++)
			{
				system("cls");
				DV_STF::CSinkTheFleet::header(cout);
				cout << "Player " << whichPlayer + 1 << ", ";
				from_file =
					safeChoice("Would you like to read starting grid from a file?",
						'Y', 'N');
				if (from_file == 'N')
				{
					/*if (i == 0)
					{
					grid_size = safeChoice("Enter desired grid size: ", 'L', 'S');
					}*/
					m_players[whichPlayer].setGridSize(m_gridSize);
					m_players[whichPlayer].setShips();
				}
				else if (from_file == 'Y')
				{
					cout << "Enter file name: ";
					cin >> filename;
					cin.ignore(FILENAME_MAX, '\n');
					cout << "Reading from file...";
					m_players[whichPlayer].getGrid(filename); // gets grid from file & prints
					cout << "Press <enter> to continue.." << endl;
					cin.get();
				}
				whichPlayer++;
			}
			system("cls");
			header(cout);
			cout << "Press <enter> to start the battle..." << endl;
			cin.ignore(BUFFER_SIZE, '\n');

			whichPlayer = 0;
			gameOver = false;
			while (!gameOver)
			{
				do
				{
					m_players[whichPlayer].printGrid(cout, YOURGRID);
					reshot = false;
					cout << "Player " << whichPlayer + 1 <<
						", Enter Coordinates for Firing." << endl;

					coord.inputCoordinates(cin, YOURGRID);

					//shipHit = m_players[!whichPlayer].getCell(MYGRID, coord);
					CShip tempShip = m_players[!whichPlayer].getCell(MYGRID, coord); 

					//If the space is not empty
					if (tempShip.getShip() != NOSHIP)
					{
						system("cls");
						//if space has already been hit
						if (tempShip.getShip() == HIT)
						{
							m_players[whichPlayer].printGrid(cout, YOURGRID);
							cout << "THIS SPACE HAS PREVIOUSLY BEEN HIT." <<
								endl;
						}
						//without this the program will detect 
						//re-firing at a missed cell as a hit
						else if (tempShip.getShip() == MISSED)
						{
							m_players[whichPlayer].printGrid(cout, YOURGRID);
							cout << "THIS SPACE HAS PREVIOUSLY BEEN MISSED." <<
								endl;
						}
						else
						{
							m_players[!whichPlayer].hitShip(tempShip);
							
							//adjust grid for hit
							m_players[!whichPlayer].setCell(MYGRID, coord, HIT);
							m_players[whichPlayer].setCell(YOURGRID, coord, HIT);
							m_players[whichPlayer].printGrid(cout, YOURGRID);
							cout << "HIT" << endl;

							if (m_players[!whichPlayer][tempShip].isSunk())
							{
								tempShip.printName(cout);
								cout << " is destroyed." << endl;
							}
							if (m_players[!whichPlayer].getPiecesLeft() == 0)
							{
								gameOver = true;
								cout << "Enemy fleet has been destroyed." <<
									endl;
								cin.ignore(BUFFER_SIZE, '\n');
								system("cls");
								break;
							}
						}
						reshot = true;

					}
					else
					{
						//adjust for miss
						m_players[!whichPlayer].setCell(MYGRID, coord, MISSED);
						m_players[whichPlayer].setCell(YOURGRID, coord, MISSED);
						m_players[whichPlayer].printGrid(cout, YOURGRID);
						cout << "MISS" << endl;
					}

					cout << "Press <enter> to continue." << endl;
					cin.ignore(BUFFER_SIZE, '\n');
					system("cls");
				} while (reshot);

				if (gameOver)
					break;
				whichPlayer = !whichPlayer;  // switch players
			}

			//show ending dialouge w/ winner
			endBox(whichPlayer);
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