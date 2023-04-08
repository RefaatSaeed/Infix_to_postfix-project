#include<stdio.h>
#include<stdlib.h>
#include "header.h"
#include<string.h>



int main(){
    char choice;stack *s=NULL;
    char item_pushed;
    char infix[100];

    char* postfix=(char *)malloc(sizeof(char)*100);
    postfix[0]=NULL;
    while (true){
        print_menu();
        scanf_s(" %c",&choice);
        switch(choice){

            case '1':
                int size;
                printf("Enter size of stack: ");
                scanf_s("%d",&size);
                s=intialize(size);
                printf("Stack 's' created successfully\n");
                break;
            case '2':
                if(s){
                    printf("Enter element to push: ");
                    scanf_s(" %c",&item_pushed);
                    push(s,item_pushed);
                }
                else
                    printf("Please create a stack first\n");
                break;
            case '3':
                if(s)
                    pop(s);
                else
                    printf("Please create a stack first\n");
                break;
            case '4':
                if(s)
                    print_stack(s);
                else
                    printf("Please create a stack first\n");
                break;
            case '5':
                printf("Enter infix expression: ");
                scanf_s("%s",infix);
                postfix=infix_to_postfix(infix,strlen(infix));
                break;
            case '6':
                printf("%.3f\n", postfix_evaluation(postfix));
                break;
            case '7':
                if(postfix)
                    printf("Postfix exp: %s\n",postfix);
                else
                    printf("Enter the infix exp first\n");
                break;
            case '0':
                printf("See you later\n");
                exit(0);
        }




    }
}


void print_menu(){
        printf("\nMenu:\n");
        printf("1. Create a Stack\n");
        printf("2. Push an element in the  Stack\n");
        printf("3. Pop an element from the stack\n");
        printf("4. Print the stack\n");
        printf("5. Infix to Postfix\n");
        printf("6. Evaluation of a postfix expression\n");
        printf("7. print the postfix expression\n");
        printf("0. Exit Program\n");
        printf("\nEnter your choice: ");
}

