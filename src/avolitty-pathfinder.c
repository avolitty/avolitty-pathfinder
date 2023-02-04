#include <stdio.h>
#include <stdlib.h>

static void AvolittyPathfinderA(unsigned long int *a, unsigned long int *b, unsigned long int *c, unsigned long int *d, unsigned long int *e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned long int j, unsigned long int k, unsigned char *l, unsigned char m) {
	/*
		*a -> [array] obstacle traversal destinations for constellation mapping
		*b -> [array] traversal direction increments
		*c -> [integer] cur pos
		*d -> [integer] cur pos height
		*e -> [integer] cur pos width
		f -> [integer] grid height
		g -> [integer] grid width
		h -> [integer] grid length
		i -> [integer] dst pos
		j -> [integer] dst height
		k -> [integer] dst width
		*l -> [array] grid
		m -> [integer] 0[main]|1[recursive]|2[debug] recursive status
	*/

	unsigned long int n;
	unsigned long int o;
	unsigned long int p;
	unsigned long int q;
	unsigned long int r;
	unsigned long int s;
	unsigned long int t;
	unsigned long int u;
	unsigned char v;
	unsigned char w;
	n = *c;
	m = o;
	p = *d;
	q = *e;
	v = ((unsigned char) (j > p));
	w = ((unsigned char) 0U);

	if (j == p) {
		v += ((unsigned char) 2U);
	}

	if (k > q) {
		v += ((unsigned char) 4U);
	}

	if (k == q) {
		v += ((unsigned char) 8U);
	}

	r = b[v];

	/*
		these cur pos [q] increments and decrements should
			apply non-diagonal traversal after diagonal traversal passes dst width or height before mapping traversal steps
			apply 1-step traversal if first step is an obstacle to prevent infinite loops
	*/

	printf("traversal direction %u\n", r);

	if (((v & 1U) == 0U) && (v != 6U)) {
		if ((v == 2U) || (v == 8U)) {
			while (l[n] != 3U) {
				n -= r;
			}
		} else {
			if (v == 4U) {
				while ((l[n] != 3U) & (j != p) && (k != q)) {
					n -= r;
					p--;
					q++;
				}
			} else {
				while ((l[n] != 3U) && (j != p) && (k != q)) {
					n -= r;
					p--;
					q--;
				}
			}
		}
	} else {
		w = 1U;

		if ((v == 6U) || (v == 9U)) {
			while (l[n] != 3U) {
				n += r;
			}
		} else {
			if (v == 1U) {
				while ((l[n] != 3U) && (j != p) && (k != q)) {
					n += q;
					p++;
					q--;
				}
			} else {
				while ((l[n] != 3U) && (j != p) && (k != q)) {
					n += q;
					p++;
					q++;
				}
			}
		}
	}

	if (l[n] != 3U) {
		/*
		*c = n;
		*d = p;
		*e = q;
		AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, (unsigned char) 2U);
		n = *c;
		p = *d;
		q = *e;
		*/
	}

	if (m == 2U) {
		*c = n;
		*d = p;
		*e = q;
		return;
	}

	t = p;
	u = q;
	printf("Traversal cur pos: %lu\n", n);

	if (i == n) {
		/* applying non-obstacle traversal to grid */

		if (w == 0U) {
			while (f != n) {
				n += r;
				l[n] = 8U;
			}
		} else {
			while (f != n) {
				n -= q;
				l[n] = 8U;
			}
		}

		*c = i;
		j = p;
		k = q;
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

		r = b[8U];

		if (w == 0U) {
			if ((v == 2U) || (v == 8U)) {
				if (v == 2U) {
					/* [left]
						[up [left]   + down [left]]
						[right [up]  + right [down]] */
					printf("left\n");
					return;
				} else {
					/* [up]
						[left [up]    + right [up]]
						[down [left]  + down [right]] */
					printf("up\n");
					return;
				}
			} else {
				if (v == 4U) {
					/*
						[left [up]    + down [right]]
						[down [left]  + left [down]] */
					/*
					printf("obstacle traversal steps after collision from [up right] non-obstacle traversal\n");
					s = (n - 1U);

					if ((l[s] == 3U) && (q != 0UL)) {
						while ((l[s] == 3U) && (f != p) && (q != 0UL)) {
							s += r;

							if (l[s] == 3U) {
								p++;
							} else {
								q--;
								s -= (r + 1UL);
							}
						}

						w = ((unsigned char) ((f == p) || (q == 0UL)));
					} else {
						s = (n - r);

                                                while ((l[s] == 3U) && (p != 0UL) && (q != 0UL)) {
							s--;

							if (l[s] == 3U) {
								q--;
							} else {
								p--;
								s -= (r - 1UL);
							}
						}

						w = ((unsigned char) ((p == 0UL) || (q == 0UL)));
					}

					if (w == 0U) {
						*c = s;
						*d = p;
						*e = q;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, (unsigned char) 1U);
					}

					p = t;
					q = u;
					s = (n + r);

					if ((l[s] == 3U) && (f != p)) {
						while ((l[s] == 3U) && (f != p) && (q != 0UL)) {
							s--;

							if (l[s] == 3U) {
								q--;
							} else {
								p++;
								s += (r + 1UL);
							}
						}

						w = ((unsigned char) ((f == p) || (q == 0UL)));
					} else {
						s = (n + 1UL);

						while ((l[s] == 3U) && (f != p) && (g != q)) {
							s += r;

							if (l[s] == 3U) {
								p++;
							} else {
								q++;
								s -= (r - 1UL);
							}
						}

						w = ((unsigned char) ((f == p) || (g == q)));
					}

					if (w == 0U) {
						*c = s;
						*d = p;
						*e = q;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, (unsigned char) 1U);

						if (m == 0U) {
							printf("Second split dst from obstacle traversal after obstacle collision: %lu\n", *c);
							printf("Original src: %lu\n", o);
							AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, (unsigned char) 1U);
						}
					}
				} else {
					/* [up left]
						[right [up]    + down [left]]
						[down [right]  + right [down]] */
					printf("up left\n");
					return;
				}
			}
		} else {
			if ((v == 6U) || (v == 9U)) {
				if (v == 6U) {
					/* [right]
						[up [right] + down [right]]
						[left [up]  + left [down]] */
					printf("right\n");
					return;
				} else {
					/* [down]
						[left [down] + right [down]]
						[up [left]   + up [right]] */
					printf("down\n");
					return;
				}
			} else {
				if (v == 1U) {
					/* [down left]
						[up [left]  + right [down]]
						[right [up] + up [right]] */
					printf("down left\n");
					return;
				} else {
					/*
						[up [right] + left [down]]
						[left [up]  + up [left]]
					*/
					printf("obstacle traversal steps after collision from [down right] non-obstacle traversal\n");
					s = (n - r);

					if ((l[s] == 3U) && (p != 0UL)) {
						while ((l[s] == 3U) && (p != 0UL) && (q != 0UL)) {
							s--;

							if (l[s] == 3U) {
								q--;
							} else {
								p--;
								s -= (r - 1UL);
							}
						}

						w = ((unsigned char) ((p == 0UL) || (q == 0UL)));
					} else {
						s = (n + 1UL);

						while ((l[s] == 3U) && (p != 0UL) && (g != q)) {
							s -= r;

							if (l[s] == 3U) {
								p--;
							} else {
								q++;
								s += (r + 1UL);
							}
						}

						w = ((unsigned char) ((p == 0UL) || (g == q)));
					}

					if (w == 0U) {
						*c = s;
						*d = p;
						*e = q;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, (unsigned char) 1U);
					}

					p = t;
					q = u;
					s = (n - 1UL);

					if ((l[s] == 3U) && (q != 0UL)) {
						while ((l[s] == 3U) && (p != 0UL) && (q != 0UL)) {
							s -= r;

							if (l[s] == 3U) {
								p--;
							} else {
								q--;
								s += (r - 1UL);
							}
						}

						w = ((unsigned char) ((p == 0UL) || (q == 0UL)));
					} else {
						s = (n + r);

						while ((l[s] == 3U) && (f != p) && (q != 0UL)) {
							s--;

							if (l[s] == 3U) {
								q--;
							} else {
								p++;
								s += (r + 1UL);
							}
						}

						w = ((unsigned char) ((f == p) || (q == 0UL)));
					}

					if (w == 0U) {
						*c = s;
						*d = p;
						*e = q;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, (unsigned char) 1U);

						if (m == 0U) {
							printf("Second split dst from obstacle traversal after obstacle collision: %lu\n", *c);
							printf("Original src: %lu\n", o);
							AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, (unsigned char) 1U);
						}
					}

					/* .. */
				}
			}
		}
	}

	/* debug grid output */
	if (m == 0U) {
		n = h;
		o = 0UL;
		printf("%u ", l[o++]);

		while (n != o) {
			printf("%u ", l[o]);

			if (((o++ + 1UL) % g) == 0UL) {
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
	unsigned long int *n;
	unsigned long int *o;
	unsigned long int *p;
	unsigned long int *q;
	e = (a * b);
	f = e;
	g = ((unsigned long int) 1UL);
	h = ((unsigned long int) 0UL);
	l = ((unsigned long int) 0UL);
	m = l;
	n = calloc((size_t) g, sizeof(a));
	o = &e;
	p = &l;
	q = &m;

	while (e != l) {
		e--;
		d[c[e]] = e;
	}

	e = d[((unsigned char) 1U)];
	n[h] = e;
	l = (e / b);
	m = (e % b);
	i = d[((unsigned char) 2U)];
	c[i] = ((unsigned char) 3U);
	d[((unsigned char) 0U)] = (b + g);
	d[((unsigned char) 1U)] = (b - g);
	d[((unsigned char) 2U)] = g;
	d[((unsigned char) 3U)] = h;
	d[((unsigned char) 4U)] = d[((unsigned char) 1U)];
	d[((unsigned char) 5U)] = d[((unsigned char) 0U)];
	d[((unsigned char) 6U)] = g;
	d[((unsigned char) 7U)] = h;
	d[((unsigned char) 8U)] = b;
	d[((unsigned char) 9U)] = b;
	j = (i / b);
	k = (i % b);
	AvolittyPathfinderA(n, d, o, p, q, a, b, f, i, j, k, c, (unsigned char) 0U);
	AvolittyPathfinderB();

	return;
}
