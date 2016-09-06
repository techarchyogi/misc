#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct link {
	int val ;
	struct link * next ;
}List ;

List * new_node ( int v )
{
	List * tmp = (List *)malloc ( sizeof ( List) );
	tmp->val = v ;
	tmp->next = NULL ;
	return tmp ;
}
print( List * head )
{
	List *tmp = NULL ;
	for ( tmp = head ; tmp != NULL ; tmp = tmp->next ){
		printf ( "%d ", tmp->val );
	}
	printf("\n");

}
List * rev ( List * head )
{
	List * tmp  = NULL ;
	List * curr = head ;
	List * prev = NULL ;
    	while ( curr )
	{
	    	tmp = curr-> next ;
		curr->next  = prev ;
		prev = curr ;
		curr = tmp ;
	}
    print(prev) ;
	return prev ;
}
int main ( void )
{
    int val = 0 ;
	// build a list
	List * curr = NULL  ;
	List * head = NULL ;
	List * tmp = NULL ;
	while ( 1 ) 
	{
		scanf("%d", &val );
		if ( val == -1 ) break ;
		if ( head == NULL ){
			head = new_node (val);
			curr = head ;
		} else {
			// printf ("Updating next \n");
			curr->next = new_node ( val );
			curr = curr->next ;
		}
		// print ( head );
	}
	//print ( head );
    rev ( head );
}

