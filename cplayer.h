#ifndef CPLAYER
#define CPLAYER
#include "cshipinfo.h"
#include "cship.h"
#include "cdirection.h"
#include "safeio.h"

using namespace std;

namespace DV_STF
{
	class CPlayer
	{
	public:
		CPlayer(unsigned short whichPlayer = 0, char gridSize = 'L') :
			m_whichPlayer(whichPlayer), m_gridSize(gridSize)
		{

		}
		~CPlayer() {};
		//CPlayer copy(void) const;									//Deep copy

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

		void setShipInfo(const Direction & dir, const CCell & cell, const Ship & ship, const short & piecesOfShip);
		void printGrid(ostream& os, short grid);
		bool getGrid(string filename); //inputs grid from file
		void saveGrid();
		void setShips();	//allow player to setup ship
		void hitShip(CShip ship); //Decrement pieces left for ship & for fleet
		bool isValidLocation(short whichShip); // the index # of which ship in array
		CShipInfo operator[](short index) const;
		CPlayer operator--();
		CPlayer operator--(int);
	private:
		unsigned short m_whichPlayer;
		short m_piecesLeft;
		CShipInfo m_ships[SHIP_SIZE_ARRAYSIZE]; //shipinfo array
		char m_gridSize;
		CShip ** m_gameGrid[2];

		void allocMem(CPlayer players[], char size); //alloc mem
		void deleteMem(CPlayer players[], char size);//delete mem
	};
}
#endif


