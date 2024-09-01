#include <stdio.h>
#include <stdlib.h>

#define MAX 100


struct queue {
	int Arr[MAX]; //fiexed length queue
	int front;
	int rear;

};


struct queue * create_empty_queue(){
	struct queue * q = (struct queue *) malloc (sizeof(struct queue));
	q->front = -1;
	q->rear = -1;
	return q;

}



//return 1 if is_empty queue else return 0
int is_empty(struct queue * q){
	int front = q->front;
	int rear = q->rear;
	if ( front == -1 && rear == -1){
		return 1;
	}
	return 0; 
}

int is_full(struct queue *q){
	//if real is equal to MAX-1 means all index is occuiped and queue is full
	//then return 1 else return 0
	if (q->rear == MAX-1) {
		return 1;
	}
	return 0;
}



//enque the data
void enqueue(struct queue * q, int data){
	if ( is_full(q)){
		printf("queue is filled full more elements cant inserted now");
		return;
	}
	else if(is_empty(q)){
		q->front = 0;
		q->rear = 0;
		q->Arr[q->rear] = data;
	}
		else{
		q->front = 0;
		q->rear++;
		q->Arr[q->rear] = data;
	}
}

void print_queue(struct queue * q){
	//int Arr[MAX] = q->Arr[MAX]; //get array of queue direct intilization is not possible in c
	//we can use pointer to 
	int i =0;
	while (i <= q->rear){ //if we use MaX IT WILL print all max index instead we can use rear 
		printf("index %d and data is %d\n", i,q->Arr[i]); //either use directly or
		i++;
	}
}


void main(){
	struct queue * q = create_empty_queue();
	enqueue(q,20);
	enqueue(q,30);
	enqueue(q,40);
	print_queue(q);

}



