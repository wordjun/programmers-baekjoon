#include <string>
#include <vector>
#include<iostream>
using namespace std;


int solution(int n) {
    int answer = 0;
    vector<int> binary;
    int i = 0, count1 = 0, count2 = 0;
    int tempNum1 = n;
    for (i = 0; tempNum1 > 0; i++) {//n이 0이하 될때까지
        binary.push_back(tempNum1 % 2);
        tempNum1 /= 2;
    }

    for (auto& a : binary)
        if (a == 1)
            count1++;

    int currentNum = n - 1;
    while (currentNum > 1) {
        binary.clear();
        int tempNum2 = currentNum;
        for (int j = 0; tempNum2 > 0; j++) {//n이 0이하 될때까지
            binary.push_back(tempNum2 % 2);
            tempNum2 /= 2;
        }
        for (auto& a : binary) {
            if (a == 1)
                count2++;
        }
            
        if (count1 == count2)
            answer++;
        count2 = 0;
        currentNum--;
    }

    /*vector<int> arr(i, 0);
    int index = 0;
    for (int j = binary.size() - 1; j > 0;j--) {
        arr[index++] = binary[j];
    }
    cout << '\n';
    for (auto& a : arr) {
        cout << a;
    }*/


    return answer;
}

int main() {
    solution(12);
}