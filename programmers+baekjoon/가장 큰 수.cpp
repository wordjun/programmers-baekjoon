#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

bool comp(int a, int b) {
    return a > b;
}
//합친 문자 비교해서 큰순으로 정렬하기, ex ) 6, 10 이 있다면 610과 106하고 어떤게 큰지 비교
// 610이 더크므로 6, 10순으로 정렬하게 된다.
bool comp2(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string>newNum;
    string temp;

    for (auto num : numbers) {
        newNum.push_back(to_string(num));//모두 string으로 바꾼다
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