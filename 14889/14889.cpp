#include <iostream>
#include <math.h>

using namespace std;

int N, halfN;
int all[20][20];
int result = -1;
// minus value, minus range, current index
int team2_idx = 0;

// Update result
void update_result(int value) {
	result = (result == -1) ? value : ((result > value) ? value : result);
}

// Get current value
int get_current_value(int team1_score, int team2_score) {
	return abs(team1_score - team2_score);
}

// Get team's score
int get_team_scores(int * team1, int * team2) {
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < halfN-1; i++) {
		for (int j = i + 1; j < halfN; j++) {
			int team1_player1 = team1[i];
			int team1_player2 = team1[j];
			int team2_player1 = team2[i];
			int team2_player2 = team2[j];
			sum1 += all[team1_player1][team1_player2] + all[team1_player2][team1_player1];
			sum2 += all[team2_player1][team2_player2] + all[team2_player2][team2_player1];
		}
	}
	return get_current_value(sum1, sum2);
}

// Get team2
void get_other_team(int * team2, int * team2_original) {
	// current index does not reached to the last
	if (team2_idx != halfN)
		--team2[team2_idx++];
	// go to the next change
	else {
		int i;
		for (i = halfN-1; i > 0; i--) {
			int crnt = team2_original[i] - team2[i];
			int next = team2_original[i-1] - team2[i-1];
			// find next index
			if (crnt < next)
				break;
		}

		// the index needs the change
		team2[i]--;
		team2_idx = i+1;

		// reset from here
		for (int j = team2_idx; j < halfN; j++)
			team2[j] = team2_original[j];
	}
}

// Get all combination of team ( return = continue : 1, finish : 0 )
int get_combination_is_OK(int * team1, int * team2, int * team2_original) {
	int i;
	for (i = halfN - 1; i > 0; i--) {
		// not last index of subregion
		if (team1[i] != N - (halfN - i)) {
			// current value++
			team1[i]++;
			// set value after this index
			for (int j = i + 1; j < halfN; j++) {
				team1[j] = team1[j - 1] + 1;
			}
			break;
		}
	}

	// all team combined
	if (i == 0)
		return 0;
	
	// set team2
	get_other_team(team2, team2_original);
	
	return 1;
}


// Merged function for updating result
void update(int * team1, int * team2) {
	int crnt = get_team_scores(team1, team2);
	update_result(crnt);
}

// Get result
void get_result() {
	int team1[10];
	int team2[10];
	int team2_original[10];

	// set team1
	for (int i = 0; i < halfN; i++)
		team1[i] = i;
	// set team2
	for (int i = 0; i < halfN; i++) {
		team2_original[i] = halfN + i;
		team2[i] = halfN + i;
	}
	// get first score
	update(team1, team2);
	
	while (get_combination_is_OK(team1, team2, team2_original))
		update(team1, team2);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> all[i][j];
		}
	}
	halfN = N / 2;

	get_result();

	cout << result << endl;

	return 0;
}