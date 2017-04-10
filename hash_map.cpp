#include <iostream>
#include <ext/hash_map>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;
int add_to_map ( __gnu_cxx::hash_map<int, string> &h , int count ) 
{
	string name = "Student" ; 
	for ( int i=0 ; i<count ; i++ ){
		ostringstream s ;
		s << i ;
		string n = s.str();
		// cout << name << n << endl ;
		n = name + n ;
		h[i] = n ;
	}
}
int main ( int argc, char **argv )
{
	__gnu_cxx::hash_map<int, string>roll_no_name ;
	int count;
	int j ;
	cin >> count ;
	cout << count << endl ;
	add_to_map ( roll_no_name, count );

	/* __gnu_cxx::hash_map<int, string>::iterator it = roll_no_name.begin();

	for ( ; it++ ; it < roll_no_name.end() ){
		roll_no_name[i] ;
	}
	*/

	for ( int i = 0 ; i < 10 ; i++ ){
		cin >> j ;
		cout << roll_no_name[j] << endl ;
	}

}

