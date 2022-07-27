#include<stdio.h>

void add(int a,int b){
    printf("Sum of %d and %d=%d",a,b,a+b);
}
void sub(int a,int b){
    printf("subtraction of %d and %d=%d",a,b,a-b);
}
void multi(int a,int b){
    printf("Product of %d and %d=%d",a,b,a*b);
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
        case '-':
            sub(a,b);
            break;
        case '*':
            multi(a,b);
            break;
    }
    return 0;
}