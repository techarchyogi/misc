#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _tn{
	void *data ;
	struct _tn *l, *r ;
} node ;

node * insert( node *root, node *curr, void *data, int (*cmp)(void *, void *) );
void *inorder( node *n, void (*prnt) (void *d));
