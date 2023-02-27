#include <stdio.h>
#include "../src/avolitty-pathfinder.h"

int main(void) {
	unsigned long int a;
	unsigned long int b;
	unsigned long int c;
	unsigned long int d;
	unsigned long int e;
	unsigned long int f;
	unsigned char g[((unsigned long int) 165UL)] = {
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
		2U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
	};
	a = ((unsigned long int) 15UL);
	b = ((unsigned long int) 11UL);
	c = ((unsigned long int) 1UL);
	d = ((unsigned long int) 0UL);
	e = d;
	f = AvolittyPathfinder(a, b, g);
	a *= b;
	printf("%u ", g[e++]);

	while (a != e) {
		printf("%u ", g[e]);

		if (((c + e) % b) == d) {
			printf("\n");
		}

		e++;
	}

	return 0;
}
