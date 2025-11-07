#include <stdio.h>
int main() {
    int n, i, key, flag = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("Element found at position %d\n", i + 1);
            flag = 1;
            break;
        }
    }
    if (!flag) printf("Element not found\n");
    return 0;
}