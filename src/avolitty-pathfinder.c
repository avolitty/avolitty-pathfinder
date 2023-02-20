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
	p = ((unsigned char) (f > i));
	q = ((unsigned char) 12U);
	r = ((unsigned char) 9U);
	s = ((unsigned char) 8U);
	t = ((unsigned char) 6U);
	u = ((unsigned char) 4U);
	v = ((unsigned char) 3U);
	w = ((unsigned char) 2U);
	x = ((unsigned char) 1U);
	y = ((unsigned char) 0U);

	if (f == i) {
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
				while ((k[h] < u) && (g != j)) {
					g--;
					k[h] += s;
					h -= o;
				}
			} else {
				while ((k[h] < u) && (f != i)) {
					f--;
					k[h] += s;
					h -= o;
				}
			}
		} else {
			if (p == u) {
				while ((k[h] < u) && (f != i) && (g != j)) {
					f--;
					g++;
					k[h] += s;
					h -= o;
				}
			} else {
				while ((k[h] < u) && (f != i) && (g != j)) {
					f--;
					g--;
					k[h] += s;
					h -= o;
				}
			}
		}
	} else {
		h += o;
		w = v;

		if ((p == t) || (p == r)) {
			if (p == t) {
				while ((k[h] < u) && (g != j)) {
					g++;
					k[h] += s;
					h += o;
				}
			} else {
				while ((k[h] < u) && (f != i)) {
					f++;
					k[h] += s;
					h += o;
				}
			}
		} else {
			if (p == x) {
				while ((k[h] < u) && (f != i) && (g != j)) {
					f++;
					g--;
					k[h] += s;
					h += o;
				}
			} else {
				f++;
				g++;

				while ((k[h] < u) && (f != i) && (g != j)) {
					f++;
					g++;
					k[h] += s;
					h += o;
				}
			}
		}
	}

	/*
		Traversing spaces recursively until an obstacle, temporary traversed space or destination position is reached.
		Reverse path is traversed to reset spaces if obstacle is reached [for memory-efficient storage of path trees within grid array].
	*/
	return e;
}

unsigned long int AvolittyPathfinderB(unsigned long int * a, unsigned long int q, unsigned long int b, unsigned long int c, unsigned long int d, unsigned long int e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned char * j) {
	/*
		* a -> [array] traversal direction increments
		q -> [integer] grid width
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
	unsigned long int o;
	unsigned char p;
	k = c;
	l = c;
	o = ((unsigned long int) 0UL);
	p = ((unsigned char) 5U);

	while (k != o) {
		k--;

		if ((j[k] == p)) {
			m = (k / q);
			n = (k % q);
			d = AvolittyPathfinderA(a, b, k, c, d, m, n, g, h, i, j);

			if ((d < l) && (d != o)) {
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

			/* debugging */
			k = o;
		}
	}

	/* Converting steps with value of 5 to finalized path step if adjacent to a finalized path step. */
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
	unsigned char t;
	e = (a * b);
	f = e;
	g = ((unsigned long int) 1UL);
	h = ((unsigned long int) 0UL);
	o = ((unsigned char) 5U);
	p = ((unsigned char) 4U);
	q = ((unsigned char) 6U);
	r = ((unsigned char) 2U);
	s = ((unsigned char) 1U);
	t = ((unsigned char) 0U);

	while (e != h) {
		e--;
		i = c[e];
		d[i] = e;

		if (i == q) {
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

			if (((c[k] != q) || (c[m] != q)) && ((c[l] != q) || (c[n] != q))) {
				if (c[k] != q) {
					c[k] = o;
				}

				if (c[l] != q) {
					c[l] = o;
				}

				if (c[m] != q) {
					c[m] = o;
				}

				if (c[n] != q) {
					c[n] = o;
				}
			}
		}
	}

	e = d[r];
	c[e] = o;
	i = (e / b);
	j = (e % b);
	k = d[s];
	c[k] = o;
	l = (k / b);
	m = (k % b);
	d[p] = k;
	d[q] = a;
	d[r] = g;
	d[s] = (b - g);
	d[t] = (b + g);
	d[((unsigned char) 5U)] = d[t];
	d[((unsigned char) 6U)] = g;
	d[((unsigned char) 7U)] = a;
	d[((unsigned char) 8U)] = b;
	d[((unsigned char) 9U)] = b;
	g--;

	/*
		* d -> [array] traversal direction increments
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
	g = AvolittyPathfinderB(d, b, e, f, g, i, j, k, l, m, c);

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
