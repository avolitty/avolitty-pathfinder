#include <stdio.h>

void debug(unsigned long int x, unsigned long int y, unsigned long int z, unsigned long int a, unsigned long int b, unsigned long int c, unsigned char * d, unsigned long int e) {
	unsigned long int f;
	f = ((unsigned long int) 0UL);
	printf("i [cur src height pos]: %lu\n", y);
	printf("j [cur src weight pos]: %lu\n", b);
	printf("l [pos]: %lu\n", z);
	printf("f [dst height pos]: %lu\n", x);
	printf("g [dst width pos]: %lu\n", b);
	printf("e [traversal step count]: %lu\n", e);
	printf("%u ", d[f++]);

	while (c != f) {
		printf("%u ", d[f]);

		if (((f++ + 1UL) % 11UL) == 0UL) {
			printf("\n");
		}
	}

	printf("\n");
	return;
}

void AvolittyPathfinderA(unsigned long int * a, unsigned long int * aa, unsigned long int b, unsigned long int c, unsigned long int d, unsigned long int e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned long int j, unsigned char * k, unsigned long int zz) {
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
		zz -> [integer] prev cur src pos

		alphabetizing and deleting unused variables with a maximum of 26 variables per function scope after completing
			using 0 values in a[3] and a[7]
		remaining recursion logic to prevent infinite loop from 5 5 5 triangle
			traversed 5 should be increased to 6
			*aa should be grid length
			finalization shouldn't convert 6 to 5
				6 should be converted back to 5 after all traversal waypoints from a waypoint are exhausted
			traversals should automatically be invalid if *aa is exceeded

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
	unsigned char ag;
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
	z = y;
	zz = h;
	printf("\n\nstart\n\n");

	/* debug */
	if (f == i && g == j) {
		printf("--");
		return;
	}

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
				printf("left --------------\n");
				j--;

				while ((k[h] < q) && (g != j)) {
					e++;
					j--;
					k[h] += s;
					h -= n;
				}

				/* left traversal */
				y = (k[h] == q);

				if (b != h) {
					if ((x == y) && (f == i) && (g == j)) {
						ac = d;
						ad = *aa;
						k[h] = t;

						while (ab != ac) {
							ac--;

							if (k[ac] == q) {
								ae = (ac / c);
								af = (ac % c);
								AvolittyPathfinderA(a, aa, b, c, d, e, ae, af, h, i, j, k, zz);
								printf("1 ++\n");
							}
						}

						k[h] = q;
						y = z;
					}

					if (y == z) {
						e = ab;
						h += n;
						j++;
						v = s;

						if (k[h] == u) {
							v = z;
						}

						while (h != l) {
							j++;
							k[h] -= v;
							h += n;
						}
					}
				}
			} else {
				printf("up --------------\n");
				i--;

				while ((k[h] < q) && (f != i)) {
					e++;
					i--;
					k[h] += s;
					h -= n;
				}

				/* up traversal */
				y = (k[h] == q);

				if (b != h) {
					if ((x == y) && (f == i) && (g == j)) {
						ac = d;
						ad = *aa;
						k[h] = t;

						while (ab != ac) {
							ac--;

							if (k[ac] == q) {
								ae = (ac / c);
								af = (ac % c);
								AvolittyPathfinderA(a, aa, b, c, d, e, ae, af, h, i, j, k, zz);
								printf("2 ++\n");
							}
						}

						k[h] = q;
						y = z;
					}

					if (y == z) {
						e = ab;
						h += n;
						i++;
						v = s;

						if (k[h] == u) {
							v = z;
						}

						while (h != l) {
							i++;
							k[h] -= v;
							h += n;
						}
					}
				}
			}
		} else {
			i--;

			if (p == u) {
				printf("up right --------------\n");
				j++;

				while ((k[h] < q) && (f != i) && (g != j)) {
					e++;
					i--;
					j++;
					k[h] += s;
					h -= n;
				}

				/* up right traversal */
				y = ((k[h] == z) || (k[h] == u));

				if (x == y) {
					e++;
					k[h] += s;
					m = h;

					if (f == i) {
						/* right traversal */
						o = a[w];
						h += o;
						j++;

						while ((k[h] < q) && (g != j)) {
							e++;
							k[h] += s;
							h += o;
							j++;
						}

						y = ((f == i) && (g == j) && (k[h] == q));

						if (y == z) {
							h -= o;
							j--;
							v = s;

							if (k[h] == u) {
								v = z;
							}

							while (h != m) {
								k[h] -= v;
								h -= o;
								j--;
							}

							k[h] -= v;
						} else {
							if (b != h) {
								ac = d;
								ad = *aa;
								k[h] = t;

								while (ab != ac) {
									ac--;

									if (k[ac] == q) {
										ae = (ac / c);
										af = (ac % c);
										AvolittyPathfinderA(a, aa, b, c, d, e, ae, af, h, i, j, k, zz);
										printf("3 ++\n");
									}
								}

								k[h] = q;
								y = z;
								h -= o;
								j--;
								v = s;

								if (k[h] == u) {
									v = z;
								}

								while (h != m) {
									k[h] -= v;
									h -= o;
									j--;
								}

								k[h] -= v;
							} else {
								y = (*aa > e);

								if (x == y) {
									*aa = e;
								} else {
									y = z;
									h -= o;
									j--;
									v = s;

									if (k[h] == u) {
										v = z;
									}

									while (h != m) {
										k[h] -= v;
										h -= o;
										j--;
									}

									k[h] -= v;
								}
							}
						}
					} else {
						/* up traversal */
						o = a[s];
						h -= o;
						i--;

						while ((k[h] < q) && (f != i)) {
							e++;
							k[h] += s;
							h -= o;
							i--;
						}

						y = ((f == i) && (g == j) && (k[h] == q));

						if (y == z) {
							h += o;
							i++;
							v = s;

							if (k[h] == u) {
								v = z;
							}

							while (h != m) {
								k[h] -= v;
								h += o;
								i++;
							}

							k[h] -= v;
						} else {
							if (b != h) {
								ac = d;
								ad = *aa;
								k[h] = t;

								while (ab != ac) {
									ac--;

									if (k[ac] == q) {
										ae = (ac / c);
										af = (ac % c);
										AvolittyPathfinderA(a, aa, b, c, d, e, ae, af, h, i, j, k, zz);
										printf("4 ++\n");
									}
								}

								k[h] = q;
								y = z;
								h += o;
								i++;
								v = s;

								if (k[h] == u) {
									v = z;
								}

								while (h != m) {
									k[h] -= v;
									h += o;
									i++;
								}

								k[h] -= v;
							} else {
								y = (*aa > e);

								if (x == y) {
									*aa = e;
								} else {
									y = z;
									h += o;
									i++;
									v = s;

									if (k[h] == u) {
										v = z;
									}

									while (h != m) {
										k[h] -= v;
										h += o;
										i++;
									}

									k[h] -= v;
								}
							}
						}
					}
				}

				if (b != h) {
					if ((x == y) || ((f == i) && (g == j))) {
						ac = d;
						ad = *aa;
						k[h] = t;

						while (ab != ac) {
							ac--;

							if (k[ac] == q) {
								ae = (ac / c);
								af = (ac % c);
								AvolittyPathfinderA(a, aa, b, c, d, e, ae, af, h, i, j, k, zz);
								printf("5 ++\n");
							}
						}

						k[h] = q;
						y = z;
					}

					if (y == z) {
						e = ab;
						h += n;
						i++;
						j--;
						v = s;

						if (k[h] == u) {
							v = z;
						}

						while (h != l) {
							i++;
							j--;
							k[h] -= v;
							h += n;
						}
					}
				}
			} else {
				printf("up left --------------\n");
				j--;

				while ((k[h] < q) && (f != i) && (g != j)) {
					e++;
					i--;
					j--;
					k[h] += s;
					h -= n;
				}

				/* up left */

				y = ((k[h] == z) || (k[h] == u));

				if (x == y) {
					e++;
					k[h] += s;
					m = h;

					if (f == i) {
						/* left traversal */
						o = a[w];
						h -= o;
						j--;

						while ((k[h] < q) && (g != j)) {
							e++;
							k[h] += s;
							h -= o;
							j--;
						}

						y = ((f == i) && (g == j) && (k[h] == q));

						if (y == z) {
							h += o;
							j++;
							v = s;

							if (k[h] == u) {
								v = z;
							}

							while (h != m) {
								k[h] -= v;
								h += o;
								j++;
							}

							k[h] -= v;
						} else {
							if (b != h) {
								ac = d;
								ad = *aa;
								k[h] = t;

								while (ab != ac) {
									ac--;

									if (k[ac] == q) {
										ae = (ac / c);
										af = (ac % c);
										AvolittyPathfinderA(a, aa, b, c, d, e, ae, af, h, i, j, k, zz);
										printf("6 ++\n");
									}
								}

								k[h] = q;
								y = z;
								h += o;
								j++;
								v = s;

								if (k[h] == u) {
									v = z;
								}

								while (h != m) {
									k[h] -= v;
									h += o;
									j++;
								}

								k[h] -= v;
							} else {
								y = (*aa > e);

								if (x == y) {
									*aa = e;
								} else {
									y = z;
									h += o;
									j++;
									v = s;

									if (k[h] == u) {
										v = z;
									}

									while (h != m) {
										k[h] -= v;
										h += o;
										j++;
									}

									k[h] -= v;
								}
							}
						}
					} else {
						/* up traversal */
						o = a[s];
						h -= o;
						i--;

						while ((k[h] < q) && (f != i)) {
							e++;
							k[h] += s;
							h -= o;
							i--;
						}

						y = ((f == i) && (g == j) && (k[h] == q));

						if (y == z) {
							h += o;
							i++;
							v = s;

							if (k[h] == u) {
								v = z;
							}

							while (h != m) {
								k[h] -= v;
								h += o;
								i++;
							}

							k[h] -= v;
						} else {
							if (b != h) {
								ac = d;
								ad = *aa;
								k[h] = t;

								while (ab != ac) {
									ac--;

									if (k[ac] == q) {
										ae = (ac / c);
										af = (ac % c);
										AvolittyPathfinderA(a, aa, b, c, d, e, ae, af, h, i, j, k, zz);
										printf("7 ++\n");
									}
								}

								k[h] = q;
								y = z;
								h += o;
								i++;
								v = s;

								if (k[h] == u) {
									v = z;
								}

								while (h != m) {
									k[h] -= v;
									h += o;
									i++;
								}

								k[h] -= v;
							} else {
								y = (*aa > e);

								if (x == y) {
									*aa = e;
								} else {
									y = z;
									h += o;
									i++;
									v = s;

									if (k[h] == u) {
										v = z;
									}

									while (h != m) {
										k[h] -= v;
										h += o;
										i++;
									}

									k[h] -= v;
								}
							}
						}
					}
				}

				if (b != h) {
					if ((x == y) || ((f == i) && (g == j))) {
						ac = d;
						ad = *aa;
						k[h] = t;

						while (ab != ac) {
							ac--;

							if (k[ac] == q) {
								ae = (ac / c);
								af = (ac % c);
								AvolittyPathfinderA(a, aa, b, c, d, e, ae, af, h, i, j, k, zz);
								printf("8 ++\n");
							}
						}

						k[h] = q;
						y = z;
					}

					if (y == z) {
						e = ab;
						h += n;
						i++;
						j++;
						v = s;

						if (k[h] == u) {
							v = z;
						}

						while (h != l) {
							i++;
							j++;
							k[h] -= v;
							h += n;
						}
					}
				}
			}
		}
	} else {
		h += n;

		if ((p == t) || (p == r)) {
			if (p == t) {
				printf("right --------------\n");
				j++;

				while ((k[h] < q) && (g != j)) {
					e++;
					j++;
					k[h] += s;
					h += n;
				}

				/* right traversal */
				y = (k[h] == q);

				if (b != h) {
					if (((x == y) && (f == i)) && (g == j)) {
						ac = d;
						ad = *aa;
						k[h] = t;

						while (ab != ac) {
							ac--;

							if (k[ac] == q) {
								ae = (ac / c);
								af = (ac % c);
								AvolittyPathfinderA(a, aa, b, c, d, e, ae, af, h, i, j, k, zz);
								printf("9 ++\n");
							}
						}

						k[h] = q;
						y = z;
					}

					if (y == z) {
						e = ab;
						h -= n;
						j--;
						v = s;

						if (k[h] == u) {
							v = z;
						}

						while (h != l) {
							j--;
							k[h] -= v;
							h -= n;
						}
					}
				}
			} else {
				printf("down --------------\n");
				i++;

				while ((k[h] < q) && (f != i)) {
					e++;
					i++;
					k[h] += s;
					h += n;
				}

				/* down traversal */
				y = (k[h] == q);

				if (b != h) {
					if (((x == y) && (f == i)) && (g == j)) {
						ac = d;
						ad = *aa;
						k[h] = t;

						while (ab != ac) {
							ac--;

							if (k[ac] == q) {
								ae = (ac / c);
								af = (ac % c);
								AvolittyPathfinderA(a, aa, b, c, d, e, ae, af, h, i, j, k, zz);
								printf("10 ++\n");
							}
						}

						k[h] = q;
						y = z;
					}

					if (y == z) {
						e = ab;
						h -= n;
						i--;
						v = s;

						if (k[h] == u) {
							v = z;
						}

						while (h != l) {
							i--;
							k[h] -= v;
							h -= n;
						}
					}
				}
			}
		} else {
			i++;

			if (p == x) {
				printf("down left --------------\n");
				j--;

				while ((k[h] < q) && (f != i) && (g != j)) {
					e++;
					i++;
					j--;
					k[h] += s;
					h += n;
				}

				/* down left traversal */
				y = ((k[h] == z) || (k[h] == u));

				if (x == y) {
					e++;
					k[h] += s;
					m = h;

					if (f == i) {
						/* left traversal */
						o = a[w];
						h -= o;
						j--;

						while ((k[h] < q) && (g != j)) {
							e++;
							k[h] += s;
							h -= o;
							j--;
						}

						y = ((f == i) && (g == j) && (k[h] == q));

						if (y == z) {
							h += o;
							j++;
							v = s;

							if (k[h] == u) {
								v = z;
							}

							while (h != m) {
								k[h] -= v;
								h += o;
								j++;
							}

							k[h] -= v;
						} else {
							if (b != h) {
								ac = d;
								ad = *aa;
								k[h] = t;

								while (ab != ac) {
									ac--;

									if (k[ac] == q) {
										ae = (ac / c);
										af = (ac % c);
										AvolittyPathfinderA(a, aa, b, c, d, e, ae, af, h, i, j, k, zz);
										printf("11 ++\n");
									}
								}

								k[h] = q;
								y = z;
								h += o;
								j++;
								v = s;

								if (k[h] == u) {
									v = z;
								}

								while (h != m) {
									k[h] -= v;
									h += o;
									j++;
								}

								k[h] -= v;
							} else {
								y = (*aa > e);

								if (x == y) {
									*aa = e;
								} else {
									y = z;
									h += o;
									j++;
									v = s;

									if (k[h] == u) {
										v = z;
									}

									while (h != m) {
										k[h] -= v;
										h += o;
										j++;
									}

									k[h] -= v;
								}
							}
						}
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

						y = ((f == i) && (g == j) && (k[h] == q));

						if (y == z) {
							h -= o;
							i--;
							v = s;

							if (k[h] == u) {
								v = z;
							}

							while (h != m) {
								k[h] -= v;
								h -= o;
								i--;
							}

							k[h] -= v;
						} else {
							if (b != h) {
								ac = d;
								ad = *aa;
								k[h] = t;

								while (ab != ac) {
									ac--;

									if (k[ac] == q) {
										ae = (ac / c);
										af = (ac % c);
										AvolittyPathfinderA(a, aa, b, c, d, e, ae, af, h, i, j, k, zz);
										printf("12 ++\n");
									}
								}

								k[h] = q;
								y = z;
								h -= o;
								i--;
								v = s;

								if (k[h] == u) {
									v = z;
								}

								while (h != m) {
									k[h] -= v;
									h -= o;
									i--;
								}

								k[h] -= v;
							} else {
								y = (*aa > e);

								if (x == y) {
									*aa = e;
								} else {
									y = z;
									h -= o;
									i--;
									v = s;

									if (k[h] == u) {
										v = z;
									}

									while (h != m) {
										k[h] -= v;
										h -= o;
										i--;
									}

									k[h] -= v;
								}
							}
						}
					}
				}

				if (b != h) {
					if ((x == y) || ((f == i) && (g == j))) {
						ac = d;
						ad = *aa;
						k[h] = t;

						while (ab != ac) {
							ac--;

							if (k[ac] == q) {
								ae = (ac / c);
								af = (ac % c);
								AvolittyPathfinderA(a, aa, b, c, d, e, ae, af, h, i, j, k, zz);
								printf("13 ++\n");
							}
						}

						k[h] = q;
						ae = *aa;
						y = z;
					}

					if (y == z) {
						e = ab;
						h -= n;
						i--;
						j++;
						v = s;

						if (k[h] == u) {
							v = z;
						}

						while (h != l) {
							i--;
							j++;
							k[h] -= v;
							h -= n;
						}
					}
				}
			} else {
				printf("down right --------------\n");
				j++;

				while ((k[h] < q) && (f != i) && (g != j)) {
					e++;
					i++;
					j++;
					k[h] += s;
					h += n;
				}

				/* down right traversal */
				y = ((k[h] == z) || (k[h] == u));

				if (x == y) {
					e++;
					k[h] += s;
					m = h;

					if (f == i) {
						/* right traversal */
						o = a[w];
						h += o;
						j++;

						while ((k[h] < q) && (g != j)) {
							e++;
							k[h] += s;
							h += o;
							j++;
						}

						y = ((f == i) && (g == j) && (k[h] == q));

						if (y == z) {
							h -= o;
							j--;

							while (h != m) {
								k[h] -= s;
								h -= o;
								j--;
							}

							k[h] -= s;
						} else {
							if (b != h) {
								ac = d;
								ad = *aa;
								k[h] = t;

								while (ab != ac) {
									ac--;

									if (k[ac] == q) {
										ae = (ac / c);
										af = (ac % c);
										AvolittyPathfinderA(a, aa, b, c, d, e, ae, af, h, i, j, k, zz);
										printf("14 ++\n");
									}
								}

								k[h] = q;
								y = z;
								h -= o;
								j--;
								v = s;

								if (k[h] == u) {
									v = z;
								}

								while (h != m) {
									k[h] -= v;
									h -= o;
									j--;
								}

								k[h] -= v;
							} else {
								y = (*aa > e);

								if (x == y) {
									*aa = e;
								} else {
									y = z;
									h -= o;
									j--;
									v = s;

									if (k[h] == u) {
										v = z;
									}

									while (h != m) {
										k[h] -= v;
										h -= o;
										j--;
									}

									k[h] -= v;
								}
							}
						}
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

						y = ((f == i) && (g == j) && (k[h] == q));

						if (y == z) {
							h -= o;
							i--;
							v = s;

							if (k[h] == u) {
								v = z;
							}

							while (h != m) {
								k[h] -= v;
								h -= o;
								i--;
							}

							k[h] -= v;
						} else {
							if (b != h) {
								ac = d;
								ad = *aa;
								k[h] = t;

								while (ab != ac) {
									ac--;

									if (k[ac] == q) {
										ae = (ac / c);
										af = (ac % c);
										AvolittyPathfinderA(a, aa, b, c, d, e, ae, af, h, i, j, k, zz);
										printf("15 ++\n");
									}
								}

								k[h] = q;
								y = z;
								h -= o;
								i--;
								v = s;

								if (k[h] == u) {
									v = z;
								}

								while (h != m) {
									k[h] -= v;
									h -= o;
									i--;
								}

								k[h] -= v;
							} else {
								y = (*aa > e);

								if (x == y) {
									*aa = e;
								} else {
									y = z;
									h -= o;
									i--;

									v = s;

									if (k[h] == u) {
										v = z;
									}

									while (h != m) {
										k[h] -= v;
										h -= o;
										i--;
									}

									k[h] -= v;
								}
							}
						}
					}
				}

				if (b != h) {
					if ((x == y) || ((f == i) && (g == j))) {
						ac = d;
						ad = *aa;
						k[h] = t;

						while (ab != ac) {
							ac--;

							if (k[ac] == q) {
								ae = (ac / c);
								af = (ac % c);
								AvolittyPathfinderA(a, aa, b, c, d, e, ae, af, h, i, j, k, zz);
								printf("16 ++ %lu %lu %lu %lu %lu %lu %lu \n", h, ae, af, ac, c, *aa, ad);
							}
						}

						printf("\n??\n");
						k[h] = q;
						printf("\n???\n");
						printf("\n????\n");
						printf("\n?????\n");
						y = z;
					}

					printf("\ny %u\n", y);
					printf("z %u\n", z);
					printf("k[h] %u\n", k[h]);
					printf("s %u\n", s);
					printf("h %lu\n", h);
					printf("l %lu\n", l);
					printf("n %lu\n", n);
					printf("i %u\n", i);
					printf("j %u\n", j);
					printf("h %u\n", h);
					debug(f, i, l, g, j, d, k, e);

					if (y == z) {
						printf("??????");
					} else {
						printf("??????????");
					}

					if (y == z) {
						printf("!!!!!!!!");
						e = ab;
						h -= n;
						i--;
						j--;
						/* adding if statement before loop to verify if k[h] is a 4 or 8 before decrementing k[h]
							if statement sets s as 4 or 8 */
						v = s;

						if (k[h] == u) {
							v = z;
						}

						while (h != l) {
							i--;
							j--;
							k[h] -= v;
							h -= n;
						}
					}
				}
			}
		}
	}

	printf("\n\nend1\n\n");

	if (b == h) {

		printf("\n------before finalization------\n");
		debug(f, i, l, g, j, d, k, e);
		ac = d;
		ad = ((unsigned char) 12U);

		if ((*aa > e) || (*aa == ab)) {
			*aa = e;
			ad = ((unsigned char) 12U);

			while (ab != ac) {
				ac--;

				if ((k[ac] == s) || (k[ac] == u)) {
					k[ac] -= u;
				}

				if (k[ac] == ad) {
					k[ac] -= s;
				}
			}
		} else {
			while (ab != ac) {
				ac--;

				if (k[ac] == s || k[ac] == ad) {
					k[ac] -= s;
				}
			}
		}

		printf("\n------after finalization------\n");
		debug(f, i, l, g, j, d, k, e);
	} else {
		debug(f, i, l, g, j, d, k, e);
	}

	printf("\n\nend2\n\n");
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
			AvolittyPathfinderA(a, y, b, q, c, d, m, n, g, h, i, j, 0UL);
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
	d[p] = (b - g);
	d[r] = g;
	d[s] = d[p];
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
	printf("\n");
	/* .. */
	return;
}
