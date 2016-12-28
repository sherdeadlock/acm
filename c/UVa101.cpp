#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;


int find_block_height(vector<int> &pile, int x) {
    for (int i = 0, l = pile.size(); i < l; i++) {
        if (pile[i] == x) {
            return i;
        }
    }
    return -1;
}

void clear_above(vector<int> piles[], int blocks[], int x) {
    int bi = blocks[x], h;
    vector<int>& pile = piles[bi];
    h = find_block_height(pile, x);
    for (int i = h+1, l = pile.size(); i < l; i++) {
        int pi = pile[i];
        blocks[pi] = pi;
        piles[pi].push_back(pi);
    }
    pile.resize(h+1);
}

void pile_onto(vector<int> piles[], int blocks[], int a, int b) {
    int ai = blocks[a], bi = blocks[b];
    vector<int> &pa = piles[ai], &pb = piles[bi];
    int h = find_block_height(pa, a);
    for (int i = h, l = pa.size(); i < l; i++) {
        int pi = pa[i];
        pb.push_back(pi);
        blocks[pi] = bi;
    }

    pa.resize(h);
}

int main(int argc, char *argv[]) {
    // 0 < n < 25
    int n, a, b;
    char cmd1[10], cmd2[10];

    scanf("%d", &n);
    vector<int> piles[30];
    int blocks[n];  // 紀錄block在那個pile

    for (int i = 0; i < n; i++) {
        piles[i].push_back(i);
        blocks[i] = i;
    }

    while (scanf("%s %d %s %d", cmd1, &a, cmd2, &b) == 4) {
        // 同一個 block 非法
        if (blocks[a] == blocks[b]) continue;

        if (strcmp("onto", cmd2) == 0) clear_above(piles, blocks, b);
        if (strcmp("move", cmd1) == 0) clear_above(piles, blocks, a);
        pile_onto(piles, blocks, a, b);
    }

    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        vector<int> pile = piles[i];
        for (int j = 0, l = pile.size(); j < l; j++) {
            printf(" %d", pile[j]);
        }
        printf("\n");
    }

    return 0;
}
