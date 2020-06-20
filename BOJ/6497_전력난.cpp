/**
 * 200619
 * BOJ 6497 전력난
 * Union_find
 * */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M, N;
int parent[200005];

struct INFO{
    int from, to, dist;
};

int findParent(int x){
    if(x==parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

bool isSameParent(int a, int b){
    return findParent(a)==findParent(b);
}

void unite(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(a>b) swap(a,b);
    parent[b] = a;
}

bool cmp(const INFO &d1, const INFO &d2){
    if(d1.dist < d2.dist) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    while(1){
        cin >> M >> N;
        if(M==0 && N==0) break;


        vector <INFO> v;
        long long tot=0;
        for(int i=0; i<N; i++){
            int x,y,z;
            cin >> x >> y >> z;
            v.push_back({x,y,z});
            tot += z;
        }

        sort(v.begin(), v.end(), cmp);

        for(int i=0; i<M; i++) parent[i] = i;

        long long ans = 0;
        int cnt = 0;

        for(int i=0; i<N; i++){
            int from = v[i].from;
            int to = v[i].to;
            int dist = v[i].dist;

            if(!isSameParent(from,to)){
                unite(from, to);
                cnt++;
                ans += dist;
            }

            if(cnt==M-1) break;
        }
        cout << tot - ans << '\n';
    }

    return 0;
}
