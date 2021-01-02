#include<iostream>
#include<stack>
using namespace std;

int N;
bool visited[101];
bool connected[101][101];
int computers = 0;
stack<int>s;

void DFS(int n) {
	visited[n] = true;
	for (int i = 1; i <= N; i++) {
		if (connected[n][i] && !visited[i]) {
			computers++;
			//cout << n << " " << i << '\n';
			DFS(i);
		}
	}
}


int main() {
	int pairs = 0, x = 0, y = 0;
	cin >> N >> pairs;
	for (int i = 0; i < pairs; i++) {
		cin >> x >> y;
		connected[x][y] = true;
		connected[y][x] = true;
	}

	int nx = 0, ny = 0;
	int current = 0;
	s.push(1);
	visited[1] = true;
	//stackȰ��
	while (!s.empty()) {
		current = s.top();
		s.pop();
		for (int i = 1; i <= N; i++) {
			if (connected[current][i] && !visited[i]) {
				s.push(i);
				visited[i] = true;
				computers++;
			}
		}
	}

	//DFS(1);//1���� �����ؼ� 1������ ����Ǿ� ������ ��ǻ�� �� Ȯ��
	//for (int i = 1; i <= N; i++) {
	//	if (!visited[i]) {
	//		DFS(i);
	//		//computers++;//����� ������
	//	}
	//}
	cout << computers << '\n';

	return 0;
}