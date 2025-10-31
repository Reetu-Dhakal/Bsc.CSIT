#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;

    printf("Enter a string (letters a/b only): ");
    scanf("%s", str);
    len = strlen(str);

    /* -------------------- DFA SECTION -------------------- */
    int state = 0; // q0=start, q1=first 'a', q2=accepted, q3=dead
    int q_dead = 3;

    printf("\n==== DFA Simulation ====\n");
    printf("Transition Table:\n");
    puts("q0 -> (a) q1, (b) q3");
    puts("q1 -> (a) q2, (b) q3");
    puts("q2 -> (a) q2, (b) q2");
    puts("q3 -> (a) q3, (b) q3");

    printf("\nStep-by-step processing:\n");
    for (i = 0; i < len; i++) {
        char ch = str[i];
        int prev = state;

        switch (state) {
            case 0: state = (ch == 'a') ? 1 : q_dead; break;
            case 1: state = (ch == 'a') ? 2 : q_dead; break;
            case 2: state = 2; break;
            case 3: state = q_dead; break;
        }

        printf("Input %c: q%d -> q%d\n", ch, prev, state);
    }

    if (state == 2)
        printf("DFA Result: Accepted (string starts with 'aa')\n");
    else
        printf("DFA Result: Rejected\n");


    /* -------------------- NFA SECTION -------------------- */
    int s0 = 1, s1 = 0, s2 = 0; // q0=start, q1=first 'a', q2=accepted

    printf("\n==== NFA Simulation ====\n");
    printf("Transition Table:\n");
    puts("q0 -> (a) q0,q1, (b) q0");
    puts("q1 -> (a) q2");
    puts("q2 -> (a,b) q2");

    printf("\nActive states after each input:\n");

    for (i = 0; i < len; i++) {
        char ch = str[i];
        int ns0 = 0, ns1 = 0, ns2 = 0;

        if (ch == 'a') {
            if (s0) { ns0 = 1; ns1 = 1; }
            if (s1) ns2 = 1;
            if (s2) ns2 = 1;
        } else if (ch == 'b') {
            if (s0) ns0 = 1;
            if (s2) ns2 = 1;
        }

        printf("After input %c -> {", ch);
        if (s0) printf("q0 ");
        if (s1) printf("q1 ");
        if (s2) printf("q2 ");
        printf("}\n");

        s0 = ns0; s1 = ns1; s2 = ns2;
    }

    if (s2)
        printf("NFA Result:Accepted (string starts with 'aa')\n");
    else
        printf("NFA Result:Rejected\n");

    return 0;
}
