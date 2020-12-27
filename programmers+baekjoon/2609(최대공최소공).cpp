#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cd(int a, int b) {//¹«Á¶°Ç a>b
	if (b == 0)
		return a;
	return cd(b, a % b);
}

int main() {
	int a, b = 0, gcd = 0, lcd = 0;
	cin >> a >> b;
	if (a < b) {
		gcd = cd(b, a);
		cout << gcd << '\n';
		lcd = (a*b) / gcd;
		cout << lcd << '\n';
	}
	else {
		gcd = cd(a, b);
		cout << gcd << '\n';
		lcd = (a * b) / gcd;
		cout << lcd << '\n';
	}
}