#include <stdio.h>

static void AvolittyPathfinderA(unsigned long int *a, unsigned long int *b, unsigned long int *c, unsigned long int *d, signed long int *e, unsigned long int f, unsigned long int g, unsigned long int h, unsigned long int i, unsigned long int j, unsigned char *k, unsigned char *l, unsigned char m, unsigned char n) {
	/*
		a -> [array] cur pos
		b -> [array] cur pos heights
		c -> [array] cur pos widths
		d -> [array] traversal direction increments
		e -> [integer] length of cur pos array
		f -> [integer] grid height
		g -> [integer] grid width
		h -> [integer] src pos
		i -> [integer] length of grid
		j -> [integer] dst pos
		k -> [array] grid
		l -> pointer [integer] traversal status 0|1
		m -> [integer] dst height
		n -> [integer] dst width
	*/
	unsigned long int o = *d;

	while (o != 0UL) {
		o--;
		/* .. */
	}

	*l = 1U;
	return;
}

void AvolittyPathfinder(unsigned long int *a, unsigned long int *b, unsigned long int *c, unsigned long int d, unsigned long int e, unsigned char *f, unsigned char g) {
	signed long int h[10U] = {0L, 0L, 0L, 0L, 0L, 0L, 1L, 0L, (~d) + 1L, d};
	unsigned long int i = d * e;
	unsigned long int j = i;
	unsigned long int k = 1UL;
	unsigned long int l;
	unsigned long int *m = &k;
	unsigned char n = 0U;
	unsigned char o;
	unsigned char p;
	unsigned char *q = &n;

	while (i != 0UL) {
		i--;
		h[f[i]] = i;
	}

	i = h[1U];
	l = h[2U];
	f[l] = 3U;
	h[0U] = h[8U] - 1L;
	h[1U] = h[9U] - 1L;
	h[2U] = -1L;
	h[3U] = 0L;
	h[4U] = h[8U] + 1L;
	h[5U] = h[9U] + 1L;
	o = (l / d) + 1U;
	p = (l - ((l / e) * 10U)) + 1U;

	while (n == 0U) {
		/*
			a -> [array] cur pos
			b -> [array] cur pos heights
			c -> [array] widths for cur pos
			m -> [integer] length of cur pos array
			h -> [array] traversal direction increments
			d -> [integer] grid height
			e -> [integer] grid width
			i -> [integer] src pos
			j -> [integer] length of grid
			k -> [integer] dst pos
			f -> [array] grid
			q -> pointer [integer] traversal status 0|1
			o -> [integer] dst height
			p -> [integer] dst width
		*/

		AvolittyPathfinderA(a, b, c, m, h, d, e, i, j, l, f, q, o, p);
	}

	return;
}
