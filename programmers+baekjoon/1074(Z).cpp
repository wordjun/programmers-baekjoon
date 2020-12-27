#include<iostream>
using namespace std;

int N, r, c;//변의 길이는 2^N이 되고, r행 c열이 몇번째로 방문되는지 확인
int cnt = 0;
void rec(int row, int col, int len) {
	//만약 현재 방문한 곳이 찾고있는 곳이면 이때까지 방문횟수 출력
	if (row == r && col == c) {
		cout << cnt << '\n';
		return;
	}
	//현재 방문한 곳이 길이기 1인경우 1증가하고 리턴(더이상 4로 나눌 수 없는 공간인 경우, base case가 된다)
	if (len == 1) {
		cnt++;
		return;
	}
	//아래 4가지 조건을 모두 만족한다는 것은
	//지금 찾고 있는 위치가 현재 4개의 사분면중 하나에 존재함을 뜻함.
	//따라서 4등분하여 찾음
	if (row <= r && col <= c  && r < row + len && c < col + len) {
		rec(row, col, len / 2);//현재 정사각형에서 왼쪽 윗부분
		rec(row, col + len / 2, len / 2);//현재 정사각형에서 오른쪽 윗부분
		rec(row + len / 2, col, len / 2);//현재 정사각형에서 왼쪽 아랫부분
		rec(row + len / 2, col + len / 2, len / 2);//현재 정사각형에서 오른쪽 아랫부분
	}
	else {//위조건 불충족 = 찾는 위치가 속한 사분면보다 이전 사분면이므로, 그 가로세로길이만큼
		//count에 더함
		cnt += len * len;//한 사분면 통째로 방문
	}
}

int main() {
	
	cin >> N >> r >> c;
	rec(0, 0, 1 << N);
}