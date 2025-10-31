#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    int i,len;

    printf("Enter a decimal number: ");
    scanf("%s",str);
    len=strlen(str);

    /* -------------------- DFA -------------------- */
    // Only last digit matters: q0=even(last digit 0,2,4,6,8), q1=odd(1,3,5,7,9)
    int state=0;

    printf("\n==== DFA Simulation (Divisible by 2) ====\n");
    printf("Transition Table:\n");
    puts("q0 -> even digit:q0, odd digit:q1");
    puts("q1 -> even digit:q0, odd digit:q1");

    printf("\nStep-by-step processing:\n");
    for(i=0;i<len;i++){
        char ch=str[i];
        int prev=state;

        if(ch=='0'||ch=='2'||ch=='4'||ch=='6'||ch=='8') state=0;
        else state=1;

        printf("Input %c: q%d -> q%d\n",ch,prev,state);
    }

    printf("DFA Result: %s\n", (state==0)?"Accepted (divisible by 2)":"Rejected");

    /* -------------------- NFA -------------------- */
    int s0=1,s1=0;

    printf("\n==== NFA Simulation ====\n");
    printf("Transition Table:\n");
    puts("q0 -> even:q0, odd:q1");
    puts("q1 -> even:q0, odd:q1");

    printf("\nActive states after each input:\n");
    for(i=0;i<len;i++){
        char ch=str[i];
        int ns0=0,ns1=0;

        if(ch=='0'||ch=='2'||ch=='4'||ch=='6'||ch=='8'){
            if(s0) ns0=1;
            if(s1) ns0=1;
        } else {
            if(s0) ns1=1;
            if(s1) ns1=1;
        }

        printf("After input %c -> {",ch);
        if(s0) printf("q0 "); if(s1) printf("q1 ");
        printf("}\n");

        s0=ns0; s1=ns1;
    }

    printf("NFA Result: %s\n", (s0)?"Accepted (divisible by 2)":"Rejected");

    return 0;
}
