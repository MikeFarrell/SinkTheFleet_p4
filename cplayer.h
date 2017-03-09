#ifndef CPLAYER
#define CPLAYER
#include "cshipinfo.h"
#include "cship.h"
#include "cdirection.h"
#include "safeio.h"

#define MYGRID 0
#define YOURGRID 1
using namespace std;

namespace DV_STF
{
	class CPlayer
	{
	public:
		//Constructors & Destructors
		CPlayer(unsigned short whichPlayer = 0, char gridSize = 'L') :
			m_whichPlayer(whichPlayer), m_gridSize(gridSize)
		//CPlayer(unsigned short whichPlayer, char gridSize)
		{
			// Sets both game grids to NULL and calls allocMem().  The nullptrs are in allocMem() too though?? 
			// so not exactly sure what he wants here..
			m_gameGrid[0] = nullptr;
			m_gameGrid[1] = nullptr;
			m_gridSize = gridSize;
			allocMem();
			
			//initializeShips() // need something here to 'initialize' player's ship array
		}
		CPlayer(const CPlayer & player);					//Deep copy constructor
		~CPlayer() {};
		
		//operator=									//Deep copy assignment
		CPlayer & operator=(const CPlayer & player);

		// INLINE 
		unsigned short getWhichPlayer() const { return m_whichPlayer; }
		short getPiecesLeft() const { return m_piecesLeft; }
		char getGridSize() const { return m_gridSize; }
		CShip getCell(const short & whichGrid, CCell & cell) const
			{return m_gameGrid[whichGrid][cell.get_row()][cell.get_col()];}
		void setGridSize(const char size) { m_gridSize = size; }
		void setCell(const short & whichGrid, CCell & cell, const CShip & ship)
			{m_gameGrid[whichGrid][cell.get_row()][cell.get_col()] = ship;} // set the proper cell to ship

		// NON-INLINE
		void setShipInfo(const Direction & dir, const CCell & cell, const Ship & ship, const short & piecesOfShip);
		void printGrid(ostream& os, const short grid) const;
		bool getGrid(const string & filename); //inputs grid from file
		void saveGrid(void) const;
		
		void setShips();	//allow player to setup ship
		void hitShip(CShip ship); //Decrement pieces left for ship & for fleet
		bool isValidLocation(short shipNumber); // the index # of which ship in array
		CShipInfo operator[](short index) const;
		CPlayer operator--();
		CPlayer operator--(int);
	private:
		unsigned short m_whichPlayer;
		short m_piecesLeft;
		CShipInfo m_ships[SHIP_SIZE_ARRAYSIZE]; //shipinfo array
		char m_gridSize;
		CShip ** m_gameGrid[2];
		//  For both players at the same time
		void allocMem(CPlayer players[], char size); //alloc mem
		void deleteMem(CPlayer players[], char size);//delete mem
		//  For 1 player at a time
		void allocMem(void);
		void deleteMem(void);
	};
}
#endif


