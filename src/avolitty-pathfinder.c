#include <stdio.h>

unsigned long int AvolittyPathfinderA(unsigned long int * a, unsigned long int b, unsigned long int c, unsigned long int d, unsigned long int e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned long int j, unsigned char * k) {
	/*
		* a -> [array] traversal direction increments
		b -> [integer] dst pos
		c -> [integer] cur dst pos
		d -> [integer] grid length
		e -> [integer] traversal steps
		f -> [integer] cur dst height
		g -> [integer] cur dst width
		h -> [integer] src pos
		i -> [integer] src height
		j -> [integer] src width
		* k -> [array] grid
	*/

	unsigned long int l;
	unsigned long int m;
	unsigned long int n;
	unsigned long int o;
	unsigned char p;
	unsigned char q;
	unsigned char r;
	unsigned char s;
	unsigned char t;
	unsigned char u;
	unsigned char v;
	unsigned char w;
	unsigned char x;
	unsigned char y;
	l = i;
	m = j;
	n = ((unsigned long int) 9UL);
	p = ((unsigned char) (b > i));
	q = ((unsigned char) 12U);
	r = ((unsigned char) 9U);
	s = ((unsigned char) 8U);
	t = ((unsigned char) 6U);
	u = ((unsigned char) 4U);
	v = ((unsigned char) 3U);
	w = ((unsigned char) 2U);
	x = ((unsigned char) 1U);
	y = ((unsigned char) 0U);

	if (b == i) {
		p += w;
	}

	if (g > j) {
		p += u;
	}

	if (g == j) {
		p += s;
	}

	o = a[p];

	if (((p & x) == y) && (p != t)) {
		if ((p == w) || (p == s)) {
			if (p == w) {
				while (((k[h] & n) != y) && (g != j)) {
					h -= o;
					g--;

					/* k[h] = s; */
				}
			} else {
				while (((k[h] & n) != y) && (f != i)) {
					h -= o;
					f--;
				}
			}
		} else {
			if (p == u) {
				while (((k[h] & n) != y) && (f != i) && (g != j)) {
					h -= o;
					f--;
					g++;
				}
			} else {
				while (((k[h] & n) != y) && (f != i) && (g != j)) {
					h -= o;
					f--;
					g--;
				}
			}
		}
	} else {

		w = v;

		if ((p == t) || (p == r)) {
			if (p == t) {
				while (((k[h] & n) != y) && (g != j)) {
					h += o;
					g++;
				}
			} else {
				while (((k[h] & n) != y) && (f != i)) {
					h += o;
					f++;
				}
			}
		} else {
			if (p == x) {
				while (((k[h] & n) != y) && (f != i) && (g != j)) {
					h += o;
					f++;
					g--;
				}
			} else {
				while (((k[h] & n) != y) && (f != i) && (g != j)) {
					h += o;
					f++;
					g++;
				}
			}
		}
	}

	/* .. */
	return f;
}

unsigned long int AvolittyPathfinderB(unsigned long int * a, unsigned long int b, unsigned long int c, unsigned long int d, unsigned long int e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned char * j) {
	/*
		* a -> [array] traversal direction increments
		b -> [integer] dst pos
		c -> [integer] grid length
		d -> [integer] traversal steps
		e -> [integer] dst height
		f -> [integer] dst width
		g -> [integer] src pos
		h -> [integer] src height
		i -> [integer] src width
		* j -> [array] grid
	*/
	unsigned long int k;
	unsigned long int l;
	unsigned long int m;
	unsigned long int n;
	unsigned char o;
	k = c;
	l = c;
	m = ((unsigned long int) 0UL);
	n = ((unsigned char) 1U);

	while (k != m) {
		k--;

		if ((j[k] == n) && (g != k)) {

			d = AvolittyPathfinderA(a, b, b, c, d, e, f, g, h, i, j);

			if ((d < l) && (d != m)) {
				l = d;

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
	return d;
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
	g = AvolittyPathfinderB(d, e, f, g, i, j, k, l, m, c);

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
