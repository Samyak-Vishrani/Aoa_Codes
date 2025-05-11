#include <stdio.h>

void rabinKarp(char pat[], char txt[], int n, int m) {

    int code = 0;
    int i = 0;
    while(pat[i] != '\0') {
        int digit = pat[i] - 'A' + 1;
        code = code * 10 + digit;
        i++;
    }
    
    // j from 0 to  = n-m
    for(int j = 0; j <= n-m; j++) {
        int txtCode = 0;
        int i = 0;
        while(i != m) {
            int digit = txt[j + i] - 'A' + 1;
            txtCode = txtCode * 10 + digit;
            i++;
        }

        if(txtCode == code) {
            printf("\nPattern found at %d\n", j);
            return;
        }
    }
    printf("Pattern not found\n");

}

int main() {

    int n = 15;
    int m = 5;
    char txt[] = "ABABCABCABABABD";
    char pat[] = "ABABD";

    rabinKarp(pat, txt, n, m);

    return 0;
}