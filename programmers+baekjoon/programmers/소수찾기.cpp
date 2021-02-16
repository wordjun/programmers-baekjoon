#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;
vector<int>v;
vector<int>allNumbers;
bool isPrime(int n) {//소수판별
    if (n == 0 || n == 1)//0 혹은 1이면 소수가 아니다
        return false;
    //소수는 1과 N 만을 약수로 가진다. 그럼 2부터 N-1까지의 수로는 나눠져서는 안된다.
    //주어진 자연수 N이 소수이기 위한 필요 충분조건은 N이 N의 제곱근보다 
    //크지 않은 어떤 소수로도 나눠지지 않는다.
    //수가 수를 나누면 몫이 발생하게 되는데 몫과 나누는 수, 
    //둘 중 하나는 반드시 $\sqrt{ N }$ 이하이기 때문이다.
    for (int i = 2; i <= n / 2; i++) {//소수는 2부터 n의 절반까지 확인.(제곱근까지만 확인해도 판별이 가능)
        if (n % i == 0) {//만약 다른 수에 의해 나눠떨어지는 경우(어차피 n 자기자신까지 가지 않음),
            //다른 수의 배수임을 뜻하고, 이는 소수가 아님을 뜻한다
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    for (int i = 0; i < numbers.length(); i++) {
        v.push_back(numbers[i] - '0');
    }
    sort(v.begin(), v.end());
    
    do {
        for (int i = 0; i <= v.size(); i++) {
            int temp = 0;
            for (int j = 0; j < i; j++) {
                temp = (temp * 10) + v[j];
                //cout << temp << '\n';
                allNumbers.push_back(temp);
            }
        }
    } while (next_permutation(v.begin(), v.end()));
    sort(allNumbers.begin(), allNumbers.end());
    allNumbers.erase(unique(allNumbers.begin(), allNumbers.end()), allNumbers.end());
    
    for (auto& i : allNumbers)
        //cout << i << " ";
        if (isPrime(i))
            answer++;

    return answer;
}

void main() {
    cout<<solution("011");
}