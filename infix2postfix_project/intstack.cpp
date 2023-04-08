#include<stdio.h>
#include<stdlib.h>

typedef struct{
    float *ar;
    int top;
    int size;
}istack;

istack * istack_intialize(int size){
    istack *s=(istack *)malloc(sizeof(istack));
    s->ar=(float *)malloc(sizeof(float )*size);
    s->top=0;
    s->size=size;
    return s;
}

bool is_empty(istack *s){
    if(s->top == 0) return true;
    else return false;
}

bool is_full(istack *s){
    if(s->top == s->size) return true;
    else return false;
}

void push(istack *s,float value){
    if(!is_full(s)){
        s->ar[s->top++]=value;
    }
    else
        printf("Stack overflow,Can't push\n");
}

float pop(istack *s){
    if(!is_empty(s)){
        s->top--;
        return s->ar[s->top];
    }
    printf("Stack is already empty\n");
    return '\0';
}
float  peek(istack *s){
    if(!is_empty(s))
        return s->ar[s->top-1];
    printf("Stack is already empty\n");
    return '\0';
}