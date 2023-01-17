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
	unsigned char u = 0U;
	unsigned char v;

	while (p != 0UL) {
		p--;
		q = a[p];
                r = b[p];
                s = c[p];
		v = ((unsigned char) (f > r));

		if (f == r) {
			v += 2U;
		}

		if (g > s) {
			v += 4U;
		}

		if (g == s) {
			v += 8U;
		}

		t = d[v];

		if (((v & 1U) == 0) && (v != 6U)) {
			if ((v == 2U) || (v == 8U)) {
				while (m[q] != 3U) {
					q -= t;
				}
			} else {
				if (v == 4U) {
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
			u = 1U;

			if ((v == 6U) || (v == 9U)) {
				while (m[q] != 3U) {
					q += t;
				}
			} else {
				if (v == 1U) {
					while ((m[q] != 3U) && (f != r) && (g != s)) {
						q += t;
						r++;
						s--;
					}
				} else {
					while ((m[q] != 3U) && (f != r) && (g != s)) {
						q += t;
						r++;
						s++;
					}
				}
			}
		}

		printf("Traversal cur pos after obstacle collision: %lu\n", q);

		if (q == l) {
			/* applying non-obstacle traversal to grid */

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
		} else {
			/* traversing obstacles for recursive split dst (visualizing to simplify from patterns)
				[traversal direction]
					[split obstacle directions to set new destinations [nested obstacle direction if first step in direction isn't an obstacle]]
					[perpendicular obstacle direction to traverse with each step (mapped to previous directions) []]
						adjusted dst position is 1 step in direction of a in [a [b]]
												     [c [a]] */

			if (u == 0U) {
				if ((v == 2U) || (v == 8U)) {
					if (v == 2U) {
						/* [left]
							[up [left]  + down [left]]
							[right [up] + right [down]] */
					} else {
						/* [up]
							[left [up]   + right [up]]
							[down [left] + down [right]] */
					}
				} else {
					if (v == 4U) {
						/* [up right]
							[left [up]   + down [right]]
							[down [left] + left [down]] */
					} else {
						/* [up left]
							[right [up]   + down [left]]
							[down [right] + right [down]] */
					}
				}
			} else {
				if ((v == 6U) || (v == 9U)) {
					if (v == 6U) {
						/* [right]
							[up [right] + down [right]]
							[left [up]  + left [down]] */
					} else {
						/* [down]
							[left [down] + right [down]]
							[up [left]   + up [right]] */
					}
				} else {
					if (v == 1U) {
						/* [down left]
							[up [left]  + right [down]]
							[right [up] + up [right]] */
					} else {
						/* [down right]
							[up [right] + left [down]]
							[left [up]  + up [left]] */
					}
				}
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
	unsigned long int h[10U] = {0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 1UL, 0UL, 0UL, 0UL};
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
	h[0U] = (d + 1UL);
	h[1U] = (d - 1UL);
	h[2U] = 1UL;
	h[3U] = 0UL;
	h[4U] = (d - 1UL);
	h[5U] = (d + 1UL);
	h[8U] = d;
	h[9U] = d;
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
