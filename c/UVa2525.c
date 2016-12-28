#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct Children {
    void *value;
    struct Children *next;
} Children;


void Children_add(Children *list, void *value) {
    Children *newlist = malloc(sizeof(Children));
    memset(newlist, 0, sizeof(Children));
    while (list->next != NULL) {
        list = list->next;
    }

    list->next = newlist;
    newlist->value = value;
}

void Children_destroy(Children *list) {
    Children *tmp;
    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

typedef struct Node {
    int value;
    int depth;
    struct Node *parent;
    int children_count;
    Children *children;
} Node;


void Node_add_child(Node *node, Node *child) {
    if (!node->children_count) {
        node->children = malloc(sizeof(Children));
        node->children->value = child;
        node->children->next = NULL;
    } else {
        Children_add(node->children, child);
    }
    node->children_count++;
}

void Node_destroy(Node *node) {
    Children_destroy(node->children);
}

Node *find_root(Node *tree) {
    int i, l = sizeof(tree);
    for (i = 0; i < l; i++) {
        Node *node = tree+i;
        if (node->parent == NULL) {
            return node;
        }
    }

    return NULL;
}

void DFS(Node *node, int depth) {
    node->depth = depth;
    Children *child = node->children;
    while (child != NULL) {
        DFS(child->value, depth+1);
        child = child->next;
    }
}

Node *find_common_ancestor(Node *a, Node *b) {
    while (a->value != b->value) {
        if (a->depth < b->depth) {
            b = b->parent;
        } else if (a->depth > b->depth) {
            a = a->parent;
        } else {
            a = a->parent;
            b = b->parent;
        }
    }
    return a;
}

void run_case(int N) {
    /* printf("run case %d\n", N); */
    int i, x, y;
    Node tree[N], *root, *node;
    memset(tree, 0, N*sizeof(Node));

    /* init value */
    for (i = 0; i < N; i++) {
        Node *node = &tree[i];
        node->value = i+1;
    }

    for (i = 0; i < N-1; i++) {
        scanf("%d %d", &x, &y);
        /* the first integer is the parent node of the second integer */

        Node *a = &tree[x-1];
        Node *b = &tree[y-1];
        /* printf("%d %d %d %d\n", x, a->value, y, b->value); */
        b->parent = a;
        Node_add_child(a, b);
    }

    root = find_root(tree);
    DFS(root, 0);

    for (i = 0; i < N; i++) {
        Node *node = tree+i;
        /* printf("i=%d value=%d depth=%d\n", i, node->value, node->depth); */
    }

    scanf("%d %d", &x, &y);
    /* 0 based */
    x--;
    y--;
    node = find_common_ancestor(tree+x, tree+y);
    printf("%d\n", node->value);
    Node_destroy(root);
}

int main(int argc, char *argv[]) {
    int T, N;
    
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d", &N);
        run_case(N);
    }
    return 0;
}
