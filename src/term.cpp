#include"term.hpp"
namespace Term{


	template <typename ... Msgs> auto error_term(std::string msg, Msgs ... msgs){
		Text::join_text(msg, msgs...);
		//std::cerr << msg << std::endl;
		//return fprintf(stderr, "%s\n", msg);
		throw( std::runtime_error( "ERROR TERM: "+ msg ) );
		return 0;
	}	

	void TermSize::update(void) noexcept{
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
		clear_screen();
		Term::Cursor::set(0,0);
	}

	unsigned int TermSize::getLines(void){
		char * lines = getenv("LINES");
		return  lines == NULL ? 
			(ws.ws_row == 0 ? error_term("Can't get LINUS") : ws.ws_row) : atoi(lines); 
	}
	unsigned int TermSize::getColumns(void) {
		char * columns = getenv("COLUMNS");
		return  columns == NULL ? 
			(ws.ws_col == 0 ? error_term("Can't get COLUMNS") : ws.ws_col) : atoi(columns);
	}


//colors
	void Colors::setColor(Colors::color color, bool background, Font::style style) noexcept{
		std::cout << Colors::setchar << "[" << ubyte(style) << 
			(ubyte(style)%10 == 8 ? ";5;" : ";" )
  				<< (background == true ? ubyte(color)+10 : ubyte(color) ) << "m";
	}

	void Colors::set_default_color(void) noexcept{
		std::cout << Colors::setchar << "[0m";
	}
//TermCommand
	void Colors::fill_screen(Colors::color color) noexcept{
		clear_screen();
		setColor(color, true);
		auto x = TermSize::X();
		auto y = TermSize::Y();
		for(y;y--;){
			for(auto xt = x;xt--;)
				std::cout << " ";
			std::cout << std::endl;
		}
		

		set_default_color();
	}

	void clear_screen(void) noexcept{
		std::cout << Colors::setchar << "c";
	}

	namespace Cursor{
		void set(short x, short y) noexcept{
				std::cout << Colors::setchar << "[" << y << ";" << x << "f";
		}

		void move_up(ushort y) noexcept{
			std::cout << Colors::setchar << "[" << y << "A";
		}
		void move_down(ushort y) noexcept{
			std::cout << Colors::setchar << "[" << y << "B";
		}
		void move_forward(ushort x) noexcept{
			std::cout << Colors::setchar << "[" << x << "C";
		}
		void move_backward(ushort x) noexcept{
			std::cout << Colors::setchar << "[" << x << "D";
		}	
		void restore(void) noexcept{
			std::cout << Colors::setchar << "[u";
		}
		void save(void) noexcept{
			std::cout << Colors::setchar << "[s";
		}
	}




}
