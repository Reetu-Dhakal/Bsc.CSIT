#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int len, i, j, k;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    printf("\n--- Prefixes ---\n");
    for (i = 1; i <= len; i++) {
        for (j = 0; j < i; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }

    printf("\n--- Suffixes ---\n");
    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }

    printf("\n--- Substrings ---\n");
    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            for (k = i; k <= j; k++) {
                printf("%c", str[k]);
            }
            printf("\n");
        }
    }

    return 0;
}
