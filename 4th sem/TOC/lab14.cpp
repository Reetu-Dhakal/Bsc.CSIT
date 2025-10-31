#include <stdio.h>
#include <string.h>

int main() {
    char tape[100];
    int n;

    printf("Enter a string over {0,1} (odd-length palindrome): ");
    scanf("%s", tape);
    n = strlen(tape);

    // Reject if length is even
    if(n % 2 == 0) {
        printf(" Rejected: length is even, cannot be odd palindrome\n");
        return 0;
    }

    int left = 0, right = n - 1;
    int step = 1;

    printf("\nStep  Left  Right  Tape Substring  Action\n");
    printf("--------------------------------------------\n");

    while(left < right) {
        printf("%-5d %-5d %-5d ", step++, left, right);
        for(int k=0; k<n; k++) printf("%c", tape[k]);

        if(tape[left] == tape[right]) {
            printf("   Match %c-%c, mark\n", tape[left], tape[right]);
            tape[left] = 'X';  // mark left
            tape[right] = 'X'; // mark right
            left++;
            right--;
        } else {
            printf("   Mismatch %c-%c, Reject\n", tape[left], tape[right]);
            printf("\nRejected: Not an odd palindrome\n");
            return 0;
        }
        printf("\n");
    }

    // The middle symbol is allowed to remain unmarked
    printf("\n? Accepted: Odd-length palindrome\n");
    return 0;
}
