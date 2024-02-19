#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

int stack[50], top=-1;

void push(char ch) {
    stack[++top] = ch;
}

void main(){
    char postfix[30],ch;
    int i=0,num1,num2;
    printf("Enter a valid postfix expression with Single operator and operand : ");
    scanf("%s",postfix);

    while((ch=postfix[i++])!='\0') {
        if(isalpha(ch)){
            printf("Invalid Expresion\n");
            return;
        }
        else if(isdigit(ch)){
            push(ch-48);
        }
        else{
            num2 = stack[top--];
            if(top<0){
                printf("invalid Expression\n");
                return;
            }
            num1 = stack[top--];

            switch(ch){
            case '+':
                push(num1 + num2);
                break;
            case '-':
                push(num1 - num2);
                break;
            case '*':
                push(num1 * num2);
                break;
            case '/':
                push(num1 / num2);
                break;
            case '%':
                push(num1 % num2);
                break;
            case '^':
                push(pow(num1,num2));
                break;
            default: printf("Invalid Operator\n");
            }
        }
    }
    if(top!=0)
        printf("Invalid Expression\n");
    else
        printf("Result = %d",stack[top]);
}
