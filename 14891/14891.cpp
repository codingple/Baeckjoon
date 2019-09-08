#include <iostream>
#include <queue>

using namespace std;

int crnt[4][8];
int turned[4];
int K;

// 0 : right , 1 : left
int idx[2] = { 2, 6 };

typedef struct state {
	int gearNum;
	int dir;
}state;

queue <state> q;

void input_data() {
	char c;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> c;
			crnt[i][j] = c - '0';
		}
	}
	cin >> K;
}

void oneTurn(int gearNum, int dir) {
	dir *= -1;
	int tmp = crnt[gearNum][0];
	int i;
	int nxt;
	for (i = 0; ((i*dir) != 7) && ((i*dir) != -1); i = nxt) {
		nxt = i + dir;
		if (nxt < 0) nxt = 7;
		crnt[gearNum][i] = crnt[gearNum][nxt];
	}
	crnt[gearNum][i] = tmp;
}

void turnedInit() {
	for (int j = 0; j < 4; j++)
		turned[j] = 0;
}

int inRange(int x) {
	if (x >= 0 && x < 4)
		return 1;
	return 0;
}

void turn() {
	int gearNum, dir;
	for (int i = 0; i < K; i++) {
		cin >> gearNum >> dir;
		gearNum--;
		state s = { gearNum, dir };
		turned[s.gearNum] = 1;
		q.push(s);

		while (!q.empty()) {
			state crnt_gear = q.front();
			int nxt = 1;
			
			// push first
			for (int k = 0; k < 2; k++) {
				int your_gearNum = crnt_gear.gearNum + nxt;
				if (!inRange(your_gearNum)) {
					nxt *= -1;
					continue;
				}
				int willTurn = crnt[crnt_gear.gearNum][idx[k]] + crnt[your_gearNum][idx[(k + 1) % 2]];
				if (willTurn == 1 && !turned[your_gearNum]) {
					state nw = { your_gearNum, crnt_gear.dir * -1 };
					q.push(nw);
					turned[your_gearNum] = 1;
				}
				nxt *= -1;
			}
			
			// then turn this gear
			oneTurn(crnt_gear.gearNum, crnt_gear.dir);

			q.pop();
		}

		turnedInit();
	}
}

int getScore() {
	int tmp_score = 1;
	int result = 0;
	for (int i = 0; i < 4; i++) {
		if (crnt[i][0]) result += tmp_score;
		tmp_score *= 2;
	}
	return result;
}

int main() {
	input_data();
	turn();
	cout << getScore() << endl;
	
	return 0;
}