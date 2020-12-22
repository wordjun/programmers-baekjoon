#include <string>
#include <vector>
#include<iostream>
using namespace std;

long long solution(int n) {
    //i=0) n=2: 1 * 2
    //i=1) n=6: 2 * 3
    //i=2) n=12: 3 * 4
    //i=3) n=20: 4 * 5
    //i=4) n=24: 2 * 3 * 4

    //index 4의배수/
    long long answer = 0;
    int index = n - 1;//배열 마지막원소
    vector<int> temp(n, 0);
    int x = 2, y = 0, z = 1;
    for (int i = 0; i < n; i++) {
        if (!(i % 4) && (i != 0)) {
            y = x * (x + 1) * (x + 2);//24
            temp[i] = y;
            x++, y = 0;
        }
        else {
            temp[i] = z * (z + 1);
            z++;
        }
    }
    answer = temp[index];
    return answer;
}

int main() {
    cout << solution(9);
}