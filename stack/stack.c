#include <stdio.h>
#include <stdlib.h>
//program to stack implements 

//node for linked list
struct node {
	int data;
	struct node * next;

};

//struct for stack
struct stack {
	struct node * top;
};



//init for create empty stack
struct stack * create_empty_stack(void){
	struct stack * st = (struct stack *)malloc(sizeof(struct stack));
	st->top = NULL;
	return st;
};


//push using linked_list on stack
void push(struct stack * st, int  data){
	struct node * nd = (struct node *)malloc (sizeof(struct node));
	nd->data = data;
	if (st->top == NULL) {
	st->top = nd;
	nd->next = NULL;
	}else{
		nd->next = st->top;
		st->top = nd;
	}


}

void print_stack(struct stack * st){
	struct node * top = st->top;
	while(top != NULL){
	printf("%d\n", top->data);
	top = top->next;

	}

}



void main(){
	struct stack * st = create_empty_stack();
	push(st,3);
	push(st,4);
	push(st,5);
	printf("%d",st->top->data);
	print_stack(st);

}
