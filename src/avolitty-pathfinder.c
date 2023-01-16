#include <stdio.h>

static void AvolittyPathfinderA(unsigned long int *a, unsigned long int *b, unsigned long int *c, unsigned long int *d, unsigned long int *e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned long int j, unsigned long int k, unsigned long int l, unsigned char *m, unsigned char *n, unsigned char o) {
	/*
		a -> [array] cur pos
		b -> [array] cur pos heights
		c -> [array] cur pos widths
		d -> [array] traversal direction increments
		e -> [integer] length of cur pos array
		f -> [integer] dst height
		g -> [integer] dst width
		h -> [integer] grid height
		i -> [integer] grid width
		j -> [integer] src pos
		k -> [integer] length of grid
		l -> [integer] dst pos
		m -> [array] grid
		n -> pointer [integer] traversal status 0|1
		o -> recursive argument 0|1
	*/
	unsigned long int p = *e;
	unsigned long int q;
	unsigned long int r;
	unsigned long int s;
	unsigned long int t;
	unsigned char u;

	while (p != 0UL) {
		p--;
		u = b[p] < f;

		if (b[p] == f) {
			u += 2U;
		}

		if (c[p] < g) {
			u += 4U;
		}

		if (c[p] == g) {
			u += 8U;
		}

		q = a[p];
		r = (q / h);
		s = (q - ((q / i) * 10UL));
		t = d[u];

		if (((u & 1) == 0) && (u != 6)) {
			u = 0U;

			if ((f == r) || (g == s)) {
				while (m[q] != 3U) {
					q -= t;
				}
			} else {
				if (t < i) {
					while ((m[q] != 3U) && (f != r) && (g != s)) {
						q -= t;
						r--;
						s++;
					}
				} else {
					while ((m[q] != 3U) && (f != r) && (g != s)) {
						q -= t;
						r--;
						s--;
					}
				}
			}
		} else {
			if ((f == r) || (g == s)) {
				while (m[q] != 3U) {
					q += t;
				}
			} else {
				if (t < i) {
					while ((m[q] != 3U) && (f != r) && (g != s)) {
						q += t;
						r++;
						s--;
					}
				} else {
					while ((m[q] != 3U) && (f != r) && (g != s)) {
						q += t;
						r--;
						s++;
					}
				}
			}
		}

		printf("Traversal cur pos after obstacle collision: %lu\n", q);

		/*
			non-diagonal keys in existing direction increment array
				2 - left
				6 - right
				8 - up
				9 - down
			obstacle traversal with re-routed destinations using AvolittyPathfinderA recursive arg goes here
		 */

		if (q == l) {
			if (u == 0U) {
				while (a[p] != q) {
					q += t;
					m[q] = 8U;
				}
			} else {
				while (a[p] != q) {
					q -= t;
					m[q] = 8U;
				}
			}

			a[p] = l;
			b[p] = r;
			c[p] = s;

			if (o != 0U) {
				*n = 1U;
			}
		}

		/* debug grid output */
		q = k;
		r = 0UL;
		printf("%u ", m[r]);

		while (q != ++r) {
			printf("%u ", m[r]);

			if (((r + 1UL) % 10UL) == 0UL) {
				printf("\n");
			}
		}

		/* .. */
	}

	/* debug loop termination */
	*n = 1U;
	return;
}

void AvolittyPathfinder(unsigned long int *a, unsigned long int *b, unsigned long int *c, unsigned long int d, unsigned long int e, unsigned char *f, unsigned char g) {
	unsigned long int h[10U] = {0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 1UL, 0UL, d, d};
	unsigned long int i = d * e;
	unsigned long int j = i;
	unsigned long int k = 1UL;
	unsigned long int l;
	unsigned long int m;
	unsigned long int n;
	unsigned long int *o = &k;
	unsigned char p = 0U;
	unsigned char *q = &p;

	while (i != 0UL) {
		i--;
		h[f[i]] = i;
	}

	i = h[1U];
	a[0UL] = i;
	b[0UL] = (i / d);
	c[0UL] = (i - ((i / e) * 10UL));
	l = h[2U];
	f[l] = 3U;
	h[0U] = (h[8U] + 1UL);
	h[1U] = (h[9U] - 1UL);
	h[2U] = 1UL;
	h[3U] = 0UL;
	h[4U] = (h[8U] - 1UL);
	h[5U] = (h[9U] + 1UL);
	m = (l / d);
	n = (l - ((l / e) * 10UL));

	while (p == 0U) {
		/*
			a -> [array] cur pos
			b -> [array] cur pos heights
			c -> [array] cur pos widths
			h -> [array] traversal direction increments
			o -> [integer] length of cur pos array
			m -> [integer] dst height
			n -> [integer] dst width
			d -> [integer] grid height
			e -> [integer] grid width
			i -> [integer] src pos
			j -> [integer] length of grid
			l -> [integer] dst pos
			f -> [array] grid
			q -> pointer [integer] traversal status 0|1
		*/

		AvolittyPathfinderA(a, b, c, h, o, m, n, d, e, i, j, l, f, q, p);
	}

	return;
}
