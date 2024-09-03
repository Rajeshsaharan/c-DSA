#include<stdio.h>
#include <stdlib.h>


//double linked_list
struct node {
     int data;
     struct node * prev;
     struct node * next;

};

//constructor 
struct node * create_linked_list(int data){
    struct node * nd = (struct node *) malloc(sizeof(struct node));
    nd->data = data;
    nd->prev = NULL;
    nd->next = NULL;
    return nd;
}


//length of linked_list

int length(struct node * head){
    struct node *current = head; // getting head
    int count = 0;
    while(current!= NULL){
        current = current->next;
        count++;
    }
    return count;
}

//last node can be also tail getting tail of linked_list
struct node * last_node(struct node * head){
    struct node * current = head;
    //to get last node 
    while(current->next != NULL)
    {
        current = current->next;
    }
    return current;
}
//printing transversal & backward transversal

//transversal forward 
void print_forward(struct node * head) {
    struct node * current = head;
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }

}
//backward transversal 
void print_backword(struct node * head){
    struct node * current = last_node(head); //getting last node
    while(current!= NULL){
        printf("%d\n", current->data);
        current= current->prev;
    
    }

}

//pushing nodes in front of linked list 
void pushFront(struct node ** head, int data){
    struct node * current = *head;
    struct node * nd = (struct node *) malloc(sizeof(struct node));
    nd->prev = NULL;
    (*head)->prev = nd;
    nd->data = data;
    nd->next = *head;
    *head = nd;
}

//pushing nodes in the tail of linked list 

void pushBack(struct node * head, int data){
	//getting second last node of linked_list
	struct node * tail = last_node(head);
	struct node * nd = (struct node *) malloc(sizeof(struct node));
	nd->data = data;
	nd->next = NULL;
	nd->prev = tail->next;
	tail->next = nd;

}

//inserting at a specific location
void insert_at_specific_index(struct node ** head, int index, int data){
		struct node * current = *head; //current position of linked_list
		int i = 0;
		//if index is more than length them simply return
		if (index > length(*head)){
			printf("length of linked list is less than index ");
			return;

		}else if (index == 0){
			struct node * newnode = (struct node *) malloc(sizeof(struct node));
			newnode->data = data;
			newnode->next = *head;
			newnode->prev = NULL;
			(*head)->prev = newnode; 
			*head = newnode;
		}else{
			while(i <= index-2){
				current = current->next;
			}
			struct node * newnode = (struct node *) malloc(sizeof(struct node));
			newnode->data = data;
			newnode->next = current->next;
			newnode->prev = current->prev;
			current->next = newnode;
			current->next->prev = newnode;
}

}

//searching the linked_list 
// if any data found in linked_list return index else return -1; means specific node not found

int search_node(struct node * head, int data){
	int count =0;
	int ln = length(head); //length of linked_list
	struct node * current = head;
	while(current != NULL &&  current->data != data ){ //stop at data found or stop at end of linked_list
		current = current->next;
		count ++;
	}
	if (count == ln){
		return -1;
	}else{
		return count;
	}

}

//searching by index of linked_list 
struct node * search_node_by_index(struct node * head, int index){
		struct node * current = head;
		int i =0;
		if (index ==0){
			return current;
		}
		while(i <= index-1){
		current = current->next;
		i++;
		}
		return current;


}


int main()
{
	//important thing is head is not NULL & at least have 1 length
    struct node * head = create_linked_list(1);
    pushFront(&head,2);
    pushFront(&head,3);
    print_forward(head);
    printf("length of linked_list -> %d\n", length(head));
   // printf("%d", last_node(head)->data);
   struct node * tail = last_node(head);
   printf("last item of list is -> %d\n", tail->data);
   
   print_backword(head);
   printf("index of searched item is -> %d", search_node(head,2));
   printf("index of searched item is -> %d", search_node(head,1));
	  printf("index of non present item is -. %d", search_node(head,4)); 
   pushFront(&head,4);
   printf("after pushing 4 on front of linked_list");
   printf("index of searched item is -> %d", search_node(head, 4));
	pushBack(head, 0);
	print_forward(head);
	printf("geeting index of 2 --> expected 2 and acutal is--->%d",search_node_by_index(head,2)->data);

insert_at_specific_index(&head,1,90);
	print_forward(head);
return 0;
}
