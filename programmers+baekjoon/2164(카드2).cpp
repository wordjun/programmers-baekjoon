#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


int main() {
	queue<int>cards;
	int N = 0, temp;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cards.push(i);

	while (cards.size() != 1) {
		//�� ��ī��� ������ī��
		//dump = cards.front();
		cards.pop();
		//���� ���� �ִ� ī�� �� ������
		temp = cards.front();
		cards.pop();
		cards.push(temp);
	}
	cout << cards.front() << '\n';
}