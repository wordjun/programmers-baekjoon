#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

//정수 배열 numbers가 주어집니다.
//numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 
//만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록 solution 함수를 완성해주세요.
//numbers의 길이는 2 이상 100 이하입니다.
//numbers의 모든 수는 0 이상 100 이하입니다.
//따라서 두 개를 뽑아 가능한 합의 최대 수는 200, 최소 수는 1입니다.
bool num[201];
//각 합이 나왔는지 안나왔는지를 체크하기 위한 배열을 사용
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int sum = 0, size = numbers.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            sum = numbers[i] + numbers[j];
            if (!num[sum]) {
                num[sum] = true;
                answer.push_back(sum);
            }
        }
    }
    sort(answer.begin(), answer.end());
    for (auto& i : answer)
        cout << i << ' ';
    return answer;
}

int main() {
    vector<int> test = { 2,1,3,4,1 };
    solution(test);
    return 0;
}