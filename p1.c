#include <stdio.h>

void minMax(int arr[], int low, int high, int *min, int *max) {

    // Case 1: One element
    if (low == high) {
        *min = arr[low];
        *max = arr[low];
        return;
    }

    // Case 2: Two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }

    // Divide
    int mid = (low + high) / 2;

    int min1, max1, min2, max2;

    // Conquer
    minMax(arr, low, mid, &min1, &max1);
    minMax(arr, mid + 1, high, &min2, &max2);

    // Combine
    *min = (min1 < min2) ? min1 : min2;
    *max = (max1 > max2) ? max1 : max2;
}

int main() {
    int n, arr[100], min, max;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    minMax(arr, 0, n - 1, &min, &max);

    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

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
