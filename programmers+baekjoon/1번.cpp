#include <iostream>
#include <vector>
using namespace std;

class Coord {
public:
    int x;
    int y;
    Coord(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans;
    Coord *c1 = new Coord(v[0][0], v[0][1]);
    Coord* c2 = new Coord(v[1][0], v[1][1]);
    Coord* c3 = new Coord(v[2][0], v[2][1]);
    Coord* newC1;
    Coord* newC2;
    if (c1->x != c2->x && c1->y != c2->y) {//c1, c2비교
        newC1 = new Coord(c1->x, c2->y);
        newC2 = new Coord(c2->x, c1->y);
        if (newC1->x != c3->x) {//남은 한개와 비교하여 다르면 정답
            ans.push_back(newC1->x);
            ans.push_back(newC1->y);
        }
        else {
            ans.push_back(newC2->x);
            ans.push_back(newC2->y);
        }
    }
    else if (c1->x != c3->x && c1->y != c3->y) {//c1, c3비교
        newC1 = new Coord(c1->x, c3->y);
        newC2 = new Coord(c3->x, c1->y);
        if (newC1->x != c2->x) {//남은 한개와 비교하여 다르면 정답
            ans.push_back(newC1->x);
            ans.push_back(newC1->y);
        }
        else {
            ans.push_back(newC2->x);
            ans.push_back(newC2->y);
        }
    }
    else {
        newC1 = new Coord(c2->x, c3->y);
        newC2 = new Coord(c3->x, c2->y);
        if (newC1->x != c1->x) {//남은 한개와 비교하여 다르면 정답
            ans.push_back(newC1->x);
            ans.push_back(newC1->y);
        }
        else {
            ans.push_back(newC2->x);
            ans.push_back(newC2->y);
        }
    }
    

    return ans;
}
int main() {
    solution({ {1, 4}, {3, 4}, {3, 10} });
}