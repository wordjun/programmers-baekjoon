#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

//��������: ����Ž��
vector<int>std1, std2, std3;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<pair<int, int>>students;
    //1�� ������: 1, 2, 3, 4, 5 (1~5������� ����)
    std1 = { 1, 2, 3, 4, 5 };
    //2�� ������: 2, 1, 2, 3, 2, 4, 2, 5, ...(2 ���� n(1~5) �����ư��� ����)
    std2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    //3�� ������: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...
    std3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int index1 = 0, index2 = 0, index3 = 0;
    int count1 = 0, count2 = 0, count3 = 0;
    for (auto& i : answers) {
        if (i == std1[index1++])
            count1++;
        if (index1 == std1.size())
            index1 = 0;
    }
    for (auto& i : answers) {
        if (i == std2[index2++])
            count2++;
        if (index2 == std2.size())
            index2 = 0;
    }
    for (auto& i : answers) {
        if (i == std3[index3++])
            count3++;
        if (index3 == std3.size())
            index3 = 0;
    }
    //cout << count1 << " "<<count2<<" "<<count3 <<endl;
    int maxScore = -1;
    students = { {1, count1}, {2, count2}, {3, count3 } };
    sort(students.begin(), students.end(), comp);
    maxScore = students.front().second;
    for (auto& i : students) {
        if(i.second == maxScore)
            answer.push_back(i.first);
    }

    /*for (auto& i : answer)
        cout << i << " ";*/
    return answer;
}

int main() {
    vector<int> sample = { 1, 2, 3, 4, 5 };
    solution(sample);
    return 0;
}