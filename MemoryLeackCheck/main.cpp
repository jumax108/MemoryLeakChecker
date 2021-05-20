#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <time.h>
#include <string.h>
#include "MemoryLeakCheck.h"

int main() {


	int* a = new int[3];
	int* b = new int;

	delete b;

	mlc->~MemoryLeakChecker();
	free(mlc);
	return 0;
}