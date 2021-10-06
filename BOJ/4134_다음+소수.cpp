/**
 * 21-10-05
 * BOJ 4134 다음 소수
 * 약수
 * */

#include <iostream>
using namespace std;
typedef long long ll;

bool is_prime(ll x){
    if(x<2) return 0;
    
    for(ll i=2; i*i<=x; i++)
        if(x%i==0) return 0;
    return 1;
}

void solve(ll x){
    while(1){
        if(is_prime(x)) {
            cout << x << '\n';
            break;
        }
        x++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    
    for(int i=0; i<N; i++){
        ll x;
        cin >> x;
        solve(x);
    }

    return 0;
}