#include <stdio.h>
#include "malloc.h"

/**
 * The main
 * 
 * 
 */
int main(int argc, char* argv[]) {
    char *x, *y, *z, *w, *p;
    /**
     * Test 1
     */
    /** Allocations less than 64 bytes, say 63 bytes for
     * x and 63 bytes for y.
     */
    printf("Test results :\n");
    x = malloc(63);
    printf("x=%08x\n", x);
    free(x);
    y = malloc(63);
    printf("y=%08x\n", y);
    free(y);
    /**
     * We get the address for x and y are same,
     * which shows fast bin was used
     */ 
    /**
     * Test 
     */
    /** Allocations less than 64 bytes, say 63 bytes for
     * x and 30 bytes for y.
     */
    printf("Test results : Fast bin sizes\n");
    printf("Allocating 72 to x\n");
    x = malloc(72);
    printf("x=%08x\n", x);
    printf("Free x\n");
    free(x);
    printf("Allocating 63 to x\n");
    x = malloc(63);
    printf("x=%08x\n", x);
    printf("Free x\n");
    free(x);
    printf("Allocating 55 to x\n");
    x = malloc(55);
    printf("x=%08x\n", x);
    printf("Free x\n");
    free(x);
    printf("Allocating 56 to x\n");
    x = malloc(56);
    printf("x=%08x\n", x);
    printf("Free x\n");
    free(x);
    printf("Allocating 40 to x\n");
    x = malloc(40);
    printf("x=%08x\n", x);
    printf("Free x\n");
    free(x);
    printf("Allocating 39 to x\n");
    x = malloc(39);
    printf("x=%08x\n", x);
    printf("Free x\n");
    free(x);
    printf("Allocating 24 to x\n");
    x = malloc(24);
    printf("x=%08x\n", x);
    printf("Free x\n");
    free(x);
    printf("Allocating 23 to x\n");
    x = malloc(23);
    printf("x=%08x\n", x);
    printf("Free x\n");
    free(x);
    printf("Allocating 16 to x\n");
    x = malloc(16);
    printf("x=%08x\n", x);
    printf("Free x\n");
    free(x);
    printf("Allocating 7 to x\n");
    x = malloc(7);
    printf("x=%08x\n", x);
    printf("Free x\n");
    free(x);
    printf("From these we can conclude that, the bin sizes are 24, 40, 56, 72\n");
    /**
     * Test 
     */
    /** Allocations less than 64 bytes, say 63 bytes for
     * x and 30 bytes for y.
     */
    printf("Test results :\n");
    x = malloc(63);
    printf("x=%08x\n", x);
    p = malloc(63);
    printf("p=%08x\n", p);
    y = malloc(63);
    printf("y=%08x\n", y);
    free(x);
    free(p);
    free(y);
    z = malloc(63);
    printf("z=%08x\n", z);
    free(z);
    /**
     * We see the address for y and z are same,
     * Since y was freed after x and p, it's chunk was
     * added last to the fast bins for 64 byte chunks.
     * The last added chunk is utillized first, thus LIFO is
     * being followed.
     */ 
    /**
     * Test 2
     */
    printf("Test results : test whether there are fast bins greater than 72\n");
    x = malloc(80);
    printf("x=%08x\n", x);
    free(x);
    y = malloc(72);
    printf("y=%08x\n", y);
    free(y);
    /** The address for the x, y are different
     */

    /** 
     * Tests for memory chunks greater than 512 bytes.
     */
    /** 
     * Test for Best Fit for chunks greater than 512
     */
    printf("Test Results: Best fit for large chunks\n");
    x = malloc(9876);
    printf("x=%08x\n", x);
    p = malloc(10000);
    y = malloc(10000);
    printf("y=%08x\n", y);
    w = malloc(10000);
    z = malloc(11000);
    printf("z=%08x\n", z);
    free(x);
    free(y);
    free(z);
    y = malloc(9875);
    printf("y=%08x\n", y);
    free(y);

    free(p);
    free(w);

    /**
     * We see x, y have same addresses since the random values 9875 is very close
     * to 9876 and thus the best must allocate this rather than some other values.
     */
    /**
     * Test for FIFO for chunks greater than 512
     */
    char *b1, *b2;
    printf("Test results : Check allocation strategy for larger chunks of same size\n");
    x = malloc(1023);
    printf("x=%08x\n", x);
    b1 = malloc(500);
    y = malloc(1023);
    printf("y=%08x\n", y);
    b2 = malloc(500);
    z = malloc(1023);
    printf("z=%08x\n", z);
    free(y);
    free(x);    
    free(z);
    w = malloc(1023);
    printf("w=%08x\n", w);
    free(w);
    free(b1);
    free(b2);
    /**
     * We see for chunks greater than 512 bytes,
     * The allocation happens depending on best fit followed 
     * by lower starting address
     */

    /**
     * Chunks of size 64-512
     * 
     */
    printf("Test results: allocate 100 to x, 100 to y , free(x), free(y), allocate 150 to z\n");
    x = malloc(100);
    printf("x=%08x\n", x);
    y = malloc(100);
    printf("y=%08x\n", y);
    free(x);
    free(y);
    z = malloc(150);
    printf("z=%08x\n", z);
    free(z);
    printf("We can see the address of x and z are same which show memory of x, y coalesced\n");

    /**
     * Test
     */
    printf("Test results: allocate 250 to x, 250 to y, 250 to z, free(x), free(y), free(z) and then allocate 250 to w\n");
    x = malloc(250);
    printf("x=%08x\n", x);
    y = malloc(250);
    printf("y=%08x\n", y);
    z = malloc(250);
    printf("z=%08x\n", z);
    free(y);
    free(x);
    free(z);
    w = malloc(250);
    printf("w=%08x\n", w);
    printf("The freeing order is y then x then z but the address of w and x are same which are also the lowest, so the allocation is happening according to smallest address first\n");
    return 0;
} 