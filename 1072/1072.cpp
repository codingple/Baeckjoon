#include <iostream>

using namespace std;

int main()
{
	long long X, Y, Z;
	cin >> X >> Y;
	Z = (100 * Y) / X;

	if (Z >= 99)
		cout << -1 << endl;
	else {
		long long tmp1 = X * (Z + 1) - (100 * Y);
		long long tmp2 = 99 - Z;
		cout << ((tmp1 % tmp2 > 0) ? (tmp1 / tmp2) + 1 : tmp1 / tmp2) << endl;
	}

	return 0;
}