#include <stdio.h>

int binarySearch(int *arr, int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target);
        }

        return binarySearch(arr, mid + 1, right, target);
    }

    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element jest obecny w indeksie %d\n", result);
    } else {
        printf("Element nie jest obecny w tablicy\n");
    }

    return 0;
}
