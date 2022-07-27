#include<stdio.h>

void add(int a,int b){
    printf("Sum of %d and %d=%d",a,b,a+b);
}


int main()
{
    float a,b;
    char ch;
    printf("Choose operation:'+' '-' '*' '/' \n" );
    scanf("%c",&ch);
    printf("Enter two numbers:\n");
    scanf("%f%f",&a,&b);
    switch(ch){
        case '+':
            add(a,b);
            break;
        
    }
    return 0;
}