#include"term.hpp"
namespace Term{

	namespace draw{
		void line(uint x, uint y, uint x1, uint y1, char ch='#');
		void rect(uint x, uint y, uint x1, uint y1, char ch='#');

		void pixel(uint x, uint y, char ch='#');
		void pixel(position pos, char ch='#');

		void circle(short, short, short rad, char ch='#');
		void circle(position center, uint rad, char ch='#');

		[[deprecated("You can use vector for it")]] void curve( std::initializer_list< std::pair<short,short> > );
		void curve( std::initializer_list< position > ) =delete;
		void curve( std::vector<position> );
	}


}
