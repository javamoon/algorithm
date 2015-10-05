#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int heap[100];
	int i;
	srand(time(0));
	for (i = 0; i < 100; i++) {
			heap[i] = rand() % 100;
//			printf("%d, %d\n", i, heap[i]);
	}

	int j = 0;
	int gap = 15;
	j -= gap;
	printf("%d \n", j);

	return 0;
}
