#include <stdio.h>

int main() {
    int n, i;
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int min = arr[0], max = arr[0];

    for(i = 1; i < n; i++) {
        if(arr[i] < min)
            min = arr[i];
        if(arr[i] > max)
            max = arr[i];
    }

    printf("Min = %d\nMax = %d", min, max);
    return 0;
}
/* 1. MIN-MAX (ARRAY)
   Time Complexity: O(n)  [Best = Avg = Worst]
   Space Complexity: O(1)
*/

/* BINARY SEARCH
   Best Case: O(1)
   Average Case: O(log n)
   Worst Case: O(log n)
   Space Complexity: O(1) (iterative)
*/