#include <stdio.h>

void AvolittyPathfinderA() {
	/*
		* a -> [array] traversal direction increments
		* b -> [integer] cur pos
		* c -> [integer] cur pos height
		* d -> [integer] cur pos width
		e -> [integer] grid height
		f -> [integer] grid width
		g -> [integer] grid length
		h -> [integer] dst pos
		i -> [integer] dst height
		j -> [integer] dst width
		* k -> [array] grid
	*/
	return;
}

void AvolittyPathfinder(unsigned long int a, unsigned long int b, unsigned char * c) {
	unsigned long int d[((unsigned char) 10U)];
	unsigned long int e;
	unsigned long int f;
	unsigned long int g;
	unsigned long int h;
	unsigned long int i;
	unsigned long int j;
	unsigned long int k;
	unsigned long int l;
	unsigned long int m;
	unsigned char n;
	unsigned char o;
	unsigned char p;
	e = (a * b);
	f = e;
	g = ((unsigned long int) 0UL);
	n = ((unsigned char) 3U);
	o = ((unsigned char) 2U);
	p = ((unsigned char) 1U);

	while (e != g) {
		e--;
		h = c[e];

		if (h == n) {
			h = (e / b);
			i = (e % b);
			j = e;
			k = e;
			l = e;
			m = e;

			if (a != h) {
				j += b;
			}

			if (b != i) {
				k++;
			}

			if (g != h) {
				l -= b;
			}

			if (g != i) {
				m--;
			}

			if (((c[j] != n) || (c[l] != n)) && ((c[k] != n) || (c[m] != n))) {
				if (c[j] != n) {
					c[j] = o;
				}

				if (c[k] != n) {
					c[k] = o;
				}

				if (c[l] != n) {
					c[l] = o;
				}

				if (c[m] != n) {
					c[m] = o;
				}
			}
		}
	}

	/* debug grid output */
	e = f;
	g = 0UL;
	printf("%u ", c[g++]);

	while (e != g) {
		printf("%u ", c[g]);

		if (((g++ + 1UL) % b) == 0UL) {
			printf("\n");
		}
	}

	AvolittyPathfinderA();
	printf("\n");
	/* .. */
	return;
}
