#include <stdio.h>

static void AvolittyPathfinderA(unsigned long int *a, unsigned long int *b, unsigned long int *c, unsigned long int *d, signed long int *e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned long int j, unsigned long int k, unsigned long int l, unsigned char *m, unsigned char *n, unsigned char o) {
	/*
		a -> [array] cur pos
		b -> [array] cur pos heights
		c -> [array] cur pos widths
		d -> [integer] length of cur pos array
		e -> [array] traversal direction increments
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
	unsigned long int p = *d;
	unsigned long int q = 0UL;
	unsigned long int r = 0UL;
	unsigned long int s;
	unsigned long int t;
	unsigned long int u;
	signed long int v;
	unsigned char w;

	while (p != 0UL) {
		p--;
		w = b[p] < f;

		if (b[p] == f) {
			w += 2U;
		}

		if (c[p] < g) {
			w += 4U;
		}

		if (c[p] == g) {
			w += 8U;
		}

		s = a[p];
		v = e[w];

		if (v < 0L) {
			r = ((unsigned long int) (~v)) + 1UL;
			t = s / h;
			u = s - ((s / i) * 10UL);

			while (m[s] != 3U && f != t && g != u) {
				s -= r;
				t = s / h;
				u = s - ((s / i) * 10UL);
			}
		} else {
			q = (unsigned long int) v;
			t = s / h;
			u = s - ((s / i) * 10UL);

			while (m[s] != 3U && f != t && g != u) {
				s += q;
				t = s / h;
				u = s - ((s / i) * 10UL);
			}
		}

		printf("Traversal cur pos after obstacle collision: %lu\n", s);

		/*
			non-diagonal keys in existing direction increment array
				2 - left
				6 - right
				8 - up
				9 - down
			obstacle traversal with re-routed destinations using AvolittyPathfinderA recursive arg goes here
		 */

		if (s == l) {
			if (q == 0UL) {
				while (a[p] != s) {
					s += r;
					m[s] = 8U;
				}
			} else {
				while (a[p] != s) {
					s -= q;
					m[s] = 8U;
				}
			}

			a[p] = l;
			b[p] = t;
			c[p] = u;

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

			if (((r + 1) % 10) == 0) {
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
	signed long int h[10U] = {0L, 0L, 0L, 0L, 0L, 0L, 1L, 0L, (~d) + 1L, d};
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
	a[0] = i;
	b[0] = i / d;
	c[0] = i - ((i / e) * 10UL);
	l = h[2U];
	f[l] = 3U;
	h[0U] = h[8U] - 1L;
	h[1U] = h[9U] - 1L;
	h[2U] = -1L;
	h[3U] = 0L;
	h[4U] = h[8U] + 1L;
	h[5U] = h[9U] + 1L;
	m = l / d;
	n = l - ((l / e) * 10UL);

	while (p == 0U) {
		/*
			a -> [array] cur pos
			b -> [array] cur pos heights
			c -> [array] cur pos widths
			o -> [integer] length of cur pos array
			h -> [array] traversal direction increments
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

		AvolittyPathfinderA(a, b, c, o, h, m, n, d, e, i, j, l, f, q, p);
	}

	return;
}
