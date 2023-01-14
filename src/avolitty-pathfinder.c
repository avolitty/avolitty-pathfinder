#include <stdio.h>

static void AvolittyPathfinderA(unsigned long int *a, unsigned long int b, unsigned long int c, unsigned char *d, unsigned char *e) {
	/* .. */
	return;
}

void AvolittyPathfinder(unsigned long int *a, unsigned long int b, unsigned long int c, unsigned char *d, unsigned char e) {
	signed long int f[10U] = {0, 0, 0, 0, 0, 0, 1, 0, (~b) + 1, b};
	unsigned long int g = b * c;
	unsigned long int h;
	unsigned char i = 0U;
	unsigned char *j = &i;

	while (g != 0UL) {
		g--;
		f[d[g]] = g;
	}

	g = f[1U];
	printf("Starting point: %u\n", g);

	h = f[2U];
	printf("Ending point: %u\n", h);

	f[0U] = f[8U] - 1;
	f[1U] = f[9U] - 1;
	f[2U] = -1;
	f[3U] = 0;
	f[4U] = f[8U] + 1;
	f[5U] = f[9U] + 1;
	/* .. */
	return;
}
