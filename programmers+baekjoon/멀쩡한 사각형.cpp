using namespace std;

long long gcd(int a, int b) {
    //유클리드 호제법
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w, int h) {
    long long answer = 1;
    long long W = w;
    long long H = h;
    long long sum = W + H;
    answer = W * H;
    answer -= sum - gcd(h, w);
    
    return answer;
}