#ifndef CCELL
#define CCELL


namespace DV_STF
{
	class CCell
	{
	public:
		CCell();
		unsigned short get_row() { return m_row; }
		unsigned short get_col() { return m_col; }

	private:
		unsigned short m_row;
		unsigned short m_col;
	};
}
#endif

