#include <string>
#include <vector>
#include<iostream>
#include<stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> s1;
    int answer = 0;
    int col;
    for (int i = 0; i < moves.size(); i++) {
        col = moves[i] - 1;

        for (int row = 0; row < board.size(); row++) {
            if (board[row][col] != 0) {
                if (!s1.empty()) {
                    if (s1.top() == board[row][col]) {
                        s1.pop();
                        answer += 2;
                    }
                    else
                        s1.push(board[row][col]);
                }
                else
                    s1.push(board[row][col]);

                board[row][col] = 0;
                break;
            }
        }
        
        
    }
    
    return answer;
}

int main() {
    vector<vector<int>> board;
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};
    vector<int>v1 = { 0, 0, 0, 0, 0 };
    vector<int>v2 = { 0, 0, 1, 0, 3 };
    vector<int>v3 = { 0, 2, 5, 0, 1 };
    vector<int>v4 = { 4, 2, 4, 4, 2 };
    vector<int>v5 = { 3, 5, 1, 3, 1 };
    board.push_back(v1), board.push_back(v2), board.push_back(v3), 
        board.push_back(v4), board.push_back(v5);

    cout << solution(board, moves);
    //cout << solution(board, moves);
    return 0;
}