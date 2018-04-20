#include"menu.hpp"


namespace Term{
	namespace Menu{
		void init(Colors::color bcolor, Colors::color fcolor){
			Term::Colors::fill_screen(bcolor);
			
			position center(Term::TermSize::X() / 4, Term::TermSize::Y() / 2);
			Term::Cursor::set( center.x, center.y );
			
			
		}

	}

}
