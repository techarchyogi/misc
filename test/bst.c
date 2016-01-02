#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _n{
	int val; 
	struct _n *r, *l ;
}node;
node *root ;
node *insert(node *curr, int val ){
	node *n = NULL ;
	if (curr==NULL){
		curr = malloc ( sizeof (node)); 
		curr->val = val ;
		if ( root == NULL ) { root = curr ; } 
		curr->r = curr->l = NULL ;
		return curr ;
	} else if (val< curr->val) {
		n = insert ( curr->r, val );
		if( !(curr->r))curr->r = n ; 
	} else {
	    n = insert ( curr->l,val );
		if( !(curr->l))curr->l = n ; 
	}
}
void pre( node *n)
{
	if(!n) return ;
	if ( n->r ) pre(n->r) ;
	printf ( "%d ", n->val );
	if ( n->l ) pre(n->l);
}
int search ( node *n, int val )
{
	if ( NULL == n ) return 0;
	if ( val < n->val ) {	
		search ( n->r, val ); 
	} else if ( val > n->val ) {
		search (n->l, val );
	} else { return 1 ; } 
}
int main ( void )
{
	root = NULL ;
	int v= 0;
	char c=0;
	while(EOF != scanf("%c", &c)){
		if ( c == 'p' ){
			pre(root);
		} else if ( c == 'i' ){
			scanf("%d", &v);
			printf("inserting %d\n",v );
			insert ( root, v);
		} else if ( c == 's' ){
			scanf("%d", &v);
			printf ( "Found = %d\n",search(root, v)); 
		}
	}
	pre(root);
}

