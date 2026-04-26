#include <stdio.h>
#include <string.h>

// Function to compute LPS array
void computeLPS(char pattern[], int lps[], int m) {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while(i < m) {
        if(pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Search
void KMPSearch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    int lps[100];
    computeLPS(pattern, lps, m);

    int i = 0, j = 0;
    int found = 0;

    while(i < n) {
        if(pattern[j] == text[i]) {
            i++;
            j++;
        }

        if(j == m) {
            printf("Pattern found at index %d\n", i - j);
            found = 1;
            j = lps[j - 1];
        }
        else if(i < n && pattern[j] != text[i]) {
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    if(!found)
        printf("Pattern not found\n");
}

int main() {
    char text[200], pattern[100];
    int choice;

    while(1) {
        printf("\n1. Enter Text & Pattern\n2. Run KMP Search\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter text: ");
                scanf("%s", text);

                printf("Enter pattern: ");
                scanf("%s", pattern);
                break;

            case 2:
                KMPSearch(text, pattern);
                break;

            case 3:
                return 0;
        }
    }
}
/* 9. KMP (KNUTH-MORRIS-PRATT)
   Time Complexity: O(n + m)
   Space Complexity: O(m)  [LPS array]
*/