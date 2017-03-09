#include "cplayer.h"

using namespace std;

namespace DV_STF
{
	//----------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        CPlayer CPlayer::operator=(const CPlayer& old)
	//	description:   assignment operator for CPlayer class 
	//	Input:         None 
	//	Output:        N/A
	//	Calls:         N/A
	//	Called By:     N/A
	//	Parameters:	   const CPlayer& old
	//	Returns:       current object
	//	History Log:
	//	               2017-03-08 DV  completed version 0.1
	//----------------------------------------------------------------------------
	CPlayer CPlayer::operator=(const CPlayer& old)
	{
		if (this == &old)
			return *this;

		delete[] m_gameGrid;
		m_gridSize = old.m_gridSize;

		allocMem();

		return *this;
	}

	//----------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        CShipInfo CPlayer::operator[](short index) const
	//	description:   assignment operator for CPlayer class 
	//	Input:         None 
	//	Output:        N/A
	//	Calls:         N/A
	//	Called By:     N/A
	//	Parameters:	   short index
	//	Returns:       m_ships[index]
	//	History Log:
	//	               2017-03-08 DV  completed version 1.0
	//----------------------------------------------------------------------------
	CShipInfo CPlayer::operator[](short index) const
	{
		if (index > 0 && index < DV_STF::SHIP_SIZE_ARRAYSIZE)
			return m_ships[index];
		//return CShipInfo(CShip(), CDirection(), CCell());
		return *this->m_ships; //fix this line
	}

	//----------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        CPlayer operator--()
	//	description:   pre-decrement operator for CPlayer class 
	//	Input:         None 
	//	Output:        N/A
	//	Calls:         N/A
	//	Called By:     N/A
	//	Parameters:	   N/A
	//	Returns:       current object
	//	History Log:
	//	               2017-03-08 DV  completed version 1.0
	//----------------------------------------------------------------------------
	CPlayer CPlayer::operator--()
	{
		m_piecesLeft--;
		return *this;
	}

	//----------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        CPlayer operator--(int)
	//	description:   pre-decrement operator for CPlayer class 
	//	Input:         None 
	//	Output:        N/A
	//	Calls:         N/A
	//	Called By:     N/A
	//	Parameters:	   unused int
	//	Returns:       temp of current object before decrement
	//	History Log:
	//	               2017-03-08 DV  completed version 1.0
	//----------------------------------------------------------------------------
	CPlayer CPlayer::operator--(int)
	{
		CPlayer temp = *this;
		m_piecesLeft--;
		return temp;
	}

	//----------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        void hitShip(CShip ship)
	//	description:   decrements pieces of ship and fleet
	//	Input:         None 
	//	Output:        N/A
	//	Calls:         N/A
	//	Called By:     N/A
	//	Parameters:	   CShip ship
	//	Returns:       N/A
	//	History Log:
	//	               2017-03-08 DV  completed version 1.0
	//----------------------------------------------------------------------------
	void CPlayer::hitShip(CShip ship)
	{
		--m_piecesLeft;
		--m_ships[ship];
	}

	//----------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        void setShips()
	//	description:   prompts user to set their ships
	//	Input:         from cin
	//	Output:        filled ship array
	//	Calls:         safeChoice(), setOrientation(), setBowLocation(), 
	//					setPiecesLeft, inputCoordinates(), getRow(), getCol(), 
	//					setName(), getName(), isValidLocation()
	//	Called By:     N/A
	//	Parameters:	   CShip ship
	//	Returns:       N/A
	//	History Log:
	//	               2017-03-08 DV  completed version 1.0
	//----------------------------------------------------------------------------
	void CPlayer::setShips()
	{
		char input = 'V';
		char shipOK = 'Y';
		char use_ship = 'Y';
		char ok = 'Y';
		char save = 'N';
		Ship ship_type;
		string use_ship_string;
		Direction orientation;
		ostringstream outSStream;
		CCell location = { 0, 0 };

		for (short j = 1; j < SHIP_SIZE_ARRAYSIZE; j++)
		{
			do {
				system("cls");
				shipOK = 'Y';
				printGrid(cout, MYGRID);
				use_ship_string = shipNames[j];
				use_ship_string += " ok?";
				use_ship = safeChoice(use_ship_string, 'Y', 'N');
				if (use_ship == 'Y')
				{
					outSStream.str("");
					outSStream << "Player " << m_whichPlayer + 1 << " Enter " << shipNames[j] << " orientation";
					input = safeChoice(outSStream.str(), 'V', 'H');
					orientation = (input == 'V') ? VERTICAL : HORIZONTAL;
					m_ships[j].setOrientation(CDirection(orientation));
					cout << "Player " << m_whichPlayer + 1 << " Enter " << shipNames[j] <<
						" bow coordinates <row letter><col #>" << endl;
					location.inputCoordinates(cin, m_gridSize);
					m_ships[j].setBowLocation(location);

					// if ok
					if (!isValidLocation(j))
					{
						cout << "invalid location. Press <enter>";
						cin.get();
						j--; // redo
						continue;
					}



					ship_type = static_cast<Ship>(j);
					m_gameGrid[MYGRID][location.get_row()][location.get_col()] = ship_type;

					for (int i = 0; i < shipSize[j]; i++)
					{
						if (input == 'V')
						{
							m_gameGrid[MYGRID]
								[location.get_row() + i][location.get_col()] = ship_type;
						}
						else
						{
							m_gameGrid[MYGRID]
								[location.get_row()][location.get_col() + i] = ship_type;
						}
						//i++;
					}
					system("cls");
					printGrid(cout, MYGRID);
					shipOK = safeChoice("Is Ship Position ok?", 'Y', 'N');
					if (shipOK == 'N')
					{
						m_gameGrid[MYGRID][location.get_row()][location.get_col()] = NOSHIP;
						for (int i = 0; i < shipSize[j]; i++)
						{
							if (input == 'V')
							{
								m_gameGrid[MYGRID][location.get_row() + i][location.get_col()] = NOSHIP;
							}
							else
							{
								m_gameGrid[MYGRID][location.get_row()][location.get_col() + i] = NOSHIP;
							}
							//i++;
						}
					}
				}//end of if(use_ship == Y)
				else
				{
					cout << "Not using [" << shipNames[j] << "]. Press <enter> to continue.." << endl;
					cin.get();
				}
			} while (shipOK == 'N');

			m_ships[j].setName(static_cast<Ship>(j));
			if (use_ship == 'Y')
			{
				m_ships[j].setPiecesLeft(shipSize[j]);
			}
			else
			{
				location = CCell(-1, -1);
				m_ships[j].setOrientation(VERTICAL);
				m_ships[j].setBowLocation(location);
				hitShip(m_ships[j].getName());
			}


		}
		printGrid(cout, MYGRID);
		save = safeChoice("\nSave starting grid?", 'Y', 'N');
		if (save == 'Y')
			saveGrid();
	}

	//
	bool CPlayer::isValidLocation(short whichShip)
	{
		bool r_val = true;
		CCell location = m_ships[whichShip].getBowLocation();
		Ship ship_type = static_cast<Ship>(whichShip);
		short numberOfRows = (toupper(m_gridSize) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols = (toupper(m_gridSize) == 'L') ? LARGECOLS : SMALLCOLS;

		if ((m_ships[whichShip].getOrientation() == VERTICAL) & (location.get_row() <= ((numberOfRows)-shipSize[whichShip])))
		{
			for (short i = 0; i < shipSize[ship_type]; i++)
			{
				if (!m_gameGrid[0][location.get_row() + i][location.get_col()] == NOSHIP)
				{
					r_val = false;
				}
			}
		}
		else if ((m_ships[whichShip].getOrientation() == HORIZONTAL) & (location.get_col() <= ((numberOfCols)-shipSize[whichShip])))
		{
			for (short i = 0; i < shipSize[ship_type]; i++)
			{
				if (!m_gameGrid[0][location.get_row()][location.get_col() + i] == NOSHIP)
				{
					r_val = false;
				}
			}
		}
		else
		{
			r_val = false;
		}

		return r_val;
	}

	//----------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        void CPlayer::allocMem(CPlayer players[], char size)
	//	description:   allocMem() original style.  For both players at same time
	//	Input:         None 
	//	Output:        N/A
	//	Calls:         N/A
	//	Called By:     N/A
	//	Parameters:	   CPlayer players[], char size
	//	Returns:       N/A
	//	History Log:
	//	               2017-03-08 DV  completed version 1.0
	//----------------------------------------------------------------------------
	void CPlayer::allocMem(CPlayer players[], char size)
	{
		short numberOfRows = (toupper(m_gridSize) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols = (toupper(m_gridSize) == 'L') ? LARGECOLS : SMALLCOLS;

		try
		{
			for (short i = 0; i < NUMPLAYERS; ++i)
			{
				players[i].m_gameGrid[0] = nullptr;
				players[i].m_gameGrid[0] = new CShip*[numberOfRows];
				players[i].m_gameGrid[1] = nullptr;
				players[i].m_gameGrid[1] = new CShip*[numberOfRows];
				for (short j = 0; j < numberOfRows; ++j)
				{
					//-------------------------------------------------
					// set the pointers to NULL, then allocate the
					// memory for each row in each grid
					//--------------------------------------------------
					players[i].m_gameGrid[0][j] = nullptr;
					players[i].m_gameGrid[0][j] = new CShip[numberOfCols];
					players[i].m_gameGrid[1][j] = nullptr;
					players[i].m_gameGrid[1][j] = new CShip[numberOfCols];

					for (short k = 0; k < numberOfCols; ++k)
					{
						players[i].m_gameGrid[0][j][k] = NOSHIP;
						players[i].m_gameGrid[1][j][k] = NOSHIP;
					} // end for k
				} // end for j
			} // end for i
		}
		catch (exception e)
		{
			deleteMem(players, size);
			cerr << "exception: " << e.what() << endl;
			cout << "shutting down" << endl;
			cin.ignore(BUFFER_SIZE, '\n');
			exit(EXIT_FAILURE);
		}
	}//end void CPlayer::allocMem()

	 //----------------------------------------------------------------------------
	 //	Class:         CPlayer
	 //	method:        void CPlayer::deleteMem(CPlayer players[], char size)
	 //	description:   deleteMem() original style.  For both players at same time
	 //	Input:         None 
	 //	Output:        N/A
	 //	Calls:         N/A
	 //	Called By:     N/A
	 //	Parameters:	   CPlayer players[], char size
	 //	Returns:       N/A
	 //	History Log:
	 //	               2017-03-08 DV  completed version 1.0
	 //---------------------------------------------------------------------------- 
	void CPlayer::deleteMem(CPlayer players[], char size)
	{
		{
			short numberOfRows = (toupper(size) == 'L') ? LARGEROWS : SMALLROWS;
			short numberOfCols = (toupper(size) == 'L') ? LARGECOLS : SMALLCOLS;
			for (short whichPlayer = 0; whichPlayer < NUMPLAYERS; whichPlayer++)
			{
				if (players[whichPlayer].m_gameGrid[0] != nullptr)
				{
					for (short j = 0; j < numberOfRows; ++j)
					{
						delete[] players[whichPlayer].m_gameGrid[0][j];
						delete[] players[whichPlayer].m_gameGrid[1][j];
					} // end for j
					delete[] players[whichPlayer].m_gameGrid[0];
					delete[] players[whichPlayer].m_gameGrid[1];
				}
			}
		}
	} //end void CPlayer::deleteMem()

	  //----------------------------------------------------------------------------
	  //	Class:         CPlayer
	  //	method:        void CPlayer::allocMem(void)
	  //	description:   allocMem() new style.  For one player at a time
	  //	Input:         None 
	  //	Output:        N/A
	  //	Calls:         N/A
	  //	Called By:     N/A
	  //	Parameters:	   N/A
	  //	Returns:       N/A
	  //	History Log:
	  //	               2017-03-07 DV  completed version 1.0
	  //---------------------------------------------------------------------------- 
	void CPlayer::allocMem(void)
	{
		short numberOfRows = (toupper(m_gridSize) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols = (toupper(m_gridSize) == 'L') ? LARGECOLS : SMALLCOLS; // Maybe get rid of all the toupper() further back
		try
		{  // Make new memory for each player's game grids. 
			m_gameGrid[MYGRID] = nullptr;
			m_gameGrid[MYGRID] = new CShip*[numberOfRows];
			m_gameGrid[YOURGRID] = nullptr;
			m_gameGrid[YOURGRID] = new CShip*[numberOfRows];
			for (short j = 0; j < numberOfRows; ++j)
			{ // setup array of columns for each grid
				m_gameGrid[MYGRID][j] = nullptr;
				m_gameGrid[MYGRID][j] = new CShip[numberOfCols];
				m_gameGrid[YOURGRID][j] = nullptr;
				m_gameGrid[YOURGRID][j] = new CShip[numberOfCols];
				for (short k = 0; k < numberOfCols; ++k)
				{  // Set initial value
					m_gameGrid[MYGRID][j][k] = NOSHIP;
					m_gameGrid[YOURGRID][j][k] = NOSHIP;
				} // end for k
			} // end for j
		}
		catch (exception e)
		{
			deleteMem();
			cerr << "exception: " << e.what() << endl;
			cout << "shutting down" << endl;
			std::cin.ignore(BUFFER_SIZE, '\n');
			exit(EXIT_FAILURE);
		}
	}

	//----------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        void CPlayer::allocMem(void)
	//	description:   deleteMem() new style.  For one player at a time
	//	Input:         None 
	//	Output:        N/A
	//	Calls:         N/A
	//	Called By:     N/A
	//	Parameters:	   N/A
	//	Returns:       N/A
	//	History Log:
	//	               2017-03-07 DV  completed version 1.0
	//----------------------------------------------------------------------------   
	void CPlayer::deleteMem(void)
	{
		short numberOfRows = (toupper(m_gridSize) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols = (toupper(m_gridSize) == 'L') ? LARGECOLS : SMALLCOLS;
		if (m_gameGrid[MYGRID] != nullptr)
		{
			for (short j = 0; j < numberOfRows; ++j)
				if (m_gameGrid[MYGRID][j] != nullptr)
					delete[] m_gameGrid[MYGRID][j];
			delete[] m_gameGrid[MYGRID];
		}
		if (m_gameGrid[YOURGRID] != nullptr)
		{
			for (short j = 0; j < numberOfRows; ++j)
				if (m_gameGrid[YOURGRID][j] != nullptr)
					delete[] m_gameGrid[YOURGRID][j];
			delete[] m_gameGrid[YOURGRID];
		}
	}

	//----------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        void CPlayer::printGrid(ostream& os, const short grid) const
	//	description:   print function to output grid
	//	Input:         None 
	//	Output:        grid
	//	Calls:         N/A
	//	Called By:     N/A
	//	Parameters:	   ostream& os, const short grid
	//	Returns:       N/A
	//	History Log:
	//	               2017-03-04 DV  completed version 1.0
	//---------------------------------------------------------------------------- 
	void CPlayer::printGrid(ostream& os, const short grid) const
	{
		short numberOfRows = (toupper(m_gridSize) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols = (toupper(m_gridSize) == 'L') ? LARGECOLS : SMALLCOLS;
		char rowChar = (numberOfRows == SMALLROWS) ? 'H' : 'J';
		system("cls");
		for (short j = 1; j <= numberOfCols; ++j) // Print first row of col numbers
			os << setw(3) << j;							//set width field to 3
		os << endl;
		for (size_t i = 'A', row = 0; i <= rowChar; i++, row++)
		{
			os << (char)i;					       //print out letter for each row
			for (short col = 0; col < numberOfCols; col++)
				m_gameGrid[grid][row][col].print();          //Print char code for ship		
			os << endl << HORIZ;						//Print out horizontal bar
			for (short h = 0; h < numberOfCols; h++)
				os << HORIZ << HORIZ << CR;
			os << endl;
		}
	}

	//----------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        bool CPlayer::getGrid(const string fileName)
	//	description:   inputs grid from .shp file
	//	Input:         None 
	//	Output:        N/A
	//	Calls:         setOrientation(), setPiecesLeft(), 
	//	Called By:     CSinkTheFleet::play()
	//	Parameters:	   const string fileName
	//	Returns:       true/false
	//	History Log:
	//	               2017-03-04 DV  completed version 1.0
	//---------------------------------------------------------------------------- 
	bool CPlayer::getGrid(const string fileName)
	{
		string line;
		ifstream ifs;
		Ship ship = NOSHIP;
		char fsize = 'S';
		char use_ship = 'Y';
		char input;
		short too_high = 0;
		unsigned short row = 0;
		unsigned short col = 0;
		char save = 'N';
		Ship ship_type = NOSHIP;
		CCell location = { 0, 0 };

		try
		{
			ifs.open(fileName);
			if (!ifs)
			{
				cout << "could not open file " << fileName << endl
					<< " press <enter> to continue" << endl;
				cin.ignore(BUFFER_SIZE, '\n');
				return false;
			}
		}
		catch (exception e)
		{
			cout << "could not open file " << fileName << endl
				<< " press <enter> to continue" << endl;
			cin.ignore(BUFFER_SIZE, '\n');
			return false;
		}

		fsize = ifs.get();
		ifs.ignore(FILENAME_MAX, '\n');

		if (m_gridSize != fsize)
		{
			cout << "File contains wrong grid size." << endl <<
				"Chosen grid size: " << m_gridSize << endl <<
				"File grid size: " << fsize << endl;
			cin.clear();
			cin.ignore(FILENAME_MAX, '\n');
			cin.get();
			return false;
		}


		short numberOfRows = (toupper(fsize) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols = (toupper(fsize) == 'L') ? LARGECOLS : SMALLCOLS;

		for (short j = 1; j < SHIP_SIZE_ARRAYSIZE; j++)
		{
			use_ship = 'Y';
			location = CCell(0, 0);
			//too_high = 0;
			getline(ifs, line);
			input = line.at(0);
			m_ships[j].setOrientation((input == 'V') ? VERTICAL : HORIZONTAL);

			row = (line.at(2));
			col = (line.at(4));
			if (((row - '0') < (-1)) || ((row - '0') > numberOfRows) ||
				((col - '0') < (-1)) || ((col - '0') > numberOfCols))
			{
				cout << "[" << shipNames[j] << "] is out of bounds. " <<
					"This ship will not be loaded." << endl;
				m_ships[j].setPiecesLeft(0);
				m_piecesLeft -= shipSize[j];
				continue;
			}
			//checks if '/' is in both locations, indicating the save file excluded that ship
			if ((row == '/') && (col == '/'))
			{
				use_ship = 'N';
			}
			else
			{
				row -= '0';
				col -= '0';
				location = CCell(row, col);
				m_ships[j].setBowLocation(location);

				ship_type = static_cast<Ship>(j);
				m_gameGrid[MYGRID][location.get_row()][location.get_col()] = ship_type; //break point
			}


			if (use_ship == 'Y')
			{

				location = CCell(row, col);
				ship_type = static_cast<Ship>(j);
				setCell(MYGRID, location, ship_type);
				for (int i = 0; i < shipSize[j]; i++)
				{
					if (input == 'V')
					{
						m_gameGrid[MYGRID][location.get_row() + i][location.get_col()] = ship_type;
					}
					else
					{
						m_gameGrid[MYGRID][location.get_row()][location.get_col() + i] = ship_type;
					}
				}
				if (j == 1)
				{
					m_ships[j].setName(MINESWEEPER);
					m_ships[j].setPiecesLeft(2);
				}
				else if (j == 2)
				{
					m_ships[j].setName(SUB);
					m_ships[j].setPiecesLeft(3);
				}
				else if (j == 3)
				{
					m_ships[j].setName(FRIGATE);
					m_ships[j].setPiecesLeft(3);
				}
				else if (j == 4)
				{
					m_ships[j].setName(BATTLESHIP);
					m_ships[j].setPiecesLeft(4);
				}
				else if (j == 5)
				{
					m_ships[j].setName(CARRIER);
					m_ships[j].setPiecesLeft(5);
				}
			}
			else
			{
				cout << "File does not contain [" << shipNames[j] << "] " << endl;
				m_ships[j].setPiecesLeft(0);
				m_piecesLeft -= shipSize[j];
			}
		} // end for j

		  /*save = safeChoice("\nSave starting grid?", 'Y', 'N');
		  if (save == 'Y')
		  saveGrid(players, whichPlayer, fsize);*/
		cout << endl << "Successfully loaded save file." <<
			endl << "You have " << m_piecesLeft << " total fleet pieces." << endl << "Press <enter> to continue.." << endl;
		cin.clear();
		cin.ignore(FILENAME_MAX, '\n');
		cin.get();
		return true;
	}

	// setShipInfo.  Loads up m_ships array. 
	void CPlayer::setShipInfo(const Direction & dir, const CCell & cell,
		const Ship & ship, const short & piecesOfShip)
	{
		short shipNum = static_cast<short>(ship);
		m_ships[shipNum].setOrientation(dir);
		m_ships[shipNum].setName((CShip)ship);
		m_ships[shipNum].setPiecesLeft(piecesOfShip);
	}

	// saveGrid()
	void CPlayer::saveGrid(void) const
	{
		short numberOfRows = (toupper(m_gridSize) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols = (toupper(m_gridSize) == 'L') ? LARGECOLS : SMALLCOLS;
		char c = 'N';
		string outputFileName;
		ofstream outputFileStream;						//declare output filestream
		cout << "PLEASE ENTER OUTPUT FILE NAME (.shp will be added)" << endl;
		cin >> outputFileName;							   //Get filename from user
		outputFileName += ".shp";
		outputFileStream.open(outputFileName);			          //Open filestream
		outputFileStream << m_gridSize << endl;	   //Output char code for grid size
		for (short i = 1; i < SHIP_SIZE_ARRAYSIZE; i++)
		{
			outputFileStream << m_ships[i].getOrientation() <<
				" " << static_cast<char>(m_ships[i].getBowLocation().get_row() + '0') <<
				"," << static_cast<char>(m_ships[i].getBowLocation().get_col() + '0') << endl;
		}
		outputFileStream << endl;
		cin.ignore(FILENAME_MAX, '\n');
		outputFileStream.close();
		cout << outputFileName << " saved." << endl;
	}
}
