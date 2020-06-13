/**
 * 200613
 * BOJ 2824 
 * 최대공약수
 * 약수 구하기 + 오버플로우 주의
 */

#include <iostream>
#include <cmath>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

int N, M;
map <int,int> mp1, mp2;
long long ans = 1;
bool flag=false;

void makeCnt(){
    int x;

    // A
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x;

        for(int j=2; j*j<=x; j++){
            while(x%j==0){
                if(!mp1.empty()){
                    if(mp1.find(j) != mp1.end()) // mp1에 존재
                        mp1[j]++;
                    else  // mp1에 없음
                        mp1.insert({j,1});
                } 
                else mp1.insert({j,1}); // mp1에 없음

                x/=j;
            }
        }
        
        if(x!=1){
            if(mp1.find(x) != mp1.end()) // mp1에 존재
                mp1[x]++;
            else  // mp1에 없음
                mp1.insert({x,1});
        }
    }

    // B
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> x;

        for(int j=2; j*j<=x; j++){
            while(x%j==0){
                if(!mp2.empty()){
                    if(mp2.find(j) != mp2.end())
                        mp2[j]++;
                    else
                        mp2.insert({j,1});
                } 
                else mp2.insert({j,1});

                x/=j;
            }
        }
        
        if(x!=1){
            if(mp2.find(x) != mp2.end())
                mp2[x]++;
            else
                mp2.insert({x,1});
        } 
    }
}

void solve(){
    for(auto it=mp1.begin(); it!=mp1.end(); it++){
        long long val = it->first;

        if(mp2.find(val) != mp2.end()){
            int cnt = min(mp1[val], mp2[val]);
            
            for(int i=0; i<cnt; i++){
                ans *= val;
                if(ans>999999999) {
                    flag = true;
                    ans %= 1000000000;
                }
            }
        }
    }
}

void printNum(){
    string s = to_string(ans);

    if(flag){
        stack <char> st;

        for(int i=s.length()-1; i>=0; i--){
            st.push(s[i]);
        }
        while(st.size()<9){
            st.push('0');
        }
        for(int i=0; i<9; i++){
            cout << st.top();
            st.pop();
        }
    }
    else
        cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    makeCnt();
    solve();
    printNum();

    return 0;
}
