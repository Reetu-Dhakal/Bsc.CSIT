lab#include <stdio.h>
#include <string.h>

int main() {
    char str[100], stack[100];
    int top = -1, i, len, state = 0;

    printf("Enter a binary string (0^n1^n): ");
    scanf("%s", str);
    len = strlen(str);

    printf("\n==== PDA Simulation for 0^n1^n ====\n");
    printf("Transitions:\n");
    puts("(q0, 0, Z) -> (q0, 0Z)");
    puts("(q0, 0, 0) -> (q0, 00)");
    puts("(q0, 1, 0) -> (q1, e)");
    puts("(q1, 1, 0) -> (q1, e)");
    puts("(q1, e, Z) -> (qf, Z)");

    // Push bottom marker
    stack[++top] = 'Z';

    printf("\nStep-by-step processing:\n");
    for (i = 0; i < len; i++) {
        char ch = str[i];
        char top_sym = stack[top];

        printf("Input %c | State: q%d | Stack top: %c -> ", ch, state, top_sym);

        if (state == 0) {
            if (ch == '0' && top_sym == 'Z') {
                stack[++top] = '0';
                printf("Push 0\n");
            } else if (ch == '0' && top_sym == '0') {
                stack[++top] = '0';
                printf("Push 0\n");
            } else if (ch == '1' && top_sym == '0') {
                top--; // pop
                state = 1;
                printf("Pop 0, move to q1\n");
            } else {
                printf("Invalid transition\n");
                break;
            }
        } else if (state == 1) {
            if (ch == '1' && top_sym == '0') {
                top--; // pop
                printf("Pop 0\n");
            } else {
                printf("Invalid transition\n");
                break;
            }
        }
    }

    // After input, check acceptance
    if (state == 1 && stack[top] == 'Z') {
        printf("\nPDA Result: Accepted (Equal number of 0's and 1's)\n");
    } else {
        printf("\nPDA Result: Rejected \n");
    }

    return 0;
}
