#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cctype>
#include <algorithm>
using namespace std;

string normalize(const string &s) {
    string ret = s;
    for (int i = 0, l = ret.size(); i < l; i++) {
        ret[i] = tolower(ret[i]);
    }

    sort(ret.begin(), ret.end());
    return ret;
}

int main(int argc, char *argv[]) {
    string s;
    map<string, int> count;
    set<string> words;

    while (cin >> s) {
        if (s[0] == '#')
            break;

        string ns = normalize(s);
        if (count.count(ns) == 0) {
            count[ns] = 1;
        } else {
            count[ns]++;
        }
        
        words.insert(s);
    }

    for (set<string>::iterator it = words.begin(); it != words.end(); ++it) {
        const string &word = *it;
        if (count[normalize(word)] == 1)
            cout << word << '\n';
    }

    return 0;
}
