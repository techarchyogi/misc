#include <stdio.h>

int f( int i )
{
	if ( i == 4 )
		return 2 ;
	else 
		f(i+1) ;
}

int main(void)
{
	printf("%d\n",f(2));
}
