//5.
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

void deleteAt(DynamicArray *da, int index) {
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
    printf("\n(Size: %d, Capacity: %d)\n", da->size, da->capacity);
}

int main() {
    DynamicArray da;
    init(&da);

    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        insert(&da, val);
    }

    printf("\nOriginal array:\n");
    display(&da);

    if (da.size == 0) {
        free(da.data);
        return 0;
    }

    int max = da.data[0], min = da.data[0];
    int maxIdx = 0, minIdx = 0;

    for (int i = 1; i < da.size; i++) {
        if (da.data[i] > max) { 
            max = da.data[i]; 
            maxIdx = i; 
        }
        if (da.data[i] < min) { 
            min = da.data[i]; 
            minIdx = i; 
        }
    }

    printf("\nMax value: %d\nMin value: %d\n", max, min);

    if (maxIdx > minIdx) {
        deleteAt(&da, maxIdx);
        deleteAt(&da, minIdx);
    } else if (maxIdx < minIdx) {
        deleteAt(&da, minIdx);
        deleteAt(&da, maxIdx);
    } else {
        deleteAt(&da, maxIdx);
    }

    printf("\nArray after deletion:\n");
    display(&da);

    free(da.data);
    return 0;
}