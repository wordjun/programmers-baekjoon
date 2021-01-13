#include<iostream>
using namespace std;

bool visited[1001];
bool connected[1001][1001]; 
int M = 0, N = 0;

void DFS(int num) {
	visited[num] = true;

	for (int i = 1; i <= N; i++) {
		if (!visited[i] && connected[num][i]) {
			DFS(i);
		}
	}
}

int main() {
	int x = 0, y = 0, comp = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		connected[x][y] = true;
		connected[y][x] = true;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			DFS(i);
			comp++;
		}
	}
	cout << comp << '\n';
	return 0;
}