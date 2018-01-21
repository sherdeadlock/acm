#include <iostream>
using namespace std;


void merge(int source[], int tmp[], int begin, int middle, int end) {
    cout << "merge begin=" << begin << " middle=" << middle << " end=" << end << endl;
    int left = begin, right = middle;
    for (int i = begin; i < end; i++) {
        if (left < middle && (source[left] <= source[right] || right >= end)) {
            tmp[i] = source[left];
            left++;
        } else {
            tmp[i] = source[right];
            right++;
        }
    }

    // copy sorted subarray back to the source
    for (int i = begin; i < end; i++) {
        source[i] = tmp[i];
    }
}

void split(int source[], int tmp[], int begin, int end) {
    int len = end - begin;
    if (len < 2) {
        return;
    }

    int middle = begin + len / 2;
    printf("split begin=%d middle=%d end=%d\n", begin, middle, end);

    split(source, tmp, begin, middle);
    split(source, tmp, middle, end);
    merge(source, tmp, begin, middle, end);
}

void mergesort(int source[], int tmp[], int length) {
    split(source, tmp, 0, length);
}

void print(int source[], int len) {
    for (int i = 0; i < len; i++) {
        cout << source[i] << " ";
    }
    cout << endl;
}


int main() {
    int source[] = {5, 1, 7, 2, 6, 1, 4};
    int len = sizeof(source) / sizeof(int);
    int tmp[len];
    mergesort(source, tmp, len);
    print(source, len);
    return 0;
}
