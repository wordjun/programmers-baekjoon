#include<iostream>
using namespace std;
int N = 0;

void printStars(int i, int j, int n) {
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
		cout << ' ';
	else {
		if (n / 3 == 0) {
			//3의배수가 아닌 경우
			cout << '*';
		}
		else {
			printStars(i, j, n / 3);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printStars(i, j, N);
		}
		cout << '\n';
	}
	return 0;
}