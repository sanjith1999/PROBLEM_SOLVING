// Insertion Sort
#include <bits/stdc++.h>

using namespace std;

void display_array(int *A, int n) {
    for (int i = 0; i < n; i++)cout << A[i] << "\t";
    cout << endl;
}

void insertion_sort(int *A, int n) {
    int key = 0;
    for (int i = 1; i < n; i++) {
        key = A[i];
        int j = i - 1;
        while (j > -1 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}


void bubbleSort(int *A, int n) {
    bool swapped = false;
    int i = 1, temp = 0, count = 0;
    do {
        swapped = false;
        for (i = 1; i < n - count; i++) {
            if (A[i - 1] > A[i]) {
                temp = A[i], A[i] = A[i - 1], A[i - 1] = temp;
                swapped = true;
            }
        }
        count++;
    } while (swapped);
}


void merge(int array[], int const left, int const mid, int const right) {
    int mergedArr[right - left + 1];
    int i = left, j = mid + 1, k = 0;
    while (i < mid + 1 && j < right + 1) {
        mergedArr[k++] = (array[i] > array[j]) ? array[j++] : array[i++];
    }
    while (i < mid + 1)
        mergedArr[k++] = array[i++];
    while (j < right + 1)
        mergedArr[k++] = array[j++];
    for (i = left; i < right + 1; i++)
        array[i] = mergedArr[i - left];
}

void mergeSort(int array[], int const begin, int const end) {
    if (begin == end) {
        return;
    }
    mergeSort(array, begin, (begin + end) / 2);
    mergeSort(array, (begin + end + 1) / 2, end);
    merge(array, begin, (begin + end - 1) / 2, end);
}

int main() {
    int n = 5;
    int A[] = {4, 3, 2, 5, 1};
//    insertion_sort(A, n);
//    mergeSort(A, 0, 4);
//    bubbleSort(A, n);
    display_array(A, n);
    return 0;
}