#include <string>
#include <vector>
#include<iostream>

using namespace std;
int arr[1000001];

int solution(int n) {
    //1부터 n 사이 소수개수를 찾아라
    //에라토스테네스의 체 사용
    int answer = 0;
    for (int i = 2; i <= n; i++) {
        arr[i] = i;
    }
    //2부터 시작해 특정 수의 배수에 해당하는 모든 수를 지운다
    for (int i = 2; i <= n; i++) {
        if (arr[i] == 0)//이미 지워진 수는 건너뛰고,
            continue;
        else {//지워지지 않은 수는 그 배수부터 시작해 가능한 모든 숫자 지우기
            for (int j = i * i; j <= n; j += i) {
                arr[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (arr[i] != 0)
            answer++;
    }
    return answer;
}

int main() {
    cout << solution(10);
    return 0;
}