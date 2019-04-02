#include <iostream>

using namespace std;

int arr[1000000];

int main()
{
	int N, tmp, B, C;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr[tmp - 1]++;
	}

	long long result = 0;
	cin >> B >> C;

	for (int i = 0; i < 1000000; i++) {
		if (arr[i] > 0) {
			long long tmp = (i+1) - B;
			result += arr[i];
			if (tmp > 0) {
				result += (tmp % C != 0) ? arr[i] * ((tmp / C) + 1) : arr[i] * (tmp / C);
			}
		}
	}

	cout << result << endl;
}