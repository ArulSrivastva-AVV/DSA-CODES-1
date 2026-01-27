//1.
//ch.sc.u4aie25003


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

void init(DynamicArray *da) {
    da->size = 0;
    da->capacity = 2;
    da->data = malloc(da->capacity * sizeof(int));
}

void resize(DynamicArray *da, int new_capacity) {
    int *temp = realloc(da->data, new_capacity * sizeof(int));
    if (temp) {
        da->data = temp;
        da->capacity = new_capacity;
    }
}

void insert(DynamicArray *da, int element) {
    if (da->size == da->capacity) {
        resize(da, da->capacity * 2);
    }
    da->data[da->size++] = element;
}

void delete(DynamicArray *da, int index) {
    if (index < 0 || index >= da->size) {
        return;
    }

    for (int i = index; i < da->size - 1; i++) {
        da->data[i] = da->data[i + 1];
    }
    da->size--;

    if (da->size > 0 && da->size < da->capacity / 2 && da->capacity > 2) {
        resize(da, da->capacity / 2);
    }
}

void display(DynamicArray *da) {
    for (int i = 0; i < da->size; i++) {
        printf("%d ", da->data[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray da;
    init(&da);

    insert(&da, 10);
    insert(&da, 20);
    insert(&da, 30);
    display(&da);

    delete(&da, 0);
    delete(&da, 0);
    display(&da);

    free(da.data);
    return 0;
}

