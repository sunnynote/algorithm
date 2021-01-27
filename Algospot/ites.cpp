/**
 * 21-01-27
 * queue로 온라인 알고리즘!
 * tail의 중요성!
 * */

#include <iostream>
#include <queue>
using namespace std;

int K, N;

struct RNG{
    unsigned seed;
    RNG() : seed(1983) {}

    unsigned next(){
        unsigned ret = seed;
        seed = ( (seed * 214013u) + 2531011u );
        return ret % 10000 + 1;
    }
};

int solve(){
    RNG rng; // 난수 생성
    queue <int> q;

    int ret = 0;
    int rangeSum = 0;

    for(int i=0; i<N; i++){
        int newSignal = rng.next();
        rangeSum += newSignal;
        q.push(newSignal);

        while(rangeSum > K){ // K 초과 하기 전까지 반복 : point
            rangeSum -= q.front();
            q.pop();
        }

        if(rangeSum == K) ret++;
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        cin >> K >> N;
        cout << solve() << '\n';
    }

    return 0;
}