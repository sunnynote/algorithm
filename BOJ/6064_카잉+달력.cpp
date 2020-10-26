/**
 * BOJ 6064 카잉 달력
 * 수학
 * */

#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return a*b / gcd(a,b);
}

void solve(int M, int N, int x, int y){
    int mx = lcm(M, N);
    int val = x;
    int tempY = x%N;
    if(x%N==0) tempY = N;
    
    while(1){
        if(val > mx) {
            val = -1;
            break;
        }

        if(tempY==y) break;
        
        tempY = (tempY+M) % N;
        if(tempY==0) tempY = N;

        val += M;
    }

    cout << val;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int tc;
    cin >> tc;
    while(tc--){
        int M,N,x,y;
        cin >> M >> N >> x >> y;
        solve(M,N,x,y);
        cout << '\n';
    }

    return 0;
}
