#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int countP = 0, countY = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'p' || s[i] == 'P')
            countP++;
        else if (s[i] == 'y' || s[i] == 'Y')
            countY++;
    }
    if (countP != countY)
        return false;
    return answer;
}