#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPrime(int n) {
	if (n == 0 || n == 1)
		return false;
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int N = 0, num = 0, count = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (isPrime(num))
			count++;
	}
	cout << count << '\n';
}