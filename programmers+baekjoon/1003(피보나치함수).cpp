#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int fib[41];

int fibonacci(int n) {
	if (n == 0) {
		fib[0] = 0;
		return 0;
	}
	else if (n == 1) {
		fib[1] = 1;
		return 1;
	}
	if (fib[n] != -1)//이미 계산됨
		return fib[n];
	else//계산되지 않은경우
		return fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	int testCase = 0, num = 0;
	memset(fib, -1, sizeof(fib));
	vector<pair<int, int>> result;
	cin >> testCase;
	//0이 출력되는 횟수와 1이 출력되는 횟수
	for (int i = 0; i < testCase; i++) {
		cin >> num;
		
		if(num == 0)
			result.push_back({1, 0});
		else if(num == 1)
			result.push_back({0, 1});
		else {
			fibonacci(num);
			result.push_back({fib[num-1], fib[num] });
		}
		
	}
	for (auto& i : result)
		cout << i.first << " " << i.second << '\n';
	return 0;
}