#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
#define MAX 100001
bool visited[MAX];

int main() {
	queue<pair<int, int>>q;
	memset(visited, false, sizeof(visited));
	int N, K, current = 0, time = 0, result = 0;
	cin >> N >> K;
	q.push({ N, 0 });
	while (!q.empty()) {
		current = q.front().first;
		time = q.front().second;
		q.pop();
		if (current == K) {//������ �ִ� ��ġ�� ���������� ����
			cout << time << '\n';
			break;
		}
		//��ĭ �ڷ� �̵��ϴ°��
		if (current - 1 >= 0 && !visited[current - 1]) {
			visited[current - 1] = true;
			q.emplace(current - 1, time + 1);
		}
		//��ĭ ������ �̵��ϴ°��
		if (current + 1 <= MAX && !visited[current + 1]) {
			visited[current + 1] = true;
			q.emplace(current + 1, time + 1);
		}
		//��ĭ �ڷ� �̵��ϴ°��
		if (current * 2 <= MAX && !visited[current * 2]) {
			visited[current * 2] = true;
			q.emplace(current * 2, time + 1);
		}
	}
}