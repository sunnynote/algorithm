/**
 * 200707
 * BOJ 10166 관중석
 * 수학
 * */

#include <iostream>
using namespace std;

int D1, D2;
bool check[2002][2002];
int ans = 0;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> D1 >> D2;

    for(int i=D1; i<=D2; i++){
        for(int j=1; j<=i; j++){

            int div = gcd(i,j);
            if(!check[i/div][j/div]){
                check[i/div][j/div]=true;
                ans++;
            }    

        }
    }    

    cout << ans;
    return 0;
}