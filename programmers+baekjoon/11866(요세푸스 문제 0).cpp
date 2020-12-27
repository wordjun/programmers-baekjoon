#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
	queue<int>q;
	vector<int>v;
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	int temp = 0;
	while (!q.empty()) {
		for (int i = 0; i < K - 1; i++) {
			temp = q.front();
			q.pop();
			q.push(temp);
		}
		v.push_back(q.front());
		q.pop();
	}
	cout << "<";
	for (int i = 0; i < v.size() - 1; i++)
		cout << v[i] << ", ";
	cout << v[v.size() - 1] << ">\n";
}