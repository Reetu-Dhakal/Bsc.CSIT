#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char str[100], stack[100];
    int top = -1, len, i;

    printf("Enter a string of parentheses: ");
    scanf("%s", str);
    len = strlen(str);

    printf("\n==== PDA Simulation for Well-Formed Parentheses ====\n");

    printf("Step-by-step processing:\n");

    for (i = 0; i < len; i++) {
        char ch = str[i];
        printf("Input %c | Stack: ", ch);

        // Display current stack
        for (int j = 0; j <= top; j++) {
            printf("%c", stack[j]);
        }

        if (ch == '(') {
            stack[++top] = '('; // push
            printf(" -> Push (\n");
        } else if (ch == ')') {
            if (top == -1) { // invalid pop
                printf(" -> Pop failed! Unmatched )\n");
                break;
            } else {
                top--; // pop
                printf(" -> Pop (\n");
            }
        } else {
            printf(" -> Invalid character! Only '(' or ')'\n");
            break;
        }
    }

    // Check acceptance
    if (top == -1 && i == len)
        printf("\nPDA Result: Accepted (Well-formed parentheses)\n");
    else
        printf("\nPDA Result: Rejected (Not well-formed)\n");

    return 0;
}
