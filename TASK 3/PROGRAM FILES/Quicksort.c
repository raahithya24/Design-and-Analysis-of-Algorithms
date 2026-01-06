#include <stdio.h>
int partition(int a[], int low, int high) {
    int pivot = a[high], i = low - 1, temp;
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            temp = a[i]; a[i] = a[j]; a[j] = temp;
        }
    }
    temp = a[i+1]; a[i+1] = a[high]; a[high] = temp;
    return i + 1;
}
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}
int main() {
    int n, a[50];
    printf("Enter number of elements for quick sort: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    quickSort(a, 0, n - 1);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
