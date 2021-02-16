#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    //int max = -1;
    //for (int i = 1; i <= sum; ++i) {//col(가로)
    //    for (int j = 1; j <= i; ++j) {//row(세로)
    //        if (sum % i == 0 && sum % j == 0) {
    //            //1. 카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 길다
    //            //2. 가로 * 세로 = sum 이어야 한다
    //            //3. 노란색타일은 두 줄 사이에 있어야 하므로, j는 적어도 3이상의 값이어야 한다.
    //            if (i >= j && (i * j == sum)) {
    //                if (max < j)//가로줄 개수는 적어도 3이상의 값이어야 노랑타일이 존재가능
    //                    max = j;//여러 격자크기 중 가장 큰 값을 가진 j가 가로줄 수가 된다
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
    ////단, width >= height
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
        if (total % i == 0) {//만약 i가 total의 배수인경우
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