#include<stdio.h>
#include<stdlib.h>
#include "header.h"

#include<ctype.h>


bool is_operator(char c){
    if(c=='/' || c=='*' || c=='+' || c=='-')
        return true;
    else return false;
}

int precedence(char c){
    if(c =='-' || c=='+')
        return 1;
    else if(c == '*' || c=='/')
        return 2;
    else if(c == '^')
        return 3;
    else
        return 0;
}

float calc(int op1,int op2,int c){
    switch(c){
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            return (float)op1/op2;
    }
}

char * infix_to_postfix(char exp[],int length){
    stack *s=intialize(length);
    char *postfix=(char *)malloc(sizeof(char)*length*2);

    int k=0;
    for(int i=0;i<length;i++){

        if(exp[i]=='('){
            push(s,exp[i]);
        }
        else if(exp[i]==')'){
            while(peek(s) != '('){
                postfix[k++]=pop(s);
                postfix[k++]=' ';
            }
            pop(s);
        }

        else if(is_operator(exp[i])){
            while(!is_empty(s) && precedence(exp[i])<=precedence(peek(s))){
                postfix[k++]=pop(s);
                postfix[k++]=' ';
            }
            push(s,exp[i]);
        }
        else if(isalnum(exp[i])){
           while(isalnum(exp[i])){
               postfix[k++]=exp[i++];
           }
           postfix[k++]=' ';
           i--;
        }
    }
    while (!is_empty(s)){
        postfix[k++]=pop(s);
    }
    postfix[k]='\0';
    return postfix;
}