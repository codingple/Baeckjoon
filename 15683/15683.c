#include <stdio.h>
#pragma warning(disable:4996)

typedef struct pos {
	int type;
	int x;
	int y;
}pos;

typedef struct state {
	int map[8][8];
	int depth;
	int zeros;
}state;

int N, M, result, numOfcctv;
pos cctv[8];
state start;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

void input_data() {
	int tmp;
	scanf("%d %d ", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i != N - 1 && j != M - 1) scanf("%d ", &tmp);
			else scanf("%d", &tmp);
			start.map[i][j] = tmp;
			// cctv
			if (tmp > 0 && tmp < 6) {
				cctv[numOfcctv].type = tmp;
				cctv[numOfcctv].x = i;
				cctv[numOfcctv++].y = j;
			}
			// zero
			else if (!tmp) start.zeros++;
		}
	}
}

int inRange(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < M)
		return 1;
	return 0;
}

void update_result(int *res, int nw) {
	if (*res == -1 || *res > nw) *res = nw;
}

void update_map_oneline(pos crnt_cctv, state *nw_s, int idx) {
	int nw_x = crnt_cctv.x + dir[idx][0];
	int nw_y = crnt_cctv.y + dir[idx][1];
	// update map
	while (inRange(nw_x, nw_y) && nw_s->map[nw_x][nw_y] < 6) {
		// only zero counted & changed into -1
		if (!nw_s->map[nw_x][nw_y]) {
			nw_s->zeros--;
			nw_s->map[nw_x][nw_y] = -1;
		}
		nw_x += dir[idx][0];
		nw_y += dir[idx][1];
	}
}

int recursive_dfs(state s) {
	int result = -1;
	int depth = s.depth;

	// ready to count zero
	if (s.depth == numOfcctv)
		return s.zeros;

	// as cctv type
	pos crnt_cctv = cctv[depth];
	int type = crnt_cctv.type;
	state nw_s;
	switch (type) {
	// {0}, {1}, {2}, {3} : 4
	case 1:
		for (int i = 0; i < 4; i++) {
			nw_s = s;
			update_map_oneline(crnt_cctv, &nw_s, i);
			nw_s.depth++;
			update_result(&result, recursive_dfs(nw_s));
		}
		break;
	// {0,2}, {1,3} : 2
	case 2:
		for (int i = 0; i < 2; i++) {
			nw_s = s;
			update_map_oneline(crnt_cctv, &nw_s, i);
			update_map_oneline(crnt_cctv, &nw_s, i+2);
			nw_s.depth++;
			update_result(&result, recursive_dfs(nw_s));
		}
		break;
	// {0,1}, {1,2}, {2,3}, {3,0} : 4
	case 3:
		for (int i = 0; i < 4; i++) {
			nw_s = s;
			update_map_oneline(crnt_cctv, &nw_s, i);
			update_map_oneline(crnt_cctv, &nw_s, (i+1)%4 );
			nw_s.depth++;
			update_result(&result, recursive_dfs(nw_s));
		}
		break;
	// {0,1,2},{1,2,3},{2,3,0},{3,0,1} : 4
	case 4:
		for (int i = 0; i < 4; i++) {
			nw_s = s;
			update_map_oneline(crnt_cctv, &nw_s, i);
			update_map_oneline(crnt_cctv, &nw_s, (i + 1) % 4);
			update_map_oneline(crnt_cctv, &nw_s, (i + 2) % 4);
			nw_s.depth++;
			update_result(&result, recursive_dfs(nw_s));
		}
		break;
	// {0,1,2,3} : 1
	case 5:
		nw_s = s;
		update_map_oneline(crnt_cctv, &nw_s, 0);
		update_map_oneline(crnt_cctv, &nw_s, 1);
		update_map_oneline(crnt_cctv, &nw_s, 2);
		update_map_oneline(crnt_cctv, &nw_s, 3);
		nw_s.depth++;
		update_result(&result, recursive_dfs(nw_s));
		break;
	}

	return result;
}


int main() {
	
	input_data();
	result = recursive_dfs(start);
	printf("%d\n", result);

	return 0;
}