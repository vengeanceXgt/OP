#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char X[100], Y[100];
    int L[100][100];
    int m = 0, n = 0;
    int choice;

    while(1) {
        printf("\n1. Enter Strings\n2. Find LCS\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter first string: ");
                scanf("%s", X);
                printf("Enter second string: ");
                scanf("%s", Y);

                m = strlen(X);
                n = strlen(Y);
                break;

            case 2:
                // Build DP table
                for(int i = 0; i <= m; i++) {
                    for(int j = 0; j <= n; j++) {
                        if(i == 0 || j == 0)
                            L[i][j] = 0;
                        else if(X[i-1] == Y[j-1])
                            L[i][j] = L[i-1][j-1] + 1;
                        else
                            L[i][j] = max(L[i-1][j], L[i][j-1]);
                    }
                }

                printf("Length of LCS = %d\n", L[m][n]);

                // Print LCS string (extra for viva)
                int i = m, j = n;
                char lcs[100];
                int index = L[m][n];
                lcs[index] = '\0';

                while(i > 0 && j > 0) {
                    if(X[i-1] == Y[j-1]) {
                        lcs[index-1] = X[i-1];
                        i--; j--; index--;
                    }
                    else if(L[i-1][j] > L[i][j-1])
                        i--;
                    else
                        j--;
                }

                printf("LCS = %s\n", lcs);
                break;

            case 3:
                return 0;
        }
    }
}
/* 6. LONGEST COMMON SUBSEQUENCE (LCS)
   Time Complexity: O(m * n)
   Space Complexity: O(m * n)

   Optimization: Space can be reduced to O(min(m,n))
*/