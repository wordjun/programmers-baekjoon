#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;


int main() {
	stack<int> s;
	int N = 0, num = 0;
	string cmd;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> num;
			s.push(num);
		}
		else if (cmd == "pop") {
			if (!s.empty()) {
				cout << s.top() << '\n';
				s.pop();
			}
			else
				cout << -1 << '\n';
		}
		else if (cmd == "top") {
			if (!s.empty())
				cout << s.top() << '\n';
			else
				cout << -1 << '\n';
		}
		else if (cmd == "size") {
			cout << s.size() << '\n';
		}
		else if (cmd == "empty") {
			if (s.empty()) {
				cout << 1 << '\n';
			}
			else
				cout << 0 << '\n';
		}
	}
	return 0;
}