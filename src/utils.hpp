namespace Text{
	inline auto join_text(std::string & emsg){}
	template<typename T, typename ... Args> auto join_text(std::string & emsg, T msg, Args ... args){
		emsg += static_cast<std::ostringstream*>( &(std::ostringstream() << msg) )->str();
		join_text(emsg, args...);
	}
}
