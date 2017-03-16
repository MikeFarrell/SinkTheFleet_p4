//----------------------------------------------------------------------------
// File:		cplayer.h
// 
// Description: Header file for CPlayer
//	
// Programmers:	Dark Vader
// 
// Environment: Hardware: i7 
//              Software: OS: Windows 10; 
//              Compiles under Microsoft Visual C++ 2015
//----------------------------------------------------------------------------

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
	//---------------------------------------------------------------------------
	//	Title:          CPlayer.h
	//	Description:    This file contains the class definition for CPlayer
	//	Programmers:     dark vader
	//	Date:           3/4/2017
	//	Version:	1.00
	//	Environment:	 Hardware: i7 
	//              Software: OS: Windows 10 
	//              Compiles under Microsoft Visual C++ 2015
	//	class CPlayer:
	//	Properties:
	//			unsigned short m_whichPlayer;
	//			short m_piecesLeft;
	//			CShipInfo m_ships[SHIP_SIZE_ARRAYSIZE];
	//			char m_gridSize;
	//			CShip ** m_gameGrid[2];
	//			void allocMem(CPlayer players[], char size); 
	//			void deleteMem(CPlayer players[], char size);
	//			void allocMem(void);
	//			void deleteMem(void);
	//
	//	Methods:
	//		Inline:
	//			CPlayer(unsigned short whichPlayer = 0, char gridSize = 'L')
	//			unsigned short getWhichPlayer() const { return m_whichPlayer; }
	//			short getPiecesLeft() const { return m_piecesLeft; }
	//			char getGridSize() const { return m_gridSize; }
	//			CShip getCell(const short & whichGrid, CCell & cell) const
	//			void setGridSize(const char size) { m_gridSize = size; }
	//			void setCell(const short & whichGrid, CCell & cell, const CShip & ship)
	//		Non-Inline:
	//			CPlayer & operator=(const CPlayer& old);
	//			void setShipInfo(const Direction & dir, const CCell & cell, const Ship & ship, const short & piecesOfShip);
	//			void printGrid(ostream& os, const short grid) const;
	//			bool getGrid(const string filename); //inputs grid from file
	//			void saveGrid(void) const;
	//			void setShips();	//allow player to setup ship
	//			void hitShip(CShip ship); //Decrement pieces left for ship & for fleet
	//			bool isValidLocation(short whichShip); // the index # of which ship in array
	//			CShipInfo operator[](short index) const;
	//			CPlayer operator--();
	//			CPlayer operator--(int);
	//		Related:
	//				ostream& operator<<(ostream& sout, CShip& ship);
	//				istream &operator>>(istream &sin, CShip &ship)
	//  History Log:
	//				3/26/2017 dark vader completed v 0.6
	//				3/27/2017 dark vader completed v 0.7
	//				3/28/2017 dark vader completed v 0.8
	//				3/29/2017 dark vader completed v 0.9
	//				3/08/2017 dark vader completed v 1.0
	//     
	//-----------------------------------------------------------------------------
	class CPlayer
	{
	public:
		//Constructors & Destructors
		CPlayer(unsigned short whichPlayer = 0, char gridSize = 'L') :
			m_whichPlayer(whichPlayer), m_gridSize(gridSize), m_piecesLeft(17)
		{
			// Sets both game grids to NULL and calls allocMem().  The nullptrs are in allocMem() too though?? 
			// so not exactly sure what he wants here..
			m_gameGrid[0] = nullptr;
			m_gameGrid[1] = nullptr;
			allocMem();
			//initializeShips() // need something here to 'initialize' player's ship array
		}

		CPlayer(const CPlayer& player)
		{
			*this = player;
		}					//Deep copy constructor

		~CPlayer() { deleteMem(); };


		//operator=									//Deep copy assignment

		// INLINE 
		unsigned short getWhichPlayer() const { return m_whichPlayer; }
		short getPiecesLeft() const { return m_piecesLeft; }
		char getGridSize() const { return m_gridSize; }
		CShip getCell(const short & whichGrid, CCell & cell) const
		{
			return m_gameGrid[whichGrid][cell.get_row()][cell.get_col()];
		}

		void setGridSize(const char size) { m_gridSize = size; }
		void setCell(const short & whichGrid, CCell & cell, const CShip & ship)
		{
			m_gameGrid[whichGrid][cell.get_row()][cell.get_col()] = ship;
		} // set the proper cell to ship

// NON-INLINE
		CPlayer & operator=(const CPlayer& old);

		void setShipInfo(const Direction & dir, const CCell & cell, const Ship & ship, const short & piecesOfShip);
		void printGrid(ostream& os, const short grid) const;
		bool getGrid(const string filename); //inputs grid from file
		void saveGrid(void) const;
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

		//  For both players at the same time
		void allocMem(CPlayer players[], char size); //alloc mem
		void deleteMem(CPlayer players[], char size);//delete mem
		//  For 1 player at a time
		void allocMem(void);
		void deleteMem(void);
	};
}
#endif


