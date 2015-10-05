#include <stdio.h>

int sumTest(int);
int sumTest2(int);
void testPrint(void *, int);
typedef int (*PFtype)(int);
PFtype getFn(void *);

int main() {
	int v;
	scanf("%d", &v);
	testPrint(sumTest, v);
	testPrint(sumTest2, v);
}

int sumTest(int x) {
	return x + 5;
}

int sumTest2(int x) {
	return x + x;
}

void testPrint(void *pfn, int x) {
    printf("PRINT -> [%d] \n", getFn(pfn)(x));
}

PFtype getFn(void *f) {
	return (PFtype) f;
}
