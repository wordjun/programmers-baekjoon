#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int DP[1001];

int main() {
	int N = 0;
	DP[1] = 1, DP[2] = 2;
	cin >> N;
	//DP[N] = DP[N-1] + DP[N-2] (N >= 3)
	for (int i = 3; i <= N; i++) {
		DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
	}
	cout << DP[N] % 10007 << '\n';
	return 0;
}