// 문제 보고 위상 정렬을 바로 못 알아차려서 아쉽

/**
 * 21-02-10
 * 위상정렬 DFS (인접리스트)
 * */

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;

vector <string> words;
vector <int> adj[26];
int check[26];

vector <int> ans;

void makeGraph(){
    string s;
    for(int i=0; i<N; i++){
        cin >> s;
        words.push_back(s);
    }

    for(int i=0; i<N-1; i++){

        int j = i+1; // 인접한 1개만 확인 할 것임
        int len = min(words[i].size(), words[j].size());

        for(int k=0; k<len; k++){
            int iIdx = words[i][k] - 'a'; 
            int jIdx = words[j][k] - 'a';

            if(iIdx != jIdx){

                bool flag = true;
                for(int z=0; z<adj[iIdx].size(); z++)
                    if(adj[iIdx][z]==jIdx)
                        flag = false;

                if(flag){
                    adj[iIdx].push_back(jIdx);
                }

                break;
            }
        }
    }
}

void dfs(int x){
    check[x] = true;

    for(int i=0; i<adj[x].size(); i++){
        int nx = adj[x][i];  
        if(!check[nx]) dfs(nx);
    }

    ans.push_back(x);
    // dfs가 종료되면 ans에 추가.
    // 가장 늦게 종료되는 문자가 루트이다.
}

void solve(){
    // topological sort

    for(int i=0; i<26; i++){
        for(int j=0; j<adj[i].size(); j++){
            if(!check[i]) dfs(i);
        }
    }

    reverse(ans.begin(), ans.end());
}

bool cycleCheck(){

    // 인접리스트 돌면서 사이클 존재하는지 확인
    for(int i=0; i<26; i++){
        for(int j=0; j<adj[i].size(); j++){
            int cur = adj[i][j];

            for(int k=0; k<adj[cur].size(); k++){
                if(i==adj[cur][k]) return true;
                
            }
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int TC;
    cin >> TC;
    while(TC--){
        ans.clear();
        words.clear();
        memset(check, 0, sizeof(check));
        for(int i=0; i<26; i++)
            adj[i].clear();

        cin >> N;

        makeGraph();
        solve();

        if(cycleCheck()){
            cout << "INVALID HYPOTHESIS";
        }
        else {
            for(int i=0; i<26; i++)
                if(!check[i]) ans.push_back(i);
            
            for(int i=0; i<ans.size(); i++)
                cout << (char)(ans[i]+'a');
        }
        
        cout << '\n';
    }

    return 0;
}