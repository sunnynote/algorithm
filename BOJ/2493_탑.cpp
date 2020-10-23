/**
 * 20-10-05
 * BOJ 2493 탑
 * STACK
 * */
#include <iostream>
#include <stack>
using namespace std;

int N;
int arr[500002];

void solve(){
    stack <int> st;

    st.push(1);
    cout << 0 << ' ';

    for(int i=2; i<=N; i++){
        int cur = arr[i];

        if(!st.empty()){
            if(arr[st.top()] < cur){
                while(!st.empty() && arr[st.top()] < cur)
                    st.pop();
                
                if(st.empty()) cout << 0 << ' ';
                else cout << st.top() << ' ';
                
                st.push(i);
            }
            else{
                cout << st.top() << ' ';
                st.push(i);
            }
        }
        else cout << 0 << ' ';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i=1; i<=N; i++)
        cin >> arr[i];

    solve();
    return 0;
}
