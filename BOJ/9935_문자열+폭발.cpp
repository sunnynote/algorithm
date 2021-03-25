/**
 * 21-03-18
 * BOJ 9935 문자열 폭발
 * */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack <char> st;
vector <char> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    string s, bomb;
    cin >> s >> bomb;

    for(int i=0; i<s.length(); i++){
        char cur = s[i];
        st.push(cur);

        if(cur==bomb[bomb.length()-1]){ // 폭발 문자열의 마지막 문자와 일치하면
            for(int j=bomb.length()-1; j>=0; j--){ 
                if(st.empty() || bomb[j]!=st.top()){
                    for(int k=v.size()-1; k>=0; k--){
                        st.push(v.back());
                        v.pop_back();
                    }
                    break;
                }
                else {
                    v.push_back(st.top());
                    st.pop();
                }
            }
            v.clear();
        }
    }

    if(st.empty()) cout << "FRULA";
    else{
        string ans="";
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        for(int i=v.size()-1; i>=0; i--)
            ans += v[i];

        cout << ans;
    }
    return 0;
}