#include <stdio.h>

unsigned long int AvolittyPathfinderA(unsigned long int * a, unsigned long int b, unsigned long int ai, unsigned long int c, unsigned long int d, unsigned long int e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned long int j, unsigned long int af, unsigned long int ag, unsigned long int ah, unsigned char * k) {
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
	unsigned long int aa;
	ab = ((unsigned long int) 0UL);
	e++;
	l = h;
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
	p = z;

	if (f > i) {
		p = x;
	} else {
		if (f == i) {
			p = w;
		}
	}

	if (g > j) {
		p += u;
	} else {
		if (g == j) {
			p += s;
		}
	}

	ai = ab;

	if (((p & x) == z) && (p != t)) {
		if ((p == w) || (p == s)) {
			if (p == w) {
				h -= af;
				j--;
				p = s;

				while ((k[h] < q) && (g != j)) {
					e++;
					j--;
					k[h] += s;
					h -= af;
				}

				if (*a > e) {
					if (b != h) {
						if ((f == i) && (g == j)) {
							ac = d;
							y = k[h];
							k[h] = t;
							f = ag;
							g = ah;

							while (ab != ac) {
								ac--;

								if (g == ab) {
									f--;
									g = ah;
								}

								g--;

								if (((k[ac] == q) || (k[ac] == r)) && ((f != i) || (g != j))) {
									aa = AvolittyPathfinderA(a, b, ai, c, d, e, f, g, h, i, j, af, ag, ah, k);

									if (ab != aa) {
										ai = aa;
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
						ac = (h + af);

						if (k[ac] == v) {
							p = ad;
						} else {
							p = t;
						}
					}
				}

				h += af;
				j++;

				if (p == s) {
					if (ab != ai) {
						p = u;
					}

					while (h != l) {
						j++;
						k[h] -= p;
						h += af;
					}
				} else {
					while (h != l) {
						j++;

						if (k[h] == v) {
							k[h] -= ad;
						} else {
							k[h] -= t;
						}

						h += af;
					}
				}
			} else {
				h -= c;
				i--;
				p = s;

				while ((k[h] < q) && (f != i)) {
					e++;
					i--;
					k[h] += s;
					h -= c;
				}

				if (*a > e) {
					if (b != h) {
						if ((f == i) && (g == j)) {
							ac = d;
							y = k[h];
							k[h] = t;
							f = ag;
							g = ah;

							while (ab != ac) {
								ac--;

								if (g == ab) {
									f--;
									g = ah;
								}

								g--;

								if (((k[ac] == q) || (k[ac] == r)) && ((f != i) || (g != j))) {
									aa = AvolittyPathfinderA(a, b, ai, c, d, e, f, g, h, i, j, af, ag, ah, k);

									if (ab != aa) {
										ai = aa;
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
						ac = (h + c);

						if (k[ac] == v) {
							p = ad;
						} else {
							p = t;
						}
					}
				}

				h += c;
				i++;

				if (p == s) {
					if (ab != ai) {
						p = u;
					}

					while (h != l) {
						i++;
						k[h] -= p;
						h += c;
					}
				} else {
					while (h != l) {
						i++;

						if (k[h] == v) {
							k[h] -= ad;
						} else {
							k[h] -= t;
						}

						h += c;
					}
				}
			}
		} else {
			i--;

			if (p == u) {
				n = (c - af);
				h -= n;
				j++;
				p = s;

				while (((k[h] < q) && (f != i)) && (g != j)) {
					e++;
					i--;
					j++;
					k[h] += s;
					h -= n;
				}

				if (*a > e) {
					if ((k[h] == z) || (k[h] == u)) {
						e++;
						k[h] += s;
						m = h;

						if (f == i) {
							h += af;
							j++;

							while ((k[h] < q) && (g != j)) {
								e++;
								k[h] += s;
								h += af;
								j++;
							}

							if ((((*a > e) && (f == i)) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								if (b != h) {
									ac = d;
									y = k[h];
									k[h] = t;
									f = ag;
									g = ah;

									while (ab != ac) {
										ac--;

										if (g == ab) {
											f--;
											g = ah;
										}

										g--;

										if (((k[ac] == q) || (k[ac] == r)) && ((f != i) || (g != j))) {
											aa = AvolittyPathfinderA(a, b, ai, c, d, e, f, g, h, i, j, af, ag, ah, k);

											if (ab != aa) {
												ai = aa;
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
									p = t;
									ac = (h - af);

									if (k[ac] == v) {
										p = ad;
									} else {
										p = t;
									}
								}

								h -= af;
								j--;

								if (p == s) {
									if (ab != ai) {
										p = u;
									}

									while (h != m) {
										k[h] -= p;
										h -= af;
										j--;
									}

									k[h] -= p;
									p = s;
								} else {
									while (h != m) {
										if (k[h] == v) {
											k[h] -= ad;
										} else {
											k[h] -= t;
										}

										h -= af;
										j--;
									}

									if (k[h] == v) {
										k[h] -= ad;
									} else {
										k[h] -= t;
									}
								}
							} else {
								h -= af;
								j--;

								while (h != m) {
									k[h] -= s;
									h -= af;
									j--;
								}

								k[h] -= s;
							}
						} else {
							h -= c;
							i--;

							while ((k[h] < q) && (f != i)) {
								e++;
								k[h] += s;
								h -= c;
								i--;
							}

							if ((((*a > e) && (f == i)) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								if (b != h) {
									ac = d;
									y = k[h];
									k[h] = t;
									f = ag;
									g = ah;

									while (ab != ac) {
										ac--;

										if (g == ab) {
											f--;
											g = ah;
										}

										g--;

										if (((k[ac] == q) || (k[ac] == r)) && ((f != i) || (g != j))) {
											aa = AvolittyPathfinderA(a, b, ai, c, d, e, f, g, h, i, j, af, ag, ah, k);

											if (ab != aa) {
												ai = aa;
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
									ac = (h + c);

									if (k[ac] == v) {
										p = ad;
									} else {
										p = t;
									}
								}

								h += c;
								i++;

								if (p == s) {
									if (ab != ai) {
										p = u;
									}

									while (h != m) {
										k[h] -= p;
										h += c;
										i++;
									}

									k[h] -= p;
									p = s;
								} else {
									while (h != m) {
										if (k[h] == v) {
											k[h] -= ad;
										} else {
											k[h] -= t;
										}

										h += c;
										i++;
									}

									if (k[h] == v) {
										k[h] -= ad;
									} else {
										k[h] -= t;
									}
								}
							} else {
								h += c;
								i++;

								while (h != m) {
									k[h] -= s;
									h += c;
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
								f = ag;
								g = ah;

								while (ab != ac) {
									ac--;

									if (g == ab) {
										f--;
										g = ah;
									}

									g--;

									if (((k[ac] == q) || (k[ac] == r)) && ((f != i) || (g != j))) {
										aa = AvolittyPathfinderA(a, b, ai, c, d, e, f, g, h, i, j, af, ag, ah, k);

										if (ab != aa) {
											ai = aa;
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
								p = ad;
							} else {
								p = t;
							}
						}
					}
				}

				h += n;
				i++;
				j--;

				if (p == s) {
					if (ab != ai) {
						p = u;
					}

					while (h != l) {
						i++;
						j--;
						k[h] -= p;
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
				n = (c + af);
				h -= n;
				j--;
				p = s;

				while (((k[h] < q) && (f != i)) && (g != j)) {
					e++;
					i--;
					j--;
					k[h] += s;
					h -= n;
				}

				if (*a > e) {
					if ((k[h] == z) || (k[h] == u)) {
						e++;
						k[h] += s;
						m = h;

						if (f == i) {
							h -= af;
							j--;

							while ((k[h] < q) && (g != j)) {
								e++;
								k[h] += s;
								h -= af;
								j--;
							}

							if ((((*a > e) && (f == i)) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								if (b != h) {
									ac = d;
									y = k[h];
									k[h] = t;
									f = ag;
									g = ah;

									while (ab != ac) {
										ac--;

										if (g == ab) {
											f--;
											g = ah;
										}

										g--;

										if (((k[ac] == q) || (k[ac] == r)) && ((f != i) || (g != j))) {
											aa = AvolittyPathfinderA(a, b, ai, c, d, e, f, g, h, i, j, af, ag, ah, k);

											if (ab != aa) {
												ai = aa;
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
									ac = (h + af);

									if (k[ac] == v) {
										p = ad;
									} else {
										p = t;
									}
								}

								h += af;
								j++;

								if (p == s) {
									if (ab != ai) {
										p = u;
									}

									while (h != m) {
										k[h] -= p;
										h += af;
										j++;
									}

									k[h] -= p;
									p = s;
								} else {
									while (h != m) {
										if (k[h] == v) {
											k[h] -= ad;
										} else {
											k[h] -= t;
										}

										h += af;
										j++;
									}

									if (k[h] == v) {
										k[h] -= ad;
									} else {
										k[h] -= t;
									}
								}
							} else {
								h += af;
								j++;

								while (h != m) {
									k[h] -= s;
									h += af;
									j++;
								}

								k[h] -= s;
							}
						} else {
							h -= c;
							i--;

							while ((k[h] < q) && (f != i)) {
								e++;
								k[h] += s;
								h -= c;
								i--;
							}

							if ((((*a > e) && (f == i)) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								if (b != h) {
									ac = d;
									y = k[h];
									k[h] = t;
									f = ag;
									g = ah;

									while (ab != ac) {
										ac--;

										if (g == ab) {
											f--;
											g = ah;
										}

										g--;

										if (((k[ac] == q) || (k[ac] == r)) && ((f != i) || (g != j))) {
											aa = AvolittyPathfinderA(a, b, ai, c, d, e, f, g, h, i, j, af, ag, ah, k);

											if (ab != aa) {
												ai = aa;
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
									ac = (h + c);

									if (k[ac] == v) {
										p = ad;
									} else {
										p = t;
									}
								}

								h += c;
								i++;

								if (p == s) {
									if (ab != ai) {
										p = u;
									}

									while (h != m) {
										k[h] -= p;
										h += c;
										i++;
									}

									k[h] -= p;
									p = s;
								} else {
									while (h != m) {
										if (k[h] == v) {
											k[h] -= ad;
										} else {
											k[h] -= t;
										}

										h += c;
										i++;
									}

									if (k[h] == v) {
										k[h] -= ad;
									} else {
										k[h] -= t;
									}
								}
							} else {
								h += c;
								i++;

								while (h != m) {
									k[h] -= s;
									h += c;
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
								f = ag;
								g = ah;

								while (ab != ac) {
									ac--;

									if (g == ab) {
										f--;
										g = ah;
									}

									g--;

									if (((k[ac] == q) || (k[ac] == r)) && ((f != i) || (g != j))) {
										aa = AvolittyPathfinderA(a, b, ai, c, d, e, f, g, h, i, j, af, ag, ah, k);

										if (ab != aa) {
											ai = aa;
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
								p = ad;
							} else {
								p = t;
							}
						}
					}
				}

				h += n;
				i++;
				j++;

				if (p == s) {
					if (ab != ai) {
						p = u;
					}

					while (h != l) {
						i++;
						j++;
						k[h] -= p;
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
		if ((p == t) || (p == r)) {
			if (p == t) {
				h += af;
				j++;
				p = s;

				while ((k[h] < q) && (g != j)) {
					e++;
					j++;
					k[h] += s;
					h += af;
				}

				if (*a > e) {
					if (b != h) {
						if ((f == i) && (g == j)) {
							ac = d;
							y = k[h];
							k[h] = t;
							f = ag;
							g = ah;

							while (ab != ac) {
								ac--;

								if (g == ab) {
									f--;
									g = ah;
								}

								g--;

								if (((k[ac] == q) || (k[ac] == r)) && ((f != i) || (g != j))) {
									aa = AvolittyPathfinderA(a, b, ai, c, d, e, f, g, h, i, j, af, ag, ah, k);

									if (ab != aa) {
										ai = aa;
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
						ac = (h - af);

						if (k[ac] == v) {
							p = ad;
						} else {
							p = t;
						}
					}
				}

				h -= af;
				j--;

				if (p == s) {
					if (ab != ai) {
						p = u;
					}

					while (h != l) {
						j--;
						k[h] -= p;
						h -= af;
					}
				} else {
					while (h != l) {
						j--;

						if (k[h] == v) {
							k[h] -= ad;
						} else {
							k[h] -= t;
						}

						h -= af;
					}
				}
			} else {
				h += c;
				i++;
				p = s;

				while ((k[h] < q) && (f != i)) {
					e++;
					i++;
					k[h] += s;
					h += c;
				}

				if (*a > e) {
					if (b != h) {
						if ((f == i) && (g == j)) {
							ac = d;
							y = k[h];
							k[h] = t;
							f = ag;
							g = ah;

							while (ab != ac) {
								ac--;

								if (g == ab) {
									f--;
									g = ah;
								}

								g--;

								if (((k[ac] == q) || (k[ac] == r)) && ((f != i) || (g != j))) {
									aa = AvolittyPathfinderA(a, b, ai, c, d, e, f, g, h, i, j, af, ag, ah, k);

									if (ab != aa) {
										ai = aa;
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
						ac = (h - c);

						if (k[ac] == v) {
							p = ad;
						} else {
							p = t;
						}
					}
				}

				h -= c;
				i--;

				if (p == s) {
					if (ab != ai) {
						p = u;
					}

					while (h != l) {
						i--;
						k[h] -= p;
						h -= c;
					}
				} else {
					while (h != l) {
						i--;

						if (k[h] == v) {
							k[h] -= ad;
						} else {
							k[h] -= t;
						}

						h -= c;
					}
				}
			}
		} else {
			i++;

			if (p == x) {
				n = (c - af);
				h += n;
				j--;
				p = s;

				while (((k[h] < q) && (f != i)) && (g != j)) {
					e++;
					i++;
					j--;
					k[h] += s;
					h += n;
				}

				if (*a > e) {
					if ((k[h] == z) || (k[h] == u)) {
						e++;
						k[h] += s;
						m = h;

						if (f == i) {
							h -= af;
							j--;

							while ((k[h] < q) && (g != j)) {
								e++;
								k[h] += s;
								h -= af;
								j--;
							}

							if ((((*a > e) && (f == i)) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								if (b != h) {
									ac = d;
									y = k[h];
									k[h] = t;
									f = ag;
									g = ah;

									while (ab != ac) {
										ac--;

										if (g == ab) {
											f--;
											g = ah;
										}

										g--;

										if (((k[ac] == q) || (k[ac] == r)) && ((f != i) || (g != j))) {
											aa = AvolittyPathfinderA(a, b, ai, c, d, e, f, g, h, i, j, af, ag, ah, k);

											if (ab != aa) {
												ai = aa;
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
									ac = (h + af);

									if (k[ac] == v) {
										p = ad;
									} else {
										p = t;
									}
								}

								h += af;
								j++;

								if (p == s) {
									if (ab != ai) {
										p = u;
									}

									while (h != m) {
										k[h] -= s;
										h += af;
										j++;
									}

									k[h] -= p;
									p = s;
								} else {
									while (h != m) {
										if (k[h] == v) {
											k[h] -= ad;
										} else {
											k[h] -= t;
										}

										h += af;
										j++;
									}

									if (k[h] == v) {
										k[h] -= ad;
									} else {
										k[h] -= t;
									}
								}
							} else {
								h += af;
								j++;

								while (h != m) {
									k[h] -= s;
									h += af;
									j++;
								}

								k[h] -= s;
							}
						} else {
							h += c;
							i++;

							while ((k[h] < q) && (f != i)) {
								e++;
								k[h] += s;
								h += c;
								i++;
							}

							if ((((*a > e) && (f == i)) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								if (b != h) {
									ac = d;
									y = k[h];
									k[h] = t;
									f = ag;
									g = ah;

									while (ab != ac) {
										ac--;

										if (g == ab) {
											f--;
											g = ah;
										}

										g--;

										if (((k[ac] == q) || (k[ac] == r)) && ((f != i) || (g != j))) {
											aa = AvolittyPathfinderA(a, b, ai, c, d, e, f, g, h, i, j, af, ag, ah, k);

											if (ab != aa) {
												ai = aa;
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
									ac = (h - c);

									if (k[ac] == v) {
										p = ad;
									} else {
										p = t;
									}
								}

								h -= c;
								i--;

								if (p == s) {
									if (ab != ai) {
										p = u;
									}

									while (h != m) {
										k[h] -= p;
										h -= c;
										i--;
									}

									k[h] -= p;
									p = s;
								} else {
									while (h != m) {
										if (k[h] == v) {
											k[h] -= ad;
										} else {
											k[h] -= t;
										}

										h -= c;
										i--;
									}

									if (k[h] == v) {
										k[h] -= ad;
									} else {
										k[h] -= t;
									}
								}
							} else {
								h -= c;
								i--;

								while (h != m) {
									k[h] -= s;
									h -= c;
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
								f = ag;
								g = ah;

								while (ab != ac) {
									ac--;

									if (g == ab) {
										f--;
										g = ah;
									}

									g--;

									if (((k[ac] == q) || (k[ac] == r)) && ((f != i) || (g != j))) {
										aa = AvolittyPathfinderA(a, b, ai, c, d, e, f, g, h, i, j, af, ag, ah, k);

										if (ab != aa) {
											ai = aa;
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
								p = ad;
							} else {
								p = t;
							}
						}
					}
				}

				h -= n;
				i--;
				j++;

				if (p == s) {
					if (ab != ai) {
						p = u;
					}

					while (h != l) {
						i--;
						j++;
						k[h] -= p;
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
				n = (c + af);
				h += n;
				j++;
				p = s;

				while (((k[h] < q) && (f != i)) && (g != j)) {
					e++;
					i++;
					j++;
					k[h] += s;
					h += n;
				}

				if (*a > e) {
					if ((k[h] == z) || (k[h] == u)) {
						e++;
						k[h] += s;
						m = h;

						if (f == i) {
							h += af;
							j++;

							while ((k[h] < q) && (g != j)) {
								e++;
								k[h] += s;
								h += af;
								j++;
							}

							if ((((*a > e) && (f == i)) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								if (b != h) {
									ac = d;
									y = k[h];
									k[h] = t;
									f = ag;
									g = ah;

									while (ab != ac) {
										ac--;

										if (g == ab) {
											f--;
											g = ah;
										}

										g--;

										if (((k[ac] == q) || (k[ac] == r)) && ((f != i) || (g != j))) {
											aa = AvolittyPathfinderA(a, b, ai, c, d, e, f, g, h, i, j, af, ag, ah, k);

											if (ab != aa) {
												ai = aa;
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
									ac = (h - af);

									if (k[ac] == v) {
										p = ad;
									} else {
										p = t;
									}
								}

								h -= af;
								j--;

								if (p == s) {
									if (ab != ai) {
										p = u;
									}

									while (h != m) {
										k[h] -= p;
										h -= af;
										j--;
									}

									k[h] -= p;
									p = s;
								} else {
									while (h != m) {
										if (k[h] == v) {
											k[h] -= ad;
										} else {
											k[h] -= t;
										}

										h -= af;
										j--;
									}

									if (k[h] == v) {
										k[h] -= ad;
									} else {
										k[h] -= t;
									}
								}
							} else {
								h -= af;
								j--;

								while (h != m) {
									k[h] -= s;
									h -= af;
									j--;
								}

								k[h] -= s;
							}
						} else {
							h += c;
							i++;

							while ((k[h] < q) && (f != i)) {
								e++;
								k[h] += s;
								h += c;
								i++;
							}

							if ((((*a > e) && (f == i)) && (g == j)) && ((k[h] == q) || (k[h] == r))) {
								if (b != h) {
									ac = d;
									y = k[h];
									k[h] = t;
									f = ag;
									g = ah;

									while (ab != ac) {
										ac--;

										if (g == ab) {
											f--;
											g = ah;
										}

										g--;

										if (((k[ac] == q) || (k[ac] == r)) && ((f != i) || (g != j))) {
											aa = AvolittyPathfinderA(a, b, ai, c, d, e, f, g, h, i, j, af, ag, ah, k);

											if (ab != aa) {
												ai = aa;
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
									ac = (h - c);

									if (k[ac] == v) {
										p = ad;
									} else {
										p = t;
									}
								}

								h -= c;
								i--;

								if (p == s) {
									if (ab != ai) {
										p = u;
									}

									while (h != m) {
										k[h] -= p;
										h -= c;
										i--;
									}

									k[h] -= p;
									p = s;
								} else {
									while (h != m) {
										if (k[h] == v) {
											k[h] -= ad;
										} else {
											k[h] -= t;
										}

										h -= c;
										i--;
									}

									if (k[h] == v) {
										k[h] -= ad;
									} else {
										k[h] -= t;
									}
								}
							} else {
								h -= c;
								i--;

								while (h != m) {
									k[h] -= s;
									h -= c;
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
								f = ag;
								g = ah;

								while (ab != ac) {
									ac--;

									if (g == ab) {
										f--;
										g = ah;
									}

									g--;

									if (((k[ac] == q) || (k[ac] == r)) && ((f != i) || (g != j))) {
										aa = AvolittyPathfinderA(a, b, ai, c, d, e, f, g, h, i, j, af, ag, ah, k);

										if (ab != aa) {
											ai = aa;
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
								p = ad;
							} else {
								p = t;
							}
						}
					}
				}

				h -= n;
				i--;
				j--;

				if (p == s) {
					if (ab != ai) {
						p = u;
					}

					while (h != l) {
						i--;
						j--;
						k[h] -= p;
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

	if ((p == t) || (p == ad)) {
		*a = e;

		while (ab != d) {
			d--;

			if (k[d] == w) {
				k[d] += w;
			} else {
				if (k[d] == r) {
					k[d] = q;
				} else {
					if (k[d] == u || k[d] == v) {
						k[d] -= u;
					}
				}
			}
		}
	}

	return ai;
}

unsigned long int AvolittyPathfinder(unsigned long int a, unsigned long int b, unsigned char * c) {
	unsigned long int * d;
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
	unsigned long int v;
	unsigned long int w;
	unsigned char o;
	unsigned char p;
	unsigned char q;
	unsigned char r;
	unsigned char s;
	unsigned char t;
	unsigned char u;
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
	u = ((unsigned char) 9U);

	while (e != h) {
		e--;
		i = c[e];

		if (i != t) {
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
						if (c[k] == r) {
							v = k;
						} else {
							if (c[k] == s) {
								w = k;
							}
						}

						c[k] = o;
					}

					if (c[l] != q) {
						if (c[l] == r) {
							v = l;
						} else {
							if (c[l] == s) {
								w = l;
							}
						}

						c[l] = o;
					}

					if (c[m] != q) {
						if (c[m] == r) {
							v = m;
						} else {
							if (c[m] == s) {
								w = m;
							}
						}

						c[m] = o;
					}

					if (c[n] != q) {
						if (c[n] == r) {
							v = n;
						} else {
							if (c[n] == s) {
								w = n;
							}
						}

						c[n] = o;
					}
				}
			} else {
				if (i == r) {
					v = e;
				} else {
					if (i == s) {
						w = e;
					}
				}

				c[e] = o;
			}
		}
	}

	a--;
	e = f;
	d = &e;
	l = (w / b);
	m = (w % b);
	i = f;

	while (h != i) {
		i--;

		if (((c[i] == u) || (c[i] == o)) && (i != w)) {
			AvolittyPathfinderA(d, v, l, b, f, h, i / b, i % b, w, l, m, g, a, b, c);
		}
	}

	i = f;

	while (h != i) {
		i--;

		if ((c[i] == u) || (c[i] == o)) {
			c[i] -= o;
		}
	}

	c[w] = s;
	c[v] = r;
	return e;
}
