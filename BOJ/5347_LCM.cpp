/**
 * 21-10-04
 * BOJ 5347 LCM
 * */

#include <iostream>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a*b / gcd(a,b);
}

void input(){
    int N;
    cin >> N;
    
    int a, b;
    for(int i=0; i<N; i++){
        cin >> a >> b;
        cout << lcm(a, b) << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();

    return 0;
}