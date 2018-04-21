#include"menu.hpp"
#include<chrono>
#include<future>

using  half_second = std::chrono::duration< int, std::ratio<1,2> >;

constexpr auto wait_event = 3;

static inline auto msg_debug(std::string && msg){
	std::cout << "DEBUG: " << msg << std::endl;
	std::this_thread::sleep_for( half_second(wait_event) );
	Term::Colors::set_default_color();
	Term::clear_screen();
}

int main(int argc, char ** argp, char  ** envp){


	Term::TermSize::update();

	msg_debug("Check foreground");


	for(char color{ char(Term::Colors::color::white) }; 
		color != char(Term::Colors::color::red);color--
		
	){
		Term::Colors::setColor( static_cast<Term::Colors::color>(color),  false, Term::Font::style::bold );
		std::cout << "Hello color" << std::endl;
	}

	

	msg_debug("Check background");


	for(char color{ char(Term::Colors::color::white) }; 
		color != char(Term::Colors::color::red);color--
		
	){
		Term::Colors::setColor( static_cast<Term::Colors::color>(color), true, Term::Font::style::set_background_rgb );
		std::cout << "Hello color" << std::endl;
	}



	msg_debug("Check fillcolor");


	for(char color{ char(Term::Colors::color::white) }; 
		color != char(Term::Colors::color::red);color--
		
	){
		
		Term::Colors::fill_screen( static_cast<Term::Colors::color>(color) );
		std::this_thread::sleep_for( half_second(1) );
	}
//check x and y
	msg_debug("Check x:y");

	std::cout <<  "X: " << Term::TermSize::X() << std::endl;
	std::cout <<  "Y: " << Term::TermSize::Y() << std::endl;


	msg_debug("Check Cursor set");


	std::this_thread::sleep_for( half_second(wait_event) );
	Term::Cursor::set( Term::TermSize::X() / 2, Term::TermSize::Y() / 2 );
	std::cout << "Hello!" << std::endl;
	Term::Cursor::restore();

	msg_debug("Check figures");




	msg_debug("Check pixel");
	Term::draw::pixel( Term::TermSize::X() / 2, Term::TermSize::Y() / 2 );

	msg_debug("Check line");
	Term::draw::line(0,0, 100, 100 );

	msg_debug("Check curve");
	//std::initializer_list<std::pair<short, short> > list = { {50,50},{60,60},{30,90} } ;
	std::vector< Term::position > list { {50,50},{90,60},{30,90},{0,0} };
	Term::draw::curve(list);

	msg_debug("Check rect");
	Term::draw::rect(60,60,30,30);

	msg_debug("Check circle");	
	Term::draw::circle( 50, 50, 10 );


	
}
