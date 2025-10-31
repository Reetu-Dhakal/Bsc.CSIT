#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char stack[100];
    int top = -1;

    printf("Enter a binary string: ");
    scanf("%s", str);
    int n = strlen(str);

    int i = 0;

    printf("\nStep  Input  Stack Top  Action\n");
    printf("----------------------------------\n");

    // Phase 1: Push W
    for(i = 0; i < n/2; i++) {
        char ch = str[i];
        stack[++top] = ch;
        printf("%-5d %-6c %-10c Push\n", i+1, ch, ch);
    }

    // Phase 2: Pop W^R
    for(int j = i; j < n; j++) {
        char ch = str[j];
        char topStack = (top >= 0) ? stack[top] : ' ';
        if(topStack == ch) {
            printf("%-5d %-6c %-10c Pop\n", j+1, ch, topStack);
            top--;
        } else {
            printf("%-5d %-6c %-10c Mismatch! Reject\n", j+1, ch, topStack);
            printf("\nRejected: Not of form W W^R\n");
            return 0;
        }
    }

    if(top == -1) {
        printf("\nAccepted: String is of form W W^R\n");
    } else {
        printf("\nRejected: Stack not empty\n");
    }

    return 0;
}
