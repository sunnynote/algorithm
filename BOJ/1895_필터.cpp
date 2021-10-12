/**
 * 21-10-12
 * BOJ 1895 필터
 * */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, T;
int arr[41][41];
vector <int> res;

int calc(int x, int y){
    vector <int> v;
    for(int i=x; i<x+3; i++)
        for(int j=y; j<y+3; j++)
            v.push_back(arr[i][j]);

    sort(v.begin(), v.end());
    return v[4];
}

int solve(){
    for(int i=0; i<=N-3; i++)
        for(int j=0; j<=M-3; j++)
            res.push_back(calc(i, j));

    int ans = 0;
    for(int i=0; i<res.size(); i++)
        if(res[i]>T) ans++;

    return ans;
}

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> arr[i][j];

    cin >> T;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    cout << solve();

    return 0;
}