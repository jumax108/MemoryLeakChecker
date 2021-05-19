#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <time.h>
#include <string.h>
#include "MemoryLeakCheck.h"

int main() {


	int* a = new int;
	int* b = new int;

	delete a;
	delete b;

	mlc->~MemoryLeakChecker();
	free(mlc);
	return 0;
}