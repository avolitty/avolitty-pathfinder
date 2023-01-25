#include <stdio.h>

static void AvolittyPathfinderA(unsigned long int *a, unsigned long int *b, unsigned long int *c, unsigned long int *d, unsigned long int e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned long int j, unsigned char *k, unsigned char l) {
	/*
		*a -> [array] traversal direction increments
		*b -> [integer] cur pos
		*c -> [integer] cur pos height
                *d -> [integer] cur pos width
		e -> [integer] grid height
                f -> [integer] grid width
                g -> [integer] grid length
                h -> [integer] dst pos
                i -> [integer] dst height
                j -> [integer] dst width
                *k -> [array] grid
                l -> [integer] 0[main]|1[recursive]|2[debug] recursive status
	*/
	unsigned long int m;
	unsigned long int n;
	unsigned long int o;
	unsigned long int p;
	unsigned long int q;
	unsigned long int r;
	unsigned long int s;
	unsigned long int t;
	unsigned char u = 0U;
	unsigned char v;
	m = *b;
	n = m;
	o = *c;
	p = *d;
	v = ((unsigned char) (i > o));

	if (i == o) {
		v += 2U;
	}

	if (j > p) {
		v += 4U;
	}

	if (j == p) {
		v += 8U;
	}

	q = a[v];

	/*
		these cur pos [q] increments and decrements should
			apply non-diagonal traversal after diagonal traversal passes dst width or height before mapping traversal steps
			apply 1-step traversal if first step is an obstacle to prevent infinite loops
	*/

	printf("traversal direction key %u\n", v);

	if (((v & 1U) == 0U) && (v != 6U)) {
		if ((v == 2U) || (v == 8U)) {
			while (k[m] != 3U) {
				m -= q;
			}
		} else {
			if (v == 4U) {
				while ((k[m] != 3U) & (i != o) && (j != p)) {
					m -= q;
					o--;
					p++;
				}
			} else {
				while ((k[m] != 3U) && (i != o) && (j != p)) {
					m -= q;
					o--;
					p--;
				}
			}
		}
	} else {
		u = 1U;

		if ((v == 6U) || (v == 9U)) {
			while (k[m] != 3U) {
				m += q;
			}
		} else {
			if (v == 1U) {
				while ((k[m] != 3U) && (i != o) && (j != p)) {
					m += p;
					o++;
					p--;
				}
			} else {
				while ((k[m] != 3U) && (i != o) && (j != p)) {
					m += q;
					o++;
					p++;
				}
			}
		}
	}

	if (k[m] != 3U) {
		*b = m;
		*c = o;
		*d = p;
		AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, (unsigned char) 2U);
		m = *b;
		o = *c;
		p = *d;
	}

	if (l == 2U) {
		*b = m;
		*c = o;
		*d = p;
		return;
	}

	s = o;
	t = p;
	printf("Traversal cur pos: %lu\n", m);

	if (h == m) {
		/* applying non-obstacle traversal to grid */

		if (u == 0U) {
			while (e != m) {
				m += q;
				k[m] = 8U;
			}
		} else {
			while (e != m) {
				m -= p;
				k[m] = 8U;
			}
		}

		*b = h;
		i = o;
		j = p;
	} else {
		/* traversing obstacles for recursive split dst (visualizing to simplify from patterns)
			[traversal direction]
				[split obstacle directions to set new destinations [alternate obstacle direction if first step in direction isn't an obstacle]]
					new destination is ignored if traversal direction is towards cur pos
				[perpendicular obstacle direction to traverse with each step (mapped to previous directions) []]
					adjusted dst position is 1 step in direction of a in [a [b]]
											     [c [a]]
					perpendicular step is ignored if height or width is the same as dst height or width (depending on traversal direction)
					new src is set with 1 diagonal step towards dst (with polarity to collision dst) if traversed obstacle dst is the src pos
					original split obstacle direction is also traversed while traversing perpendicular obstacle direction
		*/

		q = a[8U];

		if (u == 0U) {
			if ((v == 2U) || (v == 8U)) {
				if (v == 2U) {
					/* [left]
						[up [left]   + down [left]]
						[right [up]  + right [down]] */
				} else {
					/* [up]
						[left [up]    + right [up]]
						[down [left]  + down [right]] */
				}
			} else {
				if (v == 4U) {
					/* [up right]
						[left [up]    + down [right]]
						[down [left]  + left [down]] */
				} else {
					/* [up left]
						[right [up]    + down [left]]
						[down [right]  + right [down]] */
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
					/*
					  [down right]
						[up [right] + left [down]]
						[left [up]  + up [left]]
					*/
					r = (m - q);

					if ((k[r] == 3U) && (o != 0UL)) {
						/* first direction is up */

						while ((k[r] == 3U) && (o != 0UL) && (p != 0UL)) {
							r--;

							if (k[r] == 3U) {
								/* perpendicular first direction is left */
								p--;
							} else {
								o--;
								r -= (q - 1UL);
							}
						}

						u = ((unsigned char) ((o == 0UL) || (p == 0UL)));
					} else {
						/* alternate first direction is right */
						r = (m + 1UL);

						while ((k[r] == 3U) && (o != 0UL) && (f != p)) {
							if (k[(r - q)] == 3U) {
								/* perpendicular alternate first direction is up */
								o--;
								r -= q;
							} else {
								p++;
								r++;
							}
						}

						u = ((unsigned char) ((o == 0UL) || (f == p)));
					}

					if (u == 0U) {
						k[r] = 2U; /* temporary */
						*b = r;
						*c = o;
						*d = p;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, (unsigned char) 1U);

						if (l == 0U) {
							printf("First split dst from obstacle traversal after obstacle collision: %lu\n", *b);
						}
					}

					o = s;
					p = t;
					r = (m - 1UL);

					if ((k[r] == 3U) && (p != 0UL)) {
						/* second direction is left */

						while ((k[r] == 3U) && (o != 0UL) && (p != 0UL)) {
							if (k[(r - q)] == 3U) {
								/* perpendicular second direction is up */
								o--;
								r -= q;
							} else {
								p--;
								r--;
							}
						}

						u = ((unsigned char) ((o == 0UL) || (p == 0UL)));
					} else {
						/* alternate second direction is down */
						r = (m + q);

						while ((k[r] == 3U) && (e != o) && (p != 0UL)) {
							r--;

							if (k[r] == 3U) {
								/* perpendicular alternate second direction is left */
								p--;
							} else {
								o++;
								r += (q + 1UL);
							}
						}

						u = ((unsigned char) ((e == o) || (p == 0UL)));
					}

					if (u == 0U) {
						k[r] = 2U; /* temporary */
						*b = r;
						*c = o;
						*d = p;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, (unsigned char) 1U);

						if (l == 0U) {
							printf("Second split dst from obstacle traversal after obstacle collision: %lu\n", *b);
							printf("Original src: %lu\n", n);
							AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, (unsigned char) 1U);
						}
					}

					/* .. */
				}
			}
		}
	}

	/* debug grid output */
	if (l == 0U) {
		m = g;
		n = 0UL;
		printf("%u ", k[n++]);

		while (m != n) {
			printf("%u ", k[n]);

			if (((n++ + 1UL) % 10UL) == 0UL) {
				printf("\n");
			}
		}

		printf("\n");
	}

	/* .. */
	return;
}

void AvolittyPathfinderB() {
	/* grid output finalization with either random or shortest traversal based on each mapped path from AvolittyPathfinderA */
	return;
}

void AvolittyPathfinder(unsigned long int a, unsigned long int b, unsigned char *c) {
	unsigned long int d[10U] = {0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 1UL, 0UL, 0UL, 0UL};
	unsigned long int e = a * b;
	unsigned long int f = e;
	unsigned long int g = 0UL;
	unsigned long int h = 0UL;
	unsigned long int i;
	unsigned long int j;
	unsigned long int k;
	unsigned long int *l = &e;
	unsigned long int *m = &g;
	unsigned long int *n = &h;

	while (e != 0UL) {
		e--;
		d[c[e]] = e;
	}

	e = d[1U];
	g = (e / a);
	h = (e - ((e / b) * 10UL));
	i = d[2U];
	c[i] = 3U;
	d[0U] = (a + 1UL);
	d[1U] = (a - 1UL);
	d[2U] = 1UL;
	d[3U] = 0UL;
	d[4U] = (a - 1UL);
	d[5U] = (a + 1UL);
	d[8U] = a;
	d[9U] = a;
	j = (i / a);
	k = (i - ((i / b) * 10UL));
	AvolittyPathfinderA(d, l, m, n, a, b, f, i, j, k, c, (unsigned char) 0U);
	AvolittyPathfinderB();
	return;
}
