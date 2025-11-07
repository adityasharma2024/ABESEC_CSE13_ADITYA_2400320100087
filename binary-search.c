#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[100], n, key, i, result;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &key);
    result = binarySearch(arr, n, key);
    if (result == -1) printf("Not found\n");
    else printf("Found at index %d\n", result);
    return 0;
}
