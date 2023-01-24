#include <stdio.h>

static void AvolittyPathfinderA(unsigned long int *a, unsigned long int b, unsigned long int c, unsigned long int d, unsigned long int e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned long int j, unsigned char *k, unsigned char l) {
	/*
		a -> [array] traversal direction increments
		b -> [integer] grid height
		c -> [integer] grid width
		d -> [integer] cur pos
		e -> [integer] grid length
		f -> [integer] cur pos height
		g -> [integer] cur pos width
		h -> [integer] dst pos
		i -> [integer] dst height
		j -> [integer] dst width
		k -> [array] grid
		l -> [integer] 0|1 recursive status
	*/
	unsigned long int m;
	unsigned long int n;
	unsigned long int o;
	unsigned long int p;
	unsigned long int q;
	unsigned long int r;
	unsigned long int s;
	unsigned char t = 0U;
	unsigned char u;
	m = d;
	n = f;
	o = g;
	u = ((unsigned char) (i > n));

	if (i == n) {
		u += 2U;
	}

	if (j > o) {
		u += 4U;
	}

	if (j == o) {
		u += 8U;
	}

	p = a[u];

	/*
		these cur pos [q] increments and decrements should
			apply non-diagonal traversal after diagonal traversal passes dst width or height before mapping traversal steps
			apply 1-step traversal if first step is an obstacle to prevent infinite loops
	*/

	if (((u & 1U) == 0U) && (u != 6U)) {
		if ((u == 2U) || (u == 8U)) {
			while (k[m] != 3U) {
				m -= p;
			}
		} else {
			if (u == 4U) {
				while ((k[m] != 3U) & (i != n) && (j != o)) {
					m -= p;
					n--;
					o++;
				}
			} else {
				while ((k[m] != 3U) && (i != n) && (j != o)) {
					m -= p;
					n--;
					o--;
				}
			}
		}
	} else {
		t = 1U;

		if ((u == 6U) || (u == 9U)) {
			while (k[m] != 3U) {
				m += p;
			}
		} else {
			if (u == 1U) {
				while ((k[m] != 3U) && (i != n) && (j != o)) {
					m += p;
					n++;
					o--;
				}
			} else {
				while ((k[m] != 3U) && (i != n) && (j != o)) {
					m += p;
					n++;
					o++;
				}
			}
		}
	}

	r = n;
	s = o;
	printf("Traversal cur pos after obstacle collision: %lu\n", m);

	if (h == m) {
		/* applying non-obstacle traversal to grid */

		if (t == 0U) {
			while (b != m) {
				m += p;
				k[m] = 8U;
			}
		} else {
			while (b != m) {
				m -= p;
				k[m] = 8U;
			}
		}

		d = h;
		i = n;
		j = o;
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

		p = a[8U];

		if (t == 0U) {
			if ((u == 2U) || (u == 8U)) {
				if (u == 2U) {
					/* [left]
						[up [left]   + down [left]]
						[right [up]  + right [down]] */
				} else {
					/* [up]
						[left [up]    + right [up]]
						[down [left]  + down [right]] */
				}
			} else {
				if (u == 4U) {
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
			if ((u == 6U) || (u == 9U)) {
				if (u == 6U) {
					/* [right]
						[up [right] + down [right]]
						[left [up]  + left [down]] */
				} else {
					/* [down]
						[left [down] + right [down]]
						[up [left]   + up [right]] */
				}
			} else {
				if (u == 1U) {
					/* [down left]
						[up [left]  + right [down]]
						[right [up] + up [right]] */
				} else {
					/*
					  [down right]
						[up [right] + left [down]]
						[left [up]  + up [left]]
					*/
					q = (m - p);

					if ((k[q] == 3U) && (n != 0UL)) {
						/* first direction is up */

						while ((k[q] == 3U) && (n != 0UL) && (o != 0UL)) {
							q--;

							if (k[q] == 3U) {
								/* perpendicular first direction is left */
								o--;
							} else {
								n--;
								q -= (p - 1UL);
							}
						}

						t = ((unsigned char) ((n == 0UL) || (o == 0UL)));
					} else {
						/* alternate first direction is right */
						q = (m + 1UL);

						while ((k[q] == 3U) && (n != 0UL) && (c != o)) {
							if (k[(q - p)] == 3U) {
								/* perpendicular alternate first direction is up */
								n--;
								q -= p;
							} else {
								o++;
								q++;
							}
						}

						t = ((unsigned char) ((n == 0UL) || (c == o)));
					}

					if (t == 0U) {
						k[q] = 2U; /* temporary */
						printf("First split dst from obstacle traversal after obstacle collision: %lu\n", q);
					}

					n = r;
					o = s;
					q = (m - 1UL);

					if ((k[q] == 3U) && (o != 0UL)) {
						/* second direction is left */

						while ((k[q] == 3U) && (n != 0UL) && (o != 0UL)) {
							if (k[(q - p)] == 3U) {
								/* perpendicular second direction is up */
								n--;
								q -= p;
							} else {
								o--;
								q--;
							}
						}

						t = ((unsigned char) ((n == 0UL) || (o == 0UL)));
					} else {
						/* alternate second direction is down */
						q = (m + p);

						while ((k[q] == 3U) && (b != n) && (o != 0UL)) {
							q--;

							if (k[q] == 3U) {
								/* perpendicular alternate second direction is left */
								o--;
							} else {
								n++;
								q += (p + 1UL);
							}
						}

						t = ((unsigned char) ((b == n) || (o == 0UL)));
					}

					if (t == 0U) {
						k[q] = 2U; /* temporary */
						printf("Second split dst from obstacle traversal after obstacle collision: %lu\n", q);
					}

					/* .. */
				}
			}
		}
	}

	/* debug grid output */
	m = e;
	n = 0UL;
	printf("%u ", k[n++]);

	while (m != n) {
		printf("%u ", k[n]);

		if (((n++ + 1UL) % 10UL) == 0UL) {
			printf("\n");
		}
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
	unsigned long int g;
	unsigned long int h;
	unsigned long int i;
	unsigned long int j;
	unsigned long int k;

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
	AvolittyPathfinderA(d, a, b, e, f, g, h, i, j, k, c, (unsigned char) 0U);
	AvolittyPathfinderB();
	return;
}
