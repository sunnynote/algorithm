/**
 * 200521
 * BOJ 9020 골드바흐의 추측
 * 에라토스테네스의 체(소수)
 * */

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

bool isPrime[10005];

void outPrime(){
    for(int i=2; i<=sqrt(10000); i++){
        if(isPrime[i]){
            for(int j=i*2; j<=10000; j+=i){
                if(isPrime[j]) isPrime[j] = false;
            }
        }
    }
}

void solve(int n){
    int x, y;
    x = y = n/2;

    while(1){
        if( x+y == n && isPrime[x] && isPrime[y]) {
            cout << x << ' ' << y << '\n';
            break;
        }
        x--; y++;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    memset(isPrime, 1, sizeof(isPrime));
    outPrime();

    for(int test_case=1; test_case<=T; test_case++){
        int N;
        cin >> N;
        solve(N);
    }

    return 0;
}
