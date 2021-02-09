/**
 * 21-02-09
 * RUNNINGMEDIAN
 * 우선순위 큐
 * */

#include <iostream>
#include <queue>
#define MOD 20090711
using namespace std;

int N, a, b;

struct RNG{
    int a, b, seed;
    RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}

    int next(){
        int ret = seed;
        seed = ( (seed * (long long)a) + b ) % MOD;
        return ret;
    }
};

int solve(){
    priority_queue <int> pqMN;
    priority_queue <int> pqMX;
    RNG rng(a, b);
    long long ans = 0;

    for(int i=0; i<N; i++){
        int cur = rng.next();

        if(pqMN.size() == pqMX.size())
            pqMN.push(cur);
        else
            pqMX.push(-cur);
        

        if(!pqMN.empty() && !pqMX.empty() && pqMN.top() > -pqMX.top()){
            int tmp = pqMN.top();
            pqMN.pop();

            pqMN.push(-pqMX.top());
            pqMX.pop();
            pqMX.push(-tmp);
        }

        ans += pqMN.top();
    }

    return ans % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int TC;
    cin >> TC;
    while(TC--){
        cin >> N >> a >> b;
        cout << solve() << '\n';
    }

    return 0;
}