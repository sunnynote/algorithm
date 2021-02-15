// 인접 행렬 풀이

/**
 *  Algospot 고대어 사전
 * 인접리스트 풀이 16ms
 * 인접행렬 풀이 16ms
 * */

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;

vector <string> words;
vector <vector<int> > adj; // 순서 memo
int check[26];

vector <int> ans;

void makeGraph(){
    string s;
    for(int i=0; i<N; i++){
        cin >> s;
        words.push_back(s);
    }

    for(int i=0; i<N-1; i++){

        int j = i+1;
        int len = min(words[i].size(), words[j].size());

        for(int k=0; k<len; k++){
            if(words[i][k] != words[j][k]){
                adj[words[i][k] - 'a'][words[j][k] - 'a'] = 1;
                break;
            }
        }
    }
}

void dfs(int x){
    check[x] = true;
    for(int i=0; i<26; i++)
        if(adj[x][i] && !check[i]) dfs(i);

    ans.push_back(x);
}

void solve(){
    // topological sort
    for(int i=0; i<26; i++)
        if(!check[i]) dfs(i); 

    reverse(ans.begin(), ans.end());
}

bool cycleCheck(){
    for(int i=0; i<26; i++)
        for(int j=i+1; j<26; j++)
            if(adj[ans[j]][ans[i]]) return true;

    return false;
}

void init(){
    ans.clear();
    words.clear();
    memset(check, 0, sizeof(check));
    adj = vector<vector<int> >(26, vector<int>(26, 0));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int TC;
    cin >> TC;
    while(TC--){
        init();

        cin >> N;

        makeGraph();
        solve();

        if(cycleCheck()){
            cout << "INVALID HYPOTHESIS";
        }
        else { 
            for(int i=0; i<26; i++)
            // for(int i=25; i>=0; i--)
                cout << (char)(ans[i]+'a');
        }
        
        cout << '\n';
    }

    return 0;
}