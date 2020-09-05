#include <string>
#include <vector>
#include<algorithm>
#include <iostream>

using namespace std;

bool comp(int a, int b) {
    return a < b;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int>temp;
    int start = 0, end = 0, k = 0;
    for (int i = 0; i < commands.size(); i++) {
        start = commands[i][0] - 1, end = commands[i][1] - 1, k = commands[i][2] - 1;
        for (int j = start; j <= end; j++)
            temp.push_back(array[j]);
        sort(temp.begin(), temp.end(), comp);

        answer.push_back(temp[k]);
        temp.clear();
    }
    return answer;
}

int main() {
    vector<vector<int>> com;
    vector<int>a, b, c;
    a = { 2, 5, 3 }, b = { 4, 4, 1 }, c = { 1, 7, 3 };
    com.push_back(a), com.push_back(b), com.push_back(c);
    vector<int>array = { 1, 5, 2, 6, 3, 7, 4 };
    for (auto& i : solution(array, com))
        cout << i << " ";
}