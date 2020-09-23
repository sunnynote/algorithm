/**
 * 200923
 * BOJ 1935
 * 후위 표기식2
 * STACK
 * */

#include <iostream>
#include <stack>
using namespace std;

int N;
string str;
int arr[27];

double calc(){
    stack <double> st;

    for(int i=0; i<str.length(); i++){
        if('A' <= str[i] && str[i] <= 'Z'){
            st.push(arr[str[i]-'A']);
        }

        else{
            double op2 = st.top();
            st.pop();
            double op1 = st.top();
            st.pop();

            char cur = str[i];

            switch (cur)
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            }
        }
    }

    return st.top();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> str;

    for(int i=0; i<N; i++)
        cin >> arr[i];
    
    double ans = calc();
    cout << fixed;
    cout.precision(2);
    cout << ans;

    return 0;
}