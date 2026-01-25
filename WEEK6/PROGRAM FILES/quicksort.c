#include <stdio.h>
#include <stdlib.h>
int hoareDivide(int arr[], int start, int end, int option) {
    int pivotPos;
    switch (option) {
        case 1: // first element
            pivotPos = start;
            break;

        case 2: // last element
            pivotPos = end;
            break;

        case 3: // random element
            pivotPos = start + rand() % (end - start + 1);
            break;

        default:
            pivotPos = start;
    }
    int temp = arr[start];
    arr[start] = arr[pivotPos];
    arr[pivotPos] = temp;

    int pivot = arr[start];
    int left = start + 1;
    int right = end;

    while (1) {
        while (left <= end && arr[left] <= pivot)
            left++;

        while (arr[right] > pivot)
            right--;

        if (left >= right)
            break;

        // swap elements
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }

    temp = arr[start];
    arr[start] = arr[right];
    arr[right] = temp;

    return right;  
}

// Quick sort function
void quickArrange(int arr[], int start, int end, int option) {
    if (start < end) {
        int pos = hoareDivide(arr, start, end, option);
        quickArrange(arr, start, pos - 1, option);
        quickArrange(arr, pos + 1, end, option);
    }
}

int main() {
    int data[] = {157, 110, 147, 122, 111, 149, 151, 141, 123, 112, 117, 133};
    int size = sizeof(data) / sizeof(data[0]);
    int option;

    printf("Choose Pivot Type (Hoare Method):\n");
    printf("1. First element\n");
    printf("2. Last element\n");
    printf("3. Random element\n");
    printf("Enter choice: ");
    scanf("%d", &option);

    quickArrange(data, 0, size - 1, option);

    printf("Sorted array:\n");
    for (int k = 0; k < size; k++)
        printf("%d ", data[k]);

    return 0;
}