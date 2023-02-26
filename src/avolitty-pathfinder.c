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

unsigned long int AvolittyPathfinderA(unsigned long int * a, unsigned long int * aa, unsigned long int b, unsigned long int ah, unsigned long int ai, unsigned long int aj, unsigned long int ak, unsigned long int c, unsigned long int d, unsigned long int e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned long int j, unsigned char * k, unsigned long int zz) {
	/*
		* a -> [array] traversal direction increments
		* aa -> [integer] current shortest traversal path length for traversal resetting
		b -> [integer] dst pos
		ah -> [integer] src pos
		ai -> [integer] src height
		aj -> [integer] src width
		ak -> [integer] grid height
		c -> [integer] grid width
		d -> [integer] grid length
		e -> [integer] traversal steps
		f -> [integer] cur dst height
		g -> [integer] cur dst width
		h -> [integer] cur src pos
		i -> [integer] cur src height
		j -> [integer] cur src width
		* k -> [array] grid
		zz -> [integer] prev cur src pos

		alphabetizing and deleting unused variables with a maximum of 26 variables per function scope after completing

	*/
	unsigned long int ab;
	unsigned long int ac;
	unsigned char ad;
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
	v = ((unsigned char) 12U);
	ad = ((unsigned char) 10U);
	w = ((unsigned char) 2U);
	x = ((unsigned char) 1U);
	y = ((unsigned char) 0U);
	z = y;
	zz = h;
	ag = z;

	if (f == i) {
		p += w;
	}

	if (g > j) {
		p += u;
	}

	if (g == j) {
		p += s;
	}

	ai = ab;
	aj = ab;
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

				/* left traversal */
				y = (k[h] == q);

				if (b != h) {
					if ((x == y) && (f == i) && (g == j)) {
						ac = d;
						k[h] = t;

						while (ab != ac) {
							ac--;

							if (k[ac] == q) {
								ae = (ac / c);
								af = (ac % c);
								ah = AvolittyPathfinderA(a, aa, b, ah, ai, aj, ak, c, d, e, ae, af, h, i, j, k, zz);

								if (ab != ah) {
									ai = ah;
								}
							}
						}

						k[h] = q;
					}
				} else {
					if (*aa > e) {
						ai = e;
						ae = (h + n);

						if (k[ae] == v) {
							ag = ad;
						} else {
							ag = t;
						}
					}
				}

				h += n;
				j++;

				if (ag == z) {
					ag = s;

					if (ab != ai) {
						ag = u;
					}
				}

				while (h != l) {
					j++;
					k[h] -= ag;
					h += n;
				}
			} else {
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
						k[h] = t;

						while (ab != ac) {
							ac--;

							if (k[ac] == q) {
								ae = (ac / c);
								af = (ac % c);
								ah = AvolittyPathfinderA(a, aa, b, ah, ai, aj, ak, c, d, e, ae, af, h, i, j, k, zz);

								if (ab != ah) {
									ai = ah;
								}
							}
						}

						k[h] = q;
					}
				} else {
					if (*aa > e) {
						ai = e;
						ae = (h + n);

						if (k[ae] == v) {
							ag = ad;
						} else {
							ag = t;
						}
					}
				}

				h += n;
				i++;

				if (ag == z) {
					ag = s;

					if (ab != ai) {
						ag = u;
					}
				}

				while (h != l) {
					i++;
					k[h] -= ag;
					h += n;
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

				/* up right traversal */

				if ((k[h] == z) || (k[h] == u)) {
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

						if ((f == i) && (g == j) && (k[h] == q)) {
							if (b != h) {
								ac = d;
								k[h] = t;

								while (ab != ac) {
									ac--;

									if (k[ac] == q) {
										ae = (ac / c);
										af = (ac % c);
										ah = AvolittyPathfinderA(a, aa, b, ah, ai, aj, ak, c, d, e, ae, af, h, i, j, k, zz);

										if (ab != ah) {
											ai = ah;
										}
									}
								}

								k[h] = q;
							} else {
								if (*aa > e) {
									ai = e;
									ag = t;
									ae = (h - o);

									if (k[ae] == v) {
										ag = ad;
									} else {
										ag = t;
									}
								}
							}

							h -= o;
							j--;

							if (ag == z) {
								ag = s;

								if (ab != ai) {
									ag = u;
								}
							}

							while (h != m) {
								k[h] -= ag;
								h -= o;
								j--;
							}

							k[h] -= ag;
						} else {
							h -= o;
							j--;

							while (h != m) {
								k[h] -= s;
								h -= o;
								j--;
							}

							k[h] -= s;
							ag = s;
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

						if ((f == i) && (g == j) && (k[h] == q)) {
							if (b != h) {
								ac = d;
								k[h] = t;

								while (ab != ac) {
									ac--;

									if (k[ac] == q) {
										ae = (ac / c);
										af = (ac % c);
										ah = AvolittyPathfinderA(a, aa, b, ah, ai, aj, ak, c, d, e, ae, af, h, i, j, k, zz);

										if (ab != ah) {
											ai = ah;
										}
									}
								}

								k[h] = q;
							} else {
								if (*aa > e) {
									ai = e;
									ae = (h + o);

									if (k[ae] == v) {
										ag = ad;
									} else {
										ag = t;
									}
								}
							}

							h += o;
							i++;

							if (ag == z) {
								ag = s;

								if (ab != ai) {
									ag = u;
								}
							}

							while (h != m) {
								k[h] -= ag;
								h += o;
								i++;
							}

							k[h] -= ag;
						} else {
							h += o;
							i++;

							while (h != m) {
								k[h] -= s;
								h += o;
								i++;
							}

							k[h] -= s;
							ag = s;
						}
					}
				} else {
					if (b != h) {
						if ((f == i) && (g == j) && (k[h] == q)) {
							ac = d;
							k[h] = t;

							while (ab != ac) {
								ac--;

								if (k[ac] == q) {
									ae = (ac / c);
									af = (ac % c);
									ah = AvolittyPathfinderA(a, aa, b, ah, ai, aj, ak, c, d, e, ae, af, h, i, j, k, zz);

									if (ab != ah) {
										ai = ah;
									}
								}
							}

							k[h] = q;
						}
					} else {
						if (*aa > e) {
							ai = e;
							ae = (h + n);

							if (k[ae] == v) {
								ag = ad;
							} else {
								ag = t;
							}
						}
					}
				}

				h += n;
				i++;
				j--;

				if (ag == z) {
					ag = s;

					if (ab != ai) {
						ag = u;
					}
				}

				while (h != l) {
					i++;
					j--;
					k[h] -= ag;
					h += n;
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

				/* up left */

				if ((k[h] == z) || (k[h] == u)) {
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

						if ((f == i) && (g == j) && (k[h] == q)) {
							if (b != h) {
								ac = d;
								k[h] = t;

								while (ab != ac) {
									ac--;

									if (k[ac] == q) {
										ae = (ac / c);
										af = (ac % c);
										ah = AvolittyPathfinderA(a, aa, b, ah, ai, aj, ak, c, d, e, ae, af, h, i, j, k, zz);

										if (ab != ah) {
											ai = ah;
										}
									}
								}

								k[h] = q;
							} else {
								if (*aa > e) {
									ai = e;
									ae = (h + o);

									if (k[ae] == v) {
										ag = ad;
									} else {
										ag = t;
									}
								}
							}

							h += o;
							j++;

							if (ag == z) {
								ag = s;

								if (ab != ai) {
									ag = u;
								}
							}

							while (h != m) {
								k[h] -= ag;
								h += o;
								j++;
							}

							k[h] -= ag;
						} else {
							h += o;
							j++;

							while (h != m) {
								k[h] -= s;
								h += o;
								j++;
							}

							k[h] -= s;
							ag = s;
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

						if ((f == i) && (g == j) && (k[h] == q)) {
							if (b != h) {
								ac = d;
								k[h] = t;

								while (ab != ac) {
									ac--;

									if (k[ac] == q) {
										ae = (ac / c);
										af = (ac % c);
										ah = AvolittyPathfinderA(a, aa, b, ah, ai, aj, ak, c, d, e, ae, af, h, i, j, k, zz);

										if (ab != ah) {
											ai = ah;
										}
									}
								}

								k[h] = q;
							} else {
								if (*aa > e) {
									ai = e;
									ae = (h + o);

									if (k[ae] == v) {
                                                        		        ag = ad;
									} else {
										ag = t;
									}
								}
							}

							h += o;
							i++;

							if (ag == z) {
								ag = s;

								if (ab != ai) {
									ag = u;
								}
							}

							while (h != m) {
								k[h] -= ag;
								h += o;
								i++;
							}

							k[h] -= ag;
						} else {
							h += o;
							i++;

							while (h != m) {
								k[h] -= s;
								h += o;
								i++;
							}

							k[h] -= s;
							ag = s;
						}
					}
				} else {
					if (b != h) {
						if ((f == i) && (g == j) && (k[h] == q)) {
							ac = d;
							k[h] = t;

							while (ab != ac) {
								ac--;

								if (k[ac] == q) {
									ae = (ac / c);
									af = (ac % c);
									ah = AvolittyPathfinderA(a, aa, b, ah, ai, aj, ak, c, d, e, ae, af, h, i, j, k, zz);

									if (ab != ah) {
										ai = ah;
									}
								}
							}

							k[h] = q;
						}
					} else {
						if (*aa > e) {
							ai = e;
							ae = (h + n);

							if (k[ae] == v) {
								ag = ad;
							} else {
								ag = t;
							}
						}
					}
				}

				h += n;
				i++;
				j++;

				if (ag == z) {
					ag = s;

					if (ab != ai) {
						ag = u;
					}
				}

				while (h != l) {
					i++;
					j++;
					k[h] -= ag;
					h += n;
				}
			}
		}
	} else {
		h += n;

		if ((p == t) || (p == r)) {
			if (p == t) {
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
						k[h] = t;

						while (ab != ac) {
							ac--;

							if (k[ac] == q) {
								ae = (ac / c);
								af = (ac % c);
								ah = AvolittyPathfinderA(a, aa, b, ah, ai, aj, ak, c, d, e, ae, af, h, i, j, k, zz);

								if (ab != ah) {
									ai = ah;
								}
							}
						}

						k[h] = q;
					}
				} else {
					if (*aa > e) {
						ai = e;
						ae = (h - n);

						if (k[ae] == v) {
							ag = ad;
						} else {
							ag = t;
						}
					}
				}

				h -= n;
				j--;

				if (ag == z) {
					ag = s;

					if (ab != ai) {
						ag = u;
					}
				}

				while (h != l) {
					j--;
					k[h] -= ag;
					h -= n;
				}
			} else {
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
						k[h] = t;

						while (ab != ac) {
							ac--;

							if (k[ac] == q) {
								ae = (ac / c);
								af = (ac % c);
								ah = AvolittyPathfinderA(a, aa, b, ah, ai, aj, ak, c, d, e, ae, af, h, i, j, k, zz);

								if (ab != ah) {
									ai = ah;
								}
							}
						}

						k[h] = q;
					}
				} else {
					if (*aa > e) {
						ai = e;
						ae = (h - n);

						if (k[ae] == v) {
							ag = ad;
						} else {
							ag = t;
						}
					}
				}

				h -= n;
				i--;

				if (ag == z) {
					ag = s;

					if (ab != ai) {
						ag = u;
					}
				}

				while (h != l) {
					i--;
					k[h] -= ag;
					h -= n;
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

				/* down left traversal [] */

				if ((k[h] == z) || (k[h] == u)) {
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

						if ((f == i) && (g == j) && (k[h] == q)) {
							if (b != h) {
								ac = d;
								k[h] = t;

								while (ab != ac) {
									ac--;

									if (k[ac] == q) {
										ae = (ac / c);
										af = (ac % c);
										ah = AvolittyPathfinderA(a, aa, b, ah, ai, aj, ak, c, d, e, ae, af, h, i, j, k, zz);

										if (ab != ah) {
											ai = ah;
										}
									}
								}

								k[h] = q;
							} else {
								if (*aa > e) {
									ai = e;
									ae = (h + o);

									if (k[ae] == v) {
										ag = ad;
									} else {
										ag = t;
									}
								}
							}

							h += o;
							j++;

							if (ag == z) {
								ag = s;

								if (ab != ai) {
									ag = u;
								}
							}

							while (h != m) {
								k[h] -= ag;
								h += o;
								j++;
							}

							k[h] -= ag;
						} else {
							h += o;
							j++;

							while (h != m) {
								k[h] -= s;
								h += o;
								j++;
							}

							k[h] -= s;
							ag = s;
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

						if ((f == i) && (g == j) && (k[h] == q)) {
							if (b != h) {
								ac = d;
								k[h] = t;

								while (ab != ac) {
									ac--;

									if (k[ac] == q) {
										ae = (ac / c);
										af = (ac % c);
										ah = AvolittyPathfinderA(a, aa, b, ah, ai, aj, ak, c, d, e, ae, af, h, i, j, k, zz);

										if (ab != ah) {
											ai = ah;
										}
									}
								}

								k[h] = q;
							} else {
								if (*aa > e) {
									ai = e;
									ae = (h - o);

									if (k[ae] == v) {
										ag = ad;
									} else {
										ag = t;
									}
								}
							}

							h -= o;
							i--;

							if (ag == z) {
								ag = s;

								if (ab != ai) {
									ag = u;
								}
							}

							while (h != m) {
								k[h] -= ag;
								h -= o;
								i--;
							}

							k[h] -= ag;
						} else {
							h -= o;
							i--;

							while (h != m) {
								k[h] -= s;
								h -= o;
								i--;
							}

							k[h] -= s;
							ag = s;
						}
					}
				} else {
					if (b != h) {
						if ((f == i) && (g == j) && (k[h] == q)) {
							ac = d;
							k[h] = t;

							while (ab != ac) {
								ac--;

								if (k[ac] == q) {
									ae = (ac / c);
									af = (ac % c);
									ah = AvolittyPathfinderA(a, aa, b, ah, ai, aj, ak, c, d, e, ae, af, h, i, j, k, zz);

									if (ab != ah) {
										ai = ah;
									}
								}
							}

							k[h] = q;
						}
					} else {
						if (*aa > e) {
							ai = e;
							ae = (h + n);

							if (k[ae] == v) {
								ag = ad;
							} else {
								ag = t;
							}
						}
					}
				}

				h -= n;
				i--;
				j++;

				if (ag == z) {
					ag = s;

					if (ab != ai) {
						ag = u;
					}
				}

				while (h != l) {
					i--;
					j++;
					k[h] -= ag;
					h -= n;
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

				/* down right traversal [] */

				if ((k[h] == z) || (k[h] == u)) {
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

						if ((f == i) && (g == j) && (k[h] == q)) {
							if (b != h) {
								ac = d;
								k[h] = t;

								while (ab != ac) {
									ac--;

									if (k[ac] == q) {
										ae = (ac / c);
										af = (ac % c);
										ah = AvolittyPathfinderA(a, aa, b, ah, ai, aj, ak, c, d, e, ae, af, h, i, j, k, zz);

										if (ab != ah) {
											ai = ah;
										}
									}
								}

								k[h] = q;
							} else {
								if (*aa > e) {
									ai = e;
									ae = (h - o);

									if (k[ae] == v) {
										ag = ad;
									} else {
										ag = t;
									}
								}
							}

							h -= o;
							j--;

							if (ag == z) {
								ag = s;

								if (ab != ai) {
									ag = u;
								}
							}

							while (h != m) {
								k[h] -= ag;
								h -= o;
								j--;
							}

							k[h] -= ag;
						} else {
							h -= o;
							j--;

							while (h != m) {
								k[h] -= s;
								h -= o;
								j--;
							}

							k[h] -= s;
							ag = s;
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

						if ((f == i) && (g == j) && (k[h] == q)) {
							if (b != h) {
								ac = d;
								k[h] = t;

								while (ab != ac) {
									ac--;

									if (k[ac] == q) {
										ae = (ac / c);
										af = (ac % c);
										ah = AvolittyPathfinderA(a, aa, b, ah, ai, aj, ak, c, d, e, ae, af, h, i, j, k, zz);

										if (ab != ah) {
											ai = ah;
										}
									}
								}

								k[h] = q;
							} else {
								if (*aa > e) {
									ai = e;
									ae = (h - o);

									if (k[ae] == v) {
                                                                		ag = ad;
									} else {
										ag = t;
									}
								}
							}

							h -= o;
							i--;

							if (ag == z) {
								ag = s;

								if (ab != ai) {
									ag = u;
								}
							}

							while (h != m) {
								k[h] -= ag;
								h -= o;
								i--;
							}

							k[h] -= ag;
						} else {
							h -= o;
							i--;

							while (h != m) {
								k[h] -= s;
								h -= o;
								i--;
							}

							k[h] -= s;
							ag = s;
						}
					}
				} else {
					if (b != h) {
						if ((f == i) && (g == j) && (k[h] == q)) {
							ac = d;
							k[h] = t;

							while (ab != ac) {
								ac--;

								if (k[ac] == q) {
									ae = (ac / c);
									af = (ac % c);
									ah = AvolittyPathfinderA(a, aa, b, ah, ai, aj, ak, c, d, e, ae, af, h, i, j, k, zz);

									if (ab != ah) {
										ai = ah;
									}
								}
							}

							k[h] = q;
						}
					} else {
						if (*aa > e) {
							ai = e;
							ae = (h - n);

							if (k[ae] == v) {
								ag = ad;
							} else {
								ag = t;
							}
						}
					}
				}

				h -= n;
				i--;
				j--;

				if (ag == z) {
					ag = s;

					if (ab != ai) {
						ag = u;
					}
				}

				while (h != l) {
					i--;
					j--;
					k[h] -= ag;
					h -= n;
				}
			}
		}
	}

	if ((ag == t) || (ag == ad)) {
		ac = d;
		*aa = e;

		while (ab != ac) {
			ac--;

			if (k[ac] == w) {
				k[ac] += w;
			} else {
				if (k[ac] == u || k[ac] == v) {
					k[ac] -= u;
				}
			}
		}
	}

	return ai;
}

unsigned long int AvolittyPathfinderB(unsigned long int * a, unsigned long int r, unsigned long int q, unsigned long int b, unsigned long int c, unsigned long int d, unsigned long int e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned char * j) {
	/*
		* a -> [array] traversal direction increments
		r -> [integer] grid height
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
	y = &l;
	p = ((unsigned char) 5U);

	while (k != o) {
		k--;

		if (j[k] == p) {
			m = (k / q);
			n = (k % q);
			AvolittyPathfinderA(a, y, b, g, h, i, r, q, c, d, m, n, g, h, i, j, g);
	        }
	}

	k = c;
	printf("%u ", j[o++]);

        while (k != o) {
                printf("%u ", j[o]);

                if (((o++ + 1UL) % 11UL) == 0UL) {
                        printf("\n");
                }
        }

        printf("\n");
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
	d[(unsigned char) 3U] = g;
	d[r] = g;
	d[s] = d[p];
	d[t] = (b + g);
	d[((unsigned char) 5U)] = d[t];
	d[((unsigned char) 6U)] = g;
	d[((unsigned char) 7U)] = b;
	d[((unsigned char) 8U)] = b;
	d[((unsigned char) 9U)] = b;
	g--;
	/*
		* d -> [array] traversal direction increments
		a -> [integer] grid height
		b -> [integer] grid width
		e -> [integer] dst pos
		f -> [integer] grid length
		g -> [integer] traversal steps
		i -> [integer] dst height
		j -> [integer] dst width
		k -> [integer] cur src pos
		l -> [integer] cur src height
		m -> [integer] cur src width
		* c -> [array] grid
	*/
	g = AvolittyPathfinderB(d, a, b, e, f, g, i, j, k, l, m, c);
	printf("\n");
	/* .. */
	return;
}
