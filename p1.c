#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair minMax(int arr[], int low, int high) {
    struct Pair result, left, right;

    // Base Case 1: Only one element
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    // Base Case 2: Two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // Divide
    int mid = (low + high) / 2;

    // Conquer
    left = minMax(arr, low, mid);
    right = minMax(arr, mid + 1, high);

    // Combine
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int n, arr[100];
    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Pair ans = minMax(arr, 0, n - 1);

    printf("Minimum = %d\n", ans.min);
    printf("Maximum = %d\n", ans.max);

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
