#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

bool position[51][51];
bool visited[51][51];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int M, N, K;
vector<pair<int, int>>v;
queue<pair<int, int>>q;
int worms = 0;

void BFS(int x, int y) {
	int nx = 0, ny = 0;
	q.push({x, y});
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		visited[x][y] = true;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			//범위안에 있고, 배추가 있는 곳
			if (nx >= 0 && nx < M && ny >= 0 && ny < N && position[nx][ny]
				&& !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({nx, ny});
				//cout << q.front().first << " " << q.front().second << '\n';
			}
		}
	}
}


int main() {
	int testCase = 0, x, y;
	cin >> testCase;
	while (testCase--) {
		worms = 0;
		memset(position, false, sizeof(position));
		memset(visited, false, sizeof(visited));
		cin >> M >> N >> K;//가로, 세로, 배추 개수
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			position[x][y] = true;//배추있는곳 체크
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && position[i][j]) {//아직 방문하지 않은 곳 + 배추위치
					BFS(i, j);//지렁이가 배추있는곳끝까지 기어가며 BFS를 통해 visited를 체크함
					worms++;//지렁이 한마리 추가
				}
			}
		}
		cout << worms << '\n';
	}
	return 0;
}