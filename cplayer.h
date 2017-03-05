#ifndef CPLAYER
#define CPLAYER
#include "cshipinfo.h"
#include "cship.h"
#include "cdirection.h"

using namespace std;

namespace DV_STF
{
	class CPlayer
	{
	public:
		CPlayer() {};
		~CPlayer() {};
		//copy()									//Deep copy
		//operator=									//Deep copy assignment
		//Accessors

		unsigned short getWhichPlayer() const { return m_whichPlayer; }
		short getPiecesLeft() const { return m_piecesLeft; }
		char getGridSize() const { return m_gridSize; }

		CShip getCell(short & whichGrid, CCell & cell) const
		{
			return m_gameGrid[whichGrid][cell.get_row()][cell.get_col()];
		}

		void setGridSize(char size) { m_gridSize = size; }
		void setCell(short & whichGrid, CCell & cell, CShip & ship)
		{
			m_gameGrid[whichGrid][cell.get_row()][cell.get_col()] = ship;
		} // set the proper cell to ship

		  //printGrid(ostream& os);		 
		  //getGrid(string filename);					// inputs grid from file
		  //saveGrid();
		  //setShips();							// allow player to setup ship
		  //hitShip(CShip ship);						// Decrement pieces left for ship & for fleet
		  //bool isValidLocation(short whichShip);			// the index # of which ship in array
		  //operator[] const; 
		  //operator--();
	private:
		unsigned short m_whichPlayer;
		short m_piecesLeft;
		CShipInfo m_ships[6];
		char m_gridSize;
		CShip ** m_gameGrid[2];

		//alloc mem
		//delete mem
	};
}
#endif

