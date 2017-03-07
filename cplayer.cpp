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
		short numberOfRows = (toupper(size) == 'L') ? LARGEROWS : SMALLROWS;
		short numberOfCols = (toupper(size) == 'L') ? LARGECOLS : SMALLCOLS;

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
}