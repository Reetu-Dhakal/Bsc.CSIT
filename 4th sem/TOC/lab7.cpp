#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int len, i;

    printf("Enter a binary string (0s and 1s): ");
    scanf("%s", str);
    len = strlen(str);

    // -------------------- DFA Transition Description --------------------
    printf("\nDFA Transition Table\n");
    printf("Current   Input0   Input1\n");
    printf("q0        q2       q1\n");
    printf("q1        q3       q0\n");
    printf("q2        q0       q3\n");
    printf("q3        q1       q2\n");

    // -------------------- DFA Working Mechanism --------------------
    int dfa_state = 0; // q0 = even0, even1 (accepting)
    printf("\nDFA Working Process\n");
    printf("Step   Input   From   To\n");

    for (i = 0; i < len; i++) {
        char ch = str[i];
        int prev = dfa_state;

        switch (dfa_state) {
            case 0: dfa_state = (ch == '0') ? 2 : 1; break;
            case 1: dfa_state = (ch == '0') ? 3 : 0; break;
            case 2: dfa_state = (ch == '0') ? 0 : 3; break;
            case 3: dfa_state = (ch == '0') ? 1 : 2; break;
        }

        printf("%-6d %-7c q%d     q%d\n", i + 1, ch, prev, dfa_state);
    }

    if (dfa_state == 0)
        printf("DFA Result: Accepted\n");
    else
        printf("DFA Result: Rejected\n");

    // -------------------- NFA Transition Description --------------------
    printf("\nNFA Transition Table\n");
    printf("Current   Input0   Input1\n");
    printf("q0        q2       q1\n");
    printf("q1        q3       q0\n");
    printf("q2        q0       q3\n");
    printf("q3        q1       q2\n");

    // -------------------- NFA Working Mechanism --------------------
    int nfa_curr[4] = {1, 0, 0, 0}; // q0 active initially
    int nfa_next[4];

    printf("\nNFA Working Process\n");
    printf("Step   Input   Active States After Input\n");

    for (i = 0; i < len; i++) {
        char ch = str[i];
        for (int j = 0; j < 4; j++) nfa_next[j] = 0;

        for (int j = 0; j < 4; j++) {
            if (nfa_curr[j]) {
                if (ch == '0') {
                    if (j == 0) nfa_next[2] = 1;
                    else if (j == 1) nfa_next[3] = 1;
                    else if (j == 2) nfa_next[0] = 1;
                    else if (j == 3) nfa_next[1] = 1;
                } else if (ch == '1') {
                    if (j == 0) nfa_next[1] = 1;
                    else if (j == 1) nfa_next[0] = 1;
                    else if (j == 2) nfa_next[3] = 1;
                    else if (j == 3) nfa_next[2] = 1;
                }
            }
        }

        printf("%-6d %-7c {", i + 1, ch);
        for (int j = 0; j < 4; j++) if (nfa_next[j]) printf("q%d ", j);
        printf("}\n");

        for (int j = 0; j < 4; j++) nfa_curr[j] = nfa_next[j];
    }

    if (nfa_curr[0])
        printf("NFA Result: Accepted \n");
    else
        printf("NFA Result: Rejected\n");

    return 0;
}
