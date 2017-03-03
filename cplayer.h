#ifndef CPLAYER
#define CPLAYER

#include "oop.h"

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
		unsigned short getWhichPlayer(void) const { return m_whichPlayer; }
		short getPiecesLeft(void) const { return m_piecesLeft; }
		char getGridSize(void) const { return m_gridSize; }

		CShip getCell(const short & whichGrid, const CCell & cell) const
			{ return m_gameGrid[whichGrid][cell.row][cell.col]; }

		void setGridSize(const char size) { m_gridSize = size; }
		void setCell(const short & whichGrid, const CCell & cell, const Cship & ship) 
			{m_gameGrid[whichGrid][cell.row][cell.col] = ship;} // set the proper cell to ship

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
		//allocMem();
		//deleteMem();
	};
}
#endif
