#include <iostream>
#include <map>
#include <iostream>
#include <string>

int main (int argc, char ** argv ) 
{
	using namespace std ;
	/*
	 * std::map < int, std::string > simple ;
	simple.insert ( std::make_pair(1, "Ojas" ));
	simple.insert ( std::make_pair(2, "Shreyan"));

	std::map<int, std::string>::iterator it = simple.begin();
	while ( it != simple.end() ){
		std::cout << it->first << " :: " << it->second << std::endl ;
		it++ ;
	} */
	map < int, string > simple ;
	simple.insert ( make_pair(1, "Ojas" ));
	simple.insert ( make_pair(2, "Shreyan"));

	map<int, string>::iterator it = simple.begin();
	while ( it != simple.end() ){
		cout << it->first << " :: " << it->second << endl ;
		it++ ;
	}
	return 0 ;
}

