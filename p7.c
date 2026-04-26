#include <stdio.h>

int board[20], n;

// Check if safe to place queen
int isSafe(int row, int col) {
    for(int i = 0; i < row; i++) {
        if(board[i] == col || 
           board[i] - i == col - row || 
           board[i] + i == col + row)
            return 0;
    }
    return 1;
}

// Print solution
void printSolution() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// Backtracking function
int solve(int row) {
    if(row == n) {
        printSolution();
        return 1; // one solution
    }

    for(int col = 0; col < n; col++) {
        if(isSafe(row, col)) {
            board[row] = col;
            if(solve(row + 1))
                return 1;
        }
    }
    return 0;
}

int main() {
    int choice;

    while(1) {
        printf("\n1. Enter N\n2. Solve N-Queens\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter value of N: ");
                scanf("%d", &n);
                break;

            case 2:
                if(n <= 0) {
                    printf("Enter N first!\n");
                    break;
                }

                if(!solve(0))
                    printf("No solution exists\n");
                break;

            case 3:
                return 0;
        }
    }
}
/* 7. N-QUEENS (BACKTRACKING)
   Time Complexity: O(2^n)  [Exponential]
   Space Complexity: O(n) (recursion stack)
*/