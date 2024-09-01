#ifndef LIST_H
#define LIST_H

//define a struct with one int type & another self reference 


struct node {
	int data;
	struct node * next ;

};


struct node * init_node(int data); //constructor 
int  length(struct ** head); //get length of linked_list







#endif
