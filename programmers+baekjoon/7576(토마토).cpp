#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int board[1001][1001];
int days[1001][1001];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int M, N, maxNum;
queue<pair<int, int>> q;
int max(int a, int b) {
	return a > b ? a : b;
}

void BFS() {
	
	//q.push({ x, y });
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M && board[nx][ny] == 0 && days[nx][ny] == -1) {
				days[nx][ny] = days[curX][curY] + 1;
				//cout << nx << " " << ny << " " << days[nx][ny] << '\n';
				maxNum = max(days[nx][ny], maxNum);
				q.push({ nx, ny });
			}
		}
	}
}
void printDist() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << days[i][j];
		}
		cout << '\n';
	}
		
}

int main() {
	bool complete = true;
	memset(board, -1, sizeof(board));
	memset(days, -1, sizeof(days));
	maxNum = 0;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push({ i, j }); 
				complete = false;
				days[i][j] = 0;//starting point, day 0
			}
		}
	}
	BFS();
	//printDist();
	if (complete)
		cout << 0 << '\n';
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 0 && days[i][j] == -1) {
					cout << -1 << '\n';
					return 0;
				}
			}
		}
		cout << maxNum << '\n';
	}

	return 0;
}