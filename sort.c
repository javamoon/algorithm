#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int size);
void initArray(int array[], int size);
void bubble_sort(int a[], int ac);
void swap(int *pa, int *pb);
void insert_sort(int a[], int ac);
void insert_sort_x(int a[], int n, int x);
void select_sort(int a[], int ac);
void shellsort2(int a[], int n);
void shell_sort(int a[], int n);
void quick_sort(int a[], int n);
void merge_sort(int *a, int ac);

int main() {
	int SIZE = 30;
	int arr[SIZE];
	initArray(arr, SIZE);
	printArray(arr, SIZE);
	printf("\n[6] : Merge Sort ->\n");
	merge_sort(arr, SIZE);
	printArray(arr, SIZE);

//	printf("\n[5] : Quick Sort ->\n");
//	quick_sort(arr, SIZE);
//	shell_sort(arr, SIZE);
//	select_sort(arr, SIZE);
//	bubble_sort(arr, SIZE);
//	insert_sort(arr, SIZE);
}

/*recursively merge two sorted arrays*/
void merge_sort(int *a, int ac) {
    int i, j, k;    
    int ac1, ac2;
    int *ah1, *ah2;
    int *container;

    /*base case*/    
    if (ac <= 1) return;

    /*split the array into two*/
    ac1 = ac/2;
    ac2 = ac - ac1;
    ah1 = a + 0;
    ah2 = a + ac1;

    /*recursion*/
    merge_sort(ah1, ac1);
    merge_sort(ah2, ac2);
 
    /*merge*/
    i = 0;
    j = 0;
    k = 0;
    container = (int *) malloc(sizeof(int)*ac);
    while(i<ac1 && j<ac2) {
        if (ah1[i] <= ah2[j]) {
            container[k++] = ah1[i++];
        } 
        else {
            container[k++] = ah2[j++];
        }
    }
    while (i < ac1) {
        container[k++] = ah1[i++];
    }
    while (j < ac2) {
        container[k++] = ah2[j++];
    }

    /*copy back the sorted array*/
    for(i=0; i<ac; i++) {
        a[i] = container[i];
    }
    /*free space*/
    free(container);
}

void quick_sort(int a[], int n) {
    swap(a + 0, a + n / 2);

    int pivot = 1;
    int sample;

    for (sample = 1; sample < n; sample++) {
        if (a[sample] < a[0]) {
            swap(a + pivot, a + sample);
            pivot++;
        }
    }

    swap(a + 0, a + pivot - 1);

    if (n <= 2) {
		return;
	} else {
        quick_sort(a, pivot);
        quick_sort(a + pivot, n - pivot);
    }
}

/*select pivot, put elements (<= pivot) to the left*/
void quick_sort2(int a[], int ac)
{
    /*use swap*/

    /* pivot is a position, 
       all the elements before pivot is smaller or equal to pvalue */
    int pivot;
    /* the position of the element to be tested against pivot */
    int sample;

    /* select a pvalue.  
       Median is supposed to be a good choice, but that will itself take time.
       here, the pvalue is selected in a very simple wayi: a[ac/2] */
    /* store pvalue at a[0] */
    swap(a+0, a+ac/2);
    pivot = 1; 

    /* test each element */
    for (sample=1; sample<ac; sample++) {
        if (a[sample] < a[0]) {
            swap(a+pivot, a+sample);
            pivot++;
        }
    }
    /* swap an element (which <= pvalue) with a[0] */
    swap(a+0,a+pivot-1);

    /* base case, if only two elements are in the array,
       the above pass has already sorted the array */
    if (ac<=2) return;
    else {
        /* recursion */
        quick_sort(a, pivot);
        quick_sort(a+pivot, ac-pivot);
    }
}

void shell_sort(int a[], int n) {  
	printf("\n[4] : Shell Sort ->\n");
    int i, j, gap;
    for (gap = n / 2; gap > 0; gap /= 2)  
		insert_sort_x(a, n, gap);
}

void shellsort2(int a[], int n) {  
    int i, j, gap;
    for (gap = n / 2; gap > 0; gap /= 2)  
        for (i = gap; i < n; i++)  
            for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)  
                swap(a + j, a + j + gap);  
}

/*find the smallest of the rest,
  then append to the sorted part*/
void select_sort(int a[], int ac) 
{
	printf("\n[3] : Select Sort ->\n");
    /*use swap*/
    int i,j;
    int min_idx;
    for (j = 0; j < ac-1; j++) 
    {
        min_idx = j;
        for (i = j+1; i < ac; i++) 
        {
            if (a[i] < a[min_idx]) 
            {
                min_idx = i;
            }
        }
        swap(a+j, a+min_idx);
    }    
}

/* default x = 1 */
void insert_sort_x(int a[], int n, int x) {
	int i, j;
	for (i = x; i < n; i++)
		for (j = i - x; j >= 0 && a[j] > a[j + x]; j -= x)
			swap(a + j, a + j + x);
}


/*insert the next element 
  into the sorted part*/
void insert_sort(int a[], int ac) {
	printf("\n[2] : Insert Sort ->\n");
    /*use swap*/
    int i,j;    
    for (j=1; j < ac; j++) 
    {
        i = j-1;
        while((i>=0) && (a[i+1] < a[i])) 
        {
            swap(a+i+1, a+i);
            i--;
        }
    }
}

/*swap the neighbors if out of order*/
void bubble_sort(int a[], int ac) {
	printf("\n[1] : Bubble Sort ->\n");
    /*use swap*/
    int i,j;
    int sign;
    for (j = 0; j < ac-1; j++) {
        sign = 0;
        for(i = ac-1; i > j; i--)
        {
            if(a[i-1] > a[i]) {
                sign = 1;
                swap(a+i, a+i-1);
            }
        }
        if (sign == 0) break;
    }
}

void printArray(int arr[], int size) {
	printf("\n\nPrint Array : \n ");
	int i;
	for (i = 0; i < size; i++) {
		printf("[%d]: %d \n",i, arr[i]);
	}
}

void initArray(int array[], int size) {
	srand(time(0));
	int i;
	for (i = 0; i < size; i++) {
		array[i] = rand() % size + 1;
	}
}

/* exchange the values pointed by pa and pb*/
void swap(int *pa, int *pb)
{
    int tmp;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}
