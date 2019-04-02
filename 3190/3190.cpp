#include <iostream>
#include <queue>

using namespace std;

int map[100][100];

// R, D, L, U
int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int cnt, rear_cnt, N;

typedef struct state {
	int scd;
	int dirc;
}state;

typedef struct snake {
	int head_row;
	int head_col;
	int rear_row;
	int rear_col;
	int head_dir;
	int rear_dir;
	int len;
}snake;

snake crnt = { 0,0,0,0,0,0,0 };

int body[100][2];

int mov(queue<state>& q, queue<state>& rear_q) {
	int result = 0;
	state now = q.front();
	
	// each second
	for (int i = cnt; i < now.scd; i++) {
		cnt++;
		crnt.head_col += dir[crnt.head_dir][0];
		crnt.head_row += dir[crnt.head_dir][1];

		// out of map (game over)
		if (crnt.head_col < 0 || crnt.head_col == N ||
			crnt.rear_col < 0 || crnt.rear_col == N ||
			crnt.head_row < 0 || crnt.head_row == N ||
			crnt.rear_row < 0 || crnt.rear_row == N
			)
			return 1;

		// crushed itself
		else if (map[crnt.head_col][crnt.head_row] == 2)
			return 1;

		else {
			// the snake did not eat an apple
			if (!map[crnt.head_col][crnt.head_row]) {
				map[crnt.rear_col][crnt.rear_row] = 0;
				rear_cnt++;
				crnt.rear_col += dir[crnt.rear_dir][0];
				crnt.rear_row += dir[crnt.rear_dir][1];

				// rear should change its direction
				if (rear_cnt == rear_q.front().scd) {
					crnt.rear_dir = (crnt.rear_dir + rear_q.front().dirc) % 4;
					rear_q.pop();
				}
			}
			map[crnt.head_col][crnt.head_row] = 2;
		}
	}
	// head should change its direction
	crnt.head_dir = (crnt.head_dir + now.dirc) % 4;
	q.pop();
	return result;
}


int main()
{
	queue <state> q;
	queue <state> rear_q;
	int K;
	cin >> N >> K;
	
	for (int i = 0; i < K; i++) {
		int row, col;
		cin >> row >> col;
		map[row - 1][col - 1] = 1;
	}

	int L;
	cin >> L;

	for (int i = 0; i < L; i++) {
		int second;
		char direction;
		state s;
		cin >> second >> direction;
		s.scd = second;
		if (direction == 'D')
			s.dirc = 1;
		else
			s.dirc = 3;
		q.push(s);
		rear_q.push(s);
	}
	// last move
	state s;
	s.scd = 10000;
	s.dirc = 1;
	q.push(s);
	rear_q.push(s);

	while (!q.empty()) {
		int res = mov(q, rear_q);
		if (res)
			break;
	}

	cout << cnt << endl;

	return 0;
}