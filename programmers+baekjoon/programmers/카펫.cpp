#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    //int max = -1;
    //for (int i = 1; i <= sum; ++i) {//col(����)
    //    for (int j = 1; j <= i; ++j) {//row(����)
    //        if (sum % i == 0 && sum % j == 0) {
    //            //1. ī���� ���� ���̴� ���� ���̿� ���ų�, ���� ���̺��� ���
    //            //2. ���� * ���� = sum �̾�� �Ѵ�
    //            //3. �����Ÿ���� �� �� ���̿� �־�� �ϹǷ�, j�� ��� 3�̻��� ���̾�� �Ѵ�.
    //            if (i >= j && (i * j == sum)) {
    //                if (max < j)//������ ������ ��� 3�̻��� ���̾�� ���Ÿ���� ���簡��
    //                    max = j;//���� ����ũ�� �� ���� ū ���� ���� j�� ������ ���� �ȴ�
    //                //cout << i << " " << j << '\n';
    //            }
    //        }
    //    }
    //}
    //answer.push_back(sum / max);
    //answer.push_back(max);


    //int totalTiles = brown + yellow;//brown + yellow = totalTiles = height * width
    //int height = 0, width = 0;//height = 0, width = 0
    //////totalTiles - 2(height+width) = yellow - 4
    //////height + width = (totalTiles + 4 - yellow) / 2
    ////int sum = (totalTiles + 4 - yellow) / 2;
    ////��, width >= height
    //for (int i = totalTiles; i >= 1; --i) {
    //    for (int j = i; j >= 1; --j) {
    //        if (totalTiles % i == 0 && totalTiles % j == 0) {
    //            width = i - 2;
    //            height = j - 2;
    //            if (width >=1 && height >= 1 && width*height == yellow) {
    //                //cout << i << " " << j << '\n';
    //                answer.push_back(i);
    //                answer.push_back(j);
    //                break;
    //            }
    //        }
    //    }
    //}

    int total = brown + yellow;
    for (int i = total; i >= 1; i--) {
        if (total % i == 0) {//���� i�� total�� ����ΰ��
            int width = i;
            int height = total / i;

            if (width >= height && (width - 2) * (height - 2) == yellow) {
                answer.push_back(width), answer.push_back(height);
            }
        }
    }
    return answer;
}

int main() {

    for (auto& i : solution(10, 2)) {
        cout << i << ' ';
    }
}