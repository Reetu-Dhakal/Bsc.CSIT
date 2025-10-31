#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char str[100], stack[100];
    int top = -1, i, len;
    bool afterC = false;

    printf("Enter a string of the form W C W^R (binary string with C): ");
    scanf("%s", str);
    len = strlen(str);

    printf("\n==== PDA Simulation for W C W^R ====\n");
    printf("Step-by-step processing:\n");

    for (i = 0; i < len; i++) {
        char ch = str[i];

        printf("Input %c | Stack: ", ch);
        for (int j = 0; j <= top; j++)
            printf("%c", stack[j]);

        if (!afterC) {
            if (ch == '0' || ch == '1') {
                stack[++top] = ch; // push onto stack
                printf(" -> Push %c\n", ch);
            } else if (ch == 'C') {
                afterC = true; // start popping
                printf(" -> Found C, switch to matching W^R\n");
            } else {
                printf(" -> Invalid character\n");
                break;
            }
        } else { // after C, match W^R
            if (top == -1) {
                printf(" -> Stack empty, extra symbols\n");
                break;
            }
            if (ch == stack[top]) {
                top--; // pop and match
                printf(" -> Match %c, pop\n", ch);
            } else {
                printf(" -> Mismatch with stack top %c\n", stack[top]);
                break;
            }
        }
    }

    // Acceptance: stack must be empty after matching
    if (afterC && top == -1 && i == len)
        printf("\nPDA Result: Accepted (String is W C W^R)\n");
    else
        printf("\nPDA Result: Rejected \n");

    return 0;
}
