#include <string>
#include <vector>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
bool check[201];

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    memset(check, false, sizeof(bool));
    int temp = 0;
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            temp = numbers[i] + numbers[j];
            if (!check[temp]) {
                answer.push_back(temp);
                check[temp] = true;
            }
        }
    }
    sort(answer.begin(), answer.end());
    /*
    for (auto& i : answer)
        cout << i << " ";*/

    return answer;
}

int main() {
    vector<int> a = { 2, 1, 3, 4, 1 };
    solution(a);
}