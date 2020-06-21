/**
 * 200620
 * BOJ 16398 행성연결
 * Kruskal (Union-Find)
 * */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Info{
    int from, to, cost;
};
vector <Info> v;
int parent[1005];

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

    if(a==b) return;
    if(a>b) swap(a,b);

    parent[b]=a;
}

bool cmp(const Info& p1, const Info& p2){
    if(p1.cost < p2.cost) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    int cost;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> cost;

            if(i>=j) continue;
            v.push_back({i,j,cost});
        }
    }
    sort(v.begin(), v.end(), cmp);

    for(int i=1; i<=N; i++)
        parent[i] = i;

    long long ans = 0;
    int cnt = 0;
    for(int i=0; i<v.size(); i++){
        if(!isSameParent(v[i].from, v[i].to)){
            ans += v[i].cost;
            cnt++;
            unite(v[i].from, v[i].to);
        }
        if(cnt==N-1) break;
    }

    cout << ans << '\n';

    return 0;
}