#include <stdio.h>
void bucketSort(int arr[], int n) {
    int min = arr[0], max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < min)
            min = arr[i];
        if(arr[i] > max)
            max = arr[i];
    }
    int range = max - min + 1;
    int bucket[1000] = {0};   
    for(int i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }
    int index = 0;
    for(int i = 0; i < range; i++) {
        while(bucket[i] > 0) {
            arr[index++] = i + min;
            bucket[i]--;
        }
    }
}
int main() {
    int n, arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

