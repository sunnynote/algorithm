/**
 * @file 17298.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 17298 오큰수 / stack
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <stack>
using namespace std;

stack <int> st;
int arr[1000005];
int ans[1000005];

int main(){
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    for(int i=N-1; i>=0; i--){
        while(!st.empty() && arr[i] >= st.top()){
            st.pop();
        }

        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();

        st.push(arr[i]);
    }

    for(int i=0; i<N; i++){
        cout << ans[i] << ' ';
    }
}