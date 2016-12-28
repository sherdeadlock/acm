#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#include <functional>
using namespace std;

/*
 * 醜數是不能被2, 3, 5以外的其他質數整除的數.
 */
int main(int argc, char *argv[]) {
    const int coeff[3] = {2, 3, 5};
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    set<long long> sets;
    pq.push(1);
    sets.insert(1);
    for (int i = 1; ; i++) {
        const long long x = pq.top();
        pq.pop();
        if (i == 1500) {
            printf("The 1500'th ugly number is %lld.\n", x);
            break;
        }

        for (int j = 0; j < 3; j++) {
            long long ug = x*coeff[j];
            if (!sets.count(ug)) {
                sets.insert(ug);
                pq.push(ug);
            }
        }
    }
    return 0;
}
