#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;

    printf("Enter a binary string: ");
    scanf("%s", str);
    len = strlen(str);

    /* -------------------- DFA -------------------- */
    // States: q0=even0_even1, q1=even0_odd1, q2=odd0_even1, q3=odd0_odd1
    int state = 0;

    printf("\n==== DFA Simulation (Even 0's & Odd 1's) ====\n");
    printf("Transition Table:\n");
    puts("q0 -> 0:q2, 1:q1");
    puts("q1 -> 0:q3, 1:q0");
    puts("q2 -> 0:q0, 1:q3");
    puts("q3 -> 0:q1, 1:q2");

    printf("\nStep-by-step processing:\n");
    for(i=0;i<len;i++){
        char ch = str[i];
        int prev = state;
        switch(state){
            case 0: state = (ch=='0')?2:1; break;
            case 1: state = (ch=='0')?3:0; break;
            case 2: state = (ch=='0')?0:3; break;
            case 3: state = (ch=='0')?1:2; break;
        }
        printf("Input %c: q%d -> q%d\n", ch, prev, state);
    }

    printf("DFA Result: %s\n", (state==1)?"Accepted (even 0's & odd 1's)":"Rejected");


    /* -------------------- NFA -------------------- */
    int s0=1,s1=0,s2=0,s3=0;

    printf("\n==== NFA Simulation ====\n");
    printf("Transition Table:\n");
    puts("q0 -> 0:q2,1:q1");
    puts("q1 -> 0:q3,1:q0");
    puts("q2 -> 0:q0,1:q3");
    puts("q3 -> 0:q1,1:q2");

    printf("\nActive states after each input:\n");
    for(i=0;i<len;i++){
        char ch=str[i];
        int ns0=0,ns1=0,ns2=0,ns3=0;

        if(ch=='0'){
            if(s0) ns2=1;
            if(s1) ns3=1;
            if(s2) ns0=1;
            if(s3) ns1=1;
        } else if(ch=='1'){
            if(s0) ns1=1;
            if(s1) ns0=1;
            if(s2) ns3=1;
            if(s3) ns2=1;
        }

        printf("After input %c -> {", ch);
        if(s0) printf("q0 "); if(s1) printf("q1 "); if(s2) printf("q2 "); if(s3) printf("q3 ");
        printf("}\n");

        s0=ns0; s1=ns1; s2=ns2; s3=ns3;
    }

    printf("NFA Result: %s\n", (s1)?"Accepted (even 0's & odd 1's)":"Rejected");

    return 0;
}
