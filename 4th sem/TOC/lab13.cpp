#include <stdio.h>
#include <string.h>

int main() {
    char tape[100];
    int n, head = 0;

    printf("Enter a string over {a,b} (even length palindrome): ");
    scanf("%s", tape);
    n = strlen(tape);

    // Reject immediately if length is odd
    if(n % 2 != 0) {
        printf(" Rejected: length is odd, cannot be even palindrome\n");
        return 0;
    }

    int left = 0, right = n - 1;
    int step = 1;

    printf("\nStep  Left  Right  Tape Substring  Action\n");

    while(left < right) {
        printf("%-5d %-5d %-5d ", step++, left, right);
        for(int k=0; k<n; k++) printf("%c", tape[k]);
        if(tape[left] == tape[right]) {
            printf("   Match %c-%c, mark\n", tape[left], tape[right]);
            tape[left] = 'X'; // mark left
            tape[right] = 'X'; // mark right
            left++;
            right--;
        } else {
            printf(" Mismatch %c-%c, Reject\n", tape[left], tape[right]);
            printf("\n Rejected: Not an even palindrome\n");
            return 0;
        }
        printf("\n");
    }

    printf("\n? Accepted: Even-length palindrome\n");
    return 0;
}
