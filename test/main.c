#include <stdio.h>
#include "../src/avolitty-pathfinder.h"

int main(void) {
	unsigned long int a;
	unsigned long int b;
	unsigned char c[((unsigned long int) 165UL)] = {
		1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U, 0U, 7U, 0U, 0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U, 0U, 7U, 0U, 0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U, 0U, 7U, 0U, 0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U, 0U, 7U, 0U, 0U, 0U, 0U, 0U,
		0U, 0U, 0U, 7U, 7U, 7U, 0U, 7U, 0U, 0U, 0U,
		0U, 0U, 0U, 7U, 0U, 7U, 7U, 7U, 0U, 0U, 0U,
		0U, 0U, 0U, 7U, 0U, 7U, 0U, 0U, 0U, 0U, 0U,
		0U, 7U, 7U, 7U, 7U, 7U, 0U, 0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
		7U, 7U, 7U, 7U, 7U, 0U, 0U, 0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
		0U, 0U, 2U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
	};
	a = ((unsigned long int) 15UL);
	b = ((unsigned long int) 11UL);
	AvolittyPathfinder(a, b, c);
	return 0;
}
