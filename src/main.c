#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    size_t size;
} my_array;

// Move constructor
my_array* my_array_move(my_array* src) {
    my_array* dest = malloc(sizeof(my_array));
    dest->data = src->data;
    dest->size = src->size;
    src->data = NULL;
    src->size = 0;
    return dest;
}

// Move assignment operator
void my_array_move_assign(my_array* dest, my_array* src) {
    free(dest->data);
    dest->data = src->data;
    dest->size = src->size;
    src->data = NULL;
    src->size = 0;
}

int main() {
    my_array arr1 = { malloc(10 * sizeof(int)), 10 };
    arr1.data[0] = 1;

    printf("arr1.data[0]: %d\n", arr1.data[0]);

    my_array arr2 = { NULL, 0 };

    // Move arr1 to arr2
    arr2 = *my_array_move(&arr1);
    printf("arr1.data is NULL? %s", arr1.data == NULL ? "true" : "false");
    // Move arr2 to arr1
    //my_array_move_assign(&arr1, &arr2);

    // Clean up memory
    free(arr1.data);
    free(arr2.data);

    return 0;
}
