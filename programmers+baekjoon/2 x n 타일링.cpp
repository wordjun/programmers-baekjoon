#include <string>
#include <vector>

using namespace std;
int arr[60001];

//������ ���� n�� 60, 000������ �ڿ��� �Դϴ�.
//����� ���� ���� �� �� �����Ƿ�, 
//����� ���� 1, 000, 000, 007���� ���� �������� return���ּ���.

//ex
//n=1; 2 by 1�� ���� ���� 1���� => 1
//n=2; 2by 2�� ���� 2���� => 2
//n=3; 2 by 3�� ���� �� 3���� =>3
//n=4; 2 by 4�� ���: �� 5����
//�Ǻ���ġ ������ ������ ������
int solution(int n) {
    int sum = 0;
    arr[0] = 1, arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        sum = arr[i - 1] + arr[i - 2];
        arr[i] = sum % 1000000007;
    }
    return arr[n];
}
