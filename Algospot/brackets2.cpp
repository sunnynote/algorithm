/**
 * 21-01-26
 * 스택의 괄호쌍
 * */

#include <iostream>
#include <stack>
using namespace std;

string str;
stack <char> st;

bool solve(){
    bool flag = true;
    int len = str.length();

    for(int idx=0; idx<len; idx++){
        char cur = str[idx];

        if(st.empty()){
            st.push(cur);
        }
        else{
            if(cur=='(' || cur=='{' || cur=='['){
                st.push(cur);
            }
            else{
                if(st.top()=='(' && cur==')') {
                    st.pop();
                    continue;
                }
                if(st.top()=='{' && cur=='}') {
                    st.pop();
                    continue;
                }
                if(st.top()=='[' && cur==']') {
                    st.pop();
                    continue;
                }

                flag = false;
            }
        }
    }

    if(st.size() != 0) flag = false;

    return flag;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        while(!st.empty()){
            st.pop();
        }

        cin >> str;

        if(solve()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}