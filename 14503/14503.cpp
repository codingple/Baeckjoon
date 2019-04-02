#include <iostream>

using namespace std;

int N, M;
int r, c, d;

// north, east, south, west
int dir[4][2] = { {-1, 0},{0, 1},{1, 0},{0, -1} };

int map[50][50];

int dir_left(int i) {
	i--;
	if (i < 0)
		return 3;
	else
		return i;
}

int main()
{
	int result = 0;
	cin >> N >> M;
	cin >> r >> c >> d;
	int tmp;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			map[i][j] = tmp;
		}
	}

	// # 1
	map[r][c] = 2;
	result++;

	// # 2
	int chk = 0;
	while (1) {
		int left_d = dir_left(d);
		int left_i = r + dir[left_d][0];
		int left_j = c + dir[left_d][1];
		if (chk == 4) {
			int back_d = dir_left(left_d);
			int back_i = r + dir[back_d][0];
			int back_j = c + dir[back_d][1];
			// # 2.4
			if (map[back_i][back_j] == 1)
				break;
			// # 2.3
			else {
				r = back_i;
				c = back_j;
				chk = 0;
			}
		}

		// # 2.1
		else if (map[left_i][left_j] == 0) {
			r = left_i;
			c = left_j;
			d = left_d;
			chk = 0;
			map[r][c] = 2;
			result++;
		}
		// # 2.2
		else {
			d = left_d;
			chk++;
		}
	}

	cout << result << endl;
}