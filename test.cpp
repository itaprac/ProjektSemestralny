#include <iostream>

void merge_sort(int* arr, int size) {
    if (size > 1) {
        int mid = size / 2;
        int* L = new int[mid];
        int* R = new int[size - mid];
        for (int i = 0; i < mid; i++) {
            L[i] = arr[i];
        }
        for (int i = mid; i < size; i++) {
            R[i - mid] = arr[i];
        }
        merge_sort(L, mid);
        merge_sort(R, size - mid);
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < mid && j < size - mid) {
            if (L[i] < R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < mid) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < size - mid) {
            arr[k] = R[j];
            j++;
            k++;
        }
        delete[] L;
        delete[] R;
    }
}

int main(void) {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, arr_size);
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}