#include <string>
#include <vector>
#include<iostream>

using namespace std;

int arr[3] = { 4, 1, 2 };
vector<int> v;
string solution(int n) {
    string answer = "";
    //given a number n,
    //if n == 1, 4, 7..., 1 comes along
    //if n == 2, 5, 8..., 2 comes along
    //if n == 3, 6, 9..., 4 comes along
    while (n > 0) {
        int remainder = n % 3;

        n /= 3;

        if (remainder == 0)
            n--;

        v.push_back(arr[remainder]);
    }
    for (int i = v.size() - 1; i >= 0; --i)
        answer += to_string(v[i]);
    return answer;
}

void main() {
    cout << solution(18) << '\n';
}