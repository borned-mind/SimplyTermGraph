#include"Draw.hpp"
namespace Term{

 namespace draw{
	void line(uint x, uint y, uint x1, uint y1, char ch){
		//std::cout << "From " << x << ":" << y << " to " << x1 << ":" << y1 << std::endl;
		while(x != x1 || y!=y1){
			pixel(x,y);

			if(x != x1)
				x > x1 ? x-- : x++;
			if(y != y1)
				y > y1 ? y-- : y++;
		}
	}


	void pixel(uint x, uint y, char ch){
		Cursor::set(x,y);
		std::cout << ch ;
	}

	void pixel(position pos, char ch){
		pixel(pos.x, pos.y, ch);
	}


	void circle(short x, short y, short rad, char ch){
		short xt = 0, radt=rad;
		while(radt != -rad+1 ){
			pixel(x-xt,y+radt);
			pixel(x+xt,y+radt);
			radt--;
			radt > 0 ? xt++ : xt--;
		}

	}


		

	void curve( std::initializer_list< std::pair<short,short> > positions ){
		std::vector<position> positions_vec{};
		for(auto position = positions.begin();
			position!=positions.end() && positions.size() != 1;
				position++)		
			{
			/*
				if( check_odd_curve(positions, position) ){
					line( std::get<0>(*position),
				 		std::get<1>(*position),
							 std::get<0>(*(position-1)),
								 std::get<1>(*(position-1)) );
						break;
				}
				line( std::get<0>(*position),
				 std::get<1>(*position),
					 std::get<0>(*(position+1)),
						 std::get<1>(*(position+1)) );
			*/
				positions_vec.push_back( {std::get<0>(*position),std::get<1>(*position)} );
			}
			curve(positions_vec);
			
			
		
	}

	

	void curve( std::vector<position> positions ){
		for(auto position = positions.begin();
			position!=positions.end() && positions.size() != 1;
				position++){
					if( position+1 == positions.end() ){
						line( (*(position-1)).x, (*(position-1)).y, (*position).x, (*position).y );
						break;
					}
					line( (*position).x, (*position).y, (*(position+1)).x, (*(position+1)).y );
				}
	}


	void circle(position center, uint rad, char ch){
		circle(center.x, center.y, rad, ch);
	}
	
	void rect(uint x, uint y, uint x1, uint y1, char ch){

		while(y!=y1){
			Cursor::set(x,y);

			line(x, y, x1, y);			
			//for(auto xt=x; xt!=x1; (xt > x1 ? xt-- : xt++) )

			
			if(y != y1)
				y > y1 ? y-- : y++;
		}
	
	}
}//namespace Draw
}
