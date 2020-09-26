/**
 * 200924
 * BOJ 1918
 * 후위 표기식
 * STACK
 * */

#include <iostream>
#include <stack>
using namespace std;

string str;
string ans="";

int getOpPrec(char op){
    if(op=='*' || op=='/') return 3;
    if(op=='+' || op=='-') return 2;
    if(op=='(') return 1;
    return -1;
}

int cmpOpPrec(char op1, char op2){
    int op1Prec = getOpPrec(op1);
    int op2Prec = getOpPrec(op2);

    if(op1Prec>=op2Prec) return 1;
    return -1;
}

void convToExp(){
    stack <char> st;

    for(int i=0; i<str.length(); i++){
        char cur = str[i];

        if('A'<=cur && cur<='Z'){
            ans += cur;
        }
        else{
            if(cur=='('){
                st.push(cur);
            }
            else if(cur==')'){
                while(1){
                    char popOp = st.top(); st.pop();
                    if(popOp=='(') break;
                    ans += popOp;
                }
            }

            else if(cur=='+' || cur=='-' || cur=='*' || cur=='/'){
                while(!st.empty() && cmpOpPrec(st.top(), cur)==1){
                    ans += st.top(); st.pop();
                }
                st.push(cur);
            }
        }
    }

    while(!st.empty()){
        char cur = st.top(); st.pop();
        ans += cur;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> str;
    
    convToExp();
    cout << ans << '\n';
    return 0;
}