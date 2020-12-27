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
		//맨 윗카드는 버리는카드
		//dump = cards.front();
		cards.pop();
		//제일 위에 있는 카드 맨 밑으로
		temp = cards.front();
		cards.pop();
		cards.push(temp);
	}
	cout << cards.front() << '\n';
}