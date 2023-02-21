#include <stdio.h>

void AvolittyPathfinderA(unsigned long int * a, unsigned long int * aa, unsigned long int b, unsigned long int c, unsigned long int d, unsigned long int e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned long int j, unsigned char * k) {
	/*
		* a -> [array] traversal direction increments
		* aa -> [integer] current shortest traversal path length for traversal resetting
		b -> [integer] dst pos
		c -> [integer] grid width
		d -> [integer] grid length
		e -> [integer] traversal steps
		f -> [integer] cur dst height
		g -> [integer] cur dst width
		h -> [integer] src pos
		i -> [integer] src height
		j -> [integer] src width
		* k -> [array] grid

		alphabetizing and deleting unused variables with a maximum of 26 variables per function scope after completing
			using 0 values in a[3] and a[7]
	*/

	unsigned long int ab;
	unsigned long int ac;
	unsigned long int ad;
	unsigned long int ae;
	unsigned long int af;
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
	unsigned char z;
	ab = ((unsigned long int) 0UL);
	e++;
	l = h;
	p = ((unsigned char) (f > i));
	q = ((unsigned char) 5U);
	r = ((unsigned char) 9U);
	s = ((unsigned char) 8U);
	t = ((unsigned char) 6U);
	u = ((unsigned char) 4U);
	v = ((unsigned char) 3U);
	w = ((unsigned char) 2U);
	x = ((unsigned char) 1U);
	y = ((unsigned char) 0U);
	z = ((unsigned char) 0U);

	if (f == i) {
		p += w;
	}

	if (g > j) {
		p += u;
	}

	if (g == j) {
		p += s;
	}

	n = a[p];

	if (((p & x) == z) && (p != t)) {
		h -= n;

		if ((p == w) || (p == s)) {
			if (p == w) {
				j--;

				while ((k[h] < q) && (g != j)) {
					e++;
					j--;
					k[h] += s;
					h -= n;
				}
			} else {
				i--;

				while ((k[h] < q) && (f != i)) {
					e++;
					i--;
					k[h] += s;
					h -= n;
				}
			}
		} else {
			i--;

			if (p == u) {
				j++;

				while ((k[h] < q) && (f != i) && (g != j)) {
					e++;
					i--;
					j++;
					k[h] += s;
					h -= n;
				}
			} else {
				j--;

				while ((k[h] < q) && (f != i) && (g != j)) {
					e++;
					i--;
					j--;
					k[h] += s;
					h -= n;
				}
			}
		}
	} else {
		h += n;
		w = v;

		if ((p == t) || (p == r)) {
			if (p == t) {
				j++;

				while ((k[h] < q) && (g != j)) {
					e++;
					j++;
					k[h] += s;
					h += n;
				}
			} else {
				i++;

				while ((k[h] < q) && (f != i)) {
					e++;
					i++;
					k[h] += s;
					h += n;
				}
			}
		} else {
			i++;

			if (p == x) {
				j--;

				while ((k[h] < q) && (f != i) && (g != j)) {
					e++;
					i++;
					j--;
					k[h] += s;
					h += n;
				}
			} else {
				j++;

				while ((k[h] < q) && (f != i) && (g != j)) {
					e++;
					i++;
					j++;
					k[h] += s;
					h += n;
				}

				y = ((k[h] & r) == z);

				if (x == y) {
					e++;
					k[h] += s;
					m = h;

					if (f == i) {
						/* right traversal */
						o = a[w];
						h += o;
						j++;
					} else {
						/* down traversal */
						o = a[s];
						h += o;
						i++;

						while ((k[h] < q) && (f != i)) {
							e++;
							k[h] += s;
							h += o;
							i++;
						}

						y = ((f == i) && (g == j));

						if (y == z) {
							h -= o;
							i--;

							while (h != m) {
								k[h] -= s;
								h -= o;
								i--;
							}

							k[h] -= s;
						} else {
							if (b != h) {
								ac = d;
								ad = *aa;

								while (ab != ac) {
									ac--;

									if (k[ac] == q) {
										if (ac != h) {
											ae = (ac / c);
											af = (ac % c);
											AvolittyPathfinderA(a, aa, b, c, d, e, ae, af, h, i, j, k);
										}
									}
								}

								ae = *aa;

								if (ad == ae) {
									y = z;
									h -= o;
									i--;

									while (h != m) {
										k[h] -= s;
										h -= o;
										i--;
									}

									k[h] -= s;
								}
							} else {
								y = (*aa > e);

								if (x == y) {
									*aa = e;
								} else {
									y = z;
									h -= o;
									i--;

									while (h != m) {
										k[h] -= s;
										h -= o;
										i--;
									}

									k[h] -= s;
								}
							}
						}
					}
				}

				if (y == z) {
					if ((f == i) && (g == j)) {
						y = x;
					} else {
						e = ab;
						h -= n;
						i--;
						j--;

						while (h != l) {
							i--;
							j--;
							k[h] -= s;
							h -= n;
						}
					}
				}
			}
		}
	}

	if (b == h) {
		if ((*aa > e) && (e != ab)) {
			*aa = e;
			ac = d;

			while (ab != ac) {
				ac--;
				k[ac] &= s;

				if (k[ac] == s) {
					k[ac] = u;
				}
			}
		}
	}

	return;
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
	unsigned long int x;
	unsigned long int * y;
	unsigned char p;
	k = c;
	l = c;
	o = ((unsigned long int) 0UL);
	x = o;
	y = &x;
	p = ((unsigned char) 5U);

	while (k != o) {
		k--;

		if (j[k] == p) {
			m = (k / q);
			n = (k % q);
			AvolittyPathfinderA(a, y, b, q, c, d, m, n, g, h, i, j);


			/* debugging grid output */
			n = 0UL;
			printf("%u ", j[n++]);

			while (l != n) {
				printf("%u ", j[n]);

				if (((n++ + 1UL) % q) == o) {
					printf("\n");
				}
			}

			printf("\n\n");


	        }
	}

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
	q = ((unsigned char) 7U);
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
	d[r] = g;
	d[s] = (b - g);
	d[t] = (b + g);
	d[((unsigned char) 5U)] = d[t];
	d[((unsigned char) 6U)] = g;
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

	/* debugging grid output */
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
