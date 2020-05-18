/**
 * 200518 BOJ 카드게임
 * 간단한 DP 문제 (memoization)
 * */

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int a[2005];
int b[2005];
int d[2005][2005];

int dfs(int x, int y){
    if(x==N || y==N) return 0;

    int &ret = d[x][y];
    if(ret!=-1) return ret;

    ret = max(dfs(x+1, y), d[x][y]);
    ret = max(dfs(x+1, y+1), d[x][y]);
    if(a[x]>b[y]) ret = max(dfs(x, y+1)+b[y], d[x][y]);
    
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> a[i];
    for(int i=0; i<N; i++)
        cin >> b[i];
    memset(d, -1, sizeof(d));
    cout << dfs(0,0);
    
    return 0;
}