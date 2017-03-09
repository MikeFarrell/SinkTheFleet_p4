#include "cplayer.h"

using namespace std;

namespace DV_STF
{
	//--------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        CPlayer CPlayer::operator=(const CPlayer & player)
	//	description:   assignment operator for CPlayer class 
	//	Input:         None 
	//	Output:        N/A
	//	Calls:         N/A
	//	Called By:     copy constructor
	//	Parameters:	   const CPlayer & player : the player to copy
	//	Returns:       *this : the new player
	//	History Log:
	//	               2017-03-08 DV  completed version 1.0
	//--------------------------------------------------------------------------
	CPlayer & CPlayer::operator=(const CPlayer & player)
	{
		m_whichPlayer = player.m_whichPlayer;
		m_piecesLeft = player.m_piecesLeft;
		for (size_t i = 0; i < SHIP_SIZE_ARRAYSIZE; i++)
		{
			m_ships[i] = player.m_ships[i];
		}
		m_gridSize = player.m_gridSize;
		// Copy m_gameGrid
		short numberOfRows =
			(toupper(m_gridSize) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols = 
			(toupper(m_gridSize) == 'L') ? LARGECOLS : SMALLCOLS;
		for (size_t whichPlayer = 0; whichPlayer < NUMPLAYERS; whichPlayer++)
			for (size_t i = 0; i < numberOfRows; i++)
				for (size_t j = 0; j < numberOfCols; j++)
				{
					m_gameGrid[whichPlayer][i][j] = 
						player.m_gameGrid[whichPlayer][i][j];
				}
					
		return *this;
	}
	//--------------------------------------------------------------------------
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
	//--------------------------------------------------------------------------
	CShipInfo CPlayer::operator[](short index) const
	{
		if (index > 0 && index < DV_STF::SHIP_SIZE_ARRAYSIZE)
			return m_ships[index];
		//return CShipInfo(CShip(), CDirection(), CCell());
		return *this->m_ships; //fix this line
	}
	//--------------------------------------------------------------------------
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
	//--------------------------------------------------------------------------
	CPlayer CPlayer::operator--()
	{
		m_piecesLeft--;
		return *this;
	}
	//--------------------------------------------------------------------------
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
	//--------------------------------------------------------------------------
	CPlayer CPlayer::operator--(int)
	{
		CPlayer temp = *this;
		m_piecesLeft--;
		return temp;
	}
	//--------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        void autoSetShips(void)
	//	description:   auto sets ships for 1 player.
	//	Input:         
	//	Output:        filled ship array
	//	Calls:          setOrientation(), setBowLocation(), safeChoice()
	//					setPiecesLeft, getRow(), getCol(), 
	//					setName(), getName(), autoValidate()
	//	Called By:     N/A
	//	Parameters:	   CShip ship
	//	Returns:       N/A
	//	History Log:
	//	               2017-03-08 DV  completed version 1.0
	//--------------------------------------------------------------------------
	void CPlayer::autoSetShips(void)
	{
		short numberOfRows = 
			(toupper(m_gridSize) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols = 
			(toupper(m_gridSize) == 'L') ? LARGECOLS : SMALLCOLS;
		Ship tempShip;
		int randomNum = 0;
		char save = '\0';
		int attempts = 0;
		srand((unsigned)time(NULL));
		for (size_t j = 1; j < SHIP_SIZE_ARRAYSIZE; j++)
		{
			srand((unsigned)time(NULL));
			short int_dir = rand() % 2;
			Direction tempDir = (int_dir == 1) ? VERTICAL : HORIZONTAL;
			CDirection newDir(tempDir);
			m_ships[j].setOrientation(newDir);
			short row = rand() % numberOfRows;
			short col = rand() % numberOfCols;
			CCell loc(row, col);
			m_ships[j].setBowLocation(loc);
			// if ok
			if (autoValidate(j) == false)
			{
				j--; // redo
				attempts++;
				cout << "Attempts: " << attempts << endl;
				continue;
			}
			tempShip = static_cast<Ship>(j);
			CShip ship_type(tempShip);
			m_gameGrid[0][loc.get_row()][loc.get_col()] = ship_type;

			for (int i = 0; i < shipSize[j]; i++)
			{
				if (tempDir == VERTICAL)
					m_gameGrid[0][loc.get_row() + i][loc.get_col()] = ship_type;
				else
					m_gameGrid[0][loc.get_row()][loc.get_col() + i] = ship_type;
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
		printGrid(cout, 0);
		save = safeChoice("\nSave starting grid?", 'Y', 'N');
		if (save == 'Y')
			saveGrid();
	}
	//------------------------------------------------------------------------
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
	//--------------------------------------------------------------------------
	void CPlayer::setShips()
	{
		char input = 'V';
		char ok = 'Y';
		char save = 'N';
		Ship tempShip;
		Direction orientation;
		ostringstream outSStream;
		CCell location;
		for (short j = 1; j < SHIP_SIZE_ARRAYSIZE; j++)
		{
			system("cls");
			printGrid(cout, 0);
			outSStream.str("");
			outSStream << "Player " << m_whichPlayer + 1 << " Enter "
				<< shipNames[j] << " orientation";
			input = safeChoice(outSStream.str(), 'V', 'H');
			Direction tempDir = (input == 'V') ? VERTICAL : HORIZONTAL;
			CDirection newDir(tempDir);
			m_ships[j].setOrientation(newDir);
			//orientation = m_ships[j].getOrientation();
			cout << "Player " << m_whichPlayer + 1 << " Enter " << shipNames[j] <<
				" bow coordinates <row letter><col #>: ";

			location = m_ships[m_whichPlayer].getBowLocation().
				inputCoordinates(cin, m_gridSize);
			m_ships[j].setBowLocation(location);
			// if ok
			if (isValidLocation(j) == false)
			{
				cout << "invalid location. Press <enter>";
				cin.get();
				j--; // redo
				continue;
			}

			tempShip = static_cast<Ship>(j);
			CShip ship_type(tempShip);
			m_gameGrid[0][location.get_row()][location.get_col()] = ship_type;

			for (int i = 0; i < shipSize[j]; i++)
			{
				if (input == 'V')
				{
					m_gameGrid[0][location.get_row() + i][location.get_col()] =
						ship_type;
				}
				else
				{
					m_gameGrid[0][location.get_row()][location.get_col() + i] =
						ship_type;
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
			printGrid(cout, MYGRID);
			ok = safeChoice("\nIs Ship's location ok?", 'Y', 'N');
			if (ok == 'N')
			{
				CShip tempShip(NOSHIP);
				m_gameGrid[0][location.get_row()][location.get_col()] = tempShip;
				for (int i = 0; i < shipSize[j]; i++)
				{
					if (input == 'V')
						m_gameGrid[MYGRID][location.get_row() + i]
							[location.get_col()] = tempShip;
					else
						m_gameGrid[MYGRID][location.get_row()]
							[location.get_col() + i] = tempShip;
				}
				j--;
				continue;
			}
		} // end for j
		printGrid(cout, MYGRID);
		save = safeChoice("\nSave starting grid?", 'Y', 'N');
		if (save == 'Y')
			saveGrid();
	}
	//---------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        hitShip()
	//	description:   decrements ship and total pieces
	//	Input:         None
	//	Output:        None
	//	Calls:         getPieces
	//	Called By:     CSinkTheFleet
	//	Parameters:    CShip ship
	//	Returns:       n/a 
	//	History Log:
	//	               3/9/2017 MF completed version 1.0
	//---------------------------------------------------------------------------
	void CPlayer::hitShip(CShip ship)
	{
		short pieces = m_ships[ship].getPiecesLeft();
		m_piecesLeft--;
		pieces--;
		m_ships[ship].setPiecesLeft(pieces);
	}
	
	//---------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        autoValidate(short shipNumber)
	//	description:   checks to see if location is ok
	//	Input:         None
	//	Output:        None
	//	Calls:         getDirection, getOrientation, getBowlocation, get_row, 
	//				   get_col
	//	Called By:     autoSetShips()
	//	Parameters:    short shipNumber
	//	Returns:       true if location ok
	//	History Log:
	//	              3/9/2017 DV completed version 1.0 
	//---------------------------------------------------------------------------
	bool CPlayer::autoValidate(short shipNumber)
	{
		short numberOfRows = 
			(toupper(m_gridSize) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols =
			(toupper(m_gridSize) == 'L') ? LARGECOLS : SMALLCOLS;
		bool returnValue = true;
		CDirection tempDir = m_ships[shipNumber].getOrientation();
		Direction orientation = tempDir.getDirection();
		CCell tempCell = m_ships[shipNumber].getBowLocation();
		unsigned short row = tempCell.get_row();
		unsigned short col = tempCell.get_col();
		if (orientation == VERTICAL)
		{   //  Check than length of ship will not extend the game grid.
			if (numberOfRows - row < shipSize[shipNumber])
				return false;
			for (short i = 0; i < shipSize[shipNumber]; i++) //for length of ship
			{ // Check ship's cells, vertically from bow location to end location
				Ship tempShip = m_gameGrid[MYGRID][row + i][col].getShip();
				if (tempShip != NOSHIP)
				{
					returnValue = false; //return false,  cell is not empty
					break;
				}
			}
		}
		else //	orientation is HORIZONTAL
		{
			if (numberOfCols - col < shipSize[shipNumber])
				return false;
			for (short i = 0; i < shipSize[shipNumber]; i++)
			{ //Check ship's cells,horizontally from bow location to end location
				Ship tempShip = m_gameGrid[MYGRID][row][col + i].getShip();
				if (tempShip != NOSHIP)
				{
					returnValue = false;
					break;
				}
			}
		}
		if (returnValue == false)
			return returnValue;
		else
			return true;
	}
	//---------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        isValidLocation()
	//	description:   checks to see if location is ok
	//	Input:         None
	//	Output:        None
	//	Calls:         getDirection, getOrientation, getBowlocation, get_row, 
	//			       get_col
	//	Called By:     CSinkTheFleet
	//	Parameters:    short shipNumber
	//	Returns:       true 
	//	History Log:
	//	              3/9/2017 DV completed version 1.0 
	//---------------------------------------------------------------------------
	bool CPlayer::isValidLocation(short shipNumber)
	{
		short numberOfRows = 
			(toupper(m_gridSize) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols =
			(toupper(m_gridSize) == 'L') ? LARGECOLS : SMALLCOLS;
		bool returnValue = true;
		CDirection tempDir = m_ships[shipNumber].getOrientation();
		Direction orientation = tempDir.getDirection();
		CCell tempCell = m_ships[shipNumber].getBowLocation();
		unsigned short row = tempCell.get_row();
		unsigned short col = tempCell.get_col();
		if (orientation == VERTICAL)
		{   //  Check than length of ship will not extend the game grid.
			if (numberOfRows - row < shipSize[shipNumber])
			{
				cout << "Ship extends beyond the borders" << endl;
				return false;
			}
			for (short i = 0; i < shipSize[shipNumber]; i++) //for length of ship
			{ // Check ship's cells, vertically from bow location to end location
				Ship tempShip = m_gameGrid[MYGRID][row + i][col].getShip();
				if (tempShip != NOSHIP)
				{
					returnValue = false; //return false,  cell is not empty
					break;
				}
			}
		}
		else //	orientation is HORIZONTAL
		{
			if (numberOfCols - col < shipSize[shipNumber])
			{
				cout << "Ship extends beyond the borders" << endl;
				return false;
			}
			for (short i = 0; i < shipSize[shipNumber]; i++)
			{ //Check ship's cells,horizontally from bow location to end location
				Ship tempShip = m_gameGrid[MYGRID][row][col + i].getShip();
				if (tempShip != NOSHIP)
				{
					returnValue = false;
					break;
				}
			}
		}
		if (returnValue == false)
			return returnValue;
		else
			return true;
	}

	//--------------------------------------------------------------------------
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
	//--------------------------------------------------------------------------
	void CPlayer::allocMem(CPlayer players[], char size)
	{
		short numberOfRows =
			(toupper(m_gridSize) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols =
			(toupper(m_gridSize) == 'L') ? LARGECOLS : SMALLCOLS;

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

	 //--------------------------------------------------------------------------
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
	 //---------------------------------------------------------------------------
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

	  //-------------------------------------------------------------------------
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
	  //--------------------------------------------------------------------------
	void CPlayer::allocMem(void)
	{
		short numberOfRows = 
			(toupper(m_gridSize) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols = 
			(toupper(m_gridSize) == 'L') ? LARGECOLS : SMALLCOLS;
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

	//------------------------------------------------------------------------
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
	//------------------------------------------------------------------------- 
	void CPlayer::deleteMem(void)
	{
		short numberOfRows =
			(toupper(m_gridSize) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols = 
			(toupper(m_gridSize) == 'L') ? LARGECOLS : SMALLCOLS;
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

	//------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        void CPlayer::printGrid(ostream& os, const short grid) 
	//					const
	//	description:   print function to output grid
	//	Input:         None 
	//	Output:        grid
	//	Calls:         CShip::print()
	//	Called By:     N/A
	//	Parameters:	   ostream& os, const short grid
	//	Returns:       N/A
	//	History Log:
	//	               2017-03-04 DV  completed version 1.0
	//-------------------------------------------------------------------------
	void CPlayer::printGrid(ostream& os, const short grid) const
	{
		short numberOfRows = 
			(toupper(m_gridSize) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols =
			(toupper(m_gridSize) == 'L') ? LARGECOLS : SMALLCOLS;
		char rowChar = (numberOfRows == SMALLROWS) ? 'H' : 'J';
		system("cls");
		for (short j = 1; j <= numberOfCols; ++j) 
			os << setw(3) << j;							
		os << endl;
		for (size_t i = 'A', row = 0; i <= rowChar; i++, row++)
		{
			os << (char)i;					      
			for (short col = 0; col < numberOfCols; col++)
				m_gameGrid[grid][row][col].print(os);		
			os << endl << HORIZ;						
			for (short h = 0; h < numberOfCols; h++)
				os << HORIZ << HORIZ << CR;
			os << endl;
		}
	}

	//-------------------------------------------------------------------------
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
	//-------------------------------------------------------------------------
	bool CPlayer::getGrid(const string  & fileName)
	{
		ifstream ifs;
		char cell = ' ';
		char fsize = 'S';
		try
		{
			ifs.open(fileName.c_str());
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
		// your code goes here ...
		fsize = ifs.get();		 //get char from filestream 
		if (fsize != m_gridSize) // checks if file gridsize matches 
		{
			return false;
		}
		m_gridSize = fsize;
		short numberOfRows = (toupper(m_gridSize) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols = (toupper(m_gridSize) == 'L') ? LARGECOLS : SMALLCOLS;
		string tempString = "";
		getline(ifs, tempString);
		getline(ifs, tempString);  //get first line of numbers representing columns
		Direction orientation;
		bool minesweeperFound = false;
		bool subFound = false;
		bool frigateFound = false;
		bool battleshipFound = false;
		bool carrierFound = false;
		for (short row = 0; row < numberOfRows; row++) 
		{  //get first char of each row to ignore A-H letters representing rows
			cell = ifs.get(); 
			cell = ifs.get();// junk char
			cell = ifs.get();// next needed cell
			for (short col = 0; col < numberOfCols; col++)
			{ // Mark cell on players game grid, set Ship class properties
				CCell tempCell(row, col);
				switch (cell) 
				{
				case ' ':
					m_gameGrid[MYGRID][row][col] = NOSHIP;
					break;
				case 'M': m_gameGrid[MYGRID][row][col] = MINESWEEPER;
					if (minesweeperFound == false)
					{
						orientation = (m_gameGrid[MYGRID][row][col + 1] == 'M') ?
							HORIZONTAL : VERTICAL;
						CDirection dir(orientation);
						setShipInfo(dir, tempCell, MINESWEEPER, 
							shipSize[static_cast<short>(MINESWEEPER)]);
						minesweeperFound = true;
					}
					break;
				case 'S': m_gameGrid[MYGRID][row][col] = SUB;
					if (subFound == false)
					{
						orientation = (m_gameGrid[MYGRID][row][col + 1] == 'S') ?
							HORIZONTAL : VERTICAL;
						CDirection dir(orientation);
						setShipInfo(dir, tempCell, SUB, 
							shipSize[static_cast<short>(SUB)]);
						subFound = true;
					}
					break;
				case 'F': m_gameGrid[MYGRID][row][col] = FRIGATE;
					if (frigateFound == false)
					{
						orientation = (m_gameGrid[MYGRID][row][col + 1] == 'F') ?
							HORIZONTAL : VERTICAL;
						CDirection dir(orientation);
						setShipInfo(dir, tempCell, FRIGATE, 
							shipSize[static_cast<short>(FRIGATE)]);
						frigateFound = true;
					}
					break;
				case 'B': m_gameGrid[MYGRID][row][col] = BATTLESHIP;
					if (battleshipFound == false)
					{
						orientation = (m_gameGrid[MYGRID][row][col + 1] == 'B') ?
							HORIZONTAL : VERTICAL;
						CDirection dir(orientation);
						setShipInfo(dir, tempCell, BATTLESHIP, 
							shipSize[static_cast<short>(BATTLESHIP)]);
						battleshipFound = true;
					}
					break;
				case 'C': m_gameGrid[MYGRID][row][col] = CARRIER;
					if (carrierFound == false)
					{
						orientation = (m_gameGrid[MYGRID][row][col + 1] == 'C') ?
							HORIZONTAL : VERTICAL;
						CDirection dir(orientation);
						setShipInfo(dir, tempCell, CARRIER, 
							shipSize[static_cast<short>(CARRIER)]);
						carrierFound = true;
					}
					break;
				}
				cell = ifs.get(); //junk chars
				cell = ifs.get();
				cell = ifs.get();
			}
			getline(ifs, tempString); // junk line
		}
		printGrid(cout, MYGRID);
		ifs.close();
		return true;
	}

	//----------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        void CPlayer::setShipInfo(const Direction & dir, const 
	//					CCell & cell, const Ship & ship, const short & 
	//					piecesOfShip)
	//	description:   sets CPlayer private properties
	//	Input:         None 
	//	Output:        N/A
	//	Calls:         setOrientation(), setPiecesLeft(), setName()
	//	Called By:     CPlayer::getGrid()
	//	Parameters:	   const Direction & dir     : ship's orientation
	//				   const CCell & cell        : ship's bow location
	//				   const Ship & ship         : ship type
	//				   const short & piecesOfShip: pieces of ship
	//	Returns:      
	//	History Log:
	//	               2017-03-04 DV  completed version 1.0
	//---------------------------------------------------------------------------- 
	void CPlayer::setShipInfo(const Direction & dir, const CCell & cell,
		const Ship & ship, const short & piecesOfShip)
	{
		short shipNum = static_cast<short>(ship);
		m_ships[shipNum].setOrientation(dir);
		m_ships[shipNum].setName((CShip)ship);
		m_ships[shipNum].setPiecesLeft(piecesOfShip);
	}

	//----------------------------------------------------------------------------
	//	Class:         CPlayer
	//	method:        void CPlayer::saveGrid(void)
	//	description:   saves a grid to txt file
	//	Input:         None 
	//	Output:        outputs grid to a txt file
	//	Calls:         CPlayer::printGrid()
	//	Called By:     CPlayer::autSetShips(), CPlayer::setShips()
	//	Parameters:	  
	//	Returns:      
	//	History Log:
	//	               2017-03-04 DV  completed version 1.0
	//---------------------------------------------------------------------------- 
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
		printGrid(outputFileStream, 0);
		cin.ignore(FILENAME_MAX, '\n');
		outputFileStream.close();
		cout << outputFileName << " saved." << endl;
	}
}