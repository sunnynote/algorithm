/**
 * 200621
 * BOJ 2887 행성 터널
 * Kruskal + Sort
 * */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point{
    int x, y, z, idx;
};
struct Info{
    int from, to, cost;
};

vector <Point> p;
vector <Info> v;
int parent[100005];

bool cmpX(const Point &p1, const Point &p2){
    if(p1.x < p2.x) return true;
    return false;
}

bool cmpY(const Point &p1, const Point &p2){
    if(p1.y < p2.y) return true;
    return false;
}

bool cmpZ(const Point &p1, const Point &p2){
    if(p1.z < p2.z) return true;
    return false;
}

bool cmp(const Info &i1, const Info &i2){
    if(i1.cost < i2.cost) return true;
    return false;
}

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
    if(a<b) swap(a,b);
    parent[b]=a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        int x, y, z;
        cin >> x >> y >> z;
        p.push_back({x,y,z,i});
    }

    // 1 -- x기준
    sort(p.begin(), p.end(), cmpX);
    for(int i=0; i<N-1; i++)
        v.push_back({p[i].idx, p[i+1].idx, abs(p[i].x - p[i+1].x)});
    // 2 -- y기준
    sort(p.begin(), p.end(), cmpY);
    for(int i=0; i<N-1; i++)
        v.push_back({p[i].idx, p[i+1].idx, abs(p[i].y - p[i+1].y)});
    // 3 -- z기준
    sort(p.begin(), p.end(), cmpZ);
    for(int i=0; i<N-1; i++)
        v.push_back({p[i].idx, p[i+1].idx, abs(p[i].z - p[i+1].z)});

    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<N; i++) parent[i]=i;

    long long ans = 0;
    int cnt = 0;
    for(int i=0; i<v.size(); i++){
        if(!isSameParent(v[i].from, v[i].to)){
            ans += v[i].cost;
            unite(v[i].from, v[i].to);
            cnt++;
        }
        
        if(cnt==N-1) break;
    }
    
    cout << ans;
    return 0;
}