/**
 * 21-01-26
 * */

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int N, K;
deque <int> dq;

void solve(){
    for(int i=1; i<=N; i++)
        dq.push_back(i);

    while(1){
        if(dq.size()==2) break;

        dq.pop_front();
        for(int i=1; i<K; i++){
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }

    sort(dq.begin(), dq.end());
    for(int i=0; i<dq.size(); i++)
        cout << dq[i] << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        dq.clear();

        cin >> N >> K;
        solve();
    }

    return 0;
}