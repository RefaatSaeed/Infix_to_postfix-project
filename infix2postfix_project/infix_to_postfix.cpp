#include<stdio.h>
#include<stdlib.h>
#include "header.h"
#include<string.h>
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
            return (float)op1/(op2+0.0);
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
        postfix[k]=' ';
    }
    postfix[k]='\0';
    return postfix;
}

float postfix_evaluation(char exp[]){
    istack *s= istack_intialize(strlen(exp)/2);
    char num[10];int j=0;
    int x;
    int op1,op2;
    float res;
    for(int i=0;i<strlen(exp);i++){
        if(isalnum(exp[i])){
            num[j++]=exp[i];
            num[j]='\0';
        }
        else if(exp[i]==' ' && j>0){
                x=atoi(num);
                push(s,(float)x);
                j=0;
        }
        else if(is_operator(exp[i])){
            op2=pop(s);
            op1=pop(s);
            res=calc(op1,op2,exp[i]);
            push(s,res);
        }
    }
    return pop(s);
}