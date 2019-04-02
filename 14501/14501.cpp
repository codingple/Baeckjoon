#include <iostream>
#include <vector>

using namespace std;

vector<vector <int> > list;

int dp[15];
int N;

int mx(int i) {
	if (dp[i] > 0)
		return dp[i];
	int T = list.at(i).at(0);
	int P = list.at(i).at(1);
	int result = 0;
	for (int j = i + T; j < N; j++) {
		int tmp = mx(j);
		result = (result < tmp) ? tmp : result;
	}
	dp[i] = P + result;
	return P + result;
}

int main()
{
	cin >> N;
	int result = 0;

	for (int i = 0; i < N; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		if (i + tmp1 - 1 > N - 1) {
			tmp1 = N;
			tmp2 = -1;
		}
		vector<int> tmp3 = { tmp1, tmp2 };
		list.push_back(tmp3);

	}

	for (int i = N-1; i >= 0; i--) {
		int tmp = mx(i);
		result = (tmp > result) ? tmp : result;
	}

	cout << result << endl;
}