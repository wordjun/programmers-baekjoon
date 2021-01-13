#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
#define MAX 51

bool board[MAX][MAX];//먹이의 위치를 나타내는 좌표
int startX, startY;
int DP[MAX][MAX];

//knight
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

//
void BFS() {
	queue<pair<int, int>> q;
	q.push({ startX, startY });
	//knight
	for (int j = 0; j < 8; j++) {

	}
}

int main() {
	ios::sync_with_stdio(false);
	int N, kCost, bCost, rCost, M, x, y;
	memset(board, false, sizeof(board));
	cin >> N >> startX >> startY >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		board[x][y] = true;
	}

	for (int i = 0; i < MAX; i++) {
		
	}
	return 0;
}