#ifndef FLEET_H
#define FLEET_H

#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <string>
#include <sstream>
#include "textGraphics.h"
#include "safeio.h"

using namespace std;
//---------------------------------------------------------------------------
//	Title:          CCell.h
//	Description:    This file contains the class definition for CCell
//	Programmer:     dark vader
//	Date:           3/4/2017
//	Version:	1.00
//	Environment:	 Hardware: i7 
//              Software: OS: Windows 7; 
//              Compiles under Microsoft Visual C++ 2012
//	class CShip:
//	Properties:
//			m_row - the row of the coordinate
//			m_col - the column of the coordinate
//	Methods:
//		Inline:
//			Constructor CCell(unsigned short row = 0, short col = 0)
//			Accessors: unsigned short getRow()
//					   unsigned short getCol()
//			Void Print()
//		Non-Inline:
//				void CCell::getCoord(istream& sin, char size);
//				ostream& operator<<(ostream& sout, CCell& cell);
//				
//  History Log:
//				9/12/06 PB comleted v 0.5
//				3/26/2017 dark vader completed v 0.6
//				3/27/2017 dark vader completed v 0.7
//				3/28/2017 dark vader completed v 0.8
//				3/29/2017 dark vader completed v 0.9
//				3/04/2017 dark vader completed v 1.0
//     
//-----------------------------------------------------------------------------
namespace DV_STF
{

	class CCell
	{
	public:
		CCell(unsigned short row = 0, unsigned short col = 0)
		{
			m_row = row; m_col = col;
		}
		void print(ostream& sout)
		{
			sout << static_cast<char>(m_row + 'A') << m_col + 1;
		}
		CCell inputCoordinates(istream& sin, char size);
		unsigned short get_row() { return m_row; }
		unsigned short get_col() { return m_col; }
		void print() { print(cout); }
		void increaseCol() { m_col++; }
		void increaseRow() { m_row++; }

	private:
		unsigned short m_row;	// row
		unsigned short m_col;	// column
	};
	ostream& operator<<(ostream& sout, CCell& cell);
}
#endif


