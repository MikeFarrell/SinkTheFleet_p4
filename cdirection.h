#ifndef CDIRECTION
#define CDIRECTION

namespace DV_STF
{
	enum Direction
	{
		HORIZONTAL, // 0
		VERTICAL	// 1
	};


	class CDirection
	{
	public:

		CDirection() { m_direction = HORIZONTAL; }			// Default constructor
		~CDirection() {};									// Destructor
		operator Direction() const { return m_direction; }	// Cast 

																		// Print 
		void print(ostream& os) const { (m_direction == VERTICAL) ? os << 'V' : os << 'H'; }
		void print(void) const { (m_direction == VERTICAL) ? cout << 'V' : cout << 'H'; }
		//Related functions?? should these be public?
		ostream& operator<<(ostream& os) { print(os); return os; }
		istream& operator >> (istream& is) {}
	private:
		Direction m_direction;							// HORIZONTAL or VERTICAL
	};
}
#endif
