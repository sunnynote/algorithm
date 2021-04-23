/**
 * 21-04-20
 * BOJ 5568 카드 놓기
 * 순열, set
 */

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int N, K;
int arr[10];
bool chk[10];
set <string> st;
vector <int> v;

void solve(int cnt, int idx){
    if(cnt==K){
        string s = "";
        for(int i=0; i<v.size(); i++)
            s += to_string(v[i]);

        set <string>::iterator it = st.find(s);
        if(it==st.end())
            st.insert(s);

        return;
    }

    for(int i=0; i<N; i++){
        if(chk[i]) continue;

        chk[i] = true;
        v.push_back(arr[i]);
        solve(cnt+1, i);
        v.pop_back();
        chk[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    for(int i=0; i<N; i++)
        cin >> arr[i];

    solve(0, 0);
    cout << st.size();

    return 0;
}