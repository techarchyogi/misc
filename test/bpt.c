#include <stdio.h>

#define ORDER 3
typedef struct _node {
	int keys[ORDER-1] ;
	void *data[ORDER-1] ;
	struct _node * children[ORDER] ; /* keys + 1 */
	
} node;
typedef node * pnode ;

pnode root = NULL ;

node* insert( pnode curr, int key )
{
	if ( curr == NULL ) {
		curr = malloc ( sizeof ( node ));
		root->keys[0] = key ;
		return curr;
	} else {
		pnode child = NULL ;
		int i = 0 ;
		for ( i = 0 ; i < ORDER-1 ; i++ ){
			if ( curr->keys[i] > key ) {
				child = curr->children[i] ;
				break ;
			}
		}
		if ( child == NULL && i == ORDER - 1 ){
			insert ( child, key );
		}
	}
	
}
 

int print ( pnode * root )
