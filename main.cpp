#include"term.hpp"
#include<chrono>
#include<future>

using  half_second = std::chrono::duration< int, std::ratio<1,2> >;

int main(int argc, char ** argp, char  ** envp){
/*	for(auto env = envp; *env!=nullptr;env++){
		if( strstr(*env,"LINES") != 0 );
			std::cout << *env << std::endl;
	}
*/
//Check foregrounds
	Term::TermSize::update();
	for(char color{ char(Term::Colors::color::white) }; 
		color != char(Term::Colors::color::red);color--
		
	){
		Term::Colors::setColor( static_cast<Term::Colors::color>(color),  false, Term::Font::style::bold );
		std::cout << "Hello color" << std::endl;
	}
	std::this_thread::sleep_for( half_second(3) );
	Term::Colors::set_default_color();
//Check backgrounds	
	for(char color{ char(Term::Colors::color::white) }; 
		color != char(Term::Colors::color::red);color--
		
	){
		Term::Colors::setColor( static_cast<Term::Colors::color>(color), true, Term::Font::style::set_background_rgb );
		std::cout << "Hello color" << std::endl;
	}

	std::this_thread::sleep_for( half_second(3) );

//check Fill screen
	for(char color{ char(Term::Colors::color::white) }; 
		color != char(Term::Colors::color::red);color--
		
	){
		
		Term::Colors::fill_screen( static_cast<Term::Colors::color>(color) );
		std::this_thread::sleep_for( half_second(1) );
	}
//check x and y
	std::cout <<  "X: " << Term::TermSize::X() << std::endl;
	std::cout <<  "Y: " << Term::TermSize::Y() << std::endl;

	std::this_thread::sleep_for( half_second(3) );
	
	Term::clear_screen();
	Term::Cursor::set( Term::TermSize::X() / 2, Term::TermSize::Y() / 2 );
	std::cout << "Hello!" << std::endl;
	Term::Cursor::restore();


}
