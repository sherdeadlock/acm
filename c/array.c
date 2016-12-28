#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct array {
    int size;
    int _data_size;
    void **data;
} array_t;

void array_ensure(array_t *array, int size) {
    if (!array->_data_size) {
        array->_data_size = (size > 10 ? size : 10);
        array->data = calloc(array->_data_size, sizeof(void*));
        return;
    }

    if (size > array->_data_size) {
        int next_size = (array->_data_size*3)/2+1;
        void** tmp;
        if (next_size < size) {
            next_size = size;
        }

        tmp = array->data;
        array->data = calloc(next_size, sizeof(void*));
        memcpy(array->data, tmp, array->_data_size*sizeof(void*));
        array->_data_size = next_size;
        free(tmp);
    }
}

void *array_add(array_t *array, void *element) {
    int size = array->size;
    array_ensure(array, size + 1);
    *(array->data+size) = element;
    array->size = size + 1;
    return element;
}

void *array_remove(array_t *array, int index) {
    if (index < 0 || index >= array->size)
        return NULL;

    void *rm = array->data+index;
    memcpy(array->data+index, array->data+index+1, (array->size-index-1)*sizeof(void*));
    array->size--;

    return rm;
}

void array_clear(array_t *array) {
    memset(array->data, 0, array->_data_size*sizeof(void*));
    array->size = 0;
}

void array_free(array_t *array) {
    if (array->_data_size) {
        free(array->data);
        array->data = NULL;
    }

    array->_data_size = 0;
    array->size = 0;
}

void print(array_t *array) {
    int i, l = array->size;
    for (i = 0; i < l; i++) {
        printf("%s\n", array->data[i]);
    }
}

int main(int argc, char *argv[]) {
    int i;
    array_t array = {0};
    array_add(&array, "hello");
    array_add(&array, "world");
    printf("%d\n", array.size);
    print(&array);

    for (i = 0; i < 10; i++) {
        array_add(&array, "hello");
    }
    printf("===========\n");
    array_remove(&array, 1);
    print(&array);

    array_clear(&array);
    array_free(&array);

    array_add(&array, "1");
    array_add(&array, "2");
    array_add(&array, "3");
    array_add(&array, "4");
    print(&array);
    array_remove(&array, 3);
    array_remove(&array, 2);
    array_remove(&array, 1);
    array_remove(&array, 0);
    print(&array);
    array_free(&array);

    return 0;
}
