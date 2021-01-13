#include<iostream>
#include<string.h>
using namespace std;

int DP[10001];
int N;

void init() {
	memset(DP, 0, sizeof(DP));
	DP[1] = 1, DP[2] = 2, DP[3] = 4;
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		init();
		cin >> N;
		for (int i = 4; i <= N; i++) {
			DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
		}
		cout << DP[N] << '\n';
	}
	return 0;
}