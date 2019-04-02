#include <iostream>
#include <queue>

using namespace std;

typedef struct state {
	int value;
	int cnt;
}state;

int N, L, result;
int map[100][100];

queue <state> q;

int main() {
	cin >> N >> L;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	// right direction
	for (int i = 0; i < N; i++) {
		int b_val, b_cnt;
		int success = 1;
		state tmp;
		tmp.value = map[i][0];
		tmp.cnt = 0;
		for (int j = 0; j < N; j++) {
			if (map[i][j] == tmp.value)
				tmp.cnt++;
			else {
				q.push(tmp);
				tmp.value = map[i][j];
				tmp.cnt = 1;
			}
		}
		q.push(tmp);
		b_val = q.front().value;
		b_cnt = q.front().cnt;
		q.pop();

		while (!q.empty()) {
			state crnt = q.front();
			q.pop();
			// go up
			if (b_val == crnt.value - 1) {
				// fail
				if (b_cnt < L) {
					success = 0;
					break;
				}
			}
			// go down
			else if (b_val - 1 == crnt.value) {
				// fail
				if (crnt.cnt < L) {
					success = 0;
					break;
				}
				// success
				else {
					crnt.cnt -= L;
				}
			}
			// fail
			else {
				success = 0;
				break;
			}
			b_val = crnt.value;
			b_cnt = crnt.cnt;
		}
		if (success)
			result++;
		queue <state> nw;
		swap(nw, q);
	}

	// down direction
	for (int i = 0; i < N; i++) {
		int b_val, b_cnt;
		int success = 1;
		state tmp;
		tmp.value = map[0][i];
		tmp.cnt = 0;
		for (int j = 0; j < N; j++) {
			if (map[j][i] == tmp.value)
				tmp.cnt++;
			else {
				q.push(tmp);
				tmp.value = map[j][i];
				tmp.cnt = 1;
			}
		}
		q.push(tmp);
		b_val = q.front().value;
		b_cnt = q.front().cnt;
		q.pop();

		while (!q.empty()) {
			state crnt = q.front();
			q.pop();
			// go up
			if (b_val == crnt.value - 1) {
				// fail
				if (b_cnt < L) {
					success = 0;
					break;
				}
			}
			// go down
			else if (b_val - 1 == crnt.value) {
				// fail
				if (crnt.cnt < L) {
					success = 0;
					break;
				}
				// success
				else {
					crnt.cnt -= L;
				}
			}
			// fail
			else {
				success = 0;
				break;
			}
			b_val = crnt.value;
			b_cnt = crnt.cnt;
		}
		if (success)
			result++;
		queue <state> nw;
		swap(nw, q);
	}

	cout << result << endl;
}