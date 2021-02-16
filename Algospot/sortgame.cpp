/**
 * 21-02-17
 * ALGOSPOT : SORTGAME
 * BFS
 * */

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#define MX 8
using namespace std;

int N;
map<vector<int>, int> dist;

int solve(vector<int> v){
    vector<int> afterArr;

    for(int i=0; i<v.size(); i++){
        int x = 0;
        for(int j=0; j<v.size(); j++){
            if(v[i] > v[j]) x++;
        }
        afterArr.push_back(x);
    }

    if(afterArr.size() < MX){
        for(int i=afterArr.size(); i<MX; i++){
            afterArr.push_back(i);
        }
    }
    return dist[afterArr];
}

void bfs(){
    vector<int> v;
    queue<vector<int> > q;

    for(int i=0; i<MX; i++)
        v.push_back(i);
    
    q.push(v);
    dist[v] = 0;

    while(!q.empty()){
        vector<int> x = q.front();
        int cost = dist[x];
        q.pop();

        for(int i=0; i<MX-1; i++){
            for(int j=i+2; j<=MX; j++){
                reverse(x.begin()+i, x.begin()+j);

                if(dist.count(x) == 0){
                    dist[x] = cost + 1;
                    q.push(x);
                }

                reverse(x.begin()+i, x.begin()+j);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int TC;
    cin >> TC;

    bfs();

    while(TC--){
        cin >> N;

        vector <int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        
        cout << solve(arr) << '\n';
    }

    return 0;
}