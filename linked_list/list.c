#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
};



struct node * get_last_node(struct node ** head ){
	//getting last item of linked_list;
	struct node * current = (*head);
	while(current->next != NULL){
		current = current->next;		
	}
	return current;

}

int length(struct node ** head){
	struct node * current = *head;
	int count = 0;
	while(current != NULL){
		current = current->next;
		count++;
	}
	return count;

}


void  remove_first(struct node **head){
	struct node * current = *head;
	struct node * temp_node = current->next;
	free(current);
	*head = temp_node;

}


struct node * second_last(struct node ** head){
	struct node * current = * head;
	while(current->next->next != NULL)
	{
	current = current->next;
	}
	return current;
}
void remove_last(struct node ** head){
	struct node * current = *head;
	while(current->next->next !=NULL){
	current = current->next;
	}
	free(current->next);
	current->next = NULL;

}

struct node * get_nth_node(struct node ** head, int n){
	struct node * current = *head;
	int i;
	if (n >= length(head)){
		printf("index is out of bound of length\n");
	exit(1);
	}
	if (n ==0){
		return current;
	}
	for(i=0; i <= n-1; i++){
		current = current->next;
	}
	return current;

}


struct node *  remove_n_minus_one_node(struct node **head , int n ){
	struct node * current = *head;
	int i;
	if (n>= length(head)){
		printf("index is out of length");
		exit(1);
	}
	if (n ==0){
		printf("this case n-1 means 0-1 index = -1 not supported");	}

	if (n==1){
		return current;

	}
	for(i = 0; i <=n-2; i++){

		current = current->next;
	}


}



void pushFront( struct node ** head, int data){
	struct node * newnode = (struct node *) malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = *head;
	*head = newnode;

}



void pushBack(struct node ** head, int data){
	struct node * current = *head;
	while(current->next != NULL){
		current = current->next;
		
	} //accessing last node of linked_list
	struct node * newnode = (struct node *) malloc(sizeof(struct node));
	newnode->data = data;
	current->next = newnode;
	newnode->next = NULL;

}



void print_linked_list(struct node ** head){
	 struct node  * current = *head;
	 while(current != NULL){
		printf("%d\n",current->data);
		current = current->next;
	 }

}


int main(){
	struct node * head = NULL;
//	printf("%d\n",get_nth_node(&head, 0)->data);
	pushFront(&head,1);
	pushFront(&head,2);
	//print_linked_list(&head);
	//printf("__________");
	int data = get_last_node(&head)->data;	
	printf("last node ---> %d\n", data);
	pushFront(&head,3);
	pushFront(&head,4);
	pushFront(&head, 5);
	pushFront(&head, 6);
	int l = length(&head);
	printf("length ---> %d\n", l); //length 3
	printf("index %d ---> %d\n",0 ,get_nth_node(&head, 0)->data);
	printf("index %d --->%d\n" ,1,get_nth_node(&head, 1)->data);
	printf("index %d --->%d\n" ,2,get_nth_node(&head, 2)->data);

	//get_nth_node(&head,3);
	pushBack(&head,0);
	print_linked_list(&head);
	remove_first(&head);
	printf("______________\n");
	print_linked_list(&head);
	struct node * nd = second_last(&head);
	printf("______________second last --> %d\n", nd->data);
	remove_last(&head);
	print_linked_list(&head);
	printf("index %d-1 ---->%d\n", 1,remove_n_minus_one_node(&head,1)->data);
}
