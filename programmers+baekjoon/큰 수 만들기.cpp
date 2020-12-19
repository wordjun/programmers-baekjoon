#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    char maxNum;
    int index = 0, maxIdx = 0;
    int length = number.length() - k;
    for (int i = 0; i < length; i++) {
        maxNum = number[index];//현재틀에서 가장 앞 숫자가 초기 maxNum
        maxIdx = index;
        for (int j = index; j <= k + i; j++) {
            //j는 현재 틀(i의 틀)에서, answer에 넣은 가장 큰 값 이후 바로 다음 숫자부터 시작
            //(자리수에 변동이 있으면 안되므로)
            if (maxNum < number[j]) {
                maxNum = number[j];
                maxIdx = j;
            }
        }
        //현재 틀에서 가장 큰 숫자 asnwer에 추가
        answer += number[maxIdx];
        //그 다음 큰 숫자 찾는 것은 현재 maxIdx 바로 뒤
        index = maxIdx + 1;
    }
    return answer;
}
//int main() {
//    cout<<solution("1231234", 3);
//}