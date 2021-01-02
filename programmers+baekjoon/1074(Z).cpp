#include<iostream>
using namespace std;

int N, r, c, answer;

void rec(int row, int col, int len) {
	if (row == r && col == c) {
		cout << answer << '\n';
		return;
	}
	if (len == 1) {//���� �簢���� ���� 1�ΰ��
		answer++;
		return;
	}
	
	//4�� ��и� ��� ���� �ٿ���(���� ���簢������ 4���) Ȯ�� (���� �� ��������)
	if (row <= r && r < row + len && col <= c  && c < col + len) {//ã�� ��ǥ�� x��ǥ(r)�� ���� ��ġ(row)���� �տ� �־�� �Ѵ�(y��ǥ ��������)
		rec(row, col, len / 2);
		rec(row, col + (len / 2), len / 2);
		rec(row + (len/2), col, len / 2);
		rec(row + (len / 2), col + (len / 2), len / 2);
	}
	else {//���� ��и鿡 ã�� ��ǥ�� ������ ���� ���, �ش� ��и� ũ�⸸ŭ �� ���Ѵ�
		answer += (len * len);
	}
}

int main() {
	N = 0, r = 0, c = 0;
	cin >> N >> r >> c;
	rec(0, 0, 1 << N);//(0, 0)���� ����
	
	return 0;
}