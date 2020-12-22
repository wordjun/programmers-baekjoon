#include <vector>
using namespace std;

int min(int a, int b) {
    return a < b;
}

int solution(int N, vector<int> sequence)
{
    
    int answer = 0;
    int current = 1, hours = 0;
    for (int i = 0; i < sequence.size(); i++) {
        if (sequence[i] - current <= (N / 2))
            answer += sequence[i] - current;
        else
            //answer += 
        current = sequence[i];
    }

    return answer;
}