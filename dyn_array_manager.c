//4.
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
        printf(">> System: Capacity resized to %d\n", da->capacity);
    }
}

void insert(DynamicArray *da, int element) {
    if (da->size == da->capacity) {
        resize(da, da->capacity * 2);
    }
    da->data[da->size++] = element;
}

int search(DynamicArray *da, int element) {
    for (int i = 0; i < da->size; i++) {
        if (da->data[i] == element) return i;
    }
    return -1;
}

void deleteElement(DynamicArray *da, int element) {
    int index = search(da, element);
    if (index == -1) {
        printf("Error: Element not found.\n");
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

void update(DynamicArray *da, int oldVal, int newVal) {
    int index = search(da, oldVal);
    if (index != -1) {
        da->data[index] = newVal;
    } else {
        printf("Error: Element not found.\n");
    }
}

void display(DynamicArray *da) {
    printf("\n--- Current State ---\n");
    printf("Data: ");
    if (da->size == 0) printf("Empty");
    for (int i = 0; i < da->size; i++) {
        printf("%d ", da->data[i]);
    }
    printf("\nSize: %d | Capacity: %d\n", da->size, da->capacity);
    printf("---------------------\n");
}

int main() {
    DynamicArray da;
    init(&da);
    int choice, val, val2;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Update\n5. Display\n6. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(&da, val);
                display(&da);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteElement(&da, val);
                display(&da);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                val2 = search(&da, val);
                if (val2 != -1) printf("Result: Found at index %d\n", val2);
                else printf("Result: Not found\n");
                break;
            case 4:
                printf("Enter old value and new value: ");
                scanf("%d %d", &val, &val2);
                update(&da, val, val2);
                display(&da);
                break;
            case 5:
                display(&da);
                break;
            case 6:
                free(da.data);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}