// KMP
#include <stdio.h>
#include <string.h>

void createPi(char pat[], int pi[], int m) {
    int piVal = 0;
    pi[0] = 0;
    
    int i = 1;
    while(i < m) {
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

    for(int i = 0; i < m; i++) {
        printf("%d\t", pi[i]);
    }
}

void KMPSearch(char pat[], char txt[], int n, int m) {

    int pi[m];
    createPi(pat, pi, m);

    int i = 0, q = 0;
    while(i < n) {

        if(pat[q] == txt[i]) {
            i++;
            q++;
        }
        if(q == m) {
            printf("\nPattern found at index %d\n", i - q);
            q = pi[q - 1];
            return;
        }
        else if(i < n && pat[q] != txt[i]){
            if(q != 0) {
                q = pi[q - 1];
            }
            else {
                i++;
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
    // int m = strlen(pat);

    KMPSearch(pat, txt, n, m);

    return 0;
}