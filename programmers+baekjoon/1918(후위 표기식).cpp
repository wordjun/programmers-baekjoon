#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
	stack<int>s;
	vector<int>v;
	string input;
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') {
			cout << input[i];
		}
		else if (input[i]) {
			s.push(input[i]);
		}
	}
	return 0;
}