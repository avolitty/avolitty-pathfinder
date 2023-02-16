#include <stdio.h>
#include <stdlib.h>

void AvolittyPathfinderA(unsigned long int *a, unsigned long int *b, unsigned long int *c, unsigned long int *d, unsigned long int *e, unsigned long int *f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned long int j, unsigned long int k, unsigned long int l, unsigned char *m, unsigned char n) {
	/*
		*a -> [array] obstacle traversal destinations for constellation mapping
		*b -> [array] traversal direction increments
		*c -> [integer] number of constellation points in *a
		*d -> [integer] cur pos
		*e -> [integer] cur pos height
		*f -> [integer] cur pos width
		g -> [integer] grid height
		h -> [integer] grid width
		i -> [integer] grid length
		j -> [integer] dst pos
		k -> [integer] dst height
		l -> [integer] dst width
		*m -> [array] grid
		n -> [integer] 0[main]|1[recursive]|2[debug] recursive status
	*/
	unsigned long int o;
	unsigned long int p;
	unsigned long int q;
	unsigned long int r;
	unsigned long int s;
	unsigned long int t;
	unsigned long int u;
	unsigned long int v;
	unsigned long int w;
	unsigned char x;
	unsigned char y;
	o = *d;
	p = o;
	q = *e;
	r = *f;
	x = ((unsigned char) (k > q));
	y = ((unsigned char) 0U);

	if (k == q) {
		x += ((unsigned char) 2U);
	}

	if (l > r) {
		x += ((unsigned char) 4U);
	}

	if (l == r) {
		x += ((unsigned char) 8U);
	}

	s = b[x];
	/* casting integers based on avolitty guidelines after pathfinding is functional */
	printf("\ntraversal direction %u recursive %u index %u\n", s, n, x);
	printf("traversal cur pos before step: %lu\n", o);
	printf("traversal cur pos height: %lu\n", q);
	printf("traversal cur pos width: %lu\n", r);
	printf("traversal dst pos: %lu\n", j);
	printf("traversal dst pos height: %lu\n", k);
	printf("traversal dst pos width: %lu\n", l);


	if (((x & 1U) == 0U) && (x != 6U)) {
		if ((x == 2U) || (x == 8U)) {
			if (x == 2U) {
				while ((m[o] != 3U) && (r != 0UL)) {
					o -= s;
					r--;
				}
			} else {
				while ((m[o] != 3U) && (q != 0UL)) {
					o -= s;
					q--;
				}
			}
		} else {
			if (x == 4U) {
				while ((m[o] != 3U) & (k != q) && (l != r)) {
					o -= s;
					q--;
					r++;
				}
			} else {
				while ((m[o] != 3U) && (k != q) && (l != r)) {
					o -= s;
					q--;
					r--;
				}
			}
		}
	} else {
		y = 1U;

		if ((x == 6U) || (x == 9U)) {
			if (x == 6U) {
				while ((m[o] != 3U) && (l != r)) {
					o += s;
					r++;
				}
			} else {
				while ((m[o] != 3U) && (k != q)) {
					o += s;
					q++;
				}
			}
		} else {
			if (x == 1U) {
				while ((m[o] != 3U) && (k != q) && (l != r)) {
					o += s;
					q++;
					r--;
				}
			} else {
				while ((m[o] != 3U) && (k != q) && (l != r)) {
					o += s;
					q++;
					r++;
				}
			}
		}
	}

	if (m[o] == 2U) {
		return;
	}

	*d = o;
	*e = q;
	*f = r;

	if (m[o] != 3U) {
		m[o] = 2U;
		p = o;
		AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 2U);
		o = *d;
		q = *e;
		r = *f;
	}

	if (n == 2U) {
		return;
	}

	u = q;
	v = r;
	printf("traversal cur pos after step: %lu\n", o);

	if (j == o) {
		/* .. */
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

		s = b[8U];

		if (y == 0U) {
			if ((x == 2U) || (x == 8U)) {
				if (x == 2U) {
					printf("obstacle traversal steps after collision from [left] non-obstacle traversal\n");

					if ((q != 0UL) && (t = (o - s)) && (m[t] == 3U)) {
						q--;

						while ((m[t] == 3U) && (q != 0UL) && (h != r)) {
							t++;

							if (m[t] == 3U) {
								r++;
							} else {
								q--;
								t -= (s + 1UL);
							}
						}

						y = (m[t] == ((unsigned char) 3U));
					} else {
						if (r != 0UL) {
							r--;
							t = (o - 1UL);

							while ((m[t] == 3U) && (q != 0UL) && (r != 0UL)) {
								t -= s;

								if (m[t] == 3U) {
									q--;
								} else {
									r--;
									t += (s - 1UL);
								}
							}

							y = (m[t] == ((unsigned char) 3U));
						} else {
							y = 1U;
						}
					}

					if (y == 0U) {
						*d = t;
						*e = q;
						*f = r;
						m[t] = 2U;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 1U);
					}

					q = u;
					r = v;

					if ((g != q) && (t = (o + s)) && (m[t] == 3U)) {
						q++;

						while ((m[t] == 3U) && (g != q) && (h != r)) {
							t++;

							if (m[t] == 3U) {
								r++;
							} else {
								q++;
								t += (s - 1UL);
							}
						}

						y = (m[t] == ((unsigned char) 3U));
					} else {
						if (r != 0UL) {
							r--;
							t = (o - 1UL);

							while ((m[t] == 3U) && (g != q) && (r != 0UL)) {
								t += s;

								if (m[t] == 3U) {
									q++;
								} else {
									r--;
									t -= (s + 1UL);
								}
							}

							y = (m[t] == ((unsigned char) 3U));
						} else {
							y = 1U;
						}
					}

					if (y == 0U) {
						*d = t;
						*e = q;
						*f = r;
						m[t] = 2U;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 1U);

						if (n == 0U) {
							printf("Second split dst from obstacle traversal after obstacle collision: %lu\n", *d);
							printf("Original src: %lu\n", p);
							AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 1U);
						}
					}
				} else {
					printf("obstacle traversal steps after collision from [up] non-obstacle traversal\n");

					if ((r != 0UL) && (t = (o - 1U)) && (m[t] == 3U)) {
						r--;

						while ((m[t] == 3U) && (g != q) && (r != 0UL)) {
							t += s;

							if (m[t] == 3U) {
								q++;
							} else {
								r--;
								t -= (s + 1UL);
							}
						}

						y = (m[t] == ((unsigned char) 3U));
					} else {
						if (q != 0UL) {
							q--;
							t = (o - s);

							while ((m[t] == 3U) && (q != 0UL) && (r != 0UL)) {
								t--;

								if (m[t] == 3U) {
									r--;
								} else {
									q--;
									t -= (s - 1UL);
								}
							}

							y = (m[t] == ((unsigned char) 3U));
						} else {
							y = 1U;
						}
					}

					if (y == 0U) {
						*d = t;
						*e = q;
						*f = r;
						m[t] = 2U;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 1U);
					}

					q = u;
					r = v;

					if ((h != r) && (t = (o + 1U)) && (m[t] == 3U)) {
						r++;

						while ((m[t] == 3U) && (g != q) && (h != r)) {
							t += s;

							if (m[t] == 3U) {
								q++;
							} else {
								r++;
								t -= (s - 1UL);
							}
						}

						y = (m[t] == ((unsigned char) 3U));
					} else {
						if (q != 0UL) {
							q--;
							t = (o - s);

							while ((m[t] == 3U) && (q != 0UL) && (h != r)) {
								t += 1UL;

								if (m[t] == 3U) {
									r++;
								} else {
									q--;
									t -= (s + 1UL);
								}
							}

							y = (m[t] == ((unsigned char) 3U));
						} else {
							y = 1U;
						}
					}

					if (y == 0U) {
						*d = t;
						*e = q;
						*f = r;
						m[t] = 2U;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 1U);

						if (n == 0U) {
							printf("Second split dst from obstacle traversal after obstacle collision: %lu\n", *d);
							printf("Original src: %lu\n", p);
							AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 1U);
						}
					}
				}
			} else {
				if (x == 4U) {
					printf("obstacle traversal steps after collision from [up right] non-obstacle traversal\n");

					if ((r != 0UL) && (t = (o - 1U)) && (m[t] == 3U)) {
						r--;

						while ((m[t] == 3U) && (g != q) && (r != 0UL)) {
							t += s;

							if (m[t] == 3U) {
								q++;
							} else {
								r--;
								t -= (s + 1UL);
							}
						}

						y = (m[t] == ((unsigned char) 3U));
					} else {
						if (q != 0UL) {
							q--;
							t = (o - s);

							while ((m[t] == 3U) && (q != 0UL) && (r != 0UL)) {
								t--;

								if (m[t] == 3U) {
									r--;
								} else {
									q--;
									t -= (s - 1UL);
								}
							}

							y = (m[t] == ((unsigned char) 3U));
						} else {
							y = 1U;
						}
					}

					if (y == 0U) {
						*d = t;
						*e = q;
						*f = r;
						m[t] = 2U;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 1U);
					}

					q = u;
					r = v;

					if ((g != q) && (t = (o + s)) && (m[t] == 3U)) {
						q++;

						while ((m[t] == 3U) && (g != q) && (r != 0UL)) {
							t--;

							if (m[t] == 3U) {
								r--;
							} else {
								q++;
								t += (s + 1UL);
							}
						}

						if (r == v) {
							q--;
							r--;
							t -= (s + 1UL);
						}

						y = (m[t] == ((unsigned char) 3U));
					} else {
						if (h != r) {
							r++;
							t = (o + 1UL);

							while ((m[t] == 3U) && (g != q) && (h != r)) {
								t += s;

								if (m[t] == 3U) {
									q++;
								} else {
									r++;
									t -= (s - 1UL);
								}
							}

							if (q == u) {
								q++;
								r--;
								t += (s - 1UL);
							}

							y = (m[t] == ((unsigned char) 3U));
						} else {
							y = 1U;
						}
					}

					printf("traversal cur pos after obstacle traversal: %lu\n", t);

					if (y == 0U) {
						*d = t;
						*e = q;
						*f = r;
						m[t] = 2U;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 1U);
					}
				} else {
					printf("obstacle traversal steps after collision from [up left] non-obstacle traversal\n");

					if ((q != 0UL) && (t = (o + 1UL)) && (m[t] == 3U)) {
						r++;

						while ((m[t] == 3U) && (g != q) && (h != r)) {
							t++;

							if (m[t] == 3U) {
								q++;
							} else {
								r++;
								t += (s - 1UL);
							}
						}

						y = (m[t] == ((unsigned char) 3U));
					} else {
						if (q != 0UL) {
							q--;
							t = (o - s);

							while ((m[t] == 3U) && (q != 0UL) && (h != r)) {
								t++;

								if (m[t] == 3U) {
									r++;
								} else {
									q--;
									t -= (s + 1UL);
								}
							}

							y = (m[t] == ((unsigned char) 3U));
						} else {
							y = 1U;
						}
					}

					if (y == 0U) {
						*d = t;
						*e = q;
						*f = r;
						m[t] = 2U;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 1U);
					}

					q = u;
					r = v;

					if ((g != q) && (t = (o + s)) && (m[t] == 3U)) {
						q++;

						while ((m[t] == 3U) && (g != q) && (h != r)) {
							t++;

							if (m[t] == 3U) {
								r++;
							} else {
								q++;
								t += (s - 1UL);
							}
						}

						y = (m[t] == ((unsigned char) 3U));
					} else {
						if (r != 0UL) {
							r--;
							t = (o - 1UL);

							while ((m[t] == 3U) && (g != q) && (r != 0UL)) {
								t += s;

								if (m[t] == 3U) {
									q++;
								} else {
									r--;
									t -= (s + 1UL);
								}
							}

							y = (m[t] == ((unsigned char) 3U));
						} else {
							y = 1U;
						}
					}

					if (y == 0U) {
						*d = t;
						*e = q;
						*f = r;
						m[t] = 2U;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 1U);
					}
				}
			}
		} else {
			if ((x == 6U) || (x == 9U)) {
				if (x == 6U) {
					printf("obstacle traversal steps after collision from [right] non-obstacle traversal\n");

					if ((q != 0UL) && (t = (o - s)) && (m[t] == 3U)) {
						q--;

						while ((m[t] == 3U) && (q != 0UL) && (r != 0UL)) {
							t--;

							if (m[t] == 3U) {
								r--;
							} else {
								q--;
								t -= (s - 1UL);
							}
						}

						y = (m[t] == ((unsigned char) 3U));
					} else {
						if (h != r) {
							r++;
							t = (o + 1UL);

							while ((m[t] == 3U) && (q != 0UL) && (h != r)) {
								t -= s;

								if (m[t] == 3U) {
									q--;
								} else {
									r++;
									t += (s + 1UL);
								}
							}

							y = (m[t] == ((unsigned char) 3U));
						} else {
							y = 1U;
						}
					}

					if (y == 0U) {
						*d = t;
						*e = q;
						*f = r;
						m[t] = 2U;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 1U);
					}

					q = u;
					r = v;

					if ((g != q) && (t = (o + s)) && (m[t] == 3U)) {
						q++;

						while ((m[t] == 3U) && (g != q) && (r != 0UL)) {
							t--;

							if (m[t] == 3U) {
								r--;
							} else {
								q++;
								t += (s + 1UL);
							}
						}

						y = (m[t] == ((unsigned char) 3U));
					} else {
						if (h != r) {
							r++;
							t = (o + 1UL);

							while ((m[t] == 3U) && (g != q) && (h != r)) {
								t += s;

								if (m[t] == 3U) {
									q++;
								} else {
									r++;
									t += (s - 1UL);
								}
							}

							y = (m[t] == ((unsigned char) 3U));
						} else {
							y = 1U;
						}
					}

					if (y == 0U) {
						*d = t;
						*e = q;
						*f = r;
						m[t] = 2U;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 1U);
					}
				} else {
					printf("obstacle traversal steps after collision from [down] non-obstacle traversal\n");

					if ((r != 0UL) && (t = (o - 1UL)) && (m[t] == 3U)) {
						r--;

						while ((m[t] == 3U) && (q != 0UL) && (r != 0UL)) {
							t -= s;

							if (m[t] == 3U) {
								q--;
							} else {
								r--;
								t += (s - 1UL);
							}
						}

						y = (m[t] == ((unsigned char) 3U));
					} else {
						if (g != q) {
							q++;
							t = (o + s);

							while ((m[t] == 3U) && (g != q) && (r != 0UL)) {
								t--;

								if (m[t] == 3U) {
									r--;
								} else {
									q++;
									t += (s + 1UL);
								}
							}

							y = (m[t] == ((unsigned char) 3U));
						} else {
							y = 1U;
						}
					}

					if (y == 0U) {
						*d = t;
						*e = q;
						*f = r;
						m[t] = 2U;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 1U);
					}

					q = u;
					r = v;

					if ((h != r) && (t = (o + 1UL)) && (m[t] == 3U)) {
						r++;

						while ((m[t] == 3U) && (q != 0UL) && (h != r)) {
							t -= s;

							if (m[t] == 3U) {
								q--;
							} else {
								r++;
								t += (s + 1UL);
							}
						}

						y = (m[t] == ((unsigned char) 3U));
					} else {
						if (g != q) {
							q++;
							t = (o + s);

							while ((m[t] == 3U) && (g != q) && (h != r)) {
								t++;

								if (m[t] == 3U) {
									r++;
								} else {
									q++;
									t += (s - 1UL);
								}
							}

							y = (m[t] == ((unsigned char) 3U));
						} else {
							y = 1U;
						}
					}

					if (y == 0U) {
						*d = t;
						*e = q;
						*f = r;
						m[t] = 2U;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 1U);
					}
				}
			} else {
				if (x == 1U) {
					printf("obstacle traversal steps after collision from [down left] non-obstacle traversal\n");

					if ((q != 0UL) && (t = (o - s)) && (m[t] == 3U)) {
						q--;

						while ((m[t] == 3U) && (q != 0UL) && (h != r)) {
							t++;

							if (m[t] == 3U) {
								r++;
							} else {
								q--;
								t -= (s + 1UL);
							}
						}

						y = (m[t] == ((unsigned char) 3U));
					} else {
						if (r != 0UL) {
							r--;
							t = (o - 1UL);

							while ((m[t] == 3U) && (q != 0UL) && (r != 0UL)) {
								t -= s;

								if (m[t] == 3U) {
									q--;
								} else {
									r--;
									t += (s - 1UL);
								}
							}

							y = (m[t] == ((unsigned char) 3U));
						} else {
							y = 1U;
						}
					}

					if (y == 0U) {
						*d = t;
						*e = q;
						*f = r;
						m[t] = 2U;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 1U);
					}

					q = u;
					r = v;

					if ((h != r) && (t = (o + 1UL)) && (m[t] == 3U)) {
						r++;

						while ((m[t] == 3U) && (q != 0UL) && (h != r)) {
							t -= s;

							if (m[t] == 3U) {
								q--;
							} else {
								r++;
								t += (s + 1UL);
							}
						}

						y = (m[t] == ((unsigned char) 3U));
					} else {
						if (g != q) {
							q++;
							t = (o + s);

							while ((m[t] == 3U) && (g != q) && (h != r)) {
								t++;

								if (m[t] == 3U) {
									r++;
								} else {
									q++;
									t += (s + 1UL);
								}
							}

							y = (m[t] == ((unsigned char) 3U));
						} else {
							y = 1U;
						}
					}

					if (y == 0U) {
						*d = t;
						*e = q;
						*f = r;
						m[t] = 2U;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 1U);
					}
				} else {
					printf("obstacle traversal steps after collision from [down right] non-obstacle traversal\n");

					if ((q != 0UL) && (t = (o - s)) && (m[t] == 3U)) {
						q--;

						while ((m[t] == 3U) && (q != 0UL) && (r != 0UL)) {
							t--;

							if (m[t] == 3U) {
								r--;
							} else {
								q--;
								t -= (s - 1UL);
							}
						}

						y = (m[t] == ((unsigned char) 3U));
					} else {
						if (h != r) {
							r++;
							t = (o + 1UL);

							while ((m[t] == 3U) && (q != 0UL) && (h != r)) {
								t -= s;

								if (m[t] == 3U) {
									q--;
								} else {
									r++;
									t += (s + 1UL);
								}
							}

							y = (m[t] == ((unsigned char) 3U));
						} else {
							y = 1U;
						}
					}

					if (y == 0U) {
						*d = t;
						*e = q;
						*f = r;
						m[t] = 2U;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 1U);
					}

					q = u;
					r = v;

					if ((r != 0UL) && (t = (o - 1UL)) && (m[t] == 3U)) {
						r--;

						while ((m[t] == 3U) && (q != 0UL) && (r != 0UL)) {
							t -= s;

							if (m[t] == 3U) {
								q--;
							} else {
								r--;
								t += (s - 1UL);
							}
						}

						y = (m[t] == ((unsigned char) 3U));
					} else {
						if (g != q) {
							q++;
							t = (o + s);

							while ((m[t] == 3U) && (g != q) && (r != 0UL)) {
								t--;

								if (m[t] == 3U) {
									r--;
								} else {
									q++;
									t += (s + 1UL);
								}
							}

							y = (m[t] == ((unsigned char) 3U));
						} else {
							y = 1U;
						}
					}

					if (y == 0U) {
						*d = t;
						*e = q;
						*f = r;
						m[t] = 2U;
						AvolittyPathfinderA(a, b, c, d, e, f, g, h, i, j, k, l, m, (unsigned char) 1U);
					}
				}
			}

			return;
		}
	}

	/* debug grid output */
	if (n == 0U) {
		o = i;
		p = 0UL;
		printf("%u ", m[p++]);

		while (o != p) {
			printf("%u ", m[p]);

			if (((p++ + 1UL) % h) == 0UL) {
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
	unsigned long int *r;
	e = (a * b);
	f = e;
	g = ((unsigned long int) 1UL);
	h = ((unsigned long int) 0UL);
	l = ((unsigned long int) 0UL);
	m = l;
	n = calloc((size_t) g, sizeof(a));
	o = &e;
	p = &g;
	q = &l;
	r = &m;

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
	AvolittyPathfinderA(n, d, p, o, q, r, a, b, f, i, j, k, c, (unsigned char) 0U);
	AvolittyPathfinderB();
	return;
}
