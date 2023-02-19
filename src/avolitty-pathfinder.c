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
	unsigned char q;
	unsigned char r;
	e = (a * b);
	f = e;
	g = ((unsigned long int) 0UL);
	n = ((unsigned char) 4U);
	o = ((unsigned char) 3U);
	p = ((unsigned char) 2U);
	q = ((unsigned char) 1U);
	r = ((unsigned char) 0U);

	while (e != g) {
		e--;
		h = c[e];
		d[h] = e;

		if (h == o) {
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

			if (((c[j] != o) || (c[l] != o)) && ((c[k] != o) || (c[m] != o))) {
				if (c[j] != o) {
					c[j] = n;
				}

				if (c[k] != o) {
					c[k] = n;
				}

				if (c[l] != o) {
					c[l] = n;
				}

				if (c[m] != o) {
					c[m] = n;
				}
			}
		}
	}

	e = d[p];
	c[e] = n;
	h = d[q];
	c[h] = n;
	g++;
	d[n] = d[q];
	d[o] = a;
	d[p] = g;
	d[q] = (b - g);
	d[r] = (b + g);
	d[((unsigned char) 5U)] = d[r];
	d[((unsigned char) 6U)] = g;
	d[((unsigned char) 7U)] = a;
	d[((unsigned char) 8U)] = b;
	d[((unsigned char) 9U)] = b;
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
	AvolittyPathfinderA();
	printf("\n");
	/* .. */
	return;
}
