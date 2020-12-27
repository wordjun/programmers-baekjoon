#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	vector<int>n;

	int N, num = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		n.push_back(num);
	}
	sort(n.begin(), n.end());

	int M = 0;
	cin >> M;
	vector<bool>m(M, false);
	for (int i = 0; i < M; i++) {
		cin >> num;
		if (binary_search(n.begin(), n.end(), num))
			m[i] = true;
	}
	for (int i = 0; i < m.size(); i++)
		cout << m[i] << '\n';
}