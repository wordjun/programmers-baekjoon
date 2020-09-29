#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if (arr.size() == 1 || arr.size() == 0) {
        answer.push_back(-1);
        return answer;
    }
    else {
        int min = arr[0], index = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < min) {
                min = arr[i];
                index = i;
            }
        }
        for (int i = 0; i < index; i++)
            answer.push_back(arr[i]);

        for (int i = index+1; i < arr.size(); i++)
            answer.push_back(arr[i]);

        return answer;
    }
}