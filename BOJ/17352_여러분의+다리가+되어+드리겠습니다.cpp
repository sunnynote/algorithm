/**
 * 21-10-09
 * BOJ 17352 여러분의 다리가 되어 드리겠습니다!
 * 유니온 파운드
 * */

#include <iostream>
#define MX 300000
using namespace std;

int N;
int parent[MX+1];

int find_parent(int x){
    if(parent[x]==x) return x;
    return parent[x] = find_parent(parent[x]);
}

void unite(int a, int b){
    int x = find_parent(a);
    int y = find_parent(b);
    
    if(x < y) parent[y] = x;
    else parent[x] = y;
}

void solve(){
    for(int i=1; i<=N-1; i++)
        if(find_parent(i) != find_parent(i+1)){
            cout << i << ' '<< i+1;
            return;
        }
}

void input(){
    cin >> N;

    for(int i=1; i<=N; i++)
        parent[i] = i;

    int a, b;
    for(int i=1; i<=N-2; i++){
        cin >> a >> b;
        unite(a, b);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}