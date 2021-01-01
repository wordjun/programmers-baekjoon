#include<iostream>
#include<string.h>
#include<queue>//BFS
using namespace std;

int M, N, K;
bool visited[51][51];//�ش� ��ǥ�� �����̰� ������������ ���� ����
bool cabbage[51][51];//�ش� ��ǥ�� ���� ���� ����
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int worms;


void DFS(int x, int y) {
	//���
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
	//queue ���
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
		//�ʱ�ȭ
		worms = 0;
		memset(cabbage, false, sizeof(cabbage));
		memset(visited, false, sizeof(visited));

		//�Է�
		cin >> M >> N >> K;//����, ����, ������ġ����
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			cabbage[x][y] = true;//���߰� �ִ� ��ġ���� ��� ǥ��
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				//��� ��ǥ�� ����, ���߰� ������ �����̰� ���� ���� ���� ���� ��� BFS/DFS ȣ��
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