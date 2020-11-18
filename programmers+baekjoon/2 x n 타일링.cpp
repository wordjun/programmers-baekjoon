#include <string>
#include <vector>

using namespace std;
int arr[60001];

//가로의 길이 n은 60, 000이하의 자연수 입니다.
//경우의 수가 많아 질 수 있으므로, 
//경우의 수를 1, 000, 000, 007으로 나눈 나머지를 return해주세요.

//ex
//n=1; 2 by 1인 경우는 오직 1가지 => 1
//n=2; 2by 2인 경우는 2가지 => 2
//n=3; 2 by 3인 경우는 총 3가지 =>3
//n=4; 2 by 4인 경우: 총 5가지
//피보나치 수열의 패턴을 따른다
int solution(int n) {
    int sum = 0;
    arr[0] = 1, arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        sum = arr[i - 1] + arr[i - 2];
        arr[i] = sum % 1000000007;
    }
    return arr[n];
}
