#include "bstlib.h"

int cmp(void *d1, void *d2)
{
	int *i1 = (int *) d1 ;
	int *i2 = (int *) d2 ;
	//printf ( "Cpmparing %d %d \n", *i1, *i2 );
	return ( *i1 > *i2 ) ;
}
void prnt(void *d)
{
//	printf ("printing \n" );
	int *ip = (int *)d;
	printf ("%d ",*ip);
	return ;
}
int main(void)
{
	node *r = NULL ;
	node *n = NULL ;
	while ( 1 ) 
	{
		int * dp = malloc(sizeof (int));
		scanf("%d", dp ); 
		n = insert ( r, r, (void *)dp, &cmp );
		if ( r == NULL ) r = n;
		inorder ( r, &prnt );
		printf("\n");
	}
}
