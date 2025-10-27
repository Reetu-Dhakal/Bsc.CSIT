//to evaluate prefis expression
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define MAX 500
int stack[MAX];
int top = -1;
void push(int value) {
stack[++top] = value;
}
int pop() {
return stack[top--];
}
int evaluatePrefix(char* prefix) {
int i, op1, op2;
for (i = strlen(prefix) - 1; i >= 0; i--) {
char c = prefix[i];
if (isdigit(c)) {
push(c - '0');
} else {
op1 = pop();
op2 = pop();
switch (c) {
case '+': push(op1 + op2); break;
case '-': push(op1 - op2); break;
case '*': push(op1 * op2); break;
case '/': push(op1 / op2); break;
case '^': push(pow(op1, op2)); break;
case '$': push(op1 % op2); break;
}
}
}
return pop();
}
int main() {
char prefix[MAX];
printf("Enter prefix expression: ");
scanf("%s", prefix);
printf("Result: %d\n", evaluatePrefix(prefix));
return 0;
}