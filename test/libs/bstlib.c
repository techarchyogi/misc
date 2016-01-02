#include "bstlib.h"

/*
 * assumed that fp returns 1 if the data in curr node is lt the val to be inserted.
 * and returns 1 if key found and 0 if the data in curr node is gt val to be ins.
 */

node * insert ( node *root, node *curr, void *data, int (*fp)(void *, void *))
{
	node *n = NULL ;
	printf ("Inserting \n" );
	if ( NULL == curr ){
		curr = (node *) malloc ( sizeof (node) );
		curr->l = curr->r = NULL ;
		curr->data = data ;
		return curr ;
	} else if ( fp(data, curr->data) == 1 ){
		printf ("Go right \n");
		n = insert ( root, curr->r, data, fp) ;
		if ( curr->r == NULL ) curr->r = n ;
	} else if ( fp(data, curr->data) == 0 ){
		printf ("Go left \n");
		n = insert ( root, curr->l, data, fp );
		if ( curr->l == NULL ) curr->l = n ;
	} 
}

void *inorder( node *n, void (*prnt) (void *d))
{
	if(n==NULL)return ;
	inorder(n->l,prnt);
	prnt ( n->data);
	inorder (n->r, prnt); 
}
