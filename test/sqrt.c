#include <stdio.h>
#include <math.h>

/*
int sqrt(int v)

v=10, sqrt=3
v=15, sqrt=3

int sqrt(int v)
{
    int i = 1 ;
    if ( v == 0 ) return 0 ;
    for ( i = 1 ;  ; i++ ) {
       if ( i*i > v ) return (i-1)  ;
       else if ( i*i == v ) return i ;
     }
}
*/
int sqrt_1 ( int v )
{
    int i = ceil(v/2) ;
    while ( i > 1 )
    {
        if ( i * i > v ) {
			i = (int)ceil(((double)i)/2) ; 
		}	else if ( i*i <=  v ) {
              int j = i ;
              for ( j = i ; j <= 2*i ; j++ ){
                  if ( j*j > v )return (j-1);
                  else if ( j*j == v ) return j ; 
              }
              return j ; 
        }    
    }
	return 1 ;
                    
}
int sqrt_2 ( int v )
{
	int i = v/2 ;

}
int main ( void )
{	
	int i = 0 ;
	while ( scanf("%d", &i)  != EOF ){
		printf ( "Sqrt of i is %d\n",sqrt_1 ( i ) );
	} 
}
