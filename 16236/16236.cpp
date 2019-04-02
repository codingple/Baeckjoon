#include <iostream>
#include <queue>

using namespace std;

typedef struct state{
	int i;
	int j;
	int mv;
}state;

// up : 0 , left : 1 , right : 2 , down : 3
int dir[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
int N, shark, last_shark, result;
state crnt;
int map[20][20];
int crntMap[20][20];
int same;

void init() {
	shark = 2;
	last_shark = 2;
	result = 0;
}

void Push(queue<state> *q, state nw) {
	if (nw.i >= 0 && nw.i < N && nw.j >= 0 && nw.j < N &&
		crntMap[nw.i][nw.j] != -1 && map[nw.i][nw.j] != 9) {
		crntMap[nw.i][nw.j] = -1;
		(*q).push(nw);
		same++;
	}
}

int keepGoing() {
	same = 0;
	// copy map
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			crntMap[i][j] = map[i][j];
		}
	}

	// dir push
	queue <state> q;
	for (int i = 0; i < 4; i++) {
		Push(&q, state{ crnt.i + dir[i][0], crnt.j + dir[i][1], crnt.mv+1 });
	}
	queue <state> candi;
	int start = 0;
	int end = same;
	while (!q.empty()) {
		for (int j = start; j < end; j++) {
			state s = q.front();
			int v = map[s.i][s.j];

			// cant go
			if (shark < v) {
				q.pop();
				continue;
			}

			// go through
			else if (shark == v || v == 0) {
				for (int i = 0; i < 4; i++) {
					Push(&q, state{ s.i + dir[i][0], s.j + dir[i][1], s.mv + 1 });
				}
			}
			// let's eat
			else if (shark > v)
				candi.push(q.front());
			q.pop();
		}
		if (candi.size() != 0)
			break;
		start = end;
		end = same;
	}
	state tmp = { -1, -1, -1 };
	if (candi.size() == 1)
		tmp = candi.front();
	else {
		while (!candi.empty()) {
			if (tmp.i == -1) {
				tmp = candi.front();
			}
			else {
				if (tmp.i > candi.front().i) {
					tmp = candi.front();
				}
				else if (tmp.i == candi.front().i) {
					if (tmp.j > candi.front().j)
						tmp = candi.front();
				}
			}

			candi.pop();
		}
	}

	// shark ate
	if (tmp.i != -1) {
		// change shark pos
		map[crnt.i][crnt.j] = 0;
		crnt = tmp;
		result = crnt.mv;
		map[crnt.i][crnt.j] = 9;
		// size of shark
		if (--last_shark == 0) {
			last_shark = ++shark;
		}
		return 1;
	}
	// nothing to eat
	else
		return 0;
}

int main()
{
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				crnt.i = i;
				crnt.j = j;
				crnt.mv = 0;
			}
			
		}
	}

	while (keepGoing());

	cout << result << endl;
}