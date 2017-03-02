
#ifndef OOP_H
#define OOP_H

#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <string>
#include <sstream>
#include "cship.h"
#include "cdirection.h"
#include "ccell.h"
#include "cshipinfo.h"
#include "cplayer.h"
#include "csinkthefleet.h"
//#include "textGraphics.h"
//#include "safeio.h"

using namespace std;

namespace DV_STF
{
	enum Ship
	{
		NOSHIP,		 // 0
		MINESWEEPER, // 1 (1-5) -- used only for owner
		SUB,		 // 2
		FRIGATE,	 // 3
		BATTLESHIP,	 // 4
		CARRIER,	 // 5
		HIT,		 // 6 (6-7)-- used only for other side
		MISSED,		 // 7 
	};

	enum Direction
	{
		HORIZONTAL, // 0
		VERTICAL	// 1
	};
}
#endif
