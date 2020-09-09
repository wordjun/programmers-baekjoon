#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    answer.append("김서방은 ");
    for (int i = 0; i < seoul.size();i++) {
        if (seoul[i] == "Kim")
            answer.append(to_string(i));
    }
    answer.append("에 있다");
    return answer;
}