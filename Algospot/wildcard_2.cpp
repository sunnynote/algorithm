#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

string W, S;
int N;
int cache[102][102];
vector <string> v;

int solve(int w, int s){
    int &ret = cache[w][s];
    if(ret!=-1) return ret;

    // 위치 찾기
    if(w<W.length() && s<S.length() && (W[w]=='?' || W[w]==S[s]) ){
        return ret = solve(w+1, s+1);
    }
    
    // w의 끝인 경우
    if(w==W.length()) 
        return ret = (s==S.length());

    // *를 만난 경우
    if(W[w]=='*'){
        if(solve(w+1, s) || (s<S.length() && solve(w, s+1))){
            return ret = 1;
        }
    }

    return ret = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        v.clear();

        cin >> W;
        cin >> N;

        while(N--){
            cin >> S;
            memset(cache, -1, sizeof(cache));
            int ans = solve(0, 0);

            if(ans) v.push_back(S);
        }

        sort(v.begin(), v.end());

        for(int i=0; i<v.size(); i++)
            cout << v[i] << '\n';
    }
    
    return 0;
}