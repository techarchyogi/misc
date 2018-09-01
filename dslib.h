#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node {
	struct _node *right, *left ;
	int data ;
}Node;
Node * insert( Node *root, int value );
int delete( Node *root, int value );
int print(Node * root);
int insert_arbit( Node *, char *, int );
/*
int is_valid(Node *, int, int, int );
int is_valid_base(Node *);
*/
int is_valid ( Node *, Node *, Node *);
