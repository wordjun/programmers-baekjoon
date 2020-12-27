#include<iostream>
#include<cmath>
using namespace std;

int factorial(int n) {
	if (n == 1 || n == 0)
		return 1;
	return n * factorial(n - 1);
}

int main() {
	int N, K;
	cin >> N >> K;
	cout << factorial(N) / (factorial(N - K) * factorial(K))<<'\n';
	return 0;
}