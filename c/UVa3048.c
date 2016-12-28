#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0
#define bool char

#define BUF_SIZE 100
#define MAX_NAME 25
#define LIST_INC_SIZE 3


bool isblank_str(char *str) {
    int i, l = strlen(str);
    for (i = 0; i < l; i++) {
        char c = str[i];
        if (!(isblank(c)||c=='\n'))
            return false;
    }
    return true;
}

typedef struct list {
    int size;
    int _data_size;
    void **data;
} list_t;

void list_ensure(list_t *list, int size) {
    if (!list->_data_size) {
        list->_data_size = (size > LIST_INC_SIZE ? size : LIST_INC_SIZE);
        list->data = calloc(list->_data_size, sizeof(void*));
        return;
    }

    if (size > list->_data_size) {
        int next_size = list->_data_size+LIST_INC_SIZE;
        void** tmp;
        if (next_size < size) {
            next_size = size;
        }

        tmp = list->data;
        list->data = calloc(next_size, sizeof(void*));
        memcpy(list->data, tmp, list->_data_size*sizeof(void*));
        list->_data_size = next_size;
        free(tmp);
    }
}

void *list_add(list_t *list, void *element) {
    int size = list->size;
    list_ensure(list, size + 1);
    *(list->data+size) = element;
    list->size = size + 1;
    return element;
}

void *list_remove(list_t *list, int index) {
    if (index < 0 || index >= list->size)
        return NULL;

    void *rm = list->data+index;
    memcpy(list->data+index, list->data+index+1, (list->size-index-1)*sizeof(void*));
    list->size--;

    return rm;
}

void list_free(list_t *list) {
    if (list->_data_size) {
        free(list->data);
        list->data = NULL;
    }

    list->_data_size = 0;
    list->size = 0;
}

int list_indexof(list_t *list, void *d) {
    int i, l = list->size;
    for (i = 0; i < l; i++) {
        void *tmp = list->data[i];
        if (tmp == d)
            return i;
    }

    return -1;
}


typedef struct node {
    struct node *parent;
    char name[MAX_NAME];
    list_t children;
} node_t;

void node_free(node_t *node) {
    if (node->children.size) {
        int i, l = node->children.size;
        for (i = 0; i < l; i++) {
            node_t *child = node->children.data[i];
            node_free(child);
        }
    }

    list_free(&node->children);
    node->parent = NULL;
    free(node);
}

void tree_clear(node_t *tree) {
    tree->parent = NULL;
    int i, l = tree->children.size;
    for (i = 0; i < l; i++) {
        node_t *child = tree->children.data[i];
        node_free(child);
    }
    list_free(&tree->children);
}

void print(node_t *node, int depth) {
    int i, l;
    for (i = 0; i < depth; i++) {
        putchar('+');
    }
    puts(node->name);
    
    l = node->children.size;
    for (i = 0; i < l; i++) {
        node_t *child = node->children.data[i];
        print(child, depth+1);
    }
}

node_t *find_by_name(node_t *node, char *name) {
    if (strcmp(node->name, name) == 0)
        return node;

    int i, l = node->children.size;
    for (i = 0; i < l; i++) {
        node_t *child = node->children.data[i];
        node_t* ret = find_by_name(child, name);
        if (ret)
            return ret;
    }
    
    return NULL;
}

void hires(node_t *tree, char *a, char *b) {
    node_t *parent = find_by_name(tree, a);
    if (!parent)
        return;

    node_t *child = calloc(1, sizeof(node_t));
    strcpy(child->name, b);
    child->parent = parent;
    list_add(&parent->children, child);
}

void fire(node_t *tree, char *name) {
    node_t *node = find_by_name(tree, name);
    if (!node)
        return;

    while (node->children.size) {
        node_t *child = node->children.data[0];
        strcpy(node->name, child->name);
        node = child;
    }

    if (node->parent) {
        int index = list_indexof(&node->parent->children, node);
        if (index != -1)
            list_remove(&node->parent->children, index);
    }

    node_free(node);
}

int main(int argc, char *argv[]) {
    long T;
    char s[BUF_SIZE];
    /* All names in the input consist of 2 to 20 characters */
    char a[MAX_NAME], b[MAX_NAME], c[MAX_NAME];

    /* The first line of the input indicates the number of datasets in the input. */
    fgets(s, BUF_SIZE, stdin);
    T = atol(s);
    /* remove first blank line */
    fgets(s, BUF_SIZE, stdin);
    while (T-- > 0) {
        node_t tree = {0};
        while (fgets(s, BUF_SIZE, stdin) != NULL) {
            if (isblank_str(s)) {
                /* Datasets will be separated by a blank line. */
                /* reset tree */
                tree_clear(&tree);
                puts("");
                break;
            } else {
                int count = sscanf(s, "%s %s %s", a, b, c);
                if (count && strcmp(a, "print") == 0) {
                    print(&tree, 0);
                    puts("------------------------------------------------------------");
                } else if (count == 2 && strcmp(a, "fire") == 0) {
                    fire(&tree, b);
                } else if (count == 1) {
                    /* The first line of each dataset contains only the name of the person who is initially the CEO. */
                    strcpy(tree.name, a);
                } else if (count == 3 && strcmp(b, "hires") == 0) {
                    /* a hires c */
                    hires(&tree, a, c);
                } else {
                    puts("***************unhandled");
                }
            }
        }
    }

    return 0;
}
