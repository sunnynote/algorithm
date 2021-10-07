/**
 * 21-10-07
 * BOJ 13913 숨바꼭질 4
 * */
#include <iostream>
#include <vector>
#include <queue>
#define MX 100000
using namespace std;

int ans = 0;
bool chk[100001];
int res[100001];

void solve(int n, int k){
    queue <int> q;
    q.push(n);
    chk[n] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x==k) return;

        if(0 <= x-1 && !chk[x-1]) {
            q.push(x-1);
            chk[x-1] = true;
            res[x-1] = x;
        }
        if(x+1 <= MX && !chk[x+1]){
            q.push(x+1);
            chk[x+1] = true;
            res[x+1] = x;
        }
        if(x*2 <= MX && !chk[x*2]) {
            q.push(x*2);
            chk[x*2] = true;
            res[x*2] = x;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;
    if(N!=K) solve(N, K);

    vector <int> v;
    v.push_back(K);

    int idx = K;
    while(1){
        if(idx==N) break;
        v.push_back(res[idx]);
        idx = res[idx];
    }

    cout << v.size()-1 << '\n';
    for(int i=v.size()-1; i>=0; i--)
        cout << v[i] <<' ';

    return 0;
}