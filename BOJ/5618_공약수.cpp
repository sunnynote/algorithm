/**
 * 21-10-01
 * BOJ 5618 공약수
 * 수학(약수)
 * */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    
    // 최대공약수 구하기
    int a, b, c;
    if(N==2){
        cin >> a >> b;
        a = gcd(a, b);
    }
    else{
        cin >> a >> b >> c;
        a = gcd(a, b);
        a = gcd(a, c);
    }

    vector <int> ans;
    for(int i=1; i*i<=a; i++){
        if(i*i==a) { // 제곱수 처리
            ans.push_back(i);
            continue;
        }
        if(a%i==0){
            ans.push_back(i);
            ans.push_back(a/i);
        }
    }

    sort(ans.begin(), ans.end());

    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << '\n';

    return 0;
}