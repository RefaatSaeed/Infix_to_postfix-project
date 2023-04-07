#include<stdio.h>

#include "header.h"
#include<string.h>

int main(){
    printf("check\n");
    char infix[]="(300+23)*(43-21)/(84+7)";
    printf("check\n");
    printf("%s\n",infix_to_postfix(infix,strlen(infix)));
    return 0;

}