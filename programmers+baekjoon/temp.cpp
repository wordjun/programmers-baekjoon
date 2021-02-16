#include<iostream>
#include<string.h>
using namespace std;

//memoizationȰ���Ͽ� �ߺ��� ������ �ð�����

int fib[41];

int fibonacci(int n) {
	if (n == 1) {
		fib[1] = 1;
		return 1;
	}
	else if (n == 0) {
		fib[0] = 0;
		return 0;
	}
	if (fib[n] == -1) {//���� ��ϵ��� ���� �Ǻ���ġ ���� ����
		fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
		return fib[n];
	}
	else
		return fib[n];
}

int main() {
	int testCase = 0, N = 0;
	cin >> testCase;
	while (testCase--) {
		memset(fib, -1, sizeof(fib));
		cin >> N;
		
		fib[0] = 0, fib[1] = 1;
		for (int i = 2; i <= N; i++) {
			if(fib[i] != -1)
				fib[i] = fib[i - 1] + fib[i - 2];
		}
		cout << fib[N - 1] << " " << fib[N] << '\n';
	}

	return 0;
}