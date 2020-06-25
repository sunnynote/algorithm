/**
 * 200625
 * 12761 돌다리
 * BFS
 * */
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int A, B, N, M;
bool check[100005];
struct Info{
    int x, cnt;
};

int ans = 987654321;

void bfs(int X){
    queue <Info> q;
    q.push({X,0});
    check[X]=true;
    
    while(!q.empty()){
        int x = q.front().x;
        int cnt = q.front().cnt;
        q.pop();

        if(x==M){
            ans = min(ans, cnt);
            return;
        }

        if(x-1>=0 && !check[x-1]) {
            q.push({x-1, cnt+1});
            check[x-1] = true;
        }
        if(x+1<=100000 && !check[x+1]) {
            q.push({x+1, cnt+1});
            check[x+1] = true;
        }
        if(x+A<=100000 && !check[x+A]) {
            q.push({x+A, cnt+1});
            check[x+A] = true;
        }
        if(x-A>=0 && !check[x-A]) {
            q.push({x-A, cnt+1});
            check[x-A] = true;
        }
        if(x+B<=100000 && !check[x+B]) {
            q.push({x+B, cnt+1});
            check[x+B] = true;
        }
        if(x-B>=0 && !check[x-B]) {
            q.push({x-B, cnt+1});
            check[x-B] = true;
        }
        if(x*A<=100000 && !check[x*A]) {
            q.push({x*A, cnt+1});
            check[x*A] = true;
        }
        if(x*B<=100000 && !check[x*B]) {
            q.push({x*B, cnt+1});
            check[x*B] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> A >> B >> N >> M;
    bfs(N);
    cout << ans;
    return 0;
}