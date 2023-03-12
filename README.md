## Avolitty Pathfinder

#### Author
William Parsons <[avolitty.com](https://avolitty.com/)>

#### Description
Create shortest path traversals in grid graphs using C89 with a fast and unique pathfinding algorithm.

- Allocates static memory with stack instead of heap
- Compiles with Clang or GCC
- Compiles with forward-compatible C89 and C++
- Conforms to strict ISO C with -pedantic-errors enabled
- Defines a destination, obstacles, a source and traversable spaces with numbers
- Fast grid pathfinding speed without A* or Dijkstra algorithms
- Guarantees the shortest path from a source to a destination
- Maps traversal waypoint coordinates based on a count of adjacent obstacles
- Memory-safe with well-defined behavior
- Minified code
- Navigates in 8 directions with diagonal movement
- Optimized for calculation speed and minimal memory usage
- Path trees are traversed and reversed efficiently in existing grid memory
- Returns a count of spaces traversed with a modified grid
- Traversal direction calculation is [optimized with minimal conditional statements](https://avolitty.com/blog/optimizing-calculation-of-8-directional-grid-navigation-in-c/)

#### Funding
[Avolitty](https://avolitty.com/donate/)

#### License
[MIT](https://github.com/avolitty/avolitty-pathfinder/blob/main/LICENSE)

#### Usage
Clone the repository in the current directory with `git`.

``` console
git clone https://github.com/avolitty/avolitty-pathfinder.git
```

Navigate to the cloned repository's root directory with `cd`.

``` console
cd avolitty-pathfinder
```

The following example uses code from [test/main.c](https://github.com/avolitty/avolitty-pathfinder/blob/main/test/main.c) to traverse shortest paths with the `AvolittyPathfinder()` function from [src/avolitty-pathfinder.c](https://github.com/avolitty/avolitty-pathfinder/blob/main/src/avolitty-pathfinder.c).

``` c
#include <stdio.h>
#include "../src/avolitty-pathfinder.h"

int main(void) {
	unsigned long int a;
	unsigned long int b;
	unsigned long int c;
	unsigned long int d;
	unsigned long int e;
	unsigned long int f;
	unsigned char g[((unsigned long int) 165UL)] = {
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0,
		0, 0, 0, 7, 7, 7, 0, 7, 0, 0, 0,
		0, 0, 0, 7, 0, 7, 7, 7, 0, 0, 0,
		0, 0, 0, 7, 0, 7, 0, 0, 0, 0, 0,
		0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};
	a = ((unsigned long int) 15UL);
	b = ((unsigned long int) 11UL);
	c = ((unsigned long int) 1UL);
	d = ((unsigned long int) 0UL);
	e = d;
	f = AvolittyPathfinder(a, b, g);
	a *= b;
	printf("%u ", g[e++]);

	if (a == f) {
		f = d;
	}

	while (a != e) {
		printf("%u ", g[e]);

		if (((c + e) % b) == d) {
			printf("\n");
		}

		e++;
	}

	return 0;
}
```

The return value variable `f` is an `unsigned long int` and `AvolittyPathfinder()` defines it as the number of spaces in the shortest traversal path.

The first argument variable `a` is an `unsigned long int` defined as the height of the grid graph.

The second argument variable `b` is an `unsigned long int` defined as the width of the grid graph.

The result of `(a * b)` must be within the bounds of `ULONG_MAX`.

The third argument variable `g` is an `unsigned char` array defined as the grid graph for pathfinding.

The length must be the result of `(a * b)`.

The grid graph spaces are defined as the following numbers.

- `0` Traversable
- `1` Source
- `2` Destination
- `7` Obstacle

The grid must have a single source `1` and a single destination `2`.

If the destination `2` can't be reached, the grid path is unmodified and the return value `f` is defined as `0U`.

An executable binary for testing can be compiled with either `clang` or `gcc`.

``` console
gcc -o avolitty-pathfinder -pedantic-errors -std=c89 src/avolitty-pathfinder.c test/main.c
```

`-pedantic-errors` compiles with strict ISO C standards and `-std=c89` compiles with forward-compatible C89 standards.

It outputs an executable binary file named `avolitty-pathfinder` in the current directory.

The output from executing `./avolitty-pathfinder` is the grid graph with the shortest path traversal spaces defined as `4`.

``` console
./avolitty-pathfinder
# 1 0 0 0 0 0 0 0 0 0 0
# 4 0 0 0 0 7 0 0 0 0 0
# 4 0 0 0 0 7 0 0 0 0 0
# 4 0 0 0 0 7 0 0 0 0 0
# 4 0 0 0 0 7 0 0 0 0 0
# 4 0 0 7 7 7 0 7 0 0 0
# 4 0 0 7 0 7 7 7 0 0 0
# 4 0 0 7 0 7 0 0 0 0 0
# 4 7 7 7 7 7 0 0 0 0 0
# 0 4 0 0 0 0 0 0 0 0 0
# 0 0 4 4 4 0 0 0 0 0 0
# 7 7 7 7 7 4 0 0 0 0 0
# 0 0 0 0 4 0 0 0 0 0 0
# 0 2 4 4 0 0 0 0 0 0 0
# 0 0 0 0 0 0 0 0 0 0 0
```
