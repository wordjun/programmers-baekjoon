#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int index1 = 0,index2 = 1, nextNum = 0;
    answer.push_back(arr[index1]);
    while (index1 < arr.size() && index2 < arr.size()) {
        nextNum = arr[index2];
        while (arr[index1] == nextNum) {
            index2++;
            if (index2 >= arr.size())
                return answer;
            nextNum = arr[index2];
        }
        index1 = index2;
        index2++;
        answer.push_back(nextNum);
    }
    
    return answer;
}

int main() {
    vector<int> arr = { 4,4,4,3,3 };
    for (auto& i : solution(arr))
        cout << i << " ";
}