#include <stdio.h>
int main() {
    int n, arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
     for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
        printf("\n");
    return 0;
}

