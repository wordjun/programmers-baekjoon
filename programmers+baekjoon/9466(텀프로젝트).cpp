#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int N;
int teamMembers;
bool visited[100001];
bool check[100001];
vector<int> v;

void DFS(int n) {
	int next = v[n];
	visited[n] = true;


	if (!visited[next])
		DFS(next);
	else {
		//연결됐는지 확인
		if (!check[next]) {
			for (int i = next; i != n ; i= v[i]) {
				teamMembers++;
			}
			teamMembers++;
			
		}
	}
	check[n] = true;
}

int main() {
	int testCase = 0, num = 0;
	N = 0;
	cin >> testCase;
	while (testCase--) {
		//initialize
		teamMembers = 0;
		memset(visited, false, sizeof(visited));
		memset(check, false, sizeof(check));
		v.clear();
		v.push_back(-1);

		cin >> N;
		
		for (int i = 1; i <= N; i++) {
			cin >> num;
			v.push_back(num);
		}

		for (int i = 1; i <= N; i++) {
			if(!visited[i])
				DFS(i);
		}
		cout << N - teamMembers << '\n';
	}
	return 0;
}