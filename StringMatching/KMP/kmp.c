#include <stdio.h>
// #include <string.h>

void createPi(char pat[], int pi[], int m) {
    int piVal = 0;
    pi[0] = 0;
    
    int i = 1;
    while(i < m) {
        if(pi[i] == pi[piVal]) {
            piVal++;
            pi[i] = piVal;
            i++;
        }
        else{
            if(piVal != 0) {
                piVal = pi[piVal - 1];
            }
            else {
                pi[i] = 0;
                i++;
            }
        }
    }

}

void KMPSearch(char pat[], char txt[], int n, int m) {

    int pi[m];
    createPi(pat, pi, m);

    int i = 0, q = 0;
    while(i < n) {
        if(q == m) {
            printf("\nPattern found!\n");
            return;
        }

        if(txt[i] == pat[q]) {
            i++;
            q++;
        }
        else {
            if(q == 0) {
                i++;
            }
            else {
                q = pi[q];
            }
        }
    }

}

int main() {
    printf("Hello");

    char txt[] = "ABABCABCABABABD";
    char pat[] = "ABABD";
    int n = 15;
    int m = 5;
    // int n = strlen(txt);

    KMPSearch(pat, txt, n, m);

    return 0;
}