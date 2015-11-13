#include <stdio.h>
#include <stdlib.h>
 
#define ValType double
#define IS_LESS(v1, v2)  (v1 < v2)
 
void siftDown( ValType *a, int start, int count);
 
#define SWAP(r,s)  do{ValType t=r; r=s; s=t; } while(0)
 
void heapsort( ValType *a, int count)
{
    int start, end;
 
    /* heapify */
    for (start = (count-2)/2; start >=0; start--) {
        siftDown( a, start, count);
    }
 
    for (end=count-1; end > 0; end--) {
        SWAP(a[end],a[0]);
        siftDown(a, 0, end);
    }
}
 
void siftDown( ValType *a, int start, int end)
{
    int root = start;
 
    while ( root*2+1 < end ) {
        int child = 2*root + 1;
        if ((child + 1 < end) && IS_LESS(a[child],a[child+1])) {
            child += 1;
        }
        if (IS_LESS(a[root], a[child])) {
            SWAP( a[child], a[root] );
            root = child;
        }
        else
            return;
    }
}
 
 
int main()
{
    int ix;
    double valsToSort[] = {4, 2, 3, 1};
#define VSIZE (sizeof(valsToSort)/sizeof(valsToSort[0]))
 
    heapsort(valsToSort, VSIZE);
    printf("{");
    for (ix=0; ix<VSIZE; ix++) printf(" %.3f ", valsToSort[ix]);
    printf("}\n");
    return 0;
}
