#include<iostream>
using namespace std;

int N, r, c, answer;

void rec(int row, int col, int len) {
	if (row == r && col == c) {
		cout << answer << '\n';
		return;
	}
	if (len == 1) {//현재 사각형이 길이 1인경우
		answer++;
		return;
	}
	
	//4개 사분면 모두 길이 줄여서(현재 정사각형에서 4등분) 확인 (왼쪽 위 기준으로)
	if (row <= r && r < row + len && col <= c  && c < col + len) {//찾는 좌표의 x좌표(r)가 현재 위치(row)보다 앞에 있어야 한다(y좌표 마찬가지)
		rec(row, col, len / 2);
		rec(row, col + (len / 2), len / 2);
		rec(row + (len/2), col, len / 2);
		rec(row + (len / 2), col + (len / 2), len / 2);
	}
	else {//현재 사분면에 찾는 좌표가 속하지 않은 경우, 해당 사분면 크기만큼 값 더한다
		answer += (len * len);
	}
}

int main() {
	N = 0, r = 0, c = 0;
	cin >> N >> r >> c;
	rec(0, 0, 1 << N);//(0, 0)부터 시작
	
	return 0;
}