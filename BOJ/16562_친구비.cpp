/**
 * 200705
 * BOJ 16562 친구비
 * union-find
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int N, M, TOT;
int cost[10005];
int parent[10005];
int check[10005];
int ans = 0;

int findParent(int x){
    if(x==parent[x]) return x;
    return parent[x]=findParent(parent[x]);
}

bool isSameParent(int a, int b){
    return findParent(a)==findParent(b);
}

void unite(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(cost[a]<cost[b]) parent[b] = a;
    else parent[a] = b;
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> TOT;

    for(int i=1; i<=N; i++){
        cin >> cost[i];
        parent[i] = i;
    }
    
    int from, to;
    for(int i=0; i<M; i++){
        cin >> from >> to;

        if(!isSameParent(from, to))
            unite(from, to);
    }

    for(int i=1; i<=N; i++){
        int node = findParent(i);
        if(check[node]) continue;

        check[node]=true;
        ans += cost[node];
    }

    if(ans<=TOT) cout << ans;
    else cout << "Oh no";

    return 0;
}