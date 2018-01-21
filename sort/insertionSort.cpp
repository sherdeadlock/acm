#include <iostream>
using namespace std;

int descending(int* a, int* b) {
    return *b - *a;
}

int ascending(int* a, int* b) {
    return *a - *b;
}

void insertionSort(int A[], int len, int (*comp)(int*, int*) = ascending) {
    for (int j = 1; j < len; j++) {
        int key = A[j];

        int i = j - 1;
        while (i >= 0 && comp(&A[i], &key) > 0) {
            A[i+1] = A[i];
            i--;
        }

        A[i+1] = key;
    }
}

int main() {
    int A[] = {3, 2, 1, 5, 7};
    int len = sizeof(A) / sizeof(int);

    insertionSort(A, len);
    for (int i = 0; i < len; i++) {
        cout << A[i];
    }
    cout << endl;

    return 0;
}
