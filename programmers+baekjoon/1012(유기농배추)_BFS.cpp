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
			//�����ȿ� �ְ�, ���߰� �ִ� ��
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
		cin >> M >> N >> K;//����, ����, ���� ����
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			position[x][y] = true;//�����ִ°� üũ
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && position[i][j]) {//���� �湮���� ���� �� + ������ġ
					BFS(i, j);//�����̰� �����ִ°������� ���� BFS�� ���� visited�� üũ��
					worms++;//������ �Ѹ��� �߰�
				}
			}
		}
		cout << worms << '\n';
	}
	return 0;
}