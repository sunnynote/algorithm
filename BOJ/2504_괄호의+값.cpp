/**
 * 20-12-07
 * BOJ 2504 괄호의 값
 * 스택
 * */

#include <iostream>
#include <stack>
using namespace std;

stack <char> st;
int ans=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;

    int len = s.length();
    int zeroFlag = false;
    int score = 1;

    for(int i=0; i<len; i++){        
        if(len%2==1) zeroFlag = true;

        if(s[i]=='('){
            score *= 2;
            st.push(s[i]);
        }
        else if(s[i]=='['){
            score *= 3;
            st.push(s[i]);
        }
        else{
            if(st.empty())
                zeroFlag = true;
            else if(s[i]==')'){
                if(st.top()=='(') {
                    st.pop();

                    if(s[i-1]=='(') ans += score;
                    score /= 2;
                }
                else
                    zeroFlag = true;
            }
            else if(s[i]==']'){
                if(st.top()=='['){
                    st.pop();

                    if(s[i-1]=='[') ans += score;
                    score /= 3;
                }
                else
                    zeroFlag = true;
            }
        }

        if(zeroFlag) break;
    }

    if(zeroFlag) ans = 0;
    cout << ans;
    return 0;
}