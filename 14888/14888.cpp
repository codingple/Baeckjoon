#include <iostream>

using namespace std;

int N;
long long arr[11];

typedef struct state {
	int idx;
	int product[4];
}state;

typedef struct minmax {
	long long mx;
	long long mn;
}minmax;

long long product(int p, long long x, long long y) {
	switch (p) {
	case 0:
		return x + y;
	case 1:
		return x - y;
	case 2:
		return x * y;
	case 3:
		return x / y;
	}
}

minmax go(state st, long long c) {
	minmax result;

	if (st.idx == N - 1) {
		for (int i = 0; i < 4; i++) {
			if (st.product[i]) {
				result.mx = product(i, c, arr[N - 1]);
				result.mn = product(i, c, arr[N - 1]);
				return result;
			}
		}
	}

	int swit = 1;
	for (int i = 0; i < 4; i++) {
		if (st.product[i] == 0)
			continue;
		state crnt = st;
		crnt.idx++;
		crnt.product[i]--;
		minmax tmp = go(crnt, product(i, c, arr[st.idx]));
		if (swit) {
			result = tmp;
			swit = 0;
		}
		else {
			result.mx = (result.mx < tmp.mx) ? tmp.mx : result.mx;
			result.mn = (result.mn > tmp.mn) ? tmp.mn : result.mn;
		}
	}
	return result;
}

int main()
{
	int tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	state st;
	st.idx = 1;
	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		st.product[i] = tmp;
	}

	minmax res = go(st, arr[0]);

	cout << res.mx << "\n" << res.mn << "\n";

	return 0;
}