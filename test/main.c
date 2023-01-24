#include <stdio.h>
#include "../src/avolitty-pathfinder.h"

int main(void) {
	int a = 0;
	unsigned long int b = 10UL;
	unsigned long int c = 10UL;
	unsigned char d[100UL] = {
                1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
                0U, 0U, 0U, 0U, 0U, 3U, 0U, 0U, 0U, 0U,
                0U, 0U, 0U, 0U, 0U, 3U, 0U, 0U, 0U, 0U,
                0U, 0U, 0U, 0U, 0U, 3U, 0U, 0U, 0U, 0U,
                0U, 0U, 0U, 0U, 0U, 3U, 0U, 0U, 0U, 0U,
                0U, 0U, 0U, 3U, 3U, 3U, 0U, 0U, 0U, 0U,
                0U, 0U, 0U, 3U, 0U, 3U, 3U, 3U, 0U, 0U,
                0U, 0U, 0U, 3U, 0U, 3U, 2U, 0U, 0U, 0U,
                0U, 3U, 3U, 3U, 3U, 3U, 0U, 0U, 0U, 0U,
                0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
        };

	AvolittyPathfinder(b, c, d);
	return a;
}
