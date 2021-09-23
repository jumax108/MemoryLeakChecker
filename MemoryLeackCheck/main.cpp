#include <stdio.h>
#include <windows.h>
#include <malloc.h>
#include <memory.h>
#include <time.h>
#include <string.h>
#include "MemoryLeakCheck.h"

int main() {


	int* a = new int[3];
	int* b = new int;
	int* c = new int;
	int* d = new int;
	int* e = new int;
	int* f = new int;
	int* g = new int;
	int* h = new int;
	int* i = new int;
	int* j = new int;
	int* k = new int;

	delete[] a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
	delete h;
	delete i;
	delete j;
	delete k;

	mlc->~MemoryLeakChecker();
	free(mlc);
	return 0;
}