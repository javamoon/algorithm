#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printNoSortHeap(int heap[]);
void insert(int new, int heap[]); 
static void percolate_up(int heap[]);
int delete_min(int heap[]); 
static void percolate_down(int heap[]);
static void swap(int *pa, int *pb);
int pull(int heap[]);
void printSortHeap(int heap[]);

int main() {
	int SIZE = 30;
	
	int heap[1024];
	heap[0] = 0;
	insert(1, heap);
	insert(9, heap);
	insert(3, heap);
	insert(6, heap);
	insert(4, heap);
	insert(2, heap);
	insert(7, heap);
	insert(5, heap);
	insert(8, heap);

	heap[0] = 0;
	int i;
	for (i = SIZE; i > 0; i--) {
		insert(i, heap);
	}

	heap[0] = 0;
	int n;
	srand(time(0));
	for (i = SIZE; i > 0; i--) {
		n = rand() % SIZE;
		insert(n, heap);
	}
	
	printNoSortHeap(heap);
	printf("\n Sort Heap : \n");
	printSortHeap(heap);
	printf("\n After Sort Heap : \n");
	heap[0] = SIZE;
	printNoSortHeap(heap);
	return 0;
}

void printNoSortHeap(int heap[]) {
	int i, count = heap[0];
	for (i = 0; i <= count; i++) {
		printf("No Sort Heap Print : [%d], %d\n", i, heap[i]);
	}
}

void printSortHeap(int heap[]) {
	int i, count = heap[0];
	for (i = 1; i <= count; i++) {
		printf("Sort Heap Print : [%d], %d\n", i, pull(heap));
	}
}



/* 
   Use an big array to implement heap
   DECLARE: int heap[MAXSIZE] in calling function
   heap[0] : total nodes in the heap
   for a node i, its children are i*2 and i*2+1 (if exists)
   its parent is i/2  */

void insert(int new, int heap[]) 
{
    heap[0] = heap[0] + 1;
    heap[heap[0]] = new;
    
    /* recover heap property */
    percolate_up(heap);
}

static void percolate_up(int heap[]) {
    int lightIdx, parentIdx;
    lightIdx  = heap[0];
    parentIdx = lightIdx/2;
    /* lightIdx is root? && swap? */
    while((parentIdx > 0) && (heap[lightIdx] < heap[parentIdx])) {
        swap(heap + lightIdx, heap + parentIdx); 
        lightIdx  = parentIdx;
        parentIdx = lightIdx/2;
    }
}

int pull(int heap[]) {
	return delete_min(heap);
}

int delete_min(int heap[]) 
{
    int min;
    if (heap[0] < 1) {
        /* delete element from an empty heap */
        printf("Error: delete_min from an empty heap.");
        exit(1);
    }

    /* delete root 
       move the last leaf to the root */
    min = heap[1];
    swap(heap + 1, heap + heap[0]);
    heap[0] -= 1;

    /* recover heap property */
    percolate_down(heap);
 
    return min;
}

static void percolate_down(int heap[]) {
    int heavyIdx;
    int childIdx1, childIdx2, minIdx;
    int sign; /* state variable, 1: swap; 0: no swap */

    heavyIdx = 1;
    do {
        sign     = 0;
        childIdx1 = heavyIdx*2;
        childIdx2 = childIdx1 + 1;

        if (childIdx1 > heap[0]) {
            /* both children are null */
            break; 
        } else if (childIdx2 > heap[0]) {
            /* right children is null */
            minIdx = childIdx1;
        } else {
            minIdx = (heap[childIdx1] < heap[childIdx2]) ? childIdx1 : childIdx2;
        }

        if (heap[heavyIdx] > heap[minIdx]) {
            /* swap with child */
            swap(heap + heavyIdx, heap + minIdx);
            heavyIdx = minIdx;
            sign = 1;
        }
    } while(sign == 1);
}

/* exchange the values pointed by pa and pb*/
static void swap(int *pa, int *pb)
{
    int tmp;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}
