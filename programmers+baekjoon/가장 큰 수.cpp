#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

bool comp(int a, int b) {
    return a > b;
}
//��ģ ���� ���ؼ� ū������ �����ϱ�, ex ) 6, 10 �� �ִٸ� 610�� 106�ϰ� ��� ū�� ��
// 610�� ��ũ�Ƿ� 6, 10������ �����ϰ� �ȴ�.
bool comp2(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string>newNum;
    string temp;

    for (auto num : numbers) {
        newNum.push_back(to_string(num));//��� string���� �ٲ۴�
    }
    sort(newNum.begin(), newNum.end(), comp2);
    /*for (auto i : newNum) {
        cout << i << " ";
    }*/
    if (newNum[0] == "0")
        return "0";
    for (auto c : newNum)
        answer.append(c);
    /*sort(numbers.begin(), numbers.end());
    do {
        temp = "";
        for (auto& i : numbers) {
            temp.append(to_string(i));
        }
        newNum.push_back(stoi(temp));
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    sort(newNum.begin(), newNum.end(), comp);
    answer = to_string(newNum[0]);*/
    return answer;
}
//int main() {
//    solution({ 6, 10, 2 });
//}