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
		if (current == K) {//동생이 있는 위치에 도달했으면 종료
			cout << time << '\n';
			break;
		}
		//한칸 뒤로 이동하는경우
		if (current - 1 >= 0 && !visited[current - 1]) {
			visited[current - 1] = true;
			q.emplace(current - 1, time + 1);
		}
		//한칸 앞으로 이동하는경우
		if (current + 1 <= MAX && !visited[current + 1]) {
			visited[current + 1] = true;
			q.emplace(current + 1, time + 1);
		}
		//한칸 뒤로 이동하는경우
		if (current * 2 <= MAX && !visited[current * 2]) {
			visited[current * 2] = true;
			q.emplace(current * 2, time + 1);
		}
	}
}