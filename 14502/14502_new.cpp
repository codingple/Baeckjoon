#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M;
int map[8][8];
int tmp_map[8][8];

// right, left, up, down
int dir[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

vector<vector<int> > zeros;
queue<vector<int> > virus;

int valid(int i, int j, int map) {
	if (0 <= i && i < N && 0 <= j && j < M) {
		if (map == 0)
			return 1;
	}
	return 0;
}

int main()
{
	int result = 0;
	int num_zero = 0;
	int tmp;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			map[i][j] = tmp;
			// push zero
			if (tmp == 0) {
				vector<int> t;
				t.push_back(i);
				t.push_back(j);
				zeros.push_back(t);
				num_zero++;
			}
			// push virus
			else if (tmp == 2) {
				vector<int> t;
				t.push_back(i);
				t.push_back(j);
				virus.push(t);
			}
				
		}
	}
	
	num_zero -= 3;
	vector<vector<int> >::iterator iter1;
	vector<vector<int> >::iterator iter2;
	vector<vector<int> >::iterator iter3;

	// all cases of wall
	for (iter1 = zeros.begin(); *iter1 != zeros.at(zeros.size() - 2); iter1++) {
		vector<int> one = *iter1;
		for (iter2 = iter1+1; *iter2 != zeros.at(zeros.size() - 1); iter2++) {
			vector<int> two = *iter2;
			// three wall determined
			for (iter3 = iter2+1; iter3 != zeros.end(); iter3++) {
				vector<int> three = *iter3;
				queue<vector<int> > tmp_virus = virus;

				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						tmp_map[i][j] = map[i][j];
					}
				}
				tmp_map[one.at(0)][one.at(1)] = 1;
				tmp_map[two.at(0)][two.at(1)] = 1;
				tmp_map[three.at(0)][three.at(1)] = 1;
				int res = num_zero;

				// virus released
				while (!tmp_virus.empty()) {
					vector<int> crnt = tmp_virus.front();
					for (int i = 0; i < 4; i++) {
						int new_i = crnt.at(0) + dir[i][0];
						int new_j = crnt.at(1) + dir[i][1];
						if (valid(new_i, new_j, tmp_map[new_i][new_j])) {
							tmp_map[new_i][new_j] = 2;
							vector<int> t;
							t.push_back(new_i);
							t.push_back(new_j);
							tmp_virus.push(t);
							res--;
						}
					}

					tmp_virus.pop();
				}
				// remaining zero
				result = (result < res) ? res : result;
			}
		}
	}

	cout << result << endl;

	return 0;
}