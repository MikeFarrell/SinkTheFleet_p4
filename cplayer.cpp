#include "cplayer.h"

using namespace std;

namespace DV_STF
{

	CShipInfo CPlayer::operator[](short index) const
	{
		if (index > 0 && index < DV_STF::SHIP_SIZE_ARRAYSIZE)
			return m_ships[index];
		//return CShipInfo(CShip(), CDirection(), CCell());
		return *this->m_ships; //fix this line
	}

	CPlayer CPlayer::operator--()
	{
		m_piecesLeft--;
		return *this;
	}

	CPlayer CPlayer::operator--(int)
	{
		CPlayer temp = *this;
		m_piecesLeft--;
		return temp;
	}


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

	void CPlayer::printGrid(ostream& os, short grid)
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
				m_gameGrid[row][col]->print();          //Print char code for ship		
			os << endl << HORIZ;						//Print out horizontal bar
			for (short h = 0; h < numberOfCols; h++)
				os << HORIZ << HORIZ << CR;
			os << endl;
		}
	}


	// getGrid() send it the filename to open.  Returns true if file loaded ok
	bool CPlayer::getGrid(string fileName)
	{
		string line;
		ifstream ifs;
		Ship ship = NOSHIP;
		short shipCount[SHIP_SIZE_ARRAYSIZE] = { 0 };
		char cell = ' ';
		char fsize = 'S';
		short numberOfRows = (toupper(m_gridSize) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols = (toupper(m_gridSize) == 'L') ? LARGECOLS : SMALLCOLS;
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
		fsize = ifs.get(); //get char from filestream 
		if (fsize != m_gridSize)
		{

			return false;
		}
		string tempString = ""; 
		getline(ifs, tempString);
		getline(ifs, tempString);  //get first line of numbers representing columns
		Direction orientation;
		bool minesweeperFound = false;
		bool subFound = false;
		bool frigateFound = false;
		bool battleshipFound = false;
		bool carrierFound = false;
		//static const short shipSize[SHIP_SIZE_ARRAYSIZE] = { 0, 2, 3, 3, 4, 5 }; // just here for reference..
		for (short row = 0; row < numberOfRows; row++) // Read in game grid cells 1 at a time
		{
			cell = ifs.get(); //get first char of each row to ignore A-H letters representing rows
			cell = ifs.get();// junk char
			cell = ifs.get();// next needed cell
			for (short col = 0; col < numberOfCols; col++)
			{
				CCell tempCell(row, col);
				switch (cell)  // Mark cell on players game grid, set Ship struct properties on first pass
				{
				case ' ': 
					m_gameGrid[0][row][col] = NOSHIP;
					break;
				case 'M': m_gameGrid[0][row][col] = MINESWEEPER;
					if (minesweeperFound == false)
					{
						orientation = (m_gameGrid[0][row][col + 1] == 'M') ? HORIZONTAL : VERTICAL;
						CDirection dir(orientation);
						setShipInfo(dir, tempCell, MINESWEEPER, shipSize[static_cast<short>(MINESWEEPER)]);
						minesweeperFound = true;
					}
					break;
				case 'S': m_gameGrid[0][row][col] = SUB;
					if (subFound == false)
					{
						orientation = (m_gameGrid[0][row][col + 1] == 'S') ? HORIZONTAL : VERTICAL;
						CDirection dir(orientation);
						setShipInfo(dir, tempCell, SUB, shipSize[static_cast<short>(SUB)]);
						subFound = true;
					}
					break;
				case 'F': m_gameGrid[0][row][col] = FRIGATE;
					if (frigateFound == false)
					{
						orientation = (m_gameGrid[0][row][col + 1] == 'F') ? HORIZONTAL : VERTICAL;
						CDirection dir(orientation);
						setShipInfo(dir, tempCell, FRIGATE, shipSize[static_cast<short>(FRIGATE)]);
						frigateFound = true;
					}
					break;
				case 'B': m_gameGrid[0][row][col] = BATTLESHIP;
					if (battleshipFound == false)
					{
						orientation = (m_gameGrid[0][row][col + 1] == 'B') ? HORIZONTAL : VERTICAL;
						CDirection dir(orientation);
						setShipInfo(dir, tempCell, BATTLESHIP, shipSize[static_cast<short>(BATTLESHIP)]);
						battleshipFound = true;
					}
					break;
				case 'C': m_gameGrid[0][row][col] = CARRIER;
					if (carrierFound == false)
					{
						orientation = (m_gameGrid[0][row][col + 1] == 'C') ? HORIZONTAL : VERTICAL;
						CDirection dir(orientation);
						setShipInfo(dir, tempCell, CARRIER, shipSize[static_cast<short>(CARRIER)]);
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
		m_gridSize = fsize;
		printGrid(cout, m_whichPlayer);
		ifs.close();
		return true;
	}
	void CPlayer::setShipInfo(const Direction & dir, const CCell & cell, 
		const Ship & ship, const short & piecesOfShip)
	{
		short shipNum = static_cast<short>(ship);
		m_ships[shipNum].setOrientation(dir);
		m_ships[shipNum].setName((CShip)ship);
		m_ships[shipNum].setPiecesLeft(piecesOfShip);
	}
}
