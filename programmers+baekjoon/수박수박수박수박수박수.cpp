#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string a = "¼ö", b = "¹Ú";
    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; i++) {
            answer.append(a), answer.append(b);
        }
    }
    else {
        for (int i = 0; i < n / 2; i++) {
            answer.append(a), answer.append(b);
        }
        answer.append(a);
    }
    return answer;
}