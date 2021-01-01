#include<iostream>
using namespace std;

//입력의 크기는 10^6보다 작거나 같은 정수
int DP[1000001];

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	//3으로 나눠떨어지면->3으로 나눈다.
	//2로 나눠떨어지면->2로 나눈다
	//위 둘에 해당안되면 1을 뺀다.
	int N = 0;
	cin >> N;
	DP[1] = 0;//1은 이미 1이니까 계산할 필요 없음
	//따라서 2부터 N까지 bottom-up 방식으로 DP진행
	for (int i = 2; i <= N; i++) {
		//우선 모든 수들은 1에 접근하기위해 1을 빼는 연산을 기본적으로 할 수 있다.
		DP[i] = DP[i - 1] + 1;
		if (i % 2 == 0) {
			DP[i] = min(DP[i], DP[i / 2] + 1);
		}
		if (i % 3 == 0) {
			DP[i] = min(DP[i], DP[i / 3] + 1);
		}
	}
	cout << DP[N] << '\n';
}