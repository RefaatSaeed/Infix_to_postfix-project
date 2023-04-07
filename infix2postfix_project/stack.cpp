#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char *ar;
    int top;
    int size;
}stack;

stack * intialize(int size){
    stack *s=(stack *)malloc(sizeof(stack));
    s->ar=(char *)malloc(sizeof(char)*size);
    s->top=0;
    s->size=size;
    return s;
}

bool is_empty(stack *s){
    if(s->top == 0) return true;
    else return false;
}

bool is_full(stack *s){
    if(s->top == s->size) return true;
    else return false;
}

void push(stack *s,char value){
    if(!is_full(s)){
        s->ar[s->top++]=value;
    }
    else
        printf("Stack overflow,Can't push\n");
}

char pop(stack *s){
    if(!is_empty(s)){
        s->top--;
        return s->ar[s->top];
    }
    printf("Stack is already empty\n");
    return '\0';
}

char peek(stack *s){
    if(!is_empty(s))
        return s->ar[s->top-1];
    printf("Stack is already empty\n");
    return '\0';
}

void print_stack(stack s){
    printf("elements in the stack: \n");
    for(int i=0;i<s.top;i++){
        printf("%c",s.ar[i]);
    }
    printf("\n");
}






