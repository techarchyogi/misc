#include "dslib.h"

Node * insert( Node *root, int value )
{
	Node *t = NULL ;
	if(root==NULL){
		Node *r = (Node *)malloc(sizeof(Node));
		r->left = r->right = NULL ;
		r->data = value; 
		return r;
	}
	t=root ;
	while(1){
		if (t->data > value){
			if (t->left) 
				t=t->left;
			else {
				t->left = insert(NULL, value);
				break;
			}	
		} else {
			if(t->right)
				t=t->right;
			else {
				t->right = insert(NULL, value);
				break ;
			}
		}
	}
	return NULL;
}
int delete( Node *root, int value )
{
	return 0;
}

int print(Node * root)
{
	if( root == NULL )return 0;
	if (root->left )print(root->left);
	printf(" %d", root->data );
	if( root->right ) print(root->right);
	return 0;
}

//Insert a value as an arbitrary child
// Follows the string. If the string ends, then it will follow the leftward 
// path till a node is added
// eg rllr, rrr, rl, lr
int insert_arbit( Node * root, char *loc, int val)
{
	Node *t = root ;
	int i = 0;
	int len = strlen(loc);
	if (root == NULL || loc== NULL ) return -1 ;
	printf("len= %d\n",len);
	for ( i=0; i<len && t ; i++ )
	{
		if(loc[i] == 'r' && t->right ){
			printf("Moving RIGHT .. t->data = %d\n", t->data);
			t=t->right;
			printf("Moved RIGHT .. t->data = %d\n", t->data);
		} else if (loc[i] == 'l' && t->left ){
			printf("Moving LEFT .. t->data = %d\n", t->data);
			t=t->left;
			printf("Moved LEFT .. t->data = %d\n", t->data);
		} else if( t->left==NULL || t->right == NULL ) {
		    if(loc[i] == 'r')t->right = insert(NULL, val);
			else if (loc[i] == 'l')t->left = insert(NULL, val);
			printf("inserted value .... Breaking... i = %d\n",i);
			break;
		}
	}
	printf("Out of the for loop, i = %d\n",i);
/*	if ( i == len ) {
		if(loc[i] == 'r'){
			printf("inserted to Right.. t->data = %d, value = %d\n",t->data, val);
			t->right = insert(NULL, val);
		} else if (loc[i] == 'l'){
			printf("inserted to LEFT.. t->data = %d, value = %d\n",t->data, val);
			t->left = insert(NULL, val);
		}
		
	} else {
		while(t->left != NULL) t=t->left ;
		t->left = insert(NULL, val);
	}	
*/
}
/*******************************
int is_valid_base( Node *r)
{
	int rv = -1 ;
	if ( ( 0 == is_valid(r->left, 0, 0, 1) ) ||
	     ( 0 == is_valid(r->right, 0, 0, 2) )){
		 printf("VIOLATED !!!!!!\n");
		 rv = 0;
	} else {
		 printf("VALIDDDDDDDDDD !!!!!!\n");
		 rv = 1;
	}

	return rv;	 
}
/*******1 --> left child, 2 --> right child.
int is_valid( Node * root, int max, int min, int dir )
{
	if(root == NULL )return 1;
	
	printf("%d %s %p max: %d min: %d dir: %d\n",__LINE__, __func__, root,max, min, dir );
	if(root->left){
		max = root->data;
		printf("set max : %d\n", max);
		is_valid( root->left, max, min,1 ); 
	}

    if( (dir == 1 && root->data > max) || (dir ==2 && root->data < min)){
		printf("%d %s violated :: max: %d min: %d data: %d\n",__LINE__, __func__, 
		    max, min, root->data);
		return 0;
	}
	if(root->right){
		min = root->data;
		printf("set min : %d\n", min);
		is_valid( root->right, max, min,2);
	}
	return 1;
}

****/
int is_valid( Node *curr, Node *dad, Node *gdad )
{
	int valid = 0;
	if ( curr == NULL ) return 1;
	if(gdad == NULL && dad == NULL ){
		// root Node...
		valid = is_valid(curr->left, curr, NULL);
		if(valid == 0) return 0;
		valid = is_valid(curr->right, curr, NULL);
	} else if ( gdad == NULL && dad != NULL ){
		// node following the root node.
		valid = is_valid(curr->left, curr, dad);
		if(valid == 0) return 0;
		valid = is_valid(curr->right, curr, dad);
	} else {
		//regular node.
		
		valid = is_valid( curr->left, curr, dad );
		if(valid == 0) return 0;

		//visit self.
		if ( dad == gdad->left ){
			if ( curr == dad->right ){
				if(( dad->data < curr->data ) && (curr->data < gdad->data )) valid = 1;
				else valid = 0;
				printf("%d %s dad-LC, curr-RC gdad->data %d dad->data %d curr->data \
				       %d valid %d \n",__LINE__, __func__, gdad->data, dad->data, 
					   curr->data, valid);
			} else if ( curr == dad->left ) {
				if((curr->data < dad->data) && (dad->data < gdad->data )) valid = 1;
				else valid = 0;
				printf("%d %s dad-LC, curr-LC gdad->data %d dad->data %d curr->data \
				       %d valid %d \n",__LINE__, __func__, gdad->data, dad->data, 
					   curr->data, valid);
			}
		} else if ( dad == gdad->right ){
			if ( curr == dad->right ){
				if((curr->data > dad->data) && (dad->data > gdad->data )) valid = 1;
				else valid = 0;
				printf("%d %s dad-RC, curr-RC gdad->data %d dad->data %d curr->data \
				       %d valid %d \n",__LINE__, __func__, gdad->data, dad->data, 
					   curr->data, valid);
			} else if ( curr == dad->left ) {
				if( (gdad->data < curr->data ) && (curr->data < dad->data)) valid = 1;
				else valid = 0;
				printf("%d %s dad-RC, curr-LC gdad->data %d dad->data %d curr->data \
				       %d valid %d \n",__LINE__, __func__, gdad->data, dad->data, 
					   curr->data, valid);
			}
		}
		if (valid != 0)
			valid = is_valid( curr->right, curr, dad);
	}
	return valid;

}

/*
int main(void)
{
	Node *root = NULL ;
	int n = 0;
	int val = 0;
	int i = 0;

	scanf("%d",&n);

	for (i=0 ; i<n ; i++){
		scanf("%d",&val);
		if (root==NULL) root = insert ( root, val );
		else insert(root, val);
		//print(root);
	}
	printf("\n");
	print(root);
	printf("\n");
	return 0;
}
*/
