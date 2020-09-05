#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> student1 = { 1, 2, 3, 4, 5 };
vector<int> student2 = { 2, 1, 2, 3, 2, 4, 2, 5};
vector<int> student3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
vector<int> correct(3, 0);

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int index1 = 0, index2 = 0, index3 = 0;
    for (int i = 0; i < answers.size();i++) {
        index1 = i % 5;
        index2 = i % 8;
        index3 = i % 10;

        if (answers[i] == student1[index1])
            correct[0]++;
        if (answers[i] == student2[index2])
            correct[1]++;
        if (answers[i] == student3[index3])
            correct[2]++;
    }
    int max = -1, num = 1;
    for (auto& i : correct) {
        if (i > max) {
            max = i;
        }
    }
    for (int i = 0; i < correct.size();i++) {
        if (correct[i] == max)
            answer.push_back(i+1);
    }
    for (auto& i : answer)
        cout << i << " ";

    return answer;
}

int main() {
    vector<int> ans = { 1, 3, 2, 4, 2 };
    solution(ans);
    return 0;
}