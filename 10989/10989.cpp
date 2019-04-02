#include <iostream>
#include <cstdio>

using namespace std;

unsigned int arr[10001];

int main()
{
	unsigned int N, tmp;
	scanf("%u", &N);

	for (unsigned int i = 1; i <= N; i++) {
		scanf("%u", &tmp);
		arr[tmp]++;
	}

	for (unsigned int i = 1; i <= 10000; i++) {
		for (unsigned int j = 0; j < arr[i]; j++)
			printf("%u\n", i);
	}

	return 0;
}