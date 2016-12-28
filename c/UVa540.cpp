#include <cstdio>
#include <queue>
#include <map>
using namespace std;


const int max_teams = 1000;

int main(int argc, char *argv[]) {
    int T, kase=0, t;
    char cmd[10];

    while (true) {
        scanf("%d", &T);
        if (T == 0)
            break;

        map<int, int> teams;  // id->team
        // build teams
        for (int i = 0; i < T; i++) {
            scanf("%d", &t);
            int id;
            while (t--) {
                scanf("%d", &id);
                teams[id] = i;
            }
        }

        queue<int> teamqueue;
        queue<int> queues[max_teams];
        printf("Scenario #%d\n", ++kase);
        while (scanf("%s", cmd) == 1 && cmd[0] != 'S') {
            if (cmd[0] == 'E') {
                int id, team;
                scanf("%d", &id);
                team = teams[id];
                if (queues[team].empty()) {
                    teamqueue.push(team);
                }
                queues[team].push(id);
            } else if (cmd[0] == 'D') {
                int &team = teamqueue.front();
                queue<int> &tq = queues[team];
                printf("%d\n", tq.front());
                tq.pop();
                if (tq.empty()) {
                    teamqueue.pop();
                }
            }
        }
        printf("\n");
    }
    return 0;
}
