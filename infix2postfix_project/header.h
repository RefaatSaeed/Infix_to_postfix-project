//
// Created by refaa on 4/7/2023.
//

#ifndef INFIX2POSTFIX_PROJECT_HEADER_H
#define INFIX2POSTFIX_PROJECT_HEADER_H
//main.cpp
void print_menu();

//stack.cpp
typedef struct {

}stack;

stack *intialize(int size);
bool is_empty(stack *s);
bool is_full(stack *s);
void push(stack *s,char value);
char pop(stack *s);
char peek(stack *s);
void print_stack(stack *s);

//istack.cpp
typedef struct{

}istack;
bool is_empty(istack *s);
bool is_full(istack *s);
istack * istack_intialize(int size);
void push(istack *s,float value);
float pop(istack *s);
float  peek(istack *s);


//infix_to_postfix.cpp
bool is_operator(char c);
int precedence(char c);
float calc(int op1,int op2,int c);

char * infix_to_postfix(char exp[],int length);
float postfix_evaluation(char exp[]);

#endif //INFIX2POSTFIX_PROJECT_HEADER_H
