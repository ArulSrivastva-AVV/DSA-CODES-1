//2.
//ch.sc.u4aie25003gcc

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

void insertAt(DynamicArray *da, int index, int element) {
    if (index < 0 || index > da->size) {
        printf("Invalid index\n");
        return;
    }

    if (da->size == da->capacity) {
        resize(da, da->capacity * 2);
    }

    for (int i = da->size; i > index; i--) {
        da->data[i] = da->data[i - 1];
    }

    da->data[index] = element;
    da->size++;
}

void insertBeginning(DynamicArray *da, int element) {
    insertAt(da, 0, element);
}

void insertEnd(DynamicArray *da, int element) {
    insertAt(da, da->size, element);
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

    insertEnd(&da, 10);
    insertEnd(&da, 20);
    display(&da); 

    insertBeginning(&da, 5);
    display(&da); 

    insertAt(&da, 2, 15);
    display(&da); 

    free(da.data);
    return 0;
}