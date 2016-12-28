#include <cstdio>
#include <vector>
using namespace std;

void add(vector<int> a[]) {
    // 必須用 reference
    vector<int> &v = a[0];
    v.push_back(1);
}

int main(int argc, char *argv[]) {
    vector<int> a[10];
    add(a);

    for (int i = 0, l = a[0].size(); i < l; i++) {
        printf("%d: %d\n", i, a[0][i]);
    }
    printf("\n");

    add(a);
    for (int i = 0, l = a[0].size(); i < l; i++) {
        printf("%d: %d\n", i, a[0][i]);
    }
    printf("\n");

    return 0;
}
