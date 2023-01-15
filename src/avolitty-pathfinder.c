#include <stdio.h>

static void AvolittyPathfinderA(unsigned long int *a, unsigned long int *b, unsigned long int *c, unsigned long int *d, signed long int *e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned long int j, unsigned long int k, unsigned long int l, unsigned char *m, unsigned char *n) {
	/*
		a -> [array] cur pos
		b -> [array] cur pos heights
		c -> [array] cur pos widths
		d -> [integer] length of cur pos array
		e -> [array] traversal direction increments
		f -> [integer] dst height
                g -> [integer] dst width
		h -> [integer] grid height
		i -> [integer] grid width
		j -> [integer] src pos
		k -> [integer] length of grid
		l -> [integer] dst pos
		m -> [array] grid
		n -> pointer [integer] traversal status 0|1
	*/
	unsigned long int o = *d;
	signed long int p;
	unsigned char q;

	while (o != 0UL) {
		o--;
		q = b[o] < f;

		if (b[o] == f) {
			q += 2U;
		}

		if (c[o] < g) {
			q += 4U;
		}

		if (c[o] == g) {
			q += 8U;
		}

		p = e[q];
		printf("Traversal direction increment: %ld", p);
		/* .. */
	}

	*n = 1U;
	return;
}

void AvolittyPathfinder(unsigned long int *a, unsigned long int *b, unsigned long int *c, unsigned long int d, unsigned long int e, unsigned char *f, unsigned char g) {
	signed long int h[10U] = {0L, 0L, 0L, 0L, 0L, 0L, 1L, 0L, (~d) + 1L, d};
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
	a[0] = i;
	b[0] = i / d;
	c[0] = i - ((i / e) * 10UL);
	l = h[2U];
	f[l] = 3U;
	h[0U] = h[8U] - 1L;
	h[1U] = h[9U] - 1L;
	h[2U] = -1L;
	h[3U] = 0L;
	h[4U] = h[8U] + 1L;
	h[5U] = h[9U] + 1L;
	m = l / d;
	n = l - ((l / e) * 10UL);

	while (p == 0U) {
		/*
			a -> [array] cur pos
			b -> [array] cur pos heights
			c -> [array] cur pos widths
			o -> [integer] length of cur pos array
			h -> [array] traversal direction increments
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

		AvolittyPathfinderA(a, b, c, o, h, m, n, d, e, i, j, l, f, q);
	}

	return;
}
