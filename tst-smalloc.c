#include <stdio.h>
#include "malloc.h"

/**
 * The main
 * 
 * 
 */
void test_smalloc(int mem, int arena) {
    char* x;
    x = smalloc(mem, arena);
    if(x!=NULL) {
        printf("Successfully allocated %d bytes from arena %d using smalloc @%x\n", mem, arena, x);
        free(x);
        printf("Freed 64 bytes using free from arena %d\n", arena);
    }
    else {
        printf("Unsuccessful in allocating %d bytes from arena %d using smalloc\n", mem, arena);
    }
}

int main(int argc, char* argv[]) {
    char *x, *y, *z, *w, *p;
    // Currently smalloc does not actually work
    // Just testing the interface
    test_smalloc(64, 0);
    test_smalloc(256, 3);
    int s = arena_create();
    printf("Created %d arena.\n", s);
    test_smalloc(24, s);
    test_smalloc(512, s);
    return 0;
} 