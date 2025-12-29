#include <stdio.h>

int main(void){   
    // thing
    /* other thing*/
    int a;
    char op;
    int b;
    int c;
    // I think code like this is why rust in stuff are a thing
    printf("type in a number:\n");
    scanf("%d" "%c" "%d", &a, &op, &b);
    printf("%d" "%c" "%d" , a, op, b);
    printf("\n");

    if(op == '+'){
        c = a+b;
    }else if(op == '-'){
        c=a-b;
    }else if (op == '*') {
        c=a*b;
    }else if (op == '/') {
        c= a/b;
    }else{
        printf("opporator/whitespace not suported \n");
        c = -1;
    }
     printf("%d",c);
     printf("\n");

   


}