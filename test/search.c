/*
 * Solution to a google problem. Gven two strings, return from one string
 * the characters that match the second string. 
 * build a tree of the first string and then search for the other one. 
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _n{
	char k ;
	struct _n *l, *r ; 
	int freq ;
}node ;
node * root ;

node * add( node * curr, char c )
{
	node *n = NULL ;
	if ( curr == NULL ) {
		n = malloc ( sizeof ( node ));
		n->l = n->r = NULL ;
		n->k = c ;
		n->freq = 0 ;
		//printf ("adding new node ..%c..\n", c);
		return n ;
	}  
	
	if ( c < curr->k ) {
		//printf ("go left \n");
		n = add( curr->l, c );
		if ( curr->l == NULL ) {
			curr->l = n ;
			//printf ("Added to left \n");
		}	
	} else if ( c > curr->k  )  {
		//printf ("go right \n");
		n = add( curr->r, c );
		if ( curr->r == NULL ){
			curr->r = n ;
			//printf ("added to right\n");
		}
	} else if ( c == curr->k ) {
		//printf("add duplicate\n");	
		curr->freq ++ ;
	}
}
int find ( node * n, char x )
{
	int found = 0 ;
	if (n == NULL) return found ;
	else if ( n->k == x ) found = 1 ;
	else if ( n->k < x ) {
		found = find( n->r, x );
	} else if ( n->k > x ) {
		found = find ( n->l, x);
	}
	return found ;
}
void build_tree ( char s[] )
{
	int l = strlen ( s ) ;
	int i = 0;
	node *n = NULL ;
	root = NULL;
	for ( i = 0 ; i < l ; i++ ){
		//printf("root == %ux \n", (unsigned int)root ) ; 
		n = add (root, s[i] );
		if ( root == NULL ) {
			root = n ;
			//printf("Added root == %ux \n", (unsigned int)root ) ; 
		}	
			
	}
}
void print_tree (node *n)
{
	//printf("printint tree !!!\n");
	if ( n != NULL ){
		print_tree(n->l);
		printf (" COntent = %c ; freq = %d\n", n->k, n->freq );
		print_tree (n->r);
	}
}
int main ( void )
{
	char s[1000] ;
	char t;
	int found = 0 ;
	scanf("%s", s);
	build_tree(s);
	//print_tree(root);
	while ( scanf("%c",&t) != EOF ){
		if (find ( root, t )) {
			printf("found \n" );
		}
	}

}
