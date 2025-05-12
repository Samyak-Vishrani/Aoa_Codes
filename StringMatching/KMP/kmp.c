#include <stdio.h>
// #include <string.h>

void createPi(char pat[], int pi[], int m) {
    int piVal = 1;
    pi[0] = 0;
    pi[1] = 0;
    
    int i = 2;
    while(i < m + 1) {
        if(pat[i] == pat[piVal]) {
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

    for(int i = 0; i < m + 1; i++) {
        printf("%d\t", pi[i]);
    }

}

void KMPSearch(char pat[], char txt[], int n, int m) {

    int pi[m + 1];
    createPi(pat, pi, m);

    int i = 0, q = 0;
    while(i < n) {
        if(q == m) {
            printf("\nPattern found!\n");
            return;
        }

        if(txt[i] == pat[q - 1]) {
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
    printf("\nPattern not found\n");

}

int main() {
    char txt[] = "ABABCABCABABABD";
    char pat[] = "ABABD";
    int n = 15;
    int m = 5;
    // int n = strlen(txt);

    KMPSearch(pat, txt, n, m);

    return 0;
}