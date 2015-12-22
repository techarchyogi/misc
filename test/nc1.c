#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_CITIES 200000

#define MAX(i,j) (i>j?i:j) 

long c[MAX_CITIES] = {0} ;
short p[MAX_CITIES] = {0} ;

int main ( void )
{
    int n_cases = 0 ;
	int tc = 0 ;
    int i = 0 ;
    int j = 0 ;
    int city_count = 0 ;
	long long sum = 0 ;
    long long dist = 0;
	long ct = 0;
	short pop = 0 ;

    scanf("%d", &n_cases );
    for ( tc = 0 ; tc <n_cases ; tc++ ){
		int count = 0;
        sum = 0 ;
		scanf( "%d", &city_count );
		

        for ( j = 0 ; j < city_count ; j++ ){
            scanf("%lu", &ct );
			c[j] = ct ;
			
        }
        for ( j = 0 ; j < city_count ; j++ ){
            scanf("%hi", &pop );
			p[j] = pop ;
        }
        //compute(city_count);
        for ( i = 0 ; i < city_count-1 ; i++ ){
			for ( j = i+1 ; j < city_count ; j++ ){
				// dist = c[i] > c[j]  ? c[i] - c[j] : c[j] - c[i] ;
				dist =abs( c[i] - c[j] ) ; 
				sum += ( MAX(p[i],p[j]) ) * dist ;
				if ( sum >= 1000000007 ) {
					sum = sum%1000000007 ;
				}
				count++ ;
			}
		}
		printf ( "%llu, count = %d\n", sum, count);
    }
}

