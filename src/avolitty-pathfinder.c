#include <stdio.h>

unsigned long int AvolittyPathfinderA(unsigned long int * a, unsigned long int * aa, unsigned long int b, unsigned long int ah, unsigned long int ai, unsigned long int c, unsigned long int d, unsigned long int e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned long int j, unsigned char * k) {
	/* alphabetizing and deleting unused variables with a maximum of 26 variables per function scope */
	unsigned long int ab;
	unsigned long int ac;
	unsigned char ad;
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
	unsigned long int y;
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
	z = ((unsigned char) 0U);
	ag = s;

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

				if (*aa > e) {
					if (b != h) {
						if ((f == i) && (g == j)) {
							ac = d;
							y = k[h];
							k[h] = t;

							while (ab != ac) {
								ac--;

								if ((k[ac] == q) || (k[ac] == r)) {
									ah = AvolittyPathfinderA(a, aa, b, ah, ai, c, d, e, ac / c, ac % c, h, i, j, k);

									if (ab != ah) {
										ai = ah;
									}
								}
							}

							if (ab == ai) {
								k[h] = y;
							} else {
								k[h] = r;
							}
						}
					} else {
						ai = e;
						ac = (h + n);

						if (k[ac] == v) {
							ag = ad;
						} else {
							ag = t;
						}
					}
				}

				h += n;
				j++;

				if (ag == s) {
					if (ab != ai) {
						ag = u;
					}

					while (h != l) {
						j++;
						k[h] -= ag;
						h += n;
					}
				} else {
					while (h != l) {
						j++;

						if (k[h] == v) {
							k[h] -= ad;
						} else {
							k[h] -= t;
						}

						h += n;
					}
				}
			} else {
				i--;

				while ((k[h] < q) && (f != i)) {
					e++;
					i--;
					k[h] += s;
					h -= n;
				}

				if (*aa > e) {
					if (b != h) {
						if ((f == i) && (g == j)) {
							ac = d;
							y = k[h];
							k[h] = t;

							while (ab != ac) {
								ac--;

								if ((k[ac] == q) || (k[ac] == r)) {
									ah = AvolittyPathfinderA(a, aa, b, ah, ai, c, d, e, ac / c, ac % c, h, i, j, k);

									if (ab != ah) {
										ai = ah;
									}
								}
							}

							if (ab == ai) {
								k[h] = y;
							} else {
								k[h] = r;
							}
						}
					} else {
						ai = e;
						ac = (h + n);

						if (k[ac] == v) {
							ag = ad;
						} else {
							ag = t;
						}
					}
				}

				h += n;
				i++;

				if (ag == s) {
					ag = s;

					if (ab != ai) {
						ag = u;
					}

					while (h != l) {
						i++;
						k[h] -= ag;
						h += n;
					}
				} else {
					while (h != l) {
						i++;

						if (k[h] == v) {
							k[h] -= ad;
						} else {
							k[h] -= t;
						}

						h += n;
					}
				}
			}
		} else {
			i--;

			if (p == u) {
				j++;

				while (((k[h] < q) && (f != i)) && (g != j)) {
					e++;
					i--;
					j++;
					k[h] += s;
					h -= n;
				}

				if (*aa > e) {
					if ((k[h] == z) || (k[h] == u)) {
						e++;
						k[h] += s;
						m = h;

						if (f == i) {
							o = a[w];
							h += o;
							j++;

							while ((k[h] < q) && (g != j)) {
								e++;
								k[h] += s;
								h += o;
								j++;
							}

							if ((((*aa > e) && (f == i)) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								if (b != h) {
									ac = d;
									y = k[h];
									k[h] = t;

									while (ab != ac) {
										ac--;

										if ((k[ac] == q) || (k[ac] == r)) {
											ah = AvolittyPathfinderA(a, aa, b, ah, ai, c, d, e, ac / c, ac % c, h, i, j, k);

											if (ab != ah) {
												ai = ah;
											}
										}
									}

									if (ab == ai) {
										k[h] = y;
									} else {
										k[h] = r;
									}
								} else {
									ai = e;
									ag = t;
									ac = (h - o);

									if (k[ac] == v) {
										ag = ad;
									} else {
										ag = t;
									}
								}

								h -= o;
								j--;

								if (ag == s) {
									if (ab != ai) {
										ag = u;
									}

									while (h != m) {
										k[h] -= ag;
										h -= o;
										j--;
									}

									k[h] -= ag;
									ag = s;
								} else {
									while (h != m) {
										if (k[h] == v) {
											k[h] -= ad;
										} else {
											k[h] -= t;
										}

										h -= o;
										j--;
									}

									if (k[h] == v) {
										k[h] -= ad;
									} else {
										k[h] -= t;
									}
								}
							} else {
								h -= o;
								j--;

								while (h != m) {
									k[h] -= s;
									h -= o;
									j--;
								}

								k[h] -= s;
							}
						} else {
							o = a[s];
							h -= o;
							i--;

							while ((k[h] < q) && (f != i)) {
								e++;
								k[h] += s;
								h -= o;
								i--;
							}

							if ((((*aa > e) && (f == i)) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								if (b != h) {
									ac = d;
									y = k[h];
									k[h] = t;

									while (ab != ac) {
										ac--;

										if ((k[ac] == q) || (k[ac] == r)) {
											ah = AvolittyPathfinderA(a, aa, b, ah, ai, c, d, e, ac / c, ac % c, h, i, j, k);

											if (ab != ah) {
												ai = ah;
											}
										}
									}

									if (ab == ai) {
										k[h] = y;
									} else {
										k[h] = r;
									}
								} else {
									ai = e;
									ac = (h + o);

									if (k[ac] == v) {
										ag = ad;
									} else {
										ag = t;
									}
								}

								h += o;
								i++;

								if (ag == s) {
									if (ab != ai) {
										ag = u;
									}

									while (h != m) {
										k[h] -= ag;
										h += o;
										i++;
									}

									k[h] -= ag;
									ag = s;
								} else {
									while (h != m) {
										if (k[h] == v) {
											k[h] -= ad;
										} else {
											k[h] -= t;
										}

										h += o;
										i++;
									}

									if (k[h] == v) {
										k[h] -= ad;
									} else {
										k[h] -= t;
									}
								}
							} else {
								h += o;
								i++;

								while (h != m) {
									k[h] -= s;
									h += o;
									i++;
								}

								k[h] -= s;
							}
						}
					} else {
						if (b != h) {
							if (((f == i) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								ac = d;
								y = k[h];
								k[h] = t;

								while (ab != ac) {
									ac--;

									if ((k[ac] == q) || (k[ac] == r)) {
										ah = AvolittyPathfinderA(a, aa, b, ah, ai, c, d, e, ac / c, ac % c, h, i, j, k);

										if (ab != ah) {
											ai = ah;
										}
									}
								}

								if (ab == ai) {
									k[h] = y;
								} else {
									k[h] = r;
								}
							}
						} else {
							ai = e;
							ac = (h + n);

							if (k[ac] == v) {
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

				if (ag == s) {
					if (ab != ai) {
						ag = u;
					}

					while (h != l) {
						i++;
						j--;
						k[h] -= ag;
						h += n;
					}
				} else {
					while (h != l) {
						i++;
						j--;

						if (k[h] == v) {
							k[h] -= ad;
						} else {
							k[h] -= t;
						}

						h += n;
					}
				}
			} else {
				j--;

				while (((k[h] < q) && (f != i)) && (g != j)) {
					e++;
					i--;
					j--;
					k[h] += s;
					h -= n;
				}

				if (*aa > e) {
					if ((k[h] == z) || (k[h] == u)) {
						e++;
						k[h] += s;
						m = h;

						if (f == i) {
							o = a[w];
							h -= o;
							j--;

							while ((k[h] < q) && (g != j)) {
								e++;
								k[h] += s;
								h -= o;
								j--;
							}

							if ((((*aa > e) && (f == i)) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								if (b != h) {
									ac = d;
									y = k[h];
									k[h] = t;

									while (ab != ac) {
										ac--;

										if ((k[ac] == q) || (k[ac] == r)) {
											ah = AvolittyPathfinderA(a, aa, b, ah, ai, c, d, e, ac / c, ac % c, h, i, j, k);

											if (ab != ah) {
												ai = ah;
											}
										}
									}

									if (ab == ai) {
										k[h] = y;
									} else {
										k[h] = r;
									}
								} else {
									ai = e;
									ac = (h + o);

									if (k[ac] == v) {
										ag = ad;
									} else {
										ag = t;
									}
								}

								h += o;
								j++;

								if (ag == s) {
									if (ab != ai) {
										ag = u;
									}

									while (h != m) {
										k[h] -= ag;
										h += o;
										j++;
									}

									k[h] -= ag;
									ag = s;
								} else {
									while (h != m) {
										if (k[h] == v) {
											k[h] -= ad;
										} else {
											k[h] -= t;
										}

										h += o;
										j++;
									}

									if (k[h] == v) {
										k[h] -= ad;
									} else {
										k[h] -= t;
									}
								}
							} else {
								h += o;
								j++;

								while (h != m) {
									k[h] -= s;
									h += o;
									j++;
								}

								k[h] -= s;
							}
						} else {
							o = a[s];
							h -= o;
							i--;

							while ((k[h] < q) && (f != i)) {
								e++;
								k[h] += s;
								h -= o;
								i--;
							}

							if ((((*aa > e) && (f == i)) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								if (b != h) {
									ac = d;
									y = k[h];
									k[h] = t;

									while (ab != ac) {
										ac--;

										if ((k[ac] == q) || (k[ac] == r)) {
											ah = AvolittyPathfinderA(a, aa, b, ah, ai, c, d, e, ac / c, ac % c, h, i, j, k);

											if (ab != ah) {
												ai = ah;
											}
										}
									}

									if (ab == ai) {
										k[h] = y;
									} else {
										k[h] = r;
									}
								} else {
									ai = e;
									ac = (h + o);

									if (k[ac] == v) {
                                	                       		        ag = ad;
									} else {
										ag = t;
									}
								}

								h += o;
								i++;

								if (ag == s) {
									if (ab != ai) {
										ag = u;
									}

									while (h != m) {
										k[h] -= ag;
										h += o;
										i++;
									}

									k[h] -= ag;
									ag = s;
								} else {
									while (h != m) {
										if (k[h] == v) {
											k[h] -= ad;
										} else {
											k[h] -= t;
										}

										h += o;
										i++;
									}

									if (k[h] == v) {
										k[h] -= ad;
									} else {
										k[h] -= t;
									}
								}
							} else {
								h += o;
								i++;

								while (h != m) {
									k[h] -= s;
									h += o;
									i++;
								}

								k[h] -= s;
							}
						}
					} else {
						if (b != h) {
							if (((f == i) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								ac = d;
								y = k[h];
								k[h] = t;

								while (ab != ac) {
									ac--;

									if ((k[ac] == q) || (k[ac] == r)) {
										ah = AvolittyPathfinderA(a, aa, b, ah, ai, c, d, e, ac / c, ac % c, h, i, j, k);

										if (ab != ah) {
											ai = ah;
										}
									}
								}

								if (ab == ai) {
									k[h] = y;
								} else {
									k[h] = r;
								}
							}
						} else {
							ai = e;
							ac = (h + n);

							if (k[ac] == v) {
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

				if (ag == s) {
					if (ab != ai) {
						ag = u;
					}

					while (h != l) {
						i++;
						j++;
						k[h] -= ag;
						h += n;
					}
				} else {
					while (h != l) {
						i++;
						j++;

						if (k[h] == v) {
							k[h] -= ad;
						} else {
							k[h] -= t;
						}

						h += n;
					}
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

				if (*aa > e) {
					if (b != h) {
						if ((f == i) && (g == j)) {
							ac = d;
							y = k[h];
							k[h] = t;

							while (ab != ac) {
								ac--;

								if ((k[ac] == q) || (k[ac] == r)) {
									ah = AvolittyPathfinderA(a, aa, b, ah, ai, c, d, e, ac / c, ac % c, h, i, j, k);

									if (ab != ah) {
										ai = ah;
									}
								}
							}

							if (ab == ai) {
								k[h] = y;
							} else {
								k[h] = r;
							}
						}
					} else {
						ai = e;
						ac = (h - n);

						if (k[ac] == v) {
							ag = ad;
						} else {
							ag = t;
						}
					}
				}

				h -= n;
				j--;

				if (ag == s) {
					if (ab != ai) {
						ag = u;
					}

					while (h != l) {
						j--;
						k[h] -= ag;
						h -= n;
					}
				} else {
					while (h != l) {
						j--;

						if (k[h] == v) {
							k[h] -= ad;
						} else {
							k[h] -= t;
						}

						h -= n;
					}
				}
			} else {
				i++;

				while ((k[h] < q) && (f != i)) {
					e++;
					i++;
					k[h] += s;
					h += n;
				}

				if (*aa > e) {
					if (b != h) {
						if ((f == i) && (g == j)) {
							ac = d;
							y = k[h];
							k[h] = t;

							while (ab != ac) {
								ac--;

								if ((k[ac] == q) || (k[ac] == r)) {
									ah = AvolittyPathfinderA(a, aa, b, ah, ai, c, d, e, ac / c, ac % c, h, i, j, k);

									if (ab != ah) {
										ai = ah;
									}
								}
							}

							if (ab == ai) {
								k[h] = y;
							} else {
								k[h] = r;
							}
						}
					} else {
						ai = e;
						ac = (h - n);

						if (k[ac] == v) {
							ag = ad;
						} else {
							ag = t;
						}
					}
				}

				h -= n;
				i--;

				if (ag == s) {
					if (ab != ai) {
						ag = u;
					}

					while (h != l) {
						i--;
						k[h] -= ag;
						h -= n;
					}
				} else {
					while (h != l) {
						i--;

						if (k[h] == v) {
							k[h] -= ad;
						} else {
							k[h] -= t;
						}

						h -= n;
					}
				}
			}
		} else {
			i++;

			if (p == x) {
				j--;

				while (((k[h] < q) && (f != i)) && (g != j)) {
					e++;
					i++;
					j--;
					k[h] += s;
					h += n;
				}

				if (*aa > e) {
					if ((k[h] == z) || (k[h] == u)) {
						e++;
						k[h] += s;
						m = h;

						if (f == i) {
							o = a[w];
							h -= o;
							j--;

							while ((k[h] < q) && (g != j)) {
								e++;
								k[h] += s;
								h -= o;
								j--;
							}

							if ((((*aa > e) && (f == i)) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								if (b != h) {
									ac = d;
									y = k[h];
									k[h] = t;

									while (ab != ac) {
										ac--;

										if ((k[ac] == q) || (k[ac] == r)) {
											ah = AvolittyPathfinderA(a, aa, b, ah, ai, c, d, e, ac / c, ac % c, h, i, j, k);

											if (ab != ah) {
												ai = ah;
											}
										}
									}

									if (ab == ai) {
										k[h] = y;
									} else {
										k[h] = r;
									}
								} else {
									ai = e;
									ac = (h + o);

									if (k[ac] == v) {
										ag = ad;
									} else {
										ag = t;
									}
								}

								h += o;
								j++;

								if (ag == s) {
									if (ab != ai) {
										ag = u;
									}

									while (h != m) {
										k[h] -= ag;
										h += o;
										j++;
									}

									k[h] -= ag;
									ag = s;
								} else {
									while (h != m) {
										if (k[h] == v) {
											k[h] -= ad;
										} else {
											k[h] -= t;
										}

										h += o;
										j++;
									}

									if (k[h] == v) {
										k[h] -= ad;
									} else {
										k[h] -= t;
									}
								}
							} else {
								h += o;
								j++;

								while (h != m) {
									k[h] -= s;
									h += o;
									j++;
								}

								k[h] -= s;
							}
						} else {
							o = a[s];
							h += o;
							i++;

							while ((k[h] < q) && (f != i)) {
								e++;
								k[h] += s;
								h += o;
								i++;
							}

							if ((((*aa > e) && (f == i)) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								if (b != h) {
									ac = d;
									y = k[h];
									k[h] = t;

									while (ab != ac) {
										ac--;

										if ((k[ac] == q) || (k[ac] == r)) {
											ah = AvolittyPathfinderA(a, aa, b, ah, ai, c, d, e, ac / c, ac % c, h, i, j, k);

											if (ab != ah) {
												ai = ah;
											}
										}
									}

									if (ab == ai) {
										k[h] = y;
									} else {
										k[h] = r;
									}
								} else {
									ai = e;
									ac = (h - o);

									if (k[ac] == v) {
										ag = ad;
									} else {
										ag = t;
									}
								}

								h -= o;
								i--;

								if (ag == s) {
									if (ab != ai) {
										ag = u;
									}

									while (h != m) {
										k[h] -= ag;
										h -= o;
										i--;
									}

									k[h] -= ag;
									ag = s;
								} else {
									while (h != m) {
										if (k[h] == v) {
											k[h] -= ad;
										} else {
											k[h] -= t;
										}

										h -= o;
										i--;
									}

									if (k[h] == v) {
										k[h] -= ad;
									} else {
										k[h] -= t;
									}
								}
							} else {
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
					} else {
						if (b != h) {
							if (((f == i) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								ac = d;
								y = k[h];
								k[h] = t;

								while (ab != ac) {
									ac--;

									if ((k[ac] == q) || (k[ac] == r)) {
										ah = AvolittyPathfinderA(a, aa, b, ah, ai, c, d, e, ac / c, ac % c, h, i, j, k);

										if (ab != ah) {
											ai = ah;
										}
									}
								}

								if (ab == ai) {
									k[h] = y;
								} else {
									k[h] = r;
								}
							}
						} else {
							ai = e;
							ac = (h + n);

							if (k[ac] == v) {
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

				if (ag == s) {
					if (ab != ai) {
						ag = u;
					}

					while (h != l) {
						i--;
						j++;
						k[h] -= ag;
						h -= n;
					}
				} else {
					while (h != l) {
						i--;
						j++;

						if (k[h] == v) {
							k[h] -= ad;
						} else {
							k[h] -= t;
						}

						h -= n;
					}
				}
			} else {
				j++;

				while (((k[h] < q) && (f != i)) && (g != j)) {
					e++;
					i++;
					j++;
					k[h] += s;
					h += n;
				}

				if (*aa > e) {
					if ((k[h] == z) || (k[h] == u)) {
						e++;
						k[h] += s;
						m = h;

						if (f == i) {
							o = a[w];
							h += o;
							j++;

							while ((k[h] < q) && (g != j)) {
								e++;
								k[h] += s;
								h += o;
								j++;
							}

							if ((((*aa > e) && (f == i)) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								if (b != h) {
									ac = d;
									y = k[h];
									k[h] = t;

									while (ab != ac) {
										ac--;

										if ((k[ac] == q) || (k[ac] == r)) {
											ah = AvolittyPathfinderA(a, aa, b, ah, ai, c, d, e, ac / c, ac % c, h, i, j, k);

											if (ab != ah) {
												ai = ah;
											}
										}
									}

									if (ab == ai) {
										k[h] = y;
									} else {
										k[h] = r;
									}
								} else {
									ai = e;
									ac = (h - o);

									if (k[ac] == v) {
										ag = ad;
									} else {
										ag = t;
									}
								}

								h -= o;
								j--;

								if (ag == s) {
									if (ab != ai) {
										ag = u;
									}

									while (h != m) {
										k[h] -= ag;
										h -= o;
										j--;
									}

									k[h] -= ag;
									ag = s;
								} else {
									while (h != m) {
										if (k[h] == v) {
											k[h] -= ad;
										} else {
											k[h] -= t;
										}

										h -= o;
										j--;
									}

									if (k[h] == v) {
										k[h] -= ad;
									} else {
										k[h] -= t;
									}
								}
							} else {
								h -= o;
								j--;

								while (h != m) {
									k[h] -= s;
									h -= o;
									j--;
								}

								k[h] -= s;
							}
						} else {
							o = a[s];
							h += o;
							i++;

							while ((k[h] < q) && (f != i)) {
								e++;
								k[h] += s;
								h += o;
								i++;
							}

							if ((((*aa > e) && (f == i)) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								if (b != h) {
									ac = d;
									y = k[h];
									k[h] = t;

									while (ab != ac) {
										ac--;

										if ((k[ac] == q) || (k[ac] == r)) {
											ah = AvolittyPathfinderA(a, aa, b, ah, ai, c, d, e, ac / c, ac % c, h, i, j, k);

											if (ab != ah) {
												ai = ah;
											}
										}
									}

									if (ab == ai) {
										k[h] = y;
									} else {
										k[h] = r;
									}
								} else {
									ai = e;
									ac = (h - o);

									if (k[ac] == v) {
                                	                               		ag = ad;
									} else {
										ag = t;
									}
								}

								h -= o;
								i--;

								if (ag == s) {
									if (ab != ai) {
										ag = u;
									}

									while (h != m) {
										k[h] -= ag;
										h -= o;
										i--;
									}

									k[h] -= ag;
									ag = s;
								} else {
									while (h != m) {
										if (k[h] == v) {
											k[h] -= ad;
										} else {
											k[h] -= t;
										}

										h -= o;
										i--;
									}

									if (k[h] == v) {
										k[h] -= ad;
									} else {
										k[h] -= t;
									}
								}
							} else {
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
					} else {
						if (b != h) {
							if (((f == i) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								ac = d;
								y = k[h];
								k[h] = t;

								while (ab != ac) {
									ac--;

									if ((k[ac] == q) || (k[ac] == r)) {
										ah = AvolittyPathfinderA(a, aa, b, ah, ai, c, d, e, ac / c, ac % c, h, i, j, k);

										if (ab != ah) {
											ai = ah;
										}
									}
								}

								if (ab == ai) {
									k[h] = y;
								} else {
									k[h] = r;
								}
							}
						} else {
							ai = e;
							ac = (h - n);

							if (k[ac] == v) {
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

				if (ag == s) {
					if (ab != ai) {
						ag = u;
					}

					while (h != l) {
						i--;
						j--;
						k[h] -= ag;
						h -= n;
					}
				} else {
					while (h != l) {
						i--;
						j--;

						if (k[h] == v) {
							k[h] -= ad;
						} else {
							k[h] -= t;
						}

						h -= n;
					}
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
				if (k[ac] == r) {
					k[ac] = q;
				} else {
					if (k[ac] == u || k[ac] == v) {
						k[ac] -= u;
					}
				}
			}
		}
	}

	return ai;
}

unsigned long int AvolittyPathfinderB(unsigned long int * a, unsigned long int r, unsigned long int q, unsigned long int b, unsigned long int c, unsigned long int d, unsigned long int e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned char * j) {
	unsigned long int k;
	unsigned long int l;
	unsigned long int m;
	unsigned long int n;
	unsigned long int o;
	unsigned long int x;
	unsigned long int * y;
	unsigned long int z;
	unsigned char p;
	unsigned char s;
	k = c;
	l = c;
	o = ((unsigned long int) 0UL);
	y = &l;
	p = ((unsigned char) 9U);
	s = ((unsigned char) 5U);

	while (k != o) {
		k--;

		if ((j[k] == p) || (j[k] == s)) {
			m = (k / q);
			n = (k % q);
			AvolittyPathfinderA(a, y, b, g, h, q, c, d, m, n, g, h, i, j);
		}
	}

	k = c;

	while (k != o) {
		k--;

		if ((j[k] == p) || (j[k] == s)) {
			j[k] -= s;
		}
	}

	return l;
}

unsigned long int AvolittyPathfinder(unsigned long int a, unsigned long int b, unsigned char * c) {
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
	g = AvolittyPathfinderB(d, a, b, e, f, g, i, j, k, l, m, c);
	c[k] = s;
	c[e] = r;
	return g;
}
