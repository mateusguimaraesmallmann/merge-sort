#include <stdio.h>

#define LIMIT 5

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertionSort(int array[], int l, int h) {

    for (int step = l + 1; step <= h; step++) {
        int key = array[step];
        int j = step - 1;

        while (j >= l && key < array[j]) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int h) {

    int size = h - l + 1;

    if (size < LIMIT) {
        insertionSort(arr, l, h);
        return;
    }

    int i = l;
    int j = m + 1;
    int k = 0;
    int n1 = m;
    int n2 = h;
    int output[size];

    while (i <= n1 && j <= n2) {

        if (arr[i] <= arr[j]) {
            output[k] = arr[i];
            i++;
        } else {
            output[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= n1) {
        output[k] = arr[i];
        i++;
        k++;
    }

    while (j <= n2) {
        output[k] = arr[j];
        j++;
        k++;
    }

    for (i = l; i <= h; i++)
        arr[i] = output[i - l];
}

void mergeSort(int arr[], int size) {

    int l, m, h, i;

    for (int subSize = 1; subSize < size; subSize *= 2) {
        for (l = 0; l < size - subSize; l += subSize * 2) {
            m = l + subSize - 1;
            h = l + subSize * 2 - 1;

            if (h >= size)
                h = size - 1;

            merge(arr, l, m, h);
        }
    }
}

int main() {

    int data[1000], i;

    for (i = 0; i < 1000; i++)
        data[i] = rand() % 1000;

    int size = sizeof(data) / sizeof(data[0]);
    mergeSort(data, size);
    printf("Classificado ordem crescente:\n");
    printArray(data, size);
}
