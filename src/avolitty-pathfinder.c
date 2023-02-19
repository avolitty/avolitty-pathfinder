#include <stdio.h>

unsigned long int AvolittyPathfinderA(unsigned long int * a, unsigned long int b, unsigned long int c, unsigned long int d, unsigned long int e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned long int j, unsigned long int k, unsigned char * l) {
	/* .. */
	return f;
}

unsigned long int AvolittyPathfinderB(unsigned long int * a, unsigned long int b, unsigned long int c, unsigned long int d, unsigned long int e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned long int j, unsigned long int k, unsigned char * l) {
        /*
                * a -> [array] traversal direction increments
                b -> [integer] grid height
                c -> [integer] grid width
                d -> [integer] dst pos
                e -> [integer] grid length
                f -> [integer] traversal steps
                g -> [integer] dst height
                h -> [integer] dst width
                i -> [integer] src pos
                j -> [integer] src height
                k -> [integer] src width
                * l -> [array] grid
        */
	unsigned long int m;
	unsigned long int n;
	unsigned long int o;
	unsigned char p;
	m = e;
	n = ((unsigned long int) 0UL);
	o = e;
	p = ((unsigned char) 1U);

	while (m != n) {
		m--;

		if ((l[m] == o) && (i != m)) {
			f = AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l);

			if ((f < o) && (f != n)) {
				o = f;

				/*
					recursive traversals without redundant memory block
					4 finalized
					8 temporary
					12 overlapped

					re-finalized mask
					while (whole grid)

						4 & 8 -> 0
						8 & 8 -> 8
						12 & 8 -> 8

					while (whole grid)

						if (step == 8) {
							8 >> 1
						}

					reverting to finalized mask

					while (whole grid)
						4 & 7-> 4
						8 & 7-> 0
						12 & 7 -> 4
				*/
			}
		}
	}

	/* converting steps with value of 1 to finalized path step if adjacent to a finalized path step */
	return f;
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
	unsigned long int n;
	unsigned char o;
	unsigned char p;
	unsigned char q;
	unsigned char r;
	unsigned char s;
	e = (a * b);
	f = e;
	g = ((unsigned long int) 1UL);
	h = ((unsigned long int) 0UL);
	o = ((unsigned char) 4U);
	p = ((unsigned char) 3U);
	q = ((unsigned char) 2U);
	r = ((unsigned char) 1U);
	s = ((unsigned char) 0U);

	while (e != h) {
		e--;
		i = c[e];
		d[i] = e;

		if (i == p) {
			i = (e / b);
			j = (e % b);
			k = e;
			l = e;
			m = e;
			n = e;

			if (a != i) {
				k += b;
			}

			if (b != j) {
				l++;
			}

			if (h != i) {
				m -= b;
			}

			if (h != j) {
				n--;
			}

			if (((c[k] != p) || (c[m] != p)) && ((c[l] != p) || (c[n] != p))) {
				if (c[k] != p) {
					c[k] = r;
				}

				if (c[l] != p) {
					c[l] = r;
				}

				if (c[m] != p) {
					c[m] = r;
				}

				if (c[n] != p) {
					c[n] = r;
				}
			}
		}
	}

	e = d[q];
	c[e] = r;
	i = (e / b);
	j = (e % b);
	k = d[r];
	c[k] = r;
	l = (k / b);
	m = (k % b);
	d[o] = d[r];
	d[p] = a;
	d[q] = g;
	d[r] = (b - g);
	d[s] = (b + g);
	d[((unsigned char) 5U)] = d[s];
	d[((unsigned char) 6U)] = g;
	d[((unsigned char) 7U)] = a;
	d[((unsigned char) 8U)] = b;
	d[((unsigned char) 9U)] = b;
	g--;

	/*
		* d -> [array] traversal direction increments
		a -> [integer] grid height
		b -> [integer] grid width
		e -> [integer] dst pos
		f -> [integer] grid length
		g -> [integer] traversal steps
		i -> [integer] dst height
		j -> [integer] dst width
		k -> [integer] src pos
		l -> [integer] src height
		m -> [integer] src width
		* c -> [array] grid
        */
	g = AvolittyPathfinderB(d, a, b, e, f, g, i, j, k, l, m, c);

	/* debug grid output */
	h = 0UL;
	printf("%u ", c[h++]);

	while (f != h) {
		printf("%u ", c[h]);

		if (((h++ + 1UL) % b) == 0UL) {
			printf("\n");
		}
	}

	printf("\n");
	/* .. */
	return;
}
