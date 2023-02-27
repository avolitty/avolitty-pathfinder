#include <stdio.h>
#include "../src/avolitty-pathfinder.h"

int main(void) {
	unsigned long int a;
	unsigned long int b;
	unsigned long int c;
	unsigned char d[((unsigned long int) 165UL)] = {
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
		2U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
	};
	a = ((unsigned long int) 15UL);
	b = ((unsigned long int) 11UL);
	c = AvolittyPathfinder(a, b, d);
	printf("%lu spaces traversed", c);
	return 0;
}
