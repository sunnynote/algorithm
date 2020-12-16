/**
 * 20-12-16
 * BOJ 1062 가르침
 * DFS 조합
 * */

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
bool check[27];
int ans = 0;
vector <string> word;

int wordCount(){
    int ret = 0;

    for(int i=0; i<N; i++){
        string cur = word[i];
        bool flag = true;

        for(int j=0; j<cur.length(); j++){
            if(check[cur[j]-'a']) continue;

            flag = false;
            break;
        }
        
        if(flag) ret++;
    }
    return ret;
}

void dfs(int cnt, int idx){
    if(cnt==K-5){
        ans = max(wordCount(), ans);
        return;
    }

    for(int i=idx; i<26; i++){
        if(check[i]) continue;

        check[i] = true;
        dfs(cnt+1, i);
        check[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        int len = s.length();

        string temp="";
        for(int j=4; j<len-4; j++){
            temp += s[j];
        }
        word.push_back(temp);
    }

    if(K<5) ans = 0;
    else if(K==26) ans = N;
    else{
        check['a'-'a'] = true;
        check['c'-'a'] = true;
        check['i'-'a'] = true;
        check['n'-'a'] = true;
        check['t'-'a'] = true;

        dfs(0,0);
    }
    
    cout << ans;
    return 0;
}
