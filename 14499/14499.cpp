#include <iostream>

using namespace std;

// 0 : ceil, 5 : bottom
int dice[6];
int dir[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
int map[20][20];

void move(int cmd) {
	int tmp;
	switch (cmd) {
	// east
	case 1:
		tmp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[2];
		dice[2] = tmp;
		break;

	// west
	case 2:
		tmp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[4];
		dice[4] = tmp;
		break;

	// north
	case 3:
		tmp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[1];
		dice[1] = tmp;
		break;

	// south
	case 4:
		tmp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[3];
		dice[3] = tmp;
		break;
	}
}

int main()
{
	int N, M, x, y, K, tmp, cmd;
	int crnt = 0;
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			map[i][j] = tmp;
		}
	}

	// each K
	for (int ts = 0; ts < K; ts++) {
		// command
		cin >> cmd;
		int tmp_x = x + dir[cmd-1][0];
		int tmp_y = y + dir[cmd-1][1];

		// check if out of map
		if (tmp_x >= 0 && tmp_x < N && tmp_y >= 0 && tmp_y < M) {
			x = tmp_x;
			y = tmp_y;
			move(cmd);

			// 0
			if (map[x][y] == 0)
				map[x][y] = dice[5];
			// not 0
			else {
				dice[5] = map[x][y];
				map[x][y] = 0;
			}

			cout << dice[0] << endl;
		}
	}

	return 0;
}