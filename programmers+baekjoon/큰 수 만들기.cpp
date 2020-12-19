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
        maxNum = number[index];//����Ʋ���� ���� �� ���ڰ� �ʱ� maxNum
        maxIdx = index;
        for (int j = index; j <= k + i; j++) {
            //j�� ���� Ʋ(i�� Ʋ)����, answer�� ���� ���� ū �� ���� �ٷ� ���� ���ں��� ����
            //(�ڸ����� ������ ������ �ȵǹǷ�)
            if (maxNum < number[j]) {
                maxNum = number[j];
                maxIdx = j;
            }
        }
        //���� Ʋ���� ���� ū ���� asnwer�� �߰�
        answer += number[maxIdx];
        //�� ���� ū ���� ã�� ���� ���� maxIdx �ٷ� ��
        index = maxIdx + 1;
    }
    return answer;
}
//int main() {
//    cout<<solution("1231234", 3);
//}