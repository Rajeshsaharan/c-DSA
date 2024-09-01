#include<stdio.h>
#define MAX 101

struct stack {
    int array[MAX];
    int top;
};

struct stack * create_empty_stack(){
    struct stack * st = (struct stack *) malloc (sizeof(struct stack));
    st->top = -1;
    return st;

}

void print_stack(struct stack * st){
    int i;
    int * arr = st->array;
    for (i = 0; i <= st->top ; i ++){
        printf("%d\n", arr[i]);
    }

}

void push (struct stack * st, int value){
    if (st->top == MAX-1){
        printf("stack is overflowed");
        return;
    }
    st->top++;
    st->array[st->top] = value;
}

void pop(struct stack * st){
    if (st->top == -1){ 
        printf("stack is already empty");
        return;
    }
    st->top--;

}

int isempty(


int main()

{
    struct stack*  st = create_empty_stack();
    printf("Hello world!");
    printf("%d\n", st->top);
    print_stack(st);
    push(st, 2);
    push(st, 3);
    print_stack(st);
    pop(st);
    print_stack(st);
    pop(st);
    pop(st);
    return 0;
}