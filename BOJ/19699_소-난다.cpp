/**
 * 21-10-01
 * BOJ 19699 소-난다
 * 백트래킹, 소수판별
 * */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int h[10];
bool chk[10];
bool prime_arr[3001];

vector <int> v;

void is_prime(){
    prime_arr[1] = true;

    for(int i=2; i*i<=3000; i++){
        if(!prime_arr[i]){
            for(int j=i*i; j<=3000; j+=i)
                prime_arr[j] = true;
        }
    }
}

void solve(int cnt){
    if(cnt==M){
        int val = 0;
        for(int i=0; i<N; i++)
            if(chk[i]) val += h[i];

        if(!prime_arr[val]) v.push_back(val);
        return;
    }

    for(int i=0; i<N; i++){
        if(chk[i]) continue;

        chk[i] = true;
        solve(cnt+1);
        chk[i] = false;
    }

}

void input(){
    cin >> N >> M;

    for(int i=0; i<N; i++)
        cin >> h[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    is_prime();
    solve(0);

    if(v.size()==0) cout << -1 <<'\n';
    else{
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        for(int i=0; i<v.size(); i++)
            cout << v[i] << ' ';
    } 

    return 0;
}