#include <stdio.h>
#include "../src/avolitty-pathfinder.h"

int main(void) {
	int a = 0;
	unsigned long int b[10UL];
	unsigned long int c[10UL];
	unsigned long int d[10UL];
	unsigned long int e = 10UL;
	unsigned long int f = 10UL;
	unsigned char g[100UL] = {
		1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
		0U, 0U, 3U, 3U, 3U, 3U, 3U, 3U, 0U, 0U,
		0U, 0U, 3U, 0U, 3U, 0U, 0U, 3U, 0U, 0U,
		0U, 0U, 3U, 0U, 0U, 0U, 0U, 3U, 3U, 0U,
		0U, 3U, 3U, 0U, 0U, 3U, 0U, 0U, 0U, 0U,
		0U, 3U, 0U, 0U, 0U, 3U, 0U, 3U, 3U, 3U,
		0U, 3U, 0U, 3U, 0U, 3U, 0U, 3U, 2U, 0U,
		0U, 0U, 0U, 3U, 0U, 3U, 0U, 3U, 0U, 0U,
		0U, 0U, 0U, 0U, 0U, 3U, 0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
	};
	unsigned char h = 0;
	AvolittyPathfinder(b, c, d, e, f, g, h);
	return a;
}
