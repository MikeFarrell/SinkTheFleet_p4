//----------------------------------------------------------------------------
//	File:		csinkthefleet.cpp
//
//	functions:	
//			short CSinkTheFleet::play()
//			void CSinkTheFleet::header(ostream& sout)
//			void CSinkTheFleet::endBox(short player)
//			
//			
//----------------------------------------------------------------------------
#include "csinkthefleet.h"

using namespace std;

namespace DV_STF
{
	//----------------------------------------------------------------------------
	//	Class:         CSinkTheFleet
	//	method:        short CSinkTheFleet::play()
	//	description:   plays the game
	//	Input:         None 
	//	Output:        Contents to ostream
	//	Calls:         setGridSize(), setShips(), getGrid(), printGrid(),
	//					inputCoordinates(), getCell()
	//	Called By:     CSinkTheFleet object
	//	Parameters:	   N/A
	//	Returns:       winning player index 
	//	History Log:
	//	               2017-03-04 DV  completed version 1.0
	//				   2017-03-05 DV  completed version 1.1
	//				   2017-03-09 DV  completed version 1.2
	//----------------------------------------------------------------------------
	short CSinkTheFleet::play()
	{
		char from_file = 'Y';
		char grid_size = 'L';
		bool gameOver = false;
		bool reshot = false;
		short whichPlayer = 0;
		string filename;
		CShip shipHit = NOSHIP;
		short index;
		CCell coord;

		system("cls");
		header(cout);
		grid_size = safeChoice("Enter desired grid size: ", 'L', 'S');
		m_players[whichPlayer].setGridSize(grid_size);
		m_players[!whichPlayer].setGridSize(grid_size);
		m_gridSize = grid_size;

		for (whichPlayer = 0; whichPlayer < NUMPLAYERS; whichPlayer++)
		{
			system("cls");
			header(cout);
			cout << "Player " << whichPlayer + 1 << ", ";
			from_file =
				safeChoice("Would you like to read starting grid from a file?",
					'Y', 'N');
			if (from_file == 'N')
			{
				m_players[whichPlayer].setShips();
			}
			else if (from_file == 'Y')
			{
				do
				{
					system("cls");
					header(cout);
					cout << "Enter file name: ";
					
					cin >> filename;
					cout << "Reading from file..." << endl << endl;

				} while (m_players[whichPlayer].getGrid(filename) == false);
				m_players[whichPlayer].printGrid(cout, MYGRID);
				cout << "Press <enter> to continue.." << endl;
				cin.get();
			}
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

					coord.inputCoordinates(cin, grid_size);

					shipHit = m_players[!whichPlayer].getCell(MYGRID, coord);


					//If the space is not empty
					if (shipHit != NOSHIP)
					{
						system("cls");
						//if space has already been hit
						if (shipHit == HIT)
						{
							m_players[whichPlayer].printGrid(cout, YOURGRID);
							cout << "THIS SPACE HAS PREVIOUSLY BEEN HIT." <<
								endl;
						}
						//without this the program will detect 
						//re-firing at a missed cell as a hit
						else if (shipHit == MISSED)
						{
							m_players[whichPlayer].printGrid(cout, YOURGRID);
							cout << "THIS SPACE HAS PREVIOUSLY BEEN MISSED." <<
								endl;
						}
						else
						{
							m_players[!whichPlayer].hitShip(shipHit);

							//adjust grid for hit
							m_players[!whichPlayer].setCell(MYGRID, coord, MISSED);//shows player their ship was hit
							m_players[whichPlayer].setCell(YOURGRID, coord, HIT);
							m_players[whichPlayer].printGrid(cout, YOURGRID);
							cout << "HIT" << endl;

							index = static_cast<short>(shipHit);

							if (m_players[!whichPlayer][index].isSunk())
							{
								cout << shipNames[shipHit] <<
									" is destroyed." << endl;
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


		return whichPlayer;
	}// end for Play

	

	
	 //----------------------------------------------------------------------------
	 //	Class:         CSinkTheFleet
	 //	method:        void CSinkTheFleet::header(ostream& sout)
	 //	description:   prints the header box
	 //	Input:         None 
	 //	Output:        Contents to ostream& sout
	 //	Calls:         textGraphics functions
	 //	Called By:     CSinkTheFleet object
	 //	Parameters:	   ostream& sout
	 //	Returns:       N/A
	 //	History Log:
	 //	               2017-03-04 DV  completed version 1.0
	 //----------------------------------------------------------------------------
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


	//----------------------------------------------------------------------------
	//	Class:         CSinkTheFleet
	//	method:        void CSinkTheFleet::endBox(short player)
	//	description:   prints the end box
	//	Input:         None 
	//	Output:        Contents to ostream& sout
	//	Calls:         textGraphics functions
	//	Called By:     CSinkTheFleet object
	//	Parameters:	   short player
	//	Returns:       N/A
	//	History Log:
	//	               2017-03-04 DV  completed version 1.0
	//----------------------------------------------------------------------------
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
