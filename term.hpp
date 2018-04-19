#pragma once
#include<sstream>
#include<iostream>
#include<string>
#include<sys/ioctl.h>
#include<unistd.h>
#include"utils.hpp"


namespace Term{
	using byte = char;
	using ubyte = unsigned byte;
	using ushort = unsigned short;

	namespace TermSize{
		static struct winsize ws;

		void update(void);

		unsigned int getLines(void);
		unsigned int getColumns(void);
		static unsigned int (*X)(void) = &Term::TermSize::getColumns;
		static unsigned int (*Y)(void) = &Term::TermSize::getLines;
	};

	namespace Font{
		enum class style : ubyte {
			reset,
			normal=0,
			bold,
			italic,
			underline,
			blink_slow,
			blink_rapid,
			reverse,
			conceal,
			crossedout,
			primary,
			alternative,
			fraktur=20,
			off_bold,
			dunderline=22,
			nbold,
			nitalic,
			nfraktur=24,
			off_underline=25,
			off_blink=26,
			inverse_off=27,
			reveal,
			ncrossedout,

			set_foreground,
			set_foregeround_rgb=38,
			default_foreground,

			set_background=40,
			set_background_rgb=48,
			default_background,
			framed=51,
			encircled=52,
			overline=53,
			notframed=54,
			notencircled=54,
			notoverlined=55,
			ideogram=66,
			set_bright_foreground=90,
			set_bright_background=100 
		};
	}

	namespace Colors{
		enum class color : ubyte{
			black =30,
			red,
			green,
			yellow,
			blue,
			magenta,
			cyan,
			white, // foreground + 10
			bright_black=90,
			bright_red,
			bright_green,	
			bright_yellow,
			bright_blue,
			bright_magenta,
			bright_cyan,
			bright_white
		};

		constexpr const char setchar = '\033';


		void setColor(Colors::color color=Colors::color::black, bool background=false, Font::style style=Font::style::normal);
		void set_default_color(void) __attribute__( (destructor) );
		void fill_screen(Colors::color color=Colors::color::black);
		
	}

	namespace Cursor{
		void set(ushort x, ushort y);
		void move_up(ushort y);
		void move_down(ushort y);
		void move_forward(ushort x);
		void move_backward(ushort x);
		void restore(void);
		void save(void);
	}

	void clear_screen(void);

}


