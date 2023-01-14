#include <stdio.h>
#include "../src/avolitty-pathfinder.h"

int main(void) {
	int a = 0;
	unsigned long int b[9UL];
	unsigned long int c = 10UL;
	unsigned long int d = 9UL;
	unsigned char e[90UL] = {
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 3, 3, 3, 3, 3, 3, 0, 0,
		0, 0, 3, 0, 0, 0, 0, 3, 0, 0,
		0, 0, 3, 0, 0, 0, 0, 3, 3, 0,
		0, 3, 3, 0, 0, 3, 0, 0, 0, 0,
		0, 3, 0, 0, 0, 3, 0, 3, 3, 3,
		0, 3, 0, 3, 0, 3, 0, 3, 0, 0,
		0, 0, 0, 3, 0, 3, 0, 3, 0, 0,
		0, 0, 0, 0, 0, 3, 0, 0, 0, 2
	};
	unsigned char f = 0;
	AvolittyPathfinder(b, c, d, e, f);
	return a;
}
