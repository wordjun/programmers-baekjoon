#include <string>
#include <vector>
#include<unordered_map>
#include<iostream>
using namespace std;

unordered_map<string, int> map;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for (auto& i : participant) {
        if (map[i] != 0) {
            //이미 있는 경우(중복의 경우)
            map[i]++;
        }
        else {
            //맵에 첫 삽입 
            map[i] = 1;
        }
    }
    for (auto& i : completion) {
        map[i]--;
    }
    //결국 1인 map[i]을 찾으면 된다
    for (auto& i : participant) {
        if (map[i] == 1)
            return i;
    }
}

int main() {
    vector<string> p = { "leo", "kiki", "eden" };
    vector<string> c = { "eden" , "kiki" };
    cout<<solution(p, c);
    return 0;
}