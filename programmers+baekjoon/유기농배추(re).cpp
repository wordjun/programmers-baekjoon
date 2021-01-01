#include<iostream>
#include<string.h>
#include<queue>//BFS
using namespace std;

int M, N, K;
bool visited[51][51];//해당 좌표를 지렁이가 지나갔는지에 대한 여부
bool cabbage[51][51];//해당 좌표의 배추 유무 여부
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int worms;


void DFS(int x, int y) {
	//재귀
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < M && ny >= 0 && ny < N
			&& !visited[nx][ny] && cabbage[nx][ny]) {
			DFS(nx, ny);
		}
	}
}

void BFS(int x, int y) {
	//queue 사용
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N
				&& !visited[nx][ny] && cabbage[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	int test = 0, x=0, y=0;
	cin >> test;
	while (test--) {
		//초기화
		worms = 0;
		memset(cabbage, false, sizeof(cabbage));
		memset(visited, false, sizeof(visited));

		//입력
		cin >> M >> N >> K;//가로, 세로, 배추위치개수
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			cabbage[x][y] = true;//배추가 있는 위치들을 모두 표시
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				//모든 좌표에 대해, 배추가 있으며 지렁이가 아직 가지 않은 곳인 경우 BFS/DFS 호출
				if (!visited[i][j] && cabbage[i][j]) {
					DFS(i, j);
					worms++;
				}
			}
		}
		cout << worms << '\n';

	}
	return 0;
}