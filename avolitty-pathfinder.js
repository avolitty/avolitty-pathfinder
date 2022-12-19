const _1_0 = function(_1_1) {
	// ..
	_1_1[5] = 1
	return _1_1
}

const avolittyPathfinder = function(_1_1) {
	let _1_2 = _1_1.grid
	let _1_3 = _1_1.height
	let _1_4 = _1_1.width
	let _1_5 = _1_3 * _1_4
	let _1_6 = [0, _1_4 * -1, 0, 1, 0, _1_4, 0, -1]
	let _1_7 = []
	let _1_8 = []
	let _1_9 = 0
	_1_6[0] = _1_6[1] - 1
	_1_6[2] = _1_6[1] + 1
	_1_6[4] = _1_6[5] - 1
	_1_6[6] = _1_6[5] + 1

	while (_1_5 != _1_9) {
		_1_8[_1_2[_1_9]] = _1_9++
	}

	if (_1_8[1] == _1_8[2]) {
		return _1_2
	}

/*
splitting src + dst
  _1_8
    [0] grid
    [1] src + dst
    [2] current src + dst based on obstacles
    [3] nested split traversal coordinates
    [4] split traversal lengths w/ nested key
    [5] 1|0 dst reached to break recursion
*/

	_1_8 = [_1_2, [_1_8[1], _1_8[2]], [_1_8[1], _1_8[1], _1_8[2], _1_8[2]], [], 0]

	while (_1_8[5] == 0) {
		_1_8 = _1_0(_1_8)
	}

/*
recursion steps in _1_0
  calculating navigation key to use in _1_6
    based on current split pos to dst
  traversing to dst until obstacle is reached
  traversing adjacent obstacles w/ async in 2 directions to find 2 pseudo dst
  creating split for traversal to each psuedo dst with step counts in different array
  setting current split pos to array

  populating grid traversal with shortest path
*/

	// ..
	return _1_8[0]
}

let _0 = {
"grid": [
1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 3, 3, 3, 3, 3, 3, 0, 0,
0, 0, 3, 0, 0, 0, 0, 0, 0, 0,
0, 0, 3, 0, 0, 0, 0, 0, 0, 0,
0, 3, 0, 0, 0, 3, 0, 0, 0, 0,
0, 3, 0, 0, 0, 3, 0, 0, 0, 0,
0, 3, 0, 3, 0, 3, 0, 0, 0, 0,
0, 0, 0, 3, 0, 3, 0, 0, 0, 0,
0, 0, 0, 3, 0, 3, 0, 0, 0, 0,
0, 0, 0, 0, 0, 3, 0, 0, 0, 2
],
"height": 10,
"width": 10
}

_0 = avolittyPathfinder(_0)
