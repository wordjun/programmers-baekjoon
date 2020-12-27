#include<iostream>
#include<string.h>
using namespace std;
#define INIT 999999
int DP[1000001];

int min(int a, int b) {
	if (a >= b)
		return b;
	else
		return a;
}

int main() {
	//if X % 3 == 0,  X /= 3
	//if X % 2 == 0,  X /= 2
	//sub 1
	int N = 0;
	cin >> N;
	//make 1 with least calculations
	//ex1) N=2; either div by 2, or sub by 1
	//ex2) N = 10; sub by 1, div by 3, then div by 3 => 1

	//dynamic programming, bottom-up ������� ����
	memset(DP, INIT, sizeof(DP));
	DP[1] = 0;//1�� �ѹ��� ������� �ʴ´�.
	for (int i = 2; i <= N; i++) {
		//���� 1�� ����
		DP[i] = DP[i - 1] + 1;

		if (i % 3 == 0)//3���� ����������� 3���� ������, 1�� ���Ͱ� ��
			DP[i] = min(DP[i], DP[i / 3] + 1);
		else if (i % 2 == 0)//2�� ����������� 2�� ������, 1�� ���Ͱ� ��
			DP[i] = min(DP[i], DP[i / 2] + 1);
	}
	cout << DP[N] << '\n';
	return 0;
}