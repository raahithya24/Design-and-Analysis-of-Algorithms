#include <stdio.h>
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min])
                min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
int main() {
    int n, arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        }
    selectionSort(arr, n);
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
        printf("\n");
    return 0;
}

