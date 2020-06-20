/**
 * 200618
 * BOJ 1174 줄어드는 숫자
 * */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
queue <long long> q;
vector <long long> desNum;

void solve(){
    int idx=0;
    for(int i=0; i<=9; i++){
        q.push(i);
        desNum.push_back(i);
        idx++;
    }
    
    while(idx <= N){
        if(q.empty()) return;

        long long num = q.front();
        q.pop();

        for(int i=0; i<=9; i++){
            if(num%10 > i){ // 현재 1의자리 숫자보다 작으면 push
                long long res = num*10 + i;
                desNum.push_back(res);
                q.push(res);
                idx++;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;

    solve();

    sort(desNum.begin(), desNum.end());

    if(1023<N) cout << -1;
    else cout << desNum[N-1];

    return 0;
}