#include <stdio.h>
#include "malloc.h"

/**
 * The main
 * 
 * 
 */
void test_scalloc(int num_elements, int element_size, int arena) {
    int* x;
    x = scalloc(num_elements, element_size, arena);
    if(x!=NULL) {
        printf("Successfully allocated %d elements, of size %d bytes each, from arena %d, using scalloc @%x\n", num_elements, element_size, arena, x);
        free(x);
        printf("Freed %d bytes using free from arena %d\n", num_elements*element_size, arena);
    }
    else {
        printf("Unsuccessful in allocating %d elements of size %d bytes each from arena %d using scalloc\n", num_elements, element_size, arena);
    }
}

int main(int argc, char* argv[]) {
    int *x, *y, *z, *w, *p;
    // Currently smalloc does not actually work
    // Just testing the interface
    test_scalloc(16, 4, 0);
    test_scalloc(64, 4, 3);
    int s = arena_create();
    printf("Created %d arena.\n", s);
    test_scalloc(6, 4, s);
    test_scalloc(128, 4, s);
    return 0;
} 