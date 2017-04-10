#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * n cities are connected, each has its own population p. Each city is
 * connected to another city with number of connections (c), such that 
 * c = max( Pm , Px ) where Pm-> population of city m and Px -> pop. of
 * city x.
 * length of wire required = c*dist between two cities.
 * Compute the total wire required. If wire required > 10000000007 then
 * output = output / 10000000007
 */

#define MAX_CITIES 20
#define MAX_LOC 1
#define MAX_POPULATION 2
int c_p[MAX_CITIES][MAX_POPULATION] = { 0 } ; /* city, population, co-ord */

typedef struct _conn {
	int city ;
	int nbr[MAX_CITIES] ; /* Max of population, distance */
	int dist[MAX_CITIES] ; /* Max of population, distance */
	int max_pop[MAX_CITIES] ;
	int wire_reqd[MAX_CITIES] ;
	int visited ;
}conn;

int visited[MAX_CITIES] = {0};

conn graph[MAX_CITIES] ;

int main(void)
{
	int n_cities = 0;
	int i=0;
	int city_id = 0;
	int pop = 0 ;
	int co_ord = 0 ;
	scanf ( "%d", &n_cities );
	for ( i=0 ; i< n_cities ; i++ ){
		scanf("%d", &city_id ); 
		c_p[i][0] = city_id ;
		//printf ( " Added City ID %d to city_id[%d][0] %d \n", city_id,i, c_p[i][0]  );
	}
	for ( i=0 ; i< n_cities ; i++ ){
		scanf("%d", &pop ); 
		c_p[i][1] = pop ;
		//printf ( " i=%d c_p[%d][0]= %d, c_p[%d][1] = %d \n",i,i, c_p[i][0], i, c_p[i][1]);
	}
	// print_graph(); 
	build_graph(n_cities);
	visit(n_cities);

}

build_graph( int count)
{
	int n = 0 ;
	for ( n = 0 ; n < count ; n++ ){
		int j = 0 ;
		graph[n].city = c_p[n][0] ;
		printf ( "City : %d \n", graph[n].city );
		for ( j = 0 ; j < count ; j++ ){
			if ( j == n ) continue ;
				
			graph[n].nbr[j] = c_p[j][0] ;
			
			if ( c_p[n][0] > c_p[j][0] ){
				graph[n].dist[j] = ( c_p[n][0] - c_p[j][0] );
			} else {
				graph[n].dist[j] = ( c_p[j][0] - c_p[n][0] );
			}

			if ( c_p[n][1] > c_p[j][1] ){
				graph[n].max_pop[j] =  c_p[n][1] ;
			} else {
				graph[n].max_pop[j] =  c_p[j][1] ;
			}
			graph[n].wire_reqd[j] = graph[n].dist[j] * graph[n].max_pop[j] ;

			printf ("\tNeighbour : %d , distance = %d , max_pop = %d wire_len = %d \n", 
				graph[n].nbr[j], graph[n].dist[j] , graph[n].max_pop[j], 
				graph[n].wire_reqd[j]);
			
		}
	}
}
print_graph()
{
	int i = 0 ;
	for ( i=0 ; c_p[i][0] != 0 ; i++ ){
		printf ( " i = %d , c_p[i][0]=%d, c_p[i][1]=%d  \n", i, c_p[i][0] , c_p[i][1] ); 
	}
}
visit(int count) 
{
	long long  total_len = 0 ;
	int i = 0;
	int j = 0 ;
	for ( i = 0 ; i < count ; i++ )
	{
		for ( j = 0 ; j < count ; j++ ){
			if ( i == j || graph[j].visited == 1 ) {
				continue ;
			} else {
				total_len += graph[i].wire_reqd[j] ;
			}
		}
		graph[i].visited = 1 ;
	}
	total_len = total_len % 1000000007 ;
	printf ("Total length required = %llu\n", total_len) ;
}
