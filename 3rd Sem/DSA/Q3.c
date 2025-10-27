//to convert infix to postfix
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 500
char stack[MAX];
int top = -1;
void push(char c) {
if (top != MAX - 1) stack[++top] = c;
}
char pop() {
return (top == -1) ? '\0' : stack[top--];
}
int precedence(char op) {
if (op == '+' || op == '-') return 1;
if (op == '*' || op == '/') return 2;
if (op == '^'|| op=='$') return 3;
return 0;
}
void infixToPostfix(char* infix, char* postfix) {
int i = 0, j = 0;
char c;
while ((c = infix[i++]) != '\0') {
if (isalnum(c))
    postfix[j++] = c;
else if (c == '(') 
    push(c);
else if (c == ')')
{
    while (top != -1 && stack[top] != '(')
    {
        postfix[j++] = pop();
    }
    pop();
}
else
{
    while (top != -1 && precedence(stack[top]) >= precedence(c)) postfix[j++] = pop();
    push(c);
}
}
while (top != -1) postfix[j++] = pop();
postfix[j] = '\0';
}
int main() {
char infix[MAX], postfix[MAX];
printf("Enter infix expression: ");
scanf("%s", infix);
infixToPostfix(infix, postfix);
printf("Postfix expression: %s\n", postfix);
return 0;
}