#include <iostream>
#include <algorithm>
using namespace std;

const int max_col = 60;
const int max_n = 100+5;

void print(const string &filename, int max) {
    cout << filename;
    for (int i = filename.size(); i < max; i++) {
        cout << ' ';
    }
}
/*
 * 最長檔名m, 最右寬度m, 其他寬度m+2
 */
int main(int argc, char *argv[]) {
    int N=0;
    string filenames[max_n];

    while (cin >> N) {
        cout << "------------------------------------------------------------" << endl;
        int m = 0;
        for (int i = 0; i < N; i++) {
            cin >> filenames[i];
            m = max((int)filenames[i].size(), m);
        }

        sort(filenames, filenames+N);
        int cols = (max_col-m) / (m+2) + 1;
        int rows = (N-1) / cols + 1;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int index = c*rows + r;
                if (index < N) {
                    print(filenames[index], c == cols-1 ? m : m+2);
                }
            }
            cout << endl;
        }
    }

    return 0;
}
