#include <cstdio>
#include <set>
#include <stack>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;


typedef set<int> Set;
map<Set, int> ids;  // set->id
vector<Set> sets;  // id->set

int ID(const Set &s) {
    if (ids.count(s)) {
        return ids[s];
    }

    sets.push_back(s);
    return ids[s] = sets.size() - 1;
}

/*
 * stack 存 id
 * map 存 set->id
 * vector 存 id->set
 */
int main(int argc, char *argv[]) {
    int T, N;
    char cmd[10];
    stack<int> stack;

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%s", cmd);
            char ch = cmd[0];
            if (ch == 'P') {
                stack.push(ID(Set()));
            } else if (ch == 'D') {
                stack.push(stack.top());
            } else {
                const Set &a = sets[stack.top()];
                stack.pop();
                const Set &b = sets[stack.top()];
                stack.pop();
                Set new_set;
                if (ch == 'U') {
                    set_union(a.begin(), a.end(), b.begin(), b.end(), 
                            inserter(new_set, new_set.begin()));
                } else if (ch == 'I') {
                    set_intersection(a.begin(), a.end(), b.begin(), b.end(), 
                            inserter(new_set, new_set.begin()));
                } else if (ch == 'A') {
                    new_set = b;
                    new_set.insert(ID(a));
                }

                stack.push(ID(new_set));
            }
            cout << sets[stack.top()].size() << endl;
        }
        cout << "***" << endl;
    }

    return 0;
}
