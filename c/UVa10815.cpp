#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

int main(int argc, char *argv[]) {
    set<string> dict;
    stringstream ss;
    char ch;
    
    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            ss << ch;
        } else {
            const string &s = ss.str();
            if (!s.empty()) {
                dict.insert(s);
                ss.str("");
                ss.clear();
            }
        }
    }

    for (set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
        cout << *it << "\n";
    }

    return 0;
}
