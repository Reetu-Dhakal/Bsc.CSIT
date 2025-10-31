#include <stdio.h>
#include <string.h>

int check_aSb(char str[], int start, int end, int step) {
    int i;
    // Print current substring
    printf("Step %-3d  Checking substring: ", step);
    for (i = start; i <= end; i++)
        printf("%c", str[i]);
    printf("\n");

    int length = end - start + 1;

    // Base case: exactly "ab"
    if (length == 2) {
        if (str[start] == 'a' && str[end] == 'b') {
            printf("Step %-3d  Matched rule: S -> ab\n", step);
            return 1;
        } else {
            printf("Step %-3d  Invalid base case (not 'ab')\n", step);
            return 0;
        }
    }

    // Invalid case: length < 2 or wrong characters
    if (length < 2 || str[start] != 'a' || str[end] != 'b') {
        printf("Step %-3d  Rejected: does not start with 'a' or end with 'b'\n", step);
        return 0;
    }

    // Recursive case: apply S -> aSb
    printf("Step %-3d  Applying rule: S -> aSb\n", step);
    return check_aSb(str, start + 1, end - 1, step + 1);
}

int main() {
    char str[100];
    int len;

    printf("Enter a string of a's followed by b's: ");
    scanf("%s", str);

    len = strlen(str);

    printf("\n==== CFG Simulation (S -> aSb | ab) ====\n");
    printf("Grammar Rules:\nS -> aSb\nS -> ab\n\n");
    printf("Step-by-Step Derivation:\n");

    int result = check_aSb(str, 0, len - 1, 1);

    printf("\nCFG Result: %s\n", result ? "Accepted (Valid a^n b^n)" : "Rejected");

    return 0;
}
