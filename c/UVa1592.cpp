#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

/*
 * TODO 慢 time 1.22
 */


int ID(map<string, int> &str_ids, const string &str) {
    if (str_ids.count(str)) {
        return str_ids[str];
    }

    int id = str_ids.size()+1;
    str_ids[str] = id;
    return id;
}

void split(map<string, int> &str_ids, const string &str, int out[], char delim) {
    int count = 0;
    int start = 0;
    for (int i = 0, l = str.size(); i < l; i++) {
        if (str[i] == delim) {
            string s = str.substr(start, i-start);
            int id = ID(str_ids, s);
            out[count++] = id;
            start = i+1;
        }
    }

    string s = str.substr(start, str.size()-start);
    int id = ID(str_ids, s);
    out[count] = id;
}

template <size_t max_rows, size_t max_cols>
void find(int rows, int cols, int (&table)[max_rows][max_cols], map<string, int> &str_ids) {
    for (int c1 = 0; c1 < cols; c1++) {
        for (int c2 = c1+1; c2 < cols; c2++) {
            map<pair<int, int>, int> d;
            for (int r = 0; r < rows; r++) {
                pair<int, int> p = make_pair(table[r][c1], table[r][c2]);
                if (d.count(p)) {
                    printf("NO\n");
                    printf("%d %d\n", d[p]+1, r+1);
                    printf("%d %d\n", c1+1, c2+1);
                    return;
                }
                d[p] = r;
            }
        }
    }
    printf("YES\n");
}


int main(int argc, char *argv[]) {
    int rows, cols;
    int table[10000][10];
    map<string, int> str_ids;

    while (scanf("%d%d\n", &rows, &cols) == 2) {
        string row;
        for (int r = 0; r < rows; r++) {
            getline(cin, row);
            split(str_ids, row, table[r], ',');
        }

        find(rows, cols, table, str_ids);

        str_ids.clear();
    }
    return 0;
}
