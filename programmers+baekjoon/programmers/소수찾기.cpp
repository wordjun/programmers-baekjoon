#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;
vector<int>v;
vector<int>allNumbers;
bool isPrime(int n) {//�Ҽ��Ǻ�
    if (n == 0 || n == 1)//0 Ȥ�� 1�̸� �Ҽ��� �ƴϴ�
        return false;
    //�Ҽ��� 1�� N ���� ����� ������. �׷� 2���� N-1������ ���δ� ���������� �ȵȴ�.
    //�־��� �ڿ��� N�� �Ҽ��̱� ���� �ʿ� ��������� N�� N�� �����ٺ��� 
    //ũ�� ���� � �Ҽ��ε� �������� �ʴ´�.
    //���� ���� ������ ���� �߻��ϰ� �Ǵµ� ��� ������ ��, 
    //�� �� �ϳ��� �ݵ�� $\sqrt{ N }$ �����̱� �����̴�.
    for (int i = 2; i <= n / 2; i++) {//�Ҽ��� 2���� n�� ���ݱ��� Ȯ��.(�����ٱ����� Ȯ���ص� �Ǻ��� ����)
        if (n % i == 0) {//���� �ٸ� ���� ���� ������������ ���(������ n �ڱ��ڽű��� ���� ����),
            //�ٸ� ���� ������� ���ϰ�, �̴� �Ҽ��� �ƴ��� ���Ѵ�
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